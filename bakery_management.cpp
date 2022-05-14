#include <iostream>
#include <conio.h>
#include <windows.h>
using namespace std;
int total_bis, total_bun, total_roll = 0;
int total_muf, total_cake, total_pie = 0;
int total_waffle, total_ice, total_bread = 0;

void cls()
{

    system("cls");
}

class bakery_admin
{
private:
    int biscuits_pr = 0, buns_pr, rolls_pr, muffin_pr, butter_cake_pr = 0;
    int pie_pr, ice_creams_pr = 0, waffles_pr, bread_pr = 0;
    int biscuits, buns, rolls, muffin = 0, butter_cake = 0;
    int pie = 0, ice_creams, waffles = 0, bread = 0;

public:
    bool auth_user()
    {
        string pass;
        string password = "admin";
        cout << "\n\tEnter the Password to continue : ";
        cin >> pass;
        if (!password.compare(pass))
        {
            return true;
        }
        return false;
    }
    void set_Stock()
    {
        cout << "\n\tEnter the Count of Biscuits : ";
        cin >> biscuits;
        cout << "\tEnter the price of one Biscuit : ";
        cin >> biscuits_pr;
        cout << "\n\tEnter the Count of Buns : ";
        cin >> buns;
        cout << "\tEnter the price of one Bun : ";
        cin >> buns_pr;
        cout << "\n\tEnter the Count of Rolls : ";
        cin >> rolls;
        cout << "\tEnter the price of one Roll : ";
        cin >> rolls_pr;
        cout << "\n\tEnter the Count of Muffins : ";
        cin >> muffin;
        cout << "\tEnter the price of one Muffin : ";
        cin >> muffin_pr;
        cout << "\n\tEnter the Count of Butter cake : ";
        cin >> butter_cake;
        cout << "\tEnter the price of one Butter cake : ";
        cin >> butter_cake_pr;
        cout << "\n\tEnter the Count of Pie : ";
        cin >> pie;
        cout << "\tEnter the price of one Pie : ";
        cin >> pie_pr;
        cout << "\n\tEnter the Count of Ice cream : ";
        cin >> ice_creams;
        cout << "\tEnter the price of one ice cream : ";
        cin >> ice_creams_pr;
        cout << "\n\tEnter the Count of Waffles : ";
        cin >> waffles;
        cout << "\tEnter the price of one Waffle : ";
        cin >> waffles_pr;
        cout << "\n\tEnter the Count of Bread : ";
        cin >> bread;
        cout << "\tEnter the price of one Bread : ";
        cin >> bread_pr;
    }
    friend void display(bakery_admin);
    friend class bakery_custm;
};

void display(bakery_admin product)
{
    cout << "\n\t\t";
    cout << "---------------------------------------------------------";
    cout << "\n\t\t";
    cout << "|      Item Name    |  \t    Quantity      |     Rate    |";
    cout << "\n\t\t";
    cout << "|-------------------------------------------------------|";
    cout << "\n\t\t";
    cout << "|1.     Biscuits "
         << "    |  \t" << product.biscuits << "        |      " << product.biscuits_pr << "      |" << endl;
    cout << "\t\t|2.       Buns "
         << "      |  \t" << product.buns << "        |      " << product.buns_pr << "      |" << endl;
    cout << "\t\t|3.   Chicken Rolls "
         << " |     \t" << product.rolls << "        |      " << product.rolls_pr << "     |" << endl;
    cout << "\t\t|4. Chocolate Muffin"
         << " |    \t" << product.muffin << "        |      " << product.muffin_pr << "     |" << endl;
    cout << "\t\t|5.   Butter Cake "
         << "   |  \t" << product.butter_cake << "         |      " << product.butter_cake_pr << "     |" << endl;
    cout << "\t\t|6.    Apple Pie "
         << "    |  \t" << product.pie << "        |      " << product.pie_pr << "     |" << endl;
    cout << "\t\t|7.    Ice Cream "
         << "    |  \t" << product.ice_creams << "        |      " << product.ice_creams_pr << "     |" << endl;
    cout << "\t\t|8.     Waffles "
         << "     |  \t" << product.waffles << "        |      " << product.waffles_pr << "     |" << endl;
    cout << "\t\t|9.      Bread"
         << "       |  \t" << product.bread << "        |      " << product.bread_pr << "     |";
    cout << "\n\t\t";
    cout << "---------------------------------------------------------";
    cout << "\n\n";
}

