/*Given the head of a singly linked list and two integers left and right where left <= right, reverse the nodes of the list from position left to position right, and return the reversed list.

 

Example 1:


Input: head = [1,2,3,4,5], left = 2, right = 4
Output: [1,4,3,2,5]
Example 2:

Input: head = [5], left = 1, right = 1
Output: [5]
 

Constraints:

The number of nodes in the list is n.
1 <= n <= 500
-500 <= Node.val <= 500
1 <= left <= right <= n*/
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
//Time complexity O(n)
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(left==right) return head;
        int i=1;
        ListNode *temp,*prev,*marki,*nxt,*marka;
        temp=head;
        while(temp){
            if(i<left-1){
                temp=temp->next;
            }
            else if(i==left-1){
                marka=temp;
                temp=temp->next;
            }
            else if (i>right){
                break;//Do something
            }else{
                if(i==left){
                    prev=temp;
                    marki=temp;
                    temp=temp->next;
                    
                }else{
                    nxt=temp->next;
                    temp->next=prev;
                    prev=temp;
                    temp=nxt;
                }
            }
            i++;
        }
        marki->next=temp;
        if(left!=1){marka->next=prev;return head;}
        else  {return prev;} 
    }
};