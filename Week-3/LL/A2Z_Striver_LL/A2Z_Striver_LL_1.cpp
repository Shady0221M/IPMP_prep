#include<iostream>
#include<vector>
using namespace std;
class Node{
    public:
        int data;
        Node* next;
    Node(int data1,Node* next1){
        data=data1;
        next=next1;
    } 
    Node(int data1){
        data=data1;
        next=nullptr;
    } 
};
int main(){
    cout<<"Hello"<<endl;
    vector<int> arr={23,64,16,84};
    int i;
    Node* node_that=new Node(arr[0]);
    for(i=1;i<arr.size();i++){
        Node*temp=new Node(arr[i]);
        temp->next=node_that;
        node_that=temp;
    }
    Node* temp=node_that;
    while(temp!=nullptr){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}