#ifndef GAME_H
#define GAME_H

#include <QTime>

const int maxSize = 20;

class Game
{
public:
    Game();
    void setSize();
    int getPiece(int, int);
    void lookForMatches();
    void affectAbove();
    void findAndRemoveMatches();
    bool isMovePossible();
private:
    QList<QPair<int, int>> getMatchHoriz(int row, int col);
    QList<QPair<int, int>> getMatchVert (int row, int col);
    int points;
    int size;
    int matrix[maxSize][maxSize];
    QList<QList<QPair<int, int>>> matches;
    //QList<int*> matches; //хранит массивы из кнопок на удаление
};

#endif // GAME_H
