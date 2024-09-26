#include <iostream>
#include <vector>
#include <limits>

using namespace std;

class kreNo {
private:
    vector<vector<char>> board;
    char currentPlayer;

public:
    kreNo() : board(3, vector<char>(3, ' ')), currentPlayer('X') {}

    void pole() {
        cout << "    0   1   2\n";
        cout << " -------------\n";
        for (int i = 0; i < 3; i++) {
            cout << i << " | ";
            for (int j = 0; j < 3; j++) {
                cout << board[i][j] << " | ";
            }
            cout << "\n -------------\n";
        }
    }

    bool makeMove(int row, int col) {
        if (row < 0 || row >= 3 || col < 0 || col >= 3 || board[row][col] != ' ') {
            cout << "Некорректный ход. Введите клетку заново.\n";
            return false;
        }
        board[row][col] = currentPlayer;
        return true;
    }

    bool checkWin() {
        for (int i = 0; i < 3; i++) {
            if (board[i][0] == currentPlayer && board[i][1] == currentPlayer && board[i][2] == currentPlayer) {
                return true;
            }
        }
        for (int i = 0; i < 3; i++) {
            if (board[0][i] == currentPlayer && board[1][i] == currentPlayer && board[2][i] == currentPlayer) {
                return true;
            }
        }
        if (board[0][0] == currentPlayer && board[1][1] == currentPlayer && board[2][2] == currentPlayer) {
            return true;
        }
        if (board[0][2] == currentPlayer && board[1][1] == currentPlayer && board[2][0] == currentPlayer) {
            return true;
        }
        return false;
    }

    bool checkDraw() {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (board[i][j] == ' ') {
                    return false;
                }
            }
        }
        return true;
    }

    void switchPlayer() {
        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }

    void play() {
        int row, col;
        while (true) {
            system("cls");
            pole();
            cout << "Игрок " << currentPlayer << ", введите строку и столбик через пробел: ";

            while (!(cin >> row >> col)) {
                cout << "Ошибка ввода! Пожалуйста, введите два числа: ";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }

            if (!makeMove(row, col)) {
                continue;
            }
            if (checkWin()) {
                system("cls");
                pole();
                cout << "Игрок " << currentPlayer << " победил!\n";
                break;
            }
            if (checkDraw()) {
                system("cls");
                pole();
                cout << "Ничья!\n";
                break;
            }
            switchPlayer();
        }
    }
};

int main() {
    setlocale(LC_ALL, "");
    kreNo game;
    game.play();
}
