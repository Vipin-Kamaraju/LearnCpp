#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int BinaryGap(int N)
{
	if( N == 0)
		return 0;

	int x = 1;
	int count = 0;
	vector<int> countZeros = {};
	bool bit1flag = false;

	for (int m = N; (m !=0) ; m = (m >> 1))
	{
		if ((m & x) == 1 | (bit1flag != false))
		{
			bit1flag = true;
			if ((m & x) == 0)
			{
				count++;
				cout << "count increment = " << count << endl;
			}
			else
			{
				countZeros.push_back(count);
				cout << "push back :" << count << endl;
				count = 0;
			}
		}
				
	}


	return *max_element(countZeros.begin(), countZeros.end());
}

void main()
{
	int n = 20;
	int result = 0;
	result = BinaryGap(n);

	cout << "Binary gap is = " << result <<endl;

	system("PAUSE");
}