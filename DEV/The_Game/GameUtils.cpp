#include "GameUtils.h"
#include "typeDef.h"
#include "functions.h"

void centerDisplay(std::string aText){
    // center the text passed in parameter
    int nbSpace = (80 - aText.length())/2;
    for (int  i = 0; i < nbSpace; i++){
        std::cout << " ";
    }
    std::cout << aText << std::endl;
}

void displayTitle(){
   std::cout << "           _____   _                 _____" << std::endl;
   std::cout << "          |_   _| | |               |  __ \\" << std::endl;
   std::cout << "            | |   | |__     ___     | |  \\/   __ _   _ __ ___     ___" << std::endl;
   std::cout << "            | |   | '_ \\   / _ \\    | | __   / _` | | '_ ` _ \\   / _ \\" << std::endl;
   std::cout << "            | |   | | | | |  __/    | |_\\ \\ | (_| | | | | | | | |  __/" << std::endl;
   std::cout << "            \\_/   |_| |_|  \\___|    \\_____/  \\__,_| |_| |_| |_|  \\___|" << std::endl;
}

void displayBoard(const List * aFundationUpA, const List * aFundationUpB, const  List * aFundationDownA, const List * aFundationDownB, const List * aHand, const List* aStock){
    int topUpA = top(aFundationUpA);
    int topUpB = top(aFundationUpB);
    int topDownA = top(aFundationDownA);
    int topDownB = top(aFundationDownB);
    int stockSize = aStock->size;
    int handCardsSize = 8; // the size of the first card display on the board

    // display the game title
    displayTitle();

    // display the top of the cards
    std::cout << " ______________________________________________________________________________" << std::endl;
    std::cout << "/           ______      ______       ______       ______      ______           \\" << std::endl;
    std::cout << "|          /001  A\\    /001  B\\     /??    \\     /100  C\\    /100  D\\          |" << std::endl;
    std::cout << "|          |      |    |      |     |      |     |      |    |      |          |" << std::endl;

    // display the top of the fundations and the number of cards in the stock
    std::cout << "|          |  ";
    if (topUpA > 9){
        std::cout << topUpA;
    }
    else {
        std::cout << "0" << topUpA;
    }
    std::cout << "  |    |  ";
    if (topUpB > 9){
        std::cout << topUpB;
    }
    else {
        std::cout << "0" << topUpB;
    }
    std::cout << "  |     |  ";
    if (stockSize > 9){
        std::cout << stockSize;
    }
    else {
        std::cout << "0" << stockSize;
    }
    std::cout << "  |     |  ";
    if (topDownA > 9){
        std::cout << topDownA;
    }
    else {
        std::cout << "0" << topDownA;
    }
    std::cout << "  |    |  ";
    if (topDownB > 9){
        std::cout << topDownB;
    }
    else {
        std::cout << "0" << topDownB;
    }

    //display the bottom of the card
    std::cout << "  |          |" << std::endl;
    std::cout << "|          |      |    |      |     |      |     |      |    |      |          |" << std::endl;
    std::cout << "|          \\A__001/    \\B__001/     \\____??/     \\C__100/    \\D__100/          |" << std::endl;
    std::cout << "|                                                                              |" << std::endl;
    std::cout << "|                  ---------------------------------------------               |" << std::endl;


    for (int i = 1; i < aHand->size; i++){
        handCardsSize += 5;
    }

    std::cout << "|";
    for (int i = 0; i < (TERMSIZE-handCardsSize-2)/2; i++){
        std::cout << " ";
    }
    std::cout << " ______ ";
    for (int i = 1; i < aHand->size; i++){
        std::cout << "____ ";
    }
    for (int i = 0; i < (TERMSIZE-handCardsSize-2)/2+(TERMSIZE-handCardsSize-2)%2; i++){
        std::cout << " ";
    }
    std::cout << "|" << std::endl;

    std::cout << "|";
    for (int i = 0; i < (TERMSIZE-handCardsSize-2)/2; i++){
        std::cout << " ";
    }
    std::cout << "/      \\";
    for (int i = 1; i < aHand->size; i++){
        std::cout << "    \\";
    }
    for (int i = 0; i < (TERMSIZE-handCardsSize-2)/2+(TERMSIZE-handCardsSize-2)%2; i++){
        std::cout << " ";
    }
    std::cout << "|" << std::endl;

    std::cout << "|";
    for (int i = 0; i < (TERMSIZE-handCardsSize-2)/2; i++){
        std::cout << " ";
    }
    std::cout << "|      |";
    for (int i = 1; i < aHand->size; i++){
        std::cout << "    |";
    }
    for (int i = 0; i < (TERMSIZE-handCardsSize-2)/2+(TERMSIZE-handCardsSize-2)%2; i++){
        std::cout << " ";
    }
    std::cout << "|" << std::endl;

    std::cout << "|";
    for (int i = 0; i < (TERMSIZE-handCardsSize-2)/2; i++){
        std::cout << " ";
    }
    if (aHand->first->value > 9){
        std::cout << "|  " << aHand->first->value << "  |";
    }
    else {
        std::cout << "|  0" << aHand->first->value << "  |";
    }
    Element *card = aHand->first->next;
    for (int i = 1; i < aHand->size; i++){
        if (card->value > 9){
            std::cout << card->value << "  |";
        }
        else {
            std::cout << "0" << card->value << "  |";
        }
        card = card->next;
    }
    for (int i = 0; i < (TERMSIZE-handCardsSize-2)/2+(TERMSIZE-handCardsSize-2)%2; i++){
        std::cout << " ";
    }
    std::cout << "|" << std::endl;

    std::cout << "|";
    for (int i = 0; i < (TERMSIZE-handCardsSize-2)/2; i++){
        std::cout << " ";
    }
    std::cout << "|      |";
    for (int i = 1; i < aHand->size; i++){
        std::cout << "    |";
    }
    for (int i = 0; i < (TERMSIZE-handCardsSize-2)/2+(TERMSIZE-handCardsSize-2)%2; i++){
        std::cout << " ";
    }
    std::cout << "|" << std::endl;

    std::cout << "|";
    for (int i = 0; i < (TERMSIZE-handCardsSize-2)/2; i++){
        std::cout << " ";
    }
    std::cout << "\\______/";
    for (int i = 1; i < aHand->size; i++){
        std::cout << "____/";
    }
    for (int i = 0; i < (TERMSIZE-handCardsSize-2)/2+(TERMSIZE-handCardsSize-2)%2; i++){
        std::cout << " ";
    }
    std::cout << "|" << std::endl;

    std::cout << "\\______________________________________________________________________By Kevin/" << std::endl;

}


