#include<iostream>
#include<time.h>
using namespace std;

int main()
{
    int n;
    cout<<"Enter the number of random numbers to be stored in an array :- "<<endl;
    cin>>n;

    int *arr = new int(n);

    srand(time(NULL));
    for(int i=0; i<n; i++)
        arr[i]=rand()%100;
    
    int s=arr[0],l=arr[0];

    for(int i=1; i<n; i++)
    {
        if(s>arr[i])
            s=arr[i];
        if(l<arr[i])
            l=arr[i];
    }

    cout<<"The content of the array with random input are as follows:"<<endl;
    for(int i=0; i<n; i++)
        cout<<arr[i]<<" ";
    cout<<endl;
    cout<<"The smallest number is "<<s<<endl;
    cout<<"The largest number is "<<l;
}
#include <iostream>
#include <time.h>
using namespace std;

int main()
{
    int n;
    cout << "Enter the number of random numbers to be stored in an array: " << endl;
    cin >> n;

    // Dynamically allocate memory for an integer array of size n
    int *arr = new int[n]; 

    // Seed the random number generator using the current time
    srand(time(NULL));

    // Fill the array with random numbers between 0 and 99
    for (int i = 0; i < n; i++)
        arr[i] = rand() % 100;

    // Initialize variables to store the smallest (s) and largest (l) numbers
    int s = arr[0], l = arr[0];

    // Find the smallest and largest numbers in the array
    for (int i = 1; i < n; i++)
    {
        if (s > arr[i])
            s = arr[i];
        if (l < arr[i])
            l = arr[i];
    }

    // Display the content of the array with random inputs
    cout << "The content of the array with random input are as follows:" << endl;
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;

    // Display the smallest and largest numbers
    cout << "The smallest number is " << s << endl;
    cout << "The largest number is " << l;

    // Deallocate the memory for the dynamically allocated array
    delete[] arr;

    return 0;
}

