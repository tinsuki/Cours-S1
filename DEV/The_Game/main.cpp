#include <iostream>
#include "typeDef.h"
#include "functions.h"
#include "tests.h"
#include "GameUtils.h"

int main()
{

    bool running = true;
    int choice  = 0;
    while (running){
        // ask player if he want to play (1), to run the tests (2) or quit (3)
        CLEARSCREEN;
        displayMenu();
        while(!(std::cin >> choice) && choice != 1 && choice != 2 && choice != 3 && choice != 4){
            CLEARSCREEN;
            displayMenu();
            std::cin.clear();
            std::cin.ignore();
        }

        // run the game loop
        if (choice == 1){

            // initialize all variables for the game operation and verify if the pointers are good
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
            shuffle(stock); // init and shuffle the game stock

            // give cards to the player
            for (int i = 0; i < HANDLENTH; i++){
                Element *toAdd = new Element;
                if (toAdd == nullptr){
                    exit(EXIT_FAILURE);
                }
                toAdd->value = top(stock);
                pop(stock);
                insert(hand, toAdd);
            }

            // the game loop
            while (canContinue){

                // the turn loop (if the player can play and if he want to continue the turn the turn continue)
                while (canPlay(fundationUpA, fundationUpB, fundationDownA, fundationDownB, hand) && (playing=='y' || playing == 'Y')){

                    // display the game board
                    CLEARSCREEN;
                    displayBoard(fundationUpA, fundationUpB, fundationDownA, fundationDownB, hand, stock);
                    std::cout << std::endl;

                    // the movement loop (if the loop is execute the player can play at least one card)
                    while (!move){
                        play(cardValue, fundation);
                        while (!isValid(hand, cardValue)){
                            std::cout << "La carte choisie n'est pas dans votre main";
                            play(cardValue, fundation);
                        }

                        // moove the card if possible

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

                        // tell if the movement was made and remove the card from the hand if true
                        if (move == false){
                            std::cout << "The choosen card can't be played on the choosen fundation" << std::endl;
                        }
                        else {
                            std::cout << "The card is played." << std::endl;
                            remove(hand, cardValue);
                            nbMoove++;
                        }

                    }

                    // refresh screen and ask player if he want to continue this turn
                    CLEARSCREEN;
                    displayBoard(fundationUpA, fundationUpB, fundationDownA, fundationDownB, hand, stock);
                    std::cout << std::endl;

                    std::cout << "Number of Movement for this turn : " << nbMoove << std::endl;
                    std::cout << "Do you want to continue this turn ? (you must, at least, have done 2 movements) (y/n) : ";
                    while ((!(std::cin >> playing)) && !(playing =='y' || playing == 'n' || playing == 'Y' || playing == 'N')){
                        std::cout << "Input Error, input accepted : Y | y | N | n" << std::endl;
                        std::cout << "Do you want to continue this turn ? (you must, have done 2 movements) (y/n) : ";
                        std::cin.clear();
                        std::cin.ignore();
                    }
                    std::cout << std::endl << std::endl << std::endl;
                    move = false;
                }

                // verify if the player made the right number of movements
                if (stock->size > 0){
                    if (nbMoove < 2){
                        canContinue = false;
                    }
                }
                else {
                    if (nbMoove < 1){
                        canContinue = false;
                    }
                }

                // reset the variables and give card to the player if it s possible
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

            // display the score of the player
            CLEARSCREEN;
            displayTitle();
            std::cout << std::endl;
            centerDisplay("Game finished,");
            std::cout << std::endl;
            centerDisplay("your score is");
            std::cout << std::endl;
            centerDisplay(std::to_string(score(hand, stock)));
            std::cin.clear();
            std::cin.ignore();
            std::cin.get();

            // empty the memory
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
        }

        else if (choice == 2){
            // execute each test and wait for input to go to next
            CLEARSCREEN;
            test_push();
            std::cin.clear();
            std::cin.ignore();
            std::cin.get();
            CLEARSCREEN;
            test_top();
            std::cin.clear();
            std::cin.get();
            CLEARSCREEN;
            test_pop();
            std::cin.clear();
            std::cin.get();
            CLEARSCREEN;
            test_insert();
            std::cin.clear();
            std::cin.get();
            CLEARSCREEN;
            test_displayList();
            std::cin.clear();
            std::cin.get();
            CLEARSCREEN;
            test_remove();
            std::cin.clear();
            std::cin.get();
            CLEARSCREEN;
            test_putACard();
            std::cin.clear();
            std::cin.get();
            CLEARSCREEN;
            test_shuffle();
            std::cin.clear();
            std::cin.get();
            CLEARSCREEN;
            test_displayBoard();
            std::cin.clear();
            std::cin.get();
            CLEARSCREEN;
            test_moveUp();
            std::cin.clear();
            std::cin.get();
            CLEARSCREEN;
            test_moveDown();
            std::cin.clear();
            std::cin.get();
            CLEARSCREEN;
            test_play();
            std::cin.clear();
            std::cin.get();
            CLEARSCREEN;
            test_isValid();
            std::cin.clear();
            std::cin.get();
            CLEARSCREEN;
            test_score();
            std::cin.clear();
            std::cin.get();
        }

        else if (choice == 4){
            // only for develloper, show the differences between shuffle with aList.size iterations
            // and aList.size/2 iterations;
            CLEARSCREEN;
            std::cout << "tryShuffleDiffSize" << std::endl;
            tryShuffleDiffSize();
            std::cout << std::endl;
            std::cout << "shuffle with size/2 iteration : " << std::endl;
            shuffleTime(&shuffle);
            std::cout << "shuffle with size iteration : " << std::endl;
            shuffleTime(&shuffle2);
            for (int i = 0; i < 4; i++){
                testShuffleDiff(shuffle);
            }
            std::cin.clear();
            std::cin.ignore();
            std::cin.get();

        }
        else{
            running = false;
        }
    }




    return 0;
}
