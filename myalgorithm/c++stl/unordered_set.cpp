#include<iostream>
#include<unordered_set>
using namespace std;
int main()
{
    unordered_set<int>a;
    a.insert(1);
    for(auto b :a )
    cout<<b<<endl;
    a.erase(1);
    cout<<a.empty();
}