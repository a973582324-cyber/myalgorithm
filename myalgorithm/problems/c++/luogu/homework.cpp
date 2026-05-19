#include<iostream>
using namespace std;
#define Elemtype char
struct Triple
{
    int i,j;
    char e;//i为行号，j为列号，e为元素值
};
struct arrary
{
    Triple a[100];
    int nx,ny,nz;//nx为行数，ny为列数，nz为非零元素个数
};
void create(arrary &A)
{
    cout<<"请输入行数，列数，非零元素个数：";
    cin>>A.nx>>A.ny>>A.nz;
    cout<<"请输入非零元素的行号，列号，元素值："<<endl;
    for(int k=0;k<A.nz;k++)
    {
        cin>>A.a[k].i>>A.a[k].j>>A.a[k].e;
    }
}
bool judge(arrary &A,int i,int j)
{
    for(int k=0;k<A.nz;k++)
    {
        if(A.a[k].i==i && A.a[k].j==j)
        {
            return true;
        }
    }
    return false;
}
