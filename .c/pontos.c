#include <stdio.h>
#include <stdlib.h>
#include "pontos.h"

Ponto *pontos;
int num_pontos, maior_tamanho_conjunto;
Ponto ponto_ancora_a, ponto_ancora_b;

float calcular_coeficiente_reta(Ponto p1, Ponto p2){
    return (p2.y - p1.y)/(p2.x - p1.x);
}

int cmp_Pontos(const void *a, const void *b){
    return ((Ponto*)a)->y - ((Ponto*)b)->y; 
}

void encontrar_maior_conjunto(){
    qsort(pontos, num_pontos, sizeof(Ponto), cmp_Pontos);
    
    int *tamanho_conjunto = malloc(sizeof(int) * (num_pontos + 1));
    for(int i = 0; i < num_pontos; i++)
        tamanho_conjunto[i] = 1;
    
    resolver(tamanho_conjunto);
    free(tamanho_conjunto);
}

void resolver(int *tamanho_conjunto){
    maior_tamanho_conjunto = 1;
    
    for(int i = 0; i < num_pontos; i++){
        float coef_a = calcular_coeficiente_reta(ponto_ancora_a, pontos[i]);
        float coef_b = calcular_coeficiente_reta(ponto_ancora_b, pontos[i]);

        int tamanho_atual = encontrar_tamanho_conjunto(i, tamanho_conjunto, coef_a, coef_b);
        atualizar_maior_tamanho_conjunto(&maior_tamanho_conjunto, tamanho_atual);
    }
}

int encontrar_tamanho_conjunto(int indice_atual, int *tamanho_conjunto, float coef_a, float coef_b) {
    int tamanho_atual = 1;
    for(int j = indice_atual - 1; j >= 0; j--){
        if(tamanho_conjunto[j] >= tamanho_atual){
            if(verificar_interseccao(coef_a, coef_b, pontos[indice_atual], pontos[j])){
                tamanho_atual = tamanho_conjunto[j] + 1;
        
            }
        }
    }
    tamanho_conjunto[indice_atual] = tamanho_atual;
    return tamanho_atual;
}

void atualizar_maior_tamanho_conjunto(int *maior_tamanho, int tamanho_atual) {
    if(tamanho_atual > *maior_tamanho){
        *maior_tamanho = tamanho_atual;
    }
}

int verificar_interseccao(float coef_a, float coef_b, Ponto pa, Ponto pb) {
    float coef = calcular_coeficiente_reta(pa, pb);
    if (coef_a < 0) {
        return (pa.x > pb.x && coef < coef_b && coef > coef_a) ? 1 : 0;
    } else if (coef_b > 0) {
        return (pa.x > pb.x && coef < coef_b && coef > coef_a) ? 1 : 0;
    } else {
        if(pa.x > pb.x){ 
           return (coef > coef_a) ? 1 : 0;
           return (coef < coef_b) ? 1 : 0;
        } 
    }
}