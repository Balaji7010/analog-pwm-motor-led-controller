# analog-pwm-motor-led-controller
An embedded C project on PIC16F877A that uses ADC to control PWM output for real-time motor speed regulation and LED dimming. Includes modular driver code for ADC, PWM, and LCD display.
# Analog Voltage Controlled PWM System for Motor Speed Control / LED Dimming

This project implements an embedded system using the PIC16F877A microcontroller to generate a PWM signal whose duty cycle is dynamically controlled by an analog voltage input. The system can be used to control the speed of DC motors or dim the brightness of LEDs.

## Features
- ADC input for analog voltage sensing
- PWM output control based on ADC data
- LCD interface to display real-time ADC and PWM values
- Modular code architecture with separate drivers for ADC, PWM, and LCD

## Technologies Used
- PIC16F877A
- Embedded C
- MPLAB IDE
- Proteus (for simulation)

## Folder Structure
- `main.c` – Application logic
- `adc/` – ADC driver code
- `pwm/` – PWM driver code
- `lcd/` – LCD driver code
- `docs/` – Architecture and documentation
- `schematics/` – Simulation or circuit diagram (if available)

## Author
Balaji Panneerselvam
