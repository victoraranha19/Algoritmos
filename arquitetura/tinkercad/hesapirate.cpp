#include <Wire.h>
#include <LiquidCrystal_I2C.h>

#define NOTE_B0  31
#define NOTE_C1  33
#define NOTE_CS1 35
#define NOTE_D1  37
#define NOTE_DS1 39
#define NOTE_E1  41
#define NOTE_F1  44
#define NOTE_FS1 46
#define NOTE_G1  49
#define NOTE_GS1 52
#define NOTE_A1  55
#define NOTE_AS1 58
#define NOTE_B1  62
#define NOTE_C2  65
#define NOTE_CS2 69
#define NOTE_D2  73
#define NOTE_DS2 78
#define NOTE_E2  82
#define NOTE_F2  87
#define NOTE_FS2 93
#define NOTE_G2  98
#define NOTE_GS2 104
#define NOTE_A2  110
#define NOTE_AS2 117
#define NOTE_B2  123
#define NOTE_C3  131
#define NOTE_CS3 139
#define NOTE_D3  147
#define NOTE_DS3 156
#define NOTE_E3  165
#define NOTE_F3  175
#define NOTE_FS3 185
#define NOTE_G3  196
#define NOTE_GS3 208
#define NOTE_A3  220
#define NOTE_AS3 233
#define NOTE_B3  247
#define NOTE_C4  262
#define NOTE_CS4 277
#define NOTE_D4  294
#define NOTE_DS4 311
#define NOTE_E4  330
#define NOTE_F4  349
#define NOTE_FS4 370
#define NOTE_G4  392
#define NOTE_GS4 415
#define NOTE_A4  440
#define NOTE_AS4 466
#define NOTE_B4  494
#define NOTE_C5  523
#define NOTE_CS5 554
#define NOTE_D5  587
#define NOTE_DS5 622
#define NOTE_E5  659
#define NOTE_F5  698
#define NOTE_FS5 740
#define NOTE_G5  784
#define NOTE_GS5 831
#define NOTE_A5  880
#define NOTE_AS5 932
#define NOTE_B5  988
#define NOTE_C6  1047
#define NOTE_CS6 1109
#define NOTE_D6  1175
#define NOTE_DS6 1245
#define NOTE_E6  1319
#define NOTE_F6  1397
#define NOTE_FS6 1480
#define NOTE_G6  1568
#define NOTE_GS6 1661
#define NOTE_A6  1760
#define NOTE_AS6 1865
#define NOTE_B6  1976
#define NOTE_C7  2093
#define NOTE_CS7 2217
#define NOTE_D7  2349
#define NOTE_DS7 2489
#define NOTE_E7  2637
#define NOTE_F7  2794
#define NOTE_FS7 2960
#define NOTE_G7  3136
#define NOTE_GS7 3322
#define NOTE_A7  3520
#define NOTE_AS7 3729
#define NOTE_B7  3951
#define NOTE_C8  4186
#define NOTE_CS8 4435
#define NOTE_D8  4699
#define NOTE_DS8 4978
#define REST      0

// C++ code
//
LiquidCrystal_I2C lcd(32, 16, 2);

int buttonState = 0;
int perfects = 0;
int misses = 0;

