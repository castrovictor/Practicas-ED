# Práctica final: Who is Who?
> Realizada por Víctor Castro Serrano y Maximino Suárez van Gelderen.
> Estructura de datos, DGIIM, UGR. Curso 2017-2018

## Árbol mejorado
Al iniciar el juego, se pregunta al usuario si desea el modo de juego mejorado. En caso afirmativo, se construye el árbol de preguntas optimizado, de forma que se minimice el número de preguntas neecsarias para averiguar el personaje. En caso contrario, las preguntas se realizan en el orden que marcan los atributos del tablero.
La mejora del árbol consiste en calcular, con respecto al número de personajes que quedan, qué atributo tiene una proporción más cercana a 0.5 en cuanto a personajes que lo tienen que no lo tienen. De esta manera, en cada respuesta, descartaremos el número de personajes más cercano a la mitad de los restantes que permita descartar el tablero, optimizando notablemente el juego.

## Añadir personaje
Esta opción también se le plantea al jugador cuando inicia el juego. El personaje se añade tras crear el árbol y sin reconstruirlo. Para ello, el jugador introduce los atributos del personaje (que deben corresponderse con el tablero cargado) y calculamos en que parte del árbol hay que insertarlo.

## Eliminar personaje
Finalmente, el jugador dispone de una opción para eliminar un personaje.

Cuando se añade o elimina personaje, se imprime cómo queda el árbol de preguntas, pudiendo apreciar los cambios realizados si así lo hemos decidido. El makefile dispone de una orden *jugar* de forma que cuando hagamos ``make jugar`` podamos compilar y cargar automáticamente un tablero por defecto para probar el juego.
