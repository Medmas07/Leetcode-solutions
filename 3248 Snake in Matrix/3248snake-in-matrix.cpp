class Solution {
public:
    int finalPositionOfSnake(int n, vector<string>& commands) {
        int x=0;
        int y=0;
        for(int i=0;i<commands.size();i++){
            if(commands[i]=="DOWN"){
                y++;
            }
            else if(commands[i]=="UP"){
                y--;
            }
            else if(commands[i]=="RIGHT"){
                x++;
            }
            else{
                x--;
            }
        }
        return (y*n)+x;

    }
};