/*Delete Last Node of Linked List


Problem Statement: Given a linked list, delete the tail of the linked list and print the updated linked list.*/
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
void print__ll(Node* head){
    Node* temp;
    temp=head;
    while(temp!=nullptr){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}
void delete_last_node(Node*head){
    Node*temp=head;
    if(temp->next==nullptr){
        delete(head);
        return;
    }
    while(temp->next->next!=nullptr){
        temp=temp->next;
    }
    delete(temp->next);
    temp->next=nullptr;
    print__ll(head);
}

int main(){
    vector<int> arr={23,64,16,84};
    Node* head=insert(arr);
    print__ll(head);
    delete_last_node(head);
    delete_last_node(head);
    delete_last_node(head);
    delete_last_node(head);
}