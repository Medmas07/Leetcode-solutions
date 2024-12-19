class Solution(object):
    def maxChunksToSorted(self, arr):
        """
        :type arr: List[int]
        :rtype: int
        """
        sorted_arr=sorted(arr)
        l=len(arr)
        i=0
        c=0
        while(i<l):
            j=i+1
            tmp=arr[i:j]
            tmp=sorted(tmp)
            while(j<l and tmp!=sorted_arr[i:j]):
                j+=1
                tmp=arr[i:j]
                tmp=sorted(tmp)
            
            i=j
            c+=1
        return c