#pragma once
#include <iostream>
#include <string.h>
using namespace std;

class Namber {
private:
    float mantis;
    int order;
    string performance;


public:
    Namber(float A = 0, int B = 0, string C = "") {
        mantis = A;
        order = B;
        performance = C;
    }


    Namber(const Namber& equ) {
        mantis = equ.mantis;
        order = equ.order;
        performance = equ.performance;
    }



    ~Namber() {
        cout << " Число :" << performance << mantis * pow(10, order) << " удалено из памяти." << "\n";
    }


    void show() {
        cout << " Число :" << performance << mantis * pow(10, order) << "\n";
    }

};
