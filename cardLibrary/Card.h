

#include <utility>
enum Suit {
    SPADE,
    HEART,
    CLUB,
    DIAMOND,
    JOKER,
    NONE
};
/*
#define SPADE = 'S';
#define HEART = 'H';
#define CLUB = 'C';
#define DIAMOND = 'D';
*/


struct Card
{
public:
    const Suit suit;
    const unsigned int rank;

    Card(Suit suit, unsigned int rank): suit(suit), rank(rank) {};
    bool operator == (Card compCard);
    bool operator <= (Card compCard);
    std::pair<char, unsigned int> getCard();
    ~Card();
};

bool cardSortComparator(Card* a, Card* b) {
    if (a->suit < b->suit) {
        return true;
    } else if (a->suit == b->suit) {
        if (a->rank <= b-> rank) {
            return true;
        } else {
            return false;
        }
    } else {
        return false;
    }
}

