/**
 * Marlin 3D Printer Firmware
 * Copyright (c) 2020 MarlinFirmware [https://github.com/MarlinFirmware/Marlin]
 *
 * Based on Sprinter and grbl.
 * Copyright (c) 2011 Camiel Gubbels / Erik van der Zalm
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 */
#pragma once

/**
 * Mightyboard Rev.G/Rev.H pin assignments
 */

/**
 * Rev B  2 JAN 2017
 *
 *  Added pin definitions for:
 *    M3, M4 & M5 spindle control commands
 *    case light
 *
 *  Corrected pin assignment for EX2_HEAT_PIN pin. Changed it from 9 to 11.  The port
 *  number (B5) agrees with the schematic but B5 is assigned to logical pin 11.
 */

#if !defined(__AVR_ATmega1280__) && !defined(__AVR_ATmega2560__)
  #error "Oops! Select 'Mega 1280' or 'Mega 2560' in 'Tools > Board.'"
#endif

#define BOARD_INFO_NAME      "MightyboardH"
#define DEFAULT_MACHINE_NAME "MB Replicator"

//
// Servos
//
// #define SERVO0_PIN                            36  // C1 (1280-EX1)
// #define SERVO1_PIN                            37  // C0 (1280-EX2)
// #define SERVO2_PIN                            40  // G1 (1280-EX3)
// #define SERVO3_PIN                            41  // G0 (1280-EX4)

//
// Limit Switches
//
#define X_MIN_PIN                             72  // J2
#define X_MAX_PIN                             30  // C7
#define Y_MIN_PIN                             14  // J1
#define Y_MAX_PIN                             31  // C6
#define Z_MIN_PIN                             32  // C5
#define Z_MAX_PIN                             15  // J0


//
// Filament Runout Pins
//
// #ifndef FIL_RUNOUT_PIN
//   #define FIL_RUNOUT_PIN                      49
// #endif
// #ifndef FIL_RUNOUT2_PIN
//   #define FIL_RUNOUT2_PIN                     47
// #endif

//
// Steppers
//
#define X_STEP_PIN                            83  // D6 active rising edge
#define X_DIR_PIN                             38  // D7 forward on high
#define X_ENABLE_PIN                          81  // D4 active low

#define Y_STEP_PIN                            44  // L5 active rising edge
#define Y_DIR_PIN                             42  // L7 forward on high
#define Y_ENABLE_PIN                          45  // L4 active low

#define Z_STEP_PIN                            48  // L1 active rising edge
#define Z_DIR_PIN                             47  // L2 forward on high
#define Z_ENABLE_PIN                          49  // L0 active low

#define E0_STEP_PIN                           25  // A3 active rising edge
#define E0_DIR_PIN                            24  // A2 forward on high
#define E0_ENABLE_PIN                         27  // A5 active low

#define E1_STEP_PIN                           22  // A0 active rising edge
#define E1_DIR_PIN                            69  // K7 forward on high
#define E1_ENABLE_PIN                         23  // A1 active low

//
// I2C Digipots - MCP4018
// Address 5E (2F << 1)
// Set from 0 - 127 with stop bit.
// (Ex. 3F << 1 | 1)
//
#define DIGIPOTS_I2C_SCL                      28  // A6
#define DIGIPOTS_I2C_SDA_X                    82  // D5
#define DIGIPOTS_I2C_SDA_Y                    43  // L6
#define DIGIPOTS_I2C_SDA_Z                    46  // L3
#define DIGIPOTS_I2C_SDA_E0                   26  // A4
#define DIGIPOTS_I2C_SDA_E1                   74  // J7

// #ifndef DIGIPOT_I2C_ADDRESS_A
//   #define DIGIPOT_I2C_ADDRESS_A 0x2F              // unshifted slave address (5E <- 2F << 1)
// #endif

//
// Temperature Sensors
//
// ADC 3 (pin 94)
#define TEMP_BED_PIN                          3