void displayMenu(){
   std::cout << " ________  __                         ______" << std::endl;
   std::cout << "|        \\|  \\                       /      \\" << std::endl;
   std::cout << " \\########| ##____    ______        |  ######\\  ______   ______ ____    ______" << std::endl;
   std::cout << "   | ##   | ##    \\  /      \\       | ## __\\## |      \\ |      \\    \\  /      \\ " << std::endl;
   std::cout << "   | ##   | #######\\|  ######\\      | ##|    \\  \\######\\| ######\\####\\|  ######\\" << std::endl;
   std::cout << "   | ##   | ##  | ##| ##    ##      | ## \\#### /      ##| ## | ## | ##| ##    ##" << std::endl;
   std::cout << "   | ##   | ##  | ##| ########      | ##__| ##|  #######| ## | ## | ##| ########" << std::endl;
   std::cout << "   | ##   | ##  | ## \\##     \\       \\##    ## \\##    ##| ## | ## | ## \\##     \\" << std::endl;
   std::cout << "    \\##    \\##   \\##  \\#######        \\######   \\####### \\##  \\##  \\##  \\#######" << std::endl;
   std:: cout << std::endl << std::endl;
   centerDisplay("1 - Play");
   centerDisplay("2 - Run tests");
   centerDisplay("3 - Quit");
   std:: cout << std::endl << std::endl;
   std::cout << "Enter your choice here : ";
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
