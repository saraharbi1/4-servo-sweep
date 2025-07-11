#include <Servo.h>

Servo servo1;
Servo servo2;
Servo servo3;
Servo servo4;

int pos = 0;

void setup() {
  servo1.attach(9);   // توصيل السيرفو الأول على البن 9
  servo2.attach(10);  // توصيل السيرفو الثاني على البن 10
  servo3.attach(11);  // توصيل السيرفو الثالث على البن 11
  servo4.attach(12);  // توصيل السيرفو الرابع على البن 12
}

void loop() {
  // تنفيذ الحركة لمدة 2 ثانية فقط
  unsigned long startTime = millis();

  while (millis() - startTime < 2000) {
    for (pos = 0; pos <= 180; pos += 1) {
      servo1.write(pos);
      servo2.write(pos);
      servo3.write(pos);
      servo4.write(pos);
      delay(5); // تقليل التأخير لتسريع الحركة وإكمالها خلال 2 ثانية
    }

    for (pos = 180; pos >= 0; pos -= 1) {
      servo1.write(pos);
      servo2.write(pos);
      servo3.write(pos);
      servo4.write(pos);
      delay(5);
    }
  }

  // تثبيت جميع السيرفو على زاوية 90
  servo1.write(90);
  servo2.write(90);
  servo3.write(90);
  servo4.write(90);

  while (true); // توقف البرنامج (يبقى السيرفو على 90 درجة)
}
