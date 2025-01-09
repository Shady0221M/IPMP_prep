/*You are given the heads of two sorted linked lists list1 and list2.

Merge the two lists into one sorted list. The list should be made by splicing together the nodes of the first two lists.

Return the head of the merged linked list.

 

Example 1:


Input: list1 = [1,2,4], list2 = [1,3,4]
Output: [1,1,2,3,4,4]
Example 2:

Input: list1 = [], list2 = []
Output: []
Example 3:

Input: list1 = [], list2 = [0]
Output: [0]
 

Constraints:

The number of nodes in both lists is in the range [0, 50].
-100 <= Node.val <= 100
Both list1 and list2 are sorted in non-decreasing order.*/


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode *i,*j,*head,*temp;
        i=list1;j=list2;
        if(i==nullptr) return j;
        else if(j==nullptr) return i;
        if((i->val)<(j->val)) {
            head=i;i=i->next;
        }else{
            head=j;j=j->next;
        }
        temp=head;
        while(i!=nullptr && j!=nullptr){
            if((i->val)<(j->val)){
                temp->next=i;i=i->next;
            }else{
                temp->next=j;j=j->next;
            }
            temp=temp->next;

        }
        while(i!=nullptr){
            temp->next=i;i=i->next;temp=temp->next;
        }
        while(j!=nullptr){
            temp->next=j;j=j->next;temp=temp->next;
        }
        return head;
        
    }
};

ListNode* insert(vector<int> & arr){
    int i;
    ListNode* head=new ListNode(arr[0]);
    ListNode*temp=head;
    for(i=1;i<arr.size();i++){
        ListNode* temp2=new ListNode(arr[i]);
        temp->next=temp2;
        temp=temp2;
    }
    return head;
}
int main(){
    Solution s;
    vector<int> arr1={-9,3};
    vector<int> arr2={5,7};
    ListNode* l1=insert(arr1);
    ListNode* l2=insert(arr2);
    ListNode* l3=s.mergeTwoLists(l1,l2);
    while(l3!=nullptr){
        cout<<l3->val<<" ";
        l3=l3->next;
    }
}