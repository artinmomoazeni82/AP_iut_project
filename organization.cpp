#include "organization.h"
#include "ui_organization.h"
#include "inorg.h"
#include <QPixmap>
#define ORG ":/Login/Login19.png"

Organization::Organization(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Organization)
{
    ui->setupUi(this);

    setWindowFlag(Qt::FramelessWindowHint);
    this->resize(800,700);

    QPixmap bkgnd(ORG);
    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Window, bkgnd);
    this->setPalette(palette);
}

Organization::~Organization()
{
    delete ui;
}


void Organization::on_pushButton_add_clicked()
{
    inOrg * org_widget = new inOrg();
    org_widget->show();
    //QWidget::close();

    if(num == 0)
    {
        add_org = new QPushButton*[100];
        for(int i = 0; i < 100; i++)
        {
            add_org[i] = new QPushButton(this);
            add_org[i]->setStyleSheet("QPushButton{"
                                   "font-size: 10px;"
                                   "color: white;"
                                   "border-style: solid;"
                                   "border-width:2px;"
                                   "border-radius: 10px;"
                                   "background-color: black;"
                                   "border-color: black;"
                                   "font: 20px}");
        }
    }
    add_org[num]->resize(92,36);
    add_org[num]->move(_move,_move2);
    add_org[num]->show();
    num++;
    _move += 100;
    if (_move >=700){
        _move = 140;
        _move2 += 40;
    }
    connect(org_widget,SIGNAL(ItemAdded(QString)),this,SLOT(AddItem(QString)));
}


void Organization::on_pushButton_remove_clicked()
{

    //delete(add_org[7]);
}

void Organization::AddItem(QString item)
{
    add_org[num -1]->setText(item);
}

