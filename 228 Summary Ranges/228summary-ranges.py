class Solution:
    def summaryRanges(self, nums: List[int]) -> List[str]:
        rep=[]
        i=0
        while i <= len(nums)-1:
            x=nums[i]
            while i<len(nums)-1 and nums[i+1]==nums[i]+1 :
                i=i+1
            if nums[i]!=x: 
                rep.append(str(x)+'->'+str(nums[i]))
            else:
                rep.append(str(x))
            i+=1
        return rep