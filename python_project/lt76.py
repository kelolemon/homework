from collections import Counter


class Solution:
    def minWindow(self, s: str, t: str) -> str:
        if not s:
            return ""
        need_dic = dict()
        now_dic = dict()
        left = 0
        right = 0
        match = 0
        for char in t:
            need_dic[char] = need_dic[char] + 1 if char in need_dic else 1
        if s[left] in need_dic:
            now_dic[s[left]] = 1
            if now_dic[s[left]] == need_dic[s[left]]:
                match = 1
        ans = 1 << 123
        ans_str = ""
        while right < len(s):
            if match == len(need_dic):
                if ans > right - left + 1:
                    ans = right - left + 1
                    ans_str = s[left:right + 1]
                if s[left] in need_dic:
                    now_dic[s[left]] -= 1
                    if now_dic[s[left]] < need_dic[s[left]]:
                        match = match - 1
                left = left + 1
            else:
                right = right + 1
                if right == len(s):
                    break
                if s[right] in need_dic:
                    now_dic[s[right]] = now_dic[s[right]] + 1 if s[right] in now_dic else 1
                    if now_dic[s[right]] == need_dic[s[right]]:
                        match = match + 1
        return ans_str


if __name__ == '__main__':
    s = "aa"
    t = "aa"
    print(Solution().minWindow(s, t))
