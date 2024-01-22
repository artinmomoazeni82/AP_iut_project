#ifndef INORG_H
#define INORG_H

#include <QWidget>

namespace Ui {
class inOrg;
}

class inOrg : public QWidget
{
    Q_OBJECT

public:
    explicit inOrg(QWidget *parent = nullptr);
    ~inOrg();

signals:
    void ItemAdded(QString item);

private slots:
    void on_pushButton_ok_clicked();

private:
    Ui::inOrg *ui;
};

#endif // INORG_H
