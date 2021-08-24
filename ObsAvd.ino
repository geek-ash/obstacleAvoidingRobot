#define trig_pin A1
#define echo_pin A2  // defines trig and echo pin

long duration;
int distance;
int motorpin1=5;
int motorpin2=6;
int motorpin3=10;
int motorpin4=9;

void setup() {
  // put your setup code here, to run 
  pinMode(motorpin1,OUTPUT);
  pinMode(motorpin2,OUTPUT);
  pinMode(motorpin3,OUTPUT);
  pinMode(motorpin4,OUTPUT);
    pinMode(trig_pin,OUTPUT);
  pinMode(echo_pin,INPUT);
  Serial.begin(9600);
  
}

void loop() {
    digitalWrite(trig_pin,LOW);
  delayMicroseconds(2);
  digitalWrite(trig_pin,HIGH);
  delayMicroseconds(10); //sets trig pin high for 10 microseconds
  digitalWrite(trig_pin,LOW);

  duration=pulseIn(echo_pin,HIGH); //calculates the duration,returns the sound travel time in microseconds

  distance=duration*0.034/2;
  Serial.println(distance);
  // put your main code here, to run repeatedlint  
  if(distance>20)
  {
forward();
}
else
{
  Rstop();
}
}
  void forward()
  {
  digitalWrite(motorpin1,HIGH);
  digitalWrite(motorpin2,LOW);
  digitalWrite(motorpin3,HIGH);
  digitalWrite(motorpin4,LOW);
  delay(10);
}
void Rstop()
{
  delay(1000);
  digitalWrite(motorpin1,LOW);
  digitalWrite(motorpin2,LOW);
  digitalWrite(motorpin3,LOW);
  digitalWrite(motorpin4,LOW);
}
