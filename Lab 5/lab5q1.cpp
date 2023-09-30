#include <iostream>
#include <cstdlib>
#include<time.h>
using namespace std;

void displayArr(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int PARTITION(int *A,int p,int r)
{
    int x = A[r];
    int i = p-1;
    int temp;
    for(int j=p;j<=r-1;j++)
    {
        if(A[j]<=x)
        {
            i += 1;
            temp = A[i];
            A[i] = A[j];
            A[j] = temp;
        }
    }
    i += 1;
    temp = A[i];
    A[i] = A[r];
    A[r] = temp;
    return i;
}

void QUIKSORT(int *A,int p,int r)
{
    if(p<r)
    {
        int q = PARTITION(A,p,r);
        QUIKSORT(A,p,q-1);
        QUIKSORT(A,q+1,r);
    }
}

int main()
{
    int n, *arr;
    cout << "Enter how many random numbers to store into an array: ";
    cin >> n;
    arr = new int[n];
    srand(time(NULL));
    for (int i = 0; i < n; i++) 
        arr[i] = rand()%100;

    cout << "The original array is:" << endl;
    displayArr(arr, n);

    QUIKSORT(arr, 0, n - 1);

    cout << "The array after quick sort is:" << endl;
    displayArr(arr, n);

    return 0;
}
