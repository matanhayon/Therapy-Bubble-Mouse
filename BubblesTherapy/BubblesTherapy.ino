
#include <Wire.h>
#include <MPU6050.h>
#include <Mouse.h>
MPU6050 mpu;
int16_t ax, ay, az, gx, gy ,gz;
int vx, vy;

void setup() 
{
	Serial.begin(9600);
	pinMode(2, INPUT_PULLUP);
		while (!Serial);
		delay(4000);
		Serial.println("Code Start");
	Wire.begin();
	mpu.initialize();
	if (!mpu.testConnection()) { while (1); }
}
void loop() {
	mpu.getMotion6(&ax, &ay, &az, &gx, &gz, &gy);
	vx = -(gx+260)/150;
	vy = (gz+100)/150;
		int buttonState1 = digitalRead(2);
	if (buttonState1 == LOW) {
		Mouse.press(MOUSE_LEFT);
		delay(100);
		Mouse.release(MOUSE_LEFT);
		delay(100);
    Serial.println("clicked");
	}
    Serial.println("out of if");

	Mouse.move(vx, 0);
	delay(20);
}
