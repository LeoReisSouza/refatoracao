#ifndef ROSE_INCLUDED
#define ROSE_INCLUDED

#include <stddef.h> 

typedef struct {
    char *name;  
    int sellIn;  
    int quality; 
} Item;

// Função para inicializar um item
// Retorna: ponteiro para o item inicializado
Item* init_item(Item* item, const char *name, int sellIn, int quality);

// Função para atualizar a qualidade de uma lista de itens
void update_quality(Item items[], size_t size);

// Função para formatar as informações de um item em um buffer
// Retorna: ponteiro para o buffer contendo as informações formatadas
char* print_item(char* buffer, const Item* item);

#endif
