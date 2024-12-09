class Solution(object):
    def isArraySpecial(self, nums):
        """
        :type nums: List[int]
        :rtype: bool
        """
        i=0
        while(i<len(nums)-1 and (nums[i]%2)!=(nums[i+1]%2)):
            i+=1
        return i==len(nums)-1
            
        