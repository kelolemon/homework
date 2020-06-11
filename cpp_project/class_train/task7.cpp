//
// Created by kelo on 2020/5/27.
//
# include <iostream>
# include <cstring>
# include <cstdio>
# include <cmath>

class Integer_String {
private:
    int num;
    char *s;
public:
    Integer_String(int n) {
        this->num = n;
        this->s = NULL;
    }
    int f() {
        int t = 0;
        int x = this->num;
        while (x) {
            x /= 10;
            t++;
        }
        return t;
    }
    void fun() {
        int t = this->f();
        s = (char *) malloc(2 * t * sizeof(char));
        sprintf(this->s, "%d", num);
    }
    void show() {
        std::cout << this->s << " " << this->num << std::endl;
    }
    ~Integer_String() {
        free(s);
    }
};

int main() {
    Integer_String test(12345);
    test.fun();
    test.show();
}