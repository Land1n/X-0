#include <iostream>
#include <string>

using namespace std;



struct Player {
    string name;
    string symbol;
    int nWin;
};


class PlayingField {
private:
    Player player1;
    Player player2;
    Player& playerMove;
    string pf[3][3] = {
        {" "," "," "},
        {" "," "," "},
        {" "," "," "},
    };

public:

    PlayingField() : playerMove(player1) {
        player1.name = "player1";
        player1.symbol = "x";
        player1.nWin = 0;

        player2.name = "player2";
        player2.symbol = "0";
        player2.nWin = 0;
        startGame();
    }



    void startGame() {
        setStartingSetting();
        while (true)
        {
            try {
                int x = 0, y = 0;
                cout << "Позиция x: ";
                cin >> x;
                cout << "Позиция y: ";
                cin >> y;

                bool isPositionX = x >= 0 && x <= 3;
                bool isPositionY = y >= 0 && y <= 3;


                if (isPositionX && isPositionY)
                {
                    cout << "Все ок!";
                }
                else if (x == -1 || y == -1)
                {
                    break;
                }
                else {
                    cout << "Значения вне допустимого диапозона!\n\n";
                    continue;
                }
            }
            catch (exception e) {
                cout << e.what();
                break;
            }
        }
    }

    void setStartingSetting() {
        string namePlayer1, namePlayer2;
        cout << "Игра X&0\n\n";
        cout << "Сделал: Ландарев Иван\nГруппа: 4104\n";
        cout << "Чтобы прекратить игру, в поля позиции введити '-1'\n\n";
        cout << "Начинает игрок 1\n";
        cout << "Введите имя 1 игрока: ";
        cin >> namePlayer1;
        player1.name = namePlayer1;
        cout << "Введите имя 2 игрока: ";
        cin >> namePlayer2;
        player2.name = namePlayer2;
        cout << "Игра начинается. Удачи\n\n";
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

    }

    void setPositionOnPlayingField(int x, int y) {
        if (pf[x][y] == " ") {
            pf[x][y] = playerMove.symbol;
        }
        else {
            cout << "Данное поле занято" << endl;
        }
    }

};

int main()
{
    setlocale(LC_ALL, "RU");
    
    PlayingField pf;
    return 0;
}