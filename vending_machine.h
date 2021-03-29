#ifndef VENDING_MACHINE_H
#define VENDING_MACHINE_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class Vending_machine; }
QT_END_NAMESPACE

class Vending_machine : public QMainWindow
{
    Q_OBJECT

public:
    Vending_machine(QWidget *parent = nullptr);
    ~Vending_machine();

    double m_user_balance;
    double m_cost;

    void calculate_change();

private slots:
    void on_button_buy_released();

private:
    Ui::Vending_machine *ui;
};
#endif // VENDING_MACHINE_H
