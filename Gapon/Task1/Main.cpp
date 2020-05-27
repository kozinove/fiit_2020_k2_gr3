#pragma once
#include <stdio.h>
#include <iostream>

using namespace std;

void Rekursia(int A[], int len, int i)
{

    if ((i < 0) || (i>=len))
        return;
    cout << A[i] << endl;
   Rekursia(A, len, ++i);
 

}


int main()
{
    int A[4] = { 1,2,3,4,};
    Rekursia(A, 4, 0);
    system("pause");
    return 0;
}