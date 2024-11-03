class Solution {
public:
    bool rotateString(string s, string goal) {
        string g=s+s;
        if(s.length()!=goal.length())
            return 0;
        else if(g.find(goal)!=-1)
            return 1;
        else
            return 0;
    }
};