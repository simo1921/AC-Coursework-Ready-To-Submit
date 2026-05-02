# AC-Coursework-Ready-To-Submit
Power Quality Waveform Analyser
Overview

This project is a C (C99) command-line application that analyses 3-phase power quality waveform data from a CSV file. The program processes real-world electrical measurements and computes key metrics used in power system monitoring.The analyser reads sampled voltage data, performs calculations using pointer-based operations and dynamic memory, and outputs a structured report describing waveform characteristics and compliance.
Program Functionality:
The program performs the following analysis for each phase:
RMS Voltage: Calculates the effective voltage using the RMS formula Used to check compliance with the nominal 230V supply
Peak-to-Peak Voltage: Determines waveform amplitude by subtracting minimum from maximum values
DC Offset (Mean Voltage): Calculates average voltage to detect signal imbalance
Clipping Detection: Flags values exceeding ±324.9V (sensor limit)
Tolerance Check: Verifies RMS voltage is within ±10% of 230V (207V – 253V)

Project Structure
The program is designed using a modular structure, separating responsibilities across files:
main.c
Entry point of the program
Handles command-line arguments
Calls functions from other modules
Manages dynamic memory allocation and cleanup
Does NOT contain analysis logic (kept clean and structured)

waveform.c / waveform.h
Contains all waveform analysis functions:
compute_rms() → calculates RMS voltage
compute_peak_to_peak() → calculates amplitude
compute_mean() → calculates DC offset
detect_clipping() → detects voltage clipping
check_tolerance() → verifies RMS compliance
 Uses pointer arithmetic to process data arrays efficiently

 io.c / io.h
Handles all file operations:
load_csv()
Opens and reads CSV file
Uses malloc() and realloc() to dynamically store data
Parses each row into a WaveformSample struct
write_results()
Outputs formatted analysis results to results.txt

Data Structure
The program uses a struct to represent each sample:
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

 This allows clean storage and access to all waveform data

Memory Management
Dynamic memory allocation using malloc()
Automatic resizing using realloc()
Proper cleanup using free()

Prevents memory leaks and allows flexible dataset size

Build Instructions
Using CLion
Open project folder
Allow CMake to configure
Click Build

Using GCC
gcc -std=c99 main.c waveform.c io.c -o analyser -lm

How to Run
In CLion
Set program arguments:
"C:\path\to\power_quality_log.csv"

Command Line
analyser.exe power_quality_log.csv

Example Output
RMS:
A: 229.81 (OK)
B: 229.81 (OK)
C: 229.81 (OK)

Peak-to-Peak:
A: 650.00
B: 649.86
C: 649.86

DC Offset:
A: -0.00
B: 0.00
C: -0.00

Clipping:
A: Yes
B: Yes
C: Yes

Interpretation of Results
RMS values are close to 230V, indicating normal operation
Peak-to-peak values (~650V) match expected AC waveform amplitude
DC offset is near zero, indicating balanced signal
Clipping detected due to voltage reaching sensor limit

Error Handling
The program includes:
File-not-found detection
Memory allocation failure handling
Command-line argument validation

Repository
GitHub:
(https://github.com/simo1921/AC-Coursework-Ready-To-Submit)

Author
Wassim Touati

Notes
This project demonstrates:
Use of structs and pointers
Dynamic memory management
Modular programming design
File I/O in C

The implementation follows the coursework requirements and reflects practical engineering data analysis.
