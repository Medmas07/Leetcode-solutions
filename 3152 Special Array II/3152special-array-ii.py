class Solution(object):
    def isArraySpecial(self, nums, queries):
        """
        :type nums: List[int]
        :type queries: List[List[int]]
        :rtype: List[bool]
        """
        # def isArraySpecial1(nums):
        #     """
        #     :type nums: List[int]
        #     :rtype: bool
        #     """
        #     i=0
        #     while(i<len(nums)-1 and (nums[i]%2)!=(nums[i+1]%2)):
        #         i+=1
        #     return i==len(nums)-1
        # l=[]
        # v=len(queries)
        # for i in range(v):
        #     l.append(isArraySpecial1(nums[queries[i][0]:queries[i][1]+1]))
        # return l
        q=len(queries)
        ans=[False]*q
        prefix=[0]*len(nums)
        prefix[0]=0
        for i in range(1,len(nums)):
            if(nums[i]%2==nums[i-1]%2):
                prefix[i]=prefix[i-1]+1
            else:
                prefix[i]=prefix[i-1]
        for j in range(q):
            ans[j]=(((prefix[queries[j][1]])-(prefix[queries[j][0]]))==0)
        return ans
        