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
    char data[25];
    int num[128];
public:
    NUM(char data[]) {
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
        for (int i = 32, step = 0; i < 128; i++) {
            if (num[i] == 0) continue;
            printf("%c: %d ", i, num[i]);
            if ((step + 1) % 5 == 0) puts("");
            step = step + 1;
        }
        puts("");
    }
};

int main() {
    char a[25];
    for (int i = 0; i < 25; i++) {
        a[i] = rand()%128;
        while (a[i] < 32) a[i] = rand() % 128;
    }
    NUM test(a);
    test.process();
    test.print();
}