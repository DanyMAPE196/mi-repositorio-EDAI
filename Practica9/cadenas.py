print("\n===Ejemplo 1===\n")
cadena1 = 'Hola '
cadena2 = "Mundo"
print(cadena1)
print(cadena2)

concat_cadenas = cadena1 +  cadena2
print(concat_cadenas)

print("\n===Ejemplo 2===\n")
num_cadena = concat_cadenas +' '+ str(3)
print(num_cadena)

print("\n===Ejemplo 3===\n")
num_cadena = "{} {} {}". format(cadena1, cadena2, 3)
print(num_cadena)

print("\n===Ejemplo 4===\n")
num_cadena = "Cambiando el orden: {1} {2} {0} #". format(cadena1, cadena2, 3)
print(num_cadena)

