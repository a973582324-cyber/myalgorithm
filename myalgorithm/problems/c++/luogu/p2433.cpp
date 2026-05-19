#include<bits/stdc++.h>
using namespace std;
int main() {
    int T;
    cin >> T;
    if (T == 1) {
        cout << "I love Luogu!";
    } else if (T == 2) {
        cout << 2 + 4 << " " << 10 - 2 - 4;
    } else if (T == 3) {
        cout<<14/4<<endl;
        cout<<14/4*4<<endl;
        cout<<14-14/4*4<<endl;
    } else if (T == 4) {
        double a = 500.0;
        double ans = a/3;
        printf("%.3lf",ans);
    } else if (T == 5) {
        cout<<480/32<<endl;
    } else if (T == 6) {
        cout<<sqrt(117)<<endl;
    } else if (T == 7) {
        cout<<110<<endl;
        cout<<90<<endl;
        cout<<0<<endl;
    } else if (T == 8) {
        double pi = 3.141593;
        cout<<31.41593<<endl;
        double r = 5.0;
        cout<<pi*r*r<<endl;
        cout<<4.0/3*r*r*r*pi<<endl;
    } else if (T == 9) {
        int x = 1;
        for(int i = 0;i<3;i++)
        {
            x = (x + 1) * 2; 
        }
        cout<<x<<endl;
    } else if (T == 10) {
        cout<<9<<endl;
    } else if (T == 11) {
        cout<<(double)100/3<<endl;
    } else if (T == 12) {
        cout<<(int)('M'-'A')+1<<endl;
        cout<<char('A'+17)<<endl;
    } else if (T == 13) {
        double pi = 3.141593;
        double s1 = 4.0/3*pi*4*4*4;
        double s2 = 4.0/3*pi*10*10*10;
        double s = s1+s2;
        double v = pow(s,1.0/3);
        printf("%.0lf",v);
    } else if (T == 14) {
        cout<<50<<endl;
    }
    return 0;
}