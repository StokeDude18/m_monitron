#include "m_monitron_0_0.h"
#include "ui_m_monitron_0_0.h"
#include "ui_dialog_edit_tlecture.h"
#include <QtWidgets>
#include <QLocale>
#include <QString>
#include <QInputDialog>
#include <QLabel>

m_monitron_0_0::m_monitron_0_0(QWidget *parent) : QMainWindow(parent), ui(new Ui::m_monitron_0_0)
{
    ui->setupUi(this);
}

m_monitron_0_0::~m_monitron_0_0()
{
    delete ui;
}

void m_monitron_0_0::on_b_Edit_tLecture_clicked()
{
    edit_value(ui->l_Current_Setpoint);

}

void m_monitron_0_0::edit_value(QLabel* l)
{
    bool ok;
    QString s;

    double d = QInputDialog::getDouble(this, tr("Set Setpoint"), tr("New setpoint"), 0, 0, 100, 2, &ok);

    if(ok)
    {
        s.sprintf("%2.2f",d); //QString::number(d,'g',4);
        l->setText(s);
    }
}
