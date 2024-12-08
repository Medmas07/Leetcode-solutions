class Solution(object):
    def minimumSize(self, nums, maxOperations):
        """
        :type nums: List[int]
        :type maxOperations: int
        :rtype: int
        """
        def is_possible(maxi,maxOper):
            s=0
            for num in nums:
                s+=(num-1)/maxi
                if(s>maxOper):
                    return False
            return True
        
        
        left=1
        right=max(nums)
        while(left<right):
            mid=(left+right)//2
            if(is_possible(mid,maxOperations)):
                right=mid
            else:
                left=mid+1
        return left
        
                
        