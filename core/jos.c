/***************************************************************************//**
 * @file        jos.c
 *              This source file provides scheduler related functionalities for
 *              jos.
 *
 * @author      Jaydeep Dhrangdhariya (jaydeep.gajjar90@gmail.com)
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
#include <string.h>

#include "jos.h"
#include "jos_port.h"
#include "jos_config.h"

/** @defgroup   jos_module JOS core
  * @{
  */

/* Private constants ---------------------------------------------------------*/
/* Private macros ------------------------------------------------------------*/
/* Private types -------------------------------------------------------------*/
/** @defgroup   jos_private_types   JOS Core - Private variables
  * @{
  */

/**
  * This is a task list/table that holds all the tasks that needs to be
  * executed by jos.
  */
static jos_task_t * jos_tasks[JOS_MAX_TASKS];

/**
  * @}
  */

/* Private function prototypes -----------------------------------------------*/

/** @addtogroup jos_private_functions
  * @{
  */

static void jos_execute(void);

/**
  * @}
  */

/* Private variables ---------------------------------------------------------*/

/** @defgroup   jos_private_variables JOS core - Private variables
  * @{
  */

static volatile int jos_tick = 0;      /*!< Holds scheduler tick of jos */

static uint32_t jos_max_tick = 0;      /*!< Holds max execution time of all jos tasks */
static uint32_t jos_total_tasks = 0;   /*!< Holds total number of jos tasks */

/**
  * @}
  */

/* Exported variables --------------------------------------------------------*/

/** @defgroup   jos_exported_variables JOS core - Exported variables
  * @{
  */

jos_task_t * jos_current_task;      /*!< Holds pointer to the task currently in execution */

/**
  * @}
  */

/* Exported functions --------------------------------------------------------*/

/** @defgroup   jos_exported_functions JOS core - Exported functions
  * @{
  */

/**
  * @brief      Initializes timer for jos scheduler.
  * @param      None
  * @return     None
  */
void jos_init(void)
{
   /* Clear variables */
   jos_tick = 0;
   jos_max_tick = 0;

   /* Do port specific initialization */
   jos_port_init();
}

/**
  * @brief      Increments tick and calls execution of task functions.
  * @param      None
  * @return     None
  */
void jos_irq_handler(void)
{
   /* Increment scheduler tick */
   jos_tick++;

   /* Execute all the tasks */
   jos_execute();

   /* Clear scheduler tick if it is incremented upto maximum tick */
   if (jos_tick > jos_max_tick) {
      jos_tick = 0;
   }
}

/**
  * @brief      Starts jos scheduler.
  * @param      None
  * @return     None
  */
void jos_start(void)
{
   int i;

   /* Find maximum tick time from all tasks */
   jos_max_tick = 0;

   for (i = 0; i < jos_total_tasks; i++) {
      if (jos_tasks[i]->exec_time > jos_max_tick) {
         jos_max_tick = jos_tasks[i]->exec_time;
      }
   }

   /* Call port specific start function */
   jos_port_start();
}

/**
  * @brief      Sleep for sometime to save power.
  * @param      None
  * @return     None
  */
void jos_sleep(void)
{
   /* Just call port specific sleep function */
   jos_port_sleep();
}

/**
  * @brief      Add new task to task list.
  * @param      task        task pointer which needs to be added in list
  *             func        task function to be called
  *             time        time interval for callback
  * @return     JOS_OK      if task is added sucessfully
  *             JOS_ERROR   error occured
  */
jos_status jos_task_add(const jos_task_t * task, jos_task_function func, int time)
{
   jos_status status = JOS_ERROR;

   if (jos_total_tasks < JOS_MAX_TASKS) {
      jos_tasks[jos_total_tasks] = task;
      jos_tasks[jos_total_tasks]->task_func = func;
      jos_tasks[jos_total_tasks]->exec_time = time;
      jos_total_tasks++;

      status = JOS_OK;
   }

   return status;
}

/**
  * @}
  */

/* Private functions ---------------------------------------------------------*/

/** @defgroup   jos_private_functions JOS core - Private functions
  * @{
  */

/**
  * @brief      Execute all tasks one by one.
  * @param      None
  * @return     None
  */
static void jos_execute(void)
{
   int i;

   /* Go though each task */
   for (i = 0; i < jos_total_tasks; i++) {
      /* Check if it is right time to execute task function */
      if (jos_tick != 0 && (jos_tick % jos_tasks[i]->exec_time) == 0) {
         jos_current_task = jos_tasks[i];
         jos_tasks[i]->task_func();
      }
   }
}

/**
  * @}
  */

/**
  * @}
  */

/* End of file ---------------------------------------------------------------*/
