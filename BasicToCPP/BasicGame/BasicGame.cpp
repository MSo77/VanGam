// BasicGame.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include <stdio.h>
#include <iostream>
//#include <conio.h>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <string>

using namespace std;

int main() {
    cout << setw(20) << "VANGAM" << endl
        << setw(25) << "CREATIVE COMPUTING" << endl
        << setw(30) << "MORRISTOWN, NEW JERSEY \n"
        << "\n"
        << "\n"
        << "\n";
    
    cout << "VAN WYTHOFF'S GAME: DO YOU WANT INSTRUCTIONS? ";
    string instructionAnswer;
    cin >> instructionAnswer;

    if ((instructionAnswer == "N") || (instructionAnswer == "n")) {
        cout << "OK.\n"
            << "\n"
            << "\n"
            << "\n"
            << "\n";
    }
    if ((instructionAnswer == "Y") || (instructionAnswer == "y")) {
        cout << "\nYOU ARE TO CREATE TWO PILES OF MATCHES, EACH CONTAINING 100" << "\n" \
            << "OR LESS.  YOU PLAY ALTERNATELY WITH ME, AND OUR MOVES CONSIST" << "\n" \
            << "OF:" << "\n" \
            << "(A) TAKING AWAY 1 OR MORE MATCHES" << "\n" \
            << "FROM ONE PILE ONLY, OR" << "\n" \
            << "(B) TAKING AWAY THE SAME NUMBER FROM EACH PILE." << "\n" \
            << "THE ONE WHO TAKES AWAY THE LAST MATCH OF ALL WINS." << "\n" \
            << "ENTER YOUR MOVES IN THIS MANNER:" << "\n" \
            << "2L - (2 LEFT) TAKE TWO FROM LEFT PILE" << "\n" \
            << "3R - (3 RIGHT) TAKE THREE FROM RIGHT PILE" << "\n" \
            << "5B - (5 BOTH) TAKE FIVE FROM EACH PILE \n" \
            << "\n"
            << "\n"
            << "\n"
            << "\n";
    }
    cout << "DESIRED PILE SIZES (NUMBER,NUMBER): ";
    int leftPile, rightPile, p;
    string answerFirstMove;
    cin >> leftPile >> rightPile;
    if (leftPile + rightPile > 5) {
        cout << "OH, YOU'RE A SPORT, YOU ARE. \n";
        cout << "DO YOU WANT TO GO FIRST? ";
        cin >> answerFirstMove;
    }
    cout << setw(10) << "LEFT"
        << setw(10) << "RIGHT \n";
    cout << setw(10) << leftPile
        << setw(10) << rightPile;
    
    int leftRand, rightRand, botChoice, botChoiceRand, i = 0;
    string playerMove;
    srand(time(0));
    leftRand = 1 + (rand() % leftPile);
    rightRand = 1 + (rand() % rightPile);
    botChoiceRand = rand() % 2;
    botChoice = 0;



    if ((leftPile == rightPile) && ((answerFirstMove == "N") || (answerFirstMove == "n"))) {
        cout << "\nHMM...I TAKE: " << leftPile << "B" << " LEAVING 0 0" << "\n";
        cout << "SORRY - I WIN.  DON'T FEEL BADLY - I'M AN EXPERT. \n";
        exit(1);
        return 0;
    }



    if ((leftPile == rightPile) && ((answerFirstMove == "Y") || (answerFirstMove == "y"))) {
        while ((leftPile >= 0) && (rightPile >= 0)) {
            cout << "\nYOUR MOVE: ";
            string matchNumber1, matchNumber2, letter;
            int number;
            cin >> playerMove;
            if (playerMove.size() > 2) {
                matchNumber1 = playerMove[0];
                matchNumber2 = playerMove[1];
                number = (stoi(matchNumber1) * 10) + stoi(matchNumber2); // Спички
                letter = playerMove[2]; // Кучка
                cout << number << letter << "\n";
                // botChoice += 1;
            }
            else {
                matchNumber1 = playerMove[0];
                number = stoi(matchNumber1);
                letter = playerMove[1];
                cout << number << letter << "\n";
            }


            if (letter == "R") {
                rightPile -= number;
                cout << " LEAVING " << leftPile << " " << rightPile << "\n";
                if ((rightPile == 0) && (leftPile == 0)) {
                    cout << "YOU WIN!! CONGRADULATIONS.  YOU ARE A VERY CLEVER VAN WYTHOFF'S" << "\n";
                    exit(1);
                    return 0;
                }
                if (leftPile == 0) {
                    cout << "\nHMM...I TAKE: " << rightPile << "R" << " LEAVING " << leftPile << " " << "0" << "\n";
                    rightPile -= rightPile;
                    cout << "SORRY - I WIN.  DON'T FEEL BADLY - I'M AN EXPERT. \n";
                    exit(1);
                    return 0;
                }
                if (rightPile == 0) {
                    cout << "\nHMM...I TAKE: " << leftPile << "L" << " LEAVING 0 " << rightPile << "\n";
                    leftPile -= leftPile;
                    cout << "SORRY - I WIN.  DON'T FEEL BADLY - I'M AN EXPERT. \n";
                    exit(1);
                    return 0;
                }
                if (leftPile == rightPile) {
                    cout << "\nHMM...I TAKE: " << leftPile << "B" << " LEAVING 0 0" << "\n";
                    cout << "SORRY - I WIN.  DON'T FEEL BADLY - I'M AN EXPERT. \n";
                    exit(1);
                    return 0;
                }
                botChoice = 0;
                if (botChoiceRand == 1) {
                    if ((rightPile - rightRand) <= 0)
                    {
                        if (rightPile == 0) {

                        }
                        else {
                            int rightRandZero = 1 + (rand() % rightPile);
                            cout << "\nHMM...I TAKE: " << rightRandZero << "R" << " LEAVING " << leftPile << " " << rightPile - rightRandZero << "\n";
                            rightPile = rightPile - rightRandZero;
                        }
                    }
                    else {
                        cout << "\nHMM...I TAKE: " << rightRand << "R" << " LEAVING " << leftPile << " " << rightPile - rightRand << "\n";
                        rightPile = rightPile - rightRand;
                        // cout << "YOUR MOVE: ";
                        botChoice = 0;
                    }
                }
                if (botChoiceRand == 0) {
                    if ((leftPile - leftRand) <= 0) {
                        if (leftPile == 0) {

                        }
                        else {
                            int leftRandZero = 1 + (rand() % leftPile);
                            cout << "\nHMM...I TAKE: " << leftRandZero << "L" << " LEAVING " << leftPile - leftRandZero << " " << rightPile << "\n";
                            leftPile = leftPile - leftRandZero;
                        }
                    }
                    else {
                        cout << "\nHMM...I TAKE: " << leftRand << "L" << " LEAVING " << leftPile - leftRand << " " << rightPile << "\n";
                        leftPile = leftPile - leftRand;
                        // cout << "YOUR MOVE:  ";
                        botChoice = 0;
                    }
                }
            }
            if (letter == "L") {
                leftPile -= number;
                cout << " LEAVING " << leftPile << " " << rightPile << "\n";
                if ((rightPile == 0) && (leftPile == 0)) {
                    cout << "YOU WIN!! CONGRADULATIONS.  YOU ARE A VERY CLEVER VAN WYTHOFF'S" << "\n";
                    exit(1);
                    return 0;
                }
                if (leftPile == 0) {
                    cout << "\nHMM...I TAKE: " << rightPile << "R" << " LEAVING " << leftPile << " " << "0" << "\n";
                    rightPile -= rightPile;
                    cout << "SORRY - I WIN.  DON'T FEEL BADLY - I'M AN EXPERT. \n";
                    exit(1);
                    return 0;
                }
                if (rightPile == 0) {
                    cout << "\nHMM...I TAKE: " << leftPile << "L" << " LEAVING 0 " << rightPile << "\n";
                    leftPile -= leftPile;
                    cout << "SORRY - I WIN.  DON'T FEEL BADLY - I'M AN EXPERT. \n";
                    exit(1);
                    return 0;
                }
                if (leftPile == rightPile) {
                    cout << "\nHMM...I TAKE: " << leftPile << "B" << " LEAVING 0 0" << "\n";
                    cout << "SORRY - I WIN.  DON'T FEEL BADLY - I'M AN EXPERT. \n";
                    exit(1);
                    return 0;
                }
                botChoice = 0;
                if (botChoiceRand == 1) {
                    if ((rightPile - rightRand) <= 0)
                    {
                        if (rightPile == 0) {

                        }
                        else {
                            int rightRandZero = 1 + (rand() % rightPile);
                            cout << "\nHMM...I TAKE: " << rightRandZero << "R" << " LEAVING " << leftPile << " " << rightPile - rightRandZero << "\n";
                            rightPile = rightPile - rightRandZero;
                        }
                    }
                    else {
                        cout << "\nHMM...I TAKE: " << rightRand << "R" << " LEAVING " << leftPile << " " << rightPile - rightRand << "\n";
                        rightPile = rightPile - rightRand;
                        // cout << "YOUR MOVE: ";
                        botChoice = 0;
                    }
                }
                if (botChoiceRand == 0) {
                    if ((leftPile - leftRand) <= 0) {
                        if (leftPile == 0) {

                        }
                        else {
                            int leftRandZero = 1 + (rand() % leftPile);
                            cout << "\nHMM...I TAKE: " << leftRandZero << "L" << " LEAVING " << leftPile - leftRandZero << " " << rightPile << "\n";
                            leftPile = leftPile - leftRandZero;
                        }
                    }
                    else {
                        cout << "\nHMM...I TAKE: " << leftRand << "L" << " LEAVING " << leftPile - leftRand << " " << rightPile << "\n";
                        leftPile = leftPile - leftRand;
                        // cout << "YOUR MOVE:  ";
                        botChoice = 0;
                    }
                }
            }
            if (letter == "B") {
                rightPile -= number;
                leftPile -= number;
                cout << " LEAVING " << leftPile << " " << rightPile << "\n";
                if ((rightPile == 0) && (leftPile == 0)) {
                    cout << "YOU WIN!! CONGRADULATIONS.  YOU ARE A VERY CLEVER VAN WYTHOFF'S" << "\n";
                    exit(1);
                    return 0;
                }
                if (leftPile == 0) {
                    cout << "\nHMM...I TAKE: " << rightPile << "R" << " LEAVING " << leftPile << " " << "0" << "\n";
                    rightPile -= rightPile;
                    cout << "SORRY - I WIN.  DON'T FEEL BADLY - I'M AN EXPERT. \n";
                    exit(1);
                    return 0;
                }
                if (rightPile == 0) {
                    cout << "\nHMM...I TAKE: " << leftPile << "L" << " LEAVING 0 " << rightPile << "\n";
                    leftPile -= leftPile;
                    cout << "SORRY - I WIN.  DON'T FEEL BADLY - I'M AN EXPERT. \n";
                    exit(1);
                    return 0;
                }
                if (leftPile == rightPile) {
                    cout << "\nHMM...I TAKE: " << leftPile << "B" << " LEAVING 0 0" << "\n";
                    cout << "SORRY - I WIN.  DON'T FEEL BADLY - I'M AN EXPERT. \n";
                    exit(1);
                    return 0;
                }
                botChoice = 0;
                if (botChoiceRand == 1) {
                    if ((rightPile - rightRand) <= 0)
                    {
                        if (rightPile == 0) {

                        }
                        else {
                            int rightRandZero = 1 + (rand() % rightPile);
                            cout << "\nHMM...I TAKE: " << rightRandZero << "R" << " LEAVING " << leftPile << " " << rightPile - rightRandZero << "\n";
                            rightPile = rightPile - rightRandZero;
                        }
                    }
                    else {
                        cout << "\nHMM...I TAKE: " << rightRand << "R" << " LEAVING " << leftPile << " " << rightPile - rightRand << "\n";
                        rightPile = rightPile - rightRand;
                        // cout << "YOUR MOVE: ";
                        botChoice = 0;
                    }
                }
                if (botChoiceRand == 0) {
                    if ((leftPile - leftRand) <= 0) {
                        if (leftPile == 0) {

                        }
                        else {
                            int leftRandZero = 1 + (rand() % leftPile);
                            cout << "\nHMM...I TAKE: " << leftRandZero << "L" << " LEAVING " << leftPile - leftRandZero << " " << rightPile << "\n";
                            leftPile = leftPile - leftRandZero;
                        }
                    }
                    else {
                        cout << "\nHMM...I TAKE: " << leftRand << "L" << " LEAVING " << leftPile - leftRand << " " << rightPile << "\n";
                        leftPile = leftPile - leftRand;
                        // cout << "YOUR MOVE:  ";
                        botChoice = 0;
                    }
                }
            }
        }
    }



    if ((leftPile != rightPile) && ((answerFirstMove == "Y") || (answerFirstMove == "y"))) {
        while ((leftPile >= 0) && (rightPile >= 0)) {
            cout << "\nYOUR MOVE: ";
            string matchNumber1, matchNumber2, letter;
            int number;
            cin >> playerMove;
            if (playerMove.size() > 2) {
                matchNumber1 = playerMove[0];
                matchNumber2 = playerMove[1];
                number = (stoi(matchNumber1) * 10) + stoi(matchNumber2); // Спички
                letter = playerMove[2]; // Кучка
                cout << number << letter << "\n";
                // botChoice += 1;
            }
            else {
                matchNumber1 = playerMove[0];
                number = stoi(matchNumber1);
                letter = playerMove[1];
                cout << number << letter << "\n";
            }


            if (letter == "R") {
                rightPile -= number;
                cout << " LEAVING " << leftPile << " " << rightPile << "\n";
                if ((rightPile == 0) && (leftPile == 0)) {
                    cout << "YOU WIN!! CONGRADULATIONS.  YOU ARE A VERY CLEVER VAN WYTHOFF'S" << "\n";
                    exit(1);
                    return 0;
                }
                if (leftPile == 0) {
                    cout << "\nHMM...I TAKE: " << rightPile << "R" << " LEAVING " << leftPile << " " << "0" << "\n";
                    rightPile -= rightPile;
                    cout << "SORRY - I WIN.  DON'T FEEL BADLY - I'M AN EXPERT. \n";
                    exit(1);
                    return 0;
                }
                if (rightPile == 0) {
                    cout << "\nHMM...I TAKE: " << leftPile << "L" << " LEAVING 0 " << rightPile << "\n";
                    leftPile -= leftPile;
                    cout << "SORRY - I WIN.  DON'T FEEL BADLY - I'M AN EXPERT. \n";
                    exit(1);
                    return 0;
                }
                if (leftPile == rightPile) {
                    cout << "\nHMM...I TAKE: " << leftPile << "B" << " LEAVING 0 0" << "\n";
                    cout << "SORRY - I WIN.  DON'T FEEL BADLY - I'M AN EXPERT. \n";
                    exit(1);
                    return 0;
                }
                botChoice = 0;
                if (botChoiceRand == 1) {
                    if ((rightPile - rightRand) <= 0)
                    {
                        if (rightPile == 0) {

                        }
                        else {
                            int rightRandZero = 1 + (rand() % rightPile);
                            cout << "\nHMM...I TAKE: " << rightRandZero << "R" << " LEAVING " << leftPile << " " << rightPile - rightRandZero << "\n";
                            rightPile = rightPile - rightRandZero;
                        }
                    }
                    else {
                        cout << "\nHMM...I TAKE: " << rightRand << "R" << " LEAVING " << leftPile << " " << rightPile - rightRand << "\n";
                        rightPile = rightPile - rightRand;
                        // cout << "YOUR MOVE: ";
                        botChoice = 0;
                    }
                }
                if (botChoiceRand == 0) {
                    if ((leftPile - leftRand) <= 0) {
                        if (leftPile == 0) {

                        }
                        else {
                            int leftRandZero = 1 + (rand() % leftPile);
                            cout << "\nHMM...I TAKE: " << leftRandZero << "L" << " LEAVING " << leftPile - leftRandZero << " " << rightPile << "\n";
                            leftPile = leftPile - leftRandZero;
                        }
                    }
                    else {
                        cout << "\nHMM...I TAKE: " << leftRand << "L" << " LEAVING " << leftPile - leftRand << " " << rightPile << "\n";
                        leftPile = leftPile - leftRand;
                        // cout << "YOUR MOVE:  ";
                        botChoice = 0;
                    }
                }
            }
            if (letter == "L") {
                leftPile -= number;
                cout << " LEAVING " << leftPile << " " << rightPile << "\n";
                if ((rightPile == 0) && (leftPile == 0)) {
                    cout << "YOU WIN!! CONGRADULATIONS.  YOU ARE A VERY CLEVER VAN WYTHOFF'S" << "\n";
                    exit(1);
                    return 0;
                }
                if (leftPile == 0) {
                    cout << "\nHMM...I TAKE: " << rightPile << "R" << " LEAVING " << leftPile << " " << "0" << "\n";
                    rightPile -= rightPile;
                    cout << "SORRY - I WIN.  DON'T FEEL BADLY - I'M AN EXPERT. \n";
                    exit(1);
                    return 0;
                }
                if (rightPile == 0) {
                    cout << "\nHMM...I TAKE: " << leftPile << "L" << " LEAVING 0 " << rightPile << "\n";
                    leftPile -= leftPile;
                    cout << "SORRY - I WIN.  DON'T FEEL BADLY - I'M AN EXPERT. \n";
                    exit(1);
                    return 0;
                }
                if (leftPile == rightPile) {
                    cout << "\nHMM...I TAKE: " << leftPile << "B" << " LEAVING 0 0" << "\n";
                    cout << "SORRY - I WIN.  DON'T FEEL BADLY - I'M AN EXPERT. \n";
                    exit(1);
                    return 0;
                }
                botChoice = 0;
                if (botChoiceRand == 1) {
                    if ((rightPile - rightRand) <= 0)
                    {
                        if (rightPile == 0) {

                        }
                        else {
                            int rightRandZero = 1 + (rand() % rightPile);
                            cout << "\nHMM...I TAKE: " << rightRandZero << "R" << " LEAVING " << leftPile << " " << rightPile - rightRandZero << "\n";
                            rightPile = rightPile - rightRandZero;
                        }
                    }
                    else {
                        cout << "\nHMM...I TAKE: " << rightRand << "R" << " LEAVING " << leftPile << " " << rightPile - rightRand << "\n";
                        rightPile = rightPile - rightRand;
                        // cout << "YOUR MOVE: ";
                        botChoice = 0;
                    }
                }
                if (botChoiceRand == 0) {
                    if ((leftPile - leftRand) <= 0) {
                        if (leftPile == 0) {

                        }
                        else {
                            int leftRandZero = 1 + (rand() % leftPile);
                            cout << "\nHMM...I TAKE: " << leftRandZero << "L" << " LEAVING " << leftPile - leftRandZero << " " << rightPile << "\n";
                            leftPile = leftPile - leftRandZero;
                        }
                    }
                    else {
                        cout << "\nHMM...I TAKE: " << leftRand << "L" << " LEAVING " << leftPile - leftRand << " " << rightPile << "\n";
                        leftPile = leftPile - leftRand;
                        // cout << "YOUR MOVE:  ";
                        botChoice = 0;
                    }
                }
            }
            if (letter == "B") {
                rightPile -= number;
                leftPile -= number;
                cout << " LEAVING " << leftPile << " " << rightPile << "\n";
                if ((rightPile == 0) && (leftPile == 0)) {
                    cout << "YOU WIN!! CONGRADULATIONS.  YOU ARE A VERY CLEVER VAN WYTHOFF'S" << "\n";
                    exit(1);
                    return 0;
                }
                if (leftPile == 0) {
                    cout << "\nHMM...I TAKE: " << rightPile << "R" << " LEAVING " << leftPile << " " << "0" << "\n";
                    rightPile -= rightPile;
                    cout << "SORRY - I WIN.  DON'T FEEL BADLY - I'M AN EXPERT. \n";
                    exit(1);
                    return 0;
                }
                if (rightPile == 0) {
                    cout << "\nHMM...I TAKE: " << leftPile << "L" << " LEAVING 0 " << rightPile << "\n";
                    leftPile -= leftPile;
                    cout << "SORRY - I WIN.  DON'T FEEL BADLY - I'M AN EXPERT. \n";
                    exit(1);
                    return 0;
                }
                if (leftPile == rightPile) {
                    cout << "\nHMM...I TAKE: " << leftPile << "B" << " LEAVING 0 0" << "\n";
                    cout << "SORRY - I WIN.  DON'T FEEL BADLY - I'M AN EXPERT. \n";
                    exit(1);
                    return 0;
                }
                botChoice = 0;
                if (botChoiceRand == 1) {
                    if ((rightPile - rightRand) <= 0)
                    {
                        if (rightPile == 0) {

                        }
                        else {
                            int rightRandZero = 1 + (rand() % rightPile);
                            cout << "\nHMM...I TAKE: " << rightRandZero << "R" << " LEAVING " << leftPile << " " << rightPile - rightRandZero << "\n";
                            rightPile = rightPile - rightRandZero;
                        }
                    }
                    else {
                        cout << "\nHMM...I TAKE: " << rightRand << "R" << " LEAVING " << leftPile << " " << rightPile - rightRand << "\n";
                        rightPile = rightPile - rightRand;
                        // cout << "YOUR MOVE: ";
                        botChoice = 0;
                    }
                }
                if (botChoiceRand == 0) {
                    if ((leftPile - leftRand) <= 0) {
                        if (leftPile == 0) {

                        }
                        else {
                            int leftRandZero = 1 + (rand() % leftPile);
                            cout << "\nHMM...I TAKE: " << leftRandZero << "L" << " LEAVING " << leftPile - leftRandZero << " " << rightPile << "\n";
                            leftPile = leftPile - leftRandZero;
                        }
                    }
                    else {
                        cout << "\nHMM...I TAKE: " << leftRand << "L" << " LEAVING " << leftPile - leftRand << " " << rightPile << "\n";
                        leftPile = leftPile - leftRand;
                        // cout << "YOUR MOVE:  ";
                        botChoice = 0;
                    }
                }
            }
        }

    }
    if ((leftPile != rightPile) && ((answerFirstMove == "N") || (answerFirstMove == "n"))) {
        if (botChoiceRand == 1) {
            if ((rightPile - rightRand) <= 0)
            {
                if (rightPile == 0) {

                }
                else {
                    int rightRandZero = 1 + (rand() % rightPile);
                    cout << "\nHMM...I TAKE: " << rightRandZero << "R" << " LEAVING " << leftPile << " " << rightPile - rightRandZero << "\n";
                    rightPile = rightPile - rightRandZero;
                }
            }
            else {
                cout << "\nHMM...I TAKE: " << rightRand << "R" << " LEAVING " << leftPile << " " << rightPile - rightRand << "\n";
                rightPile = rightPile - rightRand;
                // cout << "YOUR MOVE: ";
                botChoice = 0;
            }
        }
        if (botChoiceRand == 0) {
            if ((leftPile - leftRand) <= 0) {
                if (leftPile == 0) {

                }
                else {
                    int leftRandZero = 1 + (rand() % leftPile);
                    cout << "\nHMM...I TAKE: " << leftRandZero << "L" << " LEAVING " << leftPile - leftRandZero << " " << rightPile << "\n";
                    leftPile = leftPile - leftRandZero;
                }
            }
            else {
                cout << "\nHMM...I TAKE: " << leftRand << "L" << " LEAVING " << leftPile - leftRand << " " << rightPile << "\n";
                leftPile = leftPile - leftRand;
                // cout << "YOUR MOVE:  ";
                botChoice = 0;
            }
        }
        while ((leftPile >= 0) && (rightPile >= 0)) {
            cout << "\nYOUR MOVE: ";
            string matchNumber1, matchNumber2, letter;
            int number;
            cin >> playerMove;
            if (playerMove.size() > 2) {
                matchNumber1 = playerMove[0];
                matchNumber2 = playerMove[1];
                number = (stoi(matchNumber1) * 10) + stoi(matchNumber2); // Спички
                letter = playerMove[2]; // Кучка
                cout << number << letter << "\n";
                // botChoice += 1;
            }
            else {
                matchNumber1 = playerMove[0];
                number = stoi(matchNumber1);
                letter = playerMove[1];
                cout << number << letter << "\n";
            }


            if (letter == "R") {
                rightPile -= number;
                cout << " LEAVING " << leftPile << " " << rightPile << "\n";
                if ((rightPile == 0) && (leftPile == 0)) {
                    cout << "YOU WIN!! CONGRADULATIONS.  YOU ARE A VERY CLEVER VAN WYTHOFF'S" << "\n";
                    exit(1);
                    return 0;
                }
                if (leftPile == 0) {
                    cout << "\nHMM...I TAKE: " << rightPile << "R" << " LEAVING " << leftPile << " " << "0" << "\n";
                    rightPile -= rightPile;
                    cout << "SORRY - I WIN.  DON'T FEEL BADLY - I'M AN EXPERT. \n";
                    exit(1);
                    return 0;
                }
                if (rightPile == 0) {
                    cout << "\nHMM...I TAKE: " << leftPile << "L" << " LEAVING 0 " << rightPile << "\n";
                    leftPile -= leftPile;
                    cout << "SORRY - I WIN.  DON'T FEEL BADLY - I'M AN EXPERT. \n";
                    exit(1);
                    return 0;
                }
                if (leftPile == rightPile) {
                    cout << "\nHMM...I TAKE: " << leftPile << "B" << " LEAVING 0 0" << "\n";
                    cout << "SORRY - I WIN.  DON'T FEEL BADLY - I'M AN EXPERT. \n";
                    exit(1);
                    return 0;
                }
                botChoice = 0;
                if (botChoiceRand == 1) {
                    if ((rightPile - rightRand) <= 0)
                    {
                        if (rightPile == 0) {

                        }
                        else {
                            int rightRandZero = 1 + (rand() % rightPile);
                            cout << "\nHMM...I TAKE: " << rightRandZero << "R" << " LEAVING " << leftPile << " " << rightPile - rightRandZero << "\n";
                            rightPile = rightPile - rightRandZero;
                        }
                    }
                    else {
                        cout << "\nHMM...I TAKE: " << rightRand << "R" << " LEAVING " << leftPile << " " << rightPile - rightRand << "\n";
                        rightPile = rightPile - rightRand;
                        // cout << "YOUR MOVE: ";
                        botChoice = 0;
                    }
                }
                if (botChoiceRand == 0) {
                    if ((leftPile - leftRand) <= 0) {
                        if (leftPile == 0) {

                        }
                        else {
                            int leftRandZero = 1 + (rand() % leftPile);
                            cout << "\nHMM...I TAKE: " << leftRandZero << "L" << " LEAVING " << leftPile - leftRandZero << " " << rightPile << "\n";
                            leftPile = leftPile - leftRandZero;
                        }
                    }
                    else {
                        cout << "\nHMM...I TAKE: " << leftRand << "L" << " LEAVING " << leftPile - leftRand << " " << rightPile << "\n";
                        leftPile = leftPile - leftRand;
                        // cout << "YOUR MOVE:  ";
                        botChoice = 0;
                    }
                }
            }
            if (letter == "L") {
                leftPile -= number;
                cout << " LEAVING " << leftPile << " " << rightPile << "\n";
                if ((rightPile == 0) && (leftPile == 0)) {
                    cout << "YOU WIN!! CONGRADULATIONS.  YOU ARE A VERY CLEVER VAN WYTHOFF'S" << "\n";
                    exit(1);
                    return 0;
                }
                if (leftPile == 0) {
                    cout << "\nHMM...I TAKE: " << rightPile << "R" << " LEAVING " << leftPile << " " << "0" << "\n";
                    rightPile -= rightPile;
                    cout << "SORRY - I WIN.  DON'T FEEL BADLY - I'M AN EXPERT. \n";
                    exit(1);
                    return 0;
                }
                if (rightPile == 0) {
                    cout << "\nHMM...I TAKE: " << leftPile << "L" << " LEAVING 0 " << rightPile << "\n";
                    leftPile -= leftPile;
                    cout << "SORRY - I WIN.  DON'T FEEL BADLY - I'M AN EXPERT. \n";
                    exit(1);
                    return 0;
                }
                if (leftPile == rightPile) {
                    cout << "\nHMM...I TAKE: " << leftPile << "B" << " LEAVING 0 0" << "\n";
                    cout << "SORRY - I WIN.  DON'T FEEL BADLY - I'M AN EXPERT. \n";
                    exit(1);
                    return 0;
                }
                botChoice = 0;
                if (botChoiceRand == 1) {
                    if ((rightPile - rightRand) <= 0)
                    {
                        if (rightPile == 0) {

                        }
                        else {
                            int rightRandZero = 1 + (rand() % rightPile);
                            cout << "\nHMM...I TAKE: " << rightRandZero << "R" << " LEAVING " << leftPile << " " << rightPile - rightRandZero << "\n";
                            rightPile = rightPile - rightRandZero;
                        }
                    }
                    else {
                        cout << "\nHMM...I TAKE: " << rightRand << "R" << " LEAVING " << leftPile << " " << rightPile - rightRand << "\n";
                        rightPile = rightPile - rightRand;
                        // cout << "YOUR MOVE: ";
                        botChoice = 0;
                    }
                }
                if (botChoiceRand == 0) {
                    if ((leftPile - leftRand) <= 0) {
                        if (leftPile == 0) {

                        }
                        else {
                            int leftRandZero = 1 + (rand() % leftPile);
                            cout << "\nHMM...I TAKE: " << leftRandZero << "L" << " LEAVING " << leftPile - leftRandZero << " " << rightPile << "\n";
                            leftPile = leftPile - leftRandZero;
                        }
                    }
                    else {
                        cout << "\nHMM...I TAKE: " << leftRand << "L" << " LEAVING " << leftPile - leftRand << " " << rightPile << "\n";
                        leftPile = leftPile - leftRand;
                        // cout << "YOUR MOVE:  ";
                        botChoice = 0;
                    }
                }
            }
            if (letter == "B") {
                rightPile -= number;
                leftPile -= number;
                cout << " LEAVING " << leftPile << " " << rightPile << "\n";
                if ((rightPile == 0) && (leftPile == 0)) {
                    cout << "YOU WIN!! CONGRADULATIONS.  YOU ARE A VERY CLEVER VAN WYTHOFF'S" << "\n";
                    exit(1);
                    return 0;
                }
                if (leftPile == 0) {
                    cout << "\nHMM...I TAKE: " << rightPile << "R" << " LEAVING " << leftPile << " " << "0" << "\n";
                    rightPile -= rightPile;
                    cout << "SORRY - I WIN.  DON'T FEEL BADLY - I'M AN EXPERT. \n";
                    exit(1);
                    return 0;
                }
                if (rightPile == 0) {
                    cout << "\nHMM...I TAKE: " << leftPile << "L" << " LEAVING 0 " << rightPile << "\n";
                    leftPile -= leftPile;
                    cout << "SORRY - I WIN.  DON'T FEEL BADLY - I'M AN EXPERT. \n";
                    exit(1);
                    return 0;
                }
                if (leftPile == rightPile) {
                    cout << "\nHMM...I TAKE: " << leftPile << "B" << " LEAVING 0 0" << "\n";
                    cout << "SORRY - I WIN.  DON'T FEEL BADLY - I'M AN EXPERT. \n";
                    exit(1);
                    return 0;
                }
                botChoice = 0;
                if (botChoiceRand == 1) {
                    if ((rightPile - rightRand) <= 0)
                    {
                        if (rightPile == 0) {
  
                        }
                        else {
                            int rightRandZero = 1 + (rand() % rightPile);
                            cout << "\nHMM...I TAKE: " << rightRandZero << "R" << " LEAVING " << leftPile << " " << rightPile - rightRandZero << "\n";
                            rightPile = rightPile - rightRandZero;
                        }
                    }
                    else {
                        cout << "\nHMM...I TAKE: " << rightRand << "R" << " LEAVING " << leftPile << " " << rightPile - rightRand << "\n";
                        rightPile = rightPile - rightRand;
                        // cout << "YOUR MOVE: ";
                        botChoice = 0;
                    }
                }
                if (botChoiceRand == 0) {
                    if ((leftPile - leftRand) <= 0) {
                        if (leftPile == 0) {

                        }
                        else {
                            int leftRandZero = 1 + (rand() % leftPile);
                            cout << "\nHMM...I TAKE: " << leftRandZero << "L" << " LEAVING " << leftPile - leftRandZero << " " << rightPile << "\n";
                            leftPile = leftPile - leftRandZero;
                        }
                    }
                    else {
                        cout << "\nHMM...I TAKE: " << leftRand << "L" << " LEAVING " << leftPile - leftRand << " " << rightPile << "\n";
                        leftPile = leftPile - leftRand;
                        // cout << "YOUR MOVE:  ";
                        botChoice = 0;
                    }
                    system("pause");
                    return 0;

                    
                }
            }
        }
    }
}