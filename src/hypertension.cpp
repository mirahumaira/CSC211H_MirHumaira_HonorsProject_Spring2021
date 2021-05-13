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

#include "hypertension.h"
#include "ui_hypertension.h"

Hypertension::Hypertension(QWidget *parent) : QDialog(parent, Qt::FramelessWindowHint), ui(new Ui::Hypertension){
    ui->setupUi(this);

    try{
        QPixmap bkgnd(directory.getBackgroundImageDark());

        if (bkgnd.isNull()) throw std::runtime_error ("Hypertension.cpp -- Error: Cannot find image. Check media directory and path.");

        bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
        QPalette palette;
        palette.setBrush(QPalette::Background, bkgnd);
        this->setPalette(palette);
    }
    catch (std::runtime_error &QImage){
        std::cerr << QImage.what() << std::endl;
    }

    ui->label_2->setScaledContents(true);
    ui->label_2->setPixmap(QPixmap(directory.getHypertensionBackgroundDirectory()));

    ui->label_3->setTextInteractionFlags(Qt::LinksAccessibleByMouse);
    ui->label_3->setOpenExternalLinks((true));
    ui->label_3->setTextFormat(Qt::RichText);
    ui->label_3->setText("<a href=\"http://www.cdc.gov/bloodpressure/about.htm\"> Source: CDC website </a>");
}

void Hypertension::mousePressEvent(QMouseEvent *evt){
    oldPos = evt->globalPos();
}

void Hypertension::mouseMoveEvent(QMouseEvent *evt){
    const QPoint delta = evt->globalPos() - oldPos;
    move(x()+delta.x(), y()+delta.y());
    oldPos = evt->globalPos();
}

Hypertension::~Hypertension(){
    delete ui;
}

void Hypertension::on_pushButton_2_clicked(){
    hide();
}

