/*

You are given an array A consisting of N integers.

For each number A[i] such that 0 = i < N, we want to count the number of elements of the array that are not the divisors of A[i]. We say that these elements are non-divisors.

For example, consider integer N = 5 and array A such that:
A[0] = 3
A[1] = 1
A[2] = 2
A[3] = 3
A[4] = 6

For the following elements:

A[0] = 3, the non-divisors are: 2, 6,
A[1] = 1, the non-divisors are: 3, 2, 3, 6,
A[2] = 2, the non-divisors are: 3, 3, 6,
A[3] = 3, the non-divisors are: 2, 6,
A[4] = 6, there aren't any non-divisors.

Write a function:

vector<int> solution(vector<int> &A);

that, given an array A consisting of N integers, returns a sequence of integers representing the amount of non-divisors.

Result array should be returned as a vector of integers.

For example, given:
A[0] = 3
A[1] = 1
A[2] = 2
A[3] = 3
A[4] = 6

the function should return [2, 4, 3, 2, 0], as explained above.

Write an efficient algorithm for the following assumptions:

N is an integer within the range [1..50,000];
each element of array A is an integer within the range [1..2 * N].

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

vector<int> solution(vector<int> &A)
{
	/*
	** Logic : Solution with O(N^2) time complexity
	*/
	int A_size = A.size();
	vector<int> result(A_size, 0);

	for (int m = 0; m < A.size(); ++m)
	{
		int count = 0;
		for (int n = 0; n < A.size(); ++n)
		{
			if ((A[m] % A[n]) != 0)
			{
				count++;
			}
		}
		result.at(m) = count;
	}

	return result;
}

void main()
{
	// refer : https://docs.microsoft.com/en-us/cpp/build/reference/zc-cplusplus?view=vs-2015
	printf("%ld\n", __cplusplus); // this is by default C++98 but C++ Language std used is actually C++14
	printf("%ld\n", _MSC_VER);    // MSVC version VC++ 14.0
	printf("%ld\n", _MSVC_LANG);  // shows unidentified due to Intellisense but Macro is defined.

	vector<int> A = { 3,1,2,3,6 };
	vector<int> resultA = { 2,4,3,2,0 };

	// first lets return the leader and check if we are getting the correct answer
	assert(solution(A) == resultA);


	
	cout << "All tests passed" << endl;
	system("PAUSE");
}

