print("\n===Ejemplo 1===\n")
vg = 'Global'

def funcion_v1():
    print(vg)

funcion_v1()
print(vg)

print("\n===Ejemplo 2===\n")
def funcion_v2():
    vg = "Local"
    print(vg)

funcion_v2()
print(vg)

print("\n===Ejemplo 3===\n")
def funcion_v4():
    global vg
    print(vg)
    vg = "Local"
    print(vg)

funcion_v4()
print(vg)
