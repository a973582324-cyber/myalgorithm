#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;
typedef int ElemType;
typedef struct node{   
    int data;
    struct node * next;
    struct node * prior;
} NODE;
int getlength(NODE*&head){
    auto l = head;
    int len = 0;
    while(l!=nullptr){
        len++;
        l = l->next;
    }
    return len;
}
NODE*headinsert(int len){
    auto head = new(NODE);
    head->next = nullptr;
    if(len<0)
    return head;
    while(len--){
        NODE*p = new(NODE);
        cin >> p -> data;
        p->next = head->next;
        p->prior = head;
        if(head->next != nullptr)
        head->next->prior = p;
        head->next = p;
    }
    return head;
}
NODE*backinsert(int len){
    auto head = new(NODE);
    head->next = nullptr;
    NODE*r = head;
    if(len<0)
    return head;
    while(len--){
        NODE*p = new(NODE);
        cin>>p->data;
        r->next = p;
        p->prior=r; 
        p->next = nullptr;
        r = p;
    }
    return head;
}
NODE*reservenode(NODE*&head){
    //利用三指针，third存储second下一个节点，便于指针后移
    //second存储节点指向first的节点
    auto first = head;
    auto second = first->next;
    NODE*third = nullptr;
    first->next = nullptr;
    while(second!=nullptr){
        third = second->next;
        second->next = first;
        first = second;
        second = third;
    }
    //时间复杂度o(n)
    return first;
}
NODE*findmidnode(NODE*&head){
    if(head->next==nullptr)
    return head;
    NODE*fast = head->next;
    NODE*slow = head;
    //令fast永远比slow多走一步，则slow最终指向中间节点
    while(fast->next!=nullptr&&fast->next->next!=nullptr)/*判断fast是否可以走两步*/{
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow->next;
}
NODE*findlastk(NODE*&head,int k){
    NODE*fast = head;
    NODE*slow = fast;
    int len = getlength(head);
    if(k>len||k<0){
    return head;
    }//检查k是否合法
    while(k--){
        fast = fast->next;
    }//令fast永远多比slow多走k步
    while(fast!=nullptr){
        fast = fast->next;
        slow = slow->next;
    }//当fast指向空时，slow指向倒数第k个节点
    return slow;
    //时间复杂度o(n)
}
NODE* resortnode(NODE*&head)
{
    if (head == nullptr || head->next == nullptr)
        return head;
    NODE* p = findmidnode(head);//令p指向中间节点
    NODE* mid = reservenode(p->next);//将中间节点之后的链表反转
    p->next = nullptr;
    auto l1 = head->next;
    auto l2 = mid;
    NODE* now = new(node);
    NODE* head1 = now;
    while(l1!=nullptr&&l2!=nullptr)
    {
        now->next = l1;
        l1 = l1->next;
        now = now->next;
        now->next = l2;
        l2 = l2->next;
        now = now->next;
    }
    if(l1!=nullptr)now->next = l1;
    if(l2!=nullptr)now->next = l2;
    return head1;
}
int find_ans(vector<int>&a){
    unordered_map<int,int>hash;
    for(int b:a)
    {
        if(b > 0)
        hash[b] = 1;
    }
    int i = 0;
    while(++i)
    {
        if (hash[i] != 1)
        return i;
    }
    return 0;    
}
//插入新节点
int insert(NODE* head,int k,ElemType e){
    int n = 0;
    NODE* p = head;
    for(int i=0;i<k-1;i++){
        p = p->next;
        n++;
        if(p == nullptr)
        return 0;
    }
    NODE* q=new(NODE);
    q->data = e;
    q->prior = p;
    q->next =p->next;
    p->next->prior = q;
    p->next = q; 
}
//判断是否有环存在
int iscycle(NODE*head){
        NODE*fast = head;
        NODE*slow = fast;
    while(fast != nullptr && fast->next != nullptr){
        fast=fast->next->next;
        slow=slow->next;
        if(fast==slow)
        return 1;
    }
    return 0;
}
//找到环的入口
NODE* findenter(NODE*head){
    NODE*fast = head;
    NODE*slow = fast;
    while (fast!=nullptr&&fast->next!=nullptr){
        fast=fast->next->next;
        slow=slow->next;
        if (fast==slow)
        {
            NODE*p = fast;
            int count = 0;
            while(p!=slow){
                count++;
                p = p->next;
            }
            fast=head;
            slow=head;
            for(int i=0;i<count;i++){
                fast = fast -> next;
            }
            while(fast!=slow)
            {
                fast=fast->next;
                slow=slow->next;
            }
            return slow;
        }
    }

}
int main(){
    /*NODE*head=backinsert(7);
    head=resortnode(head);
    NODE*l=head->next;
    while(l!=nullptr){
        cout<<l->data<<' ';
        l=l->next;
    }*/
   vector<int>a(5,1);
    cout<<find_ans(a);
}
