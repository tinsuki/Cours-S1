#include <iostream>
#include "typeDef.h"
#include "functions.h"
#include <chrono>
#include "tests.h"

int main()
{
    // test_push(); // pass
    // test_isValid(); // pass
    // test_insert(); // pass
    // test_top(); // pass
    // test_pop(); // pass
    // test_displayList(); // pass
    // test_deleteList(); // pas de test
    // test_remove(); // pass
    // test_min(); pass

    // test_putACard(); // pass
    // test_shuffle(); // pass
    // test_displayBoard(); // pass
    // test_moveUp(); // pass
    // test_moveDown(); // pass
    // test_play(); // pass
    // test_isValid(); // pass
    // test_score(); //

    List  *hand = new List;
    if (hand == nullptr){
        exit(EXIT_FAILURE);
    }

    List *fundationUpA = new List;
    if (fundationUpA == nullptr){
        exit(EXIT_FAILURE);
    }

    List *fundationUpB = new List;
    if (fundationUpB == nullptr){
        exit(EXIT_FAILURE);
    }

    List *fundationDownA = new List;
    if (fundationDownA == nullptr){
        exit(EXIT_FAILURE);
    }

    List *fundationDownB = new List;
    if (fundationDownB == nullptr){
        exit(EXIT_FAILURE);
    }

    List *stock = new List;
    if (stock == nullptr){
        exit(EXIT_FAILURE);
    }

    bool canContinue = true;
    bool move = false;
    int cardValue = 1;
    int nbMoove = 0;
    char fundation = 'f';
    char playing = 'y';
    std::chrono::system_clock::time_point begin = std::chrono::high_resolution_clock::now();
    shuffle(stock);
    std::chrono::system_clock::time_point end = std::chrono::high_resolution_clock::now();
    std::chrono::duration time = end - begin;
    long ns = std::chrono::duration_cast<std::chrono::microseconds> (time).count();

    for (int i = 0; i < HANDLENTH; i++){
        Element *toAdd = new Element;
        if (toAdd == nullptr){
            exit(EXIT_FAILURE);
        }
        toAdd->value = top(stock);
        pop(stock);
        insert(hand, toAdd);
    }

    while (canContinue){
        while (canPlay(fundationUpA, fundationUpB, fundationDownA, fundationDownB, hand) && (playing=='y' || playing == 'Y')){
            displayBoard(fundationUpA, fundationUpB, fundationDownA, fundationDownB, hand);
            while (!move){
                play(cardValue, fundation);
                while (!isValid(hand, cardValue)){
                    std::cout << "La carte choisie n'est pas dans votre main";
                    play(cardValue, fundation);
                }
                if (fundation == 'A' || fundation == 'a'){
                    move = moveUp(fundationUpA, cardValue);
                }
                else if (fundation == 'B' || fundation == 'b'){
                    move = moveUp(fundationUpB, cardValue);
                }
                else if (fundation == 'C' || fundation == 'c'){
                    move = moveDown(fundationDownA, cardValue);
                }
                else if (fundation == 'D' || fundation == 'd'){
                    move = moveDown(fundationDownB, cardValue);
                }
                if (move == false){
                    std::cout << "la carte ne peut pas etre joué sur la fondation choisie." << std::endl;
                }
                else {
                    std::cout << "la carte est jouee." << std::endl;
                    remove(hand, cardValue);
                    nbMoove++;
                }
            }
            std::cout << std::endl << std::endl << std::endl;
            displayBoard(fundationUpA, fundationUpB, fundationDownA, fundationDownB, hand);
            std::cout << "Nombre de mouvement pour ce tour : " << nbMoove << std::endl;
            std::cout << "Voulez-vous continuer ce tour ? (si vous avez joue moins de deux fois le jeu est perdu) (y/n) :";
            while ((!(std::cin >> playing)) || (playing !='y' && playing != 'Y' && playing!='n' && playing != 'N')){
                std::cout << "Erreur d'entree," << std::endl;
                std::cout << "Voulez-vous continuer ce tour ? (si vous avez joue moins de deux fois le jeu est perdu) :";
                std::cin.clear();
                std::cin.ignore();
            }
            std::cout << std::endl << std::endl << std::endl;
            move = false;
        }
        if (nbMoove < 2){
            canContinue = false;
        }
        nbMoove = 0;
        move = false;
        playing = 'y';
        while(hand->size < HANDLENTH && stock->size > 0){
            Element *toAdd = new Element;
            if (toAdd == nullptr){
                exit(EXIT_FAILURE);
            }
            toAdd->value = top(stock);
            pop(stock);
            insert(hand, toAdd);
        }
        if (hand->size == 0){
            canContinue = false;
        }
    }
    std::cout << "Game finished," << std::endl << "your score is " << score(hand, stock) << std::endl;
    CLEARSCREEN;
    std::cout << ns << std::endl;
    deleteList(hand);
    deleteList(fundationUpA);
    deleteList(fundationUpB);
    deleteList(fundationDownA);
    deleteList(fundationDownB);
    deleteList(stock);
    deleteList(hand);
    delete fundationUpA;
    delete fundationUpB;
    delete fundationDownA;
    delete fundationDownB;
    delete stock;
    return 0;
}
