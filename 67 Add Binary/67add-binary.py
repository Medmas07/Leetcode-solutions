class Solution(object):
    def addBinary(self, a, b):
        """
        :type a: str
        :type b: str
        :rtype: str
        """
        
        # resulta=0
        # for i in range(len(a)):
        #     if(a[i]=='1'):
        #         resulta +=(1<<(len(a)-1-i))
        # resultb=0
        # for i in range(len(b)):
        #     if(b[i]=='1'):
        #         resulta +=(1<<(len(b)-1-i))
        # resulta+=resultb
        # print(resulta)
        # s=""
        # v=max(len(a),len(b))+1
        # for i in range(v):
        #     if((resulta>>v-1-i)&1):
        #         s+="1"
        #     else :
        #         s+="0"
        # if(s[0]=='0'):
        #     return s[1:]
        # return s
        return bin(int(a, 2) + int(b, 2))[2:]
        