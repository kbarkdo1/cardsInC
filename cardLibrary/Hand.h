
#include "Card.h"
#include <vector>

class Hand {

    private:
        int cardNumber = 0;
        std::vector<Card*> cardSet = {};

    public:
        Hand();
        Hand(std::vector<Card*> newCardSet, bool sorted);
        void addCard(Card* newCard, bool sorted);
        void addCardSet(std::vector<Card*> newCardSet, bool sorted);
        Card* removeCard(Card* target);
        void shuffle();
        void sort();
        std::vector<Card*> dumpHand();
        ~Hand();
};