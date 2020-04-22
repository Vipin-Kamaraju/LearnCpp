/*

The Fibonacci sequence is defined using the following recursive formula:
F(0) = 0
F(1) = 1
F(M) = F(M - 1) + F(M - 2) if M >= 2

A small frog wants to get to the other side of a river. The frog is initially located at one bank of the river (position -1) and wants to get to the other bank (position N). The frog can jump over any distance F(K), where F(K) is the K-th Fibonacci number. Luckily, there are many leaves on the river, and the frog can jump between the leaves, but only in the direction of the bank at position N.

The leaves on the river are represented in an array A consisting of N integers. Consecutive elements of array A represent consecutive positions from 0 to N - 1 on the river. Array A contains only 0s and/or 1s:

0 represents a position without a leaf;
1 represents a position containing a leaf.

The goal is to count the minimum number of jumps in which the frog can get to the other side of the river (from position -1 to position N). The frog can jump between positions -1 and N (the banks of the river) and every position containing a leaf.

For example, consider array A such that:
A[0] = 0
A[1] = 0
A[2] = 0
A[3] = 1
A[4] = 1
A[5] = 0
A[6] = 1
A[7] = 0
A[8] = 0
A[9] = 0
A[10] = 0

The frog can make three jumps of length F(5) = 5, F(3) = 2 and F(5) = 5.

Write a function:

int solution(vector<int> &A);

that, given an array A consisting of N integers, returns the minimum number of jumps by which the frog can get to the other side of the river. If the frog cannot reach the other side of the river, the function should return -1.

For example, given:
A[0] = 0
A[1] = 0
A[2] = 0
A[3] = 1
A[4] = 1
A[5] = 0
A[6] = 1
A[7] = 0
A[8] = 0
A[9] = 0
A[10] = 0

the function should return 3, as explained above.

Write an efficient algorithm for the following assumptions:

N is an integer within the range [0..100,000];
each element of array A is an integer that can have one of the following values: 0, 1.

Copyright 2009–2020 by Codility Limited. All Rights Reserved. Unauthorized copying, publication or disclosure prohibited.

*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <stack>
#include <list>
#include <limits>

typedef unsigned long long int l_int;

using namespace std;

struct PathTracker
{
	int location;
	int jump;
	PathTracker(int l, int j) : location(l), jump(j)
	{}

};

vector<int> generateFibonacciSeries(int N)
{
	vector<int> fibonacci;

	fibonacci.push_back(0);
	fibonacci.push_back(1);
	int value = 0;

	for (int i = 2;value <= N + 1; ++i)
	{
		value = fibonacci[i - 1] + fibonacci[i - 2];
		fibonacci.push_back(value);
	}
	return fibonacci;
}

int solution(vector<int> &A) 
{
	/*
	** This current solution has an error. It gets stuck in the while loop
	** Adding locations variable to check if the frog has already reached a certain position in the current cycle
	** Refer : https://github.com/markhary/codility/blob/master/src/FibFrog.cpp solution
	*/
	int minimumJumps = std::numeric_limits<int>::max();
	const int A_size = A.size();

	vector<bool> locations(A_size, false);

	//step1 : generate fibonacci series with the maximum jump as N+1;
	vector<int> fibonacci = generateFibonacciSeries(A_size);

	// step2 : initialize the current location and jumps of the frog as -1,0
	std::list<PathTracker> paths;
	paths.push_back(PathTracker(-1, 0));

	// step3 :  Iterate over the array to find the min number of jumps required
	while (!paths.empty())
	{
		// get the current path
		PathTracker currentPath = paths.back();
		paths.pop_back();

		// check 
		if (currentPath.location >= 0)
		{
			locations[currentPath.location] = false;
		}

		// check if this path is already higher
		if (currentPath.jump + 1 > minimumJumps)
		{
			continue;
		}

		// iterate over the fibonacci series
		for (int i = 2; i < fibonacci.size(); ++i)
		{
			// check the actual position and jumps of the frog
			int currentVal = currentPath.location + fibonacci[i];

			// 3possibilities exist
			// the frog can only jump if this spot is avaialable i.e A[currentVal] = 1
			if ((currentVal < A_size) && (A[currentVal]))
			{
				// frog has jumped to a new position
				if (locations[currentVal])
				{
					continue;
				}
				paths.push_back(PathTracker(currentVal, currentPath.jump + 1));
				locations[currentVal] = true;
			}
			else if (currentVal == A_size)
			{
				minimumJumps = std::min(minimumJumps, currentPath.jump + 1);
				break;
			}
			else if (currentVal > A_size)
			{
				break;
			}
		}
	}

	// step4 : If the paths is empty then no possible jump exists => return -1
	if (minimumJumps == std::numeric_limits<int>::max())
	{
		return -1;
	}

	return minimumJumps;
}

void main()
{
	// refer : https://docs.microsoft.com/en-us/cpp/build/reference/zc-cplusplus?view=vs-2015
	printf("%ld\n", __cplusplus); // this is by default C++98 but C++ Language std used is actually C++14
	printf("%ld\n", _MSC_VER);    // MSVC version VC++ 14.0
	printf("%ld\n", _MSVC_LANG);  // shows unidentified due to Intellisense but Macro is defined.

	vector<int> A = { 0,0,0,1,1,0,1,0,0,0,0 };
	int result_A = 3;

	// first lets return the leader and check if we are getting the correct answer
	assert(solution(A) == result_A);	
	
	cout << "All tests passed" << endl;
	system("PAUSE");
}