// notas da melodia, seguido da duracao.
// 4 significa uma quarta, 8 uma oitava , 16 decimasexta...
// !!numeros negativos sao notas com ponto,
// entao -4 eh uma quarta com ponto, ou seja, uma quarta mais uma oitava!!
int hePirate[] = {
  // He's A Pirate
  // Score available at https://musescore.com/onnikoivisto/scores/3992921
  NOTE_D5,4, NOTE_D5,8, NOTE_D5,4, NOTE_D5,8, NOTE_D5,4, NOTE_D5,8, NOTE_D5,8, NOTE_D5,8, NOTE_D5,8,
  NOTE_D5,4, NOTE_D5,8, NOTE_D5,4, NOTE_D5,8, NOTE_D5,4, NOTE_D5,8, NOTE_D5,8, NOTE_D5,8, NOTE_D5,8,
  NOTE_D5,4, NOTE_D5,8, NOTE_D5,4, NOTE_D5,8, NOTE_D5,4, NOTE_D5,8, NOTE_D5,8, NOTE_A4,8, NOTE_C5,8,
  
  NOTE_D5,4, NOTE_D5,4, NOTE_D5,8, NOTE_E5,8, NOTE_F5,4, NOTE_F5,4, NOTE_F5,8, NOTE_G5,8,
  NOTE_E5,4, NOTE_E5,4, NOTE_D5,8, NOTE_C5,8, NOTE_C5,8, NOTE_D5,4, REST,8, NOTE_A4,8, NOTE_C5,8,
  NOTE_D5,4, NOTE_D5,4, NOTE_D5,8, NOTE_E5,8, NOTE_F5,4, NOTE_F5,4, NOTE_F5,8, NOTE_G5,8,
  NOTE_E5,4, NOTE_E5,4, NOTE_D5,8, NOTE_C5,8, NOTE_D5,4, REST,4, NOTE_A4,8, NOTE_C5,8,
  
  NOTE_D5,4, NOTE_D5,4, NOTE_D5,8, NOTE_F5,8, NOTE_G5,4, NOTE_G5,4, NOTE_G5,8, NOTE_A5,8,
  NOTE_AS5,4, NOTE_AS5,4, NOTE_A5,8, NOTE_G5,8, NOTE_A5,8, NOTE_D5,4, REST,8, NOTE_D5,8, NOTE_E5,8,
  NOTE_F5,4, NOTE_F5,4, NOTE_G5,4, NOTE_A5,8, NOTE_D5,4, REST,8, NOTE_D5,8, NOTE_F5,8,
  NOTE_E5,4, NOTE_E5,4, NOTE_F5,8, NOTE_D5,8, NOTE_E5,4, REST,4, NOTE_A5,8, NOTE_C6,8,
  
  NOTE_D6,4, NOTE_D6,4, NOTE_D6,8, NOTE_E6,8, NOTE_F6,4, NOTE_F6,4, NOTE_F6,8, NOTE_G6,8,
  NOTE_E6,4, NOTE_E6,4, NOTE_D6,8, NOTE_C6,8, NOTE_C6,8, NOTE_D6,4, REST,8, NOTE_A5,8, NOTE_C6,8,
  NOTE_D6,4, NOTE_D6,4, NOTE_D6,8, NOTE_E6,8, NOTE_F6,4, NOTE_F6,4, NOTE_F6,8, NOTE_G6,8,
  NOTE_E6,4, NOTE_E6,4, NOTE_D6,8, NOTE_C6,8, NOTE_D6,4, REST,4, NOTE_A5,8, NOTE_C6,8,
  
  NOTE_D6,4, NOTE_D6,4, NOTE_D6,8, NOTE_F6,8, NOTE_G6,4, NOTE_G6,4, NOTE_G6,8, NOTE_A6,8,
  NOTE_AS6,4, NOTE_AS6,4, NOTE_A6,8, NOTE_G6,8, NOTE_A6,8, NOTE_D6,4, REST,8, NOTE_D6,8, NOTE_E6,8,
  NOTE_F6,4, NOTE_F6,4, NOTE_G6,4, NOTE_A6,8, NOTE_D6,4, REST,8, NOTE_D6,8, NOTE_F6,8,
  NOTE_E6,4, NOTE_E6,4, NOTE_D6,8, NOTE_C6,8, NOTE_D6,4, NOTE_D6,4, NOTE_E6,4,
  NOTE_F6,4, NOTE_F6,4, NOTE_G6,4, NOTE_A6,2, NOTE_F6,8, NOTE_D6,8, NOTE_A5,-2,
  NOTE_AS6,2, NOTE_G6,8, NOTE_D6,8, NOTE_AS5,-2, NOTE_D5,-4, NOTE_D5,-4,
  
  NOTE_CS5,4, REST,4, NOTE_F5,8, NOTE_G5,8,
  NOTE_A5,4, NOTE_A5,4, NOTE_A5,4, NOTE_AS5,8, NOTE_A5,2, REST,8,
  NOTE_G5,4, NOTE_G5,4, NOTE_G5,4, NOTE_G5,8, NOTE_A5,2, REST,8,
  NOTE_A5,4, NOTE_A5,4, NOTE_A5,4, NOTE_AS5,8, NOTE_A5,2, REST,8,
  NOTE_G5,4, NOTE_F5,4, NOTE_E5,4, NOTE_D5,2, NOTE_D5,8, NOTE_E5,8,
  
  NOTE_F5,2, NOTE_G5,8, NOTE_A5,8, NOTE_G5,4, NOTE_F5,4, NOTE_E5,4,
  NOTE_F5,4, NOTE_G5,4, NOTE_A5,4, NOTE_G5,2, NOTE_F5,8, NOTE_G5,8,
  NOTE_A5,2, NOTE_G5,8, NOTE_F5,8, NOTE_E5,4, NOTE_F5,4, NOTE_E5,4,
  NOTE_D5,2, NOTE_E5,8, NOTE_C5,8, NOTE_D5,2, NOTE_D6,8, NOTE_E6,8,
  NOTE_F6,2, NOTE_E6,8, NOTE_F6,8, NOTE_G6,4, NOTE_F6,4, NOTE_G6,4,
  NOTE_A6,4, NOTE_G6,4, NOTE_F6,4, NOTE_D6,2, NOTE_D6,8, NOTE_E6,8,
  NOTE_F6,4, NOTE_G6,4, NOTE_A6,4, NOTE_AS6,4, NOTE_D6,4, NOTE_G6,4,
  NOTE_F6,2, NOTE_G6,8, NOTE_E6,8, NOTE_D6,2, NOTE_E6,8, NOTE_CS6,8,
  
  NOTE_A6,-2, NOTE_AS6,-2, NOTE_A6,4, NOTE_A6,4, NOTE_A6,4, NOTE_A6,8, NOTE_G6,2, REST,8,
  NOTE_G6,-2, NOTE_F6,-2, NOTE_E6,4, NOTE_F6,4, NOTE_E6,4, NOTE_D6,-4, NOTE_D6,8, NOTE_E6,8, NOTE_F6,8,
  NOTE_A6,-4, NOTE_D6,8, NOTE_E6,8, NOTE_F6,8, NOTE_AS6,-4, NOTE_D6,8, NOTE_E6,8, NOTE_F6,8,
  NOTE_A6,4, NOTE_A6,4, NOTE_C7,4, NOTE_A6,8, NOTE_G6,2, REST,8,
  NOTE_G6,-2, NOTE_F6,-2, NOTE_E6,4, NOTE_F6,4, NOTE_E6,4, NOTE_D6,2, NOTE_E6,8, NOTE_C6,8, NOTE_D6,-2,
};

