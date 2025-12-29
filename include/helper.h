#ifndef HELPER_H
#define HELPER_H
#include <Arduino.h>
#include <display_driver.h>


//DCS BIOS Forks
#ifdef DCSBIOS_WIFI_FORK 
    #define DCSBIOS_LAN    // LAN Access
    #define DCSBIOS_ESP32  // ESP32 microcontroller
    #define SERIAL_LOG 0   //Set to 1 to enable serial debugging 
#endif

#ifdef DCSBIOS_DEFAULT
    #define DCSBIOS_DEFAULT_SERIAL
#endif 


//Variables


// lighting test switch active
bool test_switch_enabled = false;


//Aircraft 
bool ishornet = false;
// demo variables
unsigned long nozzle_update = 0;
bool demo_forward = true;
bool reset = false;
int demo_counter = 0;


// Create tft screen 
LGFX tft;




// Create sprites 

#ifdef DOUBLE_FRAME_BUFFER
	LGFX_Sprite sMainSprite[2]; 
#else
	LGFX_Sprite sMainSprite[2]; 
#endif 
LGFX_Sprite sADI_BALL;   // ADI BALL
LGFX_Sprite sADI_BEZEL_MOST_INNER; // ADI INNER RING
LGFX_Sprite sADI_BEZEL_Inner; // ADI BEZEL
LGFX_Sprite sADI_OFF_FLAG;    //ADI OFF FLAG
LGFX_Sprite sADI_BEZEL; // ADI BEZEL
LGFX_Sprite sADI_SLIP_BEZEL;   //ADI SLIP BEZEL
LGFX_Sprite sADI_SLIP_BALL;  //ADI WINGS
LGFX_Sprite sADI_WINGS;  //ADI WINGS
LGFX_Sprite sILS_POINTER_H;  //ADI WINGS
LGFX_Sprite sILS_POINTER_V;  //ADI WINGS
LGFX_Sprite sTURN_RATE;  //ADI WINGS
LGFX_Sprite sWARNING_FLAG;  //ADI WINGS
LGFX_Sprite sBANK_INDICATOR;



// Create data structure for display elements
struct display_element{
  int sprite_width;
  int sprite_height;
  int pos_x;
  int pos_y;
  int angel;
  LGFX_Sprite* sprite;
};

// Enumeration of display elements
enum Display_Name{
    ADI_BEZEL,
	ADI_BALL,
	ADI_BEZEL_INNER,
    ADI_BEZEL_MOST_INNER,
	ADI_OFF_FLAG,
    ADI_WINGS,
	ADI_SLIP_BEZEL,
	ILS_POINTER_H,
	ILS_POINTER_V,
    SLIP_BALL,
    TURN_RATE,
    WARNING_FLAG,
    BANK_INDICATOR
};

// Functions
char* remove_trailing_spaces(const char* str) {
    if (str == nullptr || *str == '\0') {
        return nullptr; 
    }

    int length = strlen(str);
    while (length > 0 && isspace(str[length - 1])) {
        length--;
    }

    char* result = new char[length + 1];
    strncpy(result, str, length);
    result[length] = '\0';

    return result;
}
#endif
