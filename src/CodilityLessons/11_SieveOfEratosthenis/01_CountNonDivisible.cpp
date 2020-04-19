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
#include <map>

using namespace std;

vector<int> solution(vector<int> &A)
{
	
	/*
	** Logic: Use the Eratosthenes method by calculating the divisors
	** step1 : create a map of unique elements and repetetions of their occurences
	** step2 : create a vector Divisor count for keeping track of the divisors
	** step3 : According to the task. For size N, max value of array A is 2*N
	** i.e Eg. 5 elements can have a max value of 10
	*/
	int A_size = A.size();
	map<int, int> divisors;
	vector<int> result(A_size, 0);

	for (auto it_A = A.begin(); it_A != A.end(); ++it_A)
	{
		divisors[*it_A]++;
	}

	// step 3. Since 5 elements can have max value 10
	// +1 added to size to avoid confusion of zero index in calculation
	vector<int> nonDivisibleCounter(2 * A_size + 1, A_size);

	for (auto it_d = divisors.begin(); it_d != divisors.end(); ++it_d)
	{
		for (int m = 1; m*it_d->first <= nonDivisibleCounter.size() - 1; ++m)
		{
			nonDivisibleCounter[m * (it_d->first)] = nonDivisibleCounter[m * (it_d->first)] - it_d->second;
		}
	}

	for (int n = 0; n < A.size();++n)
	{
		result[n] = nonDivisibleCounter[A[n]];
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

	vector<int> B = { 1,2,5,10,12,8,4,3 };
	vector<int> resultB = { 7,6,6,4,3,4,5,6 };

	vector<int> C = {3,5,11,6,1,5,2};
	vector<int> resultC = { 5,4,5,3,6,4,5 };

	vector<int> D = {5,5,5,5,5,5,5};
	vector<int> resultD = {0,0,0,0,0,0,0};

	vector<int> E = {};
	vector<int> resultE = {};

	// first lets return the leader and check if we are getting the correct answer
	assert(solution(A) == resultA);
	assert(solution(B) == resultB);
	assert(solution(C) == resultC);
	assert(solution(D) == resultD);
	assert(solution(E) == resultE);

	cout << "All tests passed" << endl;
	system("PAUSE");
}

