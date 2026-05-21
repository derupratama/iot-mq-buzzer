# MQ Gas Sensor + Buzzer IoT with Blynk (ESP8266)

![IoT](https://img.shields.io/badge/IoT-ESP8266-blue)
![Blynk](https://img.shields.io/badge/Blynk-Connected-green)
![License](https://img.shields.io/badge/License-Educational-orange)

Project IoT sederhana menggunakan ESP8266, sensor gas MQ, buzzer, dan Blynk untuk mendeteksi kebocoran gas atau asap secara real-time.

---

# Features

* Monitoring gas atau asap menggunakan sensor MQ
* Buzzer menyala otomatis ketika gas terdeteksi
* Monitoring data melalui aplikasi Blynk
* Real-time serial monitor
* Cocok untuk pembelajaran IoT dasar

---

# Deskripsi Project

Project ini merupakan implementasi sederhana Internet of Things (IoT) menggunakan ESP8266, sensor gas MQ, buzzer, dan aplikasi Blynk. Sistem bekerja dengan cara membaca kadar gas atau asap menggunakan sensor MQ. Ketika nilai sensor melewati batas tertentu, maka buzzer akan menyala sebagai alarm.

Project ini cocok digunakan untuk:

* Monitoring kebocoran gas
* Deteksi asap sederhana
* Praktikum IoT dasar
* Pembelajaran sensor dan aktuator

---

# Komponen yang Digunakan

## Hardware

1. ESP8266 NodeMCU
2. Sensor MQ-2 / MQ Gas Sensor
3. Buzzer
4. Kabel Jumper
5. Breadboard

---

# Wiring

## MQ Sensor

| MQ Sensor | ESP8266 |
| --------- | ------- |
| VCC       | VIN     |
| GND       | GND     |
| AO        | A0      |

## Buzzer

| Buzzer      | ESP8266 |
| ----------- | ------- |
| Positif (+) | D5      |
| Negatif (-) | GND     |

---

# Library yang Digunakan

Install library berikut melalui Arduino IDE:

## 1. Blynk

Nama Library:

```txt
Blynk
```

Author:

```txt
Volodymyr Shymanskyy
```

## 2. ESP8266WiFi

Library ini tersedia setelah install board ESP8266.

---

# Cara Install ESP8266 di Arduino IDE

1. Buka Arduino IDE
2. Masuk ke:

```txt
File -> Preferences
```

3. Tambahkan URL berikut pada Additional Board Manager URLs:

```txt
http://arduino.esp8266.com/stable/package_esp8266com_index.json
```

4. Masuk ke:

```txt
Tools -> Board -> Boards Manager
```

5. Cari:

```txt
ESP8266
```

6. Install board ESP8266.

---

# Cara Membuat Template Blynk

1. Buka aplikasi atau website Blynk.
2. Buat Template baru.
3. Pilih device:

```txt
NodeMCU 1.0 (ESP-12E Module)
```

4. Connection type:

```txt
WiFi
```

5. Copy:

* BLYNK_TEMPLATE_ID
* BLYNK_TEMPLATE_NAME
* BLYNK_AUTH_TOKEN

---

# Widget Blynk yang Digunakan

## Gauge / Value Display

Gunakan:

```txt
Virtual Pin V0
```

Untuk menampilkan nilai gas.

## LED Indicator

Gunakan:

```txt
Virtual Pin V1
```

Untuk status buzzer.

---

# Source Code

```cpp
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
```

---

# Cara Upload Program

1. Sambungkan ESP8266 ke laptop.
2. Pilih board:

```txt
NodeMCU 1.0 (ESP-12E Module)
```

3. Pilih COM port yang sesuai.
4. Paste source code.
5. Ganti:

* Nama WiFi
* Password WiFi
* Token Blynk

6. Klik Upload.

---

# Cara Kerja Sistem

1. Sensor MQ membaca kadar gas atau asap.
2. Jika nilai sensor lebih dari 500:

   * Buzzer menyala
   * Status dikirim ke Blynk
3. Jika nilai sensor kurang dari 500:

   * Buzzer mati
   * Status normal dikirim ke Blynk

---

# Output Serial Monitor

## Saat Udara Normal

```txt
Gas Value: 230
Udara Normal
```

## Saat Gas Terdeteksi

```txt
Gas Value: 780
Gas Terdeteksi
```

---

# Penjelasan Logika Program

Program dimulai dengan menghubungkan ESP8266 ke jaringan WiFi dan server Blynk menggunakan token autentikasi. Setelah koneksi berhasil, sensor MQ akan membaca kadar gas atau asap menggunakan fungsi analogRead().

Nilai sensor kemudian dibandingkan menggunakan kondisi if. Ketika nilai sensor lebih dari 500, maka buzzer akan menyala menggunakan digitalWrite(BUZZER_PIN, HIGH) sebagai alarm peringatan kebocoran gas atau asap. Selain itu nilai sensor dan status buzzer juga dikirim ke aplikasi Blynk menggunakan Blynk.virtualWrite().

Jika nilai sensor kurang dari batas yang ditentukan, maka buzzer akan mati dan sistem dianggap dalam kondisi normal.

---

# Repository Structure

```txt
mq-buzzer-blynk/
│
├── mq_buzzer_blynk.ino
├── README.md
│
└── assets/
    └── wiring-diagram.png
```

---

# Kesimpulan

Project ini menunjukkan implementasi dasar IoT menggunakan ESP8266 dan Blynk dengan kombinasi sensor MQ dan buzzer. Sistem dapat melakukan monitoring gas atau asap secara real-time dan memberikan alarm otomatis ketika nilai gas melebihi batas yang ditentukan.
