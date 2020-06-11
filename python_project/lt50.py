class Solution:
    def quick(self, x: float, n: int) -> float:
        if n == 0:
            return 1
        if n == 1:
            return x
        res = 1
        if n & 1 == 1:
            res = x
        half = self.quick(x, n >> 1)
        return half * half * res

    def myPow(self, x: float, n: int) -> float:
        if n > 0:
            return self.quick(x, n)
        else:
            return self.quick(1/x, -n)


if __name__ == '__main__':
    a = 2.0
    b = 1000
    print(Solution().myPow(a, b))
