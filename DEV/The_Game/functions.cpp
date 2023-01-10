#include "functions.h"

void push(List* aList, Element* anElement){
    anElement->next = aList->first;
    aList->first = anElement;
    aList->size++;
}

int top(const List * aList){
    return (aList->size == 0)? 0: aList->first->value; // if list size = 0 return zero, else return the value of first element
}

void pop(List * aList){
    Element *toDel = aList->first; // get the first element adress
    aList->first = toDel->next; // remove it from the list
    delete toDel; // delete the element
    aList->size--; // decrease the list size
}

void insert(List * aList, Element * anElement){
    if (aList->size == 0){
        aList->first = anElement;
    }
    else if (aList->size == 1){
        if (aList->first->value < anElement->value){
            aList->first->next = anElement;
        }
        else {
            anElement->next = aList->first;
            aList->first = anElement;
        }
    }
    else{
        Element *current = aList->first->next;
        Element *precedent = aList->first;
        while (current != nullptr and current->value < anElement->value){
            precedent = current;
            current = current->next;
        }
        if (current == nullptr){
            precedent->next = anElement;
        }
        else {
            anElement->next = current;
            precedent->next = anElement;
        }
    }
    aList->size++;
}

void displayList(const List * aList){
    Element *current = aList->first;
    for (int i = 0; i < aList->size; i++){
        std::cout << current->value << "  ";
        current = current->next;
    }
    std::cout << std::endl;
}

void deleteList(List * aList){
    Element *current = aList->first;
    Element *toDel;
    while (current != nullptr){
        toDel = current;
        current = current->next;
        delete toDel;
    }
    aList->size = 0;
}

void remove(List * aList, const int aValue){
    if (aList->size == 1){
        if (aList->first->value == aValue){
            Element *toDel = aList->first;
            aList->first = toDel->next;
            delete toDel;
            aList->size--;
        }
    }
    else{
        Element *current = aList->first->next;
        Element *precedent = aList->first;
        while (current != nullptr and current->value != aValue){
            precedent = current;
            current = current->next;
        }
        if (current != nullptr){
            precedent->next = current->next;
            delete current;
            aList->size--;
        }
    }

}

int min(const int aNb1, const int aNb2){
    return (aNb2 < aNb1)? aNb2:aNb1;
}

void putACard(List * aList, const int aCard){
    Element *card = new Element;
    if (card == nullptr){
        exit(EXIT_FAILURE);
    }
    card->value = aCard;
    card->next = aList->first;
    aList->first = card;
}

void centerDisplay(std::string aText){
    // center the text passed in parameter
    int nbSpace = (80 - aText.length())/2;
    for (int  i = 0; i < nbSpace; i++){
        std::cout << " ";
    }
    std::cout << aText << std::endl;
}

void displayBoard(const List * aFundationUpA, const List * aFundationUpB, const  List * aFundationDownA, const List * aFundationDownB, const List * aHand){
    int topUpA = top(aFundationUpA);
    int topUpB = top(aFundationUpB);
    int topDownA = top(aFundationDownA);
    int topDownB = top(aFundationDownB);
    centerDisplay(" 2 -> 98     2 -> 98    98 -> 2     98 -> 2 ");
    std::cout << std::endl;
    std::string todisplay = "";
    for (int i=0; i < 3; i++){
        todisplay += " ";
    }
    if (topUpA > 9){
        todisplay += std::to_string(topUpA);
    }
    else {
        todisplay += std::to_string(topUpA) + " ";
    }
    for (int i=0; i < 10; i++){
        todisplay += " ";
    }
    if (topUpB > 9){
        todisplay += std::to_string(topUpB);
    }
    else {
        todisplay += std::to_string(topUpB) + " ";
    }
    for (int i=0; i < 10; i++){
        todisplay += " ";
    }
    if (topDownA > 9){
        todisplay += std::to_string(topDownA);
    }
    else {
        todisplay += std::to_string(topDownA) + " ";
    }
    for (int i=0; i < 10; i++){
        todisplay += " ";
    }
    if (topDownB > 9){
        todisplay += std::to_string(topDownB);
    }
    else {
        todisplay += std::to_string(topDownB) + " ";
    }
    centerDisplay(todisplay);
    std::cout << std::endl << std::endl;
    centerDisplay("your Hand");
    std::cout << std::endl;
    for (int i = 0; i < (80-13)/2; i++){
        std::cout << " ";
    }
    displayList(aHand);
}
