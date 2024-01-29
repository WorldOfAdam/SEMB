#include <stdlib.h>


int main(int argc, char **argv) {

    while(1);

    return EXIT_SUCCESS;
}

// Compilar até, imediatamente antes, a etapa de Linkagem
// > arm-none-eabi-gcc main.c -c -O0 -mcpu=cortex-m4 -mthumb -Wall

// Verificar as seções do arquivo objeto criado
// > arm-none-eabi-objdump -h main.o

// Verificar uma seção específica
// > arm-none-eabi-objdump -s .data main.o (?)