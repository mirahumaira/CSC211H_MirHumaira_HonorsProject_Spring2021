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

#include "statenisland.h"
#include "ui_statenisland.h"


StatenIsland::StatenIsland(QWidget *parent) : QDialog(parent, Qt::FramelessWindowHint), ui(new Ui::StatenIsland){
    ui->setupUi(this);

    try{
        QPixmap bkgnd(directory.getBoroughBackgroundImageDirectory());              // Setting background image.

        if (bkgnd.isNull()) throw std::runtime_error ("StatenIsland.cpp/StatenIsland() --Error: Cannot find image. Check media directory and path.");

        bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
        QPalette palette;
        palette.setBrush(QPalette::Background, bkgnd);
        this->setPalette(palette);
    }
    catch (std::runtime_error &QImage){
        std::cerr << QImage.what() << std::endl;
    }

    try{
        QFile csv(directory.getStatenIslandMasterFileDirectory());               // Reading the lines from Farmers_Market_Bronx
        csv.open(QFile::ReadOnly | QFile::Text);

        if (!csv.isOpen()) throw std::runtime_error("StatenIsland.cpp/StatenIsland() -- Runtime Error: Error opening master file! Check files directory.");

        QTextStream in(&csv);
        readCSCRowItems(in);                                                    // Calling the readCSCRowItems with the lines read from the file.

        csv.close();
    }
    catch(std::runtime_error &Qexcept1){
        std::cerr << Qexcept1.what();
    }
}

void StatenIsland::readCSCRowItems(QTextStream &in){

    try{
        while (!in.atEnd()){
            QString sline = in.readLine();                            // Saving in a Qstring called "line".
            setline(sline);

            if (sline.isEmpty())  throw  std::runtime_error ( "Error: Line is empty!");

            QStringList chunk;
            chunk.append(getline().split(','));                       // Splitting the "line" into chunks by comma as a deliminator.
            row = QVector<QString>::fromList(chunk);                  // Saving the chunks into a QVector array called row.

            QVector <QString> *locationPtr = new QVector <QString>;   // Creating a QVector locationPtr pointer of QStrings to save borough locations
                                                                      // Borough locations are dummy data that are not used further in this program.
                                                                      // So, this pointer saves them for ease of file I/O and then deletes the data
            locationPtr->push_back(row[0]);
            marketName.push_back(row[1]);
            marketLocation.push_back(row[2]);
            communityDistrict.push_back(row[3]);

            row.clear();
            delete locationPtr;
            locationPtr = nullptr;                                    // Memory leak avoided.
        }
    }
    catch (std::runtime_error &Qexcept1){
        std::cerr << Qexcept1.what() << std::endl;
    }
}

void StatenIsland::sortingLocations(){

    for (int i=0; i < communityDistrict.size(); i++){
        communityDistrictInt.append(communityDistrict[i].toInt());                  // Convert QString to Int for sorting.
        if (communityDistrictInt[i] == 0){
            std::cerr << "StatenIsland Master File -- Error: Wrong input type for community district in file. Check again." << std::endl;      // Input Validation
        }
    }

    int maxElem;
    int index;
    for (maxElem = communityDistrictInt.size() - 1; maxElem > 0; maxElem--) {            // Sorting algorithm was used.
        for (index = 0; index < maxElem; index++) {
            if (communityDistrictInt[index] > communityDistrictInt[index + 1]) {
                swap(communityDistrictInt[index], communityDistrictInt[index + 1]);
                swap(marketLocation[index], marketLocation[index+1]);
                swap(marketName[index], marketName[index+1]);
            }
        }
    }
}

void StatenIsland::swap(int& a, int& b){                             // Swap the ints.
    int temp = a;
    a = b;
    b = temp;
}

void StatenIsland::swap(QString& a, QString& b){                    // Swap the QStrings.
    QString temp = a;
    a = b;
    b = temp;
}

void StatenIsland::makeSortedFile(){

    try{
        QFile file(directory.getSortedFileDirectory());            // Write a Sorted_Farmers_Market file
        file.open(QIODevice::WriteOnly | QIODevice::Text);

        if (!file.isOpen()) throw std::runtime_error("StatenIsland.cpp/makeSortedFile() -- Runtime Error: Error opening sorted file! Check src directory.");

        QTextStream outfile(&file);

        for (int i=0; i< communityDistrictInt.size(); i++){                                  // All sorted info is set in ascending order.
            outfile << communityDistrictInt[i] << '\n';
            outfile << marketName[i] << '\n';
            outfile << marketLocation[i] << '\n';
        }
        file.flush();
        file.close();
    }
    catch(std::runtime_error &Qexcept3){
        std::cerr << Qexcept3.what() << std::endl;
    }
}

