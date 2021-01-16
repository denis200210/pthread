#include <iostream>
#include <fstream>
#include <sstream>
#include "phtr.h"

using namespace std;

void* calculSum(void* args) {
    int sum;
   ifstream infile;
    stringstream thread;

    Args *data = (Args*) args;
    infile.open(data->path);
    thread.str(std::string());
    data->sum = 0;
    while (!infile.eof()) {
        infile >> sum;
        data->sum += sum;
    }
    infile.close();
}

int summultifile(int f) {
    int sum = 0;
    pthread_t threads[f];
    Args* args = new Args[f];

    for (int k = 0; k < f; ++k) {

        args[k].path = "../f/" + to_string(k + 1) + ".txt";
        pthread_create(&(threads[k]), NULL, calculSum, &args[k]);
    }
    for (int k = 0; k < f; k++) {
        pthread_join(threads[k], NULL);
        sum += args[k].sum;
    }
    delete[] args;
    return sum;
}

int sumfiles(int f) {
    int sum = 0;
    Args args;

    for (int k = 0; k < f; ++k) {
        args.path = "../f/" + to_string(k + 1) + ".txt";
        calculSum(&args);
        sum += args.sum;
    }
    return sum;
}
