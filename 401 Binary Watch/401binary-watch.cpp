class Solution {
public:
    vector<string> readBinaryWatch(int turnedOn) {
        vector<string> ans;
        if(turnedOn>=9){
            return ans;
        }
        int turnedOn_possible_hours=3;
        int turnedOn_possible_minutes=5;
        int n=turnedOn;
        vector<string> minutes;
        for(int i=0;i<=turnedOn;i++){
            if(i>3 || n-i>5){
                continue;
            }
            vector<string> hours;
            for(int j=0;j<=11;j++){
                int m=j;
                int w=0;
                while(m){
                    if(m & 1) w++;
                    m=m>>1;
                }
                if(w==i){
                    string hour= to_string(j);
                    hours.push_back(hour);
                }

            }
            for(int j=0;j<=59;j++){
                int m=j;
                int w=0;
                while(m){
                    if(m & 1) w++;
                    m=m>>1;
                }
                if(w==n-i){
                    string minute= to_string(j);
                    if(0<=j && j<=9) minute="0"+minute;
                    string tmp;
                    for(int k=0;k<hours.size();k++){
                        tmp=hours[k]+":"+minute;
                        ans.push_back(tmp);
                    }
                    
                }
            }
        }
       /* for (string num : hours) {
        std::cout << num << " ";
    }

    std::cout << std::endl;
    for (string num : minutes) {
        std::cout << num << " ";
    }

    std::cout << std::endl;
        for(int i=0;i<hours.size();i++){
            for(int j=0;j<minutes.size();j++){
                string result=hours[i]+":"+minutes[j];
                ans.push_back(result);
            }
        }*/
        return ans;
    }
};