#include <iostream>
#include <limits>
#include <vector>
#include <cmath>

#define DEBUG_MODE 0

#if DEBUG_MODE
    #define print(x, y) std::cout << x << y << std::endl
    #define newline std::cout << std::endl
#else
    #define print(x, y) 
    #define newline
#endif

struct NumberCandle {
    int quantity;
    int decimalPlace;
    NumberCandle *next;
};

NumberCandle* makeCandleList() {
    NumberCandle *ptr = new NumberCandle;
    NumberCandle *head = ptr;
    for (int i = 0; i < 10; i++) {
        ptr->next = new NumberCandle();
        ptr = ptr->next;
    }

    return head;
}

long long minimumBirthday(NumberCandle *head);

int main() {
    int testCases;  std::cin >> testCases;

    NumberCandle *head = makeCandleList();

    for (int i = 0; i < testCases; ++i) {
        NumberCandle *ptr = head;
        for (int j = 0; j < 10; ptr = ptr->next, ++j) {
            std::cin >> ptr->quantity;
        }

        std::cout << minimumBirthday(head) << "\n";
    }
}

long long minimumBirthday(NumberCandle *head) {
    long long j = 0;
    for (int i = 1; i < 20; i++) {
        long long limit = std::pow(10, i);
        
        for (; j < limit; j++) {

        }
    }
}