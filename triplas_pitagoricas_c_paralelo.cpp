#include <omp.h>
#include <stdio.h>


void tripla_pitagorica_c(int quantidade)
{
    int a, b, c, i, j, k;
    int contador = 0;
    omp_set_num_threads(1);

    #pragma omp parallel for private (i,j,k,a,b,c)
        for (i = 1; i < quantidade - 1; i++){
            for (j = i; j < quantidade; j++){
                for (k = j; k <= quantidade; k++){
                    a = i * i;
                    b = j * j;
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
    int quantidade = 6000;
    tripla_pitagorica_c(quantidade);
     // printf("i = %d, j= %d,  k= %d,  threadId = %d \n", i, j, k, omp_get_thread_num());
}
