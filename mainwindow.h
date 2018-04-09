#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <vector>
#include "game.h"
#include "cellbutton.h"
#include "table.h"

namespace Ui {
class MainWindow;
}

using namespace std;

class MainWindow : public QMainWindow {
  Q_OBJECT

 public:
  explicit MainWindow(QWidget* parent = 0);
  ~MainWindow();

  void exit_application();

  void resizeButtonsArray();
 private slots:
  void slot1();
  void slot2();
  void updateWindow(); // Обновить поле
  void newGame(); // Новая игра

  void on_exitButton_clicked();

  // Новый слот
  void myNewSlot();

  void on_action_triggered();

  void on_action_2_triggered();

  void on_setFieldSize_triggered();

  void on_Go_Button_clicked();

  void on_pushButton_clicked();

private:
  Game game; // Состояние игры
  Table tb; // Таблица
  Ui::MainWindow* ui;
  vector<vector<CellButton*> >
  cells; // Клетки поля (кнопки)
  void updateGameButtons(); // Обновляем кнопки - клетки поля
};

#endif // MAINWINDOW_H
