#ifndef TYPEDEF_H
#define TYPEDEF_H

struct Element{
    int value = 0;
    Element *next = nullptr;
};

struct List{
    int nbrElements = 0;
    Element *first = nullptr;
};

#endif // TYPEDEF_H
