class Solution(object):
    def kidsWithCandies(self, candies, extraCandies):
        """
        :type candies: List[int]
        :type extraCandies: int
        :rtype: List[bool]
        """
        x=max(candies)
        boolarr=[False]*len(candies)
        for i in range(len(candies)):
            if(candies[i]+extraCandies >= x):
                boolarr[i]=True
        return boolarr
        