class bakery_custm
{

public:
    int quant_1 = 0, quant_2 = 0, quant_3 = 0, quant_4 = 0, quant_5 = 0, quant_6 = 0, quant_7 = 0, quant_8 = 0, quant_9 = 0;
    string op;
    int order(bakery_admin *product)
    {
    order:
        int opt;
        int item;
        cout << "\n\n\tWhat would you like to have: ";
        cin >> item;

        if (item == 1)
        {

            if (product->biscuits == 0)
            {
                cout << "\n\tWe are currently ran out of biscuits...sorry!!!";
                goto order;
            }

            cout << "\n\tHow many biscuits would you like to have: ";
            cin >> quant_1;

            if (quant_1 > product->biscuits)
            {
                cout << "\n\n\n\tWe are currently running short on biscuits, would you like to have the remaining pieces??";
                cout << "\n\tPress 1 to confirm:";
                cin >> opt;
                if (opt == 1)
                {
                    quant_1 = product->biscuits;
                    total_bis = total_bis + quant_1 * product->biscuits_pr;
                    product->biscuits = 0;
                }
            }
            else
            {
                total_bis = total_bis + quant_1 * product->biscuits_pr;
                product->biscuits = product->biscuits - quant_1;
            }
        }
        else if (item == 2)
        {
            if (product->buns == 0)
            {
                cout << "\n\tWe are currently ran out of buns...sorry!!!";
                goto order;
            }

            cout << "\n\tHow many buns would you like to have: ";
            cin >> quant_2;

            if (quant_2 > product->buns)
            {
                cout << "\n\n\n\tWe are currently running short on buns, would you like to have the remaining pieces??";
                cout << "\n\tPress 1 to confirm:";
                cin >> opt;
                if (opt == 1)
                {
                    quant_2 = product->buns;
                    total_bun = total_bun + quant_2 * product->buns_pr;
                    product->buns = 0;
                }
            }
            else
            {
                total_bun = total_bun + quant_2 * product->buns_pr;
                product->buns = product->buns - quant_2;
            }
        }
        else if (item == 3)
        {
            if (product->rolls == 0)
            {
                cout << "\n\tWe are currently ran out of rolls...sorry!!!";
                goto order;
            }

            cout << "\n\tHow many rolls would you like to have: ";
            cin >> quant_3;

            if (quant_3 > product->rolls)
            {
                cout << "\n\n\n\tWe are currently running short on rolls, would you like to have the remaining pieces??";
                cout << "\n\tPress 1 to confirm :";
                cin >> opt;
                if (opt == 1)
                {
                    quant_3 = product->rolls;
                    total_roll = total_roll + quant_3 * product->rolls_pr;
                    product->rolls = 0;
                }
            }
            else
            {
                total_roll = total_roll + quant_3 * product->rolls_pr;
                product->rolls = product->rolls - quant_3;
            }
        }
        else if (item == 4)
        {
            if (product->muffin == 0)
            {
                cout << "\nWe are currently ran out of muffins...sorry!!!";
                goto order;
            }

            cout << "\n\tHow many muffins would you like to have: ";
            cin >> quant_4;

            if (quant_4 > product->muffin)
            {
                cout << "\n\n\n\tWe are currently running short on muffins, would you like to have the remaining pieces??";
                cout << "\n\tPress 1 to confirm :";
                cin >> opt;
                if (opt == 1)
                {
                    quant_4 = product->waffles;
                    total_waffle = total_waffle + quant_4 * product->muffin_pr;
                    product->muffin = 0;
                }
            }
            else
            {
                total_waffle = total_waffle + quant_4 * product->muffin_pr;
                product->muffin = product->muffin - quant_4;
            }
        }
        else if (item == 5)
        {
            if (product->butter_cake == 0)
            {
                cout << "\n\tWe are currently ran out of butter cake...sorry!!!";
                goto order;
            }

            cout << "\n\tHow many cakes would you like to have: ";
            cin >> quant_5;

            if (quant_5 > product->butter_cake)
            {
                cout << "\n\n\n\tWe are currently running short on cake, would you like to have the remaining pieces??";
                cout << "\n\tPress 1 to confirm: ";
                cin >> opt;
                if (opt == 1)
                {
                    quant_5 = product->butter_cake;
                    total_cake = total_cake + quant_5 * product->butter_cake_pr;
                    product->butter_cake = 0;
                }
            }
            else
            {
                total_cake = total_cake + quant_5 * product->butter_cake_pr;
                product->butter_cake = product->butter_cake - quant_5;
            }
        }
        else if (item == 6)
        {
            if (product->pie == 0)
            {
                cout << "\n\tWe are currently ran out of pies...sorry!!!";
                goto order;
            }

            cout << "\n\tHow many pies would you like to have: ";
            cin >> quant_6;

            if (quant_6 > product->pie)
            {
                cout << "\n\n\n\tWe are currently running short on pie, would you like to have the remaining pieces??";
                cout << "\n\tPress 1 to confirm: ";
                cin >> opt;
                if (opt == 1)
                {
                    quant_6 = product->pie;
                    total_pie = total_pie + quant_6 * product->pie_pr;
                    product->pie = 0;
                }
            }
            else
            {
                total_pie = total_pie + quant_6 * product->pie_pr;
                product->pie = product->pie - quant_6;
            }
        }
        else if (item == 7)
        {
            if (product->ice_creams == 0)
            {
                cout << "\n\tWe are currently ran out of ice cream...sorry!!!";
                goto order;
            }

            cout << "\n\tHow many scopes of ice cream would you like to have: ";
            cin >> quant_7;

            if (quant_7 > product->ice_creams)
            {
                cout << "\n\n\n\tWe are currently running short on ice cream, would you like to have the remaining pieces??";
                cout << "\n\tPress 1 to confirm:";
                cin >> opt;
                if (opt == 1)
                {
                    quant_7 = product->ice_creams;
                    total_ice = total_ice + quant_7 * product->ice_creams_pr;
                    product->ice_creams = 0;
                }
            }
            else
            {
                total_ice = total_ice + quant_7 * product->ice_creams_pr;
                product->ice_creams = product->ice_creams - quant_7;
            }
        }
        else if (item == 8)
        {
            if (product->waffles == 0)
            {
                cout << "\n\tWe are currently ran out of waffles...sorry!!!";
                goto order;
            }

            cout << "\n\tHow many waffles would you like to have: ";
            cin >> quant_8;

            if (quant_8 > product->waffles)
            {
                cout << "\n\n\n\tWe are currently running short on waffles, would you like to have the remaining pieces??";
                cout << "\n\tPress 1 to confirm:";
                cin >> opt;
                if (opt == 1)
                {
                    quant_8 = product->waffles;
                    total_waffle = total_waffle + quant_8 * product->waffles_pr;
                    product->waffles = 0;
                }
            }
            else
            {
                total_waffle = total_waffle + quant_8 * product->waffles_pr;
                product->waffles = product->waffles - quant_8;
            }
        }
        else if (item == 9)
        {
            if (product->bread == 0)
            {
                cout << "\n\tWe are currently ran out of bread...sorry!!!";
                goto order;
            }

            cout << "\n\tHow many loafs of bread would you like to have: ";
            cin >> quant_9;

            if (quant_9 > product->bread)
            {
                cout << "\n\n\n\tWe are currently running short on bread, would you like to have the remaining pieces??";
                cout << "\n\tPress 1 to confirm:";
                cin >> opt;
                if (opt == 1)
                {
                    quant_9 = product->bread;
                    total_bread = total_bread + quant_9 * product->bread_pr;
                    product->bread = 0;
                }
            }
            else
            {
                total_bread = total_bread + quant_9 * product->bread_pr;
                product->bread = product->bread - quant_9;
            }
        }
        cout << "\n\n\tPress 1 to confirm to check out and 2 to add another item to the order: ";
        cin >> opt;
        if (opt == 2)
        {
            goto order;
        }
    }

