from functools import reduce


class Solution:

    def getPermutation(self, n: int, k: int) -> str:
        ans = ""
        all = [i + 1 for i in range(0, n)]
        now = n
        left = k
        for _ in range(0, n - 1):
            fac_now = reduce(lambda x, y: x * y, range(1, now))
            index = (left - 1) / fac_now
            index = int(index)
            left = left - index * fac_now
            ans = ans + str(all[index])
            del all[index]
            now = now - 1
        return ans + str(all[0])


if __name__ == '__main__':
    n = 3
    k = 3
    print(Solution().getPermutation(n, k))
