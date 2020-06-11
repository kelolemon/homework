//
// Created by kelo on 2020/5/27.
//

# include <iostream>
# include <cstring>
# include <cstdio>
# include <cmath>

class String_Integer {
private:
    char *s;
public:
    String_Integer(char *str) {
        s = (char *) malloc(10 * strlen(str) * sizeof(char ));
        strcpy(this->s, str);
    }
    int operate() {
        int f(10);
        int x(0);
        for (int i = 0; i < strlen(s); i++) {
            if (s[i] >= '0' && s[i] <= '9') {
                x = x * f + s[i] - '0';
            }
        }
        return x;
    }

    void show() {
        std::cout << this->operate() << std::endl;
    }
    ~String_Integer() {
        free(s);
    }
};

int main() {
    char s[100];
    std::cout << "Please input s:";
    std::cin.getline(s, 100);
    String_Integer test(s);
    test.show();
}