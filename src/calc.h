#ifndef THREADS_CALCULATION_H
#define THREADS_CALCULATION_H
using namespace std;
struct Args {
   string path{};
    int sum{};
};

int summultifile(int f);
int sumfiles(int f);

#endif