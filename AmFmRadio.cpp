/*
    FILE            : AmFmRadio.cpp
    PROJECT         : RadioProject
    PROGRAMMER      : Anton dela Cruz
    FIRST VERSION   : 2024-03-19

    DESCRIPTION
    -----------
    This file contains the methods of the AmFmRadio class.
   
*/



// INCLUDE FILES
#include "AmFmRadio.h"



/*
    Function        :   AmFmRadio()
    Parameters      :   bool status - power status (on/off)
    Return Value    :   NONE
    Description     :   This is the default constructor for the AmFmRadio object
                        that initializes its private data members.
*/
AmFmRadio::AmFmRadio(bool status)
{
    powerStatus = status;           // intialize power status
    volume = VOL_MIN;               // initialize volume level
    strcpy(band, AM_BAND2);         // initialize current band
    station = AM_MIN;               // initialize current station

    // initialize preset stations (AM and FM)
    for (int i = 0; i < PRESET_BUTTONS; ++i)
    {
        presets[i].AMFreq = AM_MIN;
        presets[i].FMFreq = FM_MIN;

        presets[i].AMPrevFreq = presets[i].AMFreq;
        presets[i].FMPrevFreq = presets[i].FMFreq;
    }

    presetButton = 0;

    prevVolume = VOL_MIN;           // initialize previous volume level
    displayOutput = true;           // intialize display status
}



/*
    Function        :   AmFmRadio()
    Parameters      :   bool status - power status (on/off)
                        struct Freqs arrayOfFreq[PRESET_BUTTONS] - array of presets
    Return Value    :   NONE
    Description     :   This is the parameterized constructor for the AmFmRadio object
                        that initializes its private data members.
*/
AmFmRadio::AmFmRadio(bool status, struct Freqs arrayOfFreq[PRESET_BUTTONS])
{
    powerStatus = status;           // intialize power status
    volume = VOL_MIN;               // initialize volume level
    strcpy(band, AM_BAND2);         // initialize current band
    station = AM_MIN;               // initialize current station

    // initialize eash Freqs' preset stations (AM and FM)
    int arrayLength = sizeof(Freqs) / sizeof(int);

    for (int i = 0; i < arrayLength; ++i)
    {
        for (int j = 0; j < PRESET_BUTTONS; ++j)
        {
            arrayOfFreq[i].AMFreq = AM_MIN;
            arrayOfFreq[i].FMFreq = FM_MIN;

            arrayOfFreq[i].AMPrevFreq = arrayOfFreq[i].AMFreq;
            arrayOfFreq[i].FMPrevFreq = arrayOfFreq[i].FMFreq;
        }
    }

    // for (int i = 0; i < PRESET_BUTTONS; ++i)
    // {
    //     presets[i].AMFreq = AM_MIN;
    //     presets[i].FMFreq = FM_MIN;

    //     presets[i].AMPrevFreq = presets[i].AMFreq;
    //     presets[i].FMPrevFreq = presets[i].FMFreq;
    // }
    
    presetButton = 0;

    prevVolume = VOL_MIN;           // initialize previous volume level
    displayOutput = true;           // intialize display status
    
}



/*
    Function        :   AmFmRadio()
    Parameters      :   NONE
    Return Value    :   NONE
    Description     :   This is the destructor for the AmFmRadio object
                        that displays a message doing so to the user.
*/
AmFmRadio::~AmFmRadio(void)
{
    cout << "Terminated AmFmRadio object..." << endl;
}



/*
    Function        :   ShowCurrentSettings()
    Parameters      :   NONE
    Return Value    :   NONE
    Description     :   This method displays the current setting and properties 
                        of the AmFmRadio object.
*/
void AmFmRadio::ShowCurrentSettings(void)
{
    // display power status
    if (GetPowerStatus())
    {
        printf("\n\nRadio is on. \n");
    }
    else
    {
        printf("\n\nRadio is off. \n");
    }

    printf("Volume level: %d.\n", GetVolume());                 // display volume level

    printf("Current band: %s.\n", GetBand());                   // display current band

    printf("Current frequency: %d\n", GetStation());            // display current station

    // display AM preset stations
    printf("AM presets: \n");
    for ( int i = 0; i < PRESET_BUTTONS; ++i )
    {
        printf("Preset button #%d: %.f\n", i, presets[i].AMFreq);
    }

    // display FM presets
    printf("FM presets: \n");
    for (int i = 0; i < PRESET_BUTTONS; ++i)
    {
        printf("Preset button #%d: %.f\n", i, presets[i].FMFreq);
    }
}



