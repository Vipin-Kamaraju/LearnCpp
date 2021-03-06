/*

Two positive integers N and M are given. Integer N represents the number of chocolates arranged in a circle, numbered from 0 to N - 1.

You start to eat the chocolates. After eating a chocolate you leave only a wrapper.

You begin with eating chocolate number 0. Then you omit the next M - 1 chocolates or wrappers on the circle, and eat the following one.

More precisely, if you ate chocolate number X, then you will next eat the chocolate with number (X + M) modulo N (remainder of division).

You stop eating when you encounter an empty wrapper.

For example, given integers N = 10 and M = 4. You will eat the following chocolates: 0, 4, 8, 2, 6.

The goal is to count the number of chocolates that you will eat, following the above rules.

Write a function:

int solution(int N, int M);

that, given two positive integers N and M, returns the number of chocolates that you will eat.

For example, given integers N = 10 and M = 4. the function should return 5, as explained above.

Write an efficient algorithm for the following assumptions:

N and M are integers within the range [1..1,000,000,000].

Copyright 2009�2020 by Codility Limited. All Rights Reserved. Unauthorized copying, publication or disclosure prohibited.

*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>

typedef long long int l_int;

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

l_int LCM(l_int N, l_int M)
{
	l_int gcd = GCD(N,M);

	return ((N*M) / gcd);
}

int solution(int N, int M)
{
	/*
	** 2 solutions possible. The first solution was 100% correctnes but crashes due to large vector size
	** 
	** Logic : The answer to this problem  =  LCM(a,b)/M;
	** Also, LCM = a.b/gcd(a,b); refer to reading material
	** GCD(a,b) = GCD(b, a%b)
	*/
	
	return (LCM(N,M)/M);
}

void main()
{
	// refer : https://docs.microsoft.com/en-us/cpp/build/reference/zc-cplusplus?view=vs-2015
	printf("%ld\n", __cplusplus); // this is by default C++98 but C++ Language std used is actually C++14
	printf("%ld\n", _MSC_VER);    // MSVC version VC++ 14.0
	printf("%ld\n", _MSVC_LANG);  // shows unidentified due to Intellisense but Macro is defined.

	int A = 10;
	int B = 4;
	int result_AB = 5;

	int C = 12;
	int D = 21;
	int result_CD = 4;

	int E = 1000000000;
	int F = 1;

	// first lets return the leader and check if we are getting the correct answer
	assert(solution(A,B) == result_AB);	
	assert(solution(C,D) == result_CD);

	assert(solution(E,F) == 1e9);

	cout << "All tests passed" << endl;
	system("PAUSE");
}

