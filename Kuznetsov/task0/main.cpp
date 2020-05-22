#include <iostream>

using namespace std;

void recursion(int* arr, int size, int i)
{
	if (i != size && i >= 0)
	{
		cout << arr[i] << " ";
		recursion(arr, size, ++i);
	}
	return;
}

int main()
{
	int array[5] = { 11,12,13,14,15 };
	recursion(array, 5, 0);
	return 0;
}