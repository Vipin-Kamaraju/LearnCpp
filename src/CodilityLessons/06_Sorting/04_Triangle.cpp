/*

An array A consisting of N integers is given. A triplet (P, Q, R) is triangular if 0 = P < Q < R < N and:

A[P] + A[Q] > A[R],
A[Q] + A[R] > A[P],
A[R] + A[P] > A[Q].

For example, consider array A such that:
A[0] = 10    A[1] = 2    A[2] = 5
A[3] = 1     A[4] = 8    A[5] = 20

Triplet (0, 2, 4) is triangular.

Write a function:

int solution(vector<int> &A);

that, given an array A consisting of N integers, returns 1 if there exists a triangular triplet for this array and returns 0 otherwise.

For example, given array A such that:
A[0] = 10    A[1] = 2    A[2] = 5
A[3] = 1     A[4] = 8    A[5] = 20

the function should return 1, as explained above. Given array A such that:
A[0] = 10    A[1] = 50    A[2] = 5
A[3] = 1

the function should return 0.

Write an efficient algorithm for the following assumptions:

N is an integer within the range [0..100,000];
each element of array A is an integer within the range [-2,147,483,648..2,147,483,647].

Copyright 2009–2020 by Codility Limited. All Rights Reserved. Unauthorized copying, publication or disclosure prohibited.

*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool IsLessThanZero(int i)
{
	return (i < 0);
}
int solution(vector<int> &A)
{
	/*
	** Approach : sort the array A.
	** check the mid most element if they satisfy the condition
	** Else I think it will fail for all other conditions
	*/
	int result = 0;

	sort(A.begin(), A.end());
	auto last = remove_if(A.begin(), A.end(), IsLessThanZero);
	A.erase(last, A.end());

	int size = A.size();
	int N;
	
	N = size / 2;

	unsigned int total1;
	unsigned int total2;
	unsigned int total3;

	if (size >= 3)
	{
		total1 = A[N - 1] + A[N + 1];
		total2 = A[N - 1] + A[N];
		total3 = A[N] + A[N + 1];

		if ((A[N] < total1 ) && (A[N + 1] < total2) && (A[N - 1] < total3))
		{
			result = 1;
		}
	}
	if (size >= 4)
	{
		N = N + 1;
		total1 = A[N - 1] + A[N + 1];
		total2 = A[N - 1] + A[N];
		total3 = A[N] + A[N + 1];
		if ((A[N] < total1) && (A[N + 1] < total2) && (A[N - 1] < total3))
		{
			result = 1;
		}
	}
	

	return result;
}

void main()
{
	//vector<int> A = {1,1,2,3,5};
	//vector<int> A = { 1,1,1,1,5,5,5 };
	vector<int> A = { 2147483647,2147483647,2147483647 };
	int result = solution(A);
	cout << result << endl;
	system("PAUSE");
}

