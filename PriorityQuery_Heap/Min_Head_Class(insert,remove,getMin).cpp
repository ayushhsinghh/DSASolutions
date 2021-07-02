#include <iostream>
#include<vector>

using namespace std;


class MinHeap{
    private:
    vector<int> pq;

    void swap(int &a , int &b){
        a = a + b;
        b = a - b;
        a = a - b;
    }

    bool isEmpty(){
        if(pq.size() == 0){
            return true;
        }
        return false;
    }

    public:
    void insert(int data){
        pq.push_back(data);

        int childIndex = pq.size() - 1;

        while(childIndex > 0){
            int parentIndex = (childIndex - 1)/2;

            if(pq[parentIndex] > pq[childIndex]){
                // Swap 
                swap(pq[parentIndex] , pq[childIndex]);
            }
            else{
                break;
            }
            childIndex = parentIndex;
        }
    }


    // we always remove the min. Element in MinHeap
    int remove(){
        if(isEmpty()){
            return -1;
        }

        int root = pq.at(0);
        int lastIndex = pq.size() -1;
        swap(pq.at(0) , pq.at(lastIndex));
        pq.pop_back();

        int parentIndex = 0;
        int leftChildIndex = 2 * parentIndex + 1;
        int rightChildIndex = 2 * parentIndex + 2;

        while(leftChildIndex < pq.size()){
            int minNodeIndex = parentIndex;
            if(pq.at(minNodeIndex) > pq.at(leftChildIndex)){
                minNodeIndex = leftChildIndex;
            }
            if(rightChildIndex < pq.size() && pq.at(minNodeIndex) > pq.at(rightChildIndex)){
                minNodeIndex = rightChildIndex;
            }
            if(minNodeIndex == parentIndex){
                break;
            }
            swap(pq.at(parentIndex), pq.at(minNodeIndex));

            parentIndex = minNodeIndex;
            leftChildIndex = 2 * parentIndex + 1;
            rightChildIndex = 2 * parentIndex + 2;
        }

        return root;
    }

    int getMin(){
        if(isEmpty()){
            return -1;
        }
        return pq.at(0);
    }



    void print(){
        if(pq.size() == 0){
            cout<<"Size is zero";
        }
        else{
            for(int i=0;i<pq.size();i++){
                cout<<pq.at(i)<<endl;
            }
        }
    }



};


int main(){
    MinHeap pq;
    pq.insert(10);
    pq.insert(5);
    pq.insert(20);
    pq.insert(4);
    pq.insert(100);
    pq.insert(6);

    int min = pq.getMin();
    cout<<"Min is :"<<min<<endl;

    // pq.print();


    cout<<"After Delete"<<endl;

    int first = pq.remove();
    int second = pq.remove();

    cout<<"first : "<< first <<" second : "<< second <<endl;


    min = pq.getMin();
    cout<<"Min is :"<<min<<endl;

    // pq.print();

}