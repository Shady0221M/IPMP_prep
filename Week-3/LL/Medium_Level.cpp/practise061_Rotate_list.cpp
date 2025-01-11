/*Given the head of a linked list, rotate the list to the right by k places.


Example 1:

Input: head = [1,2,3,4,5], k = 2
Output: [4,5,1,2,3]
Example 2:


Input: head = [0,1,2], k = 4
Output: [2,0,1]
 
Constraints:

The number of nodes in the list is in the range [0, 500].
-100 <= Node.val <= 100
0 <= k <= 2 * 109*/
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
    int length(ListNode* current){
        int i=0;
        while(current){
            i++;
            current=current->next;
        }
        return i;
    }
    ListNode* reverse(ListNode *head){
        if(!head->next) return head;
        ListNode* prev=head,*current=head->next,*next;
        while(current){
            next=current->next;
            current->next=prev;
            prev=current;
            current=next;
        }
        head->next=nullptr;
        return prev;
    }
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head || !head->next) return head;
        int n=length(head);
        k=k%n;
        if(k==0) return head;
        int j=n-k;
        int i=1;
        ListNode* current=head;
        while(i<j){
            i++;current=current->next;
        }
        ListNode* tmp=current->next;
        current->next=nullptr;
        current=tmp;
        while(tmp->next){
            tmp=tmp->next;
        }
        tmp->next=head;

        return current;
    }
};