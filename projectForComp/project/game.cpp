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
    //looking for horizntal i - row, j - col
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size - 2; j++)
        {
            QList<QPair<int,int>> temp = getMatchHoriz(i, j);
            if (temp.size() > 2)
            {
                matches.push_back(temp);
                j += temp.size() - 1;
            }
        }
    }

    //looking for vertical i - col, j - row
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size - 2; j++)
        {
            QList<QPair<int,int>> temp = getMatchVert(i, j);
            if (temp.size() > 2)
            {
                matches.push_back(temp);
                j += temp.size() - 1;
            }
        }
    }

}

void Game::findAndRemoveMatches()
{


}

bool Game::isMovePossible()
{

}

QList<QPair<int, int>> Game::getMatchHoriz(int row, int col)
{
    QList<QPair<int,int>> temp;
    temp.append(qMakePair(col,row));
    for (int i = 1; i + col < size; i++)
    {
        if(matrix[col][row] == matrix[i + col][row])
        {
           temp.append(qMakePair(i + col, row));
        }
        else
        {
            return temp;
        }
    }
    return temp;
}

QList<QPair<int, int> > Game::getMatchVert(int row, int col)
{
    QList<QPair<int,int>> temp;
    temp.append(qMakePair(col, row));
    for (int i = 1; i + row < size; i++)
    {
        if(matrix[col][row] == matrix[col][row + i])
        {
           temp.append(qMakePair(col, row + i));
        }
        else
        {
            return temp;
        }
    }
    return temp;
}
