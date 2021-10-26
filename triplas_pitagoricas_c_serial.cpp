#include <stdio.h>

void tripla_pitagorica_c(int quantidade)
{
    int a, b, c, i, j, k;
    int contador = 0;
       
    for (i = 1; i < quantidade - 1; i++){
        for (j = i; j < quantidade; j++){
            for (k = j; k <= quantidade; k++){
                a = i * i;
                b = j * j;
                c = k * k;
                if (a + b == c){
                    contador++;
                }
                //  printf("i = %d, j= %d,  k= %d,  \n", i, j, k);
            }
        }
    }

printf("%d", contador);
}
 
// Driver Code
int main()
{
    int quantidade = 100;
    tripla_pitagorica_c(quantidade);
}
