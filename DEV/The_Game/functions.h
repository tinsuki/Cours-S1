#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include "typeDef.h"
#include "GameUtils.h"

/*
 * Utility functions for data structure (based on STL API)
 */

/*
 * Inserts a new element at the top of a list (stack), above its current top
 * element.
 * param: a list
 * param: an element
 */
void push(List* aList, Element* anElement);

/*
 * Returns a reference to the top element in a list (stack)
 * param: a list
 * return: the fist element or 0
 */
int top(const List * aList);

/*
 * Removes the element on top of a list (stack), effectively reducing its size
 * by one.
 * param: a list
 */
void pop(List * aList);

/*
 * A given list is extended by inserting a new element before the element with
 * an equal or greater value. This effectively increases the list size by one.
 * param: a list
 * parma: an element
 */
void insert(List * aList, Element * anElement);

/*
 * Display alist and its size
 * param: a list
 */
void displayList(const List * aList);

/*
 * Delete a list. Free the memory occupied by each element
 */
void deleteList(List * aList);

/*
 * Removes from the container the element that compare equal to aValue. This
 * reduces the container size by one.
 * param: a list
 * parma: a value
 */
void remove(List * aList, const int aValue);

/*
 * Returns the smallest of a and b. If both are equivalent, a is returned.
 * param: a number
 * param: an other number
 * return: the number min of the first if equality
 */
int min(const int aNb1, const int aNb2);

/*
 * Utility functions for The Game
 */

/*
 * Put a card on a stack.
 * param: a list (stack)
 * param: a card
 */
void putACard(List * aList, const int aCard);

/*
 * Shuffle the stock (98 cards numbered from 2 to 99)
 * param: a list
 * var: drawIndex
 */
void shuffle(List * aList);

/*
 * Move a card on a fundation up if possible
 * Condition: the value of the card is greater than the one on the top
 * or the value of the card is 10 lower than the top of the fundation.
 * param: a fundation (stack)
 * param: a card
 * return: true if the move is possible
 * var: valid boolean
 */
bool moveUp(List * aList, const int aCard);

/*
 * Move a card on a fundation down if possible
 * Condition: the value of the card is lower than the one on the top
 * or the value of the card is 10 greater than the top of the fundation
 * param: a fundation (stack)
 * param: a card
 * return: true if the move is possible
 * var: valid boolean
 */
bool moveDown(List * aList, const int aCard);

/*
 * Ask a player to play a card
 * Ask first to choose the value of a card
 * then the name of the fundation for the move
 * param: a fundation (stack)
 * param: a card
 */
void play(int & aCard, char & aStack);

/*
 * Check if a card is in a hand
 * param: a hand (list)
 * param: a card
 * return: true if the card is in the hand
 * var: valid boolean
 */
bool isValid(const List * aHand, const int aValue);

/*
 * Calculate a score
 * Sum cards' value of the hand and the stock
 * param: a hand (list)
 * param: a stock (list)
 * return: int a score
 * var: int sum
 */
int score(const List* aHand, const List* aStock);

/**
 * @brief canPlay Check if player can play a card
 * @param aFundationUpA (List)
 * @param aFundationUpB (List)
 * @param aFundationDownA (List)
 * @param aFundationDownB (List)
 * @param aHand the hand of the player (List)
 * @return bool
 */
bool canPlay(const List * aFundationUpA, const List * aFundationUpB, const  List * aFundationDownA, const List * aFundationDownB, const List * aHand);

/**
 * @brief sendToBegin, send the element of index to first element
 * @param aList, List *, pointer to a List, the list
 * @param index, int, > 0 and < aList->size, the index of the element
 */
void sendToBegin(List *aList, int index);

/**
 * @brief shuffle2, same as shuffle but with aList.size iteration instead of aList.size/2
 * @param aList, List *, pointer to a List, the list to shuffle
 */
void shuffle2(List * aList);

/**
 * @brief tryShuffleDiffSize, show the number of differencesof the two versions of shuffe function
 */
void tryShuffleDiffSize();


#endif // FUNCTIONS_H
