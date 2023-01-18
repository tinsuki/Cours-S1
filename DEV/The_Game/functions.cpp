#include "functions.h"

int randomIntBetween(int min, int max){
    // generat a random interger between min and max
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
    // if there is no element, set to first element
    if (aList->size == 0){
        aList->first = anElement;
    }
    // set to first element if have to
    else if (aList->first->value > anElement->value){
        anElement->next = aList->first;
        aList->first = anElement;
    }
    // insert before the element superior or equal or at end of the list
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
    // increase the list size
    aList->size++;
}

void displayList(const List * aList){
    // travel the list and display the values of elements
    Element *current = aList->first;
    for (int i = 0; i < aList->size; i++){
        std::cout << current->value << "  ";
        current = current->next;
    }
    std::cout << std::endl;
}

void deleteList(List * aList){
    // delete all elements from a list by travelling and deleting element by element from begin to end
    Element *current = aList->first;
    Element *toDel;
    while (current != nullptr){
        toDel = current;
        current = current->next;
        delete toDel;
    }
}

int min(const int aNb1, const int aNb2){
    // compare to element and return the minimum
    return (aNb2 < aNb1)? aNb2:aNb1;
}

void putACard(List * aList, const int aCard){
    // put a card on top of a list by creating an element and adding the card value to the element
    // then pushing the element with the 'push' function
    Element *card = new Element;
    if (card == nullptr){
        exit(EXIT_FAILURE);
    }
    card->value = aCard;
    push(aList, card);
}


bool moveDown(List * aList, const int aCard){
    // push the card on the list if inferior, or superior by 10
    int topList = top(aList);
    if (topList == 0) {
        putACard(aList, aCard);
        return true;
    }
    if (topList > aCard || aCard-topList==10){
        putACard(aList, aCard);
        return true;
    }
    return false;
}

bool moveUp(List * aList, const int aCard){
    // push the card on the list if superior, or inferior by 10
    int topList = top(aList);
    if (topList == 0) {
        putACard(aList, aCard);
        return true;
    }
    if (topList <= aCard || aCard-topList==-10){
        putACard(aList, aCard);
        return true;
    }
    return false;
}

bool isValid(const List *aHand, const int aValue){
    // travel the hand and compare the element with the value given
    Element *current = aHand->first;
    while (current != nullptr){
        if (current->value == aValue){
            return true;
        }
        current = current->next;
    }
    // if not found return false
    return false;
}

bool isValidStack(const char aStack){
    // return if aSatck is in {'A', 'B', 'C', 'D', 'a', 'b', 'c', 'd'}
    return (aStack >= 'A' && aStack <= 'D') || (aStack >= 'a' && aStack <= 'd');
}

void play(int &aCard, char &aStack){
    // ask player for playing (a card value and a fundation)
    // verifying the entred values

    // ask for the card value and verify if value id between 2 and 99 included
    std::cout << "Which of your cards do you want to play  (" << MINCARDVALUE << " -> " << MAXCARDVALUE << ") (in your hand) ? : ";
    while (!(std::cin >> aCard) || aCard < MINCARDVALUE || aCard > MAXCARDVALUE){
        std::cout << "Input Error, Valid input :" << MINCARDVALUE << " -> " << MAXCARDVALUE << std::endl << "Which of your cards do you want to play (2 -> 98) ? : ";
        std::cin.clear();
        std::cin.ignore();
    }
    // ask player for fundation an verify if {'A', 'B', 'C', 'D', 'a', 'b', 'c', 'd'}
    std::cout << "On which fundation do you want to put the card (A, B, C ou D) ?  : ";
    while (!(std::cin >> aStack) || !isValidStack(aStack)){
        std::cout << "Input Error, accepted input are : A | B | C | D" << std::endl << "On which fundation do you want to put the card (A, B, C ou D) ?  : ";
        std::cin.clear();
        std::cin.ignore();
    }
}

int score(const List *aHand, const List *aStock){
    // travel the hand and the stack and do the sum of all element
    int score = 0;

    // travel the hand
    Element *current = aHand->first;
    while (current!=nullptr){
        score += current->value;
        current = current->next;
    }

    // travel the stock
    current = aStock->first;
    while (current!=nullptr){
        score += current->value;
        current = current->next;
    }
    return score;
}

