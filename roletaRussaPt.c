#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <unistd.h>

#define _CHAMBERS 6

void animarSpin5();
void animarSpin3();

int main(){
    srand(time(0)); // Seleciona uma seed para tornar o rand imprevisível

    printf("\n= Roleta Russa - por: Luiz =");
    printf("\nO revolver possui %d buracos e 1 bala.", _CHAMBERS);
    printf("\nPressione \"enter\" para puxar o gatilho.");
    printf("\n\nTente a sorte...");
    
    // Animar o giro do tambor
    animarSpin5();

    // Cadastrar a posição das balas (1 = Carregado, 0 = Vazio)
    int posicaoAtual = rand () % _CHAMBERS;
    int posicaoBala = rand() % _CHAMBERS;

    bool vivo = true;
    int gatilhosAcionados = 0; // Contar quantas vezes o gatilho foi acionado

    while(vivo){
        getchar(); // Aguardar o usuário acionar o gatilho

        gatilhosAcionados++;
        printf("\nPuxou #%d", gatilhosAcionados);
        animarSpin3();

        if(posicaoAtual == posicaoBala){
            printf("\nBANG! Voce perdeu...\n");
            vivo = false;
        } else{
            printf("\nClick. Voce sobreviveu!\n");
            posicaoAtual = (++posicaoAtual) % _CHAMBERS;
        }   
        
        if(gatilhosAcionados == _CHAMBERS-1){
            printf("\nVoce sobreviveu! Parabéns!!");
            vivo = false;
        }
    }

    printf("\nObrigado por jogar! Ate a proxima!!");

    return 0;
}

void animarSpin5(){
    printf("\n\nGirando o tambor");
    for(int i=0; i<5; i++){
        printf(".");
        sleep(1); // Aguardar 1 segundo para o próximo .
    }
    printf("\n");
}

void animarSpin3(){
    for(int i=0; i<3; i++){
        printf(".");
        sleep(1); // Aguardar 1 segundo para o próximo .
    }
}