#ifndef TYPEDEF_H
#define TYPEDEF_H

#include <iostream>
#include <random>

#ifdef _WIN32
#define CLEARSCREEN system("cls")
#endif

#ifdef __APPLE__
#define CLEARSCREEN system("clear")
#endif

#ifdef __linux__
#define CLEARSCREEN system("clear")
#endif

#ifndef CLEARSCREEN
#define CLEARSCREEN for (int i=0; i<100; i++){std::cout<<std::endl;}
#endif

const int MINCARDVALUE = 2;
const int MAXCARDVALUE = 99;
const int HANDLENTH = 8;
const int MAXSTOCKSIZE = MAXCARDVALUE-MINCARDVALUE+1;
const int TERMSIZE = 80;


/*
 * Element of a list
 */
struct Element
{
    int value = 0;
    Element * next = nullptr;
};

/*
 * Definition of a list
 */
struct List
{
    int size = 0;
    Element * first = nullptr;
};
#endif // TYPEDEF_H
