#ifndef M_MONITRON_0_0_H
#define M_MONITRON_0_0_H

#include <QMainWindow>

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
};

#endif // M_MONITRON_0_0_H
