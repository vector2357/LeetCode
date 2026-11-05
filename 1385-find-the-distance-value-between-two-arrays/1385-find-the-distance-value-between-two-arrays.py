class Solution:
    def findTheDistanceValue(self, arr1: list[int], arr2: list[int], d: int) -> int:
        ans = 0

        for x in arr1:
            flag = True
            for y in arr2:
                if abs(x-y) <= d:
                    flag = False
                    break
            if flag:
                ans += 1

        return ans