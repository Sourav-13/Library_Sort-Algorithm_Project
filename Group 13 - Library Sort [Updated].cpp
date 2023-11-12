#include <bits/stdc++.h>
using namespace std;

int binarySearch(int gappedSortedArray[],int userInput,int str,int end)
{
    if(end>=str)
    {
        int mid = (str+end)/2;
        if(gappedSortedArray[mid]==userInput)
        {
            return mid;
        }
        else if(gappedSortedArray[mid+1]==userInput)
        {
            return mid+1;
        }
        else if(gappedSortedArray[mid]==-1 && gappedSortedArray[mid+1]<userInput)
        {
            return  binarySearch(gappedSortedArray,userInput,mid+1,end);
        }
        else if (gappedSortedArray[mid]!=-1 && gappedSortedArray[mid]<userInput)
        {
            return  binarySearch(gappedSortedArray,userInput,mid+1,end);
        }
        else
        {
            return  binarySearch(gappedSortedArray,userInput,str,mid-1);
        }
    }
    return -2;
}

void insertion(int insertPosition,int userInput,int gappedSortedArray[])
{
    gappedSortedArray[insertPosition]=userInput;
}
void rebalancing(int gappedSortedArray[],int size, int finalArray[], int sizeOf_FA)
{
    int j=0;
    int s[size];
    for(int i=0; i<size; i++)
    {
        if(gappedSortedArray[i]!=-1)
        {
            s[j]=gappedSortedArray[i];
            j++;
        }
    }
    j=0;
    for(int i=0; i<sizeOf_FA; i++)
    {
        if(i%2==0)
        {
            finalArray[i]=s[j];
            j++;
        }
        else
        {
            finalArray[i]=-1;
        }
    }
}

int main()
{
    int gappedSortedArray[]= {1,-1,2,-1,5,-1,10,-1,12,-1,15,-1};  // Gap = -1
    int size = sizeof(gappedSortedArray)/sizeof(gappedSortedArray[0]);
    int str=0;
    int end=size-1;

    int userArray[] = {2,10,15,5};
    int sizeOf_UA = sizeof(userArray)/sizeof(userArray[0]);
    int sizeOf_FA= size + 2*sizeOf_UA;
    int finalArray[sizeOf_FA];
    cout<<"Sorted array with gapes: \n";
    for(int i=0; i<size; i++)
    {
        cout<<gappedSortedArray[i]<<" ";
    }
    cout<<"\nUnsorted user array: \n";
    for(int i=0; i<sizeOf_UA; i++)
    {
        cout<<userArray[i]<<" ";
    }
    for(int i=0; i<sizeOf_UA; i++)
    {
        int insertPosition=binarySearch(gappedSortedArray,userArray[i],str,end)+1;
        insertion(insertPosition,userArray[i],gappedSortedArray);
        rebalancing(gappedSortedArray, size,finalArray, sizeOf_FA);
    }
    cout<<"\n\nFinal array after sorting: \n";
    for(int i=0; i<sizeOf_FA; i++)
    {
        cout<<finalArray[i]<<" ";
    }
}
