#include<iostream>
using namespace std;

// 常见排序算法的数组实现。
// 约定：除特别说明外，待排序数据放在 arr[1..n]，arr[0] 用作哨兵或临时空间。
// 复杂度：冒泡/选择/插入为 O(n^2)，快速/归并/希尔排序通常用于更大规模数据。

typedef int ElemType;
struct array_
{
    ElemType data[100];
    int len = 0;
};
void print(const array_ &a)
{
    for(int i = 1;i<=a.len;i++)
    {
        cout<<a.data[i]<<(i!=a.len?' ':'\n');
    }
}
void bubblesort(ElemType arr[],int n)//从1位置开始,n是长度
{
    int flag = 1;
    int m = n-1;
    while(m > 0&&flag)
    {
        flag = 0;
        for(int i = 1;i<=m;i++)
        {
            if(arr[i+1]<arr[i])
            {
                flag = 1;
                swap(arr[i+1],arr[i]);
            }
        }
    }
}
void selectsort(ElemType arr[],int n)
{
    for(int i = n;i>1;i--)
    {
        int index = 1;
        for(int j = 1;j<=i;j++)
        {
            if(arr[j]>arr[index])
            {
                index = j;
            }
        }
        swap(arr[index],arr[i]);
    }
}
void insertsort(ElemType arr[],int n)
{
    for(int i = 2;i<=n;i++)
    {
        arr[0] = arr[i];
        if(arr[i]<arr[i-1])
        {
            arr[i] = arr[i-1];
            int j;
            for(j = i-2;arr[0]<arr[j];j--)
            {
                arr[j+1] = arr[j];                
            }
            arr[j+1] = arr[0];
        }
    }
}
void quicksort(int arr[],int l,int r)
{
    // 以最右元素为枢轴，把区间原地划分后递归处理两侧。
    if(l>=r)
        return;
    int i = l;
    int j = r;
    int p = arr[r];
    while(i<j)
    {
        while(i<j&&arr[i]<=p)i++;
        swap(arr[i],arr[j]);
        while(i<j&&arr[j]>=p)j--;
        swap(arr[i],arr[j]);
    }
    quicksort(arr,l,j-1);
    quicksort(arr,i+1,r);
}
void ss(int arr[],int k,int n)
{
    for(int i = k+1;i<=n;i++)
    {
        if(arr[i]<arr[i-k])
        {
            arr[0] = arr[i];
            int j;
            for(j = i-k;j>0&&arr[0]<arr[j];j-=k)
                arr[j+k] = arr[j];
            arr[j+k] = arr[0];
        }
    }
}
void shellsort(int arr[],int con[],int n,int nn)
{
    for(int i = 0;i<nn;i++)
    {
        ss(arr,con[i],n);
    }
}
void mergesort(int arr[],int b[],int l,int r)
{
    // b 是归并时的辅助数组，调用方需要保证它至少覆盖 [l,r]。
    if(l>=r)
        return;
    int mid = l+r>>1;
    mergesort(arr,b,l,mid);
    mergesort(arr,b,mid+1,r);

    int i = l,j = mid + 1,k = l;
    while(i<=mid&&j<=r)
    {
        if(arr[i]<=arr[j])b[k++] = arr[i++];
        else
        b[k++] = arr[j++];
    }
    while(i<=mid)b[k++] = arr[i++];
    while(j<=r)b[k++] = arr[j++];
    for(int i = l;i<=r;i++)arr[i] = b[i];
}
void intnt_(array_ &a)
{
    while(1)
    {
        cout<<"请输入数组长度"<<endl;
        cin>>a.len;
        if(a.len>=100)
        {
            cout<<"太大了重新输入"<<endl;
            continue;
        }
        for(int i = 1;i<=a.len;i++)
            cin>>a.data[i];
        break;
    }
}
int main()
{
    array_ a; 
    intnt_(a);
    print(a);
    int b[10];
    mergesort(a.data,b,1,a.len);
    print(a);
}
