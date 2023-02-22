#ifndef TESTS_H
#define TESTS_H

#include "typeDef.h"

/*
 * Utility functions for data structure (based on STL API)
 */

void test_push();
void test_top();
void test_pop();
void test_insert();
void test_displayList();
void test_deleteList();
void test_remove();
void test_min();

/*
 * Utility functions for The Game
 */

void test_putACard();
void test_shuffle();
void test_displayBoard();
void test_moveUp();
void test_moveDown();
void test_play();
void test_isValid();
void test_score();

void shuffleTime(void (* shuffle)(List *));
void testShuffleDiff(void (*shuffle)(List *));
#endif // TESTS_H
