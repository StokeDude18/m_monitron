#include "m_monitron_0_0.h"
#include "ui_m_monitron_0_0.h"
#include "settings_edit.h"
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
      edit_w.show();
}
