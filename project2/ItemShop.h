#ifndef ITEMSHOP_H
#define ITEMSHOP_H
#include "Entity.h"
#include <iostream>

class Item_Shop
{
    public:
    Item_Shop();
    Item_Shop(equipment items[], potion potions[], const int item_size, const int potion_size);
    //re-randomizes available gear in the store menu
    void storeRefresh();
    //shows available gear for purchase and options to sell
    Entity shopMenu(Entity player);

    Entity buyItem(Entity player, int selection);
    Entity buyPotion(Entity player, int selection);

    Entity sellItem(Entity player, int selection);
    Entity sellPotion(Entity player, int selection);
    //clears the array index on purchase
    void discardItem(string name);
    void discardPotion(string name);

    private:
    //an array for available items and potions, and the full arrays to select from
    equipment items_for_sale[3];
    potion potions_for_sale[3];
    equipment All_Items[21];
    potion All_Potions[9];
    const int item_size = 21;
    const int potion_size = 9;
};
#endif