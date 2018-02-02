#include "edit_cycles.h"
#include "ui_edit_cycles.h"

edit_Cycles::edit_Cycles(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::edit_Cycles)
{
    ui->setupUi(this);
}

edit_Cycles::~edit_Cycles()
{
    delete ui;
}
