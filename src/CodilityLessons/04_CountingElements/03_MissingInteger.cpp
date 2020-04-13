
/*


You are given N counters, initially set to 0, and you have two possible operations on them:

increase(X) - counter X is increased by 1,
max counter - all counters are set to the maximum value of any counter.

A non-empty array A of M integers is given. This array represents consecutive operations:

if A[K] = X, such that 1 = X = N, then operation K is increase(X),
if A[K] = N + 1 then operation K is max counter.

For example, given integer N = 5 and array A such that:
A[0] = 3
A[1] = 4
A[2] = 4
A[3] = 6
A[4] = 1
A[5] = 4
A[6] = 4

the values of the counters after each consecutive operation will be:
(0, 0, 1, 0, 0)
(0, 0, 1, 1, 0)
(0, 0, 1, 2, 0)
(2, 2, 2, 2, 2)
(3, 2, 2, 2, 2)
(3, 2, 2, 3, 2)
(3, 2, 2, 4, 2)

The goal is to calculate the value of every counter after all operations.

Write a function:

vector<int> solution(int N, vector<int> &A);

that, given an integer N and a non-empty array A consisting of M integers, returns a sequence of integers representing the values of the counters.

Result array should be returned as a vector of integers.

For example, given:
A[0] = 3
A[1] = 4
A[2] = 4
A[3] = 6
A[4] = 1
A[5] = 4
A[6] = 4

the function should return [3, 2, 2, 4, 2], as explained above.

Write an efficient algorithm for the following assumptions:

N and M are integers within the range [1..100,000];
each element of array A is an integer within the range [1..N + 1].


*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void Increment(int X,vector<int> &A)
{
	A.at(X-1) = A.at(X-1) + 1;
}

void IncrementAll(vector<int> &A)
{
	int max = *max_element(A.begin(), A.end());
	for (int i =0; i < A.size(); ++i)
	{
		A[i] = max;
	}
}

vector<int> MaxCounters(int N, vector<int> &A)
{
	vector<int> copyA(N,0);
	int X;

	for (vector<int>::iterator itr = A.begin(); itr != A.end(); ++itr)
	{
		X = *itr;
		if ((X <= N) && (X >= 1) && (X != (N + 1)))
		{
			Increment(X, copyA);
		}
		else if (X == (N + 1))
		{
			IncrementAll(copyA);
		}
	}
	
	return copyA;
}

void main()
{
	int N = 5;
	vector<int> A = {3,4,4,6,1,4,4};
	vector<int> result;
	result = MaxCounters(N, A);
	for(auto i : result)
	cout << "\nresult = " << i << endl;
	system("PAUSE");
}