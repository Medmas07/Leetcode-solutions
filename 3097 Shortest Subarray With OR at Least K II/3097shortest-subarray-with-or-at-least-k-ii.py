def update_t(t,nombre,c):
    i=0
    for i in range(32):
        if((nombre>>i)&1):
            t[i]+=c
def convert(t):
    s=0
    for i in range(32):
        if(t[i]!=0):
            s|=(1<<i)
    return s
class Solution(object):
    def minimumSubarrayLength(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        t=[0]*32
        end=0
        start=0
        lon=len(nums)
        mini=lon+1
        for end in range(lon):
            update_t(t,nums[end],1)
            while(start<=end and k<=convert(t)):
                mini=min(mini,end-start+1)
                update_t(t,nums[start],-1)
                start+=1
        if(mini==lon+1):
            return -1
        else:
            return mini
        