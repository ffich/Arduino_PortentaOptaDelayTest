#include <Arduino.h>
#line 1 "D:\\60_Repositories\\50_Offline\\10_Arduino\\20_Test\\10_GoboService\\MillisTest\\MillisTest.ino"
// Comment if you don't use LT debugger. Please note that debugger introduce a 4% error on millis() and delay().
#define USE_DEBUG

// Select Platform
#define PLATFORM_PORTENTA_H7                              1
#define PLATFORM_OPTA                                     2
#define PLATFORM_TO_USE                                   PLATFORM_PORTENTA_H7

// Select delay type
#define DELAY_WITH_MILLIS                                 1
#define DELAY_WITH_DELAY                                  2
#define DELAY_WITH_MBED_WAIT                              3

#define HOW_TO_DELAY                                      DELAY_WITH_MBED_WAIT

#if (HOW_TO_DELAY == DELAY_WITH_MBED_WAIT) 
 #include "mbed.h"
#endif

#if (PLATFORM_TO_USE == PLATFORM_PORTENTA_H7)
  #define MEASURE_PIN PD_4 
#elif (PLATFORM_TO_USE == PLATFORM_OPTA)
  #define MEASURE_PIN D0
#endif  

#ifdef USE_DEBUG
#include <ThreadDebug.h>
// Define SerialUSB as serial debug port
// use DEBUG_BREAK_IN_SETUP to break the program at setup() entry, waiting for debugger connection.
// use DEBUG_NO_BREAK_IN_SETUP to let the program start normally, debugger can attach later.  
UsbDebugCommInterface  debugComm(&SerialUSB);
ThreadDebug            threadDebug(&debugComm, DEBUG_BREAK_IN_SETUP);
#endif

// Generally, you should use "unsigned long" for variables that hold time
// The value will quickly become too large for an int to store
volatile unsigned long previousMillis = 0; 
volatile unsigned long currentMillis = 0;

// Interval in mS
unsigned long interval = 5000; 

#line 43 "D:\\60_Repositories\\50_Offline\\10_Arduino\\20_Test\\10_GoboService\\MillisTest\\MillisTest.ino"
void setup();
#line 50 "D:\\60_Repositories\\50_Offline\\10_Arduino\\20_Test\\10_GoboService\\MillisTest\\MillisTest.ino"
void loop();
#line 43 "D:\\60_Repositories\\50_Offline\\10_Arduino\\20_Test\\10_GoboService\\MillisTest\\MillisTest.ino"
void setup() {

  // set the digital pin as output:
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(MEASURE_PIN, OUTPUT);
}

void loop() {  
  // Start measure
  digitalWrite(LED_BUILTIN, LOW);
  digitalWrite(MEASURE_PIN, HIGH);

#if (HOW_TO_DELAY == DELAY_WITH_MILLIS)
  currentMillis = millis();
  previousMillis = currentMillis;
#endif  

#if (HOW_TO_DELAY == DELAY_WITH_MILLIS)  
  // Wait for the interval
  while ((currentMillis - previousMillis) <= interval) 
  {
    currentMillis = millis();  
  }
#endif  

#if (HOW_TO_DELAY == DELAY_WITH_DELAY)  
  delay(interval);
#endif  

#if (HOW_TO_DELAY == DELAY_WITH_MBED_WAIT) 
 wait_us(interval*1000);
#endif
  
  // End measure
  digitalWrite(MEASURE_PIN, LOW);
  digitalWrite(LED_BUILTIN, HIGH);  

  while(1);  
}
