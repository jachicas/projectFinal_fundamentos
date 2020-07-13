#include <iostream>
#include <iomanip>

using namespace std;

// Declarando la estructura donde se almacenaran los datos
const int longCad = 20;
struct costoPorArticulo
{
    char nombreArticul[longCad + 1];
    int cantidad;
    float precio, costoPorArticulo;
};

// Declarando todas las funciones que se utilizaran
void addArticulo(costoPorArticulo *, int);
void showArticulo(costoPorArticulo *, int);
float costo(float, int);
float suma(costoPorArticulo *, int);

int main()
{
    /*
        Declarando la variables de la cantidad de articulos que ingresara
        Se declara la variables opcion que servira para elegir una nueva compra o salir
    */
    int cantidadArticulos = 0, opcion;
    cout << "-- BIENVENIDO A LA TIENDA --" << endl;
    // Se hace un while para validar que no se ingrese numeros negativos ni 0
    while (cantidadArticulos < 1)
    {
        cout << "Ingrese la cantidad de productos que comprara" << endl;
        cin >> cantidadArticulos;
    }
    // Se declara el array y se crea un puntero de tipo struct costoPorArticulo
    costoPorArticulo *articulos = new costoPorArticulo[cantidadArticulos];
    /*
        Se llama a la funcion para agregar y
        mostrar articulos, recibe la direccion de inicio
        y la cantidad de valores que debe almacenar 
    */
    addArticulo(articulos, cantidadArticulos);
    showArticulo(articulos, cantidadArticulos);
    /*
        Imprimiendo el coste total llamando a la funcion suma()
        setprecision() y fixed son funciones traidas de la libreria iomanip
    */
    cout << "\n \t ---- El coste total de la compra es de $" 
         << setprecision(2)
         << fixed
         << suma(articulos, cantidadArticulos)
         << " ----"
         << endl
         << endl;
    // Pidiendo al usuario si desea hacer una nueva compra o salir
    cout << "Desea realizar una nueva compra? \n 1) Si \n 0) No" << endl;
    cin >> opcion;
    // Si el usuario elige 1 se ejecuta el main, si elige 0 se sale
    if (opcion == 1)
    {
        main();
    }
    else
    {
        cout << "\n \t -- Gracias por su compra, los esperamos pronto --" << endl
             << endl;
        return 0;
    }
}

void addArticulo(costoPorArticulo *dato, int cantidadArticulos)
{
    // Este for se cerrara segun la cantidad de datos que el usuario pidio, con (datos+i) se iran agregando
    for (int i = 0; i < cantidadArticulos; i++)
    {
        cout << "Ingrese el nombre de su articulo " << i + 1 << endl;
        cin >> (dato + i)->nombreArticul;
        while (((dato + i)->cantidad) < 1)
        {
            cout << "Ingrese la cantidad que comprara de " << (dato + i)->nombreArticul << endl;
            cin >> (dato + i)->cantidad;
        }
        cout << "Ingrese el precio de " << (dato + i)->nombreArticul << endl;
        cin >> (dato + i)->precio;
        (dato + i)->costoPorArticulo = costo((dato + i)->precio, (dato + i)->cantidad);
    }
}

void showArticulo(costoPorArticulo *dato, int cantidadArticulos)
{
    cout << "\t\t\t-- Detalle de productos --\n\n";
    cout << "\t|Nombre \t"
         << "|Cantidad \t"
         << "|Precio \t"
         << "|Costo por Articulo \n";
    cout << "\t------------------------------------------------------------------------- \n";
    for (int i = 0; i < cantidadArticulos; i++)
    {
        cout << "\t|" << (dato + i)->nombreArticul << "\t \t|"
             << (dato + i)->cantidad << "\t \t|"
             << setprecision(2) << fixed << (dato + i)->precio << "\t \t|"
             << setprecision(2) << fixed << (dato + i)->costoPorArticulo << "\n";
    }
}

float costo(float precio, int cantidad)
{
    return precio * cantidad;
}

float suma(costoPorArticulo *dato, int cantidadArticulos)
{
    float sumaTotal = 0;
    for (int i = 0; i < cantidadArticulos; i++)
    {
        sumaTotal = sumaTotal + (dato + i)->costoPorArticulo;
    }
    return sumaTotal;
}
