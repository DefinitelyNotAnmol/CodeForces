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
    int number;
    int quantity;
    int decimalPlace;
    NumberCandle *next;
};

NumberCandle* makeCandleList() {
    NumberCandle *ptr = new NumberCandle;
    ptr->number = 0;
    NumberCandle *head = ptr;
    for (int i = 0; i < 10; i++) {
        ptr->next = new NumberCandle();
        ptr->next->number = i+1;
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
    long long j = 1;
    NumberCandle *places[21];
    for (int i = 1; i < 20; i++) {
        long long limit = std::pow(10, i);
        places[i] = new NumberCandle();
        places[i]->next = head->next;
        places[i]->decimalPlace = i;
        if (places[i]->next->quantity > 0) {
            places[i]->quantity = 1;
            places[i]->next->quantity--;
        } else {
            return j;
        }

        for (; j < limit; j++) {
            for (int k = 1; k < 20; k++) {
                if (places[k]->number == 9) {
                    places[k]->next->quantity++;
                    places[k]->next = head->next;
                    places[k]->next->quantity--;
                    continue;
                } else {
                    places[k]->next->quantity++;
                    places[k]->next = places[k]->next->next;
                    if (places[k]->next->quantity > 0)
                        places[k]->next->quantity--;
                    else
                        return 
                }
            }
        }
    }
}