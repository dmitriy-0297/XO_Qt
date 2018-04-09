#include "mainwindow.h"
#include <QApplication>
#include "name_user.h"

int MapSize = 3;

int main(int argc, char* argv[]) {
  QApplication a(argc, argv);

  MainWindow w;
  w.show();

  // Обработка событий - основной цикл работы программы
  return a.exec();
}
