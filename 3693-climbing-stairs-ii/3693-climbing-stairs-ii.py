class Solution:
    def climbStairs(self, n: int, costs: List[int]) -> int:
        acumList = [-1 for i in range(n)]
        for i in range(1, min(n+1, 4)):
            acumList[i-1] = costs[i-1] + i*i
        for i in range(n-1):
            for j in range(1, 4):
                if i+j == n:
                    break
                if acumList[i+j] == -1:
                    acumList[i+j] = j*j + costs[i+j] + acumList[i]
                else:
                    acumList[i+j] = min(j*j + costs[i+j] + acumList[i], acumList[i+j])

        return acumList[n-1]