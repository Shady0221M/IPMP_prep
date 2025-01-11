/**/
#include<iostream>
#include<vector>
using namespace std;
struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
  class Solution {
public:
    Node* flatten(Node* head) {
        vector<Node*> stk;
        Node* pseudohead=new Node;
        Node* prev;
        prev=pseudohead;
        prev->child=nullptr;
        if(head) stk.push_back(head);
        else return head;
        while(stk.size()){
            Node* temp=stk.back();
            cout<<temp->val<<endl;
            stk.pop_back();
            prev->next=temp;
            temp->prev=prev;
            prev=temp;
            if(temp->next) stk.push_back(temp->next);
            if(temp->child) stk.push_back(temp->child);
            temp->child=nullptr;
        }
        return pseudohead->next;
    }
};