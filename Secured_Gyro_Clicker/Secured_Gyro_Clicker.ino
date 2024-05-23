#include <Wire.h>
#include <MPU6050.h>
#include <Mouse.h>

MPU6050 mpu;
int16_t ax, ay, az, gx, gy ,gz;
int vx, vy;
const int button_pin = 2;
const int security_pin = 12;
int previous_button_state = 0;

unsigned long previousTime = 0;
unsigned long currentTime;
const unsigned long interval = 500;
bool isHigh = true;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(security_pin,INPUT_PULLUP);
	pinMode(button_pin, INPUT_PULLUP);

	while (!Serial);
	    delay(400);
		Serial.println("Code Start");
	Wire.begin();
	mpu.initialize();
	if (!mpu.testConnection()) { while (1); }
}

void loop()
{
  if(digitalRead(security_pin)==LOW)
  {
    // Accelometer:
  	mpu.getMotion6(&ax, &ay, &az, &gx, &gz, &gy);
	  vx = -(gx+260)/150;
	  vy = (gz+100)/150;
    Mouse.move(vx, 0);
    delay(20);

    //click
		int current_button_state = digitalRead(button_pin);
    if (current_button_state == LOW)
    {
      Mouse.click();
      Serial.println("clicked");
    }
    else
    {
      Serial.println("else - current button state high " + current_button_state);
    }

    //Blink
    currentTime = millis();
    if(currentTime - previousTime >= interval)
    {
      digitalWrite(13, isHigh ? HIGH : LOW);
      isHigh = !isHigh;
      previousTime = currentTime;
    }


  }  
}
