/*   
The Fibonacci sequence is defined as follows: the first number of the sequence is 0,
the second number is 1 and the nth number is the sum of the (n - 1)th and (n - 2)th numbers.
 Write a function that takes in an integer n and returns the nth Fibonacci number.


Important note: the Fibonacci sequence is often defined with its first two numbers as F0 = 0 and F1= 1.
For the purpose of this question, the first Fibonacci number is F0; therefore, getNthFib(1) is equal to
F0, getNthFib(2) is equal to F1, etc..


Test Case : 

Input : n=6

output : 5

*/


#include<iostream>
using namespace std;


    int nthfabonacci(int n){
        if(n==1){
            return 0;
        }
        if(n==2){
            return 1;
        }
        return nthfabonacci(n-1) + nthfabonacci(n-2);
    }

int main(){
    int input;

    cout<<"Enter nth term : "<<endl;
    cin>>input;

    int x = nthfabonacci(input);
    cout<<x<<endl;
}