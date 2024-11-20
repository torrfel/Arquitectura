# Jerarquía y Comportamiento de Procesos en C

## 1. Jerarquía de Procesos (Caso 1)

La jerarquía de procesos comienza con un proceso padre (`P0`), que posee un hijo (`P1`). Este, a su vez, tiene otro hijo (`P2`), y finalmente este último crea un hijo más (`P3`).

![p1](https://github.com/user-attachments/assets/c2e7552c-459c-4a50-9a98-b5b43147fc18)

### Mensajes Repetidos

Esto sucede debido a la función `fork()` utilizada en el código. Esta función crea nuevos procesos que comienzan a ejecutarse desde el punto donde se llamó a `fork()`. Como el mismo bloque de código se ejecuta para el proceso padre e hijo, cada uno imprime su mensaje correspondiente, generando repetición.

### Orden de Terminación

En ocasiones, el proceso padre no imprime su mensaje antes que sus hijos. Esto ocurre porque ambos procesos (padre e hijos) pueden ejecutarse concurrentemente, pero los hijos pueden finalizar en momentos diferentes.  
Dependiendo de lo aleatorio de la función `sleep(random() % X)`, algunos procesos terminan antes que otros debido a los retrasos variables introducidos.

---

## 2. Jerarquía de Procesos (Caso 2)

En este caso, la jerarquía comienza con un proceso padre (`P0`) que posee tres hijos (`P1`, `P2`, `P3`).

![p2](https://github.com/user-attachments/assets/173766db-07c8-4b31-8764-dd9afe391aed)

### Orden de Terminación

El orden de finalización de los procesos hijos es aleatorio debido a la función `sleep(random() % 5)`, que introduce tiempos de espera distintos.  

Primero se genera el mensaje de terminación de un hijo aleatorio, luego se muestra el mensaje del padre, luego el mensaje de otro hijo, seguido nuevamente por el mensaje del padre, y finalmente el mensaje del hijo restante junto con el mensaje del padre. Esto se debe a que cada que un hijo termina, el padre imprime un mensaje "Fin del proceso..." y así para esperar el próximo hijo. 

---

## 3. Árbol de Procesos

El árbol resultante del código es el siguiente:  
![p3](https://github.com/user-attachments/assets/de65b1a7-8aa8-40d8-8ad5-f8135634d2d6)

---

## 4. Procesos Modificados con `execlp`

Los procesos que fueron modificados mediante la función `execlp` son identificados con `execlp`
![p4](https://github.com/user-attachments/assets/df67c4b9-e9d0-4123-ac04-056c09849465)

---

## 5.Jerarquia de procesos del codigo dado

![p5](https://github.com/user-attachments/assets/01ba51e0-672f-4ad3-b03c-b2da64478eae)

---

## 6. Herarquia de procesos 
![p6](https://github.com/user-attachments/assets/d5cd9922-8ba2-4182-b05f-963d1e25e3f1)
---

## 7. Modificaciones del Código

![p7](https://github.com/user-attachments/assets/a886a26d-4078-4456-9ba6-00fa87a3c739)

---
## 8. Arbol de procesos:
![p8](https://github.com/user-attachments/assets/9995968c-373e-4b88-9c56-3c3fc535aa45)

---
## 9. Árbol de procesos del código pedido:
### Arbol de procesos
![P9](https://github.com/user-attachments/assets/a8747f95-4dc3-4928-a416-bed760d23ba8)

---
## 10. Problemas y soluciones del código  

a.  En el código no se inicializa el proceso padre de forma correcta  

b. El tiempo no esta sincronizado de forma correcta en entre el procesos padre 	y el proceso hijo debido a que el proceso padre espera a que el hijo termine 

c. inicio = time(NULL) se tiene que ejecutar antes de crear al proceso hijo  

Solución del código: 
---
## 11. Codigo Modificado: 11.c

#### Lo que está sucediendo es que, si kcalc se encuentra en una ruta de PATH, se cambiará el proceso y se ejecutará kcalc. Si, por otro lado, no se encuentra en esta variable, se sigue mostrando mensaje y se hacen cambios de proceso en xload en lugar de kcalc. 
---
## 12. Codigo: 12.c

#### Se añade al programa anterior calculo del tiempo
---
## 13 Codigo: 13.c

#### Escritura con simulacion de tiempo
---
## 14. Programa dado 

### a. Comprobación de funcionamiento del código: 
    Entrada -> ./p15 
    Salida ->  
    Programa: programa1 
    Esperar? Si 
    Programa: programa1 
    Esperar? No 
    Programa: salir 
### Modificaciones del código: 14.c
---
## 15 Programa para calcular factoriales
### a. Comprobar funcionamiento:
    Entreda ->./factorial 5 
    Salida -> Factorial de 5, resultado parcial 2 
    Factorial de 5, resultado parcial 6 
    Factorial de 5, resultado parcial 24 
    Factorial de 5, resultado parcial 120 
    El factorial de 5 es 120 
### b.Pograma que  recibe dos números: 15b.c
### c. Que el proceso padre sea el ultimio en terminar: 15c.c
---
## 16. Generalizar la solución del punto anterior 
### a. Proceso por cada factorial a calcular: 
### b. El proceso padre tiene que esperar a los procesos hijos :
### c. El mensaje del primer hijo no se imprime , pero los demas si :
---
## 17. Programa tiempo.c 





