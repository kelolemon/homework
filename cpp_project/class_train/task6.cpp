//
// Created by kelo on 2020/5/27.
//

//
// Created by kelo on 2020/5/22.
//

# include <cmath>
# include <cstdio>
# include <iostream>
# include <cstring>

class NUM {
private:
    int data[10];
    int prime[10];
    int num;

public:
    NUM(int data[]) {
        for (int i = 0; i < 10; i++) {
            this->data[i] = data[i];
        }
        memset(this->prime, 0, sizeof(this->prime));
        this->num = 0;
    }

    inline int isprime(int x) {
        if (x == 2) return 1;
        for (int i = 2; i <= int(sqrt(x)); i++) {
            if ( x % i == 0) {
                return 0;
            }
        }
        return 1;
    }

    inline void process() {
        for (int i = 0; i <= 10; i++) {
            if (this->isprime(data[i])) {
                prime[num] = data[i];
                num++;
            }
        }
    }

    inline void print() {
        std::cout << num << std::endl;
        for (int i = 0; i < num; i++) {
            printf("%d ", prime[i]);
            if ((i + 1) % 4 == 0) puts("");
        }
        puts("");
    }
    ~NUM() {
        free(data);
    }
};

using namespace std;

int main() {
    int a[10] = {4, 5, 9, 11, 36, 29, 31, 101, 56, 199};
    NUM* test = new NUM(a);
    test->process();
    test->print();
}