class Solution {

    /**
     * @param Integer $n
     * @return Integer
     */
    /*function isPrime($n){
        for($i=2;$i<sqrt($n),$i++){
            if($n%$i==0){
                return false;
            }
        }
        return true;
    }*/
    function Power($x,$y,$mod){
        $res=1;
        $x=$x%$mod;
        while($y){
            if($y & 1){
                $res=($res*$x)%$mod;
            }
            $x=($x*$x)%$mod;
            $y=$y>>1;
        }
        return $res;
        
    }
    function countGoodNumbers($n) {
        $even_pos=(int)(($n+1)/2);
        $odd_pos=(int)($n/2);
        $mod=1000000007;
        return (($this->Power(5,$even_pos,$mod))*($this->Power(4,$odd_pos,$mod)))%$mod;
    }
}