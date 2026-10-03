# Last updated: 03/10/2026, 23:45:08
class Solution:
    def sumDecoded(self, nums: list[int]) -> int:
        MOD = 10**9 + 7

        total = 0
        for num in nums:
            width = num % 10
            d = num // 10
            d_str = str(d)
    
            x = int(d_str[:width])
            y = int(d_str[width:])
    
            decoded = pow(x, y, MOD)
            total = (total + decoded) % MOD
    
        return total
