#include "Perceptron.h"
#include <iostream>
#include <limits>

using namespace std;

typedef struct sDadosPerceptron{
    float pesos[2];
    float bias;
    int num_entradas;
}DadosPerceptron;
void inicializar_perceptron_and(DadosPerceptron *dados){
    dados->pesos[0] = 2;
    dados->pesos[1] = 2;
    dados->bias = -3;
    dados->num_entradas = 2;
}

void inicializar_perceptron_or(DadosPerceptron *dados){
    dados->pesos[0] = 4;
    dados->pesos[1] = 4;
    dados->bias = -3;
    dados->num_entradas = 2;
}

void inicializar_perceptron_not(DadosPerceptron *dados){
    dados->pesos[0] = -2;
    dados->bias = 1;
    dados->num_entradas = 1;
}

int main(){
    DadosPerceptron dados;
    int escolha;
    bool x = true;
    int entradas[][2] = {
        {0, 0},
        {0, 1},
        {1, 0},
        {1, 1}
    };

    int entradas2[][1] = {
        {0},
        {1}
    };

    while(x){
        cout << "PERCEPTRON - OPERADORES LOGICOS" << endl << endl;
        cout << "1. OPERADOR AND" << endl;
        cout << "2. OPERADOR OR" << endl;
        cout << "3. OPERADOR NOT" << endl;
        cout << "0. SAIR" << endl << endl;
        cout << "DIGITE: ";
        cin >> escolha;
        switch(escolha){
            case 1:{
                system("clear");
                inicializar_perceptron_and(&dados);    
                Perceptron and_perceptron(dados.pesos, dados.bias, dados.num_entradas);
                cout << "-----------------------" << endl;
                cout << "RESULTADO OPERADOR AND" << endl;
                for (int i = 0; i < 4; ++i) {
                    int result =  and_perceptron.feedfoward(&and_perceptron, entradas[i], dados.num_entradas);
                    printf("%d AND %d = %d\n", entradas[i][0], entradas[i][1], result);
                }
                cout << "-----------------------" << endl << endl;
                break;
                }
            case 2:{
                system("clear");
                inicializar_perceptron_or(&dados);    
                Perceptron or_perceptron(dados.pesos,dados.bias,dados.num_entradas);
                cout << "-----------------------" << endl;
                cout << "RESULTADO OPERADOR OR" << endl;
                for (int i = 0; i < 4; ++i) {
                    int result =  or_perceptron.feedfoward(&or_perceptron, entradas[i], dados.num_entradas);
                    printf("%d OR %d = %d\n", entradas[i][0], entradas[i][1], result);
                }
                cout << "-----------------------" << endl << endl;
                break;
                }
            case 3:{
                system("clear");
                inicializar_perceptron_not(&dados);    
                Perceptron not_perceptron(dados.pesos,dados.bias,dados.num_entradas);
                cout << "-----------------------" << endl;
                cout << "RESULTADO OPERADOR NOT" << endl;
                for (int i = 0; i < 2; ++i) {
                    int result =  not_perceptron.feedfoward(&not_perceptron, entradas2[i],dados.num_entradas);
                    printf("NOT %d = %d\n", entradas2[i][0], result);
                }
                cout << "-----------------------" << endl << endl;
                break;
                } 
            case 0:
                x = false;
                break;
            default:
                system("clear");
                cout << "Opcao inválida." << endl << endl;
                break;
        }
    }
    return 0;
}
