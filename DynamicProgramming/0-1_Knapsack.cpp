#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
#include<utility>
using namespace std;



// Recursive Way
// Complexity : 2^n (Exponential)
int knapshackR(int wt[] , int val[] , int capacity , int size){
    if(capacity==0 || size==0){
        return 0;
    }
    if(wt[size] <= capacity){
        return max( val[size] + knapshackR(wt , val , capacity - wt[size] , size-1) ,
                         knapshackR(wt , val , capacity  , size-1));
    }
    else{
        return knapshackR(wt , val , capacity , size -1);
    }

}


// Memoization Way
// Linear Complexity : O (size * capicity)

// size : Size of wt & val array
// capicity : Capicity of Knapsack
// mem : 2D Array for Storing Result : memoization
int knapshackM_helper(int wt[] , int val[] , int **mem , int capacity , int size){
    if(capacity==0 || size==0){
        return 0;
    }

    if(mem[size][capacity] != -1){
        return mem[size][capacity];
    }

    if(wt[size] <= capacity){

        mem[size][capacity] =  max( val[size] + knapshackM_helper(wt , val , mem ,  capacity - wt[size] , size-1) ,
                         knapshackM_helper(wt , val , mem , capacity  , size-1));
        return mem[size][capacity];
    }
    else{
        mem[size][capacity] =  knapshackM_helper(wt , val ,mem , capacity , size -1);
        return mem[size][capacity];
    }
}

int knapshackM(int wt[] , int val[] , int capacity , int size){

    // 2D array Alocation for Storing Result
    int** mem;
    mem = new int*[size+1];
 
    
    for (int i = 0; i < size +1; i++)
        mem[i] = new int[capacity + 1];
 
    // Initialization of Array with -1
    for (int i = 0; i < size +1; i++)
        for (int j = 0; j < capacity + 1; j++)
            mem[i][j] = -1;
    return knapshackM_helper(wt , val , mem , capacity , size);
}

// Dynamic Programming Way
// Complexity : O(size * capacity)

int knapshackDP(int wt[] , int val[] , int capacity , int size){
    int dp[size+1][capacity +1];

    // Base Case or Initialization
    for(int i=0; i < size +1; i++){
        for(int j=0; j < capacity +1; j++){
            if(i==0 || j==0){
                dp[i][j] = 0;
            }
        }
    }


    // Body
    for(int i=1; i < size +1; i++){
        for(int j=1; j < capacity +1; j++){
            if(wt[i-1] <= j){
                dp[i][j] = max(val[i-1] + dp[i - 1][j-wt[i-1]] , dp[i-1][j]);
            }
            else{
               dp[i][j] = dp[i-1][j];
            }
        }
        }


        return dp[size][capacity];
}




int main(){
    int wt[] = { 10 , 20 , 30};
    int val[] = {60 , 100 , 120};
    int capacity = 50;


    int maxProfit = knapshackDP(wt , val , capacity , 3); // Dynamic Programming
    // int maxProfit = knapshackM(wt , val , capacity , 3); // Memoization
    // int maxProfit = knapshackR(wt , val , capacity , 3); // Recursive

    cout<<maxProfit;

return 0;
}