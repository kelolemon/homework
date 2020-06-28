

def test():
    n = 3
    m = 4
    k = 5
    f = [None] * n
    for i in range(0, n):
        f[i] = [None] * m
        for j in range(0, m):
            f[i][j] = [0] * k
    print(f)


if __name__ == '__main__':
    test()