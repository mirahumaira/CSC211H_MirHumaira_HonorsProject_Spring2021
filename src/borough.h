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

#ifndef BOROUGH_H
#define BOROUGH_H

#include <QString>
#include <QTextStream>

class Borough{

private:
    QString line;

public:
    virtual void sortingLocations() =0;
    virtual void swap(int&, int&)=0;
    virtual void swap(QString&, QString&)=0;
    virtual void makeSortedFile()=0;
    virtual void setTextBrowserInfo()=0;

protected:
    void setline(QString sline)  { line = sline; }
    QString getline()  { return line; }

};

#endif // BOROUGH_H
