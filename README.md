1. La jerarquía de procesos del código empezaría con un proceso padre (en este caso P0), el cual posee un hijo (P1), este tiene otro hijo más (P2) y por último este tiene uno más (P3). 

		 

¿Por qué aparecen mensajes repetidos? 

Esto es debido a la función fork que llamamos, pues este crea procesos nuevos y ejecuta desde el punto donde se llamó a la función. Al ejecutarse la misma parte de código para el proceso padre e hijo, cada uno imprime un mensaje, entonces se repite 

Orden de terminación: 

Se observa que hay veces en el cual el proceso padre no imprime su mensaje primero que sus hijos. Esto es debido a que ambos procesos pueden ejecutarse a la vez, pero los hijos pueden terminar en momentos diferentes. 

Dependiendo de lo aleatorio de la función sleep(random()%) algunos procesos pueden terminar antes que otros. Esto debido a que hay un retraso mayor o menor en algunos procesos, lo que hace que unos terminen antes que otros. 

2. Su jerarquía empieza con un proceso padre (P0), el cual posee tres hijos más (P1, P2 y P3													 

 

Orden de terminación: 

Los procesos hijos pueden terminar en cualquier orden. Esto es debido a la función sleep(random() % 5) lo que hace que cada uno de ellos puedo demorar un tiempo diferente. 

Primero se genera el mensaje de terminación de un hijo aleatorio, luego se muestra el mensaje del padre, luego el mensaje de otro hijo, seguido nuevamente por el mensaje del padre, y finalmente el mensaje del hijo restante junto con el mensaje del padre. Esto se debe a que cada que un hijo termina, el padre imprime un mensaje "Fin del proceso..." y así para esperar el próximo hijo. 

 

3. El árbol es el siguiente 

 

4. Aquellos con ‘execlp’ son aquellos que fueron modificados por la función execlp. 

 

 

5. Jerarquía de procesos del código dado 

O 

 

6. Jerarquía de procesos 

 

o 

 

 

 

7. Jerarquía resultante del código  

 

8. Código: 



Árbol de procesos: 

 

9. Código pedido: 



Árbol de procesos 

 

10. Problemas y soluciones del código  

a.  En el código no se inicializa el proceso padre de forma correcta  

b. El tiempo no esta sincronizado de forma correcta en entre el procesos padre 	y el proceso hijo debido a que el proceso padre espera a que el hijo termine 

c. inicio = time(NULL) se tiene que ejecutar antes de crear al proceso hijo  

Solución del código: 

 

11.  Código modificado: ->11.c

Lo que está sucediendo es que, si kcalc se encuentra en una ruta de PATH, se cambiará el proceso y se ejecutará kcalc. Si, por otro lado, no se encuentra en esta variable, se sigue mostrando mensaje y se hacen cambios de proceso en xload en lugar de kcalc. 

12.  Añadir al programa anterior calculo del tiempo programa -> 13.c

 
13. Escritura con simulación de tiempo: programa -> programa -> 13.c


14. Programa dado 

Comprobación de funcionamiento del código: 

Entrada -> ./p15

Salida ->  

Programa: programa1 

Esperar? Si 

Programa: programa1 

Esperar? No 

Programa: salir 

Modificaciones del código: 14.c

 

 

15. Programa para calcular factorial 


a. Comprobar funcionamiento: 

sleep (random()\%3); -> el “\” genera un error de sintaxis y no 	es necesario 

Entreda ->./factorial 5 
Salida -> 
Factorial de 5, resultado parcial 2 
Factorial de 5, resultado parcial 6 
Factorial de 5, resultado parcial 24 
Factorial de 5, resultado parcial 120 
El factorial de 5 es 120 

b.Pograma que  recibe dos números 15.b


c. Que el proceso padre sea el ultimio en terminar programa -> 15.c


16. Generalizar la solución del punto anterior 

a. Proceso por cada factorial a calcular: programa -> 16.a


b. El proceso padre tiene que esperar a los procesos hijos: programa -> 16.b


c. El mensaje del primer hijo no se imprime , pero los demas si: programa -> 16.c
 

17. Programa tiempo.c 


