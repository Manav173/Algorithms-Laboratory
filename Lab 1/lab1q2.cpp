#include<iostream>
#include<cstdlib>
using namespace std;

void createarray(int *arr,int n)
{
    int u,l;
    cout<<"Enter the lower limit for the random function :- ";
    cin>>l;
    cout<<"Enter the upper limit for the random function :- ";
    cin>>u;
    for(int i=0; i<n; i++)
        arr[i]=(rand()%(u-l+1))+l;
}

void checkduplicate(int *arr,int n)
{
    int x=0,y,flag;
    for(int i=0;i<n;i++)
    {
        flag=0;
        for(int j=i+1;j<n;j++)
        {
            if(arr[i]==arr[j])
            {
                if(arr[j]==-1)
                {
                    continue;
                }
                else if(flag==0)
                {
                    x++;
                    arr[j]=-1;
                    flag=1;
                }
                else if(flag==1)
                {
                    arr[j]=-1;
                }
            }
        }
    }
    cout<<"Total number of duplicates :- "<<x;
}

void getMaxRepeatingElement(int *arr, int n) 
{
    int k,repeatcount=0;

    for (int i = 0; i < n; i++)
    {
        int count = 1;
        for (int j = i+1; j < n; j++)
        {
            if (arr[j] == arr[i])
            {
                count++;
            }
        }

        if (count > repeatcount)
        {
            repeatcount = count;
            k = arr[i];
        }
    }  

    cout<<"The most repeating element in the array :- "<<k<<endl;
}

int main()
{
    int n;
    cout<<"Enter the number of random numbers to be stored in an array :- "<<endl;
    cin>>n;

    int *arr = new int(n);

    createarray(arr,n);

    cout<<"The content of the array with random input are as follows:"<<endl;
    for(int i=0; i<n; i++)
        cout<<arr[i]<<" ";
    cout<<endl;
    
    getMaxRepeatingElement(arr,n);
    checkduplicate(arr,n);
}
