# Jerarquía y Comportamiento de Procesos en C

## 1. Jerarquía de Procesos (Caso 1)

La jerarquía de procesos comienza con un proceso padre (`P0`), que posee un hijo (`P1`). Este, a su vez, tiene otro hijo (`P2`), y finalmente este último crea un hijo más (`P3`).

### Mensajes Repetidos

Esto sucede debido a la función `fork()` utilizada en el código. Esta función crea nuevos procesos que comienzan a ejecutarse desde el punto donde se llamó a `fork()`. Como el mismo bloque de código se ejecuta para el proceso padre e hijo, cada uno imprime su mensaje correspondiente, generando repetición.

### Orden de Terminación

En ocasiones, el proceso padre no imprime su mensaje antes que sus hijos. Esto ocurre porque ambos procesos (padre e hijos) pueden ejecutarse concurrentemente, pero los hijos pueden finalizar en momentos diferentes.  
Dependiendo de lo aleatorio de la función `sleep(random() % X)`, algunos procesos terminan antes que otros debido a los retrasos variables introducidos.

---

## 2. Jerarquía de Procesos (Caso 2)

En este caso, la jerarquía comienza con un proceso padre (`P0`) que posee tres hijos (`P1`, `P2`, `P3`).

### Orden de Terminación

El orden de finalización de los procesos hijos es aleatorio debido a la función `sleep(random() % 5)`, que introduce tiempos de espera distintos.  

El proceso padre imprime un mensaje cada vez que uno de los hijos finaliza:  
1. Primero, se genera el mensaje de terminación de un hijo aleatorio.  
2. Luego, se muestra el mensaje del padre.  
3. Este ciclo se repite hasta que todos los hijos han finalizado.

---

## 3. Árbol de Procesos

El árbol resultante del código es el siguiente:  
*(Agregar diagrama o descripción del árbol según el código proporcionado)*

---

## 4. Procesos Modificados con `execlp`

Los procesos que fueron modificados mediante la función `execlp` son identificados claramente en el código. Este cambio ocurre al reemplazar el programa actual por otro especificado en `execlp`.

---

## 5. Problemas y Soluciones del Código

### Problemas Detectados:
a. El proceso padre no se inicializa correctamente.  
b. La sincronización entre el proceso padre y los procesos hijos no se gestiona adecuadamente. El padre espera que los hijos finalicen sin control específico.  
c. La instrucción `inicio = time(NULL)` debe ejecutarse antes de crear los procesos hijos.

### Solución Propuesta:
- Reestructurar el código para asegurar que el proceso padre inicializa correctamente.  
- Sincronizar los tiempos entre padre e hijos mediante funciones como `wait()` o `waitpid()`.  
- Asegurar que las operaciones iniciales se ejecuten antes de las llamadas a `fork()`.

---

## 6. Modificaciones del Código

Se realizaron cambios para corregir errores y mejorar la funcionalidad:  
1. Implementar `execlp` para ejecutar programas externos como `kcalc` o `xload`.  
2. Añadir cálculos del tiempo de ejecución al programa principal.

---

## 7. Ejemplo de Factorial

El siguiente programa calcula el factorial de un número, mostrando los resultados parciales en cada paso.

### Comprobación del Funcionamiento
Entrada:  
```bash
./factorial 5


