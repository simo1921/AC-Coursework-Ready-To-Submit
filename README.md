AC Coursework – Power Quality Waveform Analyser

Overview :
This project is a C (C99) command-line application that analyses 3-phase power quality waveform data from a CSV file. The program processes real-world electrical measurements and computes key metrics used in power system monitoring.
The analyser reads sampled voltage data, performs calculations using pointer-based operations and dynamic memory, and outputs a structured report describing waveform characteristics and compliance.

Program Functionality
The program performs the following analysis for each phase:
RMS Voltage
Calculates the effective voltage and checks compliance with the nominal 230V supply

Peak-to-Peak Voltage
Determines waveform amplitude by subtracting minimum from maximum values

DC Offset (Mean Voltage)
Calculates average voltage to detect signal imbalance

Clipping Detection
Flags values exceeding ±324.9V (sensor limit)

Tolerance Check
Verifies RMS voltage is within ±10% of 230V (207V – 253V)

Project Structure
main.c
Entry point of the program Handles command-line arguments Calls functions from other modules Manages memory allocation and clean upDoes not contain analysis logic waveform.c / waveform.h

Contains waveform analysis functions:
compute_rms() → calculates RMS voltage
compute_peak_to_peak() → calculates amplitude
compute_mean() → calculates DC offset
detect_clipping() → detects voltage clipping
check_tolerance() → verifies RMS compliance
Uses pointer arithmetic to process data efficiently.

io.c / io.h Handles all file operations:
load_csv() :
Opens and reads CSV file.
Uses malloc() and realloc() for dynamic storage.
Parses each row into a WaveformSample struct.

write_results() :
Outputs formatted analysis results to results.txt.


Data Structure:
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
This structure stores all waveform data in a clear and organised way.

Memory Management
Dynamic allocation using malloc().
Resizing using realloc().
Proper cleanup using free().
This ensures efficient memory usage and prevents memory leaks.

Build Instructions :
Using CLion
Open the project folder in CLion.
Allow CMake to configure automatically.
Click Build.

Using GCC
gcc -std=c99 main.c waveform.c io.c -o analyser -lm

How to Run
In CLion

Set program arguments:
"C:\Users\o2-touati\OneDrive - UWE Bristol\AC-Coursework-Ready-To-Submit\power_quality_log.csv"

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
RMS values are close to 230V, indicating normal operation Peak-to-peak values (~650V) match expected waveform amplitude DC offset is near zero, indicating a balanced AC signal Clipping is detected due to voltage reaching sensor limits.

Error Handling
The program includes:
File-not-found detection
Memory allocation failure handling
Command-line argument validation

Repository
GitHub:
https://github.com/simo1921/AC-Coursework-Ready-To-Submit

Author : Ouassim Touati

Notes
This project demonstrates:
Use of structs and pointers.
Dynamic memory management.
Modular programming design.
File I/O in C.

The implementation follows the coursework requirements and reflects practical engineering data analysis.
