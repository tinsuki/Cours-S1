#include <iostream>
#include "typeDef.h"
#include "functions.h"

int main()
{
    List *fundationUpA = new List;
    if (fundationUpA == nullptr){
        std::cout << "memory allocation Error" << std::endl;
        exit(EXIT_FAILURE);
    }

    List *fundationUpB = new List;
    if (fundationUpB == nullptr){
        std::cout << "memory allocation Error" << std::endl;
        exit(EXIT_FAILURE);
    }

    List *fundationDownA = new List;
    if (fundationDownA == nullptr){
        std::cout << "memory allocation Error" << std::endl;
        exit(EXIT_FAILURE);
    }

    List *fundationDownB = new List;
    if (fundationDownB == nullptr){
        std::cout << "memory allocation Error" << std::endl;
        exit(EXIT_FAILURE);
    }

    List *hand = new List;
    if (hand == nullptr){
        std::cout << "memory allocation Error" << std::endl;
        exit(EXIT_FAILURE);
    }

    for (int i=0; i < 5; i++){
        Element *toAdd = new Element;
        if (toAdd == nullptr){
            std::cout << "memory allocation Error" << std::endl;
            exit(EXIT_FAILURE);
        }
        toAdd->value = i+2;
        push(hand, toAdd);
    }

    displayBoard(fundationUpA, fundationUpB, fundationDownA, fundationDownB, hand);

    delete fundationUpA;
    delete fundationUpB;
    delete fundationDownA;
    delete fundationDownB;
    delete hand;
    return 0;
}
