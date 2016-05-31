/*******************************************************************************
 * @file        ex_linux_task2_500ms.c
 *              This source file implements a jos task which prints hello at
 *              every 500 seconds.
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
#include "jos.h"
#include "ex_linux_task2_500ms.h"

/* Private constants ---------------------------------------------------------*/
/* Private macros ------------------------------------------------------------*/
/* Private types -------------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
static void task2_func(void);

/* Private variables ---------------------------------------------------------*/
jos_task_t task2;

/* Exported variables --------------------------------------------------------*/
/* Exported functions --------------------------------------------------------*/

void task2_init(void)
{
   /* add task2 to os' task list */
   jos_task_add(&task2, task2_func, 500);
}

/* Private functions ---------------------------------------------------------*/

static void task2_func(void)
{
   printf("Hello from task - 2 !\n");
}

/* End of file ---------------------------------------------------------------*/
