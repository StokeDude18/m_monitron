#include "settings_edit.h"
#include "ui_settings_edit.h"

Settings_Edit::Settings_Edit(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Settings_Edit)
{
    ui->setupUi(this);
}

Settings_Edit::~Settings_Edit()
{
    delete ui;
}
