/*

A prime is a positive integer X that has exactly two distinct divisors: 1 and X. The first few prime integers are 2, 3, 5, 7, 11 and 13.

A semiprime is a natural number that is the product of two (not necessarily distinct) prime numbers. The first few semiprimes are 4, 6, 9, 10, 14, 15, 21, 22, 25, 26.

You are given two non-empty arrays P and Q, each consisting of M integers. These arrays represent queries about the number of semiprimes within specified ranges.

Query K requires you to find the number of semiprimes within the range (P[K], Q[K]), where 1 = P[K] = Q[K] = N.

For example, consider an integer N = 26 and arrays P, Q such that:
P[0] = 1    Q[0] = 26
P[1] = 4    Q[1] = 10
P[2] = 16   Q[2] = 20

The number of semiprimes within each of these ranges is as follows:

(1, 26) is 10,
(4, 10) is 4,
(16, 20) is 0.

Write a function:

vector<int> solution(int N, vector<int> &P, vector<int> &Q);

that, given an integer N and two non-empty arrays P and Q consisting of M integers, returns an array consisting of M elements specifying the consecutive answers to all the queries.

For example, given an integer N = 26 and arrays P, Q such that:
P[0] = 1    Q[0] = 26
P[1] = 4    Q[1] = 10
P[2] = 16   Q[2] = 20

the function should return the values [10, 4, 0], as explained above.

Write an efficient algorithm for the following assumptions:

N is an integer within the range [1..50,000];
M is an integer within the range [1..30,000];
each element of arrays P, Q is an integer within the range [1..N];
P[i] = Q[i].

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

vector<int> solution(int N, vector<int>& P, vector<int>& Q)
{
	/*
	** Logic : use the modified verison Eratosthenes method
	** Refer to the reading material provided for this chapter on Factorization
	** step1 : create a sort of LUT of factors using the Eratosthenes method
	** 
	*/
	vector<int> result;

	// factorization LUT
	vector<int> factors(N+1, 0);
	if (factors.size() >= 2)
	{
		factors[0] = 1;
		factors[1] = 1;
	}
	int k;
	for (int i = 2; i*i < N; ++i)
	{
		if (factors[i] == 0)
		{
			k = i*i;
		}
		while (k <= N)
		{
			if (factors[k] == 0)
			{
				factors[k] = i;
			}
			k = k + i;
		}
	}

	if (factors.size() >= 2)
	{
		factors[0] = 1;
		factors[1] = 1;
	}

	//map<int, int> primeFactors(N+1,0);
	vector<int> primeFactors(N + 1, 0);
	int factor2 = 4;

	// prime factors calculation
	for (int n = 2; n <= N; ++n)
	{
		if (factors[n] > 0)
		{
			factor2 = (n / factors[n]);
			if (factors[factor2] == 0)
			{
				primeFactors[n] = 1;
			}
		}

	}

	// iterate over P & Q
	for (int j = 0; j < P.size(); ++j)
	{
		int lowerLimit = P[j];
		int upperLimit = Q[j];
		int counterFactors = 0;

		for (int k = lowerLimit; k <= upperLimit; ++k)
		{
			if (primeFactors[k] == 1)
			{
				counterFactors++;
			}
		}
		result.push_back(counterFactors);
	}

	return result;
}

void main()
{
	// refer : https://docs.microsoft.com/en-us/cpp/build/reference/zc-cplusplus?view=vs-2015
	printf("%ld\n", __cplusplus); // this is by default C++98 but C++ Language std used is actually C++14
	printf("%ld\n", _MSC_VER);    // MSVC version VC++ 14.0
	printf("%ld\n", _MSVC_LANG);  // shows unidentified due to Intellisense but Macro is defined.

	int N = 26;
	vector<int> A = { 1,4,16 };
	vector<int> B = { 26,10,20 };
	vector<int> result = { 10,4,0};

	

	// first lets return the leader and check if we are getting the correct answer
	assert(solution(N,A,B) == result);
	

	cout << "All tests passed" << endl;
	system("PAUSE");
}

