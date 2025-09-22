#include <stdio.h>


#define MAX_PRODUCTOS 6
#define MAX_CARRITO 20


typedef struct {
    int id;
    char nombre[50];
    float precio;
} Producto;


typedef struct {
    Producto producto;
    int cantidad;
} ItemCarrito;

int main() {
  
    Producto catalogo[MAX_PRODUCTOS] = {
        {1, "Chocoramo", 3000},
        {2, "Salchichon Cervecero", 22000},
        {3, "Salchipapas", 25000},
        {4, "Chorizo Santarosano", 12000},
        {5, "Empanadas de pollo (5 und)", 13500},
        {6, "Gaseosa 1.5L", 9000}
    };

    ItemCarrito carrito[MAX_CARRITO];
    int itemsCarrito = 0;
    int opcion;
    float total = 0;

    do {
        printf("\n=== MENU PRINCIPAL ===\n");
        printf("1. menu de productos\n");
        printf("2. Agregar producto al carrito\n");
        printf("3. Ver carrito y total\n");
        printf("4. Confirmar pedido\n");
        printf("5. Salir\n");
        printf("Seleccione una opcion: ");
        scanf("%d", &opcion);

        switch(opcion) {
            case 1: 
                printf("\n--- MENU DE PRODUCTOS ---\n");
                for (int i = 0; i < MAX_PRODUCTOS; i++) {
                    printf("%d. %s - $%.2f\n", catalogo[i].id, catalogo[i].nombre, catalogo[i].precio);
                }
                break;

            case 2: { 
                int id, cantidad, encontrado = 0;
                printf("\nIngrese el ID del producto a agregar: ");
                scanf("%d", &id);
                printf("Ingrese la cantidad: ");
                scanf("%d", &cantidad);

                if (cantidad <= 0) {
                    printf("⚠️ La cantidad debe ser mayor a 0.\n");
                    break;
                }

                for (int i = 0; i < MAX_PRODUCTOS; i++) {
                    if (catalogo[i].id == id) {
                        encontrado = 1;
                        carrito[itemsCarrito].producto = catalogo[i];
                        carrito[itemsCarrito].cantidad = cantidad;
                        itemsCarrito++;
                        printf("✅ Producto agregado al carrito.\n");
                        break;
                    }
                }
                if (!encontrado) {
                    printf("❌ Producto no encontrado.\n");
                }
                break;
            }

            case 3: 
                printf("\n--- CARRITO ---\n");
                total = 0;
                if (itemsCarrito == 0) {
                    printf("Carrito vacio.\n");
                } else {
                    for (int i = 0; i < itemsCarrito; i++) {
                        float subtotal = carrito[i].producto.precio * carrito[i].cantidad;
                        printf("%s x%d - $%.2f\n", carrito[i].producto.nombre, carrito[i].cantidad, subtotal);
                        total += subtotal;
                    }
                    printf("------------------------\n");
                    printf("Subtotal: $%.2f\n", total);
                    float domicilio = 5000; 
                    printf("Domicilio: $%.2f\n", domicilio);
                    printf("TOTAL: $%.2f\n", total + domicilio);
                }
                break;

            case 4: 
                if (itemsCarrito == 0) {
                    printf("⚠️ No puede confirmar un pedido vacio.\n");
                } else {
                    printf("\n✅ Pedido confirmado. Proximo a tu Domicilio.\n");
                    
                    itemsCarrito = 0;
                    total = 0;
                }
                break;

            case 5:
                printf("👋 Gracias por usar nuestra app para tus domicilios.\n");
                break;

            default:
                printf("⚠️ Opcion invalida.\n");
                break;
        }

    } while (opcion != 5);

    return 0;
}
