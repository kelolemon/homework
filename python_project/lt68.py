from typing import List


class Solution:
    def fullJustify(self, words: List[str], maxWidth: int) -> List[str]:
        ans = []
        now = 0
        sub_str = []
        number = 0
        for string in words:
            if now + len(string) + 1 <= maxWidth:
                now = now + len(string) + 1
                sub_str.append(string)
                number = number + 1
            elif now + len(string) == maxWidth:
                sub_ans = ""
                for index in sub_str:
                    sub_ans += index + " "
                sub_ans += string
                ans.append(sub_ans)
                now = 0
                sub_str.clear()
                number = 0
            elif number != 1:
                sub_ans = ""
                number = number - 1
                space = (maxWidth - now + 1) / number
                space = int(space)
                res = (maxWidth - now + 1) % number
                for index in sub_str[:len(sub_str) - 1:]:
                    sub_ans += index + " " + " " * space
                    if res != 0:
                        sub_ans += " "
                        res -= 1
                sub_ans += sub_str[-1]
                ans.append(sub_ans)
                now = len(string) + 1
                sub_str.clear()
                sub_str.append(string)
                number = 1
            else:
                sub_ans = sub_str[0]
                sub_ans += " " * (maxWidth - len(sub_ans))
                ans.append(sub_ans)
                now = len(string) + 1
                sub_str.clear()
                sub_str.append(string)
                number = 1
        sub_ans = ""
        if sub_str:
            for string in sub_str:
                sub_ans += string + " "
            sub_ans = sub_ans[:-1]
            sub_ans += " " * (maxWidth - len(sub_ans))
            ans.append(sub_ans)
        return ans


if __name__ == '__main__':
    words = ["Science","is","what","we","understand","well","enough","to","explain",
         "to","a","computer.","Art","is","everything","else","we","do"]
    maxWidth = 20
    print(Solution().fullJustify(words, maxWidth))
