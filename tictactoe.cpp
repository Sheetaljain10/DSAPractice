#include <bits/stdc++.h>
using namespace std;

class game{
    vector<vector<char>>board;
    int currPlayer;
    public:
    game(){
        board = vector<vector<char>>(3,vector<char>(3,' '));
        currPlayer = 1;
    }
    void printBoard(){
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                cout<<board[i][j];
                if(j<2) cout<<"|";
            }
            cout<<endl;
            if(i<2) cout<<"------"<<endl;
        }
    }

    bool isBoardFull(){
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                if(board[i][j] == ' '){
                    return false;
                }
            }
        }
        return true;
    }

    bool makeMove(int row,int column){
        if(row<0 || row>2 || column<0 || column>2 || board[row][column] != ' '){
            return false;
        }
        board[row][column] = currPlayer == 1 ? 'X': 'O';
        currPlayer = 3 - currPlayer;
        return true;
    }

    bool checkWinner(){
        for(int i=0;i<3;i++){
            if(board[i][0] != ' ' && board[i][1] == board[i][2] && board[i][2] == board[i][1]) return true;
        }
        for(int i=0;i<3;i++){
            if(board[0][i] != ' ' && board[0][i] == board[1][i] && board[1][i] == board[2][i]) return true;
        }
        if(board[0][0] != ' ' && board[1][1] == board[0][0] && board[1][1] == board[2][2]) return true;
        if(board[0][2] != ' ' && board[1][1] == board[0][2] && board[1][1] == board[2][0]) return true;
        return false;
    }

    int getCurrPlayer(){
        return currPlayer;
    }
};
int main(){
    game tictactoe;
    int row, column;
    while(!tictactoe.isBoardFull() && !tictactoe.checkWinner()){
        tictactoe.printBoard();
        cout<<" Player "<<tictactoe.getCurrPlayer()<<" , Enter your move [Row Column]: ";
        cin>>row>>column;
        if(tictactoe.makeMove(row,column)){
            cout<<"Successfull move!!"<<endl;
        }
        else{
            cout<<"Invalid move!! try again..."<<endl;
        }
    }
    tictactoe.printBoard();
    if(tictactoe.checkWinner()){
        cout<<"Player "<<(3- tictactoe.getCurrPlayer())<<" wins!!"<<endl;
    }
    else{
        cout<<"It's draw!"<<endl;
    }
    return 0;
}