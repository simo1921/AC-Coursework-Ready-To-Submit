//
// Created by o2-touati on 02/05/2026.
//

#ifndef AC_COURSEWORK_READY_TO_SUBMIT_IO_H
#define AC_COURSEWORK_READY_TO_SUBMIT_IO_H

#endif //AC_COURSEWORK_READY_TO_SUBMIT_IO_H
#ifndef IO_H
#define IO_H // 1
#include "waveform.h" // 2
WaveformSample* load_csv(const char *filename, size_t *count); // 3
void write_results(const char *filename,  // 4
                   double rmsA, double rmsB, double rmsC, // 5
                   double p2pA, double p2pB, double p2pC, // 6
                   double dcA, double dcB, double dcC, // 7
                   int clipA, int clipB, int clipC); // 8
#endif // 9