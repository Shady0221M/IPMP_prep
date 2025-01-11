/*You are given the head of a singly linked-list. The list can be represented as:

L0 → L1 → … → Ln - 1 → Ln
Reorder the list to be on the following form:

L0 → Ln → L1 → Ln - 1 → L2 → Ln - 2 → …
You may not modify the values in the list's nodes. Only nodes themselves may be changed.

 

Example 1:


Input: head = [1,2,3,4]
Output: [1,4,2,3]
Example 2:


Input: head = [1,2,3,4,5]
Output: [1,5,2,4,3]
 

Constraints:

The number of nodes in the list is in the range [1, 5 * 104].
1 <= Node.val <= 1000*/
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
        ListNode *prev,*current,*nxt;
        if(!head) return head;
        current=head->next;
        prev=head;
        while(current){
            nxt=current->next;
            current->next=prev;
            prev=current;
            current=nxt;
        }
        head->next=nullptr;
        return prev;
    }
    void reorderList(ListNode* head) {
        ListNode *f,*s,*new_head=head,*temp,*rhead;
        f=head;
        s=head;
        while(f && f->next && f->next->next){
            s=s->next;
            f=f->next->next;
        }
        rhead=s->next;
        f=reverse(s->next);
        
        s=head;
        temp=new ListNode(-1);
        while( f ){
            temp->next=s;
            s=s->next;
            temp=temp->next;
            temp->next=f;
            f=f->next;
            temp=temp->next;
        }
        if(s!=rhead){
            temp->next=s;
            s->next=nullptr;
        }

    }
}; 