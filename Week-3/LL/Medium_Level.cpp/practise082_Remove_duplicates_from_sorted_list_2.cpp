/*Given the head of a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list. Return the linked list sorted as well.

 

Example 1:


Input: head = [1,2,3,3,4,4,5]
Output: [1,2,5]
Example 2:


Input: head = [1,1,1,2,3]
Output: [2,3]
 

Constraints:

The number of nodes in the list is in the range [0, 300].
-100 <= Node.val <= 100
The list is guaranteed to be sorted in ascending order.*/

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
    void delete_node(ListNode* prev){
        ListNode* temp=prev->next;
        prev->next=temp->next;
        delete(temp);
    }
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *temp=head,*temp2;
        temp2=new ListNode();
        temp2->next=head;
        temp=temp2;

        while(temp){
           while(temp->next && temp->next->next && (temp->next->val==temp->next->next->val)){
                ListNode*j=temp->next->next;
                while(j && (temp->next->val==j->val)){
                    j=j->next;
                    delete_node(temp->next);
                }
                delete_node(temp);
            }
            temp=temp->next;
        }
        return temp2->next;
    }
};