#ifndef SETTINGS_EDIT_H
#define SETTINGS_EDIT_H

#include <QDialog>

namespace Ui {
class Settings_Edit;
}

class Settings_Edit : public QDialog
{
    Q_OBJECT

public:
    explicit Settings_Edit(QWidget *parent = 0);
    ~Settings_Edit();

private:
    Ui::Settings_Edit *ui;
};

#endif // SETTINGS_EDIT_H
