#define LED_PIN   2  // GPIO 2
#define TOUCH_PIN T0 // GPIO 4

// PWM properties
#define FREQUENCY 5000
#define LED_CHANNEL 0
#define RESOLUTION 8

 
void setup(){
  Serial.begin(115200);
  delay(1000);
  Serial.println("ESP32 Analog LED");
  
  // configure LED PWM
  ledcSetup(LED_CHANNEL, FREQUENCY, RESOLUTION);
  
  ledcAttachPin(LED_PIN, LED_CHANNEL);
}
 
void loop(){
  int touch_value = touchRead(TOUCH_PIN);
  Serial.print("touch_value: ");
  Serial.println(touch_value);

  int duty_cycle = 2 * ( 100 - touch_value );
  Serial.print("duty_cycle: ");
  Serial.println(duty_cycle);

  ledcWrite(LED_CHANNEL, duty_cycle);
  delay(100);
}
