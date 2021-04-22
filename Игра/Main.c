/*Game*/

#define _WIN32_WINNT 0x0500
#include <windows.h>

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <locale.h>

#define EXIT_NUM 42
#define ACCEPT 41
#define LOSE_GAME_NUM 18
#define FIGHT_NUM 19

struct Hero_Inventory
{
    int t; // Температура
    int g; // Золото
    int up; // Улучшения
    int heroday;
} Hero;

struct Enemy_Inventory
{
    int heal; // Здоровье
    int attack; // Атака
    int goldBag; // Золото
} Enemy;

void TravelDisplay(void);
void Menu(void);
void MarketMenu(void);

void Menu1(void);
void Menu2(void);
void Menu3(void);

void Work(void);
void Relax(void);
void MarketWorld(void);

void BitCoin(void);
void EndClose(void);

void BitCoinMenu(void);
void EndCloseMenu(void);
void EndCloseEnter(void);

void Battle(int);
void BattleWin(void);
void BattleMenuGoblin(void);
void BattleMenuOrc(void);
void BattleMenuHuman(void);

void EndGAME(void);
void LoseGame(void);

int sup = 1;
int fTravel = 0;

int main() {

    system("mode con cols=120 lines=25");
    HWND consoleWindow = GetConsoleWindow(); SetWindowLong(consoleWindow, GWL_STYLE, GetWindowLong(consoleWindow, GWL_STYLE) & ~WS_MAXIMIZEBOX & ~WS_SIZEBOX);
    setlocale(LC_ALL, "Rus");


    Hero.g = 0;
    Hero.t = 0;
    Hero.up = 2;
    Hero.heroday = 0;
    int answer = 0;

    while (sup != EXIT_NUM)
    {
        srand(time(NULL));
        int x = 0 + rand() % 1000;

        if (x <= 500)
        {
            Enemy.attack = 5;
            Enemy.heal = 20;
            Enemy.goldBag = 10;
        }
        if (x >= 501 && x <= 740)
        {
            Enemy.attack = 15;
            Enemy.heal = 35;
            Enemy.goldBag = 40;
        }
        if (x > 740)
        {
            Enemy.attack = 10;
            Enemy.heal = 50;
            Enemy.goldBag = 30;
        }

            while (sup == 1)
                Menu1();

            while (sup == 2)
                Menu2();

            while (sup == 3)
               Menu3();

            while (sup == 4)
                MarketWorld();

            while (sup == 10)
                BitCoin();

            while (sup == 11)
                EndCloseEnter();

            while (sup == 12)
                EndClose();

            while (sup == LOSE_GAME_NUM)
                LoseGame();

            while (sup == FIGHT_NUM)
                Battle(x);

            while (sup == 100)
                EndGAME();
    }

    return 0;
}

void Battle(int x)
{
    if (x <= 500)
    {
        BattleMenuGoblin();
    }
    if (x >= 501 && x <= 740)
    {
        BattleMenuOrc();
    }
    if (x > 740)
    {
        BattleMenuHuman();
    }
    printf("%s| %s %d | %s %d |\n%s %d\t|\t%s %d\n%s", "Введите 'F' : для атаки!", "Атака врага:", Enemy.attack, "Здоровье врага:", Enemy.heal,"Ваша температура:", Hero.t, "Награда за врага:", Enemy.goldBag, "> ");
    char menu;

    menu = getchar();

    switch (menu)
    {
    case 'F':
        Sleep(500);
            if (x <= 500)
                BattleMenuGoblin();
            if (x >= 501 && x <= 740)
                BattleMenuOrc();
            if (x > 740)
                BattleMenuHuman();
        printf("%s\n%s", "Атака...", "> ");
        Sleep(1000);
        Enemy.heal -= Hero.up;
        Sleep(500);
        if (x <= 500)
            BattleMenuGoblin();
        if (x >= 501 && x <= 740)
            BattleMenuOrc();
        if (x > 740)
            BattleMenuHuman();
        printf("%s\n%s", "Атака врага...", "> ");
        Sleep(1000);
        Hero.t += Enemy.attack;
        Sleep(500);
        break;
    default:
        break;
    }

    if (Hero.t >= 100)
    {
        sup = LOSE_GAME_NUM;
    }

    if (Enemy.heal <= 0)
    {
        Hero.g += Enemy.goldBag;
        BattleWin();
    }

}

