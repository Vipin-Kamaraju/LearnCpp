/*

A non-empty array A consisting of N integers is given.

A peak is an array element which is larger than its neighbors. More precisely, it is an index P such that 0 < P < N - 1,  A[P - 1] < A[P] and A[P] > A[P + 1].

For example, the following array A:
A[0] = 1
A[1] = 2
A[2] = 3
A[3] = 4
A[4] = 3
A[5] = 4
A[6] = 1
A[7] = 2
A[8] = 3
A[9] = 4
A[10] = 6
A[11] = 2

has exactly three peaks: 3, 5, 10.

We want to divide this array into blocks containing the same number of elements. More precisely, we want to choose a number K that will yield the following blocks:

A[0], A[1], ..., A[K - 1],
A[K], A[K + 1], ..., A[2K - 1],
...
A[N - K], A[N - K + 1], ..., A[N - 1].

What's more, every block should contain at least one peak. Notice that extreme elements of the blocks (for example A[K - 1] or A[K]) can also be peaks, but only if they have both neighbors (including one in an adjacent blocks).

The goal is to find the maximum number of blocks into which the array A can be divided.

Array A can be divided into blocks as follows:

one block (1, 2, 3, 4, 3, 4, 1, 2, 3, 4, 6, 2). This block contains three peaks.
two blocks (1, 2, 3, 4, 3, 4) and (1, 2, 3, 4, 6, 2). Every block has a peak.
three blocks (1, 2, 3, 4), (3, 4, 1, 2), (3, 4, 6, 2). Every block has a peak. Notice in particular that the first block (1, 2, 3, 4) has a peak at A[3], because A[2] < A[3] > A[4], even though A[4] is in the adjacent block.

However, array A cannot be divided into four blocks, (1, 2, 3), (4, 3, 4), (1, 2, 3) and (4, 6, 2), because the (1, 2, 3) blocks do not contain a peak. Notice in particular that the (4, 3, 4) block contains two peaks: A[3] and A[5].

The maximum number of blocks that array A can be divided into is three.

Write a function:

int solution(vector<int> &A);

that, given a non-empty array A consisting of N integers, returns the maximum number of blocks into which A can be divided.

If A cannot be divided into some number of blocks, the function should return 0.

For example, given:
A[0] = 1
A[1] = 2
A[2] = 3
A[3] = 4
A[4] = 3
A[5] = 4
A[6] = 1
A[7] = 2
A[8] = 3
A[9] = 4
A[10] = 6
A[11] = 2

the function should return 3, as explained above.

Write an efficient algorithm for the following assumptions:

N is an integer within the range [1..100,000];
each element of array A is an integer within the range [0..1,000,000,000].

Copyright 2009–2020 by Codility Limited. All Rights Reserved. Unauthorized copying, publication or disclosure prohibited.

*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <string>
#include <stack>
#include <cmath>

using namespace std;

int solution(vector<int> &A)
{
	/*
	** Logic :
	** step 1: find the divisors of A.size()
	** since A can be split into equal blocks of size n if and only if n is a divisor of A.size()
	** step 2: find the peaks and sort them
	** step 3: Iterate through the vector of divisors and find the least block size with atleast one peak
	** step 4: least block size => maximum number of blocks
	** number of blocks = A.size()/least block size
	** This soln has a time complexity of O(N * log(log(N))) 
	*/
	int result = 0;

	if (A.size() == 0 || A.size() == 1)
	{
		return 0;
	}

	vector<int> vecDivisors;
	int divisor = 0;
	int divisor2 = 0;
	int A_size = A.size();

	int maxDivisors = sqrt(A_size);

	for (int divisor = 1; divisor <= maxDivisors; ++divisor)
	{
		if (A_size % divisor == 0)
		{
			divisor2 = A_size / divisor;
			vecDivisors.push_back(divisor);
			if (divisor != divisor2)
			{
				vecDivisors.push_back(divisor2);
			}	
		}
	}

	sort(vecDivisors.begin(), vecDivisors.end());

	vector<int> peaks;

	for (int m = 1; m < A.size() - 1; ++m)
	{
		if ((A[m] > A[m - 1]) && (A[m] > A[m + 1]))
		{
			peaks.push_back(m);
		}
	}

	if (peaks.size() == 0)
	{
		return 0;
	}
	else if (peaks.size() == 1)
	{
		return 1;
	}

	vector<int> vecResult;

	for (int n = 0; n < vecDivisors.size(); ++n)
	{
		int count = 0;
		bool peakFound = false;
		int maxDistance = vecDivisors[n];
		int peakCounter = 0;
		if (maxDistance > 1)
		{
			for (int r = 0; r < A.size(); ++r)
			{
				count++;
				if (peakCounter < peaks.size())
				{
					if (r == peaks[peakCounter])
					{
						peakFound = true;
						peakCounter++;

					}
				}
				
				if (count == maxDistance)
				{
					count = 0;
					if (!peakFound)
					{
						break;
					}
					else
					{
						peakFound = false;
					}
				}
				if ((r == A_size - 1))
				{
					vecResult.push_back(maxDistance);
				}
				
			}
		}
		
	}

	result = vecResult.front();
	result = A_size / result;

	return result;
}

void main()
{
	// refer : https://docs.microsoft.com/en-us/cpp/build/reference/zc-cplusplus?view=vs-2015
	printf("%ld\n", __cplusplus); // this is by default C++98 but C++ Language std used is actually C++14
	printf("%ld\n", _MSC_VER);    // MSVC version VC++ 14.0
	printf("%ld\n", _MSVC_LANG);  // shows unidentified due to Intellisense but Macro is defined.

	vector<int> A = { 1,2,3,4,3,4,1,2,3,4,6,2 };
	vector<int> B = {0, 1, 0, 0, 1, 0, 0, 1, 0};
	vector<int> C = {};
	vector<int> D = {4};
	vector<int> E = { 0,1,0,1,0,1,0,1,0,1,0 };
	vector<int> F = { 5,6,5,6,1,1,1,1,6,5,6,5 };
	vector<int> G = { 1,6,1,1,1,1,1,6,1,1,1,1,1,1,1,1,6,1,1,1,1,1,6,1 };

	// first lets return the leader and check if we are getting the correct answer
	assert(solution(A) == 3);
	assert(solution(B) == 3);
	assert(solution(C) == 0);
	assert(solution(D) == 0);
	assert(solution(E) == 1);
	assert(solution(F) == 4);
	assert(solution(G) == 4);

	
	cout << "All tests passed" << endl;
	system("PAUSE");
}

