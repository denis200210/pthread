#include <iostream>
#include <ctime>
#include <pthread.h>
#include "src/calc.h"
using namespace std;
int main() {
    const int f = 10;
    clock_t startes, endl;

    startes = clock();
   cout << "Сумма в файлах при одном потоке: " << sumfiles(f) << endl;
    endl = clock();
   cout << "Время в файлах при потоке: " << (double)(endl - startes) / CLOCKS_PER_SEC << endl;

    startes = clock();
    cout << "Сумма в нескольких потоках: " << summultifile(f) << endl;
    endl = clock();
   cout << "Время в нескольких потоках " << (double)(endl - startes) / CLOCKS_PER_SEC << endl;
   return 0;
}