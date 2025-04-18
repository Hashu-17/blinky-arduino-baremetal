# blkinky-arduino-baremetal
A simple beginner's guide to starting with bare-metal programming. 

## What ?
Bare-metal programming is basically writing code without using any operating system or abstraction layers such as libraries. This approach allows developers to control hardware directlty.

It offers unparalleled control, enabling the optimization of system resources and the precise execution of tasks. Without the abstraction provided by operating systems, Bare Metal Programming puts developers in the driver’s seat, offering a level of efficiency and determinism that can be transformative for certain applications. 

## The Blinky Example -

The code itself can be written on a CLI (Command Line Interface - a text-based interface where you can input commands that interact with a computer's operating system) . For now, it can be written on the Arduino IDE. The C code will not use any Arduino libraries and will be very basic.

In this example we will write a simple code to blink 3 LEDs in a sequence one after the other. We need to set PB4, PB7 and PB3 (Refer to the [Arduino Pinout]( https://docs.arduino.cc/resources/pinouts/A000066-full-pinout.pdf ) ) as outputs to which 3 LEDs are connected. This code has two blocks :

1. The Delay Function
```
void delay(uint32_t count) {
  for (uint32_t i=0; i <count; i++)
  {
    __asm__("nop");
  }
}
```

A simple for loop function which does not return anything (declared as void), and has a parameter 'count' (which is an unsigned integer 32 bits long) and executes ```  ___asm___("nop"); ``` in the loop. This will be sed to keep the LED ON for some time when the delay() function is called.


2. The Main Function
```
int main(void){
DDRB|= (1<< PB4);//or PORTB=16
DDRB|= (1<< PB3);//or PORTB=8
DDRD|= (1<< PD7);//or PORTB=128
while (1){
  PORTB^=(1<<PB4);
  delay(1000000);
   PORTB^=(1<<PB3);
  delay(1000000);
   PORTD^=(1<<PD7);
  delay(1000000);
}
}
```
The first step is to understand how the PORT B register works. Refer to the [Arduino Port Manipulation](https://docs.arduino.cc/retired/hacking/software/PortManipulation/) documentation to get a clear understanding of the PORTB register and DDRB registers. 
DDR : A data direction register (DDR) in a microcontroller or digital system configures each individual I/O pin to be either an input or an output. It essentially acts as a switch, determining whether data flows into or out of a specific port pin. A "1" in the DDR typically designates the corresponding pin as an input, while a "0" designates it as an output. 
This [article](https://electronoobs.com/eng_arduino_tut12.php) will help you get a deeper understanding.

So, it can be understood now that the Data Direction Register B or DDRB can set the PORT B pins' direction as input or output. 
Note: The Port B and DDRB registers can be both read or written.
The first three statements do just that.
```DDRB|= (1<< PB4);//or PORTB=16 ```
will left shift a 1 and set bit 4 of the register as output. Alternatively, we can control all the 8 bits at once by writing ```DDRB=16``` or ```DDRB|=B00010000;``` both will set bit 4 of the DDRB register as Output.

Next, we move on to the while loop.```PORTB^=(1<<PB4);``` will set bit 4 of the PORTB register as HIGH. The delay function is called in the next line.
If you've referred to the official [Arduino Pinout](https://docs.arduino.cc/resources/pinouts/A000066-full-pinout.pdf ), you'll see that PORTB bit 4 or PB4 in short refers to Digital Pin 12 of the Arduino Uno board. Therefore , 

