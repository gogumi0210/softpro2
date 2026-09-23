const int LED_PIN = 7;

unsigned int g_period_us = 10000;
unsigned int g_duty = 0;

void set_period(int period) {
  if (period < 100)   period = 100;
  if (period > 10000) period = 10000;
  g_period_us = (unsigned int)period;
}

void set_duty(int duty) {
  if (duty < 0)   duty = 0;
  if (duty > 100) duty = 100;
  g_duty = (unsigned int)duty;
}

void pwm_pulse() {
  unsigned long on_us  = (unsigned long)g_period_us * g_duty / 100;
  unsigned long off_us = g_period_us - on_us;

  if (on_us > 0) {
    digitalWrite(LED_PIN, HIGH);
    delayMicroseconds(on_us);
  }
  if (off_us > 0) {
    digitalWrite(LED_PIN, LOW);
    delayMicroseconds(off_us);
  }
}

void setup() {
  pinMode(LED_PIN, OUTPUT);

  set_period(100);
}
void loop() {
  unsigned long start_ms = millis();
  unsigned long elapsed;

  while ((elapsed = millis() - start_ms) < 1000) {
    int duty;
    if (elapsed < 500) {
      duty = map(elapsed, 0, 500, 0, 100);
    } else {
      duty = map(elapsed, 500, 1000, 100, 0);
    }
    set_duty(duty);
    pwm_pulse();
  }
}
