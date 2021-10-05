def tripla_pitagorica_p(quantidade):
    #inicializamos as variáveis m,c e contador com os seus respectivos valores.
    m = 2
    c = 0
    contador = 0
    parada = 0
    # é feita uma verificação se o valor de c (que é maior que a e b) é menor que a quantidade limite, inserida como entrada pelo usuário. 
    while parada==0:
         
        # no lugar de incrementar a,b,c utilizamos m e n e aplicamos m e n incrementado na fórmula para que seja encontrada o terno pigatórico.
        # o valor de n é iniciado com 1 e o valor de m é iniciado com 2, desta forma a cada incremento n = 1,2,3,4.. e m = 2,3,4,5...
        for n in range(1, m) :
            #aplicação da formula 
            a = (m * m) - (n * n)
            b = 2 * (m * n)
            c = (m * m) + (n * n)         
            
           #após aplicação da fórmula para se ter os valores de a,b e c, verificamos novamente se o novo valor de c é maior que a variável quantidade
           # que foi inserida pelo usuário.
            if c > quantidade :
                parada=1 #caso a condição seja satisfeita, é interrompida a execução e o valor do contador é retornado para o usuário.
            contador = contador +1 #// a cada tripla encontrada o contador é incrementado +1.

        m = m + 1
    return contador 

if __name__ == '__main__' :
    quantidade = 200000000
    print(tripla_pitagorica_p(quantidade))
