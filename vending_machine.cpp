#include "vending_machine.h"
#include "ui_vending_machine.h"

Vending_machine::Vending_machine(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Vending_machine)
{
    ui->setupUi(this);
}

Vending_machine::~Vending_machine()
{
    delete ui;
}

