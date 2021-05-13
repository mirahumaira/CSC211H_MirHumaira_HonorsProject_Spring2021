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

#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent, Qt::FramelessWindowHint), ui(new Ui::MainWindow){
    ui->setupUi(this);

    try{
        QPixmap bkgnd(directory.getBackgroundImageDark());

        if (bkgnd.isNull()) throw std::runtime_error ("MainWindow.cpp -- Error: Cannot find image. Check media directory and path.");

        bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
        QPalette palette;
        palette.setBrush(QPalette::Background, bkgnd);
        this->setPalette(palette);
    }
    catch (std::runtime_error &QImage){
        std::cerr << QImage.what() << std::endl;
    }

    ui->label_5->setTextInteractionFlags(Qt::LinksAccessibleByMouse);
    ui->label_5->setOpenExternalLinks((true));
    ui->label_5->setTextFormat(Qt::RichText);
    ui->label_5->setText("<a href=\"http://boundaries.beta.nyc\"> To find your Community District, Click Here. </a>");
}

void MainWindow::on_pushButton_6_clicked(){
    Brooklyn brooklynLocations;
    brooklynLocations.setModal(true);

    brooklynLocations.sortingLocations();
    brooklynLocations.makeSortedFile();
    brooklynLocations.setTextBrowserInfo();

    brooklynLocations.exec();
}

void MainWindow::on_pushButton_7_clicked(){
    Bronx bronxLocations;
    bronxLocations.setModal(true);

    bronxLocations.sortingLocations();
    bronxLocations.makeSortedFile();
    bronxLocations.setTextBrowserInfo();

    bronxLocations.exec();
}

void MainWindow::on_pushButton_8_clicked(){
    queens queensLocations;
    queensLocations.setModal(true);

    queensLocations.sortingLocations();
    queensLocations.makeSortedFile();
    queensLocations.setTextBrowserInfo();

    queensLocations.exec();
}

void MainWindow::on_pushButton_9_clicked(){
    Manhattan manhattanLocations;
    manhattanLocations.setModal(true);

    manhattanLocations.sortingLocations();
    manhattanLocations.makeSortedFile();
    manhattanLocations.setTextBrowserInfo();

    manhattanLocations.exec();
}

void MainWindow::on_pushButton_10_clicked(){
    StatenIsland statenIslandLocations;
    statenIslandLocations.setModal(true);

    statenIslandLocations.sortingLocations();
    statenIslandLocations.makeSortedFile();
    statenIslandLocations.setTextBrowserInfo();

    statenIslandLocations.exec();
}

void MainWindow::on_pushButton_clicked(){
    About aboutUs;
    aboutUs.setModal(true);
    aboutUs.exec();
}

void MainWindow::on_pushButton_3_clicked(){
    Obesity obesityInfo;
    obesityInfo.setModal(true);
    obesityInfo.exec();
}

void MainWindow::on_pushButton_4_clicked(){
    Diabetes diabetesInfo;
    diabetesInfo.setModal(true);
    diabetesInfo.exec();
}

void MainWindow::on_pushButton_5_clicked(){
    Hypertension hypertensionInfo;
    hypertensionInfo.setModal(true);
    hypertensionInfo.exec();
}

void MainWindow::on_pushButton_2_clicked(){
    exit(0);
}

void MainWindow::mousePressEvent(QMouseEvent *evt){
    oldPos = evt->globalPos();
}

void MainWindow::mouseMoveEvent(QMouseEvent *evt){
    const QPoint delta = evt->globalPos() - oldPos;
    move(x()+delta.x(), y()+delta.y());
    oldPos = evt->globalPos();
}

MainWindow::~MainWindow(){
    delete ui;
}
