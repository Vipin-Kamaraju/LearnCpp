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

typedef unsigned long long int l_int;

using namespace std;

vector<int> generateFibonacciSeries(int N)
{
	vector<int> fibonacci;

	fibonacci.push_back(0);
	fibonacci.push_back(1);
	int value = 0;

	for (int i = 2;i < N + 1; ++i)
	{
		value = fibonacci[i - 1] + fibonacci[i - 2];	
		fibonacci.push_back(value);
	}
	return fibonacci;
}

vector<int> generatePossibleJumps(vector<int>& A)
{
	vector<int> Jumps;
	int count = 1;
	int value = 0;
	vector<vector<int>> vecJumps;
	bool firstIteration = true;
	vector<int> result;

	for (int i = 0; i < A.size(); ++i)
	{
		if (A[i] == 0)
		{
			count++;
		}
		else
		{
			if (firstIteration)
			{
				result.push_back(count);
				Jumps.push_back(count);
				count = 1;
				vecJumps.push_back(Jumps);
				Jumps.erase(Jumps.begin(), Jumps.end());
				firstIteration = false;
			}
			else
			{
				result.push_back(count);
				Jumps.push_back(count);
				int Jumps_size = Jumps.size();
				int vecJumps_size = vecJumps.size();
				int j = vecJumps_size - 1;

				int vecJumps_size2 = vecJumps[j].size();
				for (int k = 0; k < vecJumps_size2; ++k)
				{
					value = vecJumps[j][k] + count;
					Jumps.push_back(value);
					result.push_back(value);
				}

				vecJumps.push_back(Jumps);
				Jumps.erase(Jumps.begin(), Jumps.end());
				count = 1;
			}
		}
	}

	return result;
}
int solution(vector<int> &A)
{
	/*
	** Logic:
	** step1 : generate a fibonacci series
	** step2 : generate possible jumps from array A
	** atep3 : find the minimum jumps that are required
	*/
	int result = 0;
	int A_size = A.size();
	
	// step1
	vector<int> fibonacciSeries = generateFibonacciSeries(A_size);

	// step2
	vector<int> possibleJumps = generatePossibleJumps(A);


	return result;
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

