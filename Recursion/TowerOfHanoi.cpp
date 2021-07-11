#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
#include<utility>
using namespace std;

void hanoi(int n, char sourse, char helper, char dest){

    if(n == 1){ // if Only 1 Plate directly send to dest
        cout << sourse << "->" << dest << endl;
    }
    else{
        hanoi(n - 1 , sourse, dest, helper); // put sourse to helper
        hanoi(n -1 , sourse ,helper , dest); // put sourse to dest
        hanoi(n - 1 , helper , sourse , dest); // put helper to dest
    }
}

int main(){
    int n ;
    n =  2;
    hanoi(n, 'S', 'H', 'D');

return 0;
}