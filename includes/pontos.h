#ifndef PONTOS_H
#define PONTOS_H

#include<math.h>
#include<stdlib.h>



typedef struct {
    float x,y;
}Ponto;


extern Ponto *pontos;                              //Conjunto P de pontos passados para o programa
extern int num_pontos, maior_tamanho_conjunto;   //Número de pontos recebidos e valor do maior conjunto(resultado)
extern Ponto ponto_ancora_a, ponto_ancora_b;    //Âncoras


float calcular_coeficiente_reta(Ponto p1,Ponto p2);
int verificar_interseccao(float coef_a, float coef_b, Ponto pa,Ponto pb);
int encontrar_tamanho_conjunto(int indice_atual, int *tamanho_conjunto, float coef_a, float coef_b);
void resolver(int *tamanho_conjunto);
void atualizar_maior_tamanho_conjunto(int *maior_tamanho, int tamanho_atual);
void encontrar_maior_conjunto();

#endif