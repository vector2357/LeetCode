class Solution:
    def isPossibleToSplit(self, nums: List[int]) -> bool:
        dic = Counter(nums)

        for num in dic.values():
            if num>2:
                return False
        return True