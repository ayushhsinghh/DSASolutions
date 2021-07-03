#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
#include<utility>
using namespace std;



void kSorted(int arr[] , int size , int k){
    priority_queue<int> pq;
    int count = 0;
    for(int i = 0 ; i<k ; i++)
    {
        pq.push(arr[i]);
    }

    for(int i = k ; i<size ;i++){
    arr[count] = pq.top();
    pq.pop();
    pq.push(arr[i]);
    count++;
    }

    while(!pq.empty()){
        arr[count] = pq.top();
        pq.pop();
        count++;
    }
}


int main(){

    int arr[] = {12 , 9 , 10 , 3 , 6 , 2};
    kSorted(arr , 6 , 3);

    for(int i = 0; i <6 ;i++){
        cout<<arr[i]<<" ";
    }


return 0;
}