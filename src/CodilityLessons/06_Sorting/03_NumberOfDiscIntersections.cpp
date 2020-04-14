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
#include <map>
#include <cassert>

#define MAX_DISC_INTERSECTIONS 1e7
using namespace std;

typedef long long int l_int;

bool checkRHS(const std::pair<l_int, l_int>& comparisionValue, const std::pair<l_int, l_int>& currentVal)
{
	return (comparisionValue.first < currentVal.first);
}

int solution(vector<int> &A)
{

	vector<std::pair<l_int,l_int>> A_range;
	l_int A_size = A.size();
	l_int minValue;
	l_int maxValue;
	int count;
	l_int discIntersections = 0;
	l_int zeroVal = 0;

	if (A.size() == 0 | A.size() == 1)
	{
		return 0;
	}

	for (l_int m = 0; m < A_size; ++m)
	{
		minValue = m - A[m];
		minValue = max(zeroVal, minValue);
		maxValue = m + A[m];
		maxValue = min((A_size -1 ), maxValue);


		A_range.push_back(std::pair<l_int, l_int>(minValue, maxValue));
	}

	sort(A_range.begin(), A_range.end());

	for (l_int n = 0; n < A_range.size(); ++n)
	{
		long discEnd = A_range[n].second;

		auto it = upper_bound(A_range.begin(), A_range.end(), make_pair(discEnd, zeroVal), checkRHS );

		count = distance(A_range.begin(), it); // counting number of intersections at index i

		count = count - (n + 1); // Removing self intersections /  Removing repetetions
		
		discIntersections = discIntersections + count;
	}

	if (discIntersections > MAX_DISC_INTERSECTIONS)
	{
		return -1;
	}

	return discIntersections;
}

void main()
{

	vector<int> A = { 1,5,2,1,4,0 };
	vector<int> B = { 3,3,3,5,1,2 }; 
	vector<int> C = { 1,2147483647,0 }; // result 2
	vector<int> D = { 1,0,2147483647 }; // result 3
	vector<int> E = { 2147483647,2147483647 };
	vector<int> F = { 5 };
	vector<int> G = { 0,0,0,0,5}; //result 4
	vector<int> H = { 0,0,0,0,0 }; // result 0
	vector<int> I = { 1,2147483647,0,2147483647 }; // result 4
	int result = solution(A);
	
	
	assert(solution(A) == 11);
	assert(solution(B) == 15);
	assert(solution(C) == 2);
	assert(solution(D) == 3);
	assert(solution(E) == 1);
	assert(solution(F) == 0);
	assert(solution(G) == 4);
	assert(solution(H) == 0);
	assert(solution(I) == 5);

	cout << result << endl;
	system("PAUSE");
}

