#include<iostream>
#include<vector>
using namespace std;


class MaxHeap{
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
            int parentIndex = (childIndex -1)/2;
            if(pq.at(childIndex) > pq.at(parentIndex))
            {
                swap(pq.at(childIndex) , pq.at(parentIndex));
            }
            childIndex = parentIndex;
        }
    }

    int getMax(){
        if(isEmpty()){
            return -1;
        }
        return pq.at(0);
    }

    int remove(){
        if(isEmpty()){
            return -1;
        }
        int root = pq.at(0);
        int lastIndex = pq.size() - 1;
        swap(pq.at(0), pq.at(lastIndex));
        pq.pop_back();

        int parentIndex = 0;
        int rightChildIndex = 2 * parentIndex + 2;
        int leftChildIndex = 2 * parentIndex + 1;

        while(leftChildIndex < pq.size()){
            int minIndex = parentIndex;
            if(pq.at(minIndex) < pq.at(leftChildIndex)){
                minIndex = leftChildIndex;
            }
            if(rightChildIndex < pq.size() && pq.at(minIndex) < pq.at(rightChildIndex)){
                minIndex = rightChildIndex;
            }
            if(minIndex == parentIndex){
                break;
            }

            swap(pq.at(minIndex), pq.at(parentIndex));

            parentIndex = minIndex;
            leftChildIndex = 2 * parentIndex + 1;
            rightChildIndex = 2 * parentIndex + 2;
        }
        return root;
    }


    void print(){
        if(isEmpty()){
            return;
        }
        int i=0;
        while(i < pq.size()){
            cout<<pq.at(i)<<endl;
            i = i + 1;
        }
    }
};




int main(){

    MaxHeap pq;
    pq.insert(10);
    pq.insert(20);
    pq.insert(30);
    pq.insert(40);
    pq.insert(4);
    pq.insert(12);
    pq.insert(11);


    pq.print();    

    cout<<"After Delete "<<endl;
    pq.remove();
    pq.print();
    cout<<"After Delete "<<endl;
    pq.remove();
    pq.print();




    return 0;
}
