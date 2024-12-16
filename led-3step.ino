int led_red = 11;    //ไฟสีแดง
int led_yellow = 10; //ไฟสีเหลือง
int led_green = 9;  //ไฟสีเขียว
int vr_pin = A0;   //ตัวต้านทานปรับค่าได้
int sw_pin = 8;    //สวิตซ์

bool normal_state = true; // ตัวแปรสถานะสวิตซ์
bool click_state = false; // ตัวแปรเช็คว่าสวิตซ์มีการกดหรือป่าว

void setup() {    //เซ็ตอุปกรณ์แต่ละตัว
  pinMode(led_red, OUTPUT);
  pinMode(led_yellow, OUTPUT);
  pinMode(led_green, OUTPUT);
  pinMode(vr_pin, INPUT_PULLUP);
  pinMode(sw_pin, INPUT_PULLUP);
  Serial.begin(9600);
}

void loop() {
  int vr = analogRead(vr_pin);
  int Vpot = map(vr, 0, 1023, 0, 5);  // เปลี่ยนสเกลจาก 0-1023 เป็น 0-5
  Serial.println(Vpot);  //แสดงค่า Vpot ผ่านทาง Serial monitor

  int sw = digitalRead(sw_pin);  //อ่านค่าสวิตซ์

  if (sw != click_state) {  // เช็คว่าสวิตซ์ถูกกดหรือยัง
    if (sw == 0) { // ปุ่มถูกกดแล้ว
      normal_state = !normal_state; // เปลี่ยนค่าตัวแปร
    }
    click_state = sw;   //Reset ค่ากลับ
  }


  if (!normal_state) {
    if (Vpot == 0) {
      digitalWrite(led_red, 0);
      digitalWrite(led_yellow, 0);
      digitalWrite(led_green, 0);
    } else if (Vpot == 1) {
      digitalWrite(led_red, 0);
      digitalWrite(led_yellow, 0);
      digitalWrite(led_green, 1);
    } else if (Vpot == 2) {
      digitalWrite(led_red, 0);
      digitalWrite(led_yellow, 1);
      digitalWrite(led_green, 1);
    } else if (Vpot >= 3) {
      digitalWrite(led_red, 1);
      digitalWrite(led_yellow, 1);
      digitalWrite(led_green, 1);
    }
  }


  else {
    if (Vpot == 0) {
      digitalWrite(led_red, 0);
      digitalWrite(led_yellow, 0);
      digitalWrite(led_green, 0);
    } else if (Vpot == 1) {
      digitalWrite(led_red, 1);
      digitalWrite(led_yellow, 0);
      digitalWrite(led_green, 0);
    } else if (Vpot == 2) {
      digitalWrite(led_red, 1);
      digitalWrite(led_yellow, 1);
      digitalWrite(led_green, 0);
    } else if (Vpot >= 3) {
      digitalWrite(led_red, 1);
      digitalWrite(led_yellow, 1);
      digitalWrite(led_green, 1);
    }
  }
}