void Work()
{
    srand(time(NULL));
    int y = 1 + rand() % 10;

    TravelDisplay();
    if (Hero.t < 100)
    {
        if (y >= 7 && Hero.heroday >= 1)
        {
            sup = FIGHT_NUM;
        }
        else
        {
            printf("%s\n%s", "Работа...", "> ");
            Sleep(5000);
            srand(time(NULL));
            Hero.g += 1 + rand() % Hero.up;
            Hero.t += 1 + rand() % 5;
        }
    }
    else
    {
        printf("%s\n%s", "У вас слишком высокая температура...", "> ");
        Sleep(2000);
    }

    if (Hero.t >= 100)
    {
        sup = LOSE_GAME_NUM;
    }

    if (fTravel == 0)
        fTravel = 1;
}

void Relax()
{
    TravelDisplay();
    if (Hero.t != 0)
    {
        printf("%s\n%s", "Отдых...", "> ");
        Sleep(5000);
        Hero.t = 0;
        TravelDisplay();
        printf("%s\n%s", "Вы отдохнули :3", "> ");
        Sleep(1500);
        Hero.heroday += 1;
    }
    else
    {
        printf("%s\n%s", "Вы уже отдохнули :3", "> ");
        Sleep(1500);
        Hero.t += 1;
    }
}

void BitCoin()
{
    Hero.t += 1;

    BitCoinMenu();
    printf("%s\n%s", "Введите 'E' : для возвращения!", "> ");
    char menu;

    menu = getchar();

    switch (menu)
    {
    case 'P':
        if (Hero.g >= 12)
        {
            Hero.g -= 12;
            Hero.up += 1;
        }
        else
        {
            BitCoinMenu();
            printf("%s %d %s\n%s", "Недостаточно", 12 - Hero.g, "средств :c", "> ");
            Sleep(1500);
        }
        break;
    case 'L':
        if (Hero.g >= 21)
        {
            Hero.g -= 21;
            Hero.up += 2;
        }
        else
        {
            BitCoinMenu();
            printf("%s %d %s\n%s", "Недостаточно", 21 - Hero.g, "средств :c", "> ");
            Sleep(1500);
        }
        break;
    case 'B':
        if (Hero.g >= 31)
        {
            Hero.g -= 31;
            Hero.up += 3;
        }
        else
        {
            BitCoinMenu();
            printf("%s %d %s\n%s", "Недостаточно", 31-Hero.g ,"средств :c", "> ");
            Sleep(1500);
        }
        break;
    case 'K':
        if (Hero.g >= 41)
        {
            Hero.g -= 41;
            Hero.up += 4;
        }
        else
        {
            BitCoinMenu();
            printf("%s %d %s\n%s", "Недостаточно", 41 - Hero.g, "средств :c", "> ");
            Sleep(1500);
        }
        break;
    case 'E':
        sup = 3;
        break;
    default:
        break;
    }

    if (Hero.t >= 100)
    {
        sup = LOSE_GAME_NUM;
    }
}

void EndClose()
{
    EndCloseMenu();
    printf("%s\n%s", "Введите 'E' : для возвращения!", "> ");
    char menu;

    menu = getchar();

    switch (menu)
    {
    case 'M':
        if (Hero.g >= 1000)
        {
            Hero.g -= 1000;
            Hero.up += 500;
            sup = 100;
        }
        else
        {
            EndCloseMenu();
            printf("%s %d %s\n%s", "Недостаточно", 1000 - Hero.g, "средств :c", "> ");
            Sleep(2000);
        }
        break;
    case 'E':
        sup = 3;
        break;
    default:
        break;
    }

    if (Hero.t >= 100)
    {
        sup = LOSE_GAME_NUM;
    }
}

void MarketWorld()
{
    Hero.t += 1;

    MarketMenu();
    printf("%s\n%s", "Введите 'E' : для возвращения!", "> ");

    char menu;

    menu = getchar();

    switch (menu)
    {
    case 'B':
        sup = 10;
        break;
    case 'C':
        sup = 11;
        break;
    case 'E':
        sup = 3;
        break;
    default:
        break;
    }

    if (Hero.t >= 100)
    {
        sup = LOSE_GAME_NUM;
    }
}