int trueScore(const List *aHand, const List *aStock){
    // return the number of card left
    return aHand->size + aStock->size;
}

void remove(List *aList, int aValue){
    if (aList->size != 0){
        // verify the list size

        if (aList->first->value == aValue){
            // if first element, set the second to first, delete the first and decrease the size of the list
            Element *toDel = aList->first;
            aList->first = aList->first->next;
            aList->size--;
            delete toDel;
        }
        else {
            // travel the list to find the element
            Element *current = aList->first;
            Element *previous = aList->first;
            while (current!=nullptr and current->value!=aValue){
                previous = current;
                current = current->next;
            }
            // if found remove from the list, delete it and ddecrease the size of the list
            if (current != nullptr){
                previous->next = current->next;
                delete current;
                aList->size--;
            }

        }
    }
}

void initialiseList(List *aList, const int minValue, const int maxValue){
    // push element by element by seting value from max to min
    for (int i = maxValue; i > minValue-1; i--){
        Element *toPush = new Element;
        if (toPush == nullptr){
            exit(EXIT_FAILURE);
        }
        toPush->value = i;
        push(aList, toPush);
    }
}

void sendToBegin(List *aList, int index){
    // travel the grid to found the index and set the element to first
    if (index > 0 and index < aList->size){
        Element *current = aList->first;
        Element *previous = aList->first;
        int i = 0;
        while (i!=index){
            previous = current;
            current = current->next;
            i++;
        }
        previous->next = current->next; // remove element from the list
        current->next = aList->first; // set first element to next
        aList->first = current; // set element to first
    }
}

void shuffle(List * aList){
    // initialise the grid
    deleteList(aList);
    initialiseList(aList, MINCARDVALUE, MAXCARDVALUE);
    // generate random integer for index and send the element of index to begin of the list
    for (int i = 0; i < aList->size/2; i++){
        int ind = randomIntBetween(0, aList->size);
        sendToBegin(aList, ind);
    }
}

void shuffle2(List * aList){
    deleteList(aList);
    initialiseList(aList, MINCARDVALUE, MAXCARDVALUE);
    int i = 0;
    while (i < aList->size){
        int ind = randomIntBetween(0, aList->size);
        sendToBegin(aList, ind);
        i++;
    }
}

void tryShuffleDiffSize(){
    int nbDif1 = 0;
    int nbDif2 = 0;
    for (int i = 0; i < 10000; i++){
        List *listA = new List;
        if (listA == nullptr){
            exit(EXIT_FAILURE);
        }
        List *listB = new List;
        if (listB == nullptr){
            exit(EXIT_FAILURE);
        }
        List *listA2 = new List;
        if (listA2 == nullptr){
            exit(EXIT_FAILURE);
        }
        List *listB2 = new List;
        if (listB2 == nullptr){
            exit(EXIT_FAILURE);
        }

        // shuffle with size iterations
        shuffle2(listA);
        initialiseList(listB, MINCARDVALUE, MAXCARDVALUE); // sorted list
        // travel lists to count differences
        Element *currentA = listA->first;
        Element *currentB = listB->first;
        for (int i = 0; i < listA->size; i++){
            if (currentA->value != currentB->value){
                nbDif1++;
            }
            currentA = currentA->next;
            currentB = currentB->next;
        }

        // shuffle with size/2 iteration
        shuffle(listA2);
        initialiseList(listB2, MINCARDVALUE, MAXCARDVALUE); // sorted list
        // travel lists to count differences
        Element *currentA2 = listA2->first;
        Element *currentB2 = listB2->first;
        for (int i = 0; i < listA->size; i++){
            if (currentA2->value != currentB2->value){
                nbDif2++;
            }
            currentA2 = currentA2->next;
            currentB2 = currentB2->next;
        }

        // empty the memory
        deleteList(listA);
        deleteList(listA2);
        deleteList(listB);
        deleteList(listB2);
        delete listA;
        delete listA2;
        delete listB;
        delete listB2;
    }
    std::cout << "Shuffle 1 (size) diff : " << nbDif1/10000 << std::endl;
    std::cout << "Shuffle 2 (size/2) diff : " << nbDif2/10000 << std::endl;



}
