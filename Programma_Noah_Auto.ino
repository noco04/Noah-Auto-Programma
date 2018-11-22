
//pinnummers toewijzen
const int PWM_Pin = 3;
const int ControlPinA = 1;  
const int ControlPinB = 2;
int val=0;
//motorwaarde instellen, min 0, max 255
int PB = 0;




void setup() {



  Serial.begin(9600);
  pinMode (0, INPUT_PULLUP); //uit voorzorg
  pinMode (PWM_Pin, OUTPUT);
  pinMode (ControlPinA, OUTPUT);
  pinMode (ControlPinB, OUTPUT);
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
    analogWrite (PWM_Pin,val);
    delay(5);
}