/*
    Function        :   GetStation()
    Parameters      :   NONE
    Return Value    :   double station - radio station frequency
    Description     :   This is accessor for the current radio station.
*/
double AmFmRadio::GetStation(void)
{
    return station;
}



/*
    Function        :   GetPresetButton()
    Parameters      :   NONE
    Return Value    :   int presetButton - preset button number
    Description     :   This is accessor for the preset button number.
*/
int AmFmRadio::GetPresetButton(void)
{
    return presetButton;
}



/*
    Function        :   GetBand()
    Parameters      :   NONE
    Return Value    :   char* band - "AM" or "BAND"
    Description     :   This is the accessor for the band property.
*/
char* AmFmRadio::GetBand(void)
{
    return band;
}



/*
    Function        :   GetVolume()
    Parameters      :   NONE
    Return Value    :   int volume - numeric volume level
    Description     :   This is the accessor for the radio's current volume level.
*/
int AmFmRadio::GetVolume(void)
{
    return volume;
}


/*
    Function        :   AmFmRadio()
    Parameters      :   NONE
    Return Value    :   bool powerStatus - radio's on or off status
    Description     :   This is the accessor for the radio power status.
*/
bool AmFmRadio::GetPowerStatus(void)
{
    return powerStatus;
}



/*
    Function        :   SetStation()
    Parameters      :   double newStation
    Return Value    :   bool - success status indicating if property mutation
                                performed successfully.
    Description     :   This is the mutator for the current station.
*/
bool AmFmRadio::SetStation(double newStation)
{
    // AM
    if (strcmp(AM_BAND2, GetBand()) == 0)
    {
        //  less than min. frequency?
        if (GetStation() < AM_MIN)
        {
            station = AM_MIN;
        }

        // greater than max. frequency?
        else if (GetStation() > AM_MAX)
        {
            station = AM_MAX;
        }

        else
        {
            station = newStation;
        }

        return SUCCESS;
    }

    else if (strcmp(FM_BAND2, GetBand()) == 0)
    {
        //  less than min. frequency?
        if (GetStation() < FM_MIN)
        {
            station = FM_MIN;
        }

        // greater than max. frequency?
        else if (GetStation() > FM_MAX)
        {
            station = FM_MAX;
        }

        else
        {
            station = newStation;
        }

        return SUCCESS;
    }

    else
    {
        return FAILURE;
    }
}



// /*
//     Function        :   SetBand()
//     Parameters      :   const char* newBand - "AM" or "FM" string
//     Return Value    :   bool - success status indicating if property mutation
//                                 performed successfully.
//     Description     :   This is the mutator for the current band.
// */
// bool AmFmRadio::SetBand(const char* newBand)
// {
//     if (strcmp(newBand, AM_BAND2) == 0)
//     {
//         strcpy(band, AM_BAND2);
//         return SUCCESS;
//     }
//     else if (strcmp(newBand, FM_BAND2) == 0)
//     {
//         strcpy(band, FM_BAND2);
//         return SUCCESS;
//     }
//     else
//     {
//         return FAILURE;
//     }
// }



/*
    Function        :   SetVolume()
    Parameters      :   int newVolume - [0 - 100]
    Return Value    :   bool - success status indicating if property mutation
                                performed successfully.
    Description     :   This is the mutator for the current volume.
*/
bool AmFmRadio::SetVolume(int newVolume)
{
    if (newVolume < VOL_MIN)
    {
        volume = VOL_MIN;
        return SUCCESS;
    }
    else if (newVolume > VOL_MAX)
    {
        volume = VOL_MAX;
        return SUCCESS;
    }
    else
    {
        volume = newVolume;
        return FAILURE;
    }
}



// /*
//     Function        :   SetPowerStatus()
//     Parameters      :   bool newStatus - bool value indicating whether the AmFmRadio is on/off.
//     Return Value    :   bool - success status indicating if property mutation
//                                 performed successfully.
//     Description     :   This is the mutator for the power status.
// */
// bool AmFmRadio::SetPowerStatus(bool newStatus)
// {
//     if (newStatus == POWER_ON)
//     {
//         powerStatus = POWER_ON;
//         return SUCCESS;
//     }
//     else if (newStatus == POWER_OFF)
//     {
//         powerStatus = POWER_OFF;
//         return SUCCESS;
//     }
//     else
//     {
//         return FAILURE;
//     }
// }



