
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
	** Idea is to use something similar to a LUT. By creating an array with the sums. This idea did not give 100%performance
	** Refer to the pdf provided in the lessons on Codility
	** Mathematically prooved that only slices of size 2 and size 3 is sufficient to find the minIdx
	** Theoretical proof for this problem description can be found here:
	** https://github.com/daotranminh/playground/blob/master/src/codibility/MinAvgTwoSlice/proof.pdf
	*/


	double sum = 0;
	double avg;
	double minAvg = std::numeric_limits<double>::max();
	unsigned int minIdx;
	
	for (unsigned int idx = 0; idx < A.size() - 1; ++idx)
	{
		sum = A[idx]+A[idx+1];
		avg = sum / 2;

		if (avg < minAvg)
		{
			minIdx = idx;
			minAvg = avg;
		}

		if ((idx + 2) < A.size())
		{
			sum = sum + A[idx + 2];
			avg = sum / 3;
			if (avg < minAvg)
			{
				minIdx = idx;
				minAvg = avg;
			}
		}
	}

	

	return minIdx;
}


void main()
{

	vector<int> A = { 4,2,2,5,1,5,8 };
	int result;
	result = solution(A);
	
	system("PAUSE");
}

