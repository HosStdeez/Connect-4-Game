/* program: Connect-4, 2 players alternatively take turns in placing pieces and whoever connects 4 or more pieces horizontally, vertically, or diagonally wins!
 * author: Hussam Muhammed Ahmed Abdelaziz
 * ID: 20230121
 * Section: No Section yet
 * Version: 1.0
 * Date: 3/3/2024
 * */


#include <iostream>
#include <string>
using namespace std;

//the board is actually 7*6 but the extra cells are just padding so it would be easier to iterate over when checking the winner
char board[12][13];
//a variable that indicates the number of empty cells, 42 = 7*6
int available = 42;

//initializes the board with all empty cells
void initializeBoard(){
    for (int i = 0; i < 12; ++i) {
        for (int j = 0; j < 13; ++j) {
            board[i][j] ='-';
        }
    }
}
//function that shows the board
void showBoard(){
    for (int i = 3; i < 9; ++i) {
        for (int j = 3; j < 10; ++j) {
           cout<<board[i][j]<<' ';
        }
        cout<<endl;
    }
}
//the message that's going to be shown when there's a winner, made into a function so we don't have to write it more than once
bool winMsg(int player){
    cout<<"Player "<<player<<" is the winner!! :)"<<endl;
    cout<<"GG"<<endl<<endl;
    return true;
}
bool checkWinner(int x,int y,char piece,int player){
    int cnt = 0;
    //horizontal iteration
    for (int j = y-3;  j <= y+3 ; ++j) {
        if (board[x][j] == piece)cnt++;
        else cnt = 0;
        if (cnt>=4)return winMsg(player);
    }
    cnt = 0;
    //vertical iteration
    for (int j = x-3;  j <= x+3 ; ++j) {
        if (board[j][y] == piece)cnt++;
        else cnt = 0;
        if (cnt>=4)return winMsg(player);
    }
    cnt = 0;
    //diagonal iteration
    for (int j = y-3,i = x-3;  j <= y+3 && i <= x+3 ; ++j,++i) {
        if (board[i][j] == piece)cnt++;
        else cnt = 0;
        if (cnt>=4)return winMsg(player);
    }
    cnt = 0;
    //diagonal iteration
    for (int j = y-3 ,i = x+3;  j <= y+3 && i >= x-3 ; ++j,i--) {
        if (board[i][j] == piece)cnt++;
        else cnt = 0;
        if (cnt>=4)return winMsg(player);
    }
    //if available cells count is zero and there's no winner then it's a draw
    if (available == 0){
        cout<<"DRAW!! :("<<endl;
        return true;
    }
    return false;
}

//playTurn function validates input first then places the piece in the preferred cell, and with each turn calls the checkWinner function and shows the board
bool playTurn(char piece){
    string input;
    cin >> input;
    int col = input[0]-'0';
    //validate the input
    while (input.size() != 1 || !isdigit(input[0]) || col < 1 || col > 7 || board[3][col+2] != '-'){
        cout<<"enter a single digit number between 1 and 7 and make sure that the column has empty space:";
        cin>>input;
        cout<<endl;
        col = input[0]-'0';
    }
    for (int i = 8; i >= 3; --i) {
        if (board[i][col + 2] == '-') {
            board[i][col + 2] = piece;
            showBoard();
            available--;
            return checkWinner(i, col + 2, piece, piece == 'X' ? 1 : 2);
        }
    }
    //code won't reach here
    return false;
}
//the game functions initiates essential assets before playing, such as the board and available cells etc.
void game(){
    available = 42;
    initializeBoard();
    showBoard();
    while(true){
        cout<<"Player1 turn enter the column number: ";
        cout<<endl;
        if (playTurn('X'))break;
        cout<<"Player2 turn enter the column number: ";
        cout<<endl;
        if (playTurn('O'))break;
    }
}

//main function to run the whole game
int main() {
    cout<<"Welcome to the Connect 4 game :))"<<endl<<endl;
    while (true){
        game();
        cout<<"do you want to continue playing?? :)) 1)yes 2)no";
        int k;cin>>k;
        if ((k-1)){
            cout<<"GoodBye :("<<endl;
            break;
        }
    }
    return 0;
}