# Last updated: 03/10/2026, 23:52:02
class Solution:
    def numOfStrings(self, patterns: List[str], word: str) -> int:

        count = 0
        for pattern in patterns:
            if pattern in word:
                count += 1

    
        return count

        