//
// Created by kegsbett on 4/30/23.
//
#include "cave.h"

int main() {
    s21::Cave a;
    a.GenerateCave(30, 50);
    for (int i{}; i < 5; ++i) {
        a.IterateCave();
        a.PrintCave();
        std::cout << std::endl << std::endl;
    }
    return 0;
}