#include <Servo.h>
Servo rain_servo;

// กำหนดขาเซ็นเซอร์และเซอร์โวมอเตอร์
int sensor_pin = 4;
int rain_servo_pin = 8;  // เปลี่ยนขาเซอร์โวเป็นขา 8
int val;

void setup() {
  pinMode(sensor_pin, INPUT);
  rain_servo.attach(rain_servo_pin);

  // เริ่มการสื่อสาร Serial เพื่อดูผลลัพธ์
  Serial.begin(9600);
  Serial.println("ระบบพร้อมทำงาน...");
}

void loop() {
  // อ่านค่าสถานะของเซ็นเซอร์
  val = digitalRead(sensor_pin);
  
  // แสดงค่าใน Serial Monitor
  Serial.print("สถานะเซ็นเซอร์: ");
  Serial.println(val);
  
  // ตรวจสอบสถานะและควบคุม Servo
  if (val == 0) {
    rain_servo.write(0);
    Serial.println("ฝนตก -> เก็บราวตากผ้า");
  } else {
    rain_servo.write(180);
    Serial.println("ฝนหยุด -> กางราวตากผ้า");
  }
  
  // รอ 500 มิลลิวินาทีเพื่อลดการทำงานที่ถี่เกินไป
  delay(500);
}