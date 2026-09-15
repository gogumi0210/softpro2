#define LED_PIN 7
#define LED_ON  LOW    // 5V-저항-LED-Pin7 배선이므로 LOW가 켜짐
#define LED_OFF HIGH

void setup() {
  pinMode(LED_PIN, OUTPUT);
  digitalWrite(LED_PIN, LED_OFF);   // 시작 시 꺼둠
}

void loop() {
  // (1) 0~1초: LED 켜기
  digitalWrite(LED_PIN, LED_ON);
  delay(1000);

  // (2) 1~2초: 5회 깜빡임 (1회당 200ms = 꺼짐 100ms + 켜짐 100ms)
  for (int i = 0; i < 5; i++) {
    digitalWrite(LED_PIN, LED_OFF);
    delay(100);
    digitalWrite(LED_PIN, LED_ON);
    delay(100);
  }

  // (3) LED 끄고 무한루프로 정지
  digitalWrite(LED_PIN, LED_OFF);
  while (1) {}
} 
