/*Study in C / C ++
        and algorithms*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct card
{
    char* face;
    char* suit;
};

typedef struct card Card;

void FillDeck(Card*, char* [], char* []);
void Shuffle(Card*);
void Deck(Card*);

int main()
{
    Card deck[52];

    char* suit[] = { "Hearts","Diamonds","Clubs","Spades" };
    char* face[] = { "Ace","Deuce","Three","Four","Five",
                      "Six","Seven","Eight","Nine","Ten",
                      "Jack","Queen","King" };

    srand(time(NULL));

    FillDeck(deck, suit, face);
    Shuffle(deck);
    Deck(deck);

    return 0;
}

void FillDeck(Card* wDeck, char* wSuit[], char* wFace[])
{
    int i;

    for (i = 0; i < 52; i++)
    {
        wDeck[i].face = wFace[i % 13];
        wDeck[i].suit = wSuit[i / 13];
    }
}

void Shuffle(Card* wDeck)
{
    int i, j;
    Card temp;

    for (i = 0; i < 52; i++)
    {
        j = 0 + rand() % 52;
        temp = wDeck[i];
        wDeck[i] = wDeck[j];
        wDeck[j] = temp;
    }
}

void Deck(Card* wDeck)
{
    int i;
    for (i = 0; i < 52; i++)
        printf("%5s of %-8s%c", wDeck[i].face, wDeck[i].suit,
            (i + 1) % 2 ? '\t' : '\n');
}