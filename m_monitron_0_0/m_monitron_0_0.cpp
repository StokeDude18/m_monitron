#include "m_monitron_0_0.h"
#include "ui_m_monitron_0_0.h"
#include "ui_dialog_edit_tlecture.h"
#include <QtWidgets>
#include <QLocale>
#include <QString>

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
   bool ok;
   Qstring s;
   double d = QInputDialog::getDouble(this, tr("Set Setpoint"), tr("New setpoint"), QLineEdit::Normal, QDir::home().dirName(), &ok);

   if(ok && d != 0)
   {
      s = QLocale::toString(d, 'g', 4);
      ui->l_Current_Setpoint->setText(s);
   }
}
