/*Given the head of a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.

You should preserve the original relative order of the nodes in each of the two partitions.

 

Example 1:


Input: head = [1,4,3,2,5,2], x = 3
Output: [1,2,2,4,3,5]
Example 2:

Input: head = [2,1], x = 2
Output: [1,2]
 

Constraints:

The number of nodes in the list is in the range [0, 200].
-100 <= Node.val <= 100
-200 <= x <= 200*/

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
    ListNode* partition(ListNode* head, int x) {
        ListNode *i,*j,*temp,*ls,*lr;
        ls=new ListNode();
        lr=new ListNode();
        i=ls;j=lr;
        temp=head;
        while(temp){
            if(temp->val<x){
                i->next=temp;
                i=i->next;
            }else{
                j->next=temp;
                j=j->next;
            }
            temp=temp->next;
        }
        i->next=lr->next;
        j->next=nullptr;
        return ls->next;
    }
};