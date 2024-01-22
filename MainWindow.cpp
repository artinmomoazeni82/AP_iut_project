#include "MainWindow.h"
#include "ui_MainWindow.h"
#include "signup.h"
#include "forgotpassword.h"
#include "user.h"
#include <QStyleOption>
#include <QPainter>
#include <QLabel>
#include <QFile>
#include <QByteArray>
#include <QMessageBox>
#include <QString>
#include <QDebug>
#define Login ":/Login/Login2.jpg"
#include "organization.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    setWindowFlag(Qt::FramelessWindowHint);
    this->resize(500,400);

    QPixmap bkgnd(Login);
    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Window, bkgnd);
    this->setPalette(palette);

    ui->pushButton_Signup->setStyleSheet("QPushButton{"
                                         "font-size: 10px;"
                                         "color: red;"
                                         "background-color: rgba(255, 255, 255, 0);}");

    ui->pushButton_Forgotpassword->setStyleSheet("QPushButton{"
                                                 "font-size: 10px;"
                                                 "color: red;"
                                                 "background-color: rgba(255, 255, 255, 0);}");

    ui->pushButton_SignIn->setStyleSheet("QPushButton{"
                                  "font-size: 25px;"
                                  "color: Blue;"
                                  "border-style: solid;"
                                  "border-width:2px;"
                                  "border-radius: 10px;"
                                  "background-color: Black;"
                                  "border-color: green;"
                                  "font: bold 20px}");

    ui->lineEdit_UserName->setStyleSheet("QLineEdit { border-radius: 15px; }");
    ui->lineEdit_Password->setStyleSheet("QLineEdit { border-radius: 15px; }");
}
MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_Signup_clicked()
{
    SignUp *s_up = new SignUp();
    s_up->show();
    QWidget::close();
}

void MainWindow::on_pushButton_SignIn_clicked()
{
    QString str_username = ui->lineEdit_UserName->text();
    QString str_password = ui->lineEdit_Password->text();

    if(str_username == "")
    {
        QMessageBox::critical(this,"Erorr!","Please Enter UserName.");
    }
    else if(str_password == "")
    {
        QMessageBox::critical(this,"Erorr!","Please Enter Password.");
    }
    else {
        QString str= "F:/project/untitled2/User.txt";
        QFile file(str);

        if (!file.open(QFile::ReadOnly | QFile::Text)){
            QMessageBox::information(this, "Error", " Path not correct");
            return;
        }
        QTextStream stream(&file);
        QString line;
        while (!stream.atEnd()){
            line = stream.readAll();
            if(line.contains(ui->lineEdit_Password->text()))
            {
                Organization * org_widget = new Organization();
                org_widget->show();
                QWidget::close();
            }
            else
            {
                QMessageBox::warning(this,"Error!","UserName Or Password Is Wrong");
            }
        }
        file.close();
    }

}

void MainWindow::on_pushButton_Forgotpassword_clicked()
{
    ForgotPassword * s_Forgot = new ForgotPassword();
    s_Forgot->show();
    QWidget::close();
}

