class Solution {
    public int minChanges(String s) {
        int l=s.length();
        int nb_change=0;
        for(int i=1;i<l;i+=2)
            if(s.charAt(i-1)!=s.charAt(i))
                nb_change+=1;
        return nb_change;
    }
}