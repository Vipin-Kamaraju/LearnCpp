/*

An array A consisting of N integers is given. The dominator of array A is the value that occurs in more than half of the elements of A.

For example, consider array A such that
A[0] = 3    A[1] = 4    A[2] =  3
A[3] = 2    A[4] = 3    A[5] = -1
A[6] = 3    A[7] = 3

The dominator of A is 3 because it occurs in 5 out of 8 elements of A (namely in those with indices 0, 2, 4, 6 and 7) and 5 is more than a half of 8.

Write a function

int solution(vector<int> &A);

that, given an array A consisting of N integers, returns index of any element of array A in which the dominator of A occurs. The function should return -1 if array A does not have a dominator.

For example, given array A such that
A[0] = 3    A[1] = 4    A[2] =  3
A[3] = 2    A[4] = 3    A[5] = -1
A[6] = 3    A[7] = 3

the function may return 0, 2, 4, 6 or 7, as explained above.

Write an efficient algorithm for the following assumptions:

N is an integer within the range [0..100,000];
each element of array A is an integer within the range [-2,147,483,648..2,147,483,647].

Copyright 2009–2020 by Codility Limited. All Rights Reserved. Unauthorized copying, publication or disclosure prohibited.

*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <string>
#include <stack>

typedef long long int l_int;

using namespace std;

int solution(vector<int> &A)
{
	/*
	** Logic : Refer to the reading material of this chapter. It has a very good explanation for 
	** getting the solution in O(N) time complexity
	** we can also use sorting method but sort() has O(N log N) time complexity
	*/

	if (A.size() == 0)
	{
		return -1;
	}

	// Stack with value and index of the Leader/Dominator
	stack<std::pair<int, int>> stackDominator;

	for (unsigned int m = 0; m < A.size(); ++m)
	{
		if (stackDominator.empty())
		{
			stackDominator.push(std::pair<int,int>(A[m], m));
		}
		else if (stackDominator.top().first != A[m])
		{
			stackDominator.pop();
		}
		else if (stackDominator.top().first == A[m])
		{
			stackDominator.push(std::pair<int, int>(A[m], m));
		}
	}

	int leaderElement = stackDominator.top().first;
	unsigned int count = 0;

	// check if the top element in the stack is actually the leader O(N) complexity
	if (!stackDominator.empty())
	{
		for (auto it_A = A.begin(); it_A != A.end(); ++it_A)
		{
			if (*it_A == leaderElement)
			{
				count++;
			}
		}
	}
	else
	{
		return -1;
	}

	if (count > (A.size() / 2))
	{
		return stackDominator.top().second;
	}
	else
	{
		return -1;
	}
}

void main()
{
	// refer : https://docs.microsoft.com/en-us/cpp/build/reference/zc-cplusplus?view=vs-2015
	printf("%ld\n", __cplusplus); // this is by default C++98 but C++ Language std used is actually C++14
	printf("%ld\n", _MSC_VER);    // MSVC version VC++ 14.0
	printf("%ld\n", _MSVC_LANG);  // shows unidentified due to Intellisense but Macro is defined.

	vector<int> A = { 3,4,3,2,3,-1,3,3 };
	vector<int> B = { 3,4,3,4,3,4,3,5,1 };
	vector<int> C = { 6,8,4,6,8,6,6,6 };
	vector<int> D = { 6,8,4,6,8,6,6,3,3 };

	// first lets return the leader and check if we are getting the correct answer
	/*assert(solution(A) == 3);
	assert(solution(B) == -1);
	assert(solution(C) == 6);
	assert(solution(D) == -1);*/

	assert((solution(A) == 0) || (solution(A) == 2) || (solution(A) == 4) || (solution(A) == 6) || (solution(A) == 7));



	cout << "All tests passed" << endl;
	system("PAUSE");
}