void Menu1()
{
    Menu();
    printf("%s\n%s\n%s\n%s", "Введите G : для входа!", "Введите S : для чтения сюжета", "Введите E : для выхода!", "> ");
    char menu;
    menu = getchar();

    switch (menu)
    {
    case 'E':
        sup = EXIT_NUM;
        break;
    case 'G':
        sup = 3;
        break;
    case 'S':
        sup = 2;
        break;
    default:
        break;
    }

}

void Menu2()
{
    system("cls");
    for (int i = 0; i <= 10; i++)
    {
        for (int j = 0; j <= 116; j++)
        {
            if (i == 0 || i == 10)
                printf("*");

            if (i == 3 && j == 0)
            {
                printf("Вы очень плохой человек!\n\n");
                printf("За ваши поступки, вас сослали в шахту по добыче золота.\n");
                printf("В этой шахте, с названием  “МегаШахта”, живут монстры и правит высокая температура.\n");
                printf("Вас поселяют жить в таверне  “ Огнегривый Лев”. Теперь ваша судьба оказывается в ваших руках. Желаем смерти!");
            }

        }
        printf("\n");
    }

    char num;
    printf("%s\n%s", "Введите 'B' : для возвращения!", "> ");
    num = getchar();

    switch (num)
    {
    case 'B':
        sup = 1;
        break;
    default:
        break;
    }

}

void Menu3()
{

    printf("%s\n%s", "Введите E : для выхода!", "> ");
    char timeToFarm;

    timeToFarm = getchar();

    TravelDisplay();

    switch (timeToFarm)
    {
    case 'W':
        Work();
        break;
    case 'S':
        Relax();
        break;
    case 'M':
        sup = 4;
        break;
    case 'E':
        sup = EXIT_NUM;
        break;
    default:
        break;
    }

    if (Hero.t >= 100)
    {
        sup = LOSE_GAME_NUM;
    }

}

void Menu()
{
    system("cls");
    for (int i = 0; i <= 20; i++)
    {
        for (int j = 0; j <= 116; j++)
        {
            if (i == 0 || i == 20)
                printf("*");

            if (i == 9 && j < 57)
                printf(" ");
            if (i == 9 && j == 57)
                printf("%s", "Добро пожаловать!");

            if (i == 10 && j < 57)
                printf(" ");
            if (i == 10 &&  j == 57)
                printf("%s", "в Temp & Work!");
        }
        printf("\n");
    }

}

void TravelDisplay()
{
    system("cls");
    for (int i = 0; i <= 13; i++)
    {
        for (int j = 0; j <= 116; j++)
        {
            if (i == 0 || i == 13)
                printf("*");

            if (i == 5 && j == 0)
            {
                printf("%s\n", "Список команд: ");
                printf("%s\n", "W - Работать в шахте.");
                printf("%s\n", "S - Сон.");
                printf("%s\n", "M - Магазины.");
            }

            if (i == 8 && j == 0)
            {
                printf("%s\n", "Состояние: ");
                printf("%s = %d\n", "Температура", Hero.t);
                printf("%s = %d\n", "Количество золота", Hero.g);
            }
            if (i == 2 && j == 57)
                printf("%s", "Ваша каторга!");
            if (fTravel == 0)
            {
                if (i == 3 && j == 57)
                    printf("%s", "Начинается!");
            }
            else
                if (i == 3 && j == 57)
                    printf("%s  %s %d", "Идёт!", "Количество дней", Hero.heroday);
        }
        printf("\n");
    }
}

void MarketMenu()
{
    system("cls");

    for (int i = 0; i <= 15; i++)
    {
        for (int j = 0; j <= 116; j++)
        {
            if (i == 0 || i == 15)
                printf("*");

            if (i == 5 && j == 0)
            {
                printf("%s\n", "Выберете магазин:");
                printf("%s\n", "Магазин Bit & Coin. - B");
                printf("%s\n", "Магазин End & Close. - C");
            }
        }
        printf("\n");
    }
}

