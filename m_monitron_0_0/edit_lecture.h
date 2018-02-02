#ifndef SETTINGS_EDIT_H
#define SETTINGS_EDIT_H

#include <QDialog>

namespace Ui {
class Settings_Edit;
}

class Edit_Lecture : public QDialog
{
    Q_OBJECT

public:
    explicit Edit_Lecture(QWidget *parent = 0);
    ~Edit_Lecture();
    Ui::Settings_Edit *ui;

private:


};

#endif // SETTINGS_EDIT_H
