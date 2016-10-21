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
 * The C functions that allow TOSSIM-side code to access the SimMoteP
 * component.
 *
 * @author Philip Levis
 * @date   Nov 22 2005
 */


// $Id: sim_gain.h,v 1.5 2010-06-29 22:07:51 scipio Exp $



#ifndef SIM_GAIN_H_INCLUDED
#define SIM_GAIN_H_INCLUDED


#ifdef __cplusplus
extern "C" {
#endif

typedef struct gain_entry {
  int mote;
  double gain;
} gain_entry_t;

void sim_gain_init(void);
void sim_gain_free(void);
  
void sim_gain_add(int src, int dest, double gain);
double sim_gain_value(int src, int dest);
bool sim_gain_connected(int src, int dest);
void sim_gain_remove(int src, int dest);
void sim_gain_set_noise_floor(int node, double mean, double range);
double sim_gain_sample_noise(int node);
double sim_gain_noise_mean(int node);
double sim_gain_noise_range(int node);

void sim_gain_set_sensitivity(double value);
double sim_gain_sensitivity(void);
  
gain_entry_t* sim_gain_begin(int src);
gain_entry_t* sim_gain_end(int src);
inline gain_entry_t* sim_gain_next(gain_entry_t* iter) { return iter - 1; }
  
#ifdef __cplusplus
}
#endif
  
#endif // SIM_GAIN_H_INCLUDED
