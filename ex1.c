/*
    Programa que calcula equações do Segundo Grau
    Autora: Andressa Von Ahnt
*/

#include <stdio.h>
#include <math.h>

int raizes(float A, float B, float C, float * X1, float * X2){
    float delta;
    delta = ((B * B) - (4 * A * C));

    if(delta < 0){
        return 0;
    }else{
        if(delta == 0){
            *X1= (- B - sqrt(delta)) / (2 * A);
            return 1;
        }else{
            *X1 = (- B + sqrt(delta)) / (2 * A);
            *X2 = (- B - sqrt(delta)) / (2 * A);
            return 2;
        }
    }
    
}

int main(){
    float a=0, b, c, X1, X2;
    int num;

    while(a == 0){
        printf("Enter a: ");
        scanf("%f", &a);
    }
    
    printf("Enter b: ");
    scanf("%f", &b);

    printf("Enter c: ");
    scanf("%f", &c);

    num = raizes(a, b, c, &X1, &X2);
    printf("\nNumber of roots: %d", num);
    
    if(num == 1){
        printf("\nRoot: %.2f", X1);
    }else{
        if(num == 2){
            printf("\nRoots: %.2f and %.2f", X1, X2);
        }
    }
}