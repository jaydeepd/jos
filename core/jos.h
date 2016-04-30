/***************************************************************************//**
 * @file		jos.h
 *				This header file provides scheduler related functionalities for
 * 				jos.
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

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef JOS_H
#define JOS_H

/* Includes ------------------------------------------------------------------*/
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

/** @addtogroup jos_module
 *  @{
 */

/* Exported types ------------------------------------------------------------*/

/** @defgroup	jos_exported_types JOS core - Exported types
  * @{
  */

typedef void (*jos_task_function)(void);	/*!< Task function prototype for jos */

typedef struct jos_task {
	jos_task_function task_func;
	int exec_time;
} jos_task_t;								/*!< Stucture that holds task relateed items */

typedef enum {
	JOS_OK = 0,
	JOS_ERROR,
} jos_status;								/*!< jos status codes */

/**
  * @}
  */

/* Exported constants --------------------------------------------------------*/
/* Exported macros -----------------------------------------------------------*/

/** @defgroup	jos_exported_macros JOS core - Exported macros
  * @{
  */

/**
  * @brief  	Defines a new jos task. (Use it source file).
  * @param  	name	Name of task.
  *				func	Task function to be executed.
  *				time	Required execution time of task.
  * @return 	None
  */
#define JOS_TASK_DEF(name, func, time)	jos_task_t jos_task_##name		\
											= { .task_func = func, 		\
											.exec_time = time}

/**
  * @brief  	Declares a new jos task. (Use it header file).
  * @param  	name	Name of task.
  * @return 	None
  */
#define JOS_TASK(name)					extern jos_task_t jos_task_##name

/**
  * @brief  	Adds new task to jos task table/structure (in jos_config.c file).
  * @param  	name	Name of task.
  * @return 	None
  */
#define JOS_TASK_ADD(name)				&jos_task_##name

/**
  * @brief  	Helper macro for writing a jos task function.
  * @param  	name	Name of task.
  * @return 	None
  */
#define JOS_TASK_FUNCTION(func_name)    void func_name(void)

/**
  * @}
  */

/* Exported variables --------------------------------------------------------*/

/** @addtogroup	jos_exported_variables
  * @{
  */

extern jos_task_t * jos_current_task;

/**
  * @}
  */

/* Exported functions --------------------------------------------------------*/

/** @addtogroup	jos_exported_functions
  * @{
  */

extern void jos_init(void);
extern void jos_irq_handler(void);

extern void jos_start(void);
extern void jos_sleep(void);

/**
  * @}
  */

/**
  * @}
  */

#endif /* JOS_H */

/* End of file ---------------------------------------------------------------*/
