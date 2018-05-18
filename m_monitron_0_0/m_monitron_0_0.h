#ifndef M_MONITRON_0_0_H
#define M_MONITRON_0_0_H

#include <QMainWindow>

#include "module.h"
#include "numpad.h"
#include "editline.h"

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

    //Méthodes
    void printParams(module* mod, uint8_t fonction);
    uint8_t getNextFunction();
    void getNewParams(module *objNewParams);
    uint8_t getNextActiveModule();
    void buildF3Frame(uint8_t* sendBuffer);
    void setNextFunction(uint8_t function);
    void setNextActiveModule(uint8_t modIndex);
    void addModuleToMenu(uint32_t modID, uint8_t type, uint8_t position);
    void enableComboBox();
    bool comboBoxEnabled;


private slots: //Événements de la fenêtre graphique
    void on_b_Apply_Changes_clicked();
    void on_cb_Module_Select_currentIndexChanged(int index);
    void onFocus(bool hasFocus);
    void cbIndexChanged(int index);
    void on_b_Calibration_clicked();

    void on_b_exit_clicked();

private:

    Ui::m_monitron_0_0 *ui;//Pointeur vers la fenêtre graphique m_monitron_0_0.ui

    QMessageBox error_Msg_Box;//MessageBox pour la génération de messages d'erreur
    module m_newParams;
    uint8_t nextFunction;
    uint8_t nextActiveModule;
    bool calibModeActive;
    vector<EditLine*> v_textBoxArray;
};

#endif // M_MONITRON_0_0_H
