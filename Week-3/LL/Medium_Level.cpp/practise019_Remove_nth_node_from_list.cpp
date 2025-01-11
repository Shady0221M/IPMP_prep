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
    ListNode* reverse(ListNode *head){
        ListNode *prev,*nxt,*current;
        if(!head->next){return head;}
        prev=head;
        current=head->next;
        while(current){
           nxt=current->next;
            current->next=prev;
            prev=current;
            current=nxt; 
        }
        head->next=nullptr;
        return prev;
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int i=1;
        ListNode *prev,*nxt,*current;
        if(!head->next && n==1){delete(head);return nullptr;}
        prev=head;
        current=prev->next;
        while(current){
            nxt=current->next;
            current->next=prev;
            prev=current;
            current=nxt;
            i++;
        }
        head->next=nullptr;
        if(n==1){
            current=prev->next;
            delete(prev);
            head=reverse(current);
            reverse(current);
        }else{
            ListNode* newhead=prev,*temp;
            current=prev->next;
            int j=1;
            while(current){
                j++;
                if(j==n+1){
                    temp=current;
                }
                nxt=current->next;
                current->next=prev;
                prev=current;
                current=nxt;
            }
            newhead->next=nullptr;
            if(n==i){
                nxt=head->next;
                delete(head);
                return nxt;
            }
            nxt=temp->next;
            temp->next=nxt->next;
            delete(nxt);
            return head;
        }
        return head;
    }
};