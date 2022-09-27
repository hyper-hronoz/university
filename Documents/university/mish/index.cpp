// без этого хуй что выведем в консоль
#include<iostream>
#include<math.h>

// без этого писать больше - придется ссылаться на глобальную область видимости
// std::cout вместо cout
using namespace std;

int main() {
  // число точек
  int coordinatesAmout = 3; 

  // если не ебаться с двумерными массивами
  int xCoordinates[] = {1, 2, 3};
  int yCoordinates[] = {2, 2, 3};

  // просто счетчик для 1 части
  int firstTaskCounter = 0;

  // сумма отрезков от начала координат (гипотинуз)
  float segmentSum = 0;

  // ебашим первую часть
  for (int i = 0; i < coordinatesAmout; i++) {
    float xCoordinate = xCoordinates[i];
    float yCoordinate = yCoordinates[i];

    // то самое условие
    if (yCoordinate > xCoordinate) {
      firstTaskCounter++;
    }

    // начался пиздец
    // Мысль номер Один - расстояние величина неотрицательная
    // расстояние от начала координат можно посчитать по пифогору
    segmentSum += sqrt(xCoordinate * xCoordinate + yCoordinate * yCoordinate);
  }

  // выводим полученный пиздец
  cout << "Amout of coincidences: " << firstTaskCounter << endl;
  cout << "Sum of segments: " << segmentSum << endl;

  // код успешного завершения(присутствие отсутствия)
  return 0;
}
