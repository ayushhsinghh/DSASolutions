#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
#include<utility>
#include<map>
using namespace std;


vector<int> getPath(int **edges , int nVertex , int start , int end){
    bool *visited = new bool[nVertex];
    for(int i = 0 ; i < nVertex ; i++){
        visited[i] = false;
    }
    map<int , int> mpp;
    queue<int> q;
    bool found = false;
    vector<int> ans;
    q.push(start);
    while(q.size() != 0){
        int front = q.front();
        if(front == end){
            found = true;
            break;
        }
        visited[front] = true;
        q.pop();
        for(int i  = 0 ; i<nVertex ; i++){
            if(i==0){
                continue;
            }
            if(visited[i]){
                continue;
            }
            if(edges[i][front] == 1){
                q.push(i);
                mpp[i] = front;
            }
        }
    }
    if(found){
    ans.push_back(end);
    while(end != start){
        ans.push_back(mpp[end]);
        end = mpp[end];
    }
    }

    return ans;
}

int main(){

    int nVertex , nEdge;
    cout<<"Enter no of Vertex ";
    cin>>nVertex;
    cout<< "Enter no of Edge ";
    cin>>nEdge;

    int **edges = new int*[nVertex];
    for(int i = 0 ; i < nVertex ; i++){
        edges[i] = new int[nVertex];
        for(int j = 0 ; j<nVertex ;++j){
            edges[i][j] = 0;
        }
    }

    for(int i = 0 ; i < nEdge ; i++){
        int fVertex , sVertex;
        cout<<"Enter"<<i<<"th Edge ";
        cin>>fVertex>>sVertex;

        edges[fVertex][sVertex] = 1;
        edges[sVertex][fVertex] = 1;
    }

    int start = 2;
    int end = 5;
    vector<int> ans = getPath(edges , nVertex , start , end);

    if(ans.size() == 0) cout<<"No Path";

    for(int it: ans){
        cout<<it<<" ";
    }

return 0;
}