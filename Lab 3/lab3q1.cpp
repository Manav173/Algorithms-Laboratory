#include <iostream>
#include <cstdlib>
#include <time.h>
using namespace std;

long long int is_ascend_count(int arr[], int n,int s)
{
    long long int steps = 0;
    for (int i = 1; i < n; i++) 
    {
        steps++;
        int key = arr[i];
        steps ++;
        int j = i - 1;
        steps++;
        steps++;
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
    cout << endl;
    for (int i = 0; i < n; i++) 
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int* generate_random_array(int n) 
{
    int* array = new int[n];
    srand(time(NULL));
    for (int i = 0; i < n; i++) 
    {
        array[i] = rand() % 100 + 1; 
    }
    return array;
}

void copyArray(int arr1[], int arr2[], int n) 
{
    for (int i = 0; i < n; i++)
    {
        arr2[i] = arr1[i];
    }
}

int main() 
{
    int choice,n,steps,*arr,m;
    cout << endl;
    cout << "--------------------------------------------------------------------------" << endl;
    cout << "\t\t\tINSERTION SORT MENU" << endl;
    cout << "--------------------------------------------------------------------------" << endl;
    cout << "0. Quit" << endl;
    cout << "1. n Random numbers => Array" << endl;
    cout << "2. Display the array" << endl;
    cout << "3. Sort the Array in Ascending Order by using Insertion Sort Algorithm" << endl;
    cout << "4. Sort the Array in Descending Order by using Insertion Sort Algorithm" << endl; 
    cout << "5. Time Complexity (step count) to sort ascending of data for all Cases\n(Data Ascending, Data in Descending & Random Data) in tabular form for\nvalues n=5 to 9, step=1" << endl;
    cout << "6. Time Complexity (step count) to sort ascending of data for all Cases\n(Data Ascending, Data in Descending & Random Data) in tabular form for\nvalues n=5000 to 500000, step=5000" << endl;
    cout << "--------------------------------------------------------------------------" << endl;

    do 
    {
        cout << endl << "Enter your choice: ";
        cin >> choice;

        switch (choice) 
        {
            case 0: cout << endl << "Quitting..." << endl;
                    break;

            case 1: cout << "Enter how many random numbers to store into an array: ";
                    cin >> n;
                    arr = new int[n];
                    srand(time(NULL));
                    for (int i = 0; i < n; i++) 
                    {
                        arr[i] = rand()%100;
                    }
                    break;

            case 2: printArray(arr, n);
                    break;

            case 3: insertionSort(arr, n);
                    printArray(arr, n);
                    break;

            case 4: insertionSort(arr, n);
                    descendingSort(arr, n);
                    printArray(arr, n);
                    break;

            case 5: cout << endl;
                    cout << "Sl. No.\t Data Size \t #Steps(Ascending data) \t #Steps(Descending data) \t #Steps(Random data)" << endl;
                    cout << "-------\t --------- \t ---------------------- \t ----------------------- \t -------------------" << endl;
                    m = 1;

                    for (int n = 5; n <= 9; n++) 
                    {
                        int *ascending_array = new int[n];
                        int *descending_array = new int[n];
                        int *random_array;

                        random_array = generate_random_array(n);

                        int random_steps = is_ascend_count(random_array, n, 1);

                        copyArray(random_array, ascending_array, n);
                        copyArray(random_array, descending_array, n);
                        
                        insertionSort(ascending_array, n);
                        descendingSort(descending_array, n);

                        int ascending_steps = is_ascend_count(ascending_array, n, 1);
                        int descending_steps = is_ascend_count(descending_array, n, 1);
                        cout<< m <<" \t "<< n <<"\t\t "<<ascending_steps<<"\t\t\t\t "<<descending_steps<<"\t\t\t\t "<<random_steps<< endl;
                        m++;
                    }
                    break;
            
            case 6: cout << endl;
                    cout << "Sl. No.\t Data Size \t #Steps(Ascending data) \t #Steps(Descending data) \t #Steps(Random data)" << endl;
                    cout << "-------\t --------- \t ---------------------- \t ----------------------- \t -------------------" << endl;
                    
                    m = 1;

                    for (int n = 5000; n <= 50000; n += 5000) 
                    {
                        int *ascending_array = new int[n];
                        int *descending_array = new int[n];
                        int *random_array;

                        random_array = generate_random_array(n);

                        long long int random_steps = is_ascend_count(random_array, n, 5000);

                        copyArray(random_array, ascending_array, n);
                        copyArray(random_array, descending_array, n);
                        
                        insertionSort(ascending_array, n);
                        descendingSort(descending_array, n);

                        long long int ascending_steps = is_ascend_count(ascending_array, n, 5000);
                        long long int descending_steps = is_ascend_count(descending_array, n, 5000);
                        
                        cout<< m <<" \t "<< n <<"\t\t "<<ascending_steps<<"\t\t\t\t "<<descending_steps<<"\t\t\t "<<random_steps<< endl;
                        m++;
                    }
                    break;
            
            default:
                cout << "Invalid choice!" << endl;
                break;
        }
    } while (choice != 0);

    return 0;
}
