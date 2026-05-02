//
// Created by o2-touati on 02/05/2026.
//

#ifndef AC_COURSEWORK_READY_TO_SUBMIT_WAVEFORM_H
#define AC_COURSEWORK_READY_TO_SUBMIT_WAVEFORM_H

#endif //AC_COURSEWORK_READY_TO_SUBMIT_WAVEFORM_H


#ifndef WAVEFORM_H
#define WAVEFORM_H

#include <stddef.h>

typedef struct {
    double timestamp;
    double phase_A_voltage;
    double phase_B_voltage;
    double phase_C_voltage;
    double line_current;
    double frequency;
    double power_factor;
    double thd_percent;
} WaveformSample;
double compute_mean(double *data, size_t n);
double compute_rms(double *data, size_t n);
double compute_peak_to_peak(double *data, size_t n);
int detect_clipping(double *data, size_t n);
int check_tolerance(double rms);
#endif