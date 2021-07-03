#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
#include<utility>
using namespace std;

// print K smallest element from Array 
void KSmallest(int arr[] , int size , int k){
    priority_queue<int> pq; //Max Heap 
    // priority_queue<int , vector<int> , greater<int>> pq; // Min heap : for K lastest element

    for(int i = 0; i < k ; i++){
        pq.push(arr[i]);
    }
    int i = k;
    while(i<size){
        pq.push(arr[k]);
        pq.pop();
        i++;
    }
    for(int i = 0; i < k ; i++){
        cout << pq.top() << " ";
        pq.pop();
    }
}


int main(){

    int arr[] = {10 , 50 , 2 , 60 , 70 , 60 ,40 , 26 , 99 , 15};


    // print 4 smallest elemt from array
    KSmallest(arr , 10 , 4);
    




return 0;
}