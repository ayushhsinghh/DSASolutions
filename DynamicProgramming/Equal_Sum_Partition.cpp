// Question : Partition problem is to determine whether a given set can be partitioned into two subsets such 
// that the sum of elements in both subsets is same.
// Examples:

// arr[] = {1, 5, 11, 5}
// Output: true 
// The array can be partitioned as {1, 5, 5} and {11}

#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
#include<utility>
using namespace std;


bool subset_sum(int arr[] , int sum , int size){
    int dp[size+1][sum+1];

    for(int i=0; i<size +1 ; i++){
        for(int j=0 ; j<sum+1 ; j++){
            if(i==0){
                dp[i][j] = false;
            }
            if(j==0){
                dp[i][j] = true;
            }
        }
    }

    for(int i=1; i<size +1 ; i++){
        for(int j=1 ; j<sum+1 ; j++){
            if(arr[i-1] <= j){
                dp[i][j] = dp[i-1][j - arr[i-1]] || dp[i-1][j];
            }
            else{
                dp[i][j] = dp[i-1][j];
            }



        }
        }

        return dp[size][sum];
    
}


bool equalSumPartition(int arr[] , int size){
    int sum = 0;
    for(int i=0 ; i<size ;i++){
        sum += arr[i];
    }

    if(sum%2==0){
        return subset_sum(arr , sum/2 , size);
    }else{
        return false;
    }

}


int main(){
    int arr[] = {5 , 3 , 3 , 10};
    int size = 4;
    
    bool check = equalSumPartition(arr , size);


    if(check) cout<<"True";
    else cout<<"False";

 
return 0;
}