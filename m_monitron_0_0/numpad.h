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
    ~Numpad();
    Ui::Numpad *ui;
signals:
    void digitClicked(int digit);

private slots:
    void onPadClick(int digit);

private:

    QPushButton *buttons[12];
    void createLayout();   
};

#endif // NUMPAD_H
