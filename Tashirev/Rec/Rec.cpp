#include <iostream>
using namespace std; 
void rec(int* arr, const int size, int i = 0)
{
	if (i != size)
	{
		cout << *arr << endl;
		rec(arr + 1, size, i + 1);
	}
}

int main()
{
	int arr[] = { 12, 2, 4, 3, 7, 8, 16, 3, 5, 23 };
	rec(arr, 10);
	system("pause");
	return 0;
}