    void bill(bakery_admin *x)
    {
        cout << "\n\n\n\t\t";
        cout << "==========================================================================";
        cout << "\n\t\t|                             RECEIPT BILL                               |";
        cout << "\n\t\t";
        cout << "|------------------------------------------------------------------------|";
        cout << "\n\t\t";
        cout << "|      Item Name    |  \t    Quantity      |     Rate      |    Amount    |";
        cout << "\n\t\t";
        cout << "|------------------------------------------------------------------------|";
        cout << "\n";
        if (quant_1 != 0)
        {
            cout << "\t\t|       Biscuits "
                 << "   |   \t" << quant_1 << "        |       " << x->biscuits_pr << "       |      " << quant_1 * x->biscuits_pr << "      |" << endl;
        }
        if (quant_2 != 0)
        {
            cout << "\t\t|         Buns "
                 << "     |   \t" << quant_2 << "        |       " << x->buns_pr << "       |      " << quant_2 * x->buns_pr << "      |" << endl;
        }
        if (quant_3 != 0)
        {
            cout << "\t\t|        Rolls  "
                 << "    |   \t" << quant_3 << "         |       " << x->rolls_pr << "      |      " << quant_3 * x->rolls_pr << "     |" << endl;
        }
        if (quant_4 != 0)
        {
            cout << "\t\t|       Muffins "
                 << "    |      \t" << quant_4 << "         |       " << x->muffin_pr << "      |      " << quant_4 * x->muffin_pr << "     |" << endl;
        }
        if (quant_5 != 0)
        {
            cout << "\t\t|     Butter Cake "
                 << "  |     \t" << quant_5 << "         |       " << x->butter_cake_pr << "      |      " << quant_5 * x->butter_cake_pr << "     |" << endl;
        }
        if (quant_6 != 0)
        {
            cout << "\t\t|         Pie "
                 << "      |   \t" << quant_6 << "         |       " << x->pie_pr << "      |     " << quant_6 * x->pie_pr << "      |" << endl;
        }
        if (quant_7 != 0)
        {
            cout << "\t\t|      Ice Cream "
                 << "   |   \t" << quant_7 << "         |       " << x->ice_creams_pr << "      |       " << quant_7 * x->ice_creams_pr << "    |" << endl;
        }
        if (quant_8 != 0)
        {
            cout << "\t\t|       Waffles "
                 << "    |   \t" << quant_8 << "         |       " << x->waffles_pr << "      |      " << quant_8 * x->waffles_pr << "     |" << endl;
        }
        if (quant_9 != 0)
        {
            cout << "\t\t|        Bread"
                 << "      |   \t" << quant_9 << "         |       " << x->bread_pr << "      |      " << quant_9 * x->bread_pr << "     |" << endl;
        }
        cout << "\t\t|\t\t\t\t\t\t                         |";
        cout << "\n\t\t|\t\t\t\t\t\t                         |";
        cout << "\n\t\t|\t\t\t\t\t\t                         |";
        cout << "\n\t\t|\t\t\t\t\t\t                         |";
        cout << "\n\t\t|\t\t\t\t\t\t--------------------     |";
        cout << "\n\t\t|\t\t\t\t\t\tGrand Total  Rs. " << total_bis + total_bun + total_roll + total_muf + total_cake + total_pie + total_waffle + total_ice + total_bread << "     |";
        cout << "\n\t\t|\t\t\t\t\t\t--------------------     |";
        cout << "\n\t\t";
        cout << "==========================================================================";
        cout << "\n\n\n";
    }

    void payment()
    {
        bakery_custm obj;
        cout << "\n\n\t\t>>> PAYMENT <<<" << endl;
        cout << "\n\n\t 1.Cash ";
        cout << "\t\t 2.Credit\n";
        printf("\n\n\tSelect Method Of payment 1-2: ");
        int payment;
        cin >> payment;

        if (payment == 1)
        {
            cout << "\n\t\t=====>THANK YOU<=====";
            cout << "\n\n\t\tItem Ordered Successfully !!!" << endl;
            getch();
        }

        if (payment == 2)
        {
            string card_number;
            string pin;

            cout << "\n\n\tEnter Your Card No : ";
            cin >> card_number;
            cout << "\n\n\tEnter Your Card Pin [we never save your pin]  : ";
            cin >> pin;
            cout << "\n\t\t\t=====>THANK YOU<=====";
            cout << "\n\tPayment is successful !!";
            getch();
        }
    }
};

void pwellcome()
{

    char welcome[50] = "WELCOME";
    char welcome2[50] = "TO THE BRAND";
    char welcome3[50] = " NEW HAPPY BAKERY HOUSE";
    char welcome4[50] = " MANAGEMENT SYSTEM";
    cout << "\n\n\n\n\n\n\n\t\t\t\t\t       ";
    for (int wlc = 0; wlc < strlen(welcome); wlc++)
    {

        cout << welcome[wlc];
        Sleep(100);
    }

    cout << " ";
    for (int wlc2 = 0; wlc2 < strlen(welcome2); wlc2++)
    {

        cout << welcome2[wlc2];
        Sleep(100);
    }

    cout << "\n\n\n\t\t\t\t             ";
    for (int wlc3 = 0; wlc3 < strlen(welcome3); wlc3++)
    {
        if (welcome3[wlc3] != 'D')
        {

            cout << welcome3[wlc3];
        }
        else
        {

            cout << welcome3[wlc3];
        }

        Sleep(100);
    }
    cout << "\n\n\n\t\t\t\t\t       ";
    for (int wlc3 = 0; wlc3 < strlen(welcome4); wlc3++)
    {
        if (welcome4[wlc3] != 'A' && welcome4[wlc3] != 'E')
        {

            cout << welcome4[wlc3];
        }
        else
        {

            cout << welcome4[wlc3];
        }
        Sleep(100);
    }

    char a = 177, b = 219;

    printf("\n\n\n\n\t\t\t\t\t    Loading...\n\n");
    printf("\t\t\t\t\t   ");

    for (int i = 0; i < 26; i++)
        printf("%c", a);

    printf("\r");
    printf("\t\t\t\t\t   ");

    for (int i = 0; i < 26; i++)
    {
        printf("%c", b);
        Sleep(100);
    }
    cout << "\n\n\n\n\tLoading Complete!!!";
    cout << "\n\tPress Any key to Continue: ";
    getch();
}

