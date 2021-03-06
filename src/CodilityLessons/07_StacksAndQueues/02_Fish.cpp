/*

You are given two non-empty arrays A and B consisting of N integers. Arrays A and B represent N voracious fish in a river, ordered downstream along the flow of the river.

The fish are numbered from 0 to N - 1. If P and Q are two fish and P < Q, then fish P is initially upstream of fish Q. Initially, each fish has a unique position.

Fish number P is represented by A[P] and B[P]. Array A contains the sizes of the fish. All its elements are unique. Array B contains the directions of the fish. It contains only 0s and/or 1s, where:

0 represents a fish flowing upstream,
1 represents a fish flowing downstream.

If two fish move in opposite directions and there are no other (living) fish between them, they will eventually meet each other. Then only one fish can stay alive - the larger fish eats the smaller one. More precisely, we say that two fish P and Q meet each other when P < Q, B[P] = 1 and B[Q] = 0, and there are no living fish between them. After they meet:

If A[P] > A[Q] then P eats Q, and P will still be flowing downstream,
If A[Q] > A[P] then Q eats P, and Q will still be flowing upstream.

We assume that all the fish are flowing at the same speed. That is, fish moving in the same direction never meet. The goal is to calculate the number of fish that will stay alive.

For example, consider arrays A and B such that:
A[0] = 4    B[0] = 0
A[1] = 3    B[1] = 1
A[2] = 2    B[2] = 0
A[3] = 1    B[3] = 0
A[4] = 5    B[4] = 0

Initially all the fish are alive and all except fish number 1 are moving upstream. Fish number 1 meets fish number 2 and eats it, then it meets fish number 3 and eats it too. Finally, it meets fish number 4 and is eaten by it. The remaining two fish, number 0 and 4, never meet and therefore stay alive.

Write a function:

int solution(vector<int> &A, vector<int> &B);

that, given two non-empty arrays A and B consisting of N integers, returns the number of fish that will stay alive.

For example, given the arrays shown above, the function should return 2, as explained above.

Write an efficient algorithm for the following assumptions:

N is an integer within the range [1..100,000];
each element of array A is an integer within the range [0..1,000,000,000];
each element of array B is an integer that can have one of the following values: 0, 1;
the elements of A are all distinct.

Copyright 2009�2020 by Codility Limited. All Rights Reserved. Unauthorized copying, publication or disclosure prohibited.

*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <cassert>
#include <string>
#include <stack>

typedef long long int l_int;

using namespace std;

int solution(vector<int> &A, vector<int> &B)
{
	/*
	** Idea : the notation of upstream and downstream can be confusing
	** lets say 0 is fish moving left
	** 1 : fish is moving right
	** If fish is moving left 2 cases are possible
	**  - case 1: it is the first fish. Since its the first fish it will not be interrupted by other fish
	**	- case 2: There is a fish moving right. The stack shall have a fish moving in opp direction.
	** If the fish is moving right it will be added to the stack
	**
	** Can perform the same operation with vectors using the vector.back() function
	*/
	int result = 0;
	
	const int fishMovingLeft = 0;

	stack<int> fishStack;
	
	for (int m = 0; m < B.size(); ++m)
	{
		// check if fish is moving left
		if (fishMovingLeft == B[m])
		{
			while ((!fishStack.empty()) && (fishStack.top() < A[m]))
			{
				fishStack.pop();
			}
			if (fishStack.empty())
			{
				result++;  // These are the fishes that moved left and have no other fishes coming in opp direction
			}
		}
		// fish is moving right. It will be added to the stack
		else
		{
			fishStack.push(A[m]);
		}
	}

	return result + fishStack.size();
}

void main()
{
	// refer : https://docs.microsoft.com/en-us/cpp/build/reference/zc-cplusplus?view=vs-2015
	printf("%ld\n", __cplusplus); // this is by default C++98 but C++ Language std used is actually C++14
	printf("%ld\n", _MSC_VER);    // MSVC version VC++ 14.0
	printf("%ld\n", _MSVC_LANG);  // shows unidentified due to Intellisense but Macro is defined.
	
	vector<int> A = { 4,3,2,1,5 };
	vector<int> B = { 0,1,0,0,0 };

	vector<int> C = { 8,6,5,3,2,4,7 };
	vector<int> D = { 1,1,1,1,1,0,0 };

	assert(solution(A, B) == 2);
	assert(solution(C, D) == 1);

	cout << "All tests passed" << endl;
	system("PAUSE");
}

