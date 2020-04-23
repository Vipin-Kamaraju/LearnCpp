/*

You have to climb up a ladder. The ladder has exactly N rungs, numbered from 1 to N. With each step, you can ascend by one or two rungs. More precisely:

with your first step you can stand on rung 1 or 2,
if you are on rung K, you can move to rungs K + 1 or K + 2,
finally you have to stand on rung N.

Your task is to count the number of different ways of climbing to the top of the ladder.

For example, given N = 4, you have five different ways of climbing, ascending by:

1, 1, 1 and 1 rung,
1, 1 and 2 rungs,
1, 2 and 1 rung,
2, 1 and 1 rungs, and
2 and 2 rungs.

Given N = 5, you have eight different ways of climbing, ascending by:

1, 1, 1, 1 and 1 rung,
1, 1, 1 and 2 rungs,
1, 1, 2 and 1 rung,
1, 2, 1 and 1 rung,
1, 2 and 2 rungs,
2, 1, 1 and 1 rungs,
2, 1 and 2 rungs, and
2, 2 and 1 rung.

The number of different ways can be very large, so it is sufficient to return the result modulo 2P, for a given integer P.

Write a function:

vector<int> solution(vector<int> &A, vector<int> &B);

that, given two non-empty arrays A and B of L integers, returns an array consisting of L integers specifying the consecutive answers; position I should contain the number of different ways of climbing the ladder with A[I] rungs modulo 2B[I].

For example, given L = 5 and:
A[0] = 4   B[0] = 3
A[1] = 4   B[1] = 2
A[2] = 5   B[2] = 4
A[3] = 5   B[3] = 3
A[4] = 1   B[4] = 1

the function should return the sequence [5, 1, 8, 0, 1], as explained above.

Write an efficient algorithm for the following assumptions:

L is an integer within the range [1..50,000];
each element of array A is an integer within the range [1..L];
each element of array B is an integer within the range [1..30].

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

struct PathTracker
{
	int location;
	int jump;
	PathTracker(int l, int j) : location(l), jump(j)
	{}

};

void generateFibonacciSeries(int N, vector<l_int>& fibonacci)
{
	fibonacci.push_back(0);
	fibonacci.push_back(1);
	l_int value = 0;

	for (int i = 2; i <= N +1; ++i)
	{
		value = fibonacci[i - 1] + fibonacci[i - 2];
		fibonacci.push_back(value);
	}

}

vector<int> solution(vector<int> &A, vector<int> &B)
{
	/*
	** Logic : This is very much similar to the coin changing problem but
	** the coin changing problem does not account for repetetions
	** when you list down the solution in the book you can see that the answer to the number of combinations for 
	** position x = Fibonacci(x+1); i.e number of ways to reach 4 is Fibonacci(5) = 5
	*/

	vector<int> result;
	vector<int> copyA(A.begin(), A.end());

	sort(copyA.begin(), copyA.end());
	int maxA = copyA.back();

	vector<l_int> fibonacci;
	generateFibonacciSeries(maxA, fibonacci);

	for (unsigned int i = 0; i < A.size(); ++i)
	{
		l_int combinations = fibonacci[A[i] + 1];
		l_int m = pow(2, B[i]);
		combinations = (combinations % m);
		result.push_back(combinations);
	}
	
	return result;
}

void main()
{
	// refer : https://docs.microsoft.com/en-us/cpp/build/reference/zc-cplusplus?view=vs-2015
	printf("%ld\n", __cplusplus); // this is by default C++98 but C++ Language std used is actually C++14
	printf("%ld\n", _MSC_VER);    // MSVC version VC++ 14.0
	printf("%ld\n", _MSVC_LANG);  // shows unidentified due to Intellisense but Macro is defined.

	vector<int> A = { 4,4,5,5,1,97 };
	vector<int> B = { 3,2,4,3,1,11 };
	vector<int> result_AB = {5,1,8,0,1,1729};

	// first lets return the leader and check if we are getting the correct answer
	assert(solution(A,B) == result_AB);	

	cout << "All tests passed" << endl;
	system("PAUSE");
}

