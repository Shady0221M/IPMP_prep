/*Find the Length of a Linked List


Problem Statement: Given the head of a linked list, print the length of the linked list.*/
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
int length__ll(Node* head){
    int count=0;
    while(head!=nullptr){count++;head=head->next;}
    return count;
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
    cout<<length__ll(head);
}