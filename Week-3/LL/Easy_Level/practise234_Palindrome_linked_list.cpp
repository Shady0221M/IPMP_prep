/*Given the head of a singly linked list, return true if it is a 
palindrome
 or false otherwise.

 

Example 1:


Input: head = [1,2,2,1]
Output: true
Example 2:


Input: head = [1,2]
Output: false
 

Constraints:

The number of nodes in the list is in the range [1, 105].
0 <= Node.val <= 9*/

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
        ListNode* temp,*prev,*nxt;
        temp=head->next;
        prev=head;
        while(temp!=nullptr){
                nxt=temp->next;
                temp->next=prev;
                prev=temp;
                temp=nxt;
        }
        head->next=nullptr;
        return prev;
    }
    bool isPalindrome_eff(ListNode* head) {
        if(head==nullptr || head->next==nullptr) return true;
        ListNode  *slow,*fast,*temp;
        slow=head;
        fast=head;
        while(fast->next!=nullptr && fast->next->next!=nullptr ){
            fast=fast->next->next;
            slow=slow->next;}
        ListNode*tail;
        tail=reverse(slow);
        temp=head;
        int i=0;
        while(tail!=slow){
            if(temp->val!=tail->val) return false;
            tail=tail->next;
            temp=temp->next;
        }
        return true;

    }

    bool isPalindrome(ListNode* head) {
        ListNode* temp=head;
        string s;
        while(temp!=nullptr){
            s+=('0'+temp->val);
            temp=temp->next;
        }
        cout<<s<<endl;
        int n=s.size(),i;
        for(i=0;i<n/2;i++){
            if(s[i]!=s[n-i-1]) {cout<<"hi "<<s[i]<<endl;return false;}
        }
        
        return true;
    }
};