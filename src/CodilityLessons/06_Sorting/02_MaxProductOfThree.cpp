/*

A non-empty array A consisting of N integers is given. The product of triplet (P, Q, R) equates to A[P] * A[Q] * A[R] (0 = P < Q < R < N).

For example, array A such that:
A[0] = -3
A[1] = 1
A[2] = 2
A[3] = -2
A[4] = 5
A[5] = 6

contains the following example triplets:

(0, 1, 2), product is -3 * 1 * 2 = -6
(1, 2, 4), product is 1 * 2 * 5 = 10
(2, 4, 5), product is 2 * 5 * 6 = 60

Your goal is to find the maximal product of any triplet.

Write a function:

int solution(vector<int> &A);

that, given a non-empty array A, returns the value of the maximal product of any triplet.

For example, given array A such that:
A[0] = -3
A[1] = 1
A[2] = 2
A[3] = -2
A[4] = 5
A[5] = 6

the function should return 60, as the product of triplet (2, 4, 5) is maximal.

Write an efficient algorithm for the following assumptions:

N is an integer within the range [3..100,000];
each element of array A is an integer within the range [-1,000..1,000].

Copyright 2009�2020 by Codility Limited. All Rights Reserved. Unauthorized copying, publication or disclosure prohibited.

*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> &A)
{
	/*
	** Approach : sort the array A. Here you will get the max elements on the extreme positions
	** We only need the extreme 5 elements to find the max triplet
	** This solution fails if all the elements are negative. 
	** hence additional case has to be written if all 5 elements are negative.
	*/
	int result = 0;

	sort(A.begin(), A.end());
	int N = A.size();
	
	if ((A[N - 2] * A[N - 3]) > (A[0] * A[1]))
	{
		result = (A[N - 2] * A[N - 3]) * (A[N - 1]);
	}
	else
	{
		result = (A[0] * A[1]) * (A[N - 1]);
	}
	

	return result;
}

void main()
{

	vector<int> A = { -3,1,2,-2,5,6 };
	int result = solution(A);
	cout << result << endl;
	system("PAUSE");
}

