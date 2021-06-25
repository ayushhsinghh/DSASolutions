#include <iostream>
#include <vector>

using namespace std;

void insertion(vector<int> &vec){
    int totalIteration = 0;
    int size = vec.size();
    for(int i=0;i<size;i++){
        for(int j=i+1;j<size;j++){
            totalIteration = totalIteration +1;
            if(vec[i] > vec[j]){
                vec[i] = vec[i] + vec[j];
                vec[j] = vec[i] - vec[j];
                vec[i] = vec[i] - vec[j];
            }            
        }
    }
    cout<<"total iterations are "<<totalIteration<<endl;
}

int main()  {
    vector<int> vec;
    int n,temp;
    cout<<"Enter Size \n";
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>temp;
        vec.push_back(temp);
    }
    for(int i=0;i<n;i++){
        cout<<vec[i]<<" ";  
          }
          cout<<endl;
    insertion(vec);
    for(int i=0;i<n;i++){
        cout<<vec[i]<<" ";  
          }

    
}