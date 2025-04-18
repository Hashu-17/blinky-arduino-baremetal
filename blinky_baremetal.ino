#define LED_PIN PB4

void delay(uint32_t count) {
  for (uint32_t i=0; i <count; i++)
  {
    __asm__("nop");
  }
}

int main(void){
DDRB|= (1<< PB4);//or we can set PORTB=16
DDRB|= (1<< PB3);//or we can set PORTB=8
DDRD|= (1<< PD7);//or we can set PORTB=128
while (1){
  PORTB^=(1<<PB4);
  delay(1000000);
   PORTB^=(1<<PB3);
  delay(1000000);
   PORTD^=(1<<PD7);
  delay(1000000);
}

}

