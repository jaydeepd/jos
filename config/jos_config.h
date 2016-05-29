/***************************************************************************//**
 * @file		jos_config.h
 *                      This header file provides configuration related options of jos.
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
#ifndef JOS_CONFIG_H
#define JOS_CONFIG_H

/* Includes ------------------------------------------------------------------*/

/** @defgroup	jos_config_module
  * @{
  */

/* Exported types ------------------------------------------------------------*/
/* Exported constants --------------------------------------------------------*/
/* Exported macros -----------------------------------------------------------*/
/* Exported variables --------------------------------------------------------*/

/** @defgroup	jos_config_exported_variables JOS configuration - Exported variables
  * @{
  */

/**
  *	This is a task list/table that holds all the tasks that needs to be
  * executed by jos.
  */
extern jos_task_t * jos_tasks[];

/**
  * @}
  */

/* Exported functions --------------------------------------------------------*/

/** @addtogroup	jos_config_exported_functions
  * @{
  */
int jos_config_get_total_tasks(void);

/**
  * @}
  */

/**
  * @}
  */

#endif /* JOS_CONFIG_H */

/* End of file ---------------------------------------------------------------*/
