#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
#include<utility>
using namespace std;

// Question:
// Given N activities with their start and finish day given in array start[ ] and end[ ].
// Select the maximum number of activities that can be performed by a single person,
// assuming that a person can only work on a single activity at a given day.
// Note : Duration of the activity includes both starting and ending day.

static bool myComp(pair<int, int> a, pair<int, int> b)
    {
        return a.second < b.second;
    }


int activitySelector(vector<int> start, vector<int> end) {
    int n = start.size();
    vector<pair<int , int>> comb;
        int count = 1;
        
        for(int i = 0 ; i < n ; i++){
            comb.push_back(make_pair(start[i] , end[i]));
        }
        
        sort(comb.begin() , comb.end() , myComp);
        pair<int , int > last = comb[0];
         for(int i = 0 ; i < n ; i++){
             if(comb[i].first > last.second){
                 count++;
                 last = comb[i];
             }
         }
         
         return count;
}


int main(){
    // activity selection using greedy approach
    vector<int> start = {1, 3, 0, 5, 8, 5};
    vector<int> end = {2, 4, 6, 7, 9, 9};
    cout<<activitySelector(start, end);



return 0;
}