// SPI for TI ADS1118 ADC for Thermocouples
// Uses a separate SPI bus
//
#define ADS1118_SCK_PIN                        78  // E2
#define ADS1118_DO_PIN                         84  // H2
#define ADS1118_DIN_PIN                        80  // E7
#define ADS1118_CS_PIN                         73  // E6

//
// Heaters / Fans (24V)
//
#define HEATER_0_PIN              3  // E5
#define HEATER_1_PIN              5  // E3
#define HEATER_BED_PIN            8  // H5
#define FAN_PIN                   4  // G5

#define E0_AUTO_FAN_PIN             7  // H4
#define E1_AUTO_FAN_PIN             2  // E4

//
// Misc. Functions
//
#define LED_PIN                               13  // B7

//
// LCD / Controller
//
#if HAS_SPI_LCD

  #if ENABLED(REPRAP_DISCOUNT_FULL_GRAPHIC_SMART_CONTROLLER)

    #define LCD_PINS_RS                       33  // C4: LCD-STROBE
    #define LCD_PINS_ENABLE                   72  // J2: LEFT
    #define LCD_PINS_D4                       35  // C2: LCD-CLK
    #define LCD_PINS_D5                       32  // C5: RLED
    #define LCD_PINS_D6                       34  // C3: LCD-DATA
    #define LCD_PINS_D7                       31  // C6: GLED

    #define BTN_EN2                           75  // J4, UP
    #define BTN_EN1                           73  // J3, DOWN
    //STOP button connected as KILL_PIN
    #define KILL_PIN                          14  // J1, RIGHT
    //KILL - not connected

    #define BEEPER_PIN                         8  // H5, SD_WP

    //on board leds
    #define STAT_LED_RED_LED          SERVO0_PIN  // C1 (1280-EX1, DEBUG2)
    #define STAT_LED_BLUE_PIN         SERVO1_PIN  // C0 (1280-EX2, DEBUG3)

  #else
    // Replicator uses a 3-wire SR controller with HD44780
    #define SR_DATA_PIN                       37  // C0
    #define SR_CLK_PIN                        36  // C1
    #define SR_STROBE_PIN                     34  // C3

    #define BTN_UP                            76  // J5
    #define BTN_DWN                           75  // J4
    #define BTN_RT                            73  // J3
    #define BTN_LFT                           77  // J6

    // Disable encoder
    #undef BTN_EN1
    #undef BTN_EN2

    #define BEEPER_PIN                         6  // H3

    #define STAT_LED_RED_PIN                  35  // C2
  #endif

  #define BTN_CENTER                          39  // G2
  #define BTN_ENC                     BTN_CENTER

#endif // HAS_SPI_LCD

//
// SD Card
//
#define SDSS                                  53  // B0
#define SD_DETECT_PIN                         40  // G1
#define SDPOWER_PIN                           29  // A7  @todo "INTERFACE POWER"

//
// RGB LEDs
//
// @todo uses I2c
// #define RGB_LED_R_PIN
// #define RGB_LED_G_PIN
// #define RGB_LED_B_PIN

//
// TMC 220x
//
#if HAS_TMC_UART
  /**
   * TMC220x stepper drivers
   *
   * Hardware serial communication ports.
   * If undefined software serial is used according to the pins below
   */
  #define X_HARDWARE_SERIAL Serial2
  #define Y_HARDWARE_SERIAL Serial1

  /**
   * Software serial
   */

  #define X_SERIAL_TX_PIN                     16
  #define X_SERIAL_RX_PIN                     17

  #define Y_SERIAL_TX_PIN                     18
  #define Y_SERIAL_RX_PIN                     19

  #define Z_SERIAL_TX_PIN                     41
  #define Z_SERIAL_RX_PIN                     66

  #define E0_SERIAL_TX_PIN                    40
  #define E0_SERIAL_RX_PIN                    67

  #define E1_SERIAL_TX_PIN                    37
  #define E1_SERIAL_RX_PIN                    68

#endif
