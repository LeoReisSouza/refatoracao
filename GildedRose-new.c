#include <string.h>
#include "GildedRose.h"
#include <stdio.h>
#include <stdlib.h>

Item* init_item(Item* item, const char *name, int sellIn, int quality) {
    item->sellIn = sellIn;
    item->quality = quality;
    item->name = strdup(name); 
    return item;
}

void print_item(char* buffer, const Item* item) {
    sprintf(buffer, "%s, %d, %d", item->name, item->sellIn, item->quality);
}

void adjust_quality(Item* item, int change) {
    item->quality += change;
    if (item->quality < 0) item->quality = 0;
    if (item->quality > 50) item->quality = 50;
}

void update_quality(Item items[], int size) {
    for (int i = 0; i < size; i++) {
        Item* item = &items[i];

        if (strcmp(item->name, "Sulfuras, Hand of Ragnaros") != 0) {
            item->sellIn--; // Decrementa o valor de sellIn para todos os itens, exceto "Sulfuras"
            if (strcmp(item->name, "Aged Brie") == 0) {
                
                adjust_quality(item, 1);
            } else if (strcmp(item->name, "Backstage passes to a TAFKAL80ETC concert") == 0) {
                if (item->sellIn < 0) {
                    item->quality = 0; // Qualidade zera após o concerto
                } else if (item->sellIn < 5) {
                    adjust_quality(item, 3);
                } else if (item->sellIn < 10) {
                    adjust_quality(item, 2);
                } else {
                    adjust_quality(item, 1);
                }
            } else {
                adjust_quality(item, -1);
            }

            if (item->sellIn < 0) {
                if (strcmp(item->name, "Aged Brie") == 0) {
                    adjust_quality(item, 1); 
                } else if (strcmp(item->name, "Backstage passes to a TAFKAL80ETC concert") != 0) {
                    adjust_quality(item, -1);                 }
            }
        }
    }
}
