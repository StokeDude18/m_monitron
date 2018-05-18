#ifndef NUMPAD_H
#define NUMPAD_H

#include <QDialog>
#include <QLineEdit>

namespace Ui {
class Numpad;
}

class Numpad : public QDialog//, public QWidget
{
    Q_OBJECT

public:
    explicit Numpad(QWidget *parent = 0);
    explicit Numpad(bool floatValuesEnabled, QWidget *parent = 0);
    ~Numpad();
    Ui::Numpad *ui;

signals:
    void digitClicked(int digit);

private slots:
    void onPadClick(int digit);

private:
    static const int NB_BOUTONS = 12;
    static const int DOT = 10;
    static const int BACK = 11;
    QPushButton *buttons[NB_BOUTONS];
    void createLayout();   
};

#endif // NUMPAD_H
