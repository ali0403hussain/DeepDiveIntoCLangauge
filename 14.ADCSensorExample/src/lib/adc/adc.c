/**
 * @file adc.c
 * 
 * @description Provides interfaces for adc
 * 
 * @author - Ali Hussain
 * @date   - 06-04-2025
 * @email  - ali0403hussain@gmail.com
 * 
 * @copyright (c) 2025 Ali Hussain
 */

/**********************************************************
 * Includes
 **********************************************************/
#include <stdio.h>
#include "time.h" 
#include "adc.h" 
 
/**********************************************************
 * Macros
 **********************************************************/
 
/**********************************************************
 * Struct, Enums, and Typedef 
 **********************************************************/
 
/***********************************************************
 * Forward declerations and global variables
 **********************************************************/
 
/***********************************************************
 * Function Prototype
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

/***********************************************************
 * Function Definations
 **********************************************************/
/**
 * @brief function to init Analog to digital
 * 
 * @param object pointer to adc object
 * 
 * @return AdcStatusCode
 */
AdcStatusCode Adc_Init( Adc *object )
{
    AdcStatusCode retValue = ADC_STATUS_GOOD;

    if ( NULL == object )
    {
        retValue = ADC_STATUS_INSTANCE_INVALID;
    }
    else if ( ( ( 0.00 >= object->adcParameters.vref ) &&
                ( ADC_MAX_VOLTAGE <= object->adcParameters.vref ) )|| 
                ( ( 0 >= object->adcParameters.channel ) && 
                ( ADC_MAX_CHANNELS <= object->adcParameters.channel ) ) || 
                ( ( 0 >= object->adcParameters.resolutionBits) && 
                ( ADC_MAX_RESOLUTION <= object->adcParameters.resolutionBits ) ) )
    {
        retValue = ADC_STATUS_PARAMETER_OUT_OF_RANGE;
    }
    else
    {
        object->adcParameters.resolution = POW2(object->adcParameters.resolutionBits);
        object->adcParameters.sensitivity = object->adcParameters.vref / (double)object->adcParameters.resolution;

        object->interface.converAnalogToDigital = &loc_adcCovertAnalogToDigital;

        //Calculate Adc sensitivity
        object->adcParameters.sensitivity = object->adcParameters.vref / (double)object->adcParameters.resolution;
    }

    return retValue;
}

/**
 * @brief local function to convert Analog to digital
 * 
 * @param object pointer to adc instance
 * @param rawInput rawInput Value
 * @param ptrDigitalValue pointer to converted digital value
 * 
 * @return AdcStatusCode
 */
AdcStatusCode loc_adcCovertAnalogToDigital(Adc *object, const double rawInput, uint32_t *ptrDigitalValue)
{
    AdcStatusCode retValue = ADC_STATUS_GOOD;

    if ( NULL == object )
    {
        retValue = ADC_STATUS_INSTANCE_INVALID;
    }
    else if ( ( 0.00 >= rawInput ) || (NULL == ptrDigitalValue ) )
    {
        retValue = ADC_STATUS_ARGUMENT_INVALID;
    }
    else
    {
        *ptrDigitalValue = (uint32_t) ( ( rawInput / object->adcParameters.vref) * ( object->adcParameters.resolution - 1) );
    }

    return retValue;
}