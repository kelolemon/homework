from typing import List
from collections import Counter


class Solution:
    def findSubstring(self, s: str, words: List[str]) -> List[int]:
        if len(s) == 0 or len(words) == 0:
            return []
        single = len(words[0])
        tot = single * len(words)
        cnt = Counter(words)
        left = 0
        ans = []
        while left + tot <= len(s):
            split_word = []
            for i in range(0, len(words)):
                split_word.append(s[left + single * i:left + single * (i + 1)])
            print(split_word)
            if Counter(split_word) == cnt:
                ans.append(left)
            left = left + 1
        return ans


if __name__ == '__main__':
    l1 = "wordgoodgoodgoodbestword"
    l2 = ["word", "good", "best", "good"]
    a = Solution()
    print(a.findSubstring(l1, l2))
