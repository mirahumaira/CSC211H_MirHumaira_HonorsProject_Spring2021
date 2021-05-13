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

#ifndef HYPERTENSION_H
#define HYPERTENSION_H

#include <QtGui>
#include <QDialog>
#include <iostream>
#include <exception>
#include "directory.h"

namespace Ui { class Hypertension; }

class Hypertension : public QDialog{
    Q_OBJECT

public:
    explicit Hypertension(QWidget *parent = nullptr);
    ~Hypertension();

private slots:
    void on_pushButton_2_clicked();

private:
    Ui::Hypertension *ui;
    QPoint oldPos;
    Directory directory;

protected:
    void mousePressEvent(QMouseEvent *evt);
    void mouseMoveEvent(QMouseEvent *evt);
};

#endif // HYPERTENSION_H
