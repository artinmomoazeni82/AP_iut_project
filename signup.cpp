#include "signup.h"
#include "ui_signup.h"
#include "MainWindow.h"
#include "user.h"
#include <QStyleOption>
#include <QPainter>
#include <QLabel>
#include <QFile>
#include <QMessageBox>
#define Login ":/Login/Login2.jpg"

SignUp::SignUp(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::SignUp)
{
    ui->setupUi(this);

    setWindowFlag(Qt::FramelessWindowHint);
    this->resize(550,400);

    QPixmap bkgnd(Login);
    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Window, bkgnd);
    this->setPalette(palette);

    ui->lineEdit_UserName->setStyleSheet("QLineEdit { border-radius: 10px;background-color: rgb(167, 151, 200); }");
    ui->lineEdit_Password->setStyleSheet("QLineEdit { border-radius: 10px;background-color: rgb(167, 151, 200); }");
    ui->lineEdit_FirstName->setStyleSheet("QLineEdit { border-radius: 10px;background-color: rgb(167, 151, 200); }");
    ui->lineEdit_LastName->setStyleSheet("QLineEdit { border-radius: 10px;background-color: rgb(167, 151, 200); }");
    ui->lineEdit_Gender->setStyleSheet("QLineEdit { border-radius: 10px;background-color: rgb(167, 151, 200); }");
    ui->lineEdit_Age->setStyleSheet("QLineEdit { border-radius: 10px;background-color: rgb(167, 151, 200); }");
    ui->lineEdit_PhoneNumber->setStyleSheet("QLineEdit { border-radius: 10px;background-color: rgb(167, 151, 200); }");

    ui->pushButton_Ok->setStyleSheet("QPushButton{"
                                  "font-size: 25px;"
                                  "color: Blue;"
                                  "border-style: solid;"
                                  "border-width:2px;"
                                  "border-radius: 10px;"
                                  "background-color: Black;"
                                  "border-color: green;"
                                     "font: bold 20px}");
}
SignUp::~SignUp()
{
    delete ui;
}

void SignUp::on_pushButton_Back_clicked()
{
    MainWindow *s_in = new MainWindow();
    s_in->show();
    QWidget::close();
}


void SignUp::on_pushButton_Ok_clicked()
{
    QString str_password = ui->lineEdit_Password->text();
    int a1 = 0, a2 = 0, a3 = 0;
    for(int i = 0; i < str_password.length(); i++)
    {
        if(str_password[i] >= 'A' && str_password[i] <= 'Z')
        {
            a1 = 1;
        }
        else if(str_password[i] >= 'a' && str_password[i] <= 'z')
        {
            a2 = 1;
        }
        else if(str_password[i] >= '0' && str_password[i] <= '9')
        {
            a3 = 1;
        }
    }
    if(a1 * a2 * a3 == 0)
    {
        QMessageBox::critical(this,"Erorr!","Please Choose A Stronger Password.");
    }
    else
    {
        QString u_name_ = ui->lineEdit_UserName->text();
        QString pass_ = ui->lineEdit_Password->text();
        QString f_name_ = ui->lineEdit_FirstName->text();
        QString l_name_ = ui->lineEdit_LastName->text();
        QString a_ = ui->lineEdit_Age->text();
        QString gend_ = ui->lineEdit_Gender->text();
        QString p_num_ = ui->lineEdit_PhoneNumber->text();
        dataPerson.Make_Person(u_name_,pass_,f_name_,l_name_,a_,gend_,p_num_);
        ui->lineEdit_UserName->setText("");
        ui->lineEdit_Password->setText("");
        ui->lineEdit_FirstName->setText("");
        ui->lineEdit_LastName->setText("");
        ui->lineEdit_Age->setText("");
        ui->lineEdit_Gender->setText("");
        ui->lineEdit_PhoneNumber->setText("");
        dataPerson.Ofstream();
    }
    MainWindow *s_in = new MainWindow();
    s_in->show();
    QWidget::close();
}

