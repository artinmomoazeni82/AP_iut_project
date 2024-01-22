#ifndef FORGOTPASSWORD_H
#define FORGOTPASSWORD_H

#include <QWidget>

namespace Ui {
class ForgotPassword;
}

class ForgotPassword : public QWidget
{
    Q_OBJECT

public:
    explicit ForgotPassword(QWidget *parent = nullptr);
    ~ForgotPassword();

private slots:
    void on_pushButton_Back_clicked();

    void on_pushButton_Ok_clicked();

private:
    Ui::ForgotPassword *ui;
};

#endif // FORGOTPASSWORD_H
