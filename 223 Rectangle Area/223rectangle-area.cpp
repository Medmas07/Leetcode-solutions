class Solution {
public:
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
        int area1 =(bx2-bx1)*(by2-by1);
        int area2 =(ax2-ax1)*(ay2-ay1);
        int ax3=ax2 , ay3=ay1, ax4=ax1 , ay4=ay2;
        
        int cx2=(ax2<bx2)?ax2:bx2;
        int cy2=(ay2<by2)?ay2:by2;
        int cx1=(ax1<bx1)?bx1:ax1;
        int cy1=(ay1<by1)?by1:ay1;
        if(cx2<=cx1 ||cy1>=cy2)return area1+area2;

        return area1+area2-((cy2-cy1)*(cx2-cx1));
    }
};