print("\n===Ejemplo 1===\n")
def numeros (num):
    if num == 1:
        print("tu numero es 1")
    elif num == 2:
        print("el numero es 2")
    elif num == 3:
        print("el numero es 3")
    elif num == 4:
        print("el numero es 4")
    else:
        print("no hay opcion")

numeros(2)

print("\n===Ejemplo 2===\n")
def numeros (num):
    if num == 1:
        print("tu numero es 1")
    elif num == 2:
        print("el numero es 2")
    elif num == 3:
        print("el numero es 3")
    elif num == 4:
        print("el numero es 4")
    else:
        print("no hay opcion")

numeros(5)

print("\n===Ejemplo 3===\n")
def numeros_idiom (num):
    if num in (1, 2, 3, 4):
        print("tu numero es {}". format (num))
    else:
        print("{} no es una opcion". format (num))

numeros_idiom(2)

print("\n===Ejemplo 4===\n")
def numeros_idiom (num):
    if num in (1, 2, 3, 4):
        print("tu numero es {}". format (num))
    else:
        print("{} no es una opcion". format (num))

numeros_idiom(5)

print("\n===Ejemplo 5===\n")
def obtenerMasGrande (a, b, c):
    if a > b:
        if a > c:
            return a
        else:
            return c
    else:
        if b > c:
            return b
        else:
            return c

print("El mas grande es {}". format(obtenerMasGrande (7, 13, 1) ))  
      


