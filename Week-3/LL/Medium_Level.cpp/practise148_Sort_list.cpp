/*Given the head of a linked list, return the list after sorting it in ascending order.

 

Example 1:


Input: head = [4,2,1,3]
Output: [1,2,3,4]
Example 2:


Input: head = [-1,5,3,4,0]
Output: [-1,0,3,4,5]
Example 3:

Input: head = []
Output: []
 

Constraints:

The number of nodes in the list is in the range [0, 5 * 104].
-105 <= Node.val <= 105
 

Follow up: Can you sort the linked list in O(n logn) time and O(1) memory (i.e. constant space)?*/

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
ListNode* merge(ListNode *t1,ListNode *t2){
    ListNode *tmp,*head;
    head=new ListNode();
    tmp=head;
    while(t1 && t2){
        if(t1->val<t2->val){
            tmp->next=t1;
            t1=t1->next;
            
        }else{
            tmp->next=t2;
            t2=t2->next;
        }
        tmp=tmp->next;
    }
    if(t1) tmp->next=t1;
    if(t2) tmp->next=t2;
    return head->next;
}
    
    ListNode* sortList(ListNode* head) {
        if(!head || !head->next ){return head;}
        ListNode *t,*h;
        t=head;
        h=head;
        while( h->next && h->next->next){
            h=h->next->next;
            t=t->next;
        }
        h=t->next;
        t->next=nullptr;
        head=sortList(head);
        h=sortList(h);
        
        return merge(head,h);
    }
};