
/*



A non-empty array A consisting of N integers is given. The consecutive elements of array A represent consecutive cars on a road.

Array A contains only 0s and/or 1s:

0 represents a car traveling east,
1 represents a car traveling west.

The goal is to count passing cars. We say that a pair of cars (P, Q), where 0 = P < Q < N, is passing when P is traveling to the east and Q is traveling to the west.

For example, consider array A such that:
A[0] = 0
A[1] = 1
A[2] = 0
A[3] = 1
A[4] = 1

We have five pairs of passing cars: (0, 1), (0, 3), (0, 4), (2, 3), (2, 4).

Write a function:

int solution(vector<int> &A);

that, given a non-empty array A of N integers, returns the number of pairs of passing cars.

The function should return -1 if the number of pairs of passing cars exceeds 1,000,000,000.

For example, given:
A[0] = 0
A[1] = 1
A[2] = 0
A[3] = 1
A[4] = 1

the function should return 5, as explained above.

Write an efficient algorithm for the following assumptions:

N is an integer within the range [1..100,000];
each element of array A is an integer that can have one of the following values: 0, 1.


*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int PassingCars(vector<int> &A)
{
	vector<int> copyA = A;
	//sort(copyA.begin(),copyA.end());
	int numberOfZeros = 0;
	int numberOfOnes = 0;
	for (auto i : copyA)
	{
		if (i == 0)
			numberOfZeros++;
		else if (i == 1)
			numberOfOnes++;
	}

	vector<int> passingCarsList;
	for (auto i : copyA)
	{
		if (i == 0)
			passingCarsList.push_back(numberOfOnes);
		else if (i == 1)
		{
			numberOfOnes = (numberOfOnes - 1);
			//cout << "numberOfOnes = " << numberOfOnes << endl;
		}
	}
	unsigned int result = 0; //2,147,483,647 since the test case failed when it has crossed this range
							 // It has flipped the bit when it crossed this range (50000 * 42950 )

	for (auto m : passingCarsList)
	{
		result = result + m;
		if (result > 1000000000)
		{
			result = -1;
			break;
		}
	}

	return result;
}

void main()
{
	int N = 5;
	//vector<int> A = {1,2,6,6,5,3,4,4,6,1,4,4};
	//vector<int> A = { 0,1,1,0,1,1 }; //8 - 2 = 6
	//vector<int> A = { 0,1,1,0,1,0,1 }; //12 - 5 = 7
	//vector<int> A = {0,1,0,1,1}; // 6 - 1 = 5
	//vector<int> A = { 0,1,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 };
	//vector<int> A = { 1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 };
	vector<int> A = { 1,1,1,1,1,1,1,1,1,1,1,1,1};
	int result;
	result = PassingCars(A);
	
	cout << "\nresult = " << result << endl;
	system("PAUSE");
}

