class Solution:
    def processStr(self, s: str) -> str:
        result = ''

        for c in s:
            if c == '#':
                result = 2*result
            elif c == '*':
                result = result[:-1]
            elif c == '%':
                result = result[::-1]
            else:
                result = result+c
        
        return result