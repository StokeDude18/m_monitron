#ifndef M_MONITRON_0_0_H
#define M_MONITRON_0_0_H

#include <QMainWindow>

#include "edit_lecture.h"
#include "edit_cycles.h"
#include "edit_calibration.h"
#include "edit_control_op.h"
#include "module.h"
#include "numpad.h"

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

    //Prototypes de méthodes
    void printParams(module* mod, uint8_t fonction);
    uint8_t getNextFunction();
    void getNewParams(module *objNewParams);
    uint8_t getNextActiveModule();
    void buildF3Frame(uint8_t* sendBuffer);
    void setNextFunction(uint8_t function);
    void setNextActiveModule(uint8_t modIndex);
    void addModuleToMenu(uint32_t modID);

private slots: //Événements de la fenêtre graphique
    void on_b_Edit_tLecture_clicked();
    void on_b_Edit_tCycles_clicked();
    void on_b_Edit_tCalibration_clicked();
    void on_b_Edit_tControl_clicked();
    void on_b_Apply_Changes_clicked();

    void on_cb_Module_Select_currentIndexChanged(int index);

private:

    Ui::m_monitron_0_0 *ui;//Pointeur vers la fenêtre graphique m_monitron_0_0.ui

    //Fenètres d'édition
    edit_Lecture edit_w_Lecture;
    edit_Cycles edit_w_Cycles;
    edit_Calibration edit_w_Calib;
    edit_Control_OP edit_w_ControlOP;
    Numpad numpad;

    QMessageBox error_Msg_Box;//MessageBox pour la génération de messages d'erreur
    module m_newParams;
    uint8_t nextFunction;
    uint8_t nextActiveModule;
};

#endif // M_MONITRON_0_0_H
