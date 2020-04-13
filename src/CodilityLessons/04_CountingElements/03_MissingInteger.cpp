
/*


This is a demo task.

Write a function:

int solution(vector<int> &A);

that, given an array A of N integers, returns the smallest positive integer (greater than 0) that does not occur in A.

For example, given A = [1, 3, 6, 4, 1, 2], the function should return 5.

Given A = [1, 2, 3], the function should return 4.

Given A = [-1, -3], the function should return 1.

Write an efficient algorithm for the following assumptions:

N is an integer within the range [1..100,000];
each element of array A is an integer within the range [-1,000,000..1,000,000].



*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int MissingInteger(vector<int> &A)
{
	vector<int> copyA = A;
	int sizeOfA = A.size();
	sort(copyA.begin(), copyA.end());
	auto last = unique(copyA.begin(), copyA.end());
	copyA.erase(last, copyA.end());

	int element = copyA[0];
	if (element > 1)
		return 1;

	element = 1;
	vector<int> MissingElementList;
	int lastElement;
	MissingElementList.clear();

	vector<int>::iterator it = find(copyA.begin(), copyA.end(), 1);
	//int Pos_elem1 = distance(A.begin(), it);
	if (it == copyA.end())
	{ 
		return 1;
	}


	for (it ; it != copyA.end(); ++it)
	{
		if (element != *it)
		{
			MissingElementList.push_back(element);
		}
		element++;
		lastElement = *it;
	}

	if (!MissingElementList.empty())
	{
		element = *min_element(MissingElementList.begin(), MissingElementList.end());
		if (element > 0)
			return element;
		else
			return 1;
	}
	else
	{
		if (lastElement > 0)
		{
			return (lastElement + 1);
		}
		else
			return 1;
	}
}

void main()
{
	int N = 5;
	//vector<int> A = {1,2,6,6,5,3,4,4,6,1,4,4};
	vector<int> A = {-100,1,3,6,4,1,2,100 };
	int result;
	result = MissingInteger(A);
	
	cout << "\nresult = " << result << endl;
	system("PAUSE");
}