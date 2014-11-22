#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QMap>
#include <QPair>
#include <QString>

#include "game.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void makeSwap(QPushButton *, QPushButton *);


private slots:
    ///Slot for generating buttons
    void createButtons();
    ///Slot for processing pushed button
    void buttonClick();

private:
    Ui::MainWindow *ui;
    QMap <QPushButton *, QPair<int, int> > buttonsPosition;
    int size;
    QPushButton *firstPiece;
    QPair <int, int> firstPlace;
    Game game;
};

#endif // MAINWINDOW_H
