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
    int points;
    int size;
    int matrix[maxSize][maxSize];
    QList<int> matches[maxSize];
};

#endif // GAME_H
