// Hotel manganment.cpp : This file contains the 'main' function. Program execution begins and ends there.

/*
    **Made by NamelessBrown
    Updated on January 22, 2020
    -Added a money system for the player. (Work on upgrade later on)
    -Made it more readable to the user playing the game
    -Fixed the first person leaving on. They will know leave when they don't have the money for the room Price.
    -Impented the hotel size.
    -Users can now upgrade their hotel size!
    -More to come with this project!!!! Stay tune!!!!!!

    Updated on January 26, 2020
    -Fixed the wrong people leaving. This fix makes it so that EVERYONE in your hotel has different amount of money and will leave when they don't
    have enough to pay for the room!
    -When people leave your hotel size will now adjust accordingly.
    -If someone is below the roomPrice, they will leave.
    -Added more in depth comments to the source code for later updates.

    Updated on January 27, 2020
    -You can now upgrade your hotel size!!
    -Added more people into the people vector. Meaning MORE NAMES and less repeats!!!!
    -Better formatting output
    -Re-changed it so that people will enter randomly. I had this in before, but removed it for debugging purposes
    -Game is done.

    Updated on January 31
    -Fixed the amount of money you should get from people.
    -You can now change your room Price anytime
    -You can now change your hotel name anytime
    -Genral bug fixes
    -I'm done with this project really. Next month new project I guess.
*/ 

#include "Game.h"

/* This is the core of the game! That srand gets the game a random number. */
int main()
{
    srand((unsigned)time(nullptr));

    Game game;

    /* This is the heart of the game. */
    while (game.isRunning())
    {
        game.update();
    }
}