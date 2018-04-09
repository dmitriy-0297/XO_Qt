#include "name_user.h"
#include "ui_name_user.h"
#include "mainwindow.h"


Name_user::Name_user(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Name_user)
{
    ui->setupUi(this);
}

Name_user::~Name_user()
{
    delete ui;
}

void Name_user::on_pushButton_clicked()
{
    QString str;
    str = ui->lineEdit->text();
}
