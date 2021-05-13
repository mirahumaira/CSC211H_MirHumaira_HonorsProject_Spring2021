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

#ifndef BRONX_H
#define BRONX_H

#include <QDialog>
#include <QTextStream>
#include <QStringList>
#include <QFile>
#include <QDebug>
#include <QVector>
#include <QtGui>
#include <exception>
#include <iostream>
#include "borough.h"
#include "directory.h"



namespace Ui { class Bronx;  }

class Bronx : public QDialog, protected Borough{
    Q_OBJECT

public:
    explicit Bronx(QWidget *parent = nullptr);
    void readCSCRowItems(QTextStream &in);
    void sortingLocations();
    void swap(int&,int&);
    void swap(QString&, QString&);
    void makeSortedFile();
    void setTextBrowserInfo();
    ~Bronx();


private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::Bronx *ui;
    QPoint oldPos;
    Directory directory;
    QVector <QString> row;
    QVector <QString> marketName;
    QVector <QString> marketLocation;
    QVector <QString> communityDistrict;
    QVector <int> communityDistrictInt;

protected:
    void mousePressEvent(QMouseEvent *evt);
    void mouseMoveEvent(QMouseEvent *evt);
};

#endif // BRONX_H
