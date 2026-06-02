#include<iostream>
using namespace std;
int MAX = 100;
struct anyone
{
    string name;
    string phone;
    string address;
    string sex;
    string age;
};
bool inspectnumber(string number)
{
    if(number.length() != 11)
    {
        return false;
    }
    return true;
}
struct people
{
    int len = 0;
    anyone a[100];
};
void add(people &p)
{
    if(p.len >= MAX)
    {
        cout<<"通讯录已满，无法添加联系人"<<endl;
        return;
    }
    cout<<"请输入联系人姓名：";
    cin>>p.a[p.len].name;
    cout<<"请输入联系人电话：";
    cin>>p.a[p.len].phone;
    while(inspectnumber(p.a[p.len].phone) == false)
    {
        cout<<"电话号码必须为11位数字,请重新输入"<<endl;
        cin>>p.a[p.len].phone;
    }
    cout<<"请输入联系人地址：";
    cin>>p.a[p.len].address;
    cout<<"请输入联系人性别：";
    cin>>p.a[p.len].sex;
    cout<<"请输入联系人年龄：";
    cin>>p.a[p.len].age;
    p.len++;
}
void show(people &p)
{
    cout<<"显示联系人"<<endl;
    for(int i = 0; i < p.len; i++)
    {
        cout<<"姓名："<<p.a[i].name<<endl;
        cout<<"电话："<<p.a[i].phone<<endl;
        cout<<"地址："<<p.a[i].address<<endl;
        cout<<"性别："<<p.a[i].sex<<endl;
        cout<<"年龄："<<p.a[i].age<<endl;
        cout<<endl;
    }
}
void deletepeople(people &p)
{
    string name;
    cout<<"请输入要删除的联系人姓名：";
    cin>>name;
    for(int i = 0; i < p.len; i++)
    {
        if(p.a[i].name == name)
        {
            for(int j = i; j < p.len - 1; j++)
            {
                p.a[j] = p.a[j+1];
            }
            p.len--;
            cout<<"联系人已删除"<<endl;
            return;
        }
    }
    cout<<"未找到联系人"<<endl;
}
void print()
{
    cout<<endl;
    cout<<"***********************"<<endl;
    cout<<"** 1~添加联系人 **"<<endl;
    cout<<"** 2~显示联系人 **"<<endl;
    cout<<"** 3~删除联系人 **"<<endl;
    cout<<"** 4~查找联系人 **"<<endl;
    cout<<"** 5~修改联系人 **"<<endl;
    cout<<"** 6~清空联系人 **"<<endl;
    cout<<"** 0~退出系统   **"<<endl;
    cout<<"***********************"<<endl;
    cout<<endl;
}
void findpeople(people &p)
{
    string name;
    cout<<"请输入要查找的联系人姓名";
    cin>>name;
    for(int i = 0;i<p.len;i++)
    {
        if(p.a[i].name == name)
        {
            cout<<"姓名："<<p.a[i].name<<endl;
            cout<<"电话："<<p.a[i].phone<<endl;
            cout<<"地址："<<p.a[i].address<<endl;
            cout<<"性别："<<p.a[i].sex<<endl;
            cout<<"年龄："<<p.a[i].age<<endl;
            cout<<endl;
            return;
        }
    }
    cout<<"未找到联系人"<<endl;
}
void changepeople(people &p)
{
    string name;
    cout<<"请输入要修改的联系人姓名";
    cin>>name;
    for(int i = 0;i<p.len;i++)    
    {
        if(p.a[i].name == name)
        {
            cout<<"请输入新的联系人姓名：";
            cin>>p.a[i].name;
            cout<<"请输入新的联系人电话：";
            cin>>p.a[i].phone;
            while(inspectnumber(p.a[p.len].phone) == false)
            {
                cout<<"电话号码必须为11位数字,请重新输入"<<endl;
                cin>>p.a[p.len].phone;
            }
            cout<<"请输入新的联系人地址：";
            cin>>p.a[i].address;
            cout<<"请输入新的联系人性别：";
            cin>>p.a[i].sex;
            cout<<"请输入新的联系人年龄：";
            cin>>p.a[i].age;
            cout<<"联系人已修改"<<endl;
            return;
        }
    }
        cout<<"未找到联系人"<<endl;        
}
void deleteall(people &p)
{
    p.len = 0;
    cout<<"联系人已清空"<<endl;
}
int main()
{
    people p;
    p.len = 0;
    int select = 0;
    while(1)
    {
        print();
        cin>>select;
        switch (select)
        {
            case 1:
                add(p);
                break;
            case 2:
                show(p);
                cout<<"显示联系人"<<endl;
                break;
            case 3:
                deletepeople(p);
                cout<<"删除联系人"<<endl;
                break;
            case 4:
                findpeople(p);
                cout<<"查找联系人"<<endl;
                break;
            case 5:
                changepeople(p);
                cout<<"修改联系人"<<endl;
                break;
            case 6:
                deleteall(p);
                cout<<"清空联系人"<<endl;
                break;
            case 0:
                cout<<"退出系统"<<endl;
                system("pause");
                return 0;
                break;
            default:
                cout<<"无效选择"<<endl;
                break;
        }
    }
    return 0;    
}