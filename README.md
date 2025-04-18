# blkinky-arduino-baremetal
A simple beginner's guide to starting with bare-metal programming. 

## What ?
Bare-metal programming is basically writing code without using any operating system or abstraction layers such as libraries. This approach allows developers to control hardware directlty.

It offers unparalleled control, enabling the optimization of system resources and the precise execution of tasks. Without the abstraction provided by operating systems, Bare Metal Programming puts developers in the driver’s seat, offering a level of efficiency and determinism that can be transformative for certain applications. 

## The Blinky Example -

The code itself can be written on a CLI (Command Line Interface - a text-based interface where you can input commands that interact with a computer's operating system) . For now, it can be written on the Arduino IDE. The C code will not use any Arduino libraries and will be very basic.

In this example we will write a simple code to blink 3 LEDs in a sequence one after the other. This code has two blocks :

1. The Delay Function
```
void delay(uint32_t count) {
  for (uint32_t i=0; i <count; i++)
  {
    __asm__("nop");
  }
}
```

A simple for loop function which does not return anything, and has a parameter 'count' (which is an unsigned integer 32 bits long) and executes ```  ___asm___("nop"); ``` in the loop.


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
