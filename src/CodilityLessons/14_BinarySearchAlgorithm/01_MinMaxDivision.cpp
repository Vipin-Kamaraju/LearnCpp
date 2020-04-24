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
	int result = 0;
	return result;
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

	// first lets return the leader and check if we are getting the correct answer
	assert(solution(K,M,A) == result_A);	

	cout << "All tests passed" << endl;
	system("PAUSE");
}

