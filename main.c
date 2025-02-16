// Declaraciones estructuradas para piezas y tableros
typedef struct {
    float ancho;
    float alto;
} Rectangulo;

typedef struct {
    float ancho;
    float alto;
    // Podríamos agregar un identificador del tipo de material si fuera necesario
    char tipo[20];
} Tablero;

// Función para ajustar dimensiones según el kerf
float ajuste_corte(float dimension) {
    return dimension - 0.3; // restamos 3mm = 0.3cm
}

// Función principal
int main() {
    // Declarar variables y estructuras necesarias
    Tablero tablero;
    int opcion;
    int numPiezas;
    Rectangulo *piezas;
    
    // 1. Entrada de datos
    printf("Seleccione el tipo de tablero (1: Contrachapados, 2: MDF, 3: Aglomerados): ");
    scanf("%d", &opcion);
    // Asignar tipo según opción...
    
    // Preguntar si se usará el tamaño por defecto
    char usar_defecto;
    printf("¿Usar dimensiones por defecto (244x122 cm)? (s/n): ");
    scanf(" %c", &usar_defecto);
    if(usar_defecto == 's' || usar_defecto == 'S') {
        tablero.ancho = 244;
        tablero.alto = 122;
    } else {
        printf("Ingrese el ancho del tablero (cm): ");
        scanf("%f", &tablero.ancho);
        printf("Ingrese el alto del tablero (cm): ");
        scanf("%f", &tablero.alto);
    }
    
    // Ingreso de piezas a cortar
    printf("Ingrese el número de piezas a cortar: ");
    scanf("%d", &numPiezas);
    piezas = malloc(numPiezas * sizeof(Rectangulo));
    for (int i = 0; i < numPiezas; i++) {
        printf("Pieza %d - Ingrese ancho (cm): ", i+1);
        scanf("%f", &piezas[i].ancho);
        printf("Pieza %d - Ingrese alto (cm): ", i+1);
        scanf("%f", &piezas[i].alto);
    }
    
    // 2. Procesamiento: Llamar a la función de asignación de piezas a tableros
    // Aquí se implementarían las funciones que prueban la estrategia H-V y V-H
    // y determinan la mejor forma de distribuir las piezas.
    // La función puede ser algo similar a:
    // int numTableros = calcular_tableros(tablero, piezas, numPiezas, &planDeCortes);
    
    // 3. Salida: Mostrar resultados
    // printf("Número de tableros necesarios: %d\n", numTableros);
    // Imprimir diagrama visual y lista de cortes.
    
    // Liberar memoria y finalizar
    free(piezas);
    return 0;
}