/*
    Function        :   SetPresetButton()
    Parameters      :   int buttonNum - preset button indices valued from 0 - 4
    Return Value    :   bool - success status indicating if property mutation
                                performed successfully.
    Description     :   This is the mutator for the specified preset button.
*/
bool AmFmRadio::SetPresetButton(int buttonNum)
{
    // validate preset button value range
    if ((buttonNum >= 0) && (buttonNum <= PRESET_BUTTONS - 1))
    {
        presetButton = buttonNum;

        // AM?
        if (strcmp(AM_BAND2, GetBand()) == 0)
        {
            presets[buttonNum].AMPrevFreq = station;
            presets[buttonNum].AMFreq = station;
        }
        else if (strcmp(FM_BAND2, GetBand()) == 0)
        {
            presets[buttonNum].FMPrevFreq = station;
            presets[buttonNum].FMFreq = station;
        }
        return SUCCESS;
    }

    return FAILURE;
}



/*
    Function        :   TogglePower()
    Parameters      :   NONE
    Return Value    :   NONE
    Description     :   This method toggles the power status.
*/
void AmFmRadio::TogglePower(void)
{
    if (powerStatus == true)
    {
        powerStatus = false;
        volume = prevVolume;
        //strcpy(band, AM_BAND2);
        

    }
    else
    {
        powerStatus = true;
        volume = VOL_MIN;
    }
}



/*
    Function        :   ToggleBand()
    Parameters      :   NONE
    Return Value    :   NONE
    Description     :   This method toggles the AmFmRadio band.
*/
void AmFmRadio::ToggleBand(void)
{
    if (strcmp(GetBand(), AM_BAND2) == 0)
    {
        strcpy(band, FM_BAND2);
        station = presets[GetPresetButton()].FMPrevFreq;
    }
    else 
    {
        strcpy(band, AM_BAND2);
        station = presets[GetPresetButton()].AMPrevFreq;
    }

}



/*
    Function        :   ScanUp()
    Parameters      :   NONE
    Return Value    :   NONE
    Description     :   This method changes the station by incrementing the freqencey value.
*/
void AmFmRadio::ScanUp(void)
{
    // AM
    if (strcmp(GetBand(), AM_BAND2) == 0)
    {
        // AM_MAX?
        if (GetStation() >= AM_MAX)
        {
            SetStation(AM_MIN);
        }
        else
        {
            //presets[presetButton].AMPrevFreq = station;
            SetStation(station + AM_INC);
        }
    }
    // FM
    else if (strcmp(GetBand(), FM_BAND2) == 0)
    {
        // FM_MAX
        if (GetStation() >= FM_MAX)
        {
            SetStation(FM_MIN);
        }
        else
        {
            //presets[presetButton].FMPrevFreq = station;
            SetStation(station + FM_INC);
            
        }
    }

    if (GetDisplayOutput())
    {
        printf("\nCurrent station: %f %s\n", GetStation(), GetBand());
    }

}



/*
    Function        :   ScanDown()
    Parameters      :   NONE
    Return Value    :   NONE
    Description     :   This method changes the station by decrementing the freqencey value.
*/
void AmFmRadio::ScanDown(void)
{
    // AM
    if (strcmp(GetBand(), AM_BAND2) == 0)
    {
        // AM MIN?
        if (GetStation() <= AM_MIN)
        {
            SetStation(AM_MAX);
        }
        else 
        {
            // presets[presetButton].AMPrevFreq = station;
            SetStation(station - AM_INC);
        }

    }
    // FM
    else if (strcmp(GetBand(), FM_BAND2) == 0)
    {
        // FM MIN
        if (GetStation() >= FM_MIN)
        {
            SetStation(FM_MAX);
        }
        else
        {
            //presets[presetButton].FMPrevFreq = station;
            SetStation(station - FM_INC);
        }
    }

    if (GetDisplayOutput())
    {
        printf("\nCurrent station: %f %s\n", GetStation(), GetBand());
    }
}



/*
    Function        :   GetDisplayOutput()
    Parameters      :   NONE
    Return Value    :   bool - true/false.
    Description     :   This accessor returns the bool indicating whether output 
                        should be displayed or not.
*/
bool AmFmRadio::GetDisplayOutput(void)
{
    return displayOutput;
}



/*
    Function        :   SetDisplayOutput()
    Parameters      :   bool newDisplayOutput - true/false
    Return Value    :   bool - true/false.
    Description     :   This mutator sets the new status for the display output property.
*/
bool AmFmRadio::SetDisplayOutput(bool newDisplayStatus)
{
    displayOutput = newDisplayStatus;
}



/*
    Function        :   GetRadioPresets()
    Parameters      :   int presetButton - index value indicating preset button
    Return Value    :   Freqs* - value indicating station set at specfied preset button
    Description     :   This accessor returns the element located at the specified array location.
*/
Freqs* AmFmRadio::GetRadioPreset(int presetButton)
{
    return &presets[presetButton];
}


