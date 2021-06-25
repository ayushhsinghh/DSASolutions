#include <iostream>
#include <vector>

using namespace std;

void bubblesort(vector<int> &vec){
    int totalIteration = 0;
    int size = vec.size();
    for(int i=0;i<size - 1;i++){
        bool swapdone = false;
        for(int j=0;j<size-i-1;j++){
            totalIteration = totalIteration + 1;
            if(vec[j] > vec[j+1]){
                vec[j] = vec[j] + vec[j+1];
                vec[j+1] = vec[j] - vec[j+1];
                vec[j] = vec[j] - vec[j+1];
                swapdone = true;
            }
        }
        if(swapdone == false){
                break;
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
    bubblesort(vec);
    for(int i=0;i<n;i++){
        cout<<vec[i]<<" ";  
          }

    
}