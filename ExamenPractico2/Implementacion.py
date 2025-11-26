def max_recursivo(lista, inicio=0, fin=None):
    
    if fin is None:
        fin = len(lista) - 1

    if inicio == fin:
        return lista[inicio]

    mitad = (inicio + fin)

    max_izq = max_recursivo(lista, inicio, mitad)
    max_der = max_recursivo(lista, mitad + 1, fin)

    return max_izq if max_izq > max_der else max_der


n = int(input("Ingrese el tamaño de la lista: "))
lista = []

print("Ingrese los elementos:")
for _ in range(n):
    lista.append(int(input()))

resultado = max_recursivo(lista)
print("El valor máximo es:", resultado)