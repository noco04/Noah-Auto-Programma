
//pinnummers toewijzen
const int PWM_Pin = 3;
const int ControlPinA = 4;  
const int ControlPinB = 3;
int val=0;
int valdisplay=0;
//motorwaarde instellen, min 0, max 255
int PB = 0;
byte numDigits = 4;

byte digitPins[] = {14, 5, 6, 4};

byte segmentPins[] = {13, 7, 8, 9, 10, 11, 12, 14};

SevSeg sevseg; //Initiate a seven segment controller object



void setup() {

sevseg.begin(COMMON_CATHODE, numDigits, digitPins, segmentPins);

sevseg.setBrightness(50);

  Serial.begin(9600);
  pinMode (0, INPUT_PULLUP); //uit voorzorg
  pinMode (PWM_Pin, OUTPUT);
  pinMode (ControlPinA, OUTPUT);
  pinMode (ControlPinB, OUTPUT);
  pinMode (11,OUTPUT);
  digitalWrite(PWM_Pin, LOW);
  
  
  Serial.println("Rijden starten over 3 seconden");
  digitalWrite (ControlPinA, HIGH);
  digitalWrite (ControlPinB, LOW);
  delay(1000);
  Serial.println("Rijden starten over 2 seconden");
  delay (1000);
  Serial.println("Rijden starten over 1 seconde");
  delay (1000); 
  Serial.println("Rijden starten!");
  delay (500);
}

void loop() {  
    int sensorValue = analogRead(A2);
    Serial.println(sensorValue);
    val = map(sensorValue, 0, 1024, 0, 255);
    analogWrite (11,val);
    analogWrite (PWM_Pin,val);
    valdisplay = map(val, 0, 255, 0, 51);
     sevseg.setNumber(valdisplay, 0);
sevseg.refreshDisplay(); // Must run repeatedly
    delay(5);
}
