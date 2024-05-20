const int switchPin = 2; 
int count = 0;
int previous = 0;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(12,INPUT_PULLUP);

  pinMode(switchPin,INPUT_PULLUP);

}

void loop() {
  // put your main code here, to run repeatedly:
  if(digitalRead(12)==LOW)
  {


  int val = digitalRead(switchPin);
 
  if(previous != val && val == 0)
  { 
    count++;
    Serial.println(count);
  }
  previous = val;
  delay(200);
  }
}