void StatenIsland::setTextBrowserInfo(){

    communityDistrict.clear();
    marketName.clear();                                                             // All the QVectors are cleared (emptied).
    marketLocation.clear();

    try{
        QFile fileRead(directory.getSortedFileDirectory());                        // Reading the sorted file
        fileRead.open(QIODevice::ReadWrite | QIODevice::Text);

        if (!fileRead.isOpen()) throw std::runtime_error("StatenIsland.cpp/setTextBrowserInfo() -- Runtime Error: Error opening sorted file! Check src directory.");

        QTextStream readFile(&fileRead);

        while (!readFile.atEnd()){
            communityDistrict.push_back(readFile.readLine());                     // Rewriting the sorted info in each QVectors.
            marketName.push_back(readFile.readLine());                            // This step is important for the on_pushButton clicked() event.
            marketLocation.push_back(readFile.readLine());

        }
        fileRead.close();

        QString   empty = "-";

        if(marketLocation.size()< 13){                                           // If there aren't 13 infos to display, set "-" to textbrowser.
            while (marketLocation.size() != 14){
                communityDistrict.push_back(empty);
                marketName.push_back(empty);
                marketLocation.push_back(empty);
            }
        }

        ui->DisText1->setText(communityDistrict[0]);
        ui->NameText1->setText(marketName[0]);
        ui->LocText1->setText(marketLocation[0]);                                 // Displaying the info in textbrowsers.

        ui->DisText2->setText(communityDistrict[1]);
        ui->NameText2->setText(marketName[1]);
        ui->LocText2->setText(marketLocation[1]);

        ui->DisText3->setText(communityDistrict[2]);
        ui->NameText3->setText(marketName[2]);
        ui->LocText3->setText(marketLocation[2]);

        ui->DisText4->setText(communityDistrict[3]);
        ui->NameText4->setText(marketName[3]);
        ui->LocText4->setText(marketLocation[3]);

        ui->DisText5->setText(communityDistrict[4]);
        ui->NameText5->setText(marketName[4]);
        ui->LocText5->setText(marketLocation[4]);

        ui->DisText6->setText(communityDistrict[5]);
        ui->NameText6->setText(marketName[5]);
        ui->LocText6->setText(marketLocation[5]);

        ui->DisText7->setText(communityDistrict[6]);
        ui->NameText7->setText(marketName[6]);
        ui->LocText7->setText(marketLocation[6]);

        ui->DisText8->setText(communityDistrict[7]);
        ui->NameText8->setText(marketName[7]);
        ui->LocText8->setText(marketLocation[7]);

        ui->DisText9->setText(communityDistrict[8]);
        ui->NameText9->setText(marketName[8]);
        ui->LocText9->setText(marketLocation[8]);

        ui->DisText10->setText(communityDistrict[9]);
        ui->NameText10->setText(marketName[9]);
        ui->LocText10->setText(marketLocation[9]);

        ui->DisText11->setText(communityDistrict[10]);
        ui->NameText11->setText(marketName[10]);
        ui->LocText11->setText(marketLocation[10]);

        ui->DisText12->setText(communityDistrict[11]);
        ui->NameText12->setText(marketName[11]);
        ui->LocText12->setText(marketLocation[11]);

        ui->DisText13->setText(communityDistrict[12]);
        ui->NameText13->setText(marketName[12]);
        ui->LocText13->setText(marketLocation[12]);
    }
    catch (std::runtime_error &Qexcept2){
        std::cerr << Qexcept2.what() << std::endl;
    }
}

// https://stackoverflow.com/questions/11314429/select-moving-qwidget-in-the-screen
void StatenIsland::mousePressEvent(QMouseEvent *evt){
    oldPos = evt->globalPos();                                                  // Making diagloue frame movable.
}

void StatenIsland::mouseMoveEvent(QMouseEvent *evt){
    const QPoint delta = evt->globalPos() - oldPos;
    move(x()+delta.x(), y()+delta.y());
    oldPos = evt->globalPos();
}

StatenIsland::~StatenIsland(){
    delete ui;
}

void StatenIsland::on_pushButton_2_clicked(){
    hide();                                                            // Hides the dialogue.
}

