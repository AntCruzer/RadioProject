/*
    FILE            : AmFmRadio.h
    PROJECT         : RadioProject
    PROGRAMMER      : Anton dela Cruz
    FIRST VERSION   : 2024-03-19

    DESCRIPTION
    ----------- 
    This file defines the AmFmRadio class, which encapsulates the 
    functionality of an AM/FM radio, including managing power status, 
    volume, frequency bands, and station presets. It includes constants 
    for operation, a Freqs struct for storing frequency information, 
    and methods for controlling the radio's behavior. The class provides 
    constructors and destructors, along with accessors and mutators to get 
    and set the radio's properties.
*/



// INCLUDE FILES
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>



// NAMESPACE
using namespace std;



// CONSTANTS
const int       FREQ_TEXT_SIZE           = 3; 
const int       PRESET_BUTTONS           = 5;
const int       AM_MIN                   = 530;
const int       AM_MAX                   = 1700;
const double    FM_MIN                   = 87.9;
const double    FM_MAX                   = 107.9;
const int       VOL_MIN                  = 0;
const int       VOL_MAX                  = 100;
const bool      SUCCESS                  = true;
const bool      FAILURE                  = false;
const bool      POWER_ON                 = true;
const bool      POWER_OFF                = false;
const int       AM_INC                   = 10;
const double    FM_INC                   = .2;
const int       PRESET_BTN_1             = 0;
const int       PRESET_BTN_2             = 1;
const int       PRESET_BTN_3             = 2;
const int       PRESET_BTN_4             = 3;
const int       PRESET_BTN_5             = 4;

//////////////////////////////////////////////////////
const char      AM_BAND[FREQ_TEXT_SIZE]  = "AM";
const char      FM_BAND[FREQ_TEXT_SIZE]  = "FM";

const char      AM_BAND2[] = "AM";
const char      FM_BAND2[] = "FM";
//////////////////////////////////////////////////////



/**/
struct Freqs
{
    double      AMFreq;             // current AM station
    double      FMFreq;             // current FM station
    char        prevBand;           // band recovery
    double      AMPrevFreq;         // station recovery (AM)
    double      FMPrevFreq;         // station recovery (FM)
};



class AmFmRadio
{
    private:

        bool    powerStatus;
        int     volume = 0;
        char    band[FREQ_TEXT_SIZE];
        double  station;

        Freqs   presets[PRESET_BUTTONS];    // preset buttons
        int     presetButton;               // preset button num
        int     prevVolume;                 // volume recovery
        bool    displayOutput;              // display status

    public:

        // CONSTRUCTORS (OK)
        AmFmRadio(bool status = false);
        AmFmRadio(bool status, struct Freqs arrayOfFreq[PRESET_BUTTONS]);//////////////

        // DESTRUCTORS (OK)
        ~AmFmRadio(void);

        // ACCESSORS (GETTERS) (OK)
        bool    GetPowerStatus(void);
        int     GetVolume(void);
        char*   GetBand(void);
        double  GetStation(void);
        bool    GetDisplayOutput(void);
        int     GetPresetButton(void);
        struct Freqs* GetRadioPreset(int presetButton);

        // MUTATORS (SETTERS)
        bool    SetVolume(int newVolume);
        bool    SetStation(double newStation);
        bool    SetPresetButton(int buttonNum);
        bool    SetDisplayOutput(bool newDisplayStatus);
        
        // OTHER METHODS
        void    TogglePower(void);
        void    ToggleBand(void);
        void    ScanUp(void);
        void    ScanDown(void);
        void    ShowCurrentSettings(void); 

        // bool    SetBand(const char* newBand); 
        //bool    SetPowerStatus(bool newPowerStatus);           
};


