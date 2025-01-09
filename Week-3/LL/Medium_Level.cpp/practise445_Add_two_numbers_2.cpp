/*You are given two non-empty linked lists representing two non-negative integers. The most significant digit comes first and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

 

Example 1:


Input: l1 = [7,2,4,3], l2 = [5,6,4]
Output: [7,8,0,7]
Example 2:

Input: l1 = [2,4,3], l2 = [5,6,4]
Output: [8,0,7]
Example 3:

Input: l1 = [0], l2 = [0]
Output: [0]
 

Constraints:

The number of nodes in each linked list is in the range [1, 100].
0 <= Node.val <= 9
It is guaranteed that the list represents a number that does not have leading zeros.*/
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
    ListNode* reverse(ListNode* head){
        ListNode *nxt,*temp=head->next,*prev;
        prev=head;
        while(temp){
            nxt=temp->next;
            temp->next=prev;
            prev=temp;
            temp=nxt;
        }
        head->next=nullptr;
        return prev;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        l1=reverse(l1);
        l2=reverse(l2);
        ListNode *l3=nullptr,*temp;
        int carry=0;
        while(l1 && l2){
            int x=l1->val+l2->val+carry;
            int sum=x%10;
            carry=x/10;
            temp=new ListNode(sum,l3);
            l3=temp;
            l1=l1->next;
            l2=l2->next;
        }
        while(l1){
            int x=l1->val+carry;
            int sum=x%10;
            carry=x/10;
            temp=new ListNode(sum,l3);
            l3=temp;
            l1=l1->next;
        }
        while(l2){
            int x=l2->val+carry;
            int sum=x%10;
            carry=x/10;
            temp=new ListNode(sum,l3);
            l3=temp;
            l2=l2->next;
        }
        if(carry){
            temp=new ListNode(1,l3);
            l3=temp;
        }
        return l3;
    }
};