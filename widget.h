#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QMessageBox>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget();

    //int money = 0; // Parameter Constructor (not assign)
    int money{0};
    int cnt500{0};
    int cnt100{0};
    int cnt50{0};
    int cnt10{0};

    QMessageBox msg;
    QString str500{"500 : 0"};
    QString str100{"100 : 0"};
    QString str50{"50 : 0"};
    QString str10{"10 : 0"};

    void disable_button(int m);
    void enable_button(int m);
    void add_money(int a);
    void minus_money(int a);
    void show_message();
    void make_message(QString qstr, QString sign);
    void rearrange_str();

private slots:
    void on_pb10_clicked();
    void on_pb50_clicked();
    void on_pb100_clicked();
    void on_pb500_clicked();
    void on_pbCof_clicked();
    void on_pbTea_clicked();
    void on_pbCok_clicked();
    void on_pbRes_clicked();

private:
    Ui::Widget *ui;
};

#endif // WIDGET_H
