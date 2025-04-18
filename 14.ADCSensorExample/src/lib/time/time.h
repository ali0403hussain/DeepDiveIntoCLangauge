/**
 * @file time.h
 * 
 * @description time library
 * 
 * @author - Ali Hussain
 * @date   - 08-04-2025
 * @email  - ali0403hussain@gmail.com
 * 
 * @copyright (c) 2025 Ali Hussain
 */

 #ifndef TIME_H_INCLUDE
 #define TIME_H_INCLUDE
 
 /**********************************************************
  * Includes
  **********************************************************/
 #include "types.h"

 /**********************************************************
 * Macros
 **********************************************************/
// Set CPU Frequency for your system
#define CPU_FREQUENCY_HZ                   ( 1800000000U ) // 1.8 GHz (1,800,000,000U Hz)
#define CPU_CYCLES_1_8_GHZ_1_PER_10_SEC    ( 180000000U ) // 0.1 x 1,800,000,000 cycles = 180,000,000 cycles
#define MILLI_SEC_PER_SEC                  ( 1000U )  
#define MICRO_SEC_PER_SEC                  ( 1000000U )

/**********************************************************
 * Struct, Enums, and Typedef 
 **********************************************************/
/**
 * @brief Typedef enum for time statuc codes
 */
typedef enum {
    TIME_STATUS_GOOD = 0,
    TIME_STATUS_INSTANCE_INVALID = 1,
    TIME_STATUS_ARGUMENT_INVALID = 2,
    TIME_STATUS_PARAMETER_OUT_OF_RANGE = 3,
    TIME_STATUS_TIMER_NOT_EXPIRED = 4,
    TIME_STATUS_TIMER_EXPIRED = 5
}TimeStatusCode;

typedef unsigned long long size_frequency_t;    //<! typedef for cpu frequency size

typedef struct Time Time;   //<! Forward decleration for struct

/**
 * @brief interface to get estimate cpu frequency in HZ
 * 
 * @param object pointer to Time instance
 * @param frequencyHz pointer to variable to return frequency
 * 
 * @return @TimeStatusCode
 */
typedef TimeStatusCode (*Time_estimateCpuFrequencyHz)( Time *object, size_frequency_t *frequencyHz );

/**
 * @brief interface to start software timer
 * 
 * @param object pointer to Time instance
 * 
 * @return @TimeStatusCode
 */
typedef TimeStatusCode (*Time_startTimer)( Time *object );

/**
 * @brief interface to stop software timer
 * 
 * @param object pointer to Time instance
 * 
 * @return @TimeStatusCode
 */
typedef TimeStatusCode (*Time_stopTimer)( Time *object );

/**
 * @brief interface to delay
 * 
 * @param object pointer to Time instance
 * @param delayMilliseconds delay in millisec
 * 
 * @return @TimeStatusCode
 */
typedef TimeStatusCode (*Time_delayMs)( Time *object, uint32_t delayMilliseconds );

/**
 * @brief struct interface for time
 */
typedef struct {
    Time_estimateCpuFrequencyHz getEstimateCpuFrequency;
    Time_startTimer startTimer;
    Time_stopTimer stopTimer;
    Time_delayMs delayMs;
}TimeInterface;

/**
 * @brief Struct for software timer
 */
typedef struct {
    uint32_t startTick;
    uint32_t duration;
    bool isRunning;
}TimeSoftwareTimer;

/**
 * @ Struct for Time
 */
struct Time {
    size_frequency_t frequencyHz;
    TimeInterface interface;
    TimeSoftwareTimer softTimer;
};

/***********************************************************
 * Forward declerations and global variables
 **********************************************************/
/**
 * @brief Fuction to initialize time
 * 
 * @param object pointer to time instance
 * 
 * @return @TimeStatusCode
 */
TimeStatusCode Time_init( Time *object );

/***********************************************************
 * Functions Declerations
 **********************************************************/

 
 #endif // TIME_H_INCLUDE
    
    