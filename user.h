#ifndef USER_H
#define USER_H
#include <vector>
#include <QString>
#include <QFile>
#include <QTextStream>
#include <QMessageBox>
#include <QLocale>


using namespace std;
class User
{
public:
    QString user_name = "";
    QString password ="";
    QString first_name ="";
    QString last_name = "";
    QString age = "";
    QString gender = "";
    QString phone_number = "";

    User(QString, QString, QString, QString, QString, QString, QString);
};

class Data
{
public:
    vector<User>vec ={};
    void Make_Person(QString ,QString ,QString ,QString ,QString ,QString, QString);
    int Search(QString , QString );
    QString Find(QString );
    void GetAllPass(vector<QString> & new_vec);
    void Ofstream();
    QString GetPassword(QString);
};
extern Data dataPerson;
extern QString user_name_;
extern QString password_;

#endif // USER_H