#define tempo 200;
int notes = sizeof(hePirate) / sizeof(hePirate[0]) / 2;
int wholenote = (60000 * 4) / tempo;
int divider = 0, noteDuration = 0;

//acender led
void switchLed(int luzes)
{
  if(luzes==0)
  {
    return;
  }
  
  digitalWrite(9, LOW);
  digitalWrite(10, LOW);
  digitalWrite(11, LOW);
  digitalWrite(12, LOW);
  
  if(luzes>=5)
  {
    digitalWrite(9, HIGH);
    digitalWrite(10, HIGH);
    digitalWrite(11, HIGH);
    digitalWrite(12, HIGH);
    return;
  }
  
  luzes+=8;
  digitalWrite(luzes, HIGH);
}

//tela inicial
void screenGame()
{
  lcd.setCursor(0,0);
  lcd.print("Iniciar musica");
}

//tela game
void pointsGame()
{
  lcd.setCursor(0,0);
  lcd.print("Perfect    Miss");
  lcd.setCursor(0,1);
  lcd.print(perfects);
  lcd.setCursor(11,1);
  lcd.print(misses);
}

//iniciar musica
void iniciar()
{
  pointsGame();
  int thisNote=0;
  for (thisNote = 0; thisNote < notes * 2; thisNote = thisNote + 2) {
  	divider = hePirate[thisNote + 1];
    
    if (divider > 0) {
      noteDuration = (wholenote) / divider;
    } else if (divider < 0) {
      noteDuration = (wholenote) / abs(divider);
      noteDuration *= 1.5;
    }
    
    tone(2, hePirate[thisNote], noteDuration * 0.9);
    delay(noteDuration);
    noTone(2);
  }
}

// setup e loop
void setup()
{
  lcd.init();
  lcd.backlight();
  pinMode(13, INPUT);
  pinMode(12, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(9, OUTPUT);
}

void loop()
{
  screenGame();
  buttonState = digitalRead(13);
  if(buttonState==HIGH) {
    iniciar();
  }
  delay(200);
}