#include "m_monitron_0_0.h"
#include "ui_m_monitron_0_0.h"
#include "edit_lecture.h"
#include "ui_settings_edit.h"
#include <QtWidgets>
#include <QApplication>
#include <QDialog>
//#include <QString>
//#include <QInputDialog>



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
      edit_w_Lecture.exec();

      if(edit_w_Lecture.result() == QDialog::Accepted)
      {
          ui->l_Current_Setpoint->setText(edit_w_Lecture.ui->tb_new_setpoint->text());
          ui->l_Current_Var_Rate->setText(edit_w_Lecture.ui->tb_new_var_rate->text());
      }
}

void m_monitron_0_0::on_b_Edit_tCycles_clicked()
{
    edit_w_Cycles.exec();

    if(edit_w_Cycles.result() == QDialog::Accepted)
    {

    }
}
