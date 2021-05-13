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

#include "obesity.h"
#include "ui_obesity.h"

Obesity::Obesity(QWidget *parent) :QDialog(parent, Qt::FramelessWindowHint), ui(new Ui::Obesity){
    ui->setupUi(this);

    try{
        QPixmap bkgnd(directory.getObesityBackgroundDirectory());

        if (bkgnd.isNull()) throw std::runtime_error ("Obesity.cpp -- Error: Cannot find image. Check media directory and path.");

        bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
        QPalette palette;
        palette.setBrush(QPalette::Background, bkgnd);
        this->setPalette(palette);
    }
    catch (std::runtime_error &QImage){
        std::cerr << QImage.what() << std::endl;
    }

    ui->label_2->setTextInteractionFlags(Qt::LinksAccessibleByMouse);
    ui->label_2->setOpenExternalLinks((true));
    ui->label_2->setTextFormat(Qt::RichText);
    ui->label_2->setText("<a href=\"http://www.cdc.gov/obesity/about-obesity/index.html\"> Source: CDC website </a>");
}

void Obesity::mousePressEvent(QMouseEvent *evt){
    oldPos = evt->globalPos();
}

void Obesity::mouseMoveEvent(QMouseEvent *evt){
    const QPoint delta = evt->globalPos() - oldPos;
    move(x()+delta.x(), y()+delta.y());
    oldPos = evt->globalPos();
}

Obesity::~Obesity(){
    delete ui;
}

void Obesity::on_pushButton_2_clicked(){
    hide();
}

