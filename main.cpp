#include <iostream>
using namespace std;

char theCharacter;
char thePlayer = 0;

char board[3][3] = {{'1','2','3'},{'4','5','6'},{'7','8','9'}};

void printTable() {
    cout << "The table is always up to date:" << endl << '\n';
    cout << " " << board[0][0] << "  " << board[0][1] << "  " << board[0][2] << endl;
    cout << " " << board[1][0] << "  " << board[1][1] << "  " << board[1][2] << endl;
    cout << " " << board[2][0] << "  " << board[2][1] << "  " << board[2][2] << endl;
    cout << endl;
}

void resetTable() {
    board[0][0] = '1';
    board[0][1] = '2';
    board[0][2] = '3';
    board[1][0] = '4';
    board[1][1] = '5';
    board[1][2] = '6';
    board[2][0] = '7';
    board[2][1] = '8';
    board[2][2] = '9';
}

bool setCharacter(int box) {
    int row = box / 3;
    int column;
    if (box % 3 == 0) {
        row = row - 1;
        column = 2;
    }
    else {
        column = (box % 3) - 1;
    }

    if (board[row][column] != 'X' && board[row][column] != 'O') {
        board[row][column] = theCharacter;
        return true;
    }
    else {
        return false;
    }
}

int theWinner() {
    for (int i = 0; i < 3; i++){
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
            return thePlayer;
        }
        if(board[0][i] == board [1][i] && board[1][i] == board[2][i]) {
            return thePlayer;
        }
    }
    if(board[0][0] == board [1][1] && board[1][1] == board[2][2]){
        return thePlayer;
    }
    if(board[0][2] == board [1][1] && board[1][1] == board[2][0]){
        return thePlayer;
    }

    return 0;
}

void checkFunction() {

    if (theCharacter == 'X') {
        theCharacter = 'O';
    }
    else {
        theCharacter = 'X';
    }

    if(thePlayer == 1) {
        thePlayer = 2;
        cout << "Player 2's turn. ";
    }
    else {
        thePlayer = 1;
        cout << "Player 1's turn. ";
    }
}

void startFunction() {
    char symbol;
    int theWonner;
    cout << "You're the 1st player, choose your symbol (X or O):";
    cin >> symbol;

    while (symbol != 'O' && symbol != 'X') {
        cout << "Please choose either X or O:" << '\n';
        //need to clear the character in for fresh input
        cin.clear();
        cin >> symbol;
    }

    thePlayer = 1;
    theCharacter = symbol;

    printTable();

    int boxNumber;

    for (int i = 0; i < 9; i++) {
        cout << "Enter the box number:";
        cin >> boxNumber;

        while (boxNumber < 1 || boxNumber > 9) {
            cout << "Invalid input. Number 1 - 9 only. Please enter again:" << endl;
            cin.clear();
            //decrement i because so the for loop dont wont go over
            i--;
            cin >> boxNumber;
        }

        while (!setCharacter(boxNumber)) {
            cout << "Box chosen! Choose another." << endl;
            cin.clear();
            i--;
            cin >> boxNumber;
        }

        printTable();
        theWonner = theWinner();

        if (theWonner == 1) {
            //better to reset the program at the main func
            cout << "1st player won.";
            break;
        }

        if (theWonner == 2) {
            cout << "2nd player won.";
            break;
        }
        checkFunction();

    }

    if (theWonner == 0) {
        cout << "No winner :(" << endl;
    }

}

char continueGame() {
    char response;
    cout << "Start another game? (Y/N):";
    cin >> response;

    while (response != 'Y' && response != 'N') {
        cout << "Y or N:" << endl;
        cin.clear();
        cin >> response;
    }

    if (response == 'Y') {
        cout << '\n';
        cout << "GAME RESTARTED" << endl << endl;
        resetTable();
        startFunction();
        cout << endl;
        continueGame();
    }
    else if (response == 'N') {
        cout << '\n';
        cout << "Thank you for playing.";
    }

}

int main() {
    //char response;
    //char Y;
    //char N;
    startFunction();
    cout << endl;
    continueGame();

    return 0;
}
