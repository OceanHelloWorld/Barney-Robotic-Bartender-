#include <LiquidCrystal.h>
#define NOTE_G3  196

#define NOTE_A3  220

#define NOTE_B3  247

#define NOTE_C4  262

// notes in the melody:
int melody[] = {
  NOTE_C4, NOTE_G3, NOTE_G3, NOTE_A3, NOTE_G3, 0, NOTE_B3, NOTE_C4
};

// note durations: 4 = quarter note, 8 = eighth note, etc.:
int noteDurations[] = {
  4, 8, 8, 4, 4, 4, 4, 4
};


const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

const int button1 = 6;
const int button2 = 7;
const int button3 = 10;
const int button4 = 9;

// all buttons set to LOW
int buttonState1 = 0;
int buttonState2 = 0;
int buttonState3 = 0;
int buttonState4 = 0;

void setup()
{
  pinMode(button1, INPUT);
  pinMode(button2, INPUT);
  pinMode(button3, INPUT);
  pinMode(button4, INPUT);
  // begin serial for readings
  Serial.begin(9600);
}

void loop() {  
  buttonState1 = digitalRead(button1);
  buttonState2 = digitalRead(button2);
  buttonState3 = digitalRead(button3);
  buttonState4 = digitalRead(button4);

  lcd.print("Pick your drink");
  delay(3000);
  lcd.clear();
  lcd.print("1. Gin and Tonic");
  delay(2000);
  lcd.clear();
  lcd.print("3. Margarita");
  delay(2000);
  lcd.clear();
  if ((buttonState1 == HIGH) || (buttonState2 == HIGH) || (buttonState3 == HIGH) || (buttonState4 == HIGH)) {
    Serial.println("pressed 1");

    delay(1500);
    lcd.print("Please Wait!");
    delay(2000);
    lcd.clear();
    lcd.print("       5");  
    delay(1400);
    lcd.clear();
    lcd.print("       4");
    delay(1400);
    lcd.clear();
    lcd.print("       3");
    delay(1400);
    lcd.clear();
    lcd.print("       2");
    delay(1400);
    lcd.clear();
    lcd.print("       1");
    delay(1400);
    lcd.clear();
    lcd.print("       0");
    delay(1400);
    lcd.clear();
    for (int thisNote = 0; thisNote < 8; thisNote++) {

      // to calculate the note duration, take one second divided by the note type.
      //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
      int noteDuration = 1000 / noteDurations[thisNote];
      tone(8, melody[thisNote], noteDuration);
  
      // to distinguish the notes, set a minimum time between them.
      // the note's duration + 30% seems to work well:
      int pauseBetweenNotes = noteDuration * 1.30;
      delay(pauseBetweenNotes);
      // stop the tone playing:
      noTone(8);
    }
    lcd.print("Enjoy your drink!");
    delay(15000);
    lcd.clear();
    
  } else {
    Serial.println("Try again please");
    delay(2000);
  }
  
  
}
