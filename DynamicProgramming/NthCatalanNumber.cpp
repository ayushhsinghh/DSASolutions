#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
#include<utility>
using namespace std;

// method 1: Recursive
// Time complexity: O(2^n) : Exponential
// Space complexity: O(n)
unsigned long int findCatalan_1(int n) 
{
        if(n <= 1){
            return 1;
        }
        unsigned long int result = 0;
        for(int i = 0 ; i<n ; i++){
            result += findCatalan_1(i) * findCatalan_1(n-i-1);
            
        }
        return result;       
}

// Method 2: Memoization
// Time Complexity: O(n^2)
// space Complexity: O(n)
unsigned long int dp[101] = {0};
unsigned long int findCatalan_2(int n) 
{
        if(n <= 1){
            return 1;
        }
        dp[0] = dp[1] = 1;
        if(dp[n] != 0){
            return dp[n];
        }
        
        unsigned long int result = 0;
        for(int i = 0 ; i<n ; i++){
            result += findCatalan_2(i) * findCatalan_2(n-i-1);
            
        }
        dp[n] = result;
        return result;
        
}
// Method 3: Dynamic Programming
// Time Complexity: O(n^2)
// Space Complexity: O(n)
unsigned long int findCatalan_3(int n) 
{
        unsigned long int dp[n+1] = {0};
        dp[0] = dp[1] = 1;

        for(int i = 0 ; i<n ; i++){
           for(int j = 0 ; j <= i ; j++){
               dp[i] += dp[j] * dp[i-j-1];
           }
        }
        return dp[n];
}

// method 4: Binomial Coefficient
// Time Complexity: O(n^2)
// Space Complexity: O(1)
unsigned long int binomialCoeff(unsigned int n, unsigned int k) 
{ 
	unsigned long int res = 1; 

	// Since C(n, k) = C(n, n-k) 
	if (k > n - k) 
		k = n - k; 

	// Calculate value of [n*(n-1)*---*(n-k+1)] / [k*(k-1)*---*1] 
	for (int i = 0; i < k; ++i) 
	{ 
		res *= (n - i); 
		res /= (i + 1); 
	} 

	return res; 
}
unsigned long int findCatalan_4(unsigned int n) 
{ 
	// Calculate value of 2nCn 
	unsigned long int c = binomialCoeff(2*n, n); 

	// return 2nCn/(n+1) 
	return c/(n+1); 
} 


int main(){
    int n;
    cin >> n;
    cout << findCatalan_4(n) << endl;
    return 0;
}