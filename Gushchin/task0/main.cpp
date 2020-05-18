#include <iostream>

using namespace std;


void printArrRec(int* A, int len, int pos = 0)
{
	if (pos < 0 || pos >= len) return;

	cout << A[pos] << endl;
	printArrRec(A, len, pos + 1);
}

int main()
{
	cout << "Enter length of array" << endl;

	int arrLen = 0;
	cin >> arrLen;

	int *arr = new int[arrLen];

	for (int i = 0; i < arrLen; i++)
	{
		arr[i] = i;
	}

	printArrRec(arr, arrLen);

	return 0;
}