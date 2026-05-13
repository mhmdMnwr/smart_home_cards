#include "serial_handler.h"

#include "app_globals.h"
#include "config.h"

void handleSerial() {
  static String buf = "";
  static unsigned long lastChar = 0;

  if (buf.length() > 0 && millis() - lastChar > 500) {
    buf = "";
  }

  while (Serial.available()) {
    char c = static_cast<char>(Serial.read());
    lastChar = millis();

    if (c == '\n') {
      buf.trim();
      if (buf.startsWith("REQ:")) {
        String input = buf.substring(4);
        input.trim();

        if (input == appState.storedPassword) {
          Serial.println("OK");
          appState.failCount = 0;
          appState.alarmState = false;
          digitalWrite(PIN_ALARM, LOW);
        } else {
          Serial.println("FAIL");
          appState.failCount++;
          if (appState.failCount >= 3) {
            appState.alarmState = true;
            digitalWrite(PIN_ALARM, HIGH);
            Serial.println("[ALARM] Triggered by serial failures");
          }
        }
      }
      buf = "";
    } else {
      buf += c;
    }
  }
}
