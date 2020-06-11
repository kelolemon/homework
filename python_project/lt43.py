class Solution:
    def multiply(self, num1: str, num2: str) -> str:
        ans = [0] * 15000
        local = 0
        for i in range(0, len(num1)):
            local = i
            for j in range(0, len(num2)):
                ans[local] += int(num1[len(num1) - i - 1]) * int(num2[len(num2) - j - 1])
                local = local + 1
        for i in range(0, local):
            if ans[local - 1] >= 10:
                local = local + 1
            ans[i + 1] += int(ans[i] / 10)
            ans[i] %=10
        final_ans = ""
        while True:
            if local == 1:
                break
            if ans[local - 1] == 0:
                local = local - 1
            else:
                break
        for i in range(0, local):
            final_ans = final_ans + str(ans[local - i - 1])
        return final_ans


if __name__ == '__main__':
    a = "123"
    b = "456"
    print(Solution().multiply(a, b))
