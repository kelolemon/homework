//
// Created by kelo on 2020/5/22.
//

# include <cmath>
# include <cstdio>
# include <iostream>
# include <cstring>

class NUM {
private:
    int *data;
    int span1, span2;
    int num;

public:
    NUM(int n1, int n2) {
        this->span1 = n1;
        this->span2 = n2;
        this->num = 0;
        this->data = (int *)malloc(sizeof(int) * (span2 - span1 + 1));
    }

    inline int isComposite(int x) {
        if (x == 2) return 1;
        for (int i = 2; i <= int(sqrt(x)); i++) {
            if ( x % 2 == 0) {
                return 0;
            }
        }
        return 1;
    }

    inline void process() {
        for (int i = span1; i <= span2; i++) {
            if (this->isComposite(i)) {
                *(data + num) = i;
                num++;
            }
        }
    }

    inline void print() {
        for (int i = 0; i < num; i++) {
            printf("%d ", data[i]);
            if ((i + 1) % 8 == 0) puts("");
        }
    }
    ~NUM() {
        free(data);
    }
};

using namespace std;

int main() {
    int a = 100, b = 200;
    NUM* test = new NUM(a, b);
    test->process();
    test->print();

}