def tripla_pitagorica_p(quantidade):
    #inicializamos as variáveis m,c e contador com os seus respectivos valores.
    contador = 0

    for i in range(1, (quantidade-1)):
        for j in range(i, quantidade):
            for k in range(j, quantidade):
                a = i * i
                b = j * j
                c = k * k

                if (a + b == c):
                    contador = contador+1

    return contador 

if __name__ == '__main__' :
    quantidade = 3000
    print(tripla_pitagorica_p(quantidade))
