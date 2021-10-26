#include <stdio.h>

void tripla_pitagorica_c(int quantidade)
{
    int a, b, c, i, j, k;
    int contador = 0;
       
    for (i = 1; i < quantidade - 1; i++){
        a = i * i;
        for (j = i + 1; j < quantidade; j++){
            b = j * j;
            for (k = j + 1; k <= quantidade; k++){
                c = k * k;
                if (a + b == c){
                    contador++;
                }
            }
        }
    }

printf("%d", contador);
}
 
// Driver Code
int main()
{
    int quantidade = 50;
    tripla_pitagorica_c(quantidade);
}
