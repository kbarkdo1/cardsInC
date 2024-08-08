
#include <deque>
#include <vector>
#include "Card.h"


class Deck {
    private:
        int cardNumber = 0;
        std::vector<Card *> staticCardVec{};
        std::deque<Card *>* deck;

    public:
        Deck();
        void shuffle();
        void sort();
        Card* draw();
        void addCard(Card* card);
        ~Deck();
};