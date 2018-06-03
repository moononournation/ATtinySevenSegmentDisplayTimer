/* 7 segment layout
      A
    F   B
      G
    E   C
      D   H
*/
#define SEG_A      B11111101 // PA1
#define SEG_B      B11111110 // PA0
#define SEG_C      B11011111 // PA5
#define SEG_D      B10111111 // PA6
#define SEG_E      B01111111 // PA7
#define SEG_F      B11111011 // PA2
#define SEG_G      B11110111 // PA3
#define SEG_H      B11101111 // PA4

#define DIGIT_1    B01000000 // PB6
#define DIGIT_2    B00100000 // PB5
#define DIGIT_3    B00010000 // PB4
#define DIGIT_4    B00001000 // PB3

#define ALL_HIGH   B11111111

uint8_t digit[] = {
  SEG_A & SEG_B & SEG_C & SEG_D & SEG_E & SEG_F, // 0
  SEG_B & SEG_C, // 1
  SEG_A & SEG_B & SEG_D & SEG_E & SEG_G, // 2
  SEG_A & SEG_B & SEG_C & SEG_D & SEG_G, // 3
  SEG_B & SEG_C & SEG_F & SEG_G, // 4
  SEG_A & SEG_C & SEG_D & SEG_F & SEG_G, // 5
  SEG_A & SEG_C & SEG_D & SEG_E & SEG_F & SEG_G, // 6
  SEG_A & SEG_B & SEG_C, // 7
  SEG_A & SEG_B & SEG_C & SEG_D & SEG_E & SEG_F & SEG_G, // 8
  SEG_A & SEG_B & SEG_C & SEG_D & SEG_F & SEG_G  // 9
};

void setup() {
  DDRA = ALL_HIGH; // set port A all pins as output
  DDRB = B01111001; // set common anode pins as output
}

void loop() {
  long tmp = millis() / 1000; // number of seconds
  PORTA = ALL_HIGH; // reset PORT A all pins to HIGH
  PORTB = (tmp % 2) | DIGIT_4; // switch to first digit
  PORTA = digit[tmp % 10]; // show 0-9
  delay(1);

  tmp = tmp / 10; // number of ten seconds
  PORTA = ALL_HIGH; // reset PORT A all pins to HIGH
  PORTB = DIGIT_3; // switch to second digit
  PORTA = digit[tmp % 6]; // show 0-5
  delay(1);

  tmp = tmp / 6; // number of minutes
  PORTA = ALL_HIGH; // reset PORT A all pins to HIGH
  PORTB = DIGIT_2; // switch to third digit
  PORTA = digit[tmp % 10]; // show 0-9
  delay(1);

  tmp = tmp / 10; // number of 10 minutes
  PORTA = ALL_HIGH; // reset PORT A all pins to HIGH
  PORTB = DIGIT_1; // switch to forth digit
  PORTA = digit[tmp % 10]; // show 0-9
  delay(1);
}

