#include "Deck.h"
#include <algorithm>
#include <random>

Deck::Deck() {
    this->cardNumber = 52;
    std::vector<Suit> suitList = {SPADE, HEART, CLUB, DIAMOND};
    for (int s = 0; s<suitList.size(); s++) {
        for (int r = 2; r<15; r++) {
            staticCardVec.push_back(new Card(suitList[s], r));
        }
    }
    deck = new std::deque<Card *>(staticCardVec.begin(), staticCardVec.end());
};

void Deck::shuffle() {
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::shuffle(deck->begin(), deck->end(), std::default_random_engine(seed));
};

void Deck::sort() {
    std::sort(deck->begin(), deck->end(), cardSortComparator);
};

Card* Deck::draw() {
    if (!deck->empty()) {
        Card* returnCard = deck->front();
    deck->pop_front();
    return returnCard;
    } else {
        return nullptr;
    }
};

void Deck::addCard(Card* card) {
    deck->push_back(card);
};

Deck::~Deck() {
    for (int i=0; i< cardNumber; i++) {
        delete this->staticCardVec[i];
    }
    delete this->deck;
};