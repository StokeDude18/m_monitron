#include "edit_control_op.h"
#include "ui_edit_control_op.h"

edit_Control_OP::edit_Control_OP(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::edit_Control_OP)
{
    ui->setupUi(this);
}

edit_Control_OP::~edit_Control_OP()
{
    delete ui;
}
