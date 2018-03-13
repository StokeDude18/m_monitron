#ifndef EDIT_CYCLES_H
#define EDIT_CYCLES_H

#include <QDialog>

namespace Ui {
class edit_Cycles;
}

class edit_Cycles : public QDialog
{
    Q_OBJECT

public:
    explicit edit_Cycles(QWidget *parent = 0);
    ~edit_Cycles();
    Ui::edit_Cycles *ui;

private:

};

#endif // EDIT_CYCLES_H
