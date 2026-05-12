#ifndef CONFIGURATION_H
#define CONFIGURATION_H

// --- FORCED 600mm BUILD SETTINGS ---
#define Z_MAX_POS 600
#define Z_MIN_POS 0
#define X_MAX_POS 250
#define Y_MAX_POS 212.5
#define X_ENABLE_ON 0
#define Y_ENABLE_ON 0
#define Z_ENABLE_ON 0
#define E_ENABLE_ON 0
#define X_HOME_DIR -1
#define Y_HOME_DIR -1
#define Z_HOME_DIR -1
#define X_MAX_ENDSTOP_INVERTING 0
#define Y_MAX_ENDSTOP_INVERTING 0
#define Z_MAX_ENDSTOP_INVERTING 0
#define HOME_Z_SEARCH_THRESHOLD 2.0
#define MESH_HOME_Z_SEARCH 5.0
#define min_software_endstops 1
#define max_software_endstops 1
#define Z_HEIGHT_HIDE_LIVE_ADJUST_MENU 2.0
#define DISABLE_Z_MAX_PROTECTION
#define NUM_AXIS 4
// --- END FORCED SETTINGS ---

#include "boards.h"

// Bed Leveling Dependencies
#define MESH_BED_LEVELING
#define BED_CHECK_TOLERANCE 0.1
#define BED_CHECK_ITERATIONS 3

// Physical offsets/Safe homing
#define Z_RAISE_BEFORE_HOMING 5 
#define Z_SAFE_HOMING_X_POINT 125
#define Z_SAFE_HOMING_Y_POINT 105
// ===================================

#include "boards.h"

#define STR_HELPER(x) #x
#define STR(x) STR_HELPER(x)
#define _CONCAT(x,y) x##y
#define CONCAT(x,y) _CONCAT(x,y)

#include <avr/pgmspace.h>
extern const uint16_t _nPrinterType;
extern const char _sPrinterName[] PROGMEM;
extern const uint16_t _nPrinterMmuType;
extern const char _sPrinterMmuName[] PROGMEM;

#ifndef CMAKE_CONTROL
#define FW_MAJOR 3
#define FW_MINOR 13
#define FW_REVISION 3
#define FW_COMMITNR 7864
#endif

#ifndef FW_FLAVOR
    #define FW_TWEAK (FIRMWARE_REVISION_RELEASED)
    #define FW_VERSION STR(FW_MAJOR) "." STR(FW_MINOR) "." STR(FW_REVISION)
    #define FW_VERSION_FULL STR(FW_MAJOR) "." STR(FW_MINOR) "." STR(FW_REVISION) "-" STR(FW_COMMITNR)
#else
    #define FW_TWEAK (CONCAT(FIRMWARE_REVISION_,FW_FLAVOR) + FW_FLAVERSION)
    #define FW_VERSION STR(FW_MAJOR) "." STR(FW_MINOR) "." STR(FW_REVISION) "-" STR(FW_FLAVOR) "" STR(FW_FLAVERSION)
    #define FW_VERSION_FULL STR(FW_MAJOR) "." STR(FW_MINOR) "." STR(FW_REVISION) "-" STR(FW_FLAVOR) "" STR(FW_FLAVERSION) "-" STR(FW_COMMITNR)
#endif

#ifndef CMAKE_CONTROL
#define FW_COMMIT_HASH_LENGTH 1
#define FW_COMMIT_HASH "0"
#define FW_REPOSITORY "Unknown"
#ifndef FW_VERSION_FULL
#define FW_VERSION_FULL FW_VERSION
#endif
#endif

#define GCODE_LEVEL 1

#ifndef SOURCE_DATE_EPOCH
#define SOURCE_DATE_EPOCH __DATE__
#endif
#ifndef SOURCE_TIME_EPOCH
#define SOURCE_TIME_EPOCH __TIME__
#endif

#include "Configuration_var.h"

// Re-asserting Z values after Var file inclusion
#undef Z_MAX_POS
#define Z_MAX_POS 600
#undef Z_MIN_POS
#define Z_MIN_POS 0

#define FW_PRUSA3D_MAGIC "PRUSA3DFW"
#define FW_PRUSA3D_MAGIC_LEN 10

#include "eeprom.h"

#define STRING_VERSION_CONFIG_H SOURCE_DATE_EPOCH " " SOURCE_TIME_EPOCH 
#define STRING_CONFIG_H_AUTHOR "(none, custom 600h)" 

#define SERIAL_PORT 0
#define BAUDRATE 115200
#define ENABLE_MEATPACK
#define EXTRUDERS 1
#define POWER_SUPPLY 1

#define TEMP_RESIDENCY_TIME 3
#define TEMP_HYSTERESIS 5
#define TEMP_WINDOW 1

#define PIDTEMP
#define BANG_MAX 255
#define PID_MAX BANG_MAX
#ifdef PIDTEMP
  #define PID_INTEGRAL_DRIVE_MAX PID_MAX
  #define PID_K1 0.95
  #define PID_dT ((OVERSAMPLENR * 10.0)/(F_CPU / 64.0 / 256.0))
#endif

#define PREVENT_DANGEROUS_EXTRUDE
#define PREVENT_LENGTHY_EXTRUDE
#define EXTRUDE_MAXLENGTH (X_MAX_LENGTH+Y_MAX_LENGTH)

#define Z_PROBE_REPEATABILITY_TEST

#define DEFAULT_XJERK 10
#define DEFAULT_YJERK 10
#define DEFAULT_ZJERK 0.4
#define DEFAULT_EJERK 4.5

#define CUSTOM_M_CODES
#define HOST_KEEPALIVE_FEATURE
#define HOST_KEEPALIVE_INTERVAL 2

#define SDSUPPORT
#define SD_CHECK_AND_RETRY
#define ENCODER_PULSES_PER_STEP 4
#define REPRAP_DISCOUNT_SMART_CONTROLLER
#define LCD_WIDTH 20
#define LCD_HEIGHT 4

#define FAN_SOFT_PWM
#define FAN_SOFT_PWM_BITS 4
#define HEATER_BED_SOFT_PWM_BITS 5
#define SOFT_PWM_SCALE 0

#define DEFAULT_NOMINAL_FILAMENT_DIA 1.75
#define MIN_Z_FOR_LOAD 50
#define MIN_Z_FOR_UNLOAD 50
#define MIN_Z_FOR_SWAP 27
#define MIN_Z_FOR_PREHEAT 10

#include "Configuration_adv.h"
#include "thermistortables.h"

// Final Safeguard: Force these one last time
#undef Z_MAX_POS
#define Z_MAX_POS 600
#undef Z_MAX_LENGTH
#define Z_MAX_LENGTH 600

#endif //CONFIGURATION_H
