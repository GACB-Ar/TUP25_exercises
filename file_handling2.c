#include <stdio.h>
void user_requests(int param, FILE *file_param);

int main()
{
    FILE *archive;

    archive = fopen("names.txt", "w");

    /*
        "r" -> Leer (el archivo debe existir)
        "w" -> Escribir (crea el archivo o lo sobreescribe si ya existe)
        "a" -> Agregar (append) al final del archivo
        "r+" -> Leer y escribir (el archivo debe existir)
        "w+" -> Leer y escribir (borra el contenido anterior)
        "a+" -> Leer y agregar (no borra el contenido anterior)
    */
    return 0;
}
