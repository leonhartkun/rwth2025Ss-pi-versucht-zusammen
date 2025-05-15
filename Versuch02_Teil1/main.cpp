#include <iostream>

int Fibonacci(int num) {
    int first = 0;
    int second = 1;
    int tmp = 0;
    for (int i = 0; i < num; i++) {
        tmp = first + second;
        first = second;
        second = tmp;
    }
    return first;
}
long long fibo(long long num) {
    if (num == 0) {
        return 0;
    }
    if (num == 1) {
        return 1;
    }
    return fibo(num - 1) + fibo(num - 2);
}

int main() {
    for (int i = 0; i <= 25; i++) {
        std::cout << "Die " << i << ". Fibonacci-Zahl ist:" << Fibonacci(i) << std::endl;
    }
    for (int i = 0; i <= 47; i++) {
        std::cout << "Die " << i << ". Fibonacci-Zahl ist:" << fibo(i) << std::endl;
    }

}
