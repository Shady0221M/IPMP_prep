/*Given a linked list, swap every two adjacent nodes and return its head. You must solve the problem without modifying the values in the list's nodes (i.e., only nodes themselves may be changed.)

 

Example 1:

Input: head = [1,2,3,4]

Output: [2,1,4,3]

Explanation:

Example 2:

Input: head = []

Output: []

Example 3:

Input: head = [1]

Output: [1]

Example 4:

Input: head = [1,2,3]

Output: [2,1,3]
Constraints:

The number of nodes in the list is in the range [0, 100].
0 <= Node.val <= 100*/

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
    ListNode* swapPairs(ListNode* head) {
        
        if(!head || !head->next) return head;
        ListNode *tmp,*tmp3;
        tmp=head;
        ListNode *head_new=head->next;
        tmp3=new ListNode();
        while(tmp && tmp->next){
            ListNode *tmp2=tmp->next;
            tmp->next=tmp2->next;
            tmp2->next=tmp;
            tmp3->next=tmp2;
            tmp3=tmp;
            tmp=tmp->next;
        }
        return head_new;
    }
};