/*Given the head of a singly linked list, reverse the list, and return the reversed list.*/


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
class ListNode{
    public:
      int val;
      ListNode *next;
      
};
#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head==nullptr) return nullptr;
        ListNode* temp=head->next;
        ListNode* temp2,*prev=head;
        while(temp!=nullptr){
            temp2=temp->next;
            temp->next=prev;
            prev=temp;
            temp=temp2;
        }
        head->next=nullptr;
        return prev;
    }
};