void BitCoinMenu()
{
    system("cls");
    for (int i = 0; i <= 10; i++)
    {
        for (int j = 0; j <= 116; j++)
        {
            if (i == 0 || i == 10)
                printf("*");

            if (i == 2 && j == 0)
            {
                printf("%s\n", "Добро пожаловать!");
                printf("%s", "В Магазин Bit & Coin!");
            }

            if (i == 5 && j == 0)
            {
                printf("%s\n", "Меню улучшений: ");
                printf("%s\n", "Перчатки дают +1 G, к получаемому золоту : Стоимость - 12 G");
                printf("%s\n", "Для покупки введите 'P'");
                printf("%s\n", "Лопата даёт +2 G, к получаемому золоту : Стоимость - 21 G");
                printf("%s\n", "Для покупки введите 'L'");
                printf("%s\n", "Бур даёт +3 G, к получаемому золоту : Стоимость - 31 G");
                printf("%s\n", "Для покупки введите 'B'");
                printf("%s\n", "Коллекция горных инструментов даёт +4 G, к получаемому золоту : Стоимость - 41 G");
                printf("%s\n", "Для покупки введите 'K'");
            }

            if (i == 9 && j == 0)
                printf("%s%d", "Ваше золото: ", Hero.g);
        }
        printf("\n");
    }
}

void EndCloseEnter()
{
    system("cls");
    for (int i = 0; i <= 20; i++)
    {
        for (int j = 0; j <= 116; j++)
        {
            if (i == 0 || i == 20)
                printf("*");

            if (i == 5 && j == 0)
            {
                printf("%s\n", "Добро пожаловать!");
                printf("%s", "В Магазин End & Close!");
            }

            if (i == 10 && j == 0)
            {
                printf("%s\n", "В магазине сейчас только один товар:");
                Sleep(1500);
                printf("%s\a\n", "ЛЕГЕНДАРНЫЙ");
                Sleep(1500);
                printf("%s\a\n", "УЛЬТРА");
                Sleep(1500);
                printf("%s\a\n", "МЕГА");
                Sleep(1500);
                printf("%s\a\n", "УБЕР");
                Sleep(1500);
                printf("%s\a\n", "МЕЧ");
                Sleep(1500);
                printf("%s\n", "...");
                Sleep(1500);
            }
        }
        printf("\n");
    }
    sup = 12;
}

void EndCloseMenu()
{
    system("cls");
    for (int i = 0; i <= 15; i++)
    {
        for (int j = 0; j <= 116; j++)
        {
            if (i == 0 || i == 15)
                printf("*");

            if (i == 10 && j == 0)
            {
                printf("%s\n","Хотите купить?");
                printf("%s\n", "Для покупки введите 'M'");
            }

        }
        printf("\n");
    }
}

void BattleMenuGoblin()
{
    system("cls");
    for (int i = 0; i <= 5; i++)
    {
        for (int j = 0; j <= 116; j++)
        {
            if (i == 0 || i == 5)
                printf("*");

            if (i == 2 && j == 0)
            {
                printf("         *\n");
                printf("         /\\\n");
                printf(" /\\     /o \\   /\\ \n");
                printf("/ /    /_ _o\\  \\ \\\n");
                printf("\\ \\__.'  '   './ /\n");
                printf(" \\___.---'---___/ \n");
                printf("    /    @    @_     __\n");
                printf("   /  )     _   '   /_/\n");
                printf("  ;_-'    _(,\\__,) / /\n");
                printf("    / \\   \\'uuuu' / /\n");
                printf("  ,'   \"\", '---' ' /\n");
                printf(" /       \"\"\", --, , / \n");
                printf("/  /       '\"\\\\\\ '\n");
            }

        }
        printf("\n");
    }
}

