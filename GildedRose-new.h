#ifndef ROSE_INCLUDED
#define ROSE_INCLUDED

#include <stddef.h>

typedef struct {
    char *name;  // Nome do item
    int sellIn;  // Dias para vender o item
    int quality; // Qualidade do item
} Item;

// Função para inicializar um item
// Retorna: ponteiro para o item inicializado
Item* init_item(Item* item, const char *name, int sellIn, int quality);

// Função para atualizar a qualidade de uma lista de itens
void update_quality(Item items[], size_t size);

// Função para formatar as informações de um item em um buffer
char* print_item(char* buffer, const Item* item);

#endif
