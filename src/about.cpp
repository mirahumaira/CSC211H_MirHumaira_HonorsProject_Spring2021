/* Developed by:  Mir Afra Humaira
   Course:        CSC 211H - Advanced Programming Techniques (Honors)
   College:       BMCC, CUNY
   Submitted on:  May 13th, Spring of 2021
   Professor:     Dr. Azhar
   Environment:   QT Framework with MSVC 2019 64-bit compiler
   Language used: C++, HTML
   Topic:         Zero Hunger for Social Good that incorporates all programming
                  techniques taught in class. (Vectors, OOP - Classes, Inheritance,
                  Aggregation, File I/O, Pointers, & Exception Handling.
*/

#include "about.h"
#include "ui_about.h"
#include <QLabel>


About::About(QWidget *parent) : QDialog(parent, Qt::FramelessWindowHint), ui(new Ui::About){
    ui->setupUi(this);

    try{

        QPixmap bkgnd(directory.getBackgroundImageDark());     // Setting background image

        if (bkgnd.isNull()) throw std::runtime_error ("About.cpp -- Error: Cannot find image. Check media directory and path.");

        bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
        QPalette palette;
        palette.setBrush(QPalette::Background, bkgnd);
        this->setPalette(palette);
    }
    catch(std::runtime_error &QImage){
        std::cerr << QImage.what() << std::endl;
    }
}

// https://stackoverflow.com/questions/11314429/select-moving-qwidget-in-the-screen

void About::mousePressEvent(QMouseEvent *evt){             // Making diagloue frame movable.
    oldPos = evt->globalPos();
}

void About::mouseMoveEvent(QMouseEvent *evt){
    const QPoint delta = evt->globalPos() - oldPos;
    move(x()+delta.x(), y()+delta.y());
    oldPos = evt->globalPos();
}

About::~About(){
    delete ui;
}

void About::on_pushButton_2_clicked(){
    hide();
}

