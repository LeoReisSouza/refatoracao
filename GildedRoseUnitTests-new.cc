#include <CppUTest/TestHarness.h>
#include <CppUTest/CommandLineTestRunner.h>
#include <CppUTestExt/MockSupport.h>

extern "C" {
#include "GildedRose.h"
}

TEST_GROUP(TestGildedRoseGroup) {
    void setup() {}
    void teardown() {}
};

// Teste para verificar o aumento da qualidade do "Aged Brie"
TEST(TestGildedRoseGroup, AgedBrieIncreasesInQuality) {
    Item items[1];
    init_item(items, "Aged Brie", 2, 0);
    update_quality(items, 1);
    LONGS_EQUAL(1, items[0].quality);
}

// Teste para verificar que a qualidade das "Sulfuras" não muda
TEST(TestGildedRoseGroup, SulfurasQualityUnchanged) {
    Item items[1];
    init_item(items, "Sulfuras, Hand of Ragnaros", 0, 80);
    update_quality(items, 1);
    LONGS_EQUAL(80, items[0].quality);
}

// Teste para verificar o aumento da qualidade dos "Backstage Passes"
TEST(TestGildedRoseGroup, BackstagePassesIncreaseInQuality) {
    Item items[1];
    init_item(items, "Backstage passes to a TAFKAL80ETC concert", 15, 20);
    update_quality(items, 1);
    LONGS_EQUAL(21, items[0].quality);
}

// Teste para verificar o aumento da qualidade dos "Backstage Passes" a 10 dias ou menos
TEST(TestGildedRoseGroup, BackstagePassesIncreaseByTwoWhenTenDaysOrLess) {
    Item items[1];
    init_item(items, "Backstage passes to a TAFKAL80ETC concert", 10, 20);
    update_quality(items, 1);
    LONGS_EQUAL(22, items[0].quality);
}

// Teste para verificar o aumento da qualidade dos "Backstage Passes" a 5 dias ou menos
TEST(TestGildedRoseGroup, BackstagePassesIncreaseByThreeWhenFiveDaysOrLess) {
    Item items[1];
    init_item(items, "Backstage passes to a TAFKAL80ETC concert", 5, 20);
    update_quality(items, 1);
    LONGS_EQUAL(23, items[0].quality);
}

// Teste para verificar que a qualidade dos "Backstage Passes" cai para zero após a data de venda
TEST(TestGildedRoseGroup, BackstagePassesDropToZeroAfterConcert) {
    Item items[1];
    init_item(items, "Backstage passes to a TAFKAL80ETC concert", 0, 20);
    update_quality(items, 1);
    LONGS_EQUAL(0, items[0].quality);
}

TEST(TestGildedRoseGroup, ConjuredItemsDegradeTwiceAsFast) {
    Item items[1];
    init_item(items, "Conjured Mana Cake", 3, 6);
    update_quality(items, 1);
    LONGS_EQUAL(4, items[0].quality);
}

TEST(TestGildedRoseGroup, ConjuredItemsDegradeTwiceAsFastAfterSellIn) {
    Item items[1];
    init_item(items, "Conjured Mana Cake", 0, 6);
    update_quality(items, 1);
    LONGS_EQUAL(2, items[0].quality);
}

int main(int ac, char** av) {
       return CommandLineTestRunner::RunAllTests(ac, av);
}
