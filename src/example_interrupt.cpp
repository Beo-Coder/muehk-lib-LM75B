// Copyright (c) 2023. Leonhard Baschang

#include "LM75B.h"
#include "mbed.h"


void osIsr();

LM75B lm75_interrupt(PB_9, PB_8, 0b00000000, PC_8, &osIsr);
DigitalOut led(LED1);


void osIsr() {
    led = !led;
}


int main_interrupt_example() {
    led = 0;
    lm75_interrupt.setTemperatureOS(26);
    lm75_interrupt.setTemperatureHYST(23);
    while (true) {

    }

    return 1;
}
