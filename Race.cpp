#include <iostream>
#include <random>

const int NUM_HORSES = 5;
const int TRACK_LENGTH = 15;

void advance(int horseNum, int* horses) {
    std::random_device rd;
    std::uniform_int_distribution<int> dist(0, 1);

    int coin = dist(rd);

    if (coin == 1) {
        horses[horseNum]++;
    } //end if
} // end advance


void printLane(int horseNum, int* horses) {
    for (int i = 0; i < TRACK_LENGTH; i++) {
        if (i == horses[horseNum]) {
            std::cout << horseNum;
        } //end if
        else {
            std::cout << ".";
        } //end else
    } //end for

    std::cout << std::endl;
} // end printLane


bool isWinner(int horseNum, int* horses) {
    if (horses[horseNum] == TRACK_LENGTH - 1) {
        return true;
    } //end if
    else {
        return false;
    } //end else
} // end isWinner


int main() {
    int horses[NUM_HORSES] = {0, 0, 0, 0, 0};

    bool winner = false;

    while (!winner) {

        for (int i = 0; i < NUM_HORSES; i++) {
            advance(i, horses);
        } //end for

        for (int i = 0; i < NUM_HORSES; i++) {
            printLane(i, horses);

            if (isWinner(i, horses)) {
                std::cout << "Horse " << i << " WINS!!!" << std::endl;
                winner = true;
            } //end if
        } //end for

        if (!winner) {
            std::cout << "Press enter for another turn";
            std::cin.get();
        } //end if
    } //end while

    return 0;
} // end main