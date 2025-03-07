/*
    Enunciado:
    Escreva uma função que aceita como parâmetro um array de inteiros com N valores, e
    determina o maior elemento do array e o número de vezes que este elemento ocorreu
    no array. Por exemplo, para um array com os seguintes elementos: 5, 2, 15, 3, 7, 15,
    8, 6, 15, a função deve retorna para o programa que a chamou o valor 15 e o número 3
    (indicando que o número 15 ocorreu 3 vezes). A função deve ser do tipo void.
*/

#include <stdio.h>
#include <string.h>

void BiggerElement(int *array, int *num, int *times, int size){
    *num = *array;
    *times = 1;

    for (int i = 1; i < size; i++){
        if(array[i] > *num){
            *num = array[i];
            *times = 1;
        }else{
            if(array[i] == *num){
                (*times)++;
            }
        }
    }
}

int main(){
    int array[] = {1, 2, 1, 2, 2, 2};
    int num, times;

    BiggerElement(array, &num, &times, 6);
    printf("Biggest number: %d\nTimes appeared: %d", num, times);
}