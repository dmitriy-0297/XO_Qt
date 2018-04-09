#ifndef TABLE_H
#define TABLE_H

#include <QDialog>
#include <QObject>
#include <QString>
#include <QStandardItemModel>
#include "game.h"

namespace Ui {
class Table;
}
class Table : public QDialog{
    Q_OBJECT
public:
    int bCells = 0;//занятые ячейки
    explicit Table(QWidget *parent = 0);
    ~Table();
     Table* tb; //ссылка на таблицу для обмена информацией
     //ввод данных в таблицу
     void enterTable(QString usr1, QString usr2, int rt1, int rt2, int &bCells);
private:
    Ui::Table *ui;
    QStandardItemModel *model;
};

#endif // TABLE_H
