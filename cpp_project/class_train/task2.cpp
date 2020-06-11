//
// Created by kelo on 2020/5/22.
//

# include <iostream>
# include <cstring>
# include <cstdio>
# include <cmath>

class MOVE {
private:
    char *array;
    int n;

public:
    MOVE(char b[], int m) {
        array = (char *)malloc(sizeof(m + 1));
        memset(array, 0, sizeof(array));
        strcpy(array, b);
        n = m;
    }
    inline void print() {
        std::cout << array << std::endl;
    }

    inline void change() {
        char *tmp = (char *)malloc((sizeof(n + 1)));
        memset(tmp, 0, sizeof(tmp));
        int tot = 0;
        for (int i = 0; i < n; i++) {
            if (array[i] >= 'A' && array[i] <= 'Z') {
                *(tmp + tot) = array[i];
                tot = tot + 1;
            }
        }
        for (int i = 0; i < n; i++) {
            if (array[i] >= 'a' && array[i] <= 'z') {
                *(tmp + tot) = array[i];
                tot = tot + 1;
            }
        }
        strcpy(array, tmp);
        free(tmp);
    }
    ~MOVE() {
        free(array);
    }
};

int main() {
    char *s;
    strcpy(s, "fdsUFfsTjfsKFEkWC");
    MOVE test(s, strlen(s));
    test.change();
    test.print();
    return 0;
}