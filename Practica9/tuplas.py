print("\n===Ejemplo 1===\n")
tupla_diasDelMes = (31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31)
print(tupla_diasDelMes)
print(tupla_diasDelMes [0])
print(tupla_diasDelMes [3])
print(tupla_diasDelMes [1])

print("\n===Ejemplo 2===\n")
tupla_numeros = (('cero', 0), ('uno', 1, 'UNO'), ('dos', 2), ('tres', 3), ('cuatro', 4), ('X', 5))

print(tupla_numeros)

print(tupla_numeros [0])
print(tupla_numeros [1])

print(tupla_numeros [2][0])
print(tupla_numeros [2][1])

print(tupla_numeros [1][0])
print(tupla_numeros [1][1])
print(tupla_numeros [1][2])

print("\n===Ejemplo 3===\n")
lista_diasDelMes = [31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31]

print("valor actual {}". format(lista_diasDelMes [0]))
lista_diasDelMes [0] = 50
print("valor cambiado {}". format(lista_diasDelMes [0]))
tupla_diasDelMes [0] = 50 