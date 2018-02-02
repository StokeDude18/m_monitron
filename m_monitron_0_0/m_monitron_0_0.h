#ifndef M_MONITRON_0_0_H
#define M_MONITRON_0_0_H

#include <QMainWindow>
#include "edit_lecture.h"
#include "ui_settings_edit.h"
#include "edit_cycles.h"

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
    double m_valSetpoint;
    double m_valVarRate;

private slots:
    void on_b_Edit_tLecture_clicked();
    void on_b_Edit_tCycles_clicked();

private:
    Ui::m_monitron_0_0 *ui;
    Edit_Lecture edit_w_Lecture;
    edit_Cycles edit_w_Cycles;

};

#endif // M_MONITRON_0_0_H
