

def minus(x, y, step, origin_y) -> int:
    ans = 0
    if x == 0:
        return 0
    while x - y >= 0:
        x = x - y
        ans = ans + pow(2, step)
    if y == origin_y:
        return ans
    return minus(x, y >> 1, step - 1, origin_y) + ans


class Solution:
    def divide(self, dividend: int, divisor: int) -> int:
        flag = 0
        if dividend < 0:
            dividend = - dividend
            flag = flag ^ 1
        if divisor < 0:
            divisor = - divisor
            flag = flag ^ 1
        ans = minus(dividend, divisor << 32, 32, divisor)
        ans = ans if flag == 0 else -ans
        ans = ans if ans < 2147483647 else 2147483647
        return ans


if __name__ == '__main__':
    a = 182441231
    b = 56
    c = Solution()
    print(Solution.divide(c, a, b))
