#ifndef NAME_USER_H
#define NAME_USER_H

#include <QDialog>

namespace Ui {
class Name_user;
}

class Name_user : public QDialog
{
    Q_OBJECT

public:
    explicit Name_user(QWidget *parent = 0);
    ~Name_user();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Name_user *ui;
};

#endif // NAME_USER_H
