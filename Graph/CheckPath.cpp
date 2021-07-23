#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
#include<utility>
using namespace std;

bool checkPath(int **edge , int n , bool* visited , int startPoint , int endPoint){
    if(edge[startPoint][endPoint] == 1){
        return true;
    }
    visited[startPoint] = true;
    for(int i = 0 ; i<n ; i++){
        if(i == startPoint){
            continue;
        }
        if(edge[startPoint][i] == 1){
            if(visited[i]){
                continue;
            }
        // cout<<i;
        bool check = checkPath(edge , n , visited , i  , endPoint);
        if(check) return true;  
        }
    }
    return false;
}


int main(){
    int n,e;
    cout<<"Enter Vertices ";
    cin>>n;
    cout<<"Enter Edges ";
    cin>>e;
    int **edge = new int*[n];
    for(int i=0;i<n;i++){
        edge[i] = new int[n];
        for(int j=0 ; j<n; j++){
            edge[i][j] = 0;
        }
    }
    for(int i = 0 ; i<e ; i++){
        int e1 , e2;
        cout<<"Enter "<<i+1<<"th Edge pair ";
        cin>>e1>>e2;
        edge[e1][e2] = 1;
        edge[e2][e1] = 1;
    }


    bool *visited = new bool[n];
    for(int i=0 ; i<n ; i++){
        visited[i] = false;
    }

    // check is path exist b/w 2 and 1
    bool check = checkPath(edge , n ,visited , 2 , 1);

    if(check) cout<<"yes";
    else cout<<"No";
return 0;
}