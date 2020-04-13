
/*

A non-empty array A consisting of N integers is given.

A permutation is a sequence containing each element from 1 to N once, and only once.

For example, array A such that:
A[0] = 4
A[1] = 1
A[2] = 3
A[3] = 2

is a permutation, but array A such that:
A[0] = 4
A[1] = 1
A[2] = 3

is not a permutation, because value 2 is missing.

The goal is to check whether array A is a permutation.

Write a function:

class Solution { public int solution(int[] A); }

that, given an array A, returns 1 if array A is a permutation and 0 if it is not.

For example, given array A such that:
A[0] = 4
A[1] = 1
A[2] = 3
A[3] = 2

the function should return 1.

Given array A such that:
A[0] = 4
A[1] = 1
A[2] = 3

the function should return 0.

Write an efficient algorithm for the following assumptions:

N is an integer within the range [1..100,000];
each element of array A is an integer within the range [1..1,000,000,000].


*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int PermCheck(vector<int> &A)
{
	int compareInt = 1;
	sort(A.begin(), A.end());
	for (vector<int>::iterator i = A.begin(); i != A.end(); ++i)
	{
		if (compareInt != *i)
		{
			cout << "compare Int " << compareInt << endl;
			return 0;
		}
		compareInt++;
	}
	return 1;
}

void main()
{
	vector<int> A;
	A = {3,1,2,5,6};
	int result;
	result = PermCheck(A);

	cout << "misssing element = " << result << endl;
	system("PAUSE");
}