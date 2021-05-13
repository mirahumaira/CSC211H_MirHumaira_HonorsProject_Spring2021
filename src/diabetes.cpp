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

#include "diabetes.h"
#include "ui_diabetes.h"

Diabetes::Diabetes(QWidget *parent) : QDialog(parent, Qt::FramelessWindowHint), ui(new Ui::Diabetes){
    ui->setupUi(this);

    try{
        QPixmap bkgnd(directory.getBackgroundImageDark());    // Setting imag background

        if (bkgnd.isNull()) throw std::runtime_error ("Diabetes.cpp/Diabetes() -- Error: Cannot find image. Check media directory and path.");

        bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
        QPalette palette;
        palette.setBrush(QPalette::Background, bkgnd);
        this->setPalette(palette);
    }
    catch (std::runtime_error &QImage){
        std::cerr << QImage.what() << std::endl;
    }

    ui->label_2->setScaledContents(true);
    ui->label_2->setPixmap(QPixmap(directory.getdiabetesBackgroundDirectory1()));     // Setting image in label.

    ui->label_3->setScaledContents(true);
    ui->label_3->setPixmap(QPixmap(directory.getdiabetesBackgroundDirectory2()));

    ui->label_4->setTextInteractionFlags(Qt::LinksAccessibleByMouse);     // Setting url
    ui->label_4->setOpenExternalLinks((true));
    ui->label_4->setTextFormat(Qt::RichText);
    ui->label_4->setText("<a href=\"http://www.cdc.gov/diabetes/basics/index.html\"> Source: CDC website </a>");
}

// https://stackoverflow.com/questions/11314429/select-moving-qwidget-in-the-screen
void Diabetes::mousePressEvent(QMouseEvent *evt){            // Making frame movable.
    oldPos = evt->globalPos();
}

void Diabetes::mouseMoveEvent(QMouseEvent *evt){
    const QPoint delta = evt->globalPos() - oldPos;
    move(x()+delta.x(), y()+delta.y());
    oldPos = evt->globalPos();
}

Diabetes::~Diabetes()
{
    delete ui;
}

void Diabetes::on_pushButton_2_clicked()
{
    hide();
}

