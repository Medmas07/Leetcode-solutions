class Solution:
    def triangleNumber(self, nums: List[int]) -> int:
        nums.sort()  # trier les côtés
        n = len(nums)
        count = 0
        
        # on fixe le côté le plus grand 'c' à l'indice k
        for k in range(2, n):
            i, j = 0, k - 1
            while i < j:
                if nums[i] + nums[j] > nums[k]:
                    # tous les indices entre i et j sont valides avec k
                    count += j - i
                    j -= 1
                else:
                    i += 1
        return count



