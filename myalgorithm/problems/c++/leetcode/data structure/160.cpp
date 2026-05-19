/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
//相交链表
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode*l=headA;
        int len1=0;
        int len2=0;
        while(l!=NULL){
            l=l->next;
            len1++;
        }
        l=headB;
        while(l!=NULL){
            l=l->next;
            len2++;
        }
        ListNode*r=len1>len2?headA:headB;
        for(int i=0;i<max(len1,len2)-min(len1,len2);i++){
            r=r->next;
        }
        ListNode*k=len1>len2?headB:headA;
        while(1){
            if(k==r)
            return k;
            k=k->next;
            r=r->next;
            if(k==NULL)
            break;
        }
        return NULL;
    }
};