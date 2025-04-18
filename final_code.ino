/*
Smart home
TO : IEEE Ras Graduation Project
By / Moaz Hany
*/
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

#define TEMP_SENSOR A1
#define MQ5_PIN A0
#define BUZZER_PIN 8
#define IR_SENSOR_PIN 7
#define TRIG_PIN 9
#define ECHO_PIN 10

#define LED1_PIN 4
#define LED2_PIN 5
#define LED3_PIN 6

#define GAS_THRESHOLD 120
#define DISTANCE_THRESHOLD 10

LiquidCrystal_I2C lcd(0x27, 16, 2);

bool led1State = false;
bool led2State = false;
bool led3State = false;

void setup() {
    pinMode(BUZZER_PIN, OUTPUT);
    pinMode(IR_SENSOR_PIN, INPUT);
    pinMode(TRIG_PIN, OUTPUT);
    pinMode(ECHO_PIN, INPUT);

    pinMode(LED1_PIN, OUTPUT);
    pinMode(LED2_PIN, OUTPUT);
    pinMode(LED3_PIN, OUTPUT);

    Serial.begin(9600);

    lcd.init();
    lcd.backlight();
}

long readUltrasonicDistance() {
    digitalWrite(TRIG_PIN, LOW);
    delayMicroseconds(2);
    digitalWrite(TRIG_PIN, HIGH);
    delayMicroseconds(10);
    digitalWrite(TRIG_PIN, LOW);

    long duration = pulseIn(ECHO_PIN, HIGH);
    long distance = duration * 0.034 / 2;
    return distance;
}

void loop() {
    int tempValue = analogRead(TEMP_SENSOR);
    float temperature = (tempValue * 5.0 * 100.0) / 1024.0;

    int gasValue = analogRead(MQ5_PIN);

    bool objectDetected = digitalRead(IR_SENSOR_PIN) == LOW;

    long distance = readUltrasonicDistance();

    if (Serial.available() > 0) {
        char cmd = Serial.read();

        switch (cmd) {
            case '1':
                led1State = !led1State;
                digitalWrite(LED1_PIN, led1State ? HIGH : LOW);
                Serial.println(led1State ? "LED1 ON" : "LED1 OFF");
                break;

            case '2':
                led2State = !led2State;
                digitalWrite(LED2_PIN, led2State ? HIGH : LOW);
                Serial.println(led2State ? "LED2 ON" : "LED2 OFF");
                break;

            case '3':
                led3State = !led3State;
                digitalWrite(LED3_PIN, led3State ? HIGH : LOW);
                Serial.println(led3State ? "LED3 ON" : "LED3 OFF");
                break;

            default:
                Serial.println("Type 1, 2, or 3 to toggle LEDs");
                break;
        }
    }

    if (gasValue > GAS_THRESHOLD) {
        lcd.clear();
        lcd.setCursor(2, 0);
        lcd.print("WARNING!");
        lcd.setCursor(1, 1);
        lcd.print("Gas Leak Detected!");
        digitalWrite(BUZZER_PIN, HIGH);
    }
    else if (objectDetected) {
        lcd.clear();
        lcd.setCursor(1, 0);
        lcd.print("Object Detected");
        lcd.setCursor(4, 1);
        lcd.print("via IR");
        digitalWrite(BUZZER_PIN, HIGH);
    }
    else if (distance < DISTANCE_THRESHOLD) {
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("WARNING! Close Obj");
        lcd.setCursor(0, 1);
        lcd.print("Ultrasonic: ");
        lcd.print(distance);
        lcd.print("cm");
        digitalWrite(BUZZER_PIN, HIGH);
    }
    else {
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("Temp: ");
        lcd.print(temperature, 1);
        lcd.print("C");

        lcd.setCursor(0, 1);
        lcd.print("Gas: ");
        lcd.print(gasValue);

        digitalWrite(BUZZER_PIN, LOW);
    }

    delay(1000);
}
