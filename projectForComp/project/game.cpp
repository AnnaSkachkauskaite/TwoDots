#include "game.h"

Game::Game() :
    size(8)
{
    QTime midnight(0,0,0);
    qsrand(midnight.secsTo(QTime::currentTime()));
    for (int i = 0; i < size; ++i)
        for (int j = 0; j < size; ++j)
            matrix[i][j] = rand() % 6;
}

int Game::getPiece(int i, int j)
{
    return matrix[i][j];
}

void Game::lookForMatches()
{
    QList<int> tmp[maxSize];

}
