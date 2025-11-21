print("Interación en listas")
print("\n===Ejemplo 1===\n")
for x in (1, 2, 3, 4, 5):
    print (x)

print("\n===Ejemplo 2===\n")
for x in range (5):
    print(x)

print("\n===Ejemplo 3===\n")
for x in range (-5, 2):
    print(x)

print("\n===Ejemplo 4===\n")
for num in ["uno", "dos", "tres", "cuatro"]:
    print(num)

print("\n")

print("Interacción en diccionarios")
print("\n===Ejemplo 1===\n")
elementos = { 'hidrogeno': 1, 'helio': 2, 'carbon': 6 }

for llave, valor in elementos.items():
    print(llave, " = ", valor)

print("\n===Ejemplo 2===\n")
for llave in elementos.keys():
    print(llave)
      
print("\n===Ejemplo 3===\n")
for valor in elementos.values():
    print(valor)

print("\n===Ejemplo 4===\n")
for idx, x in enumerate(elementos):
    print("El indice es: {} y el elemento: {}". format (idx, x))

print("\n===Ejemplo 5===\n")
def cuenta_idiom(limite):
    for i in range (limite, 0, -1):
        print (i)
    else:
        print("Cuenta finalizada")
    
cuenta_idiom (5)

print("\n===Ejemplo 6===\n")
def cuenta_idiomv2(limite):
    for i in range(limite, 0, -1):
        print(i)
        if i == 3:
            break
    else:
        print("Cuenta finalizada")

cuenta_idiomv2 (5)    
