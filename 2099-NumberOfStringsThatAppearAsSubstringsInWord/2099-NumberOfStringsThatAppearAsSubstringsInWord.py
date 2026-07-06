# Last updated: 06/07/2026, 09:53:05
class Solution:
    def numOfStrings(self, patterns: List[str], word: str) -> int:

        count = 0
        for pattern in patterns:
            if pattern in word:
                count += 1

    
        return count

        