/*
  ******************************************************************************
  * @file           : app.h
  * @brief          : Main application header
 ******************************************************************************
 * @attention
 *
 * <h2><center>&copy; Copyright (c) 2019 STMicroelectronics.
 * All rights reserved.</center></h2>
 *
 * This software component is licensed by ST under BSD 3-Clause license,
 * the "License"; You may not use this file except in compliance with the
 * License. You may obtain a copy of the License at:
 *                        opensource.org/licenses/BSD-3-Clause
 *
 ******************************************************************************
 */

#ifndef _APP_H_
#define _APP_H_

#define APP_DEBUG

#ifdef  APP_DEBUG
#define LOG printf
#else
#define LOG //
#endif

int App_Init(void);
int App_Run(void);

#endif /* _APP_H_ */