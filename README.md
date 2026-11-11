# Actividad 8 Algoritmos Voraces

Estudiante: Anthony Miguel Angel Flores Pinto  
Nivel: Cuarto semestre de Ingenieria de Software

Este proyecto contiene dos soluciones en C++17 que aplican algoritmos voraces. El programa permite ingresar los datos desde consola y elegir el problema desde un menu principal.

## Problemas implementados

- Mochila fraccional: selecciona primero los objetos con mayor relacion valor/peso. Si el ultimo objeto no cabe completo, toma solo la fraccion necesaria.
- Cobertura de antenas: ordena las casas y coloca cada antena lo mas a la derecha posible sin dejar de cubrir la primera casa que falta cubrir.

## Requisitos

- Compilador compatible con C++17, por ejemplo g++.
- Terminal o consola.

## Compilacion y ejecucion

Desde la carpeta principal del proyecto:

```bash
mkdir build
g++ -std=c++17 src/main.cpp -o build/algoritmos-voraces
./build/algoritmos-voraces
```

En Windows, el ejecutable se genera con extension `.exe`.

## Estrategias Greedy

En la mochila fraccional, la mejor decision local es aprovechar primero cada unidad de peso que aporta mas valor. Por eso se ordenan los objetos por valor/peso de mayor a menor.

En la cobertura de antenas, se toma la primera casa sin cubrir y se ubica la antena en `casa + R`. Asi se cubre esa casa y se alcanza lo mas lejos posible hacia la derecha.

## Complejidad

- Mochila fraccional: O(n log n) por el ordenamiento de los objetos.
- Cobertura de antenas: O(n log n) por el ordenamiento de las posiciones de las casas.

En ambos casos, el recorrido posterior es O(n) y el espacio usado para almacenar los datos es O(n).
