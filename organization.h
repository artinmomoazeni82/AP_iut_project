#ifndef ORGANIZATION_H
#define ORGANIZATION_H

#include <QWidget>
#include <QPushButton>

namespace Ui {
class Organization;
}

class Organization : public QWidget
{
    Q_OBJECT

public:
    explicit Organization(QWidget *parent = nullptr);
    ~Organization();

private slots:
    void on_pushButton_add_clicked();

    void on_pushButton_remove_clicked();

    void AddItem(QString);

private:
    Ui::Organization *ui;
    QPushButton **add_org;
    int num = 0;
    int _move = 140;
    int _move2 = 140;
};

#endif // ORGANIZATION_H
