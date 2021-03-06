/**
 * Copyright (c) 2016, Jack Mo (mobangjack@foxmail.com).
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef __EST_H__
#define __EST_H__

#ifdef __cplusplus
extern "C" {
#endif

// Estimator
#include "gauss.h"
#include "kalman.h"
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <float.h>

typedef struct
{
	Gauss_t* gauss;     // gauss processor
	Kalman_t* kalman;   // kalman filter
	float error;        // error
	float value;        // estimated value
	float delta;        // delta value
}Est_t; // Estimator

Est_t* Est_Create(uint32_t gaussN, float kalmanQ);
void Est_Proc(Est_t* est, float v);
void Est_Reset(Est_t* est);
void Est_Destroy(Est_t* est);

#ifdef __cplusplus
}
#endif

#endif
