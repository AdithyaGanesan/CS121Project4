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
        int winners[NUM_HORSES];
        int numWinners = 0;

        for (int i = 0; i < NUM_HORSES; i++) {
            advance(i, horses);
        } //end for

        for (int i = 0; i < NUM_HORSES; i++) {
            printLane(i, horses);
        } //end for

        for (int i = 0; i < NUM_HORSES; i++) {
            if (isWinner(i, horses)) {
                winners[numWinners] = i;
                numWinners++;
            } //end if
        } //end for
        
        if (numWinners == 1) {
            std::cout << "Horse " << winners[0] << " WINS!!!" << std::endl;
            winner = true;
        } //end if

        else if (numWinners > 1) {
            std::random_device rd;
            std::uniform_int_distribution<int> dist(0, numWinners - 1);

            int winningHorse = winners[dist(rd)];

            std::cout << "Horse " << winningHorse << " WINS!!!" << std::endl;
            winner = true;
        } //end if

        if (!winner) {
            std::cout << "Press enter for another turn";
            std::cin.get();
        } //end if
    } //end while

    return 0;
} // end main