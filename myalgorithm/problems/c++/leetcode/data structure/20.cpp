//栈，有效括号，用哈希表和栈
class Solution {
public:
    bool isValid(string s) {
        stack<char>q;
        if(s.size()==1)
            return false;
        unordered_map<char,char>hash = {{')','('},{']','['},{'}','{'}};
        for(int i = 0;i<s.size();i++)
        {
            if(hash.count(s[i])){
                if(q.empty()||q.top()!=hash[s[i]])
                    return false;
                q.pop();
            }
            else
                q.push(s[i]);
        }
        if(!q.empty())
            return false;
        return true;
    }
};