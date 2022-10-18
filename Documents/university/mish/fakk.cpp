#include <iostream>
#include <cmath>

using namespace std;

#define N 20

int main() {
  int i, n;
  float a[N];

  cout << "n="; cin >> n;

  for (i = 0; i < n; i++) {
    // тут i а не a
    cout << "a[" << i << "]="; cin >> a[i];
  }

  float max = a[0];

  for (i = 0; i < n; i++) {
    if (a[i] > max) {
      max = a[i];
    }
  }

  // тут забыл скобки
  float m = fabs(a[0]);

  // тут тоже где модули
  for (i = 0; i < n; i++) {
    if (fabs(a[i]) > m) {
      m = fabs(a[i]);
    }
  }

  // тут можешь равно влепить или двоеточие или пробел чтобы не сраслось
  cout << "max=" << max << endl;
  cout << "module max=" << m << endl;

  return 0;
}


