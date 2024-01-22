#include "forgotpassword.h"
#include "ui_forgotpassword.h"
#include "MainWindow.h"
#include <QHBoxLayout>
#include <QFile>
#include <QMessageBox>
#include <QString>
#define Login ":/Login/Login2.jpg"


ForgotPassword::ForgotPassword(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::ForgotPassword)
{
    ui->setupUi(this);

    setWindowFlag(Qt::FramelessWindowHint);
    this->resize(400,300);

    QPixmap bkgnd(Login);
    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Window, bkgnd);
    this->setPalette(palette);

    ui->lineEdit_UserName->setStyleSheet("QLineEdit { border-radius: 10px;background-color: rgb(255, 131, 238); }");

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


ForgotPassword::~ForgotPassword()
{
    delete ui;
}

void ForgotPassword::on_pushButton_Back_clicked()
{
    MainWindow *s_in = new MainWindow();
    s_in->show();
    QWidget::close();
}

void ForgotPassword::on_pushButton_Ok_clicked()
{
    QString str= "C:/Qt/untitled2/User.txt";
    QFile file(str);

    if (!file.open(QFile::ReadOnly | QFile::Text)){
        QMessageBox::information(this, "Error", " Path not correct");
        return;
    }
    QTextStream stream(&file);
    QString line;
    while (!stream.atEnd()){
        line = stream.readAll();
        if(line.contains(ui->lineEdit_UserName->text()))
        {
            QString pass;
            int index = line.lastIndexOf(ui->lineEdit_UserName->text());
            QString username = ui->lineEdit_UserName->text();
            for(int i = index + username.length() + 1; i < line.length(); i++)
            {
                pass += line[i];
                if(line[i] == ' ')
                    break;
            }
            QLineEdit * password = new QLineEdit(this);
            password->setText(pass);
            password->resize(181,31);
            password->move(210,220);
            password->setStyleSheet("QLineEdit { border-radius: 10px;background-color: rgb(255, 131, 238); }");
            password->show();

            ui->label_Password->setText("Password");
        }
    }
}

