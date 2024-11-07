class Solution:
    def canJump(self, nums: List[int]) -> bool:
        lastOne=0
        for i in range(len(nums)):
            if i>lastOne :
                return False
            lastOne=max(lastOne,i+nums[i])
        return True