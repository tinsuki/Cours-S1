#include <iostream>
#include <fstream>
#include "typeDef.h"

using namespace std;

void deleteList(List *aList){
    Element *current = aList->first;
    while (current != nullptr){
        Element *toDel = current;
        current = current->next;
        delete toDel;
    }
}

void addElement(List *aList, Element *anElement){
    if (aList->first==nullptr){
        aList->first = anElement;
    }
    else{
        Element *current = aList->first;
        while(current->next != nullptr){
            current = current->next;
        }
        current->next = anElement;
    }
    aList->nbrElements++;
}

bool initialiseListe(List *aList){
    if (aList->nbrElements != 0){
        return false;
    }
    int nbElem;
    std::cout << "Combien d'elements voullez-vous placer dans la liste ? :";
    while (!(std::cin>>nbElem)){
        std::cin.clear();
        std::cin.ignore();
        std::cout << "Erreur d'entree," << std::endl << "Combien d'elements voullez-vous placer dans la liste ? :";
    }
    for (int i = 0; i < nbElem; i++){
        Element *newElem = new Element;
        if (newElem==nullptr){
            exit(EXIT_FAILURE);
        }
        std::cout << "Quelle valeur voullez-vous placer dans la liste ? :";
        while (!(std::cin>>newElem->value)){
            std::cin.clear();
            std::cin.ignore();
            std::cout << "Erreur d'entree," << std::endl << "Quelle valeur voullez-vous placer dans la liste ? :";
        }
        addElement(aList, newElem);
    }
    return true;
}

void displayList(List *aList){
    Element *current = aList->first;
    while (current!=nullptr){
        std::cout<< current->value << "  ";
        current = current->next;
    }
    std::cout << std::endl;
}

void addElementGrowingOrder(List *aList, Element *anElement){
    if (aList->nbrElements==0){
        aList->first = anElement;
    }
    else if (aList->nbrElements == 1){
        if (aList->first->value < anElement->value){
            aList->first->next = anElement;
        }
        else {
            anElement->next = aList->first;
            aList->first = anElement;
        }
    }
    else{
        Element *precedent = aList->first;
        Element *current = aList->first;
        while (current->value < anElement->value && current != nullptr){
            precedent = current;
            current = current->next;
        }
        precedent->next = anElement;
        anElement->next = current;
    }
    aList->nbrElements++;
}

bool initWithFile(List * aList, std::string aPath){
    std::ifstream inputFile(aPath);
    if (!(inputFile.is_open())){
        std::cout << "ERREUR ! : Impossible d'ouvrir le fichier specifie !" << std::endl;
        return false;
    }
    while (!inputFile.eof()){
        std::cout << "passage de boucle" << std::endl;
        Element *newElem = new Element;
        if (newElem == nullptr){
            std::cout << "Memory allocation Error" << std::endl;
            exit(EXIT_FAILURE);
        }
        inputFile >> newElem->value;
        std::cout << newElem->value;
        addElementGrowingOrder(aList, newElem);
    }
    std::cout << "sortie de boucle" << std::endl;
    inputFile.close();
    return true;
}

int main()
{
    /*
    List *aList = new List;
    if (aList==nullptr){
        exit(EXIT_FAILURE);
    }
    initialiseListe(aList);
    displayList(aList);
    */
    List *aList = new List;
    if (aList==nullptr){
        exit(EXIT_FAILURE);
    }
    initWithFile(aList, "liste.txt");
    displayList(aList);
    deleteList(aList);
    delete aList;
    return 0;
}
