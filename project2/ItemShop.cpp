#include "ItemShop.h"
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

    Item_Shop :: Item_Shop()
    {
    }
    //sets its own full arrays equal to the ones provided by the game class when initialized
    Item_Shop :: Item_Shop(equipment items[], potion potions[], const int item_size, const int potion_size)
    {
        for (int i = 0; i < 21; i++)
        {
            All_Items[i] = items[i];
        }
        for (int i = 0; i < 9; i++)
        {
            All_Potions[i] = potions[i];
        }
    }
    //randomizes numbers to pull from the item and potion arrays by index and sets those as the purchasable items and potions
    void Item_Shop :: storeRefresh()
    {
        srand(time(NULL));
        for (int i = 0; i < 3; i++)
        {
            int item_choice = rand() % item_size;
            while (All_Items[item_choice].price == 0)
            {
                item_choice = rand() % item_size;
            }

            int potion_choice = rand() % potion_size;
            if (All_Items[item_choice].price != 0)
            {
                items_for_sale[i] = All_Items[item_choice];
            }
            
            potions_for_sale[i] = All_Potions[potion_choice];
        }
        return;
    }
    
    //standard pass by reference and refitted menu structure with integrated input verification, calls other functions on input
    Entity Item_Shop ::  shopMenu(Entity player1)
    {
        Entity player = player1;
        int choice = 1;
        string menu_choice;
        int player_count = player.getPlayerCount();
        string menu0 = "Welcome to the Item Shop player ";
        string menuA = "! Select from the following options:"; 
        string menu1 = "1. Buy Item";
        string menu2 = "2. Buy Potion";
        string menu3 = "3. Sell Item";
        string menu4 = "4. Sell Potion";
        string menu5 = "5. Inventory status";
        string menu6 = "6. Leave Shop";
        do 
        {

            int menu = 0;
            int test = 0;

            do 
            {
                cout << endl << "----------------------------------------------" << endl;
                cout << endl;
                cout << menu0 << player_count << menuA << endl << menu1 << endl << menu2 << endl << menu3 << endl << menu4 << endl << menu5 << endl << menu6 << endl;
                cin >> menu_choice;

                while (menu_choice.length() == 0 || menu_choice.length() > 1) 
                {
                    cout << endl << "----------------------------------------------" << endl;
                    cout << endl;
                    cout << "Invalid input. Please enter a valid choice (1-6)" << endl;
                    cout << menu0 << player_count << menuA << endl << menu1 << endl << menu2 << endl << menu3 << endl << menu4 << endl << menu5 << endl << menu6 << endl;
                    cin >> menu_choice;
                }

                while (!isdigit(menu_choice[0])) 
                {
                    cout << endl << "----------------------------------------------" << endl;
                    cout << endl;
                    cout << "Invalid input. Please enter a valid choice (1-6)" << endl;
                    cout << menu0 << player_count << menuA << endl << menu1 << endl << menu2 << endl << menu3 << endl << menu4 << endl << menu5 << endl << menu6 << endl;
                    menu_choice = "";
                    cin >> menu_choice;
                }

                test = stoi(menu_choice);
                
                if (!(test < 7 && test > 0)) 
                {
                cout << "Invalid input. Please enter a valid choice (1-6)" << endl;
                }

            } while (!(test < 7 && test > 0));

            menu = stoi(menu_choice);
            choice = menu;

            //1 and 2 display all items and potions available to buy and entering a number will purchase that, if the player does not have enough money, it will ask if they want to sell, input verification included
            if (menu == 1) 
            {
                cout << endl;
                cout << "Items for sale:" << endl;
                for (int i = 0; i < 3; i++)
                {
                    if (items_for_sale[i].name != "" && items_for_sale[i].name != " ")
                    {
                        cout << "Name: " << items_for_sale[i].name << endl;

                        if (items_for_sale[i].type == 'D')
                        {
                            cout << "Type: Weapon" << endl;
                        }
                        else if (items_for_sale[i].type == 'S')
                        {
                            cout << "Type: Shield" << endl;
                        }
                        else if (items_for_sale[i].type == 'B')
                        {
                            cout << "Type: Mythical" << endl;
                        }
                        else if (items_for_sale[i].type == 'U')
                        {
                            cout << "Type: Unique" << endl;
                        }

                        cout << "Description: " << items_for_sale[i].description << endl;
                        cout << "Price: " << items_for_sale[i].price << endl;

                        if (items_for_sale[i].element == 'F')
                        {
                            cout << "Element: Fire" << endl;
                        }
                        else if (items_for_sale[i].element == 'W')
                        {
                            cout << "Element: Water" << endl;
                        }
                        else if (items_for_sale[i].element == 'A')
                        {
                            cout << "Element: Air" << endl;
                        }
                        else if (items_for_sale[i].element == 'E')
                        {
                            cout << "Element: Earth" << endl;
                        }

                        cout << "Owner: " << items_for_sale[i].owner << endl;

                        if (player.getName() == items_for_sale[i].owner)
                        {
                            cout << "Value: " << items_for_sale[i].alt_value << endl;
                        }
                        else 
                        {
                            cout << "Value: " << items_for_sale[i].value << endl;
                        }
                        cout << endl << "----------------------------------------------" << endl;
                    }
                }
                cout << endl;
                cout << "Which item would you like to purchase (1, 2, or 3)?" << endl;
                int purchase;
                cin >> purchase;
                while (purchase != 1 && purchase != 2 && purchase != 3)
                {
                    if (purchase == 1 || purchase == 2 || purchase == 3)
                    {
                        break;
                    }
                    else 
                    {
                        cout << endl << "----------------------------------------------" << endl;
                        cout << endl;
                        cout << "Not an available option, please try again" << endl;
                        purchase = 0;
                        cout << "What item would you like to purchase (1, 2, or 3)?" << endl;
                        cin >> purchase;
                    }
                }
                player = buyItem(player, purchase);
            }

            else if (menu == 2) 
            {
                cout << endl;
                cout << "Potions for sale:" << endl;
                for (int i = 0; i < 3; i++)
                {
                    if (potions_for_sale[i].name != "" && potions_for_sale[i].name != " ")
                    {
                        cout << endl;
                        cout << "Name: " << potions_for_sale[i].name << endl;

                        if (potions_for_sale[i].type == 'H')
                        {
                            cout << "Type: Healing" << endl;
                        }
                        else if (potions_for_sale[i].type == 'S')
                        {
                            cout << "Type: Stamina" << endl;
                        }
                        else if (potions_for_sale[i].type == 'B')
                        {
                            cout << "Type: Restoration" << endl;
                        }
                        else if (potions_for_sale[i].type == 'P')
                        {
                            cout << "Type: Medicine" << endl;
                        }
                        else if (potions_for_sale[i].type == 'D')
                        {
                            cout << "Type: Blessing of Ares" << endl;
                        }

                        cout << "Description: " << potions_for_sale[i].description << endl;
                        cout << "Price: " << potions_for_sale[i].price << endl;
                        cout << "Value:" << potions_for_sale[i].value << endl;
                        cout << endl << "----------------------------------------------" << endl;
                    }
                }
                cout << endl;
                cout << "Which potion would you like to purchase (1, 2, or 3)?" << endl;
                int potion_purchase;
                cin >> potion_purchase;
                while (potion_purchase != 1 && potion_purchase != 2 && potion_purchase != 3)
                {
                    if (potion_purchase == 1 || potion_purchase == 2 || potion_purchase == 3)
                    {
                        break;
                    }
                    else 
                    {
                        cout << endl << "----------------------------------------------" << endl;
                        cout << endl;
                        cout << "Not an available option, please try again" << endl;
                        potion_purchase = 0;
                        cout << "What potion would you like to purchase (1, 2, or 3)?" << endl;
                        cin >> potion_purchase;
                    }
                }
                player = buyPotion(player, potion_purchase);
            }

            //3 and 4 show the player what they can sell, and for potions how many they can sell
            else if (menu == 3)
            {
                cout << endl;
                cout << "Items available to sell:" << endl;
                cout << endl << "----------------------------------------------" << endl;
                cout << endl;
                player.displayBackpack();
                cout << endl << "----------------------------------------------" << endl;
                cout << endl;
                cout << "Which item would you like to sell (1 or 2)?" << endl;
                int sold_item;
                cin >> sold_item;
                while (sold_item != 1 && sold_item != 2)
                {
                    if (sold_item == 1 || sold_item == 2)
                    {
                        break;
                    }
                    else 
                    {
                        cout << endl << "----------------------------------------------" << endl;
                        cout << endl;
                        cout << "Not an available option, please try again." << endl;
                        sold_item = 0;
                        cout << "Which item would you like to sell (1 or 2)?" << endl;
                        cin >> sold_item;
                    }
                }
                player = sellItem(player, sold_item);
            }
                
            else if (menu == 4)
            {
                cout << endl << "----------------------------------------------" << endl;
                cout << endl;
                cout << "Potions available to sell:" << endl;
                player.displayPotions();
                cout << endl << "----------------------------------------------" << endl;
                cout << endl;
                cout << "Which potion would you like to sell (1, 2, or 3)?" << endl;
                int sold_potion;
                cin >> sold_potion;
                while (sold_potion != 1 && sold_potion != 2 && sold_potion != 3)
                {
                    if (sold_potion == 1 || sold_potion == 2 || sold_potion == 3)
                    {
                        break;
                    }
                    else 
                    {
                        cout << endl << "----------------------------------------------" << endl;
                        cout << endl;
                        cout << "Not an available option, please try again." << endl;
                        sold_potion = 0;
                        cout << "Which potion would you like to sell (1, 2, or 3)?" << endl;
                        cin >> sold_potion;
                    }
                }
                cout << endl << "----------------------------------------------" << endl;
                cout << endl;
                cout << "How many would you like to sell?" << endl << "You have " << player.getPotionsHeld(sold_potion) << " available." << endl;
                int number_sold;
                cin >> number_sold;
                while (number_sold <= 0 && number_sold < player.getPotionsHeld(sold_potion))
                {
                    if (number_sold > 0 && number_sold <= player.getPotionsHeld(sold_potion))
                    {
                        break;
                    }
                    else
                    {
                        cout << endl << "----------------------------------------------" << endl;
                        cout << endl;
                        cout << "Not an available option, please try again." << endl;
                        number_sold = 0;
                        cout << "How many would you like to sell?" << endl << "You have " << player.getPotionsHeld(sold_potion) << " available." << endl; 
                        cin >> number_sold;
                    }
                }

                for (int i = 0; i < number_sold; i++)
                {
                player = sellPotion(player, sold_potion);
                }
            }

            //shows the player how many open equipment slots, backpack slots, and potion slots they have as well as gold
            else if (menu == 5) 
            {
                cout << endl;
                cout << "You currently have: " << endl;
                cout << 2 - player.getEquipmentCount() << " equipment slots available" << endl;
                cout << 2 - player.getBackpackCount() << " backpack slots available" << endl;
                cout << 3 - player.getPotionCount() << " potion slots available" << endl;
                cout << player.getGold() << " gold" << endl;
                cout << "----------------------------------------------" << endl;
            }

            else if (menu == 6)
            {
                cout << endl;
                cout << "Good luck returning to your voyage, let's hope you bring some good stories back with you." << endl;
                cout << endl << "----------------------------------------------" << endl;
                break;
            }

        } while (choice < 7 && choice > 0);
    return player;
}


    //checks for available slot and enough gold, if either fail, offers to sell an item to make space/money
    Entity Item_Shop ::  buyItem(Entity player1, int selection)
    {
        Entity player = player1;
        if (player.getEquipmentCount() < 2 || player.getBackpackCount() < 2)
        {
            if (player.findEquipment(items_for_sale[selection - 1].name) == false)
            {
                if (player.getGold() >= items_for_sale[selection - 1].price)
                {
                player.setGold(player.getGold() - items_for_sale[selection - 1].price);
                player.setItem(items_for_sale[selection - 1]);
                cout << endl;
                cout << items_for_sale[selection - 1].name << " successfully purchased!" << endl;
                discardItem(items_for_sale[selection - 1].name);
                }
                else 
                {
                    cout << endl << "----------------------------------------------" << endl;
                    cout << endl;
                    cout << "You do not have enough money to purchase this item, would you like to sell an item to make money back?" << endl << "1. Yes" << "     " << "2. No" << endl;
                    int sell_choice;
                    cin >> sell_choice;
                    while (sell_choice != 1 && sell_choice != 2)
                    {
                        if (sell_choice == 1 || sell_choice == 2)
                        {
                            break;
                        }
                        else
                        {
                            cout << endl << "----------------------------------------------" << endl;
                            cout << endl;
                            cout << "Not an available option, please try again." << endl;
                            sell_choice = 0;
                            cout << "You do not have enough money to purchase this item, would you like to sell an item to make money back?" << endl << "1. Yes" << "     " << "2. No" << endl;
                            cin >> sell_choice;
                        }
                    }
                    if (sell_choice == 1)
                    {
                        cout << endl << "----------------------------------------------" << endl;
                        cout << endl;
                        cout << "Items available for sale:" << endl;
                        player.displayBackpack();
                        cout << "Which item would you like to sell (1 or 2)?" << endl;
                        int sold_item;
                        cin >> sold_item;
                        while (sold_item != 1 && sold_item != 2)
                        {
                            if (sold_item == 1 || sold_item == 2)
                            {
                                break;
                            }
                            else 
                            {
                                cout << endl << "----------------------------------------------" << endl;
                                cout << endl;
                                cout << "Not an available option, please try again." << endl;
                                sold_item = 0;
                                cout << "Which item would you like to sell (1 or 2)?" << endl;
                                cin >> sold_item;
                            }
                        }
                        player = sellItem(player, sold_item);
                    }
                    else if (sell_choice == 2)
                    {
                        cout << endl << "----------------------------------------------" << endl;
                        cout << endl;
                        cout << "May your equipment treat you well and carry you across the seas as you face the gods wrath, feel free to return anytime." << endl;
                        return player;
                    }
                }
            }
            else 
            {
                cout << endl << "----------------------------------------------" << endl;
                cout << endl;
                cout << "You already own this item and cannot purchase it again." << endl;
            }
        }
        else 
        {
            cout << endl << "----------------------------------------------" << endl;
            cout << endl;
            cout << "You do not have any available slots for this item, would you like to sell an item to make space?" << endl << "1. Yes" << "     " << "2. No" << endl;
            int sell_choice;
            cin >> sell_choice;
            while (sell_choice != 1 && sell_choice != 2)
            {
                if (sell_choice == 1 || sell_choice == 2)
                {
                    break;
                }
                else
                {
                    cout << endl << "----------------------------------------------" << endl;
                    cout << endl;
                    cout << "Not an available option, please try again." << endl;
                    sell_choice = 0;
                    cout << "You do not have any available slots for this item, would you like to sell an item to make space?" << endl << "1. Yes" << "     " << "2. No" << endl;
                    cin >> sell_choice;
                }
            }
            if (sell_choice == 1)
            {
                cout << endl << "----------------------------------------------" << endl;
                cout << endl;
                cout << "Items available for sale:" << endl;
                player.displayBackpack();
                cout << "Which item would you like to sell (1 or 2)?" << endl;
                int sold_item;
                cin >> sold_item;
                while (sold_item != 1 && sold_item != 2)
                {
                    if (sold_item == 1 || sold_item == 2)
                    {
                        break;
                    }
                    else 
                    {
                        cout << endl << "----------------------------------------------" << endl;
                        cout << endl;
                        cout << "Not an available option, please try again." << endl;
                        sold_item = 0;
                        cout << "Which item would you like to sell (1 or 2)?" << endl;
                        cin >> sold_item;
                    }
                }
                player = sellItem(player, sold_item);
            }
            else if (sell_choice == 2)
            {
                cout << endl << "----------------------------------------------" << endl;
                cout << endl;
                cout << "May your equipment treat you well and carry you across the seas as you face the gods wrath, feel free to return anytime." << endl;
                return player;
            }
        }
        return player;
    }  

    //functions same as buying an item just fitted for potions
    Entity Item_Shop ::  buyPotion(Entity player1, int selection)
    {
        Entity player = player1;
        if (player.getPotionCount() < 3 && player.findPotion(potions_for_sale[selection - 1].name) == false)
        {
            if (player.getGold() >= potions_for_sale[selection - 1].price)
            {
                player.setGold(player.getGold() - potions_for_sale[selection - 1].price);
                player.setPotion(potions_for_sale[selection - 1]);
                discardPotion(potions_for_sale[selection - 1].name);
            }
            else
            {
                cout << endl << "----------------------------------------------" << endl;
                cout << endl;
                cout << "You do not have enough money to purchase this item, would you like to sell a potion to make money back?" << "1. Yes" << "     " << "2. No" << endl;
                int sell_choice;
                cin >> sell_choice;
                while (sell_choice != 1 && sell_choice != 2)
                {
                    if (sell_choice == 1 || sell_choice == 2)
                    {
                        break;
                    }
                    else
                    {
                        cout << endl << "----------------------------------------------" << endl;
                        cout << endl;
                        cout << "Not an available option, please try again." << endl;
                        sell_choice = 0;
                        cout << "You do not have enough money to purchase this item, would you like to sell a potion to make money back?" << "1. Yes" << "     " << "2. No" << endl;
                        cin >> sell_choice;
                    }
                }
                if (sell_choice == 1)
                {
                    cout << endl << "----------------------------------------------" << endl;
                    cout << endl;
                    cout << "Potions available for sale:" << endl;
                    player.displayPotions();
                    cout << endl << "----------------------------------------------" << endl;
                    cout << endl;
                    cout << "Which potion would you like to sell (1, 2, or 3)?" << endl;
                    int sold_potion;
                    cin >> sold_potion;
                    while (sold_potion != 1 && sold_potion != 2 && sold_potion != 3)
                    {
                        if (sold_potion == 1 || sold_potion == 2 || sold_potion == 3)
                        {
                            break;
                        }
                        else 
                        {
                            cout << endl << "----------------------------------------------" << endl;
                            cout << endl;
                            cout << "Not an available option, please try again." << endl;
                            sold_potion = 0;
                            cout << "Which potion would you like to sell (1, 2, or 3)?" << endl;
                            cin >> sold_potion;
                        }
                    }
                    cout << endl << "----------------------------------------------" << endl;
                    cout << endl;
                    cout << "How many would you like to sell?" << endl << "You have " << player.getPotionsHeld(sold_potion) << " available." << endl;
                    int number_sold;
                    cin >> number_sold;
                    while (number_sold <= 0 && number_sold < player.getPotionsHeld(sold_potion))
                    {
                        if (number_sold > 0 && number_sold <= player.getPotionsHeld(sold_potion))
                        {
                            break;
                        }
                        else
                        {
                            cout << endl << "----------------------------------------------" << endl;
                            cout << endl;
                            cout << "Not an available option, please try again." << endl;
                            number_sold = 0;
                            cout << "How many would you like to sell?" << endl << "You have " << player.getPotionsHeld(sold_potion) << " available." << endl; 
                            cin >> number_sold;
                        }
                    }

                    for (int i = 0; i < number_sold; i++)
                    {
                    player = sellPotion(player, sold_potion);
                    }
                }
                if (sell_choice == 2)
                {
                    cout << endl << "----------------------------------------------" << endl;
                    cout << endl;
                    cout << "May the potions you carry treat you well and the gods favor your journey, feel free to return anytime." << endl;
                    return player;
                }
            }
        }

        else if (player.getPotionCount() == 3 && player.findPotion(potions_for_sale[selection - 1].name) == true)
        {
            if (player.getGold() >= potions_for_sale[selection - 1].price)
            {
                player.setGold(player.getGold() - potions_for_sale[selection - 1].price);
                player.setPotion(potions_for_sale[selection - 1]);
                discardPotion(potions_for_sale[selection - 1].name);
            }
            else
            {
                cout << endl << "----------------------------------------------" << endl;
                cout << endl;
                cout << "You do not have enough money to purchase this item, would you like to sell a potion to make money back?" << "1. Yes" << "     " << "2. No" << endl;
                int sell_choice;
                cin >> sell_choice;
                while (sell_choice != 1 && sell_choice != 2)
                {
                    if (sell_choice == 1 || sell_choice == 2)
                    {
                        break;
                    }
                    else
                    {
                        cout << endl << "----------------------------------------------" << endl;
                        cout << endl;
                        cout << "Not an available option, please try again." << endl;
                        sell_choice = 0;
                        cout << "You do not have enough money to purchase this item, would you like to sell a potion to make money back?" << "1. Yes" << "     " << "2. No" << endl;
                        cin >> sell_choice;
                    }
                }
                if (sell_choice == 1)
                {
                    cout << endl << "----------------------------------------------" << endl;
                    cout << endl;
                    cout << "Potions available for sale:" << endl;
                    player.displayPotions();
                    cout << endl << "----------------------------------------------" << endl;
                    cout << endl;
                    cout << "Which potion would you like to sell (1, 2, or 3)?" << endl;
                    int sold_potion;
                    cin >> sold_potion;
                    while (sold_potion != 1 && sold_potion != 2 && sold_potion != 3)
                    {
                        if (sold_potion == 1 || sold_potion == 2 || sold_potion == 3)
                        {
                            break;
                        }
                        else 
                        {
                            cout << endl << "----------------------------------------------" << endl;
                            cout << endl;
                            cout << "Not an available option, please try again." << endl;
                            sold_potion = 0;
                            cout << "Which potion would you like to sell (1, 2, or 3)?" << endl;
                            cin >> sold_potion;
                        }
                    }
                    cout << endl << "----------------------------------------------" << endl;
                    cout << endl;
                    cout << "How many would you like to sell?" << endl << "You have " << player.getPotionsHeld(sold_potion) << " available." << endl;
                    int number_sold;
                    cin >> number_sold;
                    while (number_sold <= 0 && number_sold < player.getPotionsHeld(sold_potion))
                    {
                        if (number_sold > 0 && number_sold <= player.getPotionsHeld(sold_potion))
                        {
                            break;
                        }
                        else
                        {
                            cout << endl << "----------------------------------------------" << endl;
                            cout << endl;
                            cout << "Not an available option, please try again." << endl;
                            number_sold = 0;
                            cout << "How many would you like to sell?" << endl << "You have " << player.getPotionsHeld(sold_potion) << " available." << endl; 
                            cin >> number_sold;
                        }
                    }

                    for (int i = 0; i < number_sold; i++)
                    {
                    player = sellPotion(player, sold_potion);
                    }
                }
                if (sell_choice == 2)
                {
                    cout << endl << "----------------------------------------------" << endl;
                    cout << endl;
                    cout << "May the potions you carry treat you well and the gods favor your journey, feel free to return anytime." << endl;
                    return player;
                }
            }
        }

        else
        {
            cout << "You do not have any available slots for this potion. Would you like to sell a potion to make space?" << endl << "1. Yes" << "     " << "2. No" << endl;
            int sell_choice;
            cin >> sell_choice;
            while (sell_choice != 1 && sell_choice != 2)
            {
                if (sell_choice == 1 || sell_choice == 2)
                {
                    break;
                }
                else
                {
                    cout << "Not an available option, please try again." << endl;
                    sell_choice = 0;
                    cout << "You do not have any available slots for this potion. Would you like to sell a potion to make space?" << endl << "1. Yes" << "     " << "2. No" << endl;
                    cin >> sell_choice;
                }
            }
            if (sell_choice == 1)
            {
                cout << "Potions available for sale:" << endl;
                player.displayPotions();
                cout << "Which potion would you like to sell (1, 2, or 3)?" << endl;
                int sold_potion;
                cin >> sold_potion;
                while (sold_potion != 1 && sold_potion != 2 && sold_potion != 3)
                {
                    if (sold_potion == 1 || sold_potion == 2 || sold_potion == 3)
                    {
                        break;
                    }
                    else 
                    {
                        cout << "Not an available option, please try again." << endl;
                        sold_potion = 0;
                        cout << "Which potion would you like to sell (1, 2, or 3)?" << endl;
                        cin >> sold_potion;
                    }
                }
                cout << "How many would you like to sell?" << endl << "You have " << player.getPotionsHeld(sold_potion) << " available." << endl;
                int number_sold;
                cin >> number_sold;
                while (number_sold <= 0 && number_sold < player.getPotionsHeld(sold_potion))
                {
                    if (number_sold > 0 && number_sold <= player.getPotionsHeld(sold_potion))
                    {
                        break;
                    }
                    else
                    {
                        cout << "Not an available option, please try again." << endl;
                        number_sold = 0;
                        cout << "How many would you like to sell?" << endl << "You have " << player.getPotionsHeld(sold_potion) << " available." << endl; 
                        cin >> number_sold;
                    }
                }

                for (int i = 0; i < number_sold; i++)
                {
                player = sellPotion(player, sold_potion);
                }
            }
            if (sell_choice == 2)
            {
                cout << "May the potions you carry treat you well and the gods favor your journey, feel free to return anytime." << endl;
                return player;
            }
        }
        return player;
    }

    //sets gold as current gold plus item or potion price, then clears that array index from the entity and returns it
    Entity Item_Shop :: sellItem(Entity player1, int selection)
    {
        Entity player = player1;
        player.setGold(player.getGold() + player.getStoredEquipment(selection - 1).price);
        player.discard(player.getStoredEquipment(selection - 1).name);
        return player;
    }

    Entity Item_Shop :: sellPotion(Entity player1, int selection)
    {
        Entity player = player1;
        player.setGold(player.getGold() + player.getPotion(selection).price);
        player.reducePotionsHeld(selection);
        return player;
    }

    //clears the array index using item or potion name, used to prevent duplicate purchases in the store
    void Item_Shop :: discardItem(string name)
    {
        for (int i = 0; i < 3; i++)
        {
            if (name == items_for_sale[i].name)
            {
                items_for_sale[i].name = " ";
                items_for_sale[i].description = " ";
                items_for_sale[i].element = ' ';
                items_for_sale[i].owner = " ";
                items_for_sale[i].value = 0;
                items_for_sale[i].alt_value = 0;
                items_for_sale[i].type = ' ';
                items_for_sale[i].price = 0;
            }
        }
        return;
    }

    void Item_Shop :: discardPotion(string name)
    {
        for (int i = 0; i < 3; i++)
        {
            if (name == potions_for_sale[i].name)
            {
                potions_for_sale[i].name = " ";
                potions_for_sale[i].description = " ";
                potions_for_sale[i].type =  ' ';
                potions_for_sale[i].element = ' ';
                potions_for_sale[i].value = 0;
                potions_for_sale[i].price = 0;
            }
        }
        return;
    }