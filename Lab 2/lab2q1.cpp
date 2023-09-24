#include <iostream>
#include<cstdlib>
using namespace std;

int insertionSort(int arr[], int n, int s) 
{
  int steps = s;
  for (int i = 1; i < n; i++) 
  {
    steps ++;
    int key = arr[i];
    steps ++;
    int j = i - 1;
    steps ++;
    steps ++;
    while (j >= 0 && arr[j] > key) 
    {
      steps ++;
      arr[j + 1] = arr[j];
      steps ++;
      j--;
      steps ++;
    }
    arr[j + 1] = key;
    steps ++;
  }
  return steps;
}

void insertionSort(int arr[], int n) 
{
  for (int i = 1; i < n; i++) 
  {
    int key = arr[i];
    int j = i - 1;
    while (j >= 0 && arr[j] > key) 
    {
      arr[j + 1] = arr[j];
      j--;
    }
    arr[j + 1] = key;
  }
}

void descendingSort(int arr[], int n) 
{
    int temp,j=n-1;
    for (int i = 0; i < n/2; i++)
    {
        temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
        j--;
    }
}

void printArray(int arr[], int n) 
{
  for (int i = 0; i < n; i++) 
  {
    cout << arr[i] << " ";
  }
  cout << endl;
}

int main() 
{
  int choice,n,steps,*arr,m;
  cout << endl;
  cout << "                        INSERTION SORT MENU" << endl;
  cout << "-------------------------------------------------------------------" << endl;
  cout << "0. Quit" << endl;
  cout << "1. n Random numbers => Array" << endl;
  cout << "2. Display the Array" << endl;
  cout << "3. Sort the Array in Ascending Order by using Insertion Sort Algorithm" << endl;
  cout << "4. Sort the Array in Descending Order by using any sorting algorithm" << endl;
  cout << "-------------------------------------------------------------------" << endl;
  do 
  {
    cout << "Enter your choice: ";
    cin >> choice;

    switch (choice) 
    {
      case 0: cout << "Quitting..." << endl;
              break;

      case 1: cout << "Enter   how many random numbers to store into an array: ";
              cin >> n;
              arr = new int[n];
              for (int i = 0; i < n; i++) 
              {
                arr[i] = rand()%100;
              }
              break;

      case 2: printArray(arr, n);
              break;

      case 3: steps = insertionSort(arr, n, 0);
              printArray(arr, n);
              break;

      case 4: steps = insertionSort(arr, n, 0);
              descendingSort(arr, n);
              printArray(arr, n);
              break;

      default:cout << "Invalid choice!" << endl;
    }
  } while (choice != 0);

  return 0;
}
