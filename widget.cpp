#include "widget.h"
#include "ui_widget.h"

// ############################################################

void Widget::rearrange_str(){
    const int n10 = 10;
    const int n50 = 50;
    const int n100 = 100;
    const int n500 = 500;
    int c10 = 0;
    int c50 = 0;
    int c100 = 0;
    int c500 = 0;
    int temp_money = money;

    while(true){
        if(temp_money >= n500){
            temp_money -= n500;
            c500++;
        }
        else{
            break;
        }
    }

    while(true){
        if(temp_money >= n100){
            temp_money -= n100;
            c100++;
        }
        else{
            break;
        }
    }

    while(true){
        if(temp_money >= n50){
            temp_money -= n50;
            c50++;
        }
        else {
            break;
        }
    }

    while(true){
        if(temp_money >= n10){
            temp_money -= n10;
            c10++;
        }
        else {
            break;
        }
    }

    cnt10 = c10;
    str10.remove(5, str10.size()-5);
    str10.append(QString::number(cnt10));
    cnt10 = 0;

    cnt50 = c50;
    str50.remove(5, str50.size()-5);
    str50.append(QString::number(cnt50));
    cnt50 = 0;

    cnt100 = c100;
    str100.remove(5, str100.size()-5);
    str100.append(QString::number(cnt100));
    cnt100 = 0;

    cnt500 = c500;
    str500.remove(5, str500.size()-5);
    str500.append(QString::number(cnt500));
    cnt500 = 0;
}

// ############################################################

void Widget::show_message(){
    QString qstr = nullptr;
    qstr.append(str10);
    qstr.append("\n");
    qstr.append(str50);
    qstr.append("\n");
    qstr.append(str100);
    qstr.append("\n");
    qstr.append(str500);
    msg.information(nullptr, "INFO", qstr);
}

// ############################################################

void Widget::make_message(QString qstr, QString sign){
    if(qstr.isNull()){
        return ;
    }
    else{
        if(qstr.contains("10") && (qstr.size() == 2)){
            if(sign.contains("+")){
                cnt10++;
            }
            else if(sign.contains("-")){
                if(cnt10 > 0){
                    cnt10--;
                }
            }
            //str10.remove(5, str10.size()-5);
            //str10.append(QString::number(cnt10));
        }
        else if(qstr.contains("50") && (qstr.size() == 2)){
            if(sign.contains("+")){
                cnt50++;
            }
            else if(sign.contains("-")){
                if(cnt50 > 0){
                    cnt50--;
                }
            }
            //str50.remove(5, str50.size()-5);
            //str50.append(QString::number(cnt50));
        }
        else if(qstr.contains("100") && (qstr.size() == 3)){
            if(sign.contains("+")){
                cnt100++;
            }
            else if(sign.contains("-")){
                if(cnt100 > 0){
                    cnt100--;
                }
            }
            //str100.remove(6, str100.size()-6);
            //str100.append(QString::number(cnt100));
        }
        else if(qstr.contains("500") && (qstr.size() == 3)){
            if(sign.contains("+")){
                cnt500++;
            }
            else if(sign.contains("-")){
                if(cnt500 > 0){
                    cnt500--;
                }
            }
            //str500.remove(6, str500.size()-6);
            //str500.append(QString::number(cnt500));
        }
    }
}

// ############################################################

void Widget::add_money(int a){
    money += a;
    make_message(QString::number(a), QString("+"));
    enable_button(money);
    ui->totalN->display(money); // str, int, doublemoney += a;
}

void Widget::minus_money(int a){
    money -= a;
    make_message(QString::number(a), QString("-"));
    disable_button(money);
    ui->totalN->display(money);
}

// ############################################################

void Widget::enable_button(int m){
    if(m >= 100){
        ui->pbCof->setEnabled(true);
        if(m >= 150){
            ui->pbTea->setEnabled(true);
        }
        if(m >= 200){
            ui->pbCok->setEnabled(true);
        }
    }
}

void Widget::disable_button(int m){
    if(m < 200){
        ui->pbCok->setEnabled(false);
        if(m < 100){
            ui->pbCof->setEnabled(false);
        }
        if(m < 150){
            ui->pbTea->setEnabled(false);
        }
    }
}

// ############################################################

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

// ############################################################

void Widget::on_pb10_clicked()
{
    add_money(10);

}

void Widget::on_pb50_clicked()
{
    add_money(50);
}

void Widget::on_pb100_clicked()
{
    add_money(100);
}

void Widget::on_pb500_clicked()
{
    add_money(500);
}


// ############################################################

void Widget::on_pbCof_clicked()
{
    if(money >= 100){
        minus_money(100);
    }
}

void Widget::on_pbTea_clicked()
{
    if(money >= 150){
        minus_money(150);
    }
}

void Widget::on_pbCok_clicked()
{
    if(money >= 200){
        minus_money(200);
    }
}

// ############################################################

// reset button
void Widget::on_pbRes_clicked()
{
    rearrange_str();
    show_message();
    money = 0;
    disable_button(money);
    ui->totalN->display(money);
}

// ############################################################
