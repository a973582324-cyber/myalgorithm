//使用链表实现栈
#include<iostream>
using namespace std;
typedef int ElemType;
struct stack
{
     ElemType data;
     struct stack *next;
};
int isempty(stack *s)
{
     if(s->next==nullptr)
        return 1;
     return 0;
}
int insert(stack*s,ElemType e){
        stack*p = new(stack);
        p->next = s->next;
        p->data = e;
        s->next = p;
        return 1;
}
int pop(stack *s,ElemType *e){
        if(s->next == nullptr)
        return 0;
        *e=s->next->data;
        stack* q=s->next;
        s->next = q->next;
        delete(q);
        return 1;
}
int top(stack *s)
{
        if(s->next == nullptr)
        return 0;
        ElemType e =s->next->data;
        return e;
}
