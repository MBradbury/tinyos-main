/*
 * Copyright (c) 2005 Stanford University. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * - Redistributions of source code must retain the above copyright
 *   notice, this list of conditions and the following disclaimer.
 * - Redistributions in binary form must reproduce the above copyright
 *   notice, this list of conditions and the following disclaimer in the
 *   documentation and/or other materials provided with the
 *   distribution.
 * - Neither the name of the copyright holder nor the names of
 *   its contributors may be used to endorse or promote products derived
 *   from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
 * FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL
 * THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT,
 * INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,
 * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED
 * OF THE POSSIBILITY OF SUCH DAMAGE.
 */

/**
 * Implementation of all of the basic TOSSIM primitives and utility
 * functions.
 *
 * @author Philip Levis
 * @date   Nov 22 2005
 */

// $Id: sim_tossim.h,v 1.5 2010-06-29 22:07:51 scipio Exp $

#ifndef SIM_TOSSIM_H_INCLUDED
#define SIM_TOSSIM_H_INCLUDED

#include <stdio.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef long long int sim_time_t;
  
void sim_init(void);
void sim_end(void) __attribute__ ((cold));

void sim_random_seed(int seed);
int sim_random(void);
  
sim_time_t sim_time(void);
void sim_set_time(sim_time_t time);
sim_time_t sim_ticks_per_sec(void);
  
unsigned long sim_node(void);
void sim_set_node(unsigned long node);

int sim_print_time(char* buf, int bufLen, sim_time_t time);
int sim_print_now(char* buf, int bufLen);
const char* sim_time_string(void);

void sim_add_channel(const char* channel, FILE* file);
bool sim_remove_channel(const char* channel, FILE* file);
void sim_add_callback(const char* channel, void (*handle)(void* data, const char* line, size_t line_length), void* data);
  
bool sim_run_next_event(void) __attribute__ ((hot));

void sim_register_event(sim_time_t execution_time, void (*handle)(void*), void* data);

#ifdef __cplusplus
}
#endif
  
#endif // SIM_TOSSIM_H_INCLUDED
