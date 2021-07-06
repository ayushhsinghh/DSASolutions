// Question : Given a set of non-negative integers, and a value sum,
//            determine if there is a subset of the given set with sum equal to given sum. 


#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
#include<utility>
using namespace std;

bool isSubsetSum(int arr[] , int sum , int size){

    int dp[size+1][sum+1];


    // Intialization
    for(int i = 0; i < size +1; i++){
        for(int j = 0; j < sum + 1; j++){
            if(i==0){
                dp[i][j] = false;
            }
            if(j==0){
                dp[i][j] = true;
            }
        }
    }

    for(int i = 1; i < size+1 ; i++){
        for(int j = 1; j < sum+1 ; j++){
            if(arr[i - 1] <= j){
                dp[i][j] = dp[i-1][j - arr[i-1]] || dp[i-1][j];
            }
            else{
                dp[i][j] = dp[i-1][j];
            }
        }


        
}
    return dp[size][sum];
}


int main(){

    int val[] =  {3, 34, 4, 12, 5, 2};
    int sum = 33;

    int size = 6;

    bool check =  isSubsetSum(val , sum , size);


    if (check) cout<<"True"; 
    else cout<<"False";

return 0;
}