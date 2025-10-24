
#include "mbed.h"
#include "rtos.h"

#include <Arduino_PortentaMachineControl.h>

using namespace mbed;
using namespace rtos;

Thread myThread;
 
void thread_func()
{
    while (true) {
        printf("Hello from thread!\n");
        
        Serial.println("DIGITAL OUT:");
    
        // Set all channels to CLOSED
        MachineControl_DigitalOutputs.writeAll(255);
        Serial.print("All channels are CLOSED for 1 s...");
        delay(1000);

        // Set all channels to OPEN
        MachineControl_DigitalOutputs.writeAll(0);
        Serial.println("now they are OPEN.");
        delay(1000);

        // Toggle each channel for 1 s, one by one

        MachineControl_DigitalOutputs.write(0, HIGH);
        Serial.print("CH0 is CLOSED for 1 s...");
        delay(1000);
        MachineControl_DigitalOutputs.write(0, LOW);
        Serial.println("now is OPEN.");

        MachineControl_DigitalOutputs.write(1, HIGH);
        Serial.print("CH1 is CLOSED for 1 s...");
        delay(1000);
        MachineControl_DigitalOutputs.write(1, LOW);
        Serial.println("now is OPEN.");

        MachineControl_DigitalOutputs.write(2, HIGH);
        Serial.print("CH2 is CLOSED for 1 s...");
        delay(1000);
        MachineControl_DigitalOutputs.write(2, LOW);
        Serial.println("now is OPEN.");

        MachineControl_DigitalOutputs.write(3, HIGH);
        Serial.print("CH3 is CLOSED for 1 s...");
        delay(1000);
        MachineControl_DigitalOutputs.write(3, LOW);
        Serial.println("now is OPEN.");

        MachineControl_DigitalOutputs.write(4, HIGH);
        Serial.print("CH4 is CLOSED for 1 s...");
        delay(1000);
        MachineControl_DigitalOutputs.write(4, LOW);
        Serial.println("now is OPEN.");

        MachineControl_DigitalOutputs.write(5, HIGH);
        Serial.print("CH5 is CLOSED for 1 s...");
        delay(1000);
        MachineControl_DigitalOutputs.write(5, LOW);
        Serial.println("now is OPEN.");

        MachineControl_DigitalOutputs.write(6, HIGH);
        Serial.print("CH6 is CLOSED for 1 s...");
        delay(1000);
        MachineControl_DigitalOutputs.write(6, LOW);
        Serial.println("now is OPEN.");

        MachineControl_DigitalOutputs.write(7, HIGH);
        Serial.print("CH7 is CLOSED for 1 s...");
        delay(1000);
        MachineControl_DigitalOutputs.write(7, LOW);
        Serial.println("now is OPEN.");

        Serial.println();
        delay(1000);
    }
}


void setup() 
{
    Serial.begin(115200);
    
    while (!Serial) {
        ; // wait for serial port to connect.
    }

    //Set over current behavior of all channels to latch mode (true)
    MachineControl_DigitalOutputs.begin(true);

    //At startup set all channels to OPEN
    MachineControl_DigitalOutputs.writeAll(0);

    myThread.start(thread_func);
}

void loop() 
{
    Serial.println("now is OPEN.");

    while (true) {
        Serial.println("now is OPEN.");

        Serial.println();
        delay(1000);
    }
}