#include <avr/io.h>
#include <avr/delay.h>

int main(){
  
  DDRB=0b10000000;
  DDRA=0b00000010;
  

while(1){
  PORTB=0b00000000;
  PORTA=0b00000010;

  _delay_ms(1000);

  PORTB=0b10000000;
  PORTA=0b00000000;

  _delay_ms(1000);
}

/* FOr different blinking times

static uint16_t scale = 0

void blinkOtherFrequency(){
  scale ++;
  if(scale >= 2){
    scale = 0;
    PORTA ^= 1<<1;
  }
}

int main(){
  DDRB |= 1<<7;
  DDRA |= 1<<1;
  PORTA |= 1<<1

  while(){
    _delay_ms(200)
    PORTB ^= 1<<7

    blinkOtherFrequency();
  }
}




*/
}
