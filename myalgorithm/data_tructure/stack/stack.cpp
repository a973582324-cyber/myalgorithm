#include<iostream>
using namespace std;
#define MAXSIZE  100
typedef int ElemType;
struct stack
{
    ElemType data[MAXSIZE];
    int top;
};
void initStack(stack *s){
    s->top = -1;
}

int isempty(stack *s){
    if(s->top == -1)
    return 1;
    return 0;
}
int push(stack *s,ElemType e){
    s->top++;
    if(s->top == MAXSIZE)
    return 0;
    else
    s->data[s->top] = e;
    return  1;
}
ElemType pop(stack *s,ElemType *e)
{
    if(s->top == 1)
    {
        return 0;
    }
    *e = s->data[s->top];
    s->top--;
    return 1;
}
ElemType gettop(stack *s,ElemType *e)
{
    if(s->top == -1)
    {
        return 0;
    }
    *e = s->data[s->top];
    return 1;
}
int main(){
    stack s;
    initStack(&s);
    push(&s,10);
    push(&s,20);
    push(&s,30);
    cout<<s.data[s.top]<<endl;
    ElemType e;
    pop(&s,&e);
    cout<<e<<endl;
}