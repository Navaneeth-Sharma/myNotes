#include<iostream>

using namespace std;

// Iterative Approach
int binSearch(int arr[], int length, int key){
    int l=0;
    int h=length;
    int mid=(l+h)/2;

    while (l<h)
    {
        if(key>arr[mid]){
            l=mid+1;
            mid=(l+h)/2;
        }
        if(key<arr[mid]){
            h=mid-1;
            mid=(l+h)/2;
        }
        if(key==arr[mid]){
            return mid;
        }
        else{
            return -1;
        }
    }

    return -1;
    
}


int main(){

    int arr[5]={2,3,4,6,9};

    cout<<binSearch(arr,5, 9);

    return 0;
}
