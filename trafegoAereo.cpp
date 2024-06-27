#include <iostream>
#include <iomanip>
#include <ctime>

using namespace std;

#include "FilaPrioridadesLE.h"

struct Voo {
    int numVoo;
    int prioridadeVoo;
};

// Sequências de escape ANSI para cores
#define RESET "\033[0m"
#define BOLD "\033[1m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN "\033[36m"
#define WHITE "\033[37m"

int main(void)
{
    srand(time(NULL));

    no *entradaDeVoos, *FP;
    int ut, voo, data, prior, i;
    bool continua = true;
    
    entradaDeVoos = inicializaFP(entradaDeVoos);    	
    FP = inicializaFP(FP);

   for(int i = 1; i <= 50; i++) {
        int prioridadeVoo = rand() % 3 + 1;
        entradaDeVoos = insereFilaChegada(entradaDeVoos, 100 + i, prioridadeVoo);
   }

    cout << BOLD << BLUE << "======================================" << RESET << endl;
    cout << BOLD << BLUE << "VOOS CHEGANDO NO AEROPORTO!!" << RESET << endl;
    cout << BOLD << BLUE << "======================================" << RESET << endl;
    exibe(entradaDeVoos);

    cin.get();

    for(ut = 1; continua; ut++) {
        cout << endl << BOLD << CYAN << "======================================" << RESET << endl;
        cout << BOLD << CYAN << "***** UNIDADE DE TEMPO: " << ut << " *****" << RESET << endl;
        cout << BOLD << CYAN << "======================================" << RESET << endl;

        for(voo = 1; voo <= 4; voo++) {
            if(!verificaSeVazia(entradaDeVoos)) {
                entradaDeVoos = removeFP(entradaDeVoos, &data, &prior);
                FP = insereFP(FP, data, prior);
            }
        }

        cout << BOLD << YELLOW << "FILA DE VOOS A SEREM ATENDIDOS: " << RESET;
        exibe(FP);

        if((ut % 2) == 0 && continua) {
            for(i = 1; i <= 3; i++) {
                if(FP != NULL) {
                    FP = removeFP(FP, &data, &prior);
                    if(prior == 1) {
                        cout << RED << BOLD << "PISTA " << i << ": Pouso autorizado para o voo " << data << " (Prioridade ALTA)" << RESET << endl;
                    } 
                    else if(prior == 2) {
                        cout << BLUE << "PISTA " << i << ": Pouso autorizado para o voo " << data << " (Prioridade MEDIA)" << RESET << endl;
                    } 
                    else {
                        cout << MAGENTA << "PISTA " << i << ": Decolagem autorizada para o voo " << data << " (Prioridade NORMAL)" << RESET << endl;
                    }   
                } else {
                    cout << RED << "TODOS OS VOOS FORAM ATENDIDOS - FILA VAZIA" << RESET << endl;
                    continua = false;
                    break;
                }
            }
            if(!verificaSeVazia(FP)) {
                cout << '\n' << BOLD << YELLOW << "FILA DE VOOS A SEREM ATENDIDOS: " << RESET;
                exibe(FP);
            }
        } 
        else {
            cout << BOLD << GREEN << "PISTAS EM ATENDIMENTO" << RESET << endl;
        }
    }

    cout << BOLD << BLUE << "======================================" << RESET << endl;
    cout << BOLD << BLUE << "SIMULAÇÃO FINALIZADA" << RESET << endl;
    cout << BOLD << BLUE << "======================================" << RESET << endl;

    return 0;
}
