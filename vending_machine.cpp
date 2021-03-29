#include "vending_machine.h"
#include "ui_vending_machine.h"


Vending_machine::Vending_machine(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Vending_machine)
{
    ui->setupUi(this);
    setWindowTitle("Vending Machine");

    // Set table
    QStringList coin_list;
    coin_list << "2€" << "1€" << "0.50€" << "0.20€" <<
                 "0.10€" << "0.05" << "0.02€" << "0.01€";
    ui->tableWidget->setRowCount(coin_list.size());
    ui->tableWidget->setVerticalHeaderLabels(coin_list);
    QStringList header;
    header << "NumberOfCoins";
    ui->tableWidget->setColumnCount(1);
    ui->tableWidget->setHorizontalHeaderLabels(header);


    // connect button
    connect(ui->button_buy, SIGNAL(released()), this,
            SLOT(on_button_buy_released()));

}

Vending_machine::~Vending_machine()
{
    delete ui;
}


void Vending_machine::on_button_buy_released()
{
    // check if purchase is valid
    if(ui->user_balance->value() > ui->cost->value())
    {
        m_cost = ui->cost->value();
        m_user_balance = ui->user_balance->value();
        calculate_change();
    }
}

void Vending_machine::calculate_change()
{
    // give the least possible amount of coins

    uint16_t coin_counter = 0;
    uint16_t user_balance_in_cents = m_user_balance * 100;
    uint16_t cost_in_cents = m_cost * 100;
    uint16_t change_in_cents = user_balance_in_cents - cost_in_cents;
    uint16_t coins[8] = {200, 100, 50, 20, 10, 5, 2, 1};
    uint16_t coins_size = sizeof(coins)/sizeof(*coins);

    for (uint16_t i = 0; i < coins_size && change_in_cents > 0; ++i)
    {
        while(change_in_cents - coins[i] >= 0)
        {
            change_in_cents -= coins[i];
            ++coin_counter;
        }
        // update the table and reset value
        ui->tableWidget->setItem(i, 0, new QTableWidgetItem(
                                     QString::number(coin_counter)));
        coin_counter = 0;
    }
}
