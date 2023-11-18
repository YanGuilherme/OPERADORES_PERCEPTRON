#include "Perceptron.h"

Perceptron::Perceptron()
{
}

Perceptron::Perceptron(float* pesos, float bias, int num_entradas){
    this->pesos = (float*)malloc(num_entradas * sizeof(float));
    for(int i = 0; i < num_entradas ; i++){
        this->pesos[i] = pesos[i];
    }
    
    this->bias = bias;

}

Perceptron::~Perceptron(){
    free(pesos);
}

int Perceptron::feedfoward(Perceptron *p, int *entradas, int num_entradas){
    float sum = p->bias;
    for (int i = 0; i < num_entradas; ++i) {
        sum += p->pesos[i] * entradas[i];
    }
    return activation_step(sum);
}

int Perceptron::activation_step(int total){
    if(total > 0){
        return 1;
    }
    return 0;
}

