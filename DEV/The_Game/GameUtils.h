#ifndef GAMEUTILS_H
#define GAMEUTILS_H

#include "typeDef.h"

/**
 * @brief displayTitle, display the game title in ascii art
 */
void displayTitle();

/**
 * @brief displayGameBoard, display the game board in ascii art
 * @param aFundationUpA, List *, pointer to a List, a fundation from 1 to 100
 * @param aFundationUpB, List *, pointer to a List, a fundation from 1 to 100
 * @param aFundationDownA, List *, pointer to a List, a fundation from 100 to 1
 * @param aFundationDownB, List *, pointer to a List, a fundation from 100 to 1
 * @param aHand, List *, pointer to a List, the hand of the player
 * @param aStock, List *, pointer to a List, the stock of the game
 */
void displayGameBoard(const List * aFundationUpA, const List * aFundationUpB, const  List * aFundationDownA, const List * aFundationDownB, const List * aHand, const List* aStock);

/**
 * @brief displayMenu, display the game menu with an ascii art
 */
void displayMenu();

/**
 * @brief centerDisplay, display a text at the center of a Linux or Mac Os terminal, if it's windows, display right offset
 * @param aText, std::string, a string, the text to display, may be at max 80 characters
 */
void centerDisplay(std::string aText);

/*
 * Display a game board
 * use displayList
 * param: fundations (up and down)
 * param: a stock (stock)
 * param: the player hand (list)

 */
void displayBoard(const List * aFundationUpA, const List * aFundationUpB, const  List * aFundationDownA, const List * aFundationDownB, const List * aHand,const List * stock);

#endif // GAMEUTILS_H
