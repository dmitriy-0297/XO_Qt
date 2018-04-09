#ifndef GAME_H
#define GAME_H

#include <QString>
#include <QFile>
#include <vector>
#include "table.h"

const char X = 'X';
const char O = 'O';

// Состояние игры
enum State {
  X_MOVE, // Ход крестиков
  O_MOVE, // Ход ноликов
  X_WIN,  // Крестики выйграли
  O_WIN,  // Нолики выйграли
  DRAW    // Ничья
};

// Все что проиходит на поле и логика игрового мира
// Ходы, выйгрыш/проигрыш
class Game  {
  State state; // Текущее состояние игры
  // Игровое поле
  std::vector<std::vector<char> > Map;
  // Проверка выйгрыша
  // проверяется одна строка
  // один столбец или одна диагональ
  void checkLine(std::vector<char> a);
 public:
  // Конструктор
  Game();
  QString user1, user2;
  int rating1 = 0, rating2 = 0;
  // Новая игра без пересоздания объекта
  void newGame();
  Game* game; //ссылка на обьект, для обмна информацией
  // Получаем строку, соответствующую состоянию игры
  QString getStateString();
  // Совершаем ход, возвращает строку для клетки на форме
  QString makeMove(int row, int col);
  // Проверяем на окончание игры
  void checkGameOver();
  // Состояние ячейки
  const char* getCell(int i, int j);
  void resizeMap();
  void mapResize();
};

#endif // GAME_H
