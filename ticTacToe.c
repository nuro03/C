#include <stdio.h>
#include <stdlib.h>
#include <time.h>


char field[9] = "         "; // Variablen initialisieren
char board[3][3];
int playerChoice = 0;
int computerChoice = 0;
int count = 0;

void printField(void)   // Funktion zum anzeigen des Spielplans.
{
    printf("1 2 3\n");
    printf("4 5 6\n");
    printf("7 8 9\n");
    printf("\n");
    printf("\n");
    printf(" %c | %c | %c \n", field[0], field[1], field[2]);
    printf("---|---|---\n");
    printf(" %c | %c | %c \n", field[3], field[4], field[5]);
    printf("---|---|---\n");
    printf(" %c | %c | %c \n", field[6], field[7], field[8]);
}

void userInput()
{
    printf("Please enter your field  ");
    scanf("%i", &playerChoice);   // Die eingegebene Zahl wird in choice gespeichert
    playerChoice--;
    if(field[playerChoice] == ' ') // Wenn das Feld leer ist wird dort X eingetragen und der counter um 1 erhoeht
    {
        field[playerChoice] = 'X';
        count++;
    }
    else                     // Wenn nicht wird der Spieler aufgefordert ein leeres Feld einzugeben...
    {
        printf("Please choose empty field");
        userInput();        // ...und die Funktion erneut aufgerufen.
    }
}

void computerInput() // Spielzug des Computers
{
    srand(time(NULL)); // Zufallsgenerator mit dem Zeitstempel als Startwert

    while (field[computerChoice] != ' ') // Solange das Feld nicht leer ist
    {
        computerChoice = rand()%10; // Benutzt wird der Rest des Teilens durch 10 um eine Ziffer von 0 bis 9 zu erhalten
    }
    field[computerChoice] = 'O';
    count++;
}

int checkWinner(char *player) // Funktion zum pruefen des Gewinners
{
    int a;
    int b;
    int c;
    int i;

    a = 0; // a, b und c werden so gesetzt, dass sie die erste Reihe belegen.
    b = 1;
    c = 2;
    i = 0; // i als Zaehler

    while(i <= 3)
    {
       if (field[a] == 'X' && field[b] == 'X' && field [c] == 'X' || field[a] == 'O' && field[b] == 'O' && field [c] == 'O') // if Funtion um zu pruefen, ob alle drei Felder X oder alle O sind
       {
            printf("### %s wins ###\n", player); // Wenn ja, wird der Gewinner ausgegeben und 1 returnt
            return 1;
       }
       a += 3; // a, b und c werden um 3 erhoeht um die naechste Reihe zu belegen
       b += 3;
       c += 3;
       i++;
    }

    a = 0; // a, b und c werden so gesetzt, dass sid die erste Spalte belegen
    b = 3;
    c = 6;
    i = 0;

    while(i <= 3)
    {
        if (field[a] == 'X' && field[b] == 'X' && field [c] == 'X' || field[a] == 'O' && field[b] == 'O' && field [c] == 'O')
        {
            printf("### %s wins ###\n", player);
            return 1;
        }
        a++; // a, b und c werden um 1 erhoeht um die naechste Spalte zu belegen
        b++;
        c++;
        i++;
    }

    a = 0;
    b = 4;
    c = 8;
    i = 0;
/*
Hier werden die Diagonalen geprueft. a, b und c werden zuerst so gesetzt, dass sie Diagonale von links oben nach rechts unten bilden.
Dann wird a um 2 erhoeht und b um 2 erniedrigt um die Diagonale von links unten nach rechts oben zu bilden.
*/
    while (i < 2)
    {
        if (field[a] == 'X' && field[b] == 'X' && field [c] == 'X' || field[a] == 'O' && field[b] == 'O' && field [c] == 'O')
        {
            printf("### %s wins ###\n", player);
            return 1;
        }
        a += 2;
        c -= 2;
        i++;
    }
}

int main(void)
{
    int n;

    printField();
    while (count < 9) // Schleife solange der counter kleiner 9 ist
    {
        userInput();
        n = checkWinner("Player");   // Pruefen, ob der Spieler gewonnen hat | n = returnwert der Prueffunktion
        if (n == 1)             // Wenn der Rueckgabewert 1 ist 0 returnen / Programm beenden
        {
            printField();
            return 0;
        }

        if (count < 9) // Schleife solange der counter kleiner 9 ist
        {
            computerInput();
            n = checkWinner("Computer");   // Pruefen, ob der Spieler gewonnen hat | n = returnwert der Prueffunktion
            if (n == 1)             // Wenn der Rueckgabewert 1 ist 0 returnen / Programm beenden
            {
                printField();
                return 0;
            }
        }
        printField();
    }
}