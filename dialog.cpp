#include "dialog.h"
#include "ui_dialog.h"
#include"mainwindow.h"
#include"ui_mainwindow.h"
Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_pushButton_clicked()
{
    this->hide();
   mainwindow1.show();
}



void Dialog::showw()
{
    this->show();
}

void Dialog::on_pushButton_2_clicked()
{
    this->close();
}
