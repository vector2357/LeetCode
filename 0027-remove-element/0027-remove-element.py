class Solution:
    def removeElement(self, nums: List[int], val: int) -> int:
        ans = []
        for num in nums:
            if num != val:
                ans.append(num)
        n = len(ans)
        for i in range(n):
            nums[i] = ans[i]

        return n