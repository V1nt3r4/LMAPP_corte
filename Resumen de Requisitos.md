Resumen de Requisitos
Tipos de material: Contrachapados, MDF y aglomerados (podrías usar esta información para, por ejemplo, asignar precios o características específicas en una versión futura).

Dimensiones del tablero: Por defecto 244 × 122 cm, pero el usuario podrá ingresar otras dimensiones.

Kerf (pérdida por corte): 3 mm (0.3 cm) se pierden en cada corte.

Interfaz interactiva: Entrada a través de consola (o similar) que permita al usuario ingresar las dimensiones del tablero y de las piezas.

Rotación de piezas: Las piezas pueden ser cortadas en orientación vertical u horizontal para optimizar el uso.

Orden de cortes: Se deben realizar cortes de punta a punta. Se considerarán dos estrategias:

Cortes primero en horizontal y luego en vertical.
Cortes primero en vertical y luego en horizontal.
La aplicación evaluará cuál de los dos órdenes permite aprovechar mejor el tablero, siempre asegurando que cada pieza salga completa.

Optimización: Se buscará aprovechar al máximo el material, pero lo esencial es que todas las piezas queden completas.

Salida:

Número de tableros necesarios.
Diagrama visual (por ejemplo, mediante un esquema en ASCII) del corte en cada tablero.
Lista paso a paso con el orden de corte.
Diseño General de la Aplicación
1. Módulo de Entrada
Selección del tipo de tablero: Permitir al usuario elegir entre Contrachapados, MDF y aglomerados (aunque, en la versión inicial, esto puede servir solo para etiquetar el resultado).
Entrada de dimensiones del tablero:
Opción de usar la medida por defecto (244×122 cm) o ingresar otras dimensiones.
Entrada de las piezas a cortar:
Preguntar cuántas piezas se necesitan y, para cada una, sus dimensiones (ancho y alto en cm).
Permitir que el usuario ingrese si la pieza puede rotarse (en nuestro caso, siempre es posible la rotación).
2. Módulo de Procesamiento (Algoritmo de Corte)
Dado que se trata de un problema de corte con “guillotina” (cortes de punta a punta), se puede plantear el siguiente enfoque:

Ajuste por kerf:
Cada vez que se realiza un corte (ya sea horizontal o vertical), se debe descontar 0.3 cm de la dimensión de la pieza resultante. Por ejemplo, si se realiza un corte horizontal en un tablero de 244 cm de largo, el corte separa dos piezas que juntas perderán 0.3 cm de la dimensión total.

Estrategias de corte:
Implementar dos estrategias para cada tablero:

Estrategia H-V:
Realizar primero cortes horizontales para dividir el tablero en franjas.
En cada franja, realizar los cortes verticales para obtener las piezas requeridas.
Estrategia V-H:
Realizar primero cortes verticales para dividir el tablero en columnas.
En cada columna, hacer cortes horizontales.
Heurística de asignación:

Ordena las piezas según algún criterio (por ejemplo, área o el lado mayor) para intentar colocar primero las piezas más grandes.
Para cada tablero, intenta “empaquetar” las piezas siguiendo la estrategia H-V y luego la V-H.
Evalúa cuál de las dos estrategias permite colocar más piezas sin desperdiciar material y sin que se corten las piezas.
Si en un tablero no caben todas las piezas planificadas, inicia otro tablero y repite el proceso hasta asignar todas las piezas.
Generación del plan de cortes:
Una vez determinada la estrategia óptima para cada tablero, se genera una lista secuencial de cortes:

Orden de corte:
Por ejemplo, “Cortar horizontalmente a 100 cm para obtener la franja A” y luego “Cortar verticalmente en la franja A a 50 cm y a 80 cm…”, teniendo en cuenta que cada corte afecta las dimensiones debido al kerf.
3. Módulo de Salida
Informe en consola:
Cantidad de tableros necesarios.
Diagrama visual:
Un esquema sencillo (por ejemplo, usando caracteres) que muestre cómo se subdivide cada tablero.
Lista paso a paso:
Una serie de instrucciones detalladas, en el orden en que se deben realizar los cortes, incluyendo las posiciones de los cortes y las dimensiones resultantes en cada paso.