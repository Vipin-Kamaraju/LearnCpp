
/*



A small frog wants to get to the other side of a river. The frog is initially located on one bank of the river (position 0) and wants to get to the opposite bank (position X+1). Leaves fall from a tree onto the surface of the river.

You are given an array A consisting of N integers representing the falling leaves. A[K] represents the position where one leaf falls at time K, measured in seconds.

The goal is to find the earliest time when the frog can jump to the other side of the river. The frog can cross only when leaves appear at every position across the river from 1 to X (that is, we want to find the earliest moment when all the positions from 1 to X are covered by leaves). You may assume that the speed of the current in the river is negligibly small, i.e. the leaves do not change their positions once they fall in the river.

For example, you are given integer X = 5 and array A such that:
A[0] = 1
A[1] = 3
A[2] = 1
A[3] = 4
A[4] = 2
A[5] = 3
A[6] = 5
A[7] = 4

In second 6, a leaf falls into position 5. This is the earliest time when leaves appear in every position across the river.

Write a function:

int solution(int X, vector<int> &A);

that, given a non-empty array A consisting of N integers and integer X, returns the earliest time when the frog can jump to the other side of the river.

If the frog is never able to jump to the other side of the river, the function should return -1.

For example, given X = 5 and array A such that:
A[0] = 1
A[1] = 3
A[2] = 1
A[3] = 4
A[4] = 2
A[5] = 3
A[6] = 5
A[7] = 4

the function should return 6, as explained above.

Write an efficient algorithm for the following assumptions:

N and X are integers within the range [1..100,000];
each element of array A is an integer within the range [1..X].

*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int FrogRiverOne(int X, vector<int> &A)
{
	vector<int> copyA = A;
	sort(copyA.begin(), copyA.end());
	int LeafPos = 1;
	int iterationNum = 1;

	for (vector<int>::iterator i = copyA.begin(); i != copyA.end(); ++i)
	{
		//check all leaves from 1 to X
		if (LeafPos == *i)
			LeafPos++;
		iterationNum++;

		if (LeafPos == X)
		{
			cout << "iterationNum = " << iterationNum << endl;
			break;
		}
	}

	if (LeafPos < X)
	{
		cout << "Frog cannot reach the other end" << endl;
		return -1;
	}
	vector<int> ElemPosVec;
	int ElemPosInt = 0;
	for (int y = 1; y < X + 1; ++y)
	{
		for (vector<int>::iterator m = A.begin(); m != A.end(); ++m)
		{
			
			if (*m == y)
			{
				ElemPosVec.push_back(ElemPosInt);
				ElemPosInt = 0;
				break;
			}
			ElemPosInt++;
		}
	}

	
	
	return *max_element(ElemPosVec.begin(), ElemPosVec.end());
}

void main()
{
	vector<int> A = { 1,3,1,4,2,3,5,4,5 };
	int X = 5;
	int result = 0;

	result = FrogRiverOne(X, A);

	cout << "result = " << result << endl;
	system("PAUSE");
}