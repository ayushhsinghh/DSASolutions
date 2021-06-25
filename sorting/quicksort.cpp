#include <iostream>
#include <vector>

using namespace std;

int partition(int low , int high , vector<int> &vec){
  if(low<high){
      int temp;
      int pivot = vec[low];
      int i = low, j = high;
      while(i<j){
          while(vec[i] <= pivot && i<high){
          i++;
      }
      while(vec[j] > pivot){
          j--;
      }
      if(i<j){
        vec[i] = vec[i] + vec[j];
        vec[j] = vec[i] - vec[j];
        vec[i] = vec[i] - vec[j];
      }}
    vec[low] = vec[low] + vec[j];
        vec[j] = vec[low] - vec[j];
        vec[low] = vec[low] - vec[j];
      return j;
  }   
}

void quickSort(vector<int> &vec ,int  low ,int  high){
    
    if(low < high){
        int j;
        j = partition(low , high , vec);
        quickSort(vec , low , j-1);
        quickSort(vec , j+1 , high);
    }
  
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
    quickSort(vec , 0 , vec.size() - 1);
    for(int i=0;i<n;i++){
        cout<<vec[i]<<" ";  
          }
    
}