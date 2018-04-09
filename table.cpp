#include "table.h"
#include "ui_table.h"
#include "mainwindow.h"

Table::Table(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Table)
{
    ui->setupUi(this);
    model = new QStandardItemModel(8, 2, this); //создаем таблицу
    ui->tableView->setModel(model);
    model->setHeaderData(0, Qt::Horizontal, "Name");
    model->setHeaderData(1, Qt::Horizontal, "rating");
}

Table::~Table()
{
    delete ui;
}

//ввод данных рейтинга в таблицу
void Table::enterTable(QString usr1, QString usr2, int rt1, int rt2, int &bCells){
    QModelIndex index;
    bool flag1 = false; // флаг для проверки 1-ого имени
    bool flag2 = false; // // флаг для проверки 2-ого имени
    //проверка, что бы исключть повторение
    for(int row = 0; row < model->rowCount(); ++row)
    {
        for(int col = 0; col < model->rowCount(); ++col){
            index = model->index(row, col);
            if (model->data(index).toString() == usr1){
                flag1 = true;
                col++;
                index = model->index(row, col);
                if(bCells != 0){
                model->setData(index, model->data(index).toInt() + rt1);
                }
            }
            index = model->index(row, col);
            if (model->data(index).toString() == usr2){
                flag2 = true;
                col++;
                index = model->index(row, col);
                if(bCells != 0){
                model->setData(index, model->data(index).toInt() + rt2);
                }
            }
        }
    }
    //ввод в таблицу рейтинка
    int row = bCells;
    int col = 0;
    index = model->index(row, col);
    if(flag1 == false){
        index = model->index(row, col);
        model->setData(index, usr1);
        col++;
        index = model->index(row, col);
        model->setData(index, rt1);
        row++; col--; bCells++;
    }
    if (flag2 == false){
        index = model->index(row, col);
        model->setData(index, usr2);
        col++;
        index = model->index(row, col);
        model->setData(index, rt2);
        bCells++;
    }
}
