#include <iostream>
#include <string>
#include "Polynom.h"

using namespace std;

int main()
{
	try
	{
		string s1, s2;
		int n = 0;
		while (n == 0)
		{
			cout << "Enter the first polynom:" << endl;
			getline(std::cin, s1);
			Polynom p1(s1);
			cout << "Enter the second polynom:" << endl;
			getline(std::cin, s2);
			Polynom p2(s2);
			cout << "Choose a math operation:" << endl;
			cout << "1 - 'Polynom1 + Polynom2' " << endl;
			cout << "2 - 'Polynom1 - Polynom2' " << endl;
			cout << "3 - 'Polynom1 * Polynom2' " << endl;
			cin >> n;
			switch (n)
			{
			case 1:
			{
				cout << p1 + p2 << endl;
				system("pause");
				break;
			}
			case 2:
			{
				cout << p1 - p2 << endl;
				system("pause");
				break;
			}
			case 3:
			{
				cout << p1 * p2 << endl;
				system("pause");
				break;
			}
			default:
				cout << "Incorrect input" << endl;
				system("pause");
			}
		}
	}
	catch (const char* error)
	{
		cout << error << endl;
	}
	return 0;
}