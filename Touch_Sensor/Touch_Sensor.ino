
#define LED_PIN   2  // GPIO 4
#define TOUCH_PIN T0 // GPIO 2
#define TOUCH_THRESHOLD 50



void setup() {
  Serial.begin(115200);
  delay(1000);
  Serial.println("ESP32 Touch Sensor");
  
  pinMode(LED_PIN, OUTPUT);
  digitalWrite (LED_PIN, LOW);
}

void loop() {
  int touch_value = touchRead(TOUCH_PIN);
  Serial.println(touch_value);
  if (touch_value < TOUCH_THRESHOLD) {
    digitalWrite(LED_PIN, HIGH);
  } else {
    digitalWrite(LED_PIN, LOW);
  }
  delay(500);
}
