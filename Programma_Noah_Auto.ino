// STEM@SCHOOL - Module 1 - Programma A
// indien wagentje te snel rijdt dan moet PB lager gezet worden, of omgekeerd



//pinnummers toewijzen
const int PWM_Pin = 9;
const int ControlPinA = 4;  
const int ControlPinB = 3;
int val=0;
//motorwaarde instellen, min 160, max 255
int PB = 0
;

void setup() {
  Serial.begin(9600);
  pinMode (0, INPUT_PULLUP); //uit voorzorg
  pinMode (PWM_Pin, OUTPUT);
  pinMode (ControlPinA, OUTPUT);
  pinMode (ControlPinB, OUTPUT);
  pinMode (11,OUTPUT);
  digitalWrite(PWM_Pin, LOW);
  
  
// 15 seconden rijden
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
    delay(100);
}
