class Solution(object):
    def compareVersion(self, version1, version2):
        """
        :type version1: str
        :type version2: str
        :rtype: int
        """
        l=version1.split('.')
        l2=version2.split('.')
        k=[int(i) for i in l]
        w=[int(i) for i in l2]
        if(len(k)<len(w)):
            n=len(k)
        else:
            n=len(w)
        for i in range(n):
            if(k[i]<w[i]):
                return -1
            elif(k[i]>w[i]):
                return 1
        
        if(len(k)<len(w)):
            for t in range (len(k),len(w),1):
                if(w[t]!=0):
                    return -1
        elif(len(k)>len(w)):
            for t in range (len(w),len(k),1):
                if(k[t]!=0):
                    return 1


        return 0
        