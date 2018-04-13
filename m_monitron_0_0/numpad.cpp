#include "numpad.h"
#include "ui_numpad.h"

Numpad::Numpad(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Numpad)
{
    ui->setupUi(this);
}

Numpad::~Numpad()
{
    delete ui;
}
