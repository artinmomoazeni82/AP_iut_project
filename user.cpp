#include <vector>
#include <QString>
#include <user.h>
#include <QDebug>
#include <QMessageBox>
using namespace std;


Data dataPerson;
QString login_;
QString password_;

User::User(QString a, QString b, QString c, QString d, QString e, QString f, QString g){
    user_name = a;
    password = b;
    first_name = c;
    last_name = d;
    age = e;
    gender = f;
    phone_number = g;
}

void Data::Make_Person(QString user_name,QString password,QString first_name,QString last_name,QString age,QString gender, QString phone_number){
    vec.push_back(User{user_name, password,first_name, last_name, age, gender, phone_number});
}

int Data::Search(QString user_name_, QString password_){
    for(auto it = vec.begin(); it!= vec.end(); it++){
        if((((*it).user_name)==user_name_)&&(((*it).password)==password_)){
            return 1;
        }
    }
    return 0;
}

QString Data::Find(QString user_name_){
    for(auto it = vec.begin(); it!= vec.end(); it++){
        if(((*it).user_name)==user_name_){
            return user_name_;
        }
    }
    return "nothing";
}

void Data::GetAllPass(vector<QString> & new_vec){
    for(auto it = vec.begin(); it!= vec.end(); it++){
        new_vec.push_back((it)->password);
    }
}

void Data::Ofstream(){
    QFile mFile("F:/project/untitled2/User.txt");
    if(!mFile.open(QFile::WriteOnly | QFile::Text | QIODevice::Append)){
        //QMessageBox::information(this, "Error", " Path not correct");
        return;
    }

    QTextStream stream(&mFile);

    for(auto it = vec.begin(); it!= vec.end(); it++){
        if (it != (vec.end()-1)){
            stream << it->user_name << " " << it->password << " " << it->first_name << " " << it->last_name << " " << it->age << " " << it->gender << " " << it->phone_number << "\n";
        }
        else{
            stream << it->user_name << " " << it->password << " " << it->first_name << " " << it->last_name << " " << it->age << " " << it->gender << " " << it->phone_number << "\n";
        }
    }

    mFile.close();
}

QString Data::GetPassword(QString user_name_){
    for(auto it = vec.begin(); it!= vec.end(); it++){
        if(((*it).user_name)==user_name_){
            return it->password;
        }
    }
}
