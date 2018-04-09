#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QLabel>
#include <QtGlobal>
#include<QTime>
#include<QLineEdit>
#include<string>
#include<iostream>
#include<QMessageBox>
using namespace std;
//符号
char create_symbol(int n)
{
    int n1,j;
    char symbol[1];
    if(n==0)
    {
        n1=2;
    }
    else if(n==1)
    {
        n1=4;
    }
    j=qrand()%n1;
    if(j==0) symbol[0]='+';
    else if(j==1) symbol[0]='-';
    else if(j==2) symbol[0]='*';
    else symbol[0]='/';
    return symbol[0];
 }
 //把数字转换成字符串型
 string int_string(int number)
 {
     int temp=abs(number);
    char str[200];
    itoa(temp,str,10);
    string str_=str;
    return str_;
  }
 //运算式转换成一个字符串
 string combination(string str1,string str2,char k)
 {
     string equation;
     equation=str1+k+str2;
     return equation;
 }


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    qsrand(QTime(0,0,0).secsTo(QTime::currentTime() ));
    int num1,num2,count,n=1,change,amount=10,range=100,j,repeat=0,bracket=1;
    string str_num1,str_num2,temp;
    QString string1;
    string Equation[amount];
    string egal;
        char symbol;
        for(int i=0;i<amount;i++)
        {

            num1=qrand()%range+1;
            num2=qrand()%range+1;
            count=qrand()%9+2;
            symbol=create_symbol(n);
            str_num1=int_string(num1);
            str_num2=int_string(num2);
            Equation[i]=combination(str_num1,str_num2,symbol);
            if(count>2)
            {
                for(count;count>2;count--)
                {
                    symbol=create_symbol(n);
                    str_num1=Equation[i];
                    if(bracket==1)
                    {
                        change=qrand()%2;
                        if(change==0)
                        {
                           str_num1='('+str_num1+')';
                         }
                    }
                    symbol=create_symbol(n);
                    num2=qrand()%range+1;
                    str_num2=int_string(num2);
                    change=qrand()%2;
                    if(change==0)
                    {
                        temp=str_num1;
                        str_num1=str_num2;
                        str_num2=temp;
                    }
                    Equation[i]=combination(str_num1,str_num2,symbol);
                }
            }
            //判断是否重复
             for(j=0;j<i;j++)
             {
                 if(Equation[j]==Equation[i])
                 {
                    i=i-1;
                    repeat=1;
                    break;
                 }
             }
             if(repeat!=1)//若不重复，则输出
             {
                 QLabel *label=new QLabel(this);
                 string1=QString::fromStdString(Equation[i]);
                 label->setText(string1);
                 label->setGeometry(50,50+i*50,400,15);
             }
             QLabel *label2=new QLabel(this);
             label2->setText("=");
             label2->setGeometry(400,50+i*50,15,15);
             QLineEdit *line=new QLineEdit(this);
             line->setGeometry(415,50+i*50,60,15);
}
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    this->close();

}


