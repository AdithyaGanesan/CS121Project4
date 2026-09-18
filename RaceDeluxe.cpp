#include <iostream>
#include <random>

const int NUM_HORSES = 5;
const int TRACK_LENGTH = 60;

void advance(int horseNum, int* horses) {
    std::random_device rd;
    std::uniform_int_distribution<int> dist0(0, 1); //1/2
    std::uniform_int_distribution<int> dist1(0, 2); //1/3
    std::uniform_int_distribution<int> dist2(0, 3); //1/4
    std::uniform_int_distribution<int> dist3(0, 4); //1/5
    std::uniform_int_distribution<int> dist4(0, 5); //1/6

    std::uniform_int_distribution<int> chooseDist(0, 4);

    int choice = chooseDist(rd);
    int coin;
    int distance; //keeps Expected Value of advance the same for all distX

    if (choice == 0) {
        coin = dist0(rd);
        distance = 2;
    } //end if
    else if (choice == 1) {
        coin = dist1(rd);
        distance = 3;
    } //end else if
    else if (choice == 2) {
        coin = dist2(rd);
        distance = 4;
    }//end else if
    else if (choice == 3) {
        coin = dist3(rd);
        distance = 5;
    }//end else if
    else {
        coin = dist4(rd);
        distance = 6;
    }//end else if

    if (coin == 0) {
        horses[horseNum] += distance;
    }//end if
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
    if (horses[horseNum] >= TRACK_LENGTH - 1) {
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
        
        //protects against multiple horses winning in the same run
        if (numWinners == 1) {
            std::cout << "Horse " << winners[0] << " WINS!!!" << std::endl;
            winner = true;
        } //end if
        else if (numWinners > 1) {
            //creates a tool for randomization
            std::random_device rd;
            std::uniform_int_distribution<int> dist(0, numWinners - 1);

            int winningHorse = winners[dist(rd)];

            std::cout << "Horse " << winningHorse << " WINS!!!" << std::endl;
            winner = true;
        } //end else if

        if (!winner) {
            std::cout << "Press enter for another turn";
            std::cin.get();
        } //end if
    } //end while

    return 0;
} // end main