#ifndef M_MONITRON_0_0_H
#define M_MONITRON_0_0_H

#include <QMainWindow>
#include "settings_edit.h"
#include "ui_settings_edit.h"

#include <QDialog>

namespace Ui {
class m_monitron_0_0;

}

class m_monitron_0_0 : public QMainWindow
{
    Q_OBJECT

public:
    explicit m_monitron_0_0(QWidget *parent = 0);
    ~m_monitron_0_0();

private slots:
    void on_b_Edit_tLecture_clicked();

private:
    Ui::m_monitron_0_0 *ui;
    Settings_Edit edit_w;
};

#endif // M_MONITRON_0_0_H
