/*

A prime is a positive integer X that has exactly two distinct divisors: 1 and X. The first few prime integers are 2, 3, 5, 7, 11 and 13.

A prime D is called a prime divisor of a positive integer P if there exists a positive integer K such that D * K = P. For example, 2 and 5 are prime divisors of 20.

You are given two positive integers N and M. The goal is to check whether the sets of prime divisors of integers N and M are exactly the same.

For example, given:

N = 15 and M = 75, the prime divisors are the same: {3, 5};
N = 10 and M = 30, the prime divisors aren't the same: {2, 5} is not equal to {2, 3, 5};
N = 9 and M = 5, the prime divisors aren't the same: {3} is not equal to {5}.

Write a function:

int solution(vector<int> &A, vector<int> &B);

that, given two non-empty arrays A and B of Z integers, returns the number of positions K for which the prime divisors of A[K] and B[K] are exactly the same.

For example, given:
A[0] = 15   B[0] = 75
A[1] = 10   B[1] = 30
A[2] = 3    B[2] = 5

the function should return 1, because only one pair (15, 75) has the same set of prime divisors.

Write an efficient algorithm for the following assumptions:

Z is an integer within the range [1..6,000];
each element of arrays A, B is an integer within the range [1..2,147,483,647].

Copyright 2009–2020 by Codility Limited. All Rights Reserved. Unauthorized copying, publication or disclosure prohibited.

*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>

typedef unsigned long long int l_int;

using namespace std;

l_int GCD(l_int N, l_int M)
{
	if (N % M == 0)
	{
		return M;
	}
	else
	{
		return GCD(M, (N%M));
	}

}

std::pair<l_int,l_int> LCM(l_int N, l_int M)
{
	l_int gcd = GCD(N,M);

	return (std::pair<l_int,l_int>(((N*M) / gcd),gcd));
}


int solution(vector<int> &A, vector<int> &B)
{
	int result = 0;
	/*
	** Logic: found logic from test cases
	** step1: find LCM of A,B
	** step2: find GCD of A,B
	** step3: find int N = LCM/GCD
	** step4: check if A%N==0 and B%N==0 => prime divisors are same
	*/
	for (int m = 0; m < A.size(); ++m)
	{
		//step1+step2
		std::pair<l_int, l_int> lcm_gcd = LCM(A[m], B[m]);

		//step 3
		l_int N = lcm_gcd.first / lcm_gcd.second;

		if ((A[m] % N == 0) && (B[m] % N == 0))
		{
			result++;
		}
	}
	
	return result;
}

void main()
{
	// refer : https://docs.microsoft.com/en-us/cpp/build/reference/zc-cplusplus?view=vs-2015
	printf("%ld\n", __cplusplus); // this is by default C++98 but C++ Language std used is actually C++14
	printf("%ld\n", _MSC_VER);    // MSVC version VC++ 14.0
	printf("%ld\n", _MSVC_LANG);  // shows unidentified due to Intellisense but Macro is defined.

	vector<int> A = { 15,10,3,12,12,17 };
	vector<int> B = { 75,30,5,18,14,34 };
	int result_AB = 2;

	// first lets return the leader and check if we are getting the correct answer
	assert(solution(A,B) == result_AB);	
	
	cout << "All tests passed" << endl;
	system("PAUSE");
}

