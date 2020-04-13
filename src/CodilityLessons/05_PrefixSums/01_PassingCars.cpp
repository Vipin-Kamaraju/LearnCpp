
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
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

// function to compute result
template<typename X , typename Y>
void resultAddition(X &result, Y &passingCarsList)
{
	for (auto m : passingCarsList)
	{
		result = result + m;
		if (result > 1000000000)
		{
			result = -1;
			break;
		}
	}
}

// function overloading using templates
template<>
void resultAddition(unsigned int &result, vector<int> &passingCarsList)
{
	for (auto m : passingCarsList)
	{
		result = result + m;
		if (result > 1000000000)
		{
			result = -1;
			break;
		}
	}
}

// function to compute number of zeros and ones
template<typename X, typename Y, typename Z>
void countZerosOnes(X &A, Y &numberOfZeros, Z &numberOfOnes)
{
	for (auto i : A)
	{
		if (i == 0)
			numberOfZeros++;
		else if (i == 1)
			numberOfOnes++;
	}
}

// function to count number of passing cars
template<typename X, typename Y, typename Z>
void numPassingCars(X &A, Y &passingCarsList, Z &numberOfOnes)
{
	for (auto i : A)
	{
		if (i == 0)
			passingCarsList.push_back(numberOfOnes);
		else if (i == 1)
		{
			numberOfOnes = (numberOfOnes - 1);
		}
	}
}

int PassingCars(vector<int> &A)
{
	int numberOfZeros = 0;
	int numberOfOnes = 0;
	vector<int> passingCarsList;

	unsigned int result = 0; //2,147,483,647 since the test case failed when it has crossed this range
							 // It has flipped the bit when it crossed this range (50000 * 42950 )

	// count number of zeros and ones
	countZerosOnes(A, numberOfZeros , numberOfOnes);

	// count number of passing cars
	numPassingCars(A, passingCarsList , numberOfOnes);
	
	// compute the result
	resultAddition(result, passingCarsList);

	return result;
}

template<typename X, typename Y>
void ReadInputFile()
{

}

void main()
{	
	int N;
	vector<int> A;
	vector<vector<int>> ListA;
	int result;

	// Enter N value
	// Later change this to the next line in the Input file or read with a delimiter
	cout << " Enter N value = ";
	cin >> N;

	// Input file for vector
	ifstream InputFile("InputFile.txt");
	string strLine;
	//string str;
	int c;
	if (InputFile.is_open())
	{
		while (getline(InputFile, strLine))
		{
			cout << "Entire line " << strLine << endl;
			istringstream str(strLine);
			
			// This method is not suggested since the element is read not as an integer but as a character
			// This means 25 will be read as 2 and 5
			/*strLine.erase(remove_if(strLine.begin(), strLine.end(), isspace),strLine.end());
			for (string::iterator it = strLine.begin(); it != strLine.end(); ++it)
			{
				A.push_back(*it);
			}*/

			str >> c;
			while(str)
			{
				A.push_back(c);
				str >> c;
			}
			for (auto i : A)
			{
				cout << "i = " << i << endl;
			}
			ListA.push_back(A);
			A.erase(A.begin(), A.end());
		}
	}
	else
	{
		cout << "Error opening file" << endl;
	}
	InputFile.close();

	for (auto A : ListA)
	{
		result = PassingCars(A);

		cout << "\nresult = " << result << endl;
	}
	system("PAUSE");
}

