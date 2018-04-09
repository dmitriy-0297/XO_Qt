#include <QTextStream>
#include <QDebug>
#include <QMessageBox>
#include <cassert>
#include "game.h"
#include "map_size.h"
#include "map_size.h"
#include "mainwindow.h"
#include "table.h"

Game::Game() {
  // При старте программы сразу начинается новая игра
  newGame();
}

// Новая игра
void Game::mapResize() {
  Map.resize(MapSize);

  for(int i = 0; i < MapSize; ++i)
    Map[i].resize(MapSize);
}

void Game::newGame() {
  mapResize();

  // Первыми ходят всегда крестики
  state = O_MOVE;

  // Заполняем поле пустыми клетками, без крестиков и ноликов
  for(int i = 0; i < MapSize; i++)
    for(int j = 0; j < MapSize; j++)
      Map[i][j] = ' ';
}


QString Game::getStateString() {
  switch(state) {
    case X_MOVE:
      return QString("Ходит " + this->user2);

    case O_MOVE:
      return QString("Ходит " + this->user1);

    case X_WIN:
      this->rating1 = 0;
      this->rating2 = 100;
      return QString(this->user2 + " выйграл(-a)!");

    case O_WIN:
      this->rating2 = 0;
      this->rating1 = 100;
      return QString(this->user1 + " выйграл(-a)!");

    case DRAW:
      this->rating1 = 50;
      this->rating2 = 50;
      return QString("Ничья! :)");

    default:
      return QString("Ошибка в программе!");
      assert(false);
  }

  return QString("Непредусмотренное состояние игры!");
}

// Совершаем ход
QString Game::makeMove(int row, int col) {
  if(Map[row][col] != ' ') {
    QMessageBox::critical(NULL, "Ошибка",
                          "Нельзя ходить в занятую клетку");
    return QString("!");
  }

  switch (state) {
    case X_MOVE:
      Map[row][col] = X;
      state = O_MOVE;
      break;

    case O_MOVE:
      Map[row][col] = O;
      state = X_MOVE;
      break;

    default:
      return QString(" ");
  }

  checkGameOver();
  return QString(Map[row][col]);
}

// Три крестика или три нолика
void Game::checkLine(std::vector<char> a) {
  // Если не все элементы равны => не подходит
  for(int i = 1; i < MapSize; ++i)
    if(a[i - 1] != a[i])
      return;

  // Кто-то выйграл :)
  switch(a[0]) {
    case X:
      state = X_WIN;
      break;

    case O:
      state = O_WIN;
      break;

    default:
      break; // Если не крестики и не нолики, то не подходит
  }
}

void Game::checkGameOver() {
  std::vector<char> a(MapSize);

  // == Проверяем диагонали ==
  // Основная диагональ
  for(int i = 0; i < MapSize; ++i)
    a[i] = Map[i][i];

  checkLine(a);

  // Дополнительная диагональ
  //   (0,0) (0,1) [0,2]
  //   (1,0) [1,1] (1,2)
  //   [2,0] (2,1) (2,2)
  for(int i = 0; i < MapSize; ++i)
    a[i] = Map[MapSize - i - 1][i];

  checkLine(a);

  // Вертикальные и горизонтальные линии
  for(int i = 0; i < MapSize; ++i) {
    // Вертикальная линия
    // копируем в a i-ый столбец
    for(int j = 0; j < MapSize; ++j)
      a[j] = Map[j][i];

    checkLine(a);

    // Горизонтальная линия
    checkLine(Map[i]);
  }

  // Проверяем что крестики или нолики
  // выйграли и выходим
  switch(state) {
    case X_WIN:
    case O_WIN:
      return;

    default:
      ; // Do nothing
  }

  // Ничья = не осталось пустых клеток
  int cnt = 0; // Количество пустых клеток

  for(int i = 0; i < MapSize; i++)
    for(int j = 0; j < MapSize; j++)
      if(Map[i][j] == ' ')
        cnt++;

  qDebug() << "cnt = " << cnt;

  if(cnt == 0)
    state = DRAW;
}

const char* Game::getCell(int i, int j) {
  static char buf[2];
  sprintf(buf, "%c", Map[i][j]);
  return buf;
}

