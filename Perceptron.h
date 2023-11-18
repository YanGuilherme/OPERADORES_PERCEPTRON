#ifndef PERCEPTRON_H
#define PERCEPTRON_H
#include <iostream>
#include <stdio.h>

#define NUM_ENTRADAS 2

class Perceptron{
    public:
        Perceptron();
        Perceptron(float*, float, int);
        ~Perceptron();

        int feedfoward(Perceptron*,int*, int);
    private:
        int activation_step(int);
        float *pesos;
        float bias;
};

#endif