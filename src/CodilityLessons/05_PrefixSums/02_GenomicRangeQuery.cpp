
/*


A DNA sequence can be represented as a string consisting of the letters A, C, G and T, which correspond to the types of successive nucleotides in the sequence. 
Each nucleotide has an impact factor, which is an integer. Nucleotides of types A, C, G and T have impact factors of 1, 2, 3 and 4, respectively. 
You are going to answer several queries of the form: What is the minimal impact factor of nucleotides contained in a particular part of the given DNA sequence?

The DNA sequence is given as a non-empty string S = S[0]S[1]...S[N-1] consisting of N characters. 
There are M queries, which are given in non-empty arrays P and Q, each consisting of M integers. 
The K-th query (0 = K < M) requires you to find the minimal impact factor of nucleotides contained in the DNA sequence between positions P[K] and Q[K] (inclusive).

For example, consider string S = CAGCCTA and arrays P, Q such that:
P[0] = 2    Q[0] = 4
P[1] = 5    Q[1] = 5
P[2] = 0    Q[2] = 6

The answers to these M = 3 queries are as follows:

The part of the DNA between positions 2 and 4 contains nucleotides G and C (twice), whose impact factors are 3 and 2 respectively, so the answer is 2.
The part between positions 5 and 5 contains a single nucleotide T, whose impact factor is 4, so the answer is 4.
The part between positions 0 and 6 (the whole string) contains all nucleotides, in particular nucleotide A whose impact factor is 1, so the answer is 1.

Write a function:

vector<int> solution(string &S, vector<int> &P, vector<int> &Q);

that, given a non-empty string S consisting of N characters and two non-empty arrays P and Q consisting of M integers, 
returns an array consisting of M integers specifying the consecutive answers to all queries.

Result array should be returned as a vector of integers.

For example, given the string S = CAGCCTA and arrays P, Q such that:
P[0] = 2    Q[0] = 4
P[1] = 5    Q[1] = 5
P[2] = 0    Q[2] = 6

the function should return the values [2, 4, 1], as explained above.

Write an efficient algorithm for the following assumptions:

N is an integer within the range [1..100,000];
M is an integer within the range [1..50,000];
each element of arrays P, Q is an integer within the range [0..N - 1];
P[K] = Q[K], where 0 = K < M;
string S consists only of upper-case English letters A, C, G, T.

Copyright 2009–2020 by Codility Limited. All Rights Reserved. Unauthorized copying, publication or disclosure prohibited.

*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(string &S, vector<int> &P, vector<int> &Q)
{
	vector<int> result;
	vector<string> StringCombination;
	for (int M = 0; M != P.size() ; ++M)
	{
		int difference = (Q.at(M) - P.at(M)) + 1;
		/*string S2 = S.substr(P.at(M), difference);
		std::sort(S2.begin(), S2.end());
		auto last = std::unique(S2.begin(), S2.end());
		S2.erase(last, S2.end());*/
		StringCombination.push_back(S.substr(P.at(M), difference));
				
	}

	for (std::vector<string>::iterator it = StringCombination.begin(); it != StringCombination.end(); ++it)
	{
		
		if (it->find("A") != (-1))
		{
			result.push_back(1);
		}
		else if (it->find("C") != (-1))
		{
			result.push_back(2);
		}
		else if (it->find("G") != (-1))
		{
			result.push_back(3);
		}
		else if (it->find("T") != (-1))
		{
			result.push_back(4);
		}	
	}

	return result;
}


void main()
{
	string S = "CAGCCTA";
	vector<string> DNA = { "A", "C", "G","T" };
	vector<int> P = { 2,5,0,2 };
	vector<int> Q = { 4,5,6,4 };
	vector<int> result;

	result = solution(S, P, Q);
	
	system("PAUSE");
}

