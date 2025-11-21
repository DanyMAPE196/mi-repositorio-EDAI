print("\n===Ejemplo 1===\n")
def imprime_nombre(nombre):
    print("hola " + nombre)

imprime_nombre("JJ")

print("\n===Ejemplo 2===\n")
def cuadrado(x):
    return x ** 2

x = 5
print("El cuadrado de {} es {}". format(x, cuadrado(x)))

print("\n===Ejemplo 3===\n")
def varios(x):
    return x ** 2, x ** 3, x ** 4

val1, val2, val3 = varios(2)
print("{} {} {}". format(val1, val2, val3))

print("\n===Ejemplo 4===\n")
def cuadrado_default(x = 3):
    return x ** 2

print(cuadrado_default())

print("\n===Ejemplo 5===\n")
val4, _, val5 = varios(2)
print("{} {}". format(val4, val5))
