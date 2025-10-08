class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int nb_five_bills=0;
        int nb_ten_bills=0;
        int nb_twen_bills=0;
        for(int i=0;i<bills.size();i++){
            if(bills[i]==5){
                nb_five_bills++;
            }else if(bills[i]==10){
                nb_ten_bills++;
                if(nb_five_bills >0){
                    nb_five_bills--;
                }
                else{
                    return false;
                }
                
            }else{
                nb_twen_bills++;
                if(nb_ten_bills>0 && nb_five_bills>0){
                    nb_ten_bills--;
                    nb_five_bills--;
                }
                else if(nb_five_bills>0){
                    int i=0;
                    while(i<3 && nb_five_bills>0){
                        i++;
                        nb_five_bills--;
                    }
                    if(i<3){
                        return false ;
                    }
                }
                else{
                    return false;
                }
            }
        }
        return true;
    }
};