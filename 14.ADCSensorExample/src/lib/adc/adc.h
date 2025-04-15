/**
 * @file adc.h
 * 
 * @description adc library
 * 
 * @author - Ali Hussain
 * @date   - 08-04-2025
 * @email  - ali0403hussain@gmail.com
 * 
 * @copyright (c) 2025 Ali Hussain
 */


/**********************************************************
 * Macros
 **********************************************************/

#ifndef ADC_H_INCLUDE
#define ADC_H_INCLUDE

#define POW2(x)           (1U << x)  //<!2^x macro   

#define ADC_MAX_CHANNELS   (3U)
#define ADC_MAX_VOLTAGE    (5U)
#define ADC_MAX_RESOLUTION (16U)

/**********************************************************
 * Includes
 **********************************************************/
#include <stdint.h>

/***********************************************************
 * Forward declerations and global variables
 **********************************************************/

/**********************************************************
 * Struct, Enums, and Typedef 
 **********************************************************/
/**
 * @brief Typedef enum for adc statuc codes
 */
typedef enum {
    ADC_STATUS_GOOD = 0,
    ADC_STATUS_INSTANCE_INVALID = 1,
    ADC_STATUS_ARGUMENT_INVALID = 2,
    ADC_STATUS_PARAMETER_OUT_OF_RANGE = 3
}AdcStatusCode;

/**
 * @brief Typedef struct for adc
 */
typedef struct {
    uint32_t resolution;     //<! adc resolution 
    double vref;             //<! adc reference voltage
    double sensitivity;      //<! adc sensitivity
    uint8_t channel;         //<! channel for adc
    uint8_t resolutionBits;  //adc resolution in bits
    uint8_t __pad[2];
}AdcParam;

/**
 * @brief Typedef struct for adc 
 */
typedef struct {
    AdcParam adcParameters;
    AdcInterface interface;
}Adc;

/**
 * @brief Interface function to convert Analog to digital
 * 
 * @param object pointer to adc instance
 * @param rawInput rawInput Value
 * @param ptrDigitalValue pointer to converted digital value
 * 
 * @return 
 */
typedef AdcStatusCode (*Adc_ConvertAnalogToDigital)(Adc *object, const double rawInput, uint32_t *ptrDigitalValue);

/**
 * @brief Typedef struct for adc interface
 */
typedef struct {
    Adc_ConvertAnalogToDigital adcInterface;
}AdcInterface;


/***********************************************************
 * Functions Declerations
 **********************************************************/

/**
 * @brief local function to convert Analog to digital
 * 
 * @param object pointer to adc instance
 * @param rawInput rawInput Value
 * @param ptrDigitalValue pointer to converted digital value
 * 
 * @return AdcStatusCode
 */
static AdcStatusCode loc_adcCovertAnalogToDigital(Adc *object, const double rawInput, uint32_t *ptrDigitalValue);

/**
 * @brief function to init Analog to digital
 * 
 * @param object pointer to adc object
 * 
 * @return AdcStatusCode
 */
AdcStatusCode Adc_Init( Adc *object );
 
 #endif // ADC_H_INCLUDE
  
  