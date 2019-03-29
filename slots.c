#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

int currency;
char screen[3] = {'$', '$', '$'};

char symbols[15] = {'$', '*', '#', '@', '7', '?', '~', '=', '&', '#', '@', '!', '%', '~', '='};


void printUsage() {
    printf("                Welcome to slots!\n");
    printf("          The slot machine game you're \n");
    printf("       actually guarenteed to win (probabbly\n");
    printf("                                            \n");
    printf("                                  by Andrew Thorp\n");
    printf("---------------------------------------------------\n");
    printf("\n");
    printf("Usage:\n");
    printf("    <Enter> to pull the lever\n");
    printf("    press 'q' to quit\n");
    printf("    Try not to run out of coins!\n");
    printf("Press anything to continue..");
    getchar();
}

void printScreen() {
    printf("\n");
    printf("\n");
    printf("\n");
    printf("   / ,-.-.-.  | ( ) |\n");
    printf("  /  |%c|%c|%c|  |  |  |\n", screen[0], screen[1], screen[2]);
    printf(" /   `-'-'-'  |  |  |\n");
    printf("\n");
}

void printStart() {
    printf("Press enter to pull lever...\n");
}

void quit() {
    printf("Winnings: %d\n", currency);
    printf("Come back again!\n");
    sleep(1);
    printf("Goodbye\n");
    exit(0);
}

void broke() {

    unsigned int time = 200000;
    printf("Why \n");
    usleep(time);

    printf("do \n");
    usleep(time);

    printf("we \n");
    usleep(time);

    printf("even \n");
    usleep(time);

    printf("HAVE \n");
    usleep(time + 100000);

    printf("that \n");
    usleep(time);

    printf("lever?\n ");
    usleep(time);

    quit();
}

void pullTheLeverKronk() {
    printf("\n");
    printf("\n");
    printf("\n");
    printf("   / ,-.-.-.  ( )   |\n");
    printf("  /  |%c|%c|%c|  | \\   |\n", screen[0], screen[1], screen[2]);
    printf(" /   `-'-'-'  |  \\  |\n");
    printf("\n");

    sleep(1);

    if (currency < 2) {
        printf("You don't have enough money to play!\n");
        broke();
    }

    currency -= 2;
    printf("Payment recieved. Current winnings: %d\n", currency);

    screen[0] = ' ';
    screen[1] = ' ';
    screen[2] = ' ';

    int i;
    for (i = 0; i < 3; i++) {
        printScreen();
        int r = rand() % 15;
        screen[i] = symbols[r];
        sleep(1);
    }
    printScreen();
}

void jackpot() {
    if (screen[0] == '$') { // mega jackpot
        printf("!!!!!!!!!!!!!!\n");
        printf("!MEGA JACKPOT!\n");
        printf("!!!!!!!!!!!!!!\n");
        printf("You win 100!\n");
        currency += 100;
    } else {
        printf("**********\n");
        printf("*Jackpot!*\n");
        printf("**********\n");
        printf("You win 20!\n");
        currency += 20;
    }
}

void matchTwo(int first, int second) {
    if (screen[first] == '$') {
        printf("Winner!\n");
        printf("You win 10!\n");
        currency += 10;
    } else {
        printf("Nice!\n");
        printf("You win 5!\n");
        currency += 5;
    }
}

void printStandings()  {
    printf("-------------------------------------------------\n");
    printf("  Current winnings: %d\n", currency);
    printf("\n");
}

void printResults(){
    if (screen[0] == screen[1]) {
        if (screen[0] == screen[2]) jackpot();
        else matchTwo(0, 1);
    } else if (screen[0] == screen[2]) {
        matchTwo(0, 2);
    } else if (screen[1] == screen[2]) {
        matchTwo(1, 2);
    } else {
        printf("Better luck on your next pull\n");
    }

    printStandings();
}

void main() {
    // seed the random generator
    srand(time(0));

    currency = 20;
    printUsage();
    printScreen();

    while (1) {
        // print first stuff
        printStart();

        // wait for input
        int c = getchar();
        if (c == 'q' || c == 'Q') quit();

        pullTheLeverKronk();

        // print results
        printResults();
    }
}
