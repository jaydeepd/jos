/***************************************************************************//**
 * @file		jos_port_linux.c
 * 				This source file provides jos port for a GNU/linux system.
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
#include <unistd.h>
#include <signal.h>
#include <time.h>

#include "jos.h"
#include "jos_port.h"

/** @defgroup   jos_port_linux_module JOS Linux port
  * @{
  */

/* Private constants ---------------------------------------------------------*/

/** @defgroup   jos_port_linux_private_constants JOS Linux port - Private constants
  * @{
  */

#define TIMER_CLOCKID	CLOCK_REALTIME		/*!< Clock source for timer */
#define TIMER_SIG 		SIGUSR1				/*!< Timer signal */
#define TIMER_TIME		1000000				/*!< 1 ms delay/tick time */

/**
  * @}
  */

/* Private macros ------------------------------------------------------------*/
/* Private types -------------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/

/** @addtogroup   jos_port_linux_private_functions
  * @{
  */

static void timer_irq_handler(int sig, siginfo_t *si, void *uc);

/**
  * @}
  */

/* Private variables ---------------------------------------------------------*/

/** @defgroup   jos_port_linux_private_variables JOS Linux port - Private variables
  * @{
  */

static timer_t timerid;

/**
  * @}
  */

/* Exported variables --------------------------------------------------------*/
/* Exported functions --------------------------------------------------------*/

/** @defgroup   jos_port_linux_exported_functions JOS Linux port - Exported functions
  * @{
  */

/**
  * @brief  	Initializes tick timer for scheduler.
  * @param  	None
  * @return 	None
  */
void jos_port_init(void)
{
	struct sigevent sev;
    struct sigaction sa;

	/* Create signal action for timer interrupt */
    sa.sa_flags = SA_SIGINFO;
    sa.sa_sigaction = timer_irq_handler;
    sigemptyset(&sa.sa_mask);
    sigaction(TIMER_SIG, &sa, NULL);

	/* Create timer event for tick timer */
    sev.sigev_notify = SIGEV_SIGNAL;
    sev.sigev_signo = TIMER_SIG;
    sev.sigev_value.sival_ptr = &timerid;
    timer_create(TIMER_CLOCKID, &sev, &timerid);
}

/**
  * @brief  	Starts jos timer.
  * @param  	None
  * @return 	None
  */
void jos_port_start(void)
{
	struct itimerspec its;
	
	/* Set time and start the timer */
    its.it_value.tv_sec = 0;
    its.it_value.tv_nsec = TIMER_TIME;
    its.it_interval.tv_sec = its.it_value.tv_sec;
    its.it_interval.tv_nsec = its.it_value.tv_nsec;
	
    timer_settime(timerid, 0, &its, NULL);
}

/**
  * @brief  	sleep function for jos scheduler.
  * @param  	None
  * @return 	None
  */
void jos_port_sleep(void)
{
	/* Sleep for some time */
    sleep(1);
}

/**
  * @}
  */

/* Private functions ---------------------------------------------------------*/

/** @defgroup   jos_port_linux_private_functions JOS Linux port - Private functions
  * @{
  */

/**
  * @brief  	IRQ handler for timer on Linux port.
  * @param  	sig		Signal number
  * 			si		Signal info structure
  * 			uc		Todo
  * @return 	None
  */
static void timer_irq_handler(int sig, siginfo_t *si, void *uc)
{
	/* Call for jos irq handler to execute tasks */
    if(si->si_value.sival_ptr == &timerid) {
        jos_irq_handler();
    }
}

/**
  * @}
  */

/**
  * @}
  */

/* End of file ---------------------------------------------------------------*/
