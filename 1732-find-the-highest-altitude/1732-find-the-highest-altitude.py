class Solution:
    def largestAltitude(self, gain: List[int]) -> int:
        ans = 0
        cur = 0
        
        for g in gain:
            cur += g
            ans = max( cur ,ans)
            
        return ans
        