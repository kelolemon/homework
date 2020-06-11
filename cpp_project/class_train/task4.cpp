//
// Created by kelo on 2020/5/22.
//

# include <cmath>
# include <cstdio>
# include <iostream>
# include <cstring>

class NUM {
private:
    int data[25];
    int num[10];
public:
    NUM(int data[]) {
        for (int i = 0; i < 25; i++) {
            this->data[i] =data[i];
        }
        memset(this->num, 0, sizeof(this->num));
    }
    void process() {
        for (int i = 0; i < 24; i++) {
            this->num[this->data[i]] ++;
        }
    }
    void print() {
        for (int i = 0; i < 10; i++) {
            printf("%d: %d ", i, num[i]);
            if ((i + 1) % 5 == 0) puts("");
        }
        puts("");
    }
};

int main() {
    int a[25];
    for (int i = 0; i < 25; i++) {
        a[i] = rand()%10;
    }
    NUM test(a);
    test.process();
    test.print();
}