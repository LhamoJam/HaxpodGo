//==============================================================================
//Lynxmotion Phoenix Clone
//
//Version:    3.1
//Date:       09-04-2018
//Programmer: Jeroen Janssen    (Xan)   - Main code
//            Kurt Eckhardt     (KurtE) - Converted to arduino
//            Lex van Teeffelen (Lexons)- Converted to AliExpress Hexapod
//            misbah najh       (misbah)- Converted movement work better 
//This code should only be used on phoenix clones running the 
// Lynxmotion SSC32-U and PS2 remote.
//==============================================================================

#ifndef HEX_CFG_PHOENIX3_H
#define HEX_CFG_PHOENIX3_H

#define OPT_GPPLAYER
#define OPT_SINGLELEG

#define DBGSerial Serial
//#define DEBUG_IOPINS

#if defined(UBRR1H)
#define SSCSerial Serial1
#else
#endif

#define USEPS2
#define USE_SSC32
#define cSSC_BAUD 115200  //SSC32 BAUD rate, recheck on SCC boudrate jumpers setting

//==============================================================================
//[Arduino pin configuration]
#define SOUND_PIN    5 
#define PS2_DAT      6
#define PS2_CMD      7
#define PS2_SEL      8 // On the PS2 receiver this pin may be called ATT (attention)
#define PS2_CLK      9
#define cSSC_IN      12 //Output pin for (SSC32 TX/output)
#define cSSC_OUT     11 //Output pin for (SSC32 RX/input)

//==============================================================================
//[SSC32 pin configuration]
#define cRRCoxaPin      0   //Rear Right leg Hip Horizontal (coxa)
#define cRRFemurPin     1   //Rear Right leg Hip Vertical (femur)
#define cRRTibiaPin     2   //Rear Right leg Knee (tibia)

#define cRMCoxaPin      4   //Middle Right leg Hip Horizontal (coxa)
#define cRMFemurPin     5   //Middle Right leg Hip Vertical (femur)
#define cRMTibiaPin     6   //Middle Right leg Knee (tibia)

#define cRFCoxaPin      8   //Front Right leg Hip Horizontal (coxa)
#define cRFFemurPin     9   //Front Right leg Hip Vertical (femur)
#define cRFTibiaPin     10   //Front Right leg Knee (tibia)

#define cLRCoxaPin      16   //Rear Left leg Hip Horizontal (coxa)
#define cLRFemurPin     17   //Rear Left leg Hip Vertical (femur)
#define cLRTibiaPin     18   //Rear Left leg Knee (tibia)

#define cLMCoxaPin      20   //Middle Left leg Hip Horizontal (coxa)
#define cLMFemurPin     21   //Middle Left leg Hip Vertical (femur)
#define cLMTibiaPin     22   //Middle Left leg Knee (tibia)

#define cLFCoxaPin      24   //Front Left leg Hip Horizontal (coxa)
#define cLFFemurPin     25   //Front Left leg Hip Vertical (femur)
#define cLFTibiaPin     26   //Front Left leg Knee (tibia)

//==============================================================================
//[Inverse Servo Direction]
#define cRRCoxaInv  0
#define cRMCoxaInv  0
#define cRFCoxaInv  0
#define cRRFemurInv 0
#define cRMFemurInv 0
#define cRFFemurInv 0
#define cRRTibiaInv 0
#define cRMTibiaInv 0
#define cRFTibiaInv 0

#define cLRCoxaInv  1
#define cLMCoxaInv  1
#define cLFCoxaInv  1
#define cLRFemurInv 1
#define cLMFemurInv 1
#define cLFFemurInv 1
#define cLRTibiaInv 1
#define cLMTibiaInv 1
#define cLFTibiaInv 1

//==============================================================================
//[Min/Max angles]
#define cRRCoxaMin1   -260       //Mechanical limits of the Right Rear Leg
#define cRRCoxaMax1   740
#define cRRFemurMin1  -1010
#define cRRFemurMax1  950
#define cRRTibiaMin1  -1060
#define cRRTibiaMax1  770

#define cRMCoxaMin1   -530      //Mechanical limits of the Right Middle Leg
#define cRMCoxaMax1   530
#define cRMFemurMin1  -1010
#define cRMFemurMax1  950
#define cRMTibiaMin1  -1060
#define cRMTibiaMax1  770

#define cRFCoxaMin1   -580      //Mechanical limits of the Right Front Leg
#define cRFCoxaMax1   740
#define cRFFemurMin1  -1010
#define cRFFemurMax1  950
#define cRFTibiaMin1  -1060
#define cRFTibiaMax1  770

#define cLRCoxaMin1   -740      //Mechanical limits of the Left Rear Leg
#define cLRCoxaMax1   260
#define cLRFemurMin1  -950
#define cLRFemurMax1  1010
#define cLRTibiaMin1  -770
#define cLRTibiaMax1  1060

