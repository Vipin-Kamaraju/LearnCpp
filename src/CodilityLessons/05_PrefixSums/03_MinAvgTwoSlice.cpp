
/*


A non-empty array A consisting of N integers is given. A pair of integers (P, Q), such that 0 = P < Q < N, is called a slice of array A 
(notice that the slice contains at least two elements). The average of a slice (P, Q) is the sum of A[P] + A[P + 1] + ... + A[Q] divided by the length of the slice. 
To be precise, the average equals (A[P] + A[P + 1] + ... + A[Q]) / (Q - P + 1).

For example, array A such that:
A[0] = 4
A[1] = 2
A[2] = 2
A[3] = 5
A[4] = 1
A[5] = 5
A[6] = 8

contains the following example slices:

slice (1, 2), whose average is (2 + 2) / 2 = 2;
slice (3, 4), whose average is (5 + 1) / 2 = 3;
slice (1, 4), whose average is (2 + 2 + 5 + 1) / 4 = 2.5.

The goal is to find the starting position of a slice whose average is minimal.

Write a function:

int solution(vector<int> &A);

that, given a non-empty array A consisting of N integers, returns the starting position of the slice with the minimal average. 
If there is more than one slice with a minimal average, you should return the smallest starting position of such a slice.

For example, given array A such that:
A[0] = 4
A[1] = 2
A[2] = 2
A[3] = 5
A[4] = 1
A[5] = 5
A[6] = 8

the function should return 1, as explained above.

Write an efficient algorithm for the following assumptions:

N is an integer within the range [2..100,000];
each element of array A is an integer within the range [-10,000..10,000].

Copyright 2009–2020 by Codility Limited. All Rights Reserved. Unauthorized copying, publication or disclosure prohibited. */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> &A)
{
	/*
	** Idea is to use something similar to a LUT. By creating an array with the sums
	** Refer to the pdf provided in the lessons on Codility
	*/

	int result = 0;
	vector<int> ArraySum;
	int sum = 0;

	float slice = 0;
	float minSliceValue;
	bool firstLoop = true;
	int min_Q_Pos;
	float slice2D[7][7] = { 0 };
	ArraySum.push_back(sum);
	
	for (std::vector<int>::iterator it = A.begin(); it != A.end(); ++it)
	{
		sum = sum + (*it);
		ArraySum.push_back(sum);
	}
	int count = 0;
	/*for (int P_Pos = 0; P_Pos < A.size() ; ++P_Pos)
	{
		for (int Q_Pos = P_Pos + 1; Q_Pos < A.size(); ++Q_Pos)
		{
			slice = float(float(ArraySum.at(Q_Pos+1) - ArraySum.at(P_Pos)) / float((Q_Pos)-(P_Pos)+1));
			slice2D[P_Pos][Q_Pos] = slice;
			if (firstLoop)
			{
				minSliceValue = slice;
				firstLoop = false;
				result = P_Pos;
				min_Q_Pos = Q_Pos;
			}
			
			if (slice < minSliceValue)
			{
				minSliceValue = slice;
				result = P_Pos;
				min_Q_Pos = Q_Pos;
			}
			count++;
		}
	}*/

	/*for (int P_Pos = 0;P_Pos < A.size(); ++P_Pos)
	{
		slice = ArraySum.at(P_Pos + 1 + 1) - ArraySum.at(P_Pos) / P_Pos + 1 - P_Pos + 1;
		slice = ArraySum.at(P_Pos + 1 + 2) - ArraySum.at(P_Pos) / P_Pos + 2 - P_Pos + 1;
		slice = ArraySum.at(P_Pos + 1 + 3) - ArraySum.at(P_Pos) / P_Pos + 3 - P_Pos + 1;
		slice = ArraySum.at(P_Pos + 1 + 4) - ArraySum.at(P_Pos) / P_Pos + 4 - P_Pos + 1;
		slice = ArraySum.at(P_Pos + 1 + 5) - ArraySum.at(P_Pos) / P_Pos + 5 - P_Pos + 1;
		slice = ArraySum.at(P_Pos + 1 + 6) - ArraySum.at(P_Pos) / P_Pos + 6 - P_Pos + 1;
	}

	for (int P_Pos = 0;P_Pos < A.size(); ++P_Pos)
	{
		slice = ArraySum.at(P_Pos + 2) - ArraySum.at(P_Pos) / 2;
		slice = ArraySum.at(P_Pos + 3) - ArraySum.at(P_Pos) / 3;
		slice = ArraySum.at(P_Pos + 4) - ArraySum.at(P_Pos) / 4;
		slice = ArraySum.at(P_Pos + 5) - ArraySum.at(P_Pos) / 5;
		slice = ArraySum.at(P_Pos + 6) - ArraySum.at(P_Pos) / 6;
		slice = ArraySum.at(P_Pos + 7) - ArraySum.at(P_Pos) / 7;
	}
*/
	int counter = 2;
	for (int P_Pos = 0; P_Pos < (A.size() - 1); counter++)
	{
		slice = float(ArraySum.at(P_Pos + counter) - ArraySum.at(P_Pos)) / float(counter);

		if (firstLoop)
		{
			minSliceValue = slice;
			firstLoop = false;
			result = P_Pos;
		}

		if (slice < minSliceValue)
		{
			minSliceValue = slice;
			result = P_Pos;
		}

		if ((P_Pos + counter) >= A.size())
		{
			counter = 1;
			P_Pos++;
		}
		count++;
	}

	return result;
}


void main()
{

	vector<int> A = { 4,2,2,5,1,5,8 };
	int result;
	result = solution(A);
	
	system("PAUSE");
}

