#include "Card.h"

std::pair<char, unsigned int> Card::getCard() { 
    return {this->suit, this->rank};
}

