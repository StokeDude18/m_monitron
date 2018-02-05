#ifndef EDIT_CONTROL_OP_H
#define EDIT_CONTROL_OP_H

#include <QDialog>

namespace Ui {
class edit_Control_OP;
}

class edit_Control_OP : public QDialog
{
    Q_OBJECT

public:
    explicit edit_Control_OP(QWidget *parent = 0);
    ~edit_Control_OP();
    Ui::edit_Control_OP *ui;

private:

};

#endif // EDIT_CONTROL_OP_H
