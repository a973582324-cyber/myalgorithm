//表达式树求值
//正常的是中缀表达式
//现在需要给你一个后缀表达式，要求计算出运算式的结果
#include<iostream>//计算机看的都是后缀表达式
using namespace std;
//算法实现过程，
//1.建立栈，将后缀表达式从前往后扫，
//2.扫到数字入栈，扫到运算符出栈进行运算，
//建立两个变量存放出栈的两个元素，先出栈的进入后边的变量
//运算完后再入栈
#include<iostream>
using namespace std;
const int MAXSIZE = 100;
typedef int ElemType;
char str[] = "82/2+56*-";
struct stack
{
    ElemType *data;
    int top;
    stack():data(nullptr),top(-1){};//初始化列表
};
typedef enum{
    add,mod,sub,mul,DIV,eos,num,l_p,r_p
}content;
stack* initStack(){
    stack*s = new(stack);
    s->data = new ElemType[MAXSIZE];
    s->top = -1;
    return s;
}

int isempty(stack *s){
    if(s->top == -1)
        return 1;
    return 0;
}
ElemType push(stack *s,ElemType e){
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
content gettoken(char* s,int* index)
{
    *s = str[*index];
    *index = *index + 1;
    switch (*s)
    {
    case '(': 
        return l_p;
    case ')':
        return r_p;
    case '+':
        return add;
    case '*':
        return mul;
    case '-':
        return sub;
    case '/':
        return DIV;
    case '%':
        return mod;
    case '/0':
        return eos;
    default:
        return num;
    }
}
int eval(stack *s)
{
    int op1,op2;
    int index = 0;
    char ss;
    content token = gettoken(&ss,&index);
    ElemType res;
    while(token != eos)
    {
        if(token == num) push(s,ss-'0');
        else
        {
            pop(s,&op1),pop(s,&op2);
            switch (token)
            {
            case add:
                //........
                break;
            
            default:
                break;
            }
        }
    }
}
int main(){
    stack*s = initStack();
    int ans = eval(s);
}