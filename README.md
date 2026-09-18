# CS121Project4

**Built By Adithya Ganesan**

Introduction to C++ Programs

Procedural Horse Race

## Race.cpp

Horse race game in C++. Each horse has a 50% chance to move one space forward each turn.

Pseudocode:

```text
constant NUM_HORSES is the current number of horses
constant TRACK_LENGTH is the amount of spaces a horse needs to move to finish

function advance(horseNum, horses):
    create random device rd
    create integer distribution dist from 0 to 1
    create integer variable coin

    coin = dist(rd)

    if coin equals 1:
        horses[horseNum] = horses[horseNum] + 1
    
function printLane(horseNum, horses):
    create integer variable i

    for i from zero to 14:
        if i equals horses[horseNum]:
            print horseNum
        else:
            print "."
    
    print new line

function isWinner(horseNum, horses):
    if horses[horseNum] equals 14:
        return true
    else:
        return false

function main():
    create integer array horses with 5 elements
    set all horses to zero

    create boolean variable winner
    set winner to false

    while winner is false:
        for each horse from 0 to 4:
            advance(horse, horses)

        for each horse from 0 to 4:
            printLane(horse, horses)

            if isWinner(horse, horses):
                print "Horse horse WINS!!!"
                set winner to true

        if winner is false:
            print "Press enter for another turn"
            wait for user to press Enter