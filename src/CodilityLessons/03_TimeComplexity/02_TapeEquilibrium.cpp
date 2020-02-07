
/*
Codility Tasks:

A non-empty array A consisting of N integers is given. Array A represents numbers on a tape.

Any integer P, such that 0 < P < N, splits this tape into two non-empty parts: A[0], A[1], ..., A[P - 1] and A[P], A[P + 1], ..., A[N - 1].

The difference between the two parts is the value of: |(A[0] + A[1] + ... + A[P - 1]) - (A[P] + A[P + 1] + ... + A[N - 1])|

In other words, it is the absolute difference between the sum of the first part and the sum of the second part.

For example, consider array A such that:
A[0] = 3
A[1] = 1
A[2] = 2
A[3] = 4
A[4] = 3

We can split this tape in four places:

P = 1, difference = |3 - 10| = 7
P = 2, difference = |4 - 9| = 5
P = 3, difference = |6 - 7| = 1
P = 4, difference = |10 - 3| = 7

Write a function:

int solution(vector<int> &A);

that, given a non-empty array A of N integers, returns the minimal difference that can be achieved.

For example, given:
A[0] = 3
A[1] = 1
A[2] = 2
A[3] = 4
A[4] = 3

the function should return 1, as explained above.

Write an efficient algorithm for the following assumptions:

N is an integer within the range [2..100,000];
each element of array A is an integer within the range [-1,000..1,000].


*/

#include <iostream>
#include <vector>
#include <algorithm>
// #include <cmath> // only for the codility run

using namespace std;

int TapeEquilibrioum(vector<int> &A)
{
	int countLhs= 0;
	int countRhs = 0;
	int result=0;
	vector<int> resultList = {};

	for (int P = 1; P < A.size(); P++)
	{
		for (vector<int>::iterator i = A.begin(); i != (A.begin() + P); i++)
		{
			countLhs = countLhs + (*i);
		}

		for (vector<int>::iterator m = (A.begin() + P); m != A.end(); m++)
		{
			countRhs = countRhs + (*m);
		}
		cout << "P = " << P << endl;
		cout << "countLhs = " << countLhs << endl;
		cout << "countRhs = " << countRhs << endl;

		result = fabs(countLhs - countRhs);
		countLhs = 0;
		countRhs = 0;
		
		cout << "result = " << result << endl;
		resultList.push_back(result);
	}

	result = *min_element(resultList.begin(), resultList.end());

	return result;
}

void main()
{
	vector<int> A;
	A = {3,1,2,4,3};
	int result;
	result = TapeEquilibrioum(A);

	cout << "minimum element = " << result << endl;
	system("PAUSE");
}