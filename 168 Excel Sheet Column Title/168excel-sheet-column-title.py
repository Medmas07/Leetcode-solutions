class Solution(object):
    def convertToTitle(self, columnNumber):
        """
        :type columnNumber: int
        :rtype: str
        """
        ch=""
        s=columnNumber
        while(s>0):
            s-=1
            ch=chr(ord('A')+s%26)+ch
            s=s//26
       
        return ch
        