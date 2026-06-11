#include<iostream>
using namespace std;
#define MAXSIZE 100
#define ElemType int
struct queue
{
    int data[MAXSIZE];
    int l;
    int r;
};
void intiqueue(queue* q)
{
    q->data[0] = 0;
    q->l = 0;
    q->r = 0;
}
void push(queue* q,ElemType e){
    if(q->r - q->l==MAXSIZE){
        if(!resort(q)){
            return;
        }
    }
    q->data[q->r] = e;
    q->r++;
}
void pop(queue* q){
    if(q->l == q->r)
        return;
    q->l++;
}
int resort(queue* q){
    if(q->l == 0)
        return 0;
    for(int i = q->l;i <= q->r;i++)
        q->data[i-q->l] = q->data[i];
    q->r -=q->l;
    q->l = 0;
    return 1;
}
int main(){
    queue a;
    intiqueue(&a);


}

