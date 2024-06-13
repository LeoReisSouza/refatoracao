#include <stdio.h>
#include "GildedRose.h"

// Função para imprimir informações de um item
void print_item(const Item *item) {
    printf("%s, %d, %d\n", item->name, item->sellIn, item->quality);
}

int main() {
    Item items[9];
    int last = 0;

    // Inicialização dos itens
    init_item(&items[last++], "+5 Dexterity Vest", 10, 20);
    init_item(&items[last++], "Aged Brie", 2, 0);
    init_item(&items[last++], "Elixir of the Mongoose", 5, 7);
    init_item(&items[last++], "Sulfuras, Hand of Ragnaros", 0, 80);
    init_item(&items[last++], "Sulfuras, Hand of Ragnaros", -1, 80);
    init_item(&items[last++], "Backstage passes to a TAFKAL80ETC concert", 15, 20);
    init_item(&items[last++], "Backstage passes to a TAFKAL80ETC concert", 10, 49);
    init_item(&items[last++], "Backstage passes to a TAFKAL80ETC concert", 5, 49);
    init_item(&items[last++], "Conjured Mana Cake", 3, 6);

    puts("OMGHAI!");

    for (int day = 0; day <= 30; day++) {
        printf("-------- day %d --------\n", day);
        printf("name, sellIn, quality\n");
        for (int index = 0; index < last; index++) {
            print_item(&items[index]);
        }
        printf("\n");

        update_quality(items, last);
    }

    return 0;
}