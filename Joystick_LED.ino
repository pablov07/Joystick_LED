// define pins 
const int LRpin = A0;
const int UDpin = A1;

const int Rpin = 11;
const int Ypin = 10;
const int Gpin = 8;
const int Bpin = 9;

//variables for analog reading 
int LR;
int UD;

int LR_neutral;
int UD_neutral;

//LED brightness
int R;
int Y;
int G;
int B;

//define deadzone of joystick 
const int deadzone = 10;

void setup() {
  //Intialize serial communication
  Serial.begin(9600);

  //neutral reading when program starts 
  LR_neutral = analogRead(LRpin);
  UD_neutral = analogRead(UDpin);
}

void loop() {
  //reads analog pins 
  LR = analogRead(LRpin);
  UD = analogRead(UDpin);

  if (UD>=UD_neutral+deadzone) { 
    R = 0; //red LED off
    B = map(UD, UD_neutral, 1023, 0, 255); //blue LED on
  }
  else if (UD<=UD_neutral-deadzone) {
    B = 0; //blue LED off
    R = map(UD, UD_neutral, 0, 0, 255); //red LED on
  }
  else { //both blue and red LEDs off
    R = 0;
    B = 0;
  }
  
  if (LR>=LR_neutral+deadzone) {
    Y = 0; //yellow LED off
    G = map(LR, LR_neutral, 1023, 0 , 255); //green LED on
  }
  else if (LR<=LR_neutral-deadzone) {
    G = 0; //greeb LED off 
    Y = map(LR, LR_neutral, 0, 0, 255); //yellow LED on
  }
  else { //both yellow and green LEDs off
    G = 0;
    Y = 0;
  }
   
   analogWrite(Rpin, R);
   analogWrite(Ypin, Y);
   analogWrite(Gpin, G);
   analogWrite(Bpin, B);
}
