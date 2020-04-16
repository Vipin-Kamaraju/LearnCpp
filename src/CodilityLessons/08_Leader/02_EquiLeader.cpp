/*

A non-empty array A consisting of N integers is given.

The leader of this array is the value that occurs in more than half of the elements of A.

An equi leader is an index S such that 0 = S < N - 1 and two sequences A[0], A[1], ..., A[S] and A[S + 1], A[S + 2], ..., A[N - 1] have leaders of the same value.

For example, given array A such that:
A[0] = 4
A[1] = 3
A[2] = 4
A[3] = 4
A[4] = 4
A[5] = 2

we can find two equi leaders:

0, because sequences: (4) and (3, 4, 4, 4, 2) have the same leader, whose value is 4.
2, because sequences: (4, 3, 4) and (4, 4, 2) have the same leader, whose value is 4.

The goal is to count the number of equi leaders.

Write a function:

int solution(vector<int> &A);

that, given a non-empty array A consisting of N integers, returns the number of equi leaders.

For example, given:
A[0] = 4
A[1] = 3
A[2] = 4
A[3] = 4
A[4] = 4
A[5] = 2

the function should return 2, as explained above.

Write an efficient algorithm for the following assumptions:

N is an integer within the range [1..100,000];
each element of array A is an integer within the range [-1,000,000,000..1,000,000,000].

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
	** Refer to the reading material of this chapter. It has a very good explanation for 
	** getting the solution in O(N) time complexity
	** This solution is same as the Dominator task
	** Logic: check if there is a leader for the array. If yes then can continue by checking equileaders
	** Idiom: If we remove a pair of unmatched elems then the rest of the pair will have the same leader
	** First we check if the array has a leader
	** If the array has a leader then compare the 'count' variable if it is greater than A/2 for both split array
	*/

	if (A.size() == 0)
	{
		return -1;
	}

	// Stack with value and index of the Leader/Dominator
	stack<std::pair<int, int>> stackDominator;
	int numOfEquiLeaders = 0;
	int currentLeaderCount = 0;
	int remainingLeaderCount = 0;
	int A_size_lhs = 0;
	int A_size_rhs = A.size();
	int result = 0;

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
		return 0;
	}

	remainingLeaderCount = count;
	if (count > (A.size() / 2))
	{
		for (int n = 0; n < A.size() ; ++n)
		{
			A_size_lhs++;
			A_size_rhs--;

			if (A[n] == leaderElement)
			{
				currentLeaderCount++;
				remainingLeaderCount--;
			}

			// check if the leader is same for both sides of split array
			if ((currentLeaderCount > A_size_lhs / 2) && (remainingLeaderCount > A_size_rhs / 2))
			{
				result++;
			}

		}
	}
	else
	{
		return 0;
	}

	return result;
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
	vector<int> E = { 4,3,4,4,4,2 };

	// first lets return the leader and check if we are getting the correct answer
	/*assert(solution(A) == 3);
	assert(solution(B) == -1);
	assert(solution(C) == 6);
	assert(solution(D) == -1);*/
	assert(solution(E) == 2);

	cout << "All tests passed" << endl;
	system("PAUSE");
}

