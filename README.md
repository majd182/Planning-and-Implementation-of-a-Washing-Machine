# Planning-and-Implementation-of-a-Washing-Machine
Washing Machine Project: Design and Implementation
Project Overview
This project involved the design and implementation of an automated washing machine system. The goal was to create a system that can execute two different washing programs (for white and colored clothes) based on user selection, providing real-time feedback on the remaining wash time. The system ensures safe operation by verifying door closure and water availability before starting any cycle. 


Key Features
Two Washing Programs: Designed for white and colored clothes. 
Automated Cycle Control: Manages the entire washing process including motor delay, washing with soap, water drainage, soap-free rinsing, final drainage, and spinning. 

Safety Interlocks: Requires the power switch to be ON, door closed, and sufficient water level before starting the washing process. 


User Feedback: Displays the remaining washing time on a 7-segment display. 

End-of-Cycle Notification: A buzzer sounds three times upon completion of the wash cycle. 

Time-Based Operation: The system's timing is precisely controlled using hardware components and C code. 



Technical Specifications
Hardware Implementation
The system's control logic was implemented using a combination of discrete logic ICs and an Arduino microcontroller. 



Microcontroller: Arduino board was used for overall system control and software logic. 


Timing Control:
CD4538BC Dual Precision Monostable: Used as retriggerable/non-retriggerable monostable multivibrators to control pulse width (τ=RC) and define specific delays and timings for each washing stage. 
LM555 Timer: Configured in astable operation to generate a periodic square wave for the buzzer at the end of the washing cycle, providing three beeps. 

Counter and Display:
74LS190D U/D Counter: A 4-bit binary up/down counter used to implement the system's clock and display the remaining time in a countdown manner. 




74LS47D BCD to 7-Segment Decoder: Decodes the 4-bit BCD output from the counter to drive the 7-segment display. 
7 Segment Display TDSG5150: Single-digit 7-segment displays used to visualize the countdown time. 
Logic Gates:
7432N OR Gates: Used for various logical conditions within the circuit, including controlling the system's state based on input conditions. 

7408J AND Gates: Used for logical conjunctions, similar to OR gates but with different truth tables. 



Other Components: Resistors, capacitors, switches (for power, door lock, water level, program selection), LEDs (for status indication), and a buzzer. 


Software Implementation
The software (firmware) was developed in C language using the Arduino IDE environment, and simulated in Tinkercad. 


Programming Language: C. 

Development Environment: Tinkercad for circuit building and simulation. 
Control Flow: The setup() function initializes I/O pins, while the loop() function continuously monitors user input and system conditions to execute the washing cycle. 
Washing Programs Logic:
White Clothes Program: Total duration of 15 seconds. Includes phases for washing with soap, water drainage, soap-free rinsing, and final drainage/spinning. 




Colored Clothes Program: Total duration of 19 seconds. Includes phases for washing with soap, water drainage, soap-free rinsing, and final drainage/spinning. 




Timing Control in Software: delay() functions are used to control the duration of each washing phase. 
