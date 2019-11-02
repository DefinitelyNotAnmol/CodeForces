#include <iostream>
#include <limits>

int minimumBirthday(int candles[]);

int main() {
    int testCases;  std::cin >> testCases;

    for (int i = 0; i < testCases; ++i) {
        int candles[10];
        for (int j = 0; j < 10; ++j) {
            std::cin >> candles[j];
        }

        std::cout << minimumBirthday(candles) << std::endl;
    }
}

int minimumBirthday(int candles[]) {
    long long i = 1ll;
    while (i < LONG_MAX) {
        long long age = i;
        int numbers[10] = { 0 };

        int r;

        while (age > 0) {
            r = age % 10;
            age /= 10;
            numbers[r-1]++;
        }
    }
}