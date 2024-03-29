#ifndef SIGNUP_H
#define SIGNUP_H

#include <QWidget>

namespace Ui {
class SignUp;
}

class SignUp : public QWidget
{
    Q_OBJECT

public:
    explicit SignUp(QWidget *parent = nullptr);
    ~SignUp();

private slots:
    void on_pushButton_Back_clicked();

    void on_pushButton_Ok_clicked();

private:
    Ui::SignUp *ui;
};

#endif // SIGNUP_H
