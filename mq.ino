#define BLYNK_TEMPLATE_ID "YourTemplateID"
#define BLYNK_TEMPLATE_NAME "MQ Monitoring"
#define BLYNK_AUTH_TOKEN "YourAuthToken"

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

char auth[] = BLYNK_AUTH_TOKEN;
char ssid[] = "NamaWiFi";
char pass[] = "PasswordWiFi";

#define MQ_PIN A0
#define BUZZER_PIN D5

int gasValue;

void setup()
{
    Serial.begin(115200);

    pinMode(BUZZER_PIN, OUTPUT);

    digitalWrite(BUZZER_PIN, LOW);

    Blynk.begin(auth, ssid, pass);
}

void loop()
{
    Blynk.run();

    gasValue = analogRead(MQ_PIN);

    Serial.print("Gas Value: ");
    Serial.println(gasValue);

    Blynk.virtualWrite(V0, gasValue);

    if(gasValue > 500)
    {
        digitalWrite(BUZZER_PIN, HIGH);

        Blynk.virtualWrite(V1, 1);

        Serial.println("Gas Terdeteksi");
    }
    else
    {
        digitalWrite(BUZZER_PIN, LOW);

        Blynk.virtualWrite(V1, 0);

        Serial.println("Udara Normal");
    }

    delay(1000);
}
