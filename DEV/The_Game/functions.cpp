#include "functions.h"

int randomIntBetween(int min, int max){
    std::random_device rd;
    std::default_random_engine eng(rd());
    std::uniform_int_distribution<int> distr(min, max);
    return distr(eng);
}

void push(List* aList, Element* anElement){
    anElement->next = aList->first;
    aList->first = anElement;
    aList->size++;
}

int top(const List * aList){
    return (aList->size == 0)? 0: aList->first->value; // if list size = 0 return zero, else return the value of first element
}

void pop(List * aList){
    if (aList->size > 0){
        Element *toDel = aList->first; // get the first element adress
        aList->first = toDel->next; // remove it from the list
        aList->size--; // decrease the list size
        delete toDel;
    }
}

void insert(List * aList, Element * anElement){
    if (aList->size == 0){
        aList->first = anElement;
    }
    else if (aList->first->value > anElement->value){
        anElement->next = aList->first;
        aList->first = anElement;
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
    push(aList, card);
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
    centerDisplay("A: 2 -> 99    B: 2 -> 99    C: 99 -> 2    D: 99 -> 2");
    std::cout << std::endl;
    std::string todisplay = "";
    for (int i=0; i < 5; i++){
        todisplay += " ";
    }
    if (topUpA > 9){
        todisplay += std::to_string(topUpA);
    }
    else {
        todisplay += std::to_string(topUpA) + " ";
    }
    for (int i=0; i < 12; i++){
        todisplay += " ";
    }
    if (topUpB > 9){
        todisplay += std::to_string(topUpB);
    }
    else {
        todisplay += std::to_string(topUpB) + " ";
    }
    for (int i=0; i < 12; i++){
        todisplay += " ";
    }
    if (topDownA > 9){
        todisplay += std::to_string(topDownA);
    }
    else {
        todisplay += std::to_string(topDownA) + " ";
    }
    for (int i=0; i < 12; i++){
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
    for (int i = 0; i < (80-30)/2; i++){
        std::cout << " ";
    }
    displayList(aHand);
    std::cout << std::endl;
}

bool moveUp(List * aList, const int aCard){
    int topList = top(aList);
    if (topList < aCard || topList-aCard==10){
        Element *card = new Element;
        if (card == nullptr){
            exit(EXIT_FAILURE);
        }
        card->value = aCard;
        push(aList, card);
        return true;
    }
    return false;
}

bool moveDown(List * aList, const int aCard){
    int topList = top(aList);
    if (topList == 0) {
        Element *card = new Element;
        if (card == nullptr){
            exit(EXIT_FAILURE);
        }
        card->value = aCard;
        push(aList, card);
        return true;
    }
    if (topList > aCard || aCard-topList==10){
        Element *card = new Element;
        if (card == nullptr){
            exit(EXIT_FAILURE);
        }
        card->value = aCard;
        push(aList, card);
        return true;
    }
    return false;
}

bool isValid(const List *aHand, const int aValue){
    Element *current = aHand->first;
    while (current != nullptr){
        if (current->value == aValue){
            return true;
        }
        current = current->next;
    }
    return false;
}

bool isValidStack(const char aStack){
    return (aStack >= 'A' && aStack <= 'D') || (aStack >= 'a' && aStack <= 'd');
}

void play(int &aCard, char &aStack){
    std::cout << "Quelle carte de votre main voullez-vous jouer (2 -> 98) ? :    ";
    while (!(std::cin >> aCard) || aCard < MINCARDVALUE || aCard > MAXCARDVALUE){
        std::cout << "Erreur" << std::endl << "Quelle carte de votre main voullez-vous jouer (2 -> 98) ? : ";
        std::cin.clear();
        std::cin.ignore();
    }
    std::cout << "Sur quelle base voullez-vous poser la carte (A, B, C ou D) ?  :    ";
    while (!(std::cin >> aStack) || !isValidStack(aStack)){
        std::cout << "Erreur" << std::endl << "Sur quelle base voullez-vous poser la carte (A, B, C ou D) ?  :    ";
        std::cin.clear();
        std::cin.ignore();
    }
}


int score(const List *aHand, const List *aStock){
    int score = 0;
    Element *current = aHand->first;
    while (current!=nullptr){
        score += current->value;
        current = current->next;
    }
    current = aStock->first;
    while (current!=nullptr){
        score += current->value;
        current = current->next;
    }
    return score;
}

int trueScore(const List *aHand, const List *aStock){
    return aHand->size + aStock->size;
}

void remove(List *aList, int aValue){
    if (aList->size != 0){
        if (aList->first->value == aValue){
            Element *toDel = aList->first;
            aList->first = aList->first->next;
            aList->size--;
            delete toDel;
        }
        else {
            Element *current = aList->first;
            Element *previous = aList->first;
            while (current!=nullptr and current->value!=aValue){
                previous = current;
                current = current->next;
            }
            if (current != nullptr){
                previous->next = current->next;
                delete current;
                aList->size--;
            }

        }
    }
}

void initialiseList(List *aList, const int minValue, const int maxValue){
    for (int i = minValue; i < maxValue+1; i++){
        Element *toPush = new Element;
        if (toPush == nullptr){
            exit(EXIT_FAILURE);
        }
        toPush->value = i;
        push(aList, toPush);
    }
}

void sendToBegin(List *aList, int index){
    if (index > 0 and index < aList->size){
        Element *current = aList->first;
        Element *previous = aList->first;
        int i = 0;
        while (i!=index){
            previous = current;
            current = current->next;
            i++;
        }
        previous->next = current->next;
        current->next = aList->first;
        aList->first = current;
    }
}

void shuffle(List * aList){
    deleteList(aList);
    initialiseList(aList, MINCARDVALUE, MAXCARDVALUE);
    int i = 0;
    while (i < aList->size){
        int ind = randomIntBetween(0, aList->size);
        sendToBegin(aList, ind);
        i++;
    }
}

bool canPlay(const List * aFundationUpA, const List * aFundationUpB, const  List * aFundationDownA, const List * aFundationDownB, const List * aHand){
    int topUpA = top(aFundationUpA);
    int topUpB = top(aFundationUpB);
    int topDownA = top(aFundationDownA);
    int topDownB = top(aFundationDownB);
    Element *current = aHand->first;
    while (current != nullptr){
        if (topUpA < current->value || topUpA-current->value==10){
            return true;
        }
        if (topUpB < current->value || topUpB-current->value==10){
            return true;
        }
        if (topDownA > current->value || current->value-topDownA==10){
            return true;
        }
        if (topDownB > current->value || current->value-topDownB==10){
            return true;
        }
    }
    return false;
}
