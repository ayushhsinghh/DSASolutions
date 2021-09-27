#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
#include<climits>
#include<utility>
using namespace std;

// Recursive Way
// Time Complexity : Exponentian - O(T^n)
// Space : O(N)
int minCoinChange(int n , vector<int> coins){
    if(n ==0){
        return 0;
    }
    int ans = INT_MAX;
    for(int i = 0 ; i < coins.size() ; i++){
        if(n-coins[i] >=0){
            int sub = minCoinChange(n-coins[i] , coins)  + 1;
            ans = min(ans , sub);
        }
    }
    return ans;
}

// Memoization Way
// Time Complexity : O(T * N) : {T is Total no of Coins}
// Space Complexity : O(N)
int minCoinChangeMemo(int n , vector<int> coins , int memo[]){
    if(n ==0){
        return 0;
    }
    if(memo[n] != 0){
        return memo[n];
    }
    int ans = INT_MAX;
    for(int i = 0 ; i < coins.size() ; i++){
        if(n-coins[i] >=0){
            int sub = minCoinChangeMemo(n-coins[i] , coins , memo)  + 1;
            ans = min(ans , sub);
        }
    }
    memo[n] = ans;
    return memo[n];
}

// Dynamic Programming
// Time Complexity : O(T * N) : {T is Total no of Coins}
// Space Complexity : O(N)
int minCoinChangedyna(int n , vector<int> coins , int dp[]){
    dp[0] = 0;
    
    for(int i = 1 ; i<=n ; i++){
        dp[i] = INT_MAX;
        for(int j  = 0 ; j < coins.size() ; j++){
            if(i-coins[j] >= 0){
                int sub = dp[i-coins[j]] + 1;
                dp[i] = min(dp[i] , sub);
            }
        }
    }
    return dp[n];
}


int main(){
    int n;
    int memo[100] = {0};
    int dp[100] = {0};
    vector<int> coins = {1 , 7 , 10};
    cout<<"Enter N :";
    cin>>n;

    // int ans = minCoinChange(n , coins);
    // int ans = minCoinChangeMemo(n , coins , memo);
    int ans = minCoinChangedyna(n , coins , dp);
    cout<<"Ans is : "<<ans;




return 0;
}