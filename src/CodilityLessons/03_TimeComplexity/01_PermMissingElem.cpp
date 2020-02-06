
/*

Codility Tasks:


An array A consisting of N different integers is given. The array contains integers in the range [1..(N + 1)], which means that exactly one element is missing.

Your goal is to find that missing element.

Write a function:

int solution(vector<int> &A);

that, given an array A, returns the value of the missing element.

For example, given array A such that:
A[0] = 2
A[1] = 3
A[2] = 1
A[3] = 5

the function should return 4, as it is the missing element.

Write an efficient algorithm for the following assumptions:

N is an integer within the range [0..100,000];
the elements of A are all distinct;
each element of array A is an integer within the range [1..(N + 1)].




*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int PermMissingElem(vector<int> &A)
{
	if (A.empty())
		return 1;

	sort(A.begin(), A.end());
	//int numberOfEltsA = A.size();

	int count = 1;

	for (vector<int>::iterator i = A.begin(); i != A.end(); i++)
	{
		if (count != *i)
		{
			return count;
		}
			
		count++;
	}

	return count;
}

void main()
{
	vector<int> A;
	A = {2,3,1,5};
	int result;
	result = PermMissingElem(A);

	cout << "missing element = " << result << endl;
	system("PAUSE");
}