#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
#include <array> 
#include<utility>
using namespace std;

vector<int>* getPathHelper(int **edges , int nVertex , int start , int end ,bool *visited){
    if(start == end){
        vector<int> *ans = new vector<int>;
        ans->push_back(start);
        return ans;
    }
    visited[start] = true;
    vector<int> *result = NULL;
    for(int i = 0 ; i<nVertex ; i++){
        if(i==start){
            continue;
        }
        if(visited[i]){
                continue;
            }
        if(edges[i][start]==1){
            // cout<<"Reached helper"<<endl;
            vector<int> *temp = getPathHelper(edges , nVertex , i , end , visited );
            if(temp != NULL){
                result = temp;
                break;
            }
        }
    }
    if(result!=NULL)
    {
        result->push_back(start);

    }

    return result;

}


vector<int>* getPath(int **edges , int nVertex , int start , int end){
    bool* visited = new bool[nVertex];
    for(int i = 0 ; i < nVertex ; i++){
        visited[i] = false;
    }

    return getPathHelper(edges ,  nVertex ,  start ,  end , visited);
}

int main(){

    int nVertex , nEdge;
    cin>>nVertex>>nEdge;

    int **edges = new int*[nVertex];
    for(int i=0;i<nVertex;i++){
        edges[i]=new int[nVertex];
        for(int j=0;j<nVertex;j++){
            edges[i][j]=0; // intializing all values to 0
        }
    }

     for(int i=0;i<nEdge;i++){
        int f , s; // f = first vertex and s = second vertex
        cout<<"Enter"<<i<<"th edge ";
        cin>>f>>s;
        edges[f][s] = 1;
        edges[s][f] = 1;
    }

    vector<int> *ans  = getPath(edges , nVertex , 1 , 3);

    for(int i=0;i<ans->size();i++)
  {
    cout<<ans->at(i)<<" ";
  }




return 0;
}