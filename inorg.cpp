#include "inorg.h"
#include "ui_inorg.h"
#include "organization.h"
#define ORG ":/Login/Login19.png"

inOrg::inOrg(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::inOrg)
{
    ui->setupUi(this);

    setWindowFlag(Qt::FramelessWindowHint);
    this->resize(600,400);

    QPixmap bkgnd(ORG);
    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Window, bkgnd);
    this->setPalette(palette);

    ui->lineEdit_nameorg->setStyleSheet("QLineEdit { border-radius: 10px;background-color: rgb(167, 151, 200); }");
}

inOrg::~inOrg()
{
    delete ui;
}

void inOrg::on_pushButton_ok_clicked()
{
    emit ItemAdded(ui->lineEdit_nameorg->text());
    hide();
}

