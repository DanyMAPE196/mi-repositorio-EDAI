print("\n===Ejemplo 1===\n")
def obtenerMayor (param1, param2):
    if param1 < param2:
        print('{} es mayor que {}'. format(param2, param1))

obtenerMayor(5, 7)

print("\n===Ejemplo 2===\n")
def obtenerMayor (param1, param2):
    if param1 < param2:
        print('{} es amyor que {}'. format(param2, param1))

obtenerMayor(7, 5) #No va a imprimir nada

print("\n===Ejemplo 3===\n")
x = y = z = 3
if x - y - z:
    print(True)