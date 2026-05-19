//最小覆盖字串 滑动窗口问题
class Solution {
public:
    string minWindow(string s, string t) {
        const int INF = 1e9;
        unordered_map<char,int>n,w;
        for(char c : t){
            n[c]++;
        }
        int len = INF,start;
        int v = 0;
        int l = 0,r = 0;
        while(r < s.size())
        {
            char c = s[r];
            r++;
            if(n.count(c))
            {
                w[c]++;
                if(w[c] == n[c])
                    v++;
            }
            while(v == n.size())
            {
                c = s[l];
                int now = r - l;
                if(now < len)
                {
                    len = now;
                    start = l;
                }
                if(n.count(c))
                {
                    if(w[c] == n[c])
                        v--;
                    w[c]--;
                }
                l++;
            }
        }
        return len == INF ? "" : s.substr(start,len);
    }
};