#include <iostream>
#include <vector>

using namespace std;

void merge(vector<int> &vec , int low , int mid , int high){
    int i = 0 , j = 0  , k = low;
    int n1 = mid - low + 1;
    int n2 =  high - mid;

    vector<int> L;
    vector<int> R;

    for(int i=0;i<n1;i++){
        L.push_back(vec[low + i]);
    }
    for(int i=0;i<n2;i++){
        R.push_back(vec[mid + 1 + i]);
    }

    while(i < n1 && j < n2){
        if(L[i] <= R[j]){
            vec[k] = L[i];
            k++;
            i++;
            cout<<L[i]<<endl;
        }
        else{
            vec[k] = R[j];
            k++;
            j++;
            cout<<R[j]<<endl;
        }
    }
    while(i < n1){
        vec[k] = L[i];
        i++;
        k++;
    }
    while(j < n2){
        vec[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(vector<int> &vec , int low , int high){
    int mid;

    if(low < high){
        mid = (low +high)/2;
        mergeSort(vec , low , mid);
        mergeSort(vec , mid+1 , high);
        merge(vec , low , mid , high);
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
    mergeSort(vec , 0 , vec.size() -1 );
    for(int i=0;i<n;i++){
        cout<<vec[i]<<" ";  
          }
}