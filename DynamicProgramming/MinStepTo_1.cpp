#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
#include<climits>
#include<utility>
using namespace std;

// Recursive Way
// Time Complexity : Exponential : O(2^n)  
int minStep(int n){
    if(n == 1){
        return 0;
    }
    
    int x = INT_MAX;
    int y = INT_MAX;
    int z = INT_MAX;
    if(n%3 == 0){
         x = minStep(n/3) + 1;
    }
    if(n%2 == 0){
         y = minStep(n/2) + 1;
    }
     z = minStep(n-1) + 1;

    return min(z , min(x,y));
}

// Memoization Way
// Time Complexity : O(N)
int minStepMemo(int n , int memo[]){
    if(n == 1){
        return 0;
    }
    // Memoization
    if(memo[n] != 0){
        return memo[n];
    }

    int x , y , z;
    x = y = x = INT_MAX;

    if(n%3 == 0){
        x = minStepMemo(n/3 , memo) + 1;
    }
    if(n % 2 == 0 ){
        y = minStepMemo(n/2 , memo) + 1;
    }
    z = minStepMemo(n-1 , memo) + 1;
    
    memo[n] = min(min(x,y) , z);
    return memo[n];

}

// Dynamic Programming Way
// Time Complexity : O(N)
int minStepDyna(int n , int dp[]){
    dp[0] = 0;
    dp[1] = 0;
    for(int i = 2 ; i <= n ; i++){
        int x, y , z;
        x = y = x = INT_MAX;
        if(n % 3 == 0){
            x = dp[i/3] + 1;
        }
        if(n % 2 == 0){
            y = dp[i/2] + 1;
        }
        z = dp[i-1] + 1; 

        dp[i] = min(min(x,y) , z);
    }
    return dp[n];
}

int main(){
    int n;
    cout<<"Enter N : ";
    cin>>n;
    int memo[100] = {0};

    // int ans = minStep(n);
    // int ans = minStepMemo(n , memo);
    int ans = minStepDyna(n , memo);
    cout<<"Ans is :"<<ans;


return 0;
}