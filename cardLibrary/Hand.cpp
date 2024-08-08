#include "Hand.h"
#include <algorithm>
#include <random>

Hand::Hand(std::vector<Card*> newCardSet, bool sorted) {
    this->addCardSet(newCardSet, sorted);
}

void Hand::addCard(Card* newCard, bool sorted) {

    cardSet.push_back(newCard);
    cardNumber++;
    if (sorted) {
        Hand::sort();
    }
}

void Hand::addCardSet(std::vector<Card*> newCardSet, bool sorted) {
    for (int i=0; i < newCardSet.size(); i++) {
        cardNumber++;
        cardSet.push_back(newCardSet[i]);
    }
};

Card* Hand::removeCard(Card* target) {
    for (auto i = cardSet.begin(); i != cardSet.end(); i++) {
        if ((*i)->suit == target->suit && (*i)->rank == target->rank) {
            Card* card = (*i);
            cardSet.erase(i, i+1);
            cardNumber--;
            return card;
        }
    }
    return nullptr;
}

void Hand::shuffle() {
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::shuffle(cardSet.begin(), cardSet.end(), std::default_random_engine(seed));
}

void Hand::sort() {
    std::sort(cardSet.begin(), cardSet.end(), cardSortComparator);
}

std::vector<Card*> Hand::dumpHand() {
    std::vector<Card*> handVec = {};
    std::copy(cardSet.begin(), cardSet.end(), handVec.begin());
    cardSet.clear();
    cardNumber = 0;
    return handVec;
};



