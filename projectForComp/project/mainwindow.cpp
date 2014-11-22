#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <cmath>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    size(8),
    game()

{
    ui->setupUi(this);
    firstPiece = nullptr;
    createButtons();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::createButtons()
{
    for (int i = 0; i < size; ++i)
        for (int j = 0; j < size; ++j)
        {
            QPushButton *button = new QPushButton;
            button->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
            button->setText(" ");
            ui->gridLayout->addWidget( button, i, j);
            buttonsPosition[button] = qMakePair(i, j);
            button->setText(QString("%1").arg(game.getPiece(i, j)));
            connect(button, &QPushButton::clicked, this, &MainWindow::buttonClick);
        }
}
void MainWindow::buttonClick()
{
    QPushButton *button = dynamic_cast<QPushButton *> (sender());
    int i = buttonsPosition[button].first;
    int j = buttonsPosition[button].second;
    if (firstPiece == nullptr)
    {
        firstPiece = button;
        firstPlace.first = i;
        firstPlace.second = j;
        button->setStyleSheet("color: red");
    }

    else if (firstPiece == button)
    {
        button->setStyleSheet("color: black");
        firstPiece = nullptr;
    }
    else
    {
        if (i == firstPlace.first && abs(j - firstPlace.second) == 1)
        {
            firstPiece->setStyleSheet("color: black");
            makeSwap(firstPiece, button);
            firstPiece = nullptr;

        }
        else if (j == firstPlace.second && abs(i - firstPlace.first) == 1)
        {
            firstPiece->setStyleSheet("color: black");
            makeSwap(firstPiece, button);
            firstPiece = nullptr;
        }
        else
        {
            firstPiece->setStyleSheet("color: black");
            firstPiece = button;
            firstPiece->setStyleSheet("color: red");
        }
    }

}

void MainWindow::makeSwap(QPushButton *first, QPushButton *second)
{
    /*QString tmp;
    tmp = first->text();
    first->setText(second->text());
    second->setText(tmp);*/

}
