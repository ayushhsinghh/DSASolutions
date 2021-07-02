#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
#include<utility>
using namespace std;


void swap(int &a , int &b){
        a = a + b;
        b = a - b;
        a = a - b;
    }

// Sort : Ascending Order - Min Heap
// Sort : Descending Order - Max Heap


// Function to sort in Ascending Order
void heapSort(int arr[] , int n){


    // Insert Array Element to Heap
    for(int i=1; i<n; i++){
        int childIndex = i;
        while(childIndex > 0){
            int parentIndex = (childIndex -1)/2;
            if(arr[parentIndex] < arr[childIndex]){
                swap(arr[parentIndex], arr[childIndex]);
            }
            else{
                break;
            }
            childIndex = parentIndex;
        }  
    }

    
    
    while(n > 1){ // n is Size of array
        swap(arr[0] , arr[n-1]);
        n--;

        int parentIndex = 0;
        int leftChildIndex = 2 * parentIndex + 1;
        int rightChildIndex = 2 * parentIndex + 2;

        while(leftChildIndex < n){
            int minIndex = parentIndex;
            if(arr[minIndex] < arr[leftChildIndex]){
                minIndex = leftChildIndex;
            }
            if(rightChildIndex < n && arr[minIndex] < arr[rightChildIndex]){
                minIndex = rightChildIndex;
            }
            if(minIndex == parentIndex){
                break;
            }
            swap(arr[minIndex], arr[parentIndex]);

            parentIndex = minIndex;
            leftChildIndex = 2 * parentIndex + 1;
            rightChildIndex = 2 * parentIndex + 2;
        }

        }



}


int main(){

    int arr[] = {20 , 50 , 3 , 100 , 6 , 84 , 7};

    heapSort(arr , 7);

    cout<<"Sorted Array is :";
    for(int i = 0; i < 7 ; i++){
        cout<<arr[i] <<" ";
    }


return 0;
}