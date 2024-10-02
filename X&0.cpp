#include <iostream>
#include <string>
#include <array>

using namespace std;



struct Player {
    string name;
    string symbol;
    int nWin = 0;
};


class PlayingField {
private:
    Player player1;
    Player player2;
    Player playerMove;
    bool isGame = false;
    string pf[3][3] = {
        {" "," "," "},
        {" "," "," "},
        {" "," "," "},
    };

public:

    PlayingField() {
        player1.name = "player1";
        player1.symbol = "x";
        player1.nWin = 0;

        player2.name = "player2";
        player2.symbol = "0";
        player2.nWin = 0;
    }



    void startGame() {
        setStartingSetting();
        isGame = true;
        while (isGame)
        {
            printPlaingField();
            int* arrayPosition = &getPosition()[0];
            int& x = *arrayPosition;
            int& y = *(arrayPosition + 1);
            if (!setPosition(x, y)) {
                continue;
            }
            if (cheakPlayingField()) {
                printWin();
            }
            else {
                swapPlayerMove();
            }
        }
    }

    void printWin() {
        cout << "Выйграл: " << playerMove.name << endl;
        playerMove.nWin++;
        string isСontinuesGame;
        cout << "Продолжаем игру? (Y/N): ";
        cin >> isСontinuesGame;
        cout << "\n";
        if (isСontinuesGame == "Y" || isСontinuesGame == "y") {
            cout << "Продолжаем\n\n";
            setDefaultPlayingField();
            swapPlayerMove();
        }
        else if (isСontinuesGame == "N" || isСontinuesGame == "n") {
            isGame = false;
        }
        else {
            cout << "Недопустимое значение" << "\n\n";
            printWin();
        }
    }

    void setDefaultPlayingField() {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++)
            {
                pf[i][j] = " ";
            }
        }
    }
   
    void setStartingSetting() {
        string namePlayer1, namePlayer2;
        cout << "Игра X&0\n\n";
        cout << "Сделал: Ландарев Иван\nГруппа: 4104\n";
        cout << "Чтобы прекратить игру, в поля позиции введити '-1'\n\n";
        cout << "Введите имя 1 игрока: ";
        cin >> namePlayer1;
        player1.name = namePlayer1;
        cout << "Введите имя 2 игрока: ";
        cin >> namePlayer2;
        player2.name = namePlayer2;
        cout << "Игра начинается. Удачи\n\n";
        playerMove = player1;
        cout << "Игру начинает: " << playerMove.name << " \n\n";

    }

    void printPlaingField() {
        for (int i = 0; i < 3; i++)
        {
            string tempLine = " ";
            for (int j = 0; j < 3; j++)
            {
                tempLine.append(pf[i][j]);
                if (j < 2) {
                    tempLine.append(" | ");
                };
            };
            cout << tempLine << endl;
        };
    }
  
    bool cheakPlayingField() {
        // horizontal and vertical

        for (int i = 0; i < 3; i++)
        {
            int nHorizontal = 0;
            int nVertical = 0;
            for (int j = 0; j < 3; j++)
            {
                if (pf[i][j] == playerMove.symbol) {
                    nHorizontal++;
                }
                if (pf[j][i] == playerMove.symbol) {
                    nVertical++;
                }
            }
            if (nHorizontal == 3) {
                return true;
            }
            if (nVertical == 3) {
                return true;
            }
        }
       
        // diagonal
        int nDiagonal1 = 0;
        int nDiagonal2 = 0;

        for (int i = 0; i < 3; i++)
        {
            if (pf[i][i] == playerMove.symbol)
            {
                nDiagonal1++;
            }
            if (pf[i][2 - i] == playerMove.symbol) {
                nDiagonal2++;
            }
            if (nDiagonal1 == 3) {
                return true;
            }
            if (nDiagonal2 == 3) {
                return true;
            }
        }
        return false;
    }

    void swapPlayerMove() {
        if (playerMove.name == player1.name) {
            playerMove = player2;
        }
        else {
            playerMove = player1;
        }
        cout << "Теперь ходит игрок " << playerMove.name << "\n\n";
    }

    array<int, 2> getPosition() {
        int x = 0, y = 0;
        cout << "Позиция x: ";
        cin >> x;
        cout << endl;
        cout << "Позиция y: ";
        cin >> y;
        cout << endl;

        bool isPositionX = (x >= 0 && x <= 3);
        bool isPositionY = (y >= 0 && y <= 3);

        if (isPositionX && isPositionY)
        {
            array<int,2> arrayPosition {x, y};
            return arrayPosition;
        }
        else if (x == -1 || y == -1)
        {
            cout << "Игра закончена!\n\n";
            array<int, 2> arrayPosition{ -1, -1 };
            return arrayPosition;
        }
        else {
            cout << "Значения вне допустимого диапозона!\n\n";
            getPosition();
        }
    }

    bool setPosition(int& x, int& y) {
        if (pf[3 - (--y)][--x] == " ")
        {
            pf[3 - (--y)][--x] = playerMove.symbol;
            cout << "Значение установленно" << endl;
            return true;
        }
        else {
            cout << "Поле занято" << endl;
            return false;
        }
    }

};

int main()
{
    setlocale(LC_ALL, "RU");
    PlayingField pf;
    pf.startGame();
    return 0;
}