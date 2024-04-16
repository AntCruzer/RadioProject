/*
    FILE            : test.cpp
    PROJECT         : RadioProject
    PROGRAMMER      : Anton dela Cruz
    FIRST VERSION   : 2024-03-19

    DESCRIPTION
    -----------
    This file contains the main function testing out the AmFmRadio class
    and its methods.
*/



// INCLUDE FILES
#include <stdio.h>
#include "AmFmRadio.h"



int main(void)
{
    printf("\nPERFORM TESTING...");
    printf("\n");


    AmFmRadio* radio1 = new AmFmRadio();    // instantiate object (default constructor)
    radio1->ShowCurrentSettings();          // show radio1's current settings
    // modify radio1's properties
    radio1->SetVolume(50);                  
    radio1->ToggleBand();
    radio1->SetStation(100.0);

    printf("\n");

    radio1->ShowCurrentSettings();          // show radio1's current settings

    // clean up
    delete radio1;

    printf("\n");
    return 0;
}


