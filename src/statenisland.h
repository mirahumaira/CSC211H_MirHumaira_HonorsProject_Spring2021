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

#ifndef STATENISLAND_H
#define STATENISLAND_H

#include <QDialog>
#include <QTextStream>
#include <QStringList>
#include <QFile>
#include <QDebug>
#include <QVector>
#include <QtGui>
#include <iostream>
#include <exception>
#include "directory.h"
#include "borough.h"


namespace Ui {class StatenIsland;}

class StatenIsland : public QDialog, protected Borough{
    Q_OBJECT

public:
    explicit StatenIsland(QWidget *parent = nullptr);
    void readCSCRowItems(QTextStream &in);
    void sortingLocations();
    void swap(int&, int&);
    void swap(QString&, QString&);
    void makeSortedFile();
    void setTextBrowserInfo();

    ~StatenIsland();

private slots:
    void on_pushButton_2_clicked();

private:
    Ui::StatenIsland *ui;
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

#endif // STATENISLAND_H