#define cLMCoxaMin1   -530      //Mechanical limits of the Left Middle Leg
#define cLMCoxaMax1   530
#define cLMFemurMin1  -950
#define cLMFemurMax1  1010
#define cLMTibiaMin1  -770
#define cLMTibiaMax1  1060

#define cLFCoxaMin1   -740      //Mechanical limits of the Left Front Leg
#define cLFCoxaMax1   580
#define cLFFemurMin1  -950
#define cLFFemurMax1  1010
#define cLFTibiaMin1  -770
#define cLFTibiaMax1  1060

//==============================================================================
//[Leg dimensions]
//Universal dimensions for each leg in mm
//Set up for the AliExpress Phoenix Clones!
#define cXXCoxaLength     29     // This is for CH3-R with Type 3 legs
#define cXXFemurLength    76
#define cXXTibiaLength    106

#define cRRCoxaLength     cXXCoxaLength         //Right Rear leg
#define cRRFemurLength    cXXFemurLength
#define cRRTibiaLength    cXXTibiaLength

#define cRMCoxaLength     cXXCoxaLength         //Right middle leg
#define cRMFemurLength    cXXFemurLength
#define cRMTibiaLength    cXXTibiaLength

#define cRFCoxaLength     cXXCoxaLength         //Rigth front leg
#define cRFFemurLength    cXXFemurLength
#define cRFTibiaLength    cXXTibiaLength

#define cLRCoxaLength     cXXCoxaLength         //Left Rear leg
#define cLRFemurLength    cXXFemurLength
#define cLRTibiaLength    cXXTibiaLength

#define cLMCoxaLength     cXXCoxaLength         //Left middle leg
#define cLMFemurLength    cXXFemurLength
#define cLMTibiaLength    cXXTibiaLength

#define cLFCoxaLength     cXXCoxaLength         //Left front leg
#define cLFFemurLength    cXXFemurLength
#define cLFTibiaLength    cXXTibiaLength

//==============================================================================
//[Body dimensions in mm]
#define cRRCoxaAngle1    -600   //Default Coxa setup angle, decimals = 1
#define cRMCoxaAngle1    0      //Default Coxa setup angle, decimals = 1
#define cRFCoxaAngle1    600    //Default Coxa setup angle, decimals = 1
#define cLRCoxaAngle1    -600   //Default Coxa setup angle, decimals = 1
#define cLMCoxaAngle1    0      //Default Coxa setup angle, decimals = 1
#define cLFCoxaAngle1    600    //Default Coxa setup angle, decimals = 1

#define cRROffsetX       -43     //Distance X from center of the body to the Right Rear coxa
#define cRROffsetZ       73      //Distance Z from center of the body to the Right Rear coxa

#define cRMOffsetX       -51     //Distance X from center of the body to the Right Middle coxa
#define cRMOffsetZ       0       //Distance Z from center of the body to the Right Middle coxa

#define cRFOffsetX       -43     //Distance X from center of the body to the Right Front coxa
#define cRFOffsetZ       -73     //Distance Z from center of the body to the Right Front coxa

#define cLROffsetX       43      //Distance X from center of the body to the Left Rear coxa
#define cLROffsetZ       73      //Distance Z from center of the body to the Left Rear coxa

#define cLMOffsetX       51      //Distance X from center of the body to the Left Middle coxa
#define cLMOffsetZ       0       //Distance Z from center of the body to the Left Middle coxa

#define cLFOffsetX       43      //Distance X from center of the body to the Left Front coxa
#define cLFOffsetZ       -73     //Distance Z from center of the body to the Left Front coxa

//==============================================================================
//[Start positions legs]
#define cHexInitXZ       105
#define CHexInitXZCos60  53     // COS(60) = .5
#define CHexInitXZSin60  91     // sin(60) = .866
#define CHexInitY        25

#define cRRInitPosX      CHexInitXZCos60      //Start positions of the Right Rear leg
#define cRRInitPosY      CHexInitY
#define cRRInitPosZ      CHexInitXZSin60

#define cRMInitPosX      cHexInitXZ           //Start positions of the Right Middle leg
#define cRMInitPosY      CHexInitY
#define cRMInitPosZ      0

#define cRFInitPosX      CHexInitXZCos60      //Start positions of the Right Front leg
#define cRFInitPosY      CHexInitY
#define cRFInitPosZ      -CHexInitXZSin60

#define cLRInitPosX      CHexInitXZCos60      //Start positions of the Left Rear leg
#define cLRInitPosY      CHexInitY
#define cLRInitPosZ      CHexInitXZSin60

#define cLMInitPosX      cHexInitXZ           //Start positions of the Left Middle leg
#define cLMInitPosY      CHexInitY
#define cLMInitPosZ      0

#define cLFInitPosX      CHexInitXZCos60      //Start positions of the Left Front leg
#define cLFInitPosY      CHexInitY
#define cLFInitPosZ      -CHexInitXZSin60

//==============================================================================
#endif CFG_HEX_H
