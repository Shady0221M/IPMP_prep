/*Search an element in a Linked List

Problem Statement: Given the head of a linked list and an integer value,
 find out whether the integer is present in the linked list or not. Return true if it is present, or else return false.*/
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
bool check_ll(Node* head, int i){
    while(head!=nullptr){
        if(head->data==i){return true;}
        head=head->next;
    }
    return false;
}
Node* insert(vector<int> & arr){
    int i;
    Node* head=new Node(arr[0]);
    Node*temp=head;
    for(i=1;i<arr.size();i++){
        Node* temp2=new Node(arr[i]);
        temp->next=temp2;
        temp=temp2;
    }
    return head;
}
int main(){
    vector<int> arr={23,64,16,84,12,45,87};
    Node* head=insert(arr);
    cout<<check_ll(head,120);
}