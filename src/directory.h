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

#ifndef DIRECTORY_H
#define DIRECTORY_H
#include <QString>


class Directory{

private:
   
    // File directory. "Your directory/Files/Sorted_Farmers_Market.txt"
    const QString sortedFileDirectory = "C:/Users/afrah/OneDrive/Documents/Food4All/Files/Sorted_Farmers_Market.txt";
    
   // File directory. "Your directory\\Files\\Farmers_Market_Bronx.txt"
    const QString bronxMasterFileDirectory = "C:\\Users\\afrah\\OneDrive\\Documents\\Food4All\\Files\\Farmers_Market_Bronx.txt";
   // File directory. "Your directory\\Files\\Farmers_Market_Brooklyn.txt"
    const QString brooklynMasterFileDirectory = "C:\\Users\\afrah\\OneDrive\\Documents\\Food4All\\Files\\Farmers_Market_Brooklyn.txt";
   // File directory. "Your directory\\Files\\Farmers_Market_Manhattan.txt"
    const QString manhattanMasterFileDirectory = "C:\\Users\\afrah\\OneDrive\\Documents\\Food4All\\Files\\Farmers_Market_Manhattan.txt";
   // File directory. "Your directory\\Files\\Farmers_Market_Queens.txt"
    const QString queensMasterFileDirectory = "C:\\Users\\afrah\\OneDrive\\Documents\\Food4All\\Files\\Farmers_Market_Queens.txt";
   // File directory. "Your directory\\Files\\Farmers_Market_StatenIsland.txt"
    const QString statenIslandMasterFileDirectory = "C:\\Users\\afrah\\OneDrive\\Documents\\Food4All\\Files\\Farmers_Market_StatenIsland.txt";

    // Image directory. "Your directory/media/BackgroudBorough.jpg"
    const QString boroughBackgroundImageDirectory = "C:/Users/afrah/OneDrive/Documents/Food4All/media/BackgroudBorough.jpg";
   // Image directory. "Your directory/media/Backgroud-img.jpg"
    const QString backgroundImageDark = "C:/Users/afrah/OneDrive/Documents/Food4All/media/Backgroud-img.jpg";
   // Image directory. "Your directory/media/prediabetes1.jpg"
    const QString diabetesBackgroundDirectory1 = "C:/Users/afrah/OneDrive/Documents/Food4All/media/prediabetes1.jpg";
   // Image directory. "Your directory/media/diabetes2.jpg"
    const QString diabetesBackgroundDirectory2 = "C:/Users/afrah/OneDrive/Documents/Food4All/media/diabetes2.jpg";
   // Image directory. "Your directory/media/Backgroud-img - Obesity.jpg"
    const QString obesityBackgroundDirectory = "C:/Users/afrah/OneDrive/Documents/Food4All/media/Backgroud-img - Obesity.jpg";
   // Image directory. "Your directory/media/Hypertension1.jpg"
    const QString hypertensionBackgroundDirectory = "C:/Users/afrah/OneDrive/Documents/Food4All/media/Hypertension1.jpg";


public:
    Directory();

    QString getSortedFileDirectory();

    QString getBronxMasterFileDirectory();
    QString getBrooklynMasterFileDirectory();
    QString getManhattanMasterFileDirectory();
    QString getQueensMasterFileDirectory();
    QString getStatenIslandMasterFileDirectory();

    QString getBoroughBackgroundImageDirectory();
    QString getBackgroundImageDark();

    QString getdiabetesBackgroundDirectory1 ();
    QString getdiabetesBackgroundDirectory2 ();
    QString getObesityBackgroundDirectory();
    QString getHypertensionBackgroundDirectory();

};

#endif // DIRECTORY_H
