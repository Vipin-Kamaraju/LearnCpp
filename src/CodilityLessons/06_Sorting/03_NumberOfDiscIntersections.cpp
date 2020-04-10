/*

We draw N discs on a plane. The discs are numbered from 0 to N - 1. An array A of N non-negative integers, specifying the radiuses of the discs, is given. 
The J-th disc is drawn with its center at (J, 0) and radius A[J].

We say that the J-th disc and K-th disc intersect if J ? K and the J-th and K-th discs have at least one common point (assuming that the discs contain their borders).

The figure below shows discs drawn for N = 6 and A as follows:
A[0] = 1
A[1] = 5
A[2] = 2
A[3] = 1
A[4] = 4
A[5] = 0

There are eleven (unordered) pairs of discs that intersect, namely:

discs 1 and 4 intersect, and both intersect with all the other discs;
disc 2 also intersects with discs 0 and 3.

Write a function:

int solution(vector<int> &A);

that, given an array A describing N discs as explained above, returns the number of (unordered) pairs of intersecting discs. 
The function should return -1 if the number of intersecting pairs exceeds 10,000,000.

Given array A shown above, the function should return 11, as explained above.

Write an efficient algorithm for the following assumptions:

N is an integer within the range [0..100,000];
each element of array A is an integer within the range [0..2,147,483,647].

Copyright 2009–2020 by Codility Limited. All Rights Reserved. Unauthorized copying, publication or disclosure prohibited.

*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> &A)
{
	/*
	** Logic: maxA < minB || minA > maxB
	** If either if the above condition is true then A does not intersect B
	*/
	int result = 0;
	vector<int> minValues;
	vector<int> maxValues;
	int minValue;
	int maxValue;
	int discIntersections = 0;

	if (A.size() == 0)
	{
		return result;
	}

	for (int m = 0; m < A.size(); ++m)
	{
		minValue = m - A[m];
		minValues.push_back(minValue);
		maxValue = m + A[m];
		maxValues.push_back(maxValue);
	
	}

	int minValue2;
	int maxValue2;

	for (int r = 0; r < A.size(); ++r)
	{
		minValue2 = r - A[r];
		maxValue2 = r + A[r];

		for (int n = 0; n < minValues.size(); ++n)
		{
			if((maxValue2 < minValues[n]) || (minValue2 > maxValues[n]))
			{ }
			else
			{
				discIntersections++;
			}
		}

	}

	discIntersections = discIntersections - A.size();

	result = discIntersections / 2;

	if (result > 10000000)
	{
		result = -1;
	}

	return result;
}

void main()
{
	//vector<int> A = { 1,5,2,1,4,0 };
	vector<int> A = { 3,3,3,5,1,2 };
	int result = solution(A);
	cout << result << endl;
	system("PAUSE");
}

