/*

A positive integer D is a factor of a positive integer N if there exists an integer M such that N = D * M.

For example, 6 is a factor of 24, because M = 4 satisfies the above condition (24 = 6 * 4).

Write a function:

int solution(int N);

that, given a positive integer N, returns the number of its factors.

For example, given N = 24, the function should return 8, because 24 has 8 factors, namely 1, 2, 3, 4, 6, 8, 12, 24. There are no other factors of 24.

Write an efficient algorithm for the following assumptions:

N is an integer within the range [1..2,147,483,647].

Copyright 2009–2020 by Codility Limited. All Rights Reserved. Unauthorized copying, publication or disclosure prohibited.

*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <string>
#include <stack>
#include <cmath>

typedef long long int l_int;

using namespace std;

int solution(int N)
{
	unsigned int sqrt_N = static_cast<unsigned int>(sqrt(N));
	vector<int> divisors;
	unsigned int secondDivisor;
	
	for (unsigned int i = 1; i <= sqrt_N; ++i)
	{
		if (N% i == 0)
		{
			divisors.push_back(i);

			secondDivisor = (N / i);
			if (secondDivisor != i)
			{
				divisors.push_back(secondDivisor);
			}
		}
	}

	return divisors.size();
}

void main()
{
	// refer : https://docs.microsoft.com/en-us/cpp/build/reference/zc-cplusplus?view=vs-2015
	printf("%ld\n", __cplusplus); // this is by default C++98 but C++ Language std used is actually C++14
	printf("%ld\n", _MSC_VER);    // MSVC version VC++ 14.0
	printf("%ld\n", _MSVC_LANG);  // shows unidentified due to Intellisense but Macro is defined.

	int A = 24;
	int B = 1;
	int C = 10;
	int D = 16;

	// first lets return the leader and check if we are getting the correct answer
	assert(solution(A) == 8);
	assert(solution(B) == 1);
	assert(solution(C) == 4);
	assert(solution(D) == 5);
	
	cout << "All tests passed" << endl;
	system("PAUSE");
}

