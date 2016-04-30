/***************************************************************************//**
 * @file		jos_config.c
 *				This source file provides configuration (to add tasks)
 * 				to jos.
 *
 * @author		Jaydeep Dhrangdhariya (jaydeep.gajjar90@gmail.com)
 *
 * @attention  
 *  
 * The MIT License (MIT)
 *  
 * Copyright (c) 2016 Jaydeep Dhrangdhariya
 * 
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 * 
 * The above copyright notice and this permission notice shall be included in 
 * all copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 ******************************************************************************/

/* Includes ------------------------------------------------------------------*/
#include "jos.h"
#include "jos_config.h"

/**
 *******************************************************************************
 * Add header files below 
 ******************************************************************************/

/******************************************************************************/

/** @defgroup   jos_config_module	JOS Configuration
  * @{
  */

/* Private constants ---------------------------------------------------------*/
/* Private macros ------------------------------------------------------------*/
/* Private types -------------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Exported variables --------------------------------------------------------*/

/** @defgroup   jos_config_module	JOS Configuration - Exported variables
  * @{
  */

jos_task_t * jos_tasks[] = {

/**
  * To add new tasks to schedular just use this macro below:
  * 
  *		JOS_TASK_ADD(name),
  * 
  * Do not forget to put comma ',' at the end the macro.
  */
/************************* Add the tasks below ********************************/

/******************************************************************************/
};

/**
  * @}
  */

/* Exported functions --------------------------------------------------------*/

/** @defgroup   jos_config_module	JOS Configuration - Exported functions
  * @{
  */
  
/**
  * @brief  	Returns total number of jos tasks table/structure.
  * @param  	None
  * @return 	Number of total tasks.
  */
int jos_config_get_total_tasks(void)
{
	return sizeof(jos_tasks)/sizeof(jos_tasks[0]);
}

/**
  * @}
  */

/* Private functions ---------------------------------------------------------*/

/**
  * @}
  */

/* End of file ---------------------------------------------------------------*/
