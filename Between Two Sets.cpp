// Between Two Sets.cpp : This file contains the 'main' function. Program execution begins and ends there.

                                             /**** PROBLEM STATEMENT ****/
// There will be two arrays of integers. Determine all integers that satisfy the following two conditions:

//     The elements of the first array are all factors of the integer being considered
//     The integer being considered is a factor of all elements of the second array

// These numbers are referred to as being between the two arrays. Determine how many such numbers exist.
                                             /**** END OF PROBLEM STATEMENT ****/

#include <iostream>
#include <vector>

using namespace std;

//string ltrim(const string&);
//string rtrim(const string&);
//vector<string> split(const string&);
int getGCD(int, int);
int getLCM(int, int);

/*
 * Complete the 'getTotalX' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER_ARRAY a
 *  2. INTEGER_ARRAY b
 */


int getTotalX(vector<int> a, vector<int> b) {
	int result = 0;

	int lcm = a[0];
	//get LCM of all the elelment of vector a
	for (int i = 1; i < a.size(); i++)
	{
		lcm = getLCM(lcm, a[i]);
	}

	int gcd = b[0];
	// Get GCD of all element of Vector b
	for (int i = 1; i < b.size(); i++)
	{
		gcd = getGCD(gcd, b[i]);
	}

	int multiple = 0;

	while (multiple <= gcd)
	{
		multiple = lcm + multiple;
		if (gcd % multiple == 0)
		{
			result++;
		}
	}
	return result;
}

int main() {
	
	vector<int> a;
	vector<int> b;

	a.push_back(2);
	a.push_back(6);
	b.push_back(24);
	b.push_back(36);

	//int result = getTotalX(a, b);
	//cout << result;

	cout << getTotalX(a, b);
	return 0;
}


int getGCD(int integer1, int integer2)
{
	if (integer2 == 0)
	{
		return integer1;
	}
	else {
		return getGCD(integer2, integer1 % integer2);
	}
}

int getLCM(int integer1, int integer2)
{
	// int lcm;
	// if (integer1 > integer2)    
	// {
	//     lcm = integer1;
	// }
	// else 
	// {
	//     lcm = integer2;
	// }    
	// while(1)
	// {
	//     if (lcm % integer1 == 0 && lcm % integer2 ==0)
	//     {
	//         return lcm;
	//         break;
	//     }
	//     lcm++;
	// }

	// a solution provided from the discussion for getting LCM
	return integer1 * (integer2 / getGCD(integer1, integer2));
}
