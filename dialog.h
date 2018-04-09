#ifndef DIALOG_H
#define DIALOG_H
#include"mainwindow.h"
#include <QDialog>

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = 0);
    ~Dialog();

private slots:
    void on_pushButton_clicked();
    void showw();
    void on_pushButton_2_clicked();

private:
    Ui::Dialog *ui;
    MainWindow mainwindow1;
};

#endif // DIALOG_H
