#ifndef EDIT_CALIBRATION_H
#define EDIT_CALIBRATION_H

#include <QDialog>

namespace Ui {
class edit_Calibration;
}

class edit_Calibration : public QDialog
{
    Q_OBJECT

public:
    explicit edit_Calibration(QWidget *parent = 0);
    ~edit_Calibration();
    Ui::edit_Calibration *ui;//Pointeur vers la fenêtre graphique edit_calibration.ui

private slots:
    void onFocus(bool hasFocus);

private:

};

#endif // EDIT_CALIBRATION_H
