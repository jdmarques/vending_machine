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

private:
    Ui::Vending_machine *ui;
};
#endif // VENDING_MACHINE_H
