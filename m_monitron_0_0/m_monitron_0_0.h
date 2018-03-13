#ifndef M_MONITRON_0_0_H
#define M_MONITRON_0_0_H

#include <QMainWindow>

#include "edit_lecture.h"
#include "edit_cycles.h"
#include "edit_calibration.h"
#include "edit_control_op.h"
#include "module.h"

#include <QDialog>
#include <QMessageBox>

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
    void printParams(module* mod, uint8_t fonction);
    uint8_t getNextFunction();
    void getNewParams(module *objNewParams);
    void buildF3Frame(uint8_t* sendBuffer);


private slots:
    void on_b_Edit_tLecture_clicked();
    void on_b_Edit_tCycles_clicked();
    void on_b_Edit_tCalibration_clicked();
    void on_b_Edit_tControl_clicked();

private:
    Ui::m_monitron_0_0 *ui;
    edit_Lecture edit_w_Lecture;
    edit_Cycles edit_w_Cycles;
    edit_Calibration edit_w_Calib;
    edit_Control_OP edit_w_ControlOP;    
    QMessageBox error_Msg_Box;
    module m_newParams;
    uint8_t nextFunction;
};

#endif // M_MONITRON_0_0_H
