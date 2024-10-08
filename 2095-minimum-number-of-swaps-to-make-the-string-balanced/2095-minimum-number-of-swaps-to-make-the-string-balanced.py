class Solution:
    def minSwaps(self, s: str) -> int:
        aberto,ans = 0,0

        for c in s:
            if c == ']':
                if not aberto:
                    ans+=1
                    aberto+=1
                else:
                    aberto-=1
            else:
                aberto+=1
                
        return ans