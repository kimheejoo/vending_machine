#include "widget.h"
#include "ui_widget.h"
#include <QMessageBox>
#include <string>
#include <stdio.h>

int money = 0;
Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}

void Widget:: initVending(){
    money = 0;
    ui->lcdNumber->display(QString::number(money));
    ui->pbTea->setEnabled(false);
    ui->pbCoffee->setEnabled(false);
    ui->pbGongCha->setEnabled(false);
}

void Widget:: enableButton(){
    if(money >=100 ) ui->pbCoffee->setEnabled(true);
    else ui->pbCoffee->setEnabled(false);
    if(money >= 150 ) ui->pbTea->setEnabled(true);
    else ui->pbTea->setEnabled(false);
    if(money >= 200 ) ui->pbGongCha->setEnabled(true);
    else ui->pbGongCha->setEnabled(false);
}

void Widget:: changeMoney(int n){
    money += n;
    ui->lcdNumber->display(QString::number(money));
    enableButton();
}

int Widget:: returnCoin(int n){
   int coin = 0;
   coin = (money/n);
   money = money % n;
   return coin;
}

void Widget::on_pb10_clicked()
{
    changeMoney(10);
}

void Widget::on_pb50_clicked()
{
    changeMoney(50);
}

void Widget::on_pb100_clicked()
{
    changeMoney(100);
}

void Widget::on_pb500_clicked()
{
    changeMoney(500);
}

void Widget::on_pbCoffee_clicked()
{
    changeMoney(-100);
}

void Widget::on_pbTea_clicked()
{
    changeMoney(-150);
}

void Widget::on_pbGongCha_clicked()
{
    changeMoney(-200);
}


void Widget::on_pbReturn_clicked()
{
    int c500=0,c100=0,c50=0,c10=0;
    c500 = returnCoin(500);
    c100 = returnCoin(100);
    c50 = returnCoin(50);
    c10 = returnCoin(10);
    QString str ="";

    str.sprintf("500: %d, 100: %d, 50: %d, 10: %d",c500,c100,c50,c10);
    QMessageBox msg;
    msg.information(nullptr,"RETURN",str);
    initVending();
}






























