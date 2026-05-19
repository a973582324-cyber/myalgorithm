//链表实现的两数相加
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
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode*l=l1;
        int len1=0;
        while(l!=nullptr){
            l=l->next;
            len1++;
        }
        l=l2;
        int len2=0;
        while(l!=nullptr){
            l=l->next;
            len2++;
        }
        int len=min(len1,len2);
        l=new ListNode;
        ListNode*r=l;
        ListNode*a=nullptr;
        for(int i=0;i<len;i++){
            ListNode*p=new ListNode;
            r->val+=l1->val+l2->val;
            p->val=0;
            if(r->val>=10){
                p->val++;
                r->val%=10;
            }
            p->next=nullptr;
            r->next=p;
            if(i==len-1)
                a=r;
            r=p;
            l1=l1->next;
            l2=l2->next;
        }
        if(len1==len2){
            if(r->val==0){
                a->next=nullptr;
                delete r;
            }
            return l;
        }
        else if(len1>len2){
           r->val+=l1->val;
           r->next=l1->next;
        }
        else{
            r->val+=l2->val;
            r->next=l2->next;
        }
        for(int i=0;i<max(len1,len2)-min(len1,len2);i++){
            a=a->next;
            if(i==max(len1,len2)-min(len1,len2)-1&&a->val==10){
                ListNode*p=new ListNode;
                p->next=nullptr;
                p->val=1;
                a->next=p;
                a->val=0;
            }
            if(a->val==10){
                a->next->val+=1;
                a->val=0;
            }
           
        }
        return l;
    }
};
