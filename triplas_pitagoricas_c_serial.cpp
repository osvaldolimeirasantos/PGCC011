#include <stdio.h>

void tripla_pitagorica_c(int quantidade)
{
 
    // inicializando as variáveis que vão compor o terno pitagórico
    int a, b, c = 0;
 
    // inicializando m e n que vão ser utilizadas para realizar a interação dos valores.
    int m = 2;
    int n;
    int contador = 0; // a variável contador, será utilizada para trazer o total de triplas pitagóricas existentes.
 
    //a tripla pitagórica compreende que: a<b<c , desta forma como c é o maior valor entre as outras 2 partes,
    // verificamos se c é menor que o valor da quantidade inserida pelo usuário.
    while (c < quantidade) {
 
        // nesse loop, verificamos se n é menor que m, caso a condição seja verdadeira, o cálculo será executado.
        for (n=1; n < m; ++n) {
 
            //cálculo para obter os valores de a,b e c
            a = (m * m) - (n * n);
            b = 2 * (m * n);
            c = (m * m) + (n * n);
            
        
            // com o novo valor de c, verificamos se c é maior que o valor da quantidade inserida.
            if (c > quantidade)
                break; //caso a condição seja verdadeira, a execução é encerrada e o valor do contador é apresentado ao usuário.
            
            ++contador; // a cada tripla encontrada o contador é incrementado +1.
        }
        m++;
    }
    printf("%d", contador);
}
 
// Driver Code
int main()
{
    int quantidade = 1000;
    tripla_pitagorica_c(quantidade);
    return 0;
}