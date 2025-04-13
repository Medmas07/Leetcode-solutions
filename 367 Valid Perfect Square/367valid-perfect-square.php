class Solution {

    /**
     * @param Integer $num
     * @return Boolean
     */
    function isPerfectSquare($num) {
       if($num <= 1){
        return true;
        }
        $left=1;
        $right=$num;
        while($left<=$right){
            $mid=(int)($left+((-$left+$right)/2));
            $square=$mid**2;
            if($square==$num){
                return true;
            }
            else if($square<$num){
                $left=$mid+1;
            }
            else{
                $right=$mid-1;
            }
        }
        return false;
    }
}