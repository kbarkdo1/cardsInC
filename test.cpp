
#include <iostream>

#define SPADE = 'S';
#define HEART = 'H';
#define CLUB = 'C';
#define DIAMOND = 'D';

int helper() {
    int x = 5;
    return x;
}

int main() {

    int res = helper();
    int* resAdd = &res;
    std::cout << resAdd << std::endl;

    return 0;
}
