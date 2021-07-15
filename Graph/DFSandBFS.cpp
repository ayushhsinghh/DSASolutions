#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
#include<utility>
using namespace std;


// DFS
void printDFS(int** edge , int n ,bool* visited ,int sv){
    cout<<sv<<" ";
    visited[sv] = true;
    for(int i = 0 ; i < n ; i++){
        if(i==sv){
            continue;
        }
        if(edge[sv][i] == 1){
            if(visited[i]){
                continue;
            }
            printDFS(edge,n,visited,i);
        }
    }
}

// This function will help to print disconnected vertices as well
void DFS(int** edge , int n){
    bool* visited = new bool[n];
    for(int i = 0 ; i < n ; i++){
        visited[i] = false;
            }

    for(int i = 0 ; i < n ; i++){
        if(visited[i] == false){
            printDFS(edge,n,visited,i);
        }
    }
    delete[] visited;
}
}

// BFS 
void printBFS(int** edge , int n ,bool* visited ,int sv){
    queue<int> vertex;
    vertex.push(sv);
    visited[sv] = true;
    while(!vertex.empty()){
        int front = vertex.front();
        vertex.pop();
        cout<<front<<" ";
        for(int i = 0 ; i < n ; i++){
            if(i==front){
                continue;
                }
            if(edge[front][i] == 1){
                if(visited[i]){
                    continue;
                }
                vertex.push(i);
                visited[i] = true;
            }
            }
                }
    }


// This function will help to print disconnected vertices as well
void BFS(int**edge , int n){
    bool* visited = new bool[n];
    for(int i = 0 ; i < n ; i++){
        visited[i] = false;
    }
    for(int i = 0 ; i < n ; i++){
        if(!visited[i]){
            printBFS(edge,n,visited,i);
        }
    }
    delete[] visited;
}






int main(){

    int n ,e;
    cout<<"Enter no of vertices ";
    cin>>n;
    cout<<"Enter no of edges ";
    cin>>e;

    // Implemented using Adjacency Matrix
    // dynamic allocation of 2D array
    int **edge = new int*[n];
    for(int i=0;i<n;i++){
        edge[i]=new int[n];
        for(int j=0;j<n;j++){
            edge[i][j]=0; // intializing all values to 0
        }
    }

    for(int i=0;i<e;i++){
        int f , s;
        cout<<"Enter"<<i<<"th edge ";
        cin>>f>>s;
        edge[f][s] = 1;
        edge[s][f] = 1;
    }


    // DFS  
    cout<<"DFS is"<<endl;
    DFS(edge,n);
    cout<<endl;


    // BFS
    cout<<"BFS is"<<endl;
    BFS(edge,n);




    // delete allocated memory
    for(int i=0;i<n;i++){
        delete [] edge[i];
    }
    


return 0;
}