void BattleMenuOrc()
{
    system("cls");
    for (int i = 0; i <= 2; i++)
    {
        for (int j = 0; j <= 116; j++)
        {
            if (i == 0 || i == 2)
                printf("*");

            if (i == 1 && j == 0)
            {
                printf("     .'\"\"\"S, ._'--'_2.., _\n");
                printf("     |    ':::::=:::::  \\\n");
                printf("     .     f== ;-,---.' T\n");
                printf("      Y.   r,-,_/_      |\n");
                printf("      |:\\___.---' '---./\n");
                printf("      |'`             )\n");
                printf("       \\             ,\n");
                printf("       ':;,.________.;L\n");
                printf("       /  '---------' |\n");
                printf("       |              \\\n");
                printf("       L---'-,--.-'--,-'\n");
                printf("        T    /   \\   Y\n");
                printf("        |   Y    ,   |\n");
                printf("        |   \\    (   |\n");
                printf("        (   )     \\,_L\n");
                printf("        7-./      )  `,\n");
                printf("       /  _(      '._  \\\n");
                printf("     '---'           '--'\n");
            }

        }
        printf("\n");
    }
}

void BattleMenuHuman()
{
    system("cls");
    for (int i = 0; i <= 2; i++)
    {
        for (int j = 0; j <= 116; j++)
        {
            if (i == 0 || i == 2)
                printf("*");

            if (i == 1 && j == 0)
            {
                printf("                      ____... \n");
                printf("             .-\"--\"\"\"\".__    `\n");
                printf("            |            `    |\n");
                printf("  (         `._....------.._.:\n");
                printf("   )         .()''        ``().\n");
                printf("  '          () .=='  `===  `-.  \n");
                printf("   . )       (         g)        \n");
                printf("    )         )     /        J \n");
                printf("   (          |.   /      . (\n");
                printf("   $$         (.  (_'.   , )|`\n");
                printf("   ||         |\\`-....--'/  ' \\\n");
                printf("  /||.         \\ | | | /  /   \\.\n");
                printf(" //||(\\         \\`-===-'  '     \\o. \n");
                printf(".//7' |)         `. --   / (     OObaaaad888b.\n");
                printf("(<<. / |     .a888b`.__.'d\\     OO888888888888a.\n");
                printf(" \\  Y' |    .8888888aaaa88POOOOOO888888888888888.\n");
                printf("  \\  \\ |   .888888888888888888888888888888888888b \n");
                printf("  |   |  .d88888P88888888888888888888888b8888888.\n");
                printf("   b.--d .d88888P8888888888888888a:f888888|888888b \n");
                printf("   88888b 888888|8888888888888888888888888\\8888888\n");
            }

        }
        printf("\n");
    }
}

void EndGAME()
{
    system("cls");
    for (int i = 0; i <= 20; i++)
    {
        for (int j = 0; j <= 116; j++)
        {
            if (i == 0 || i == 20)
                printf("*");

            if (i == 10 && j == 0)
            {
                printf("%s\n", "Вы прошли игру!");
                Sleep(500);
                printf("%s\a\n", "УрААААААААААААААААААААААААААААААААААААААААААААААААААААААААААААААААААААААААААААААААААААААААААААААААААААААААААААААААААААААААААААААААААААААААААААААААААААААААААААААААААААААААААААААААААААААААААА");
                Sleep(1000);
                printf("%s\n", "Спасибо что играли =)");
                Sleep(2000);
                printf("%s\n", "На игрой работали:");
                Sleep(500);
                printf("%s\n", "Boris)");
                Sleep(2000);
                printf("%s\n", "Secret word: Vanillin)");
                Sleep(2000);

            }

        }
        printf("\n");
    }

    sup = EXIT_NUM;
}
void LoseGame(void)
{
    system("cls");
    for (int i = 0; i <= 20; i++)
    {
        for (int j = 0; j <= 116; j++)
        {
            if (i == 0 || i == 20)
                printf("*");

            if (i == 10 && j == 0)
            {
                printf("%s\n", "Вы погибли!");
                Sleep(2000);
            }
            if (i == 11 && j == 0)
            {
                printf("%s\n", ":c");
                Sleep(2000);
            }

        }
        printf("\n");
    }

    sup = EXIT_NUM;
}

void BattleWin()
{
    system("cls");
    for (int i = 0; i <= 20; i++)
    {
        for (int j = 0; j <= 116; j++)
        {
            if (i == 0 || i == 20)
                printf("*");

            if (i == 10 && j == 0)
            {
                printf("%s\n", "Вы выиграли битву!");
                Sleep(2000);
            }
            if (i == 11 && j == 0)
            {
                printf("%s\n", ":>");
                Sleep(2000);
            }

        }
        printf("\n");
    }

    sup = 3;
}