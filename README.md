# Arduino_PortentaOptaDelayTest
A simple sketch to test the precision of some Arduino delay/timing services. The version for Portenta H7 can also be tested with Lauterbach T32 debugger, using the Arduino Pro Free debugger and the runtime feature.

# ⚡ Arduino PortentaOpta Delay Test

This repository contains an Arduino sketch designed to test and compare different delay and timing methods on the Portenta platform, with elapsed time measured externally.

## 📝 Overview

The sketch tests three common delay techniques on the Portenta:

- Blocking `delay()` (milliseconds)
- Non-blocking timing using `millis()`
- Blocking microsecond delay using `wait_us()` (from Mbed OS API)

The actual performance of the delay can be obtained by using:

- The free **Lauterbach for Arduino debugger's runtime feature**, or
- By observing output pins with an **oscilloscope**

This approach allows precise and independent timing measurements for comparison.

## 🚀 Features

- ⏳ Tests blocking vs non-blocking delay methods.
- 🔧 Uses `delay()`, `millis()`, and `wait_us()`.
- 🖥️ Pin toggling output to visualize timing externally.
- 🖥️ Enables precise elapsed time measurement with Lauterbach debugger
- 🛠️ Useful for understanding delay method accuracy on Arduino Portenta.

## ⚙️ Usage

1. Open `MillisTest.ino` in Arduino IDE.
2. Connect your Arduino Portenta board.
3. Upload the sketch.
4. Connect Lauterbach debugger or oscilloscope to the indicated pins.
5. Use Lauterbach’s runtime feature or oscilloscope waveform to measure elapsed time during each delay method.

## 🔍 Code Explanation

- Performs blocking delay with `delay()` and `wait_us()`.
- Uses `millis()` for non-blocking timing checks.
- Toggles GPIO pins to mark timing windows.
- Elapsed time is measured externally for accurate benchmarking.

## 📄 License

This code is released under the MIT License.



