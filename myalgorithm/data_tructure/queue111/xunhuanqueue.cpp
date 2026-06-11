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
    q->r = MAXSIZE-1;
}
void push(queue* q,ElemType e){
    if((q->r+1)%MAXSIZE==q->l){
            return;
    }
    q->data[q->r] = e;
    q->r = (q->r+1)%MAXSIZE;
}
void pop(queue* q){
    q->l=(q->l+1)%MAXSIZE;
}
int main(){
    queue a;
    intiqueue(&a);


}

