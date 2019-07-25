#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget();
    void initVending();
    void changeMoney(int n);
    int returnCoin(int n);
    int money{0};
    void enableButton();
private slots:
    void on_pb10_clicked();

    void on_pb50_clicked();

    void on_pb100_clicked();

    void on_pb500_clicked();

    void on_pbCoffee_clicked();

    void on_pbTea_clicked();

    void on_pbGongCha_clicked();

    void on_pbReturn_clicked();

private:
    Ui::Widget *ui;
};

#endif // WIDGET_H
