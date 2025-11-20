memoria = {1: 0, 2: 1}

def fibonacci(n):
    
    if n in memoria:
        return memoria[n]

    
    resultado = fibonacci(n - 1) + fibonacci(n - 2)

    
    memoria[n] = resultado
    return resultado


posiciones = [7, 21, 40, 71, 94]

for p in posiciones:
    print(f"Fibonacci({p}) = {fibonacci(p)}")