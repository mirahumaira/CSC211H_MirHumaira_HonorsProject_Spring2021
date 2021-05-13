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

#include "directory.h"

Directory::Directory(){  }

QString Directory::getSortedFileDirectory()  { return sortedFileDirectory; }

QString Directory::getBronxMasterFileDirectory()  { return bronxMasterFileDirectory; }
QString Directory::getBrooklynMasterFileDirectory()  { return brooklynMasterFileDirectory; }
QString Directory::getManhattanMasterFileDirectory()  { return manhattanMasterFileDirectory; }
QString Directory::getQueensMasterFileDirectory()  { return queensMasterFileDirectory; }
QString Directory::getStatenIslandMasterFileDirectory()  { return statenIslandMasterFileDirectory; }

QString Directory::getBoroughBackgroundImageDirectory()  { return boroughBackgroundImageDirectory; }
QString Directory::getBackgroundImageDark()  { return backgroundImageDark; }

QString Directory::getdiabetesBackgroundDirectory1()   { return diabetesBackgroundDirectory1; }
QString Directory::getdiabetesBackgroundDirectory2()  {  return diabetesBackgroundDirectory2; }
QString Directory::getObesityBackgroundDirectory()  {  return obesityBackgroundDirectory; }
QString Directory::getHypertensionBackgroundDirectory()  { return hypertensionBackgroundDirectory; }
