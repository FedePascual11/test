#include <stdio.h>
#include <string.h>

#define SEMILLADJB 42
#define PASODJB 3
#define NDJB 10

typedef unsigned int Natural;

void readAndHashLn(Natural semilla, Natural paso, Natural N, Natural *codigo) {
    char input[1000]; // Ajusta el tamaño según tus necesidades
    char charInput;
    int i = 0;

    // Lee la entrada estándar hasta encontrar '.'
    do {
        charInput = getchar();
        input[i++] = charInput;
    } while (charInput != '.' && i < sizeof(input) - 1);

    input[i] = '\0'; // Agrega el terminador nulo al final de la cadena

    // Calcula el código de hash
    *codigo = semilla;
    for (i = 0; i < strlen(input) - 1; ++i) {
        *codigo = (*codigo * paso + input[i]) % N;
    }
}

void writeFallo(int intentos) {
    printf("Intento fallido. Intentos restantes: %d\n", intentos);
}

void login(Natural codigo, int intentos, int *ok) {
    Natural inputCodigo;
    int i;

    for (i = 0; i < intentos; ++i) {
        // Lee la contraseña y calcula el código de hash
        readAndHashLn(SEMILLADJB, PASODJB, NDJB, &inputCodigo);

        // Compara el código de hash
        if (inputCodigo == codigo) {
            *ok = 1; // Login exitoso
            return;
        } else {
            // Muestra información del fallo
            writeFallo(intentos - i - 1);
        }
    }

    // Si llega aquí, el login no fue exitoso
    *ok = 0;
}

int main() {
    Natural codigo;
    int intentos = 3; // Puedes ajustar el número de intentos según tus necesidades
    int ok;

    // Realiza el login
    login(codigo, intentos, &ok);

    // Verifica el resultado del login
    if (ok) {
        printf("Login exitoso\n");
    } else {
        printf("Login fallido\n");
    }

    return 0;
}

