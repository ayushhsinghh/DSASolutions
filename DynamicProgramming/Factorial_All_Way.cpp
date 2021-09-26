#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
#include<utility>
using namespace std;


// Recursion
// Time Complexity : O(2^n) (Exponetial)
// Space Complexity : O(n)
int factorial(int n){
    if(n<2){
        return n;
    }
    int ans = factorial(n-1) + factorial(n - 2);
    return ans;
}

// Memoization Way
// Linear Complexity : O (N)
// Space Complexity : O (N);
int factorialMemo(int n , int dp[]){
    if(n<2){
        return n;
    }

    if(dp[n] != 0){
        return dp[n];
    }
    int ans = factorial(n-1) + factorial(n - 2);
    dp[n] = ans;
    return dp[n];
}

// Dynamic Programming Way
// Linear Time Complexity : O (N)
// Space Complexity : O (N);
int FactorialDyn(int n){
    if(n < 2){
        return n;
    }
    int dp[100] = {0};
    dp[1] = 1;

    for(int i = 2 ; i<=n ; i++){
        dp[i] = dp[i -1] + dp[i -2]; 
    }

    return dp[n];

}

// Factorial with Constant Space
// Time Complexity : O(N)
// Space Complexity : O(1)

int FactorialBest(int n){
    if(n<2){
        return n;
    }
    int a = 0;
    int b = 1;
    int c;

    for(int i = 2 ; i<=n ; i++){
        c = a + b;
        a = b;
        b = c;
    }
    return c;
}

int main(){
    int dp[100] = {0};
    int n;
    cout<<"Enter N"<<endl;
    cin>>n;

    // int ans = factorial(n);
    // int ans = factorialMemo(n , dp);
    // int ans = FactorialDyn(n);
    int ans = FactorialBest(n);
    cout<<"Ans is : "<<ans;


return 0;
}