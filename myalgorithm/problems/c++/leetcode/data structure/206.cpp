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
//反转链表
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
       int len=0;
       ListNode*l=head;
       while(l!=nullptr){
        len++;
        l=l->next;
       }
       if(len==0||len==1)
       return head;
       ListNode*first=head;
       ListNode*second=first->next;
       ListNode*third=second->next;
       while(second!=nullptr){
        second->next=first;
        first=second;
        second=third;
        if(third!=nullptr)
        third=third->next;
       }
       head->next=nullptr;
       return first;
    }
};