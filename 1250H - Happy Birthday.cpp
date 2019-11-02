#include <iostream>
#include <limits>

#define DEBUG_MODE 0

#if DEBUG_MODE
    #define print(x, y) std::cout << x << y << std::endl
    #define newline std::cout << std::endl
#else
    #define print(x, y) 
    #define newline
#endif

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

int minimumBirthday(int candles_input[]) {
    long long i = 1ll;
    while (i < LONG_MAX and i > 0) {
        long long age = i;
        int r;
        int candles[10];

        for (int i = 0; i < 10; i++) 
            candles[i] = candles_input[i];
            
        newline;

        while (age > 0) {
            r = age % 10;
            age /= 10;
            print(r, ", ");

            if (candles[r] >= 1) 
                candles[r]--;
            else
                return i;
        }

        newline;

        i++;
    }
}