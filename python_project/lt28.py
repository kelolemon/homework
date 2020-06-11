

class Solution:
    def strStr(self, haystack: str, needle: str) -> int:
        pos = haystack.find(needle, 0, len(haystack))
        return 0 if pos == -1 else pos