int main()
{
    cout << "Enter a key to proceed : ";
    getch();
    cls();
    system("title Bakery House Management System");
    pwellcome();
    bakery_admin admin_log;
    bakery_custm custm_log;
    cls();
    int user;
mainmenu:
    cout << "\n\n\t>>> Main Menu <<<" << endl;
    cout << "\n\t1. Admin Login" << endl;
    cout << "\t2. Customer Order" << endl;
    cout << "\t3. Exit" << endl;
    cout << "\n\tEnter your choice : ";
    cin >> user;
    if (user == 1)
    {
        if (!admin_log.auth_user())
        {
            cout << "Incorrect Password !" << endl;
            goto mainmenu;
        }
        cout << "\n\n\tWelcome Admin !! (#Please note: Do update the menu before being received by the customer!!)" << endl;
        int choice;
        cout << "\n\t1. Display Stocks" << endl;
        cout << "\t2. Update Stocks" << endl;
        cout << "\t3. Go Back" << endl;
        while (true)
        {
            cout << "\n\tEnter your choice : ";
            cin >> choice;
            if (choice == 1)
            {
                cout << "\n\n\tCustomers can view menu as of the following: " << endl;
                display(admin_log);
            }
            else if (choice == 2)
            {
                admin_log.set_Stock();
            }
            else
            {
                goto mainmenu;
            }
        }
        admin_log.set_Stock();
    }
    else if (user == 2)
    {
        cout << "\n\t\t";
        cout << "---------------------------------------------------------";
        cout << "\n\t\t|                        BAKERY MENU                    |";
        display(admin_log);
        custm_log.order(&admin_log);
        custm_log.bill(&admin_log);
        custm_log.payment();
        cls();
        Sleep(50);
        goto mainmenu;
    }
    else if (user == 3)
    {
        exit(1);
    }
    else
    {
        cout << "Input only between 1 - 3 !" << endl;
    }
    return 0;
}