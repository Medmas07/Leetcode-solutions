class Solution {
public:
    int countCollisions(string directions) {
        stack<char> s1;
        stack<char> s2;
        for(int i=directions.size()-1 ; i>=0 ;i--){
            s1.push(directions[i]);
        }
        s2.push(s1.top());
        s1.pop();
        int res=0;
        while(!s1.empty()){
            char c1=s1.top(),c2=s2.top();
            if(c2=='R' && c1=='L'){
                res+=2;
                s1.pop();
                s2.pop();
                
                //s1.push('S');
                while(!s2.empty() && (s2.top()=='R')){
                    res++;
                    s2.pop();
                }
                s2.push('S');
            }else if((c2=='R' && c1=='S') ){
                //res++;
                
                while(!s2.empty() && (s2.top()=='R')){
                    res++;
                    s2.pop();
                }
                s2.push(c1);
                s1.pop();
            }else if(c2=='S' && c1=='L'){
                res++;
                s1.pop();
            }else{
                s2.push(s1.top());
                s1.pop();
            }
        }
        return res;
    }
};