/*

You are given integers K, M and a non-empty array A consisting of N integers. Every element of the array is not greater than M.

You should divide this array into K blocks of consecutive elements. The size of the block is any integer between 0 and N. Every element of the array should belong to some block.

The sum of the block from X to Y equals A[X] + A[X + 1] + ... + A[Y]. The sum of empty block equals 0.

The large sum is the maximal sum of any block.

For example, you are given integers K = 3, M = 5 and array A such that:
A[0] = 2
A[1] = 1
A[2] = 5
A[3] = 1
A[4] = 2
A[5] = 2
A[6] = 2

The array can be divided, for example, into the following blocks:

[2, 1, 5, 1, 2, 2, 2], [], [] with a large sum of 15;
[2], [1, 5, 1, 2], [2, 2] with a large sum of 9;
[2, 1, 5], [], [1, 2, 2, 2] with a large sum of 8;
[2, 1], [5, 1], [2, 2, 2] with a large sum of 6.

The goal is to minimize the large sum. In the above example, 6 is the minimal large sum.

Write a function:

int solution(int K, int M, vector<int> &A);

that, given integers K, M and a non-empty array A consisting of N integers, returns the minimal large sum.

For example, given K = 3, M = 5 and array A such that:
A[0] = 2
A[1] = 1
A[2] = 5
A[3] = 1
A[4] = 2
A[5] = 2
A[6] = 2

the function should return 6, as explained above.

Write an efficient algorithm for the following assumptions:

N and K are integers within the range [1..100,000];
M is an integer within the range [0..10,000];
each element of array A is an integer within the range [0..M].

Copyright 2009–2020 by Codility Limited. All Rights Reserved. Unauthorized copying, publication or disclosure prohibited.

*/

#include <iostream>
#include <algorithm>
#include <cassert>
#include <stack>
#include <list>
#include <limits>
#include <vector>
#include <cmath>

typedef unsigned long long int l_int;

using namespace std;

int solution(int K, int M, vector<int> &A)
{
	/*
	** Logic: Use binary search concept to reduce the search for the min of Large sum possible
	** step1 : the min Large sum that can be achieved is the max(A)
	** step2 : the max Large sum it can achieve is sum(A)
	** step3 :  Using the binary search algorithm find the median value within this range that can satisfy all the conditions
	**
	*/

	int result = 0;
	int upperLimit = 0; // sum(A)
	int lowerLimit = 0; // max(A)

	for (const auto &a : A)
	{
		lowerLimit = std::max(a, lowerLimit);
		upperLimit = upperLimit + a;
	}

	// check if the loop works for a median value of upperLimit and LowerLimit
	// if yes, then set the upperLimit to the current median value
	// if no, then set the lowerLimit to the current median value
	result = (upperLimit + lowerLimit) / 2;

	while ((upperLimit != lowerLimit) && (upperLimit - lowerLimit != 1))
	{
		
		int sum = 0;
		int block = 0;
		for (unsigned int m = 0; m < A.size(); ++m)
		{
			sum = sum + A[m];
			if (sum > result)
			{
				block++;
				sum = A[m];
			}
			else if (sum == result)
			{
				block++;
				sum = 0;
			}
		}
		if (block < K)
		{
			upperLimit = result;
			result = (upperLimit + lowerLimit) / 2;
		}
		if (block >= K)
		{
			lowerLimit = result;
			result = result+1;
		}
	}

	if (upperLimit == lowerLimit)
	{
		return lowerLimit;
	}
	else if ((upperLimit - lowerLimit == 1))
	{
		result = lowerLimit;
		int sum = 0;
		int block = 0;
		for (unsigned int m = 0; m < A.size(); ++m)
		{
			sum = sum + A[m];
			if (sum > result)
			{
				block++;
				sum = A[m];
			}
			else if (sum == result)
			{
				block++;
				sum = 0;
			}
		}
		if (block < K)
		{
			return lowerLimit;
		}
		else if ((block == K) && (sum == 0))
		{
			return lowerLimit;
		}
		else if (block >= K)
		{
			return upperLimit;
		}
	}

}

void main()
{
	// refer : https://docs.microsoft.com/en-us/cpp/build/reference/zc-cplusplus?view=vs-2015
	printf("%ld\n", __cplusplus); // this is by default C++98 but C++ Language std used is actually C++14
	printf("%ld\n", _MSC_VER);    // MSVC version VC++ 14.0
	printf("%ld\n", _MSVC_LANG);  // shows unidentified due to Intellisense but Macro is defined.

	vector<int> A = { 2, 1, 5, 1, 2, 2, 2 };
	int K = 3;
	int M = 5;
	int result_A = 6;

	int K2 = 1;
	int M2 = 10;
	vector<int> B = { 5,3 };
	int result_B = 8;

	int K3 = 3;
	int M3 = 3;
	vector<int> C = { 1,3,1,3,2,1,3 };
	int result_C = 5;

	// first lets return the leader and check if we are getting the correct answer
	assert(solution(K,M,A) == result_A);	
	assert(solution(K2, M2, B) == result_B);
	assert(solution(K3, M3, C) == result_C);

	cout << "All tests passed" << endl;
	system("PAUSE");
}

