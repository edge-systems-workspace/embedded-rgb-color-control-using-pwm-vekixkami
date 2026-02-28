#include <Arduino.h>

/**
 * @file main.cpp
 * @brief Embedded RGB LED Control (Digital + PWM)
 * @author Vedansh
 * @date 2026-02-28
 *
 * @details
 * This program demonstrates control of an RGB LED using both
 * digital ON/OFF control and analog PWM brightness control.
 * First, the LED is toggled using digital signals, and then
 * brightness of each color (Red, Green, Blue) is varied using PWM.
 */

// Define RED pin (Use 9)
#define RED_PIN 9

// Define GREEN pin (Use 10)
#define GREEN_PIN 10

// Define BLUE pin (Use 11)
#define BLUE_PIN 11

/**
 * @brief Initializes serial communication and configures RGB pins.
 */
void setup() {

    // Initialize Serial communication (9600 baud)
    Serial.begin(9600);

    // Configure RGB pins as OUTPUT
    pinMode(RED_PIN, OUTPUT);
    pinMode(GREEN_PIN, OUTPUT);
    pinMode(BLUE_PIN, OUTPUT);

    // Print initialization message
    Serial.println("RGB LED Control System Initialized");
}

/**
 * @brief Main loop to demonstrate digital and PWM control of RGB LED.
 */
void loop() {

    // -------- DIGITAL MODE --------
    Serial.println("Digital Mode: RED ON");

    // Turn ON red (digital HIGH)
    digitalWrite(RED_PIN, HIGH);
    delay(1000);

    // Turn OFF red
    digitalWrite(RED_PIN, LOW);
    delay(1000);

    // -------- ANALOG (PWM) MODE --------
    Serial.println("Analog PWM Mode: Color Fading");

    // Set RED brightness using analogWrite()
    analogWrite(RED_PIN, 255);   // Full brightness red
    analogWrite(GREEN_PIN, 0);
    analogWrite(BLUE_PIN, 0);
    delay(1000);

    // Set GREEN brightness using analogWrite()
    analogWrite(RED_PIN, 0);
    analogWrite(GREEN_PIN, 255); // Full brightness green
    analogWrite(BLUE_PIN, 0);
    delay(1000);

    // Set BLUE brightness using analogWrite()
    analogWrite(RED_PIN, 0);
    analogWrite(GREEN_PIN, 0);
    analogWrite(BLUE_PIN, 255);  // Full brightness blue
    delay(1000);

    // Add delay for visible transition (white color)
    analogWrite(RED_PIN, 255);
    analogWrite(GREEN_PIN, 255);
    analogWrite(BLUE_PIN, 255);  // White color
    delay(1000);
}
