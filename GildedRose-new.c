#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "GildedRose.h"

// Função para inicializar um item
Item* init_item(Item* item, const char *name, int sellIn, int quality) {
    item->sellIn = sellIn;
    item->quality = quality;
    item->name = strdup(name); 
    return item;
}

// Função para formatar as informações de um item em um buffer
void print_item(char* buffer, const Item* item) {
    sprintf(buffer, "%s, %d, %d", item->name, item->sellIn, item->quality);
}

// Função auxiliar para ajustar a qualidade com limite
void adjust_quality(Item* item, int change) {
    item->quality += change;
    if (item->quality < 0) item->quality = 0;
    if (item->quality > 50) item->quality = 50;
}

// Função para atualizar a qualidade dos itens
void update_quality(Item items[], size_t size) {
    for (size_t i = 0; i < size; i++) {
        Item* item = &items[i];

        if (strcmp(item->name, "Sulfuras, Hand of Ragnaros") == 0) {
            // "Sulfuras" é um item lendário, não muda qualidade ou sellIn
            continue;
        }

        item->sellIn--;

        if (strcmp(item->name, "Aged Brie") == 0) {
            adjust_quality(item, 1);
            if (item->sellIn < 0) {
                adjust_quality(item, 1);
            }
        } else if (strcmp(item->name, "Backstage passes to a TAFKAL80ETC concert") == 0) {
            if (item->sellIn < 0) {
                item->quality = 0; 
            } else if (item->sellIn < 5) {
                adjust_quality(item, 3); 
            } else if (item->sellIn < 10) {
                adjust_quality(item, 2); 
            } else {
                adjust_quality(item, 1); 
            }
        } else {
            adjust_quality(item, -1);
            if (item->sellIn < 0) {
                adjust_quality(item, -1); 
            }
        }
    }
}
