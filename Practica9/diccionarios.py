print("\n===Ejemplo 1===\n")
elementos = { 'hidrogeno' : 1, 'helio' : 2, 'carbon': 6}

print(elementos)

print (elementos['hidrogeno'])

print("\n===Ejemplo 2===\n")
elementos['litio'] = 3
elementos['nitrogeno'] = 8

print(elementos)

print("\n===Ejemplo 3===\n")
elementos2 = {}
elementos2 ['H'] = {'name': 'Hydrogen', 'number' : 1, 'weight' : 1.00794}
elementos2 ['He'] = {'name': 'Helium', 'number' : 2, 'weight' : 4.002602}

print(elementos2)

print("\n===Ejemplo 4===\n")
print (elementos2 ['H'])
print (elementos2 ['H'] ['name'])
print (elementos2 ['H'] ['number'])
elementos2 ['H'] ['weight'] = 4.30
print (elementos2 ['H'] ['weight'])

print("\n===Ejemplo 5===\n")
elementos2 ['H']. update({'gas noble' : True})
print (elementos2 ['H'])

print("\n===Ejemplo 6===\n")
print (elementos2.items())
print (elementos2.keys())