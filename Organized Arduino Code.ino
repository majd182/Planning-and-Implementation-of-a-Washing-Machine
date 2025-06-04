#define WHITE_BTN 2
#define COLOR_BTN 3
#define DRAINING_AND_EXTORTION_OF_WATER_PIN 8
#define SOAP_FREE_RINSE_PIN 7
#define DRAIN_WATER_PIN 6
#define WASH_WITH_SOAP_PIN 5
#define WATER_FILLING_PIN 4 // Not used in current logic, but kept for clarity
#define BUZZER_PIN 1

// Define pins for 7-segment display (assuming common cathode and pins 9-13 control segments/digits)
// You'll need to map these to actual segments based on your hardware wiring.
// For example, if pins 9,10,11,12,13 represent A,B,C,D,E or specific digit controls.
// For simplicity, let's assume they drive a single digit BCD display (e.g., connected to 74LS47)
// and represent a specific BCD value, or individual segments.
// Based on the original code, they seem to control a single digit display, possibly via BCD to 7-segment decoder.
// Let's call them DISPLAY_PIN_A, DISPLAY_PIN_B, etc.
#define DISPLAY_PIN_1 9
#define DISPLAY_PIN_2 10
#define DISPLAY_PIN_3 11
#define DISPLAY_PIN_4 12
#define DISPLAY_PIN_5 13 // Assuming these are 5 pins controlling display, adjust if it's 4 BCD + 1 enable or similar

// Function to update the 7-segment display
// This function assumes a specific mapping of pins 9-13 to display digits or segments
// You'll need to adapt this function to your actual 7-segment display setup (e.g., BCD, common cathode/anode)
void updateDisplay(int digit) {
  // This is a placeholder logic. You need to implement the actual BCD to 7-segment logic
  // based on your 74LS47 decoder's input pins (connected to Arduino pins).
  // Example for a simple 4-bit BCD to 7-segment decoder (like 74LS47):
  // Assuming pins 9,10,11,12 are connected to A,B,C,D inputs of 74LS47 respectively.
  digitalWrite(DISPLAY_PIN_2, (digit & 0b0001) ? HIGH : LOW); // A
  digitalWrite(DISPLAY_PIN_3, (digit & 0b0010) ? HIGH : LOW); // B
  digitalWrite(DISPLAY_PIN_4, (digit & 0b0100) ? HIGH : LOW); // C
  digitalWrite(DISPLAY_PIN_5, (digit & 0b1000) ? HIGH : LOW); // D
  // The original code uses 5 pins (9-13) and has complex patterns.
  // A better way would be to create an array of patterns for each digit (0-9).
  // For now, let's mimic the original's changing patterns for illustration
  // This part of the code needs to be customized to how your 7-segment is connected and driven.
  // The original code literally writes patterns like:
  // digitalWrite(10, HIGH); digitalWrite(11, LOW); digitalWrite(12, HIGH); digitalWrite(13, LOW);
  // for different "digits"
  // It's likely that these pins are directly connected to segments or to a custom decoder/driver.
  // For a clean implementation, define patterns for each digit if directly driving segments,
  // or send BCD values if using a BCD-to-7-segment decoder.

  // The original code sets specific HIGH/LOW patterns for each "countdown step"
  // If pins 9-13 are directly controlling segments, you'd have something like:
  // const byte digit_patterns[][5] = {
  //   {HIGH, HIGH, HIGH, HIGH, HIGH}, // For a hypothetical "15" or initial state
  //   {LOW, HIGH, HIGH, LOW, LOW},    // For a hypothetical "14"
  //   // ... up to 0
  // };
  // digitalWrite(DISPLAY_PIN_1, digit_patterns[digit_index][0]);
  // ... and so on.

  // For now, just a simplified representation that needs real implementation based on hardware
  // The actual display logic from your original code is mixed with delays.
  // It's recommended to create a dedicated function to set the display for a given digit.
  // Example: `void displayDigit(int digit)`
  // If you are using a 74LS47, you would send BCD values to pins 9-12 (if these are the A,B,C,D inputs).
  // E.g., `digitalWrite(9, (digit & 0x01)); digitalWrite(10, (digit & 0x02) >> 1); ...`
}


// Function to make the buzzer beep
void beepBuzzer(int times, int duration_ms) {
  for (int i = 0; i < times; i++) {
    digitalWrite(BUZZER_PIN, HIGH);
    delay(duration_ms);
    digitalWrite(BUZZER_PIN, LOW);
    delay(duration_ms); // Or a shorter delay between beeps if desired
  }
}

// Function to run the "White Clothes" washing program
void runWhiteProgram() {
  Serial.println("Starting White Clothes Program (15s total)");

  // Reset all washing action outputs
  digitalWrite(DRAINING_AND_EXTORTION_OF_WATER_PIN, LOW);
  digitalWrite(SOAP_FREE_RINSE_PIN, LOW);
  digitalWrite(DRAIN_WATER_PIN, LOW);
  digitalWrite(WASH_WITH_SOAP_PIN, LOW);
  digitalWrite(WATER_FILLING_PIN, LOW); // Ensure water filling is off

  // --- Initial Countdown & Wash with Soap (4s) ---
  // The original code's display logic is integrated with delays.
  // For better clarity, you might want to separate display updates from delays
  // or manage them in a state machine.
  // Here, mimicking original structure for display updates during delays.

  // Countdown from 15 to 11 (5 seconds including initial delay)
  // Second 15: Initial delay
  digitalWrite(DISPLAY_PIN_1, HIGH); // Example display states
  digitalWrite(DISPLAY_PIN_2, HIGH);
  digitalWrite(DISPLAY_PIN_3, LOW);
  digitalWrite(DISPLAY_PIN_4, HIGH);
  digitalWrite(DISPLAY_PIN_5, LOW);
  delay(1000);

  // Second 14: Wash with soap starts
  digitalWrite(WASH_WITH_SOAP_PIN, HIGH);
  digitalWrite(DISPLAY_PIN_2, LOW);
  digitalWrite(DISPLAY_PIN_3, LOW);
  digitalWrite(DISPLAY_PIN_4, HIGH);
  digitalWrite(DISPLAY_PIN_5, LOW);
  delay(1000);

  // Second 13:
  digitalWrite(DISPLAY_PIN_2, HIGH);
  digitalWrite(DISPLAY_PIN_3, HIGH);
  digitalWrite(DISPLAY_PIN_4, LOW);
  digitalWrite(DISPLAY_PIN_5, LOW);
  delay(1000);

  // Second 12:
  digitalWrite(DISPLAY_PIN_2, LOW);
  digitalWrite(DISPLAY_PIN_3, HIGH);
  digitalWrite(DISPLAY_PIN_4, LOW);
  digitalWrite(DISPLAY_PIN_5, LOW);
  delay(1000);

  // Second 11:
  digitalWrite(DISPLAY_PIN_2, HIGH);
  digitalWrite(DISPLAY_PIN_3, LOW);
  digitalWrite(DISPLAY_PIN_4, LOW);
  digitalWrite(DISPLAY_PIN_5, LOW);
  delay(1000);
  Serial.println("Washing with soap complete.");
  digitalWrite(WASH_WITH_SOAP_PIN, LOW);


  // --- Drain Water (2s) ---
  digitalWrite(DRAIN_WATER_PIN, HIGH);
  // Countdown from 10 to 9
  digitalWrite(DISPLAY_PIN_2, LOW);
  digitalWrite(DISPLAY_PIN_3, LOW);
  digitalWrite(DISPLAY_PIN_4, LOW);
  digitalWrite(DISPLAY_PIN_5, LOW); // Representing 10
  delay(1000);
  digitalWrite(DISPLAY_PIN_1, LOW); // Adjust as per your display
  digitalWrite(DISPLAY_PIN_2, HIGH);
  digitalWrite(DISPLAY_PIN_3, LOW);
  digitalWrite(DISPLAY_PIN_4, LOW);
  digitalWrite(DISPLAY_PIN_5, HIGH); // Representing 9
  delay(1000);
  Serial.println("Water drainage complete.");
  digitalWrite(DRAIN_WATER_PIN, LOW);


  // --- Soap-Free Rinse (4s) ---
  digitalWrite(SOAP_FREE_RINSE_PIN, HIGH);
  // Countdown from 8 to 5
  digitalWrite(DISPLAY_PIN_2, LOW);
  digitalWrite(DISPLAY_PIN_3, LOW);
  digitalWrite(DISPLAY_PIN_4, LOW);
  digitalWrite(DISPLAY_PIN_5, HIGH); // Representing 8
  delay(1000);
  digitalWrite(DISPLAY_PIN_2, HIGH);
  digitalWrite(DISPLAY_PIN_3, HIGH);
  digitalWrite(DISPLAY_PIN_4, HIGH);
  digitalWrite(DISPLAY_PIN_5, LOW); // Representing 7
  delay(1000);
  digitalWrite(DISPLAY_PIN_2, LOW);
  digitalWrite(DISPLAY_PIN_3, HIGH);
  digitalWrite(DISPLAY_PIN_4, HIGH);
  digitalWrite(DISPLAY_PIN_5, LOW); // Representing 6
  delay(1000);
  digitalWrite(DISPLAY_PIN_2, HIGH);
  digitalWrite(DISPLAY_PIN_3, LOW);
  digitalWrite(DISPLAY_PIN_4, HIGH);
  digitalWrite(DISPLAY_PIN_5, LOW); // Representing 5
  delay(1000);
  Serial.println("Soap-free rinse complete.");
  digitalWrite(SOAP_FREE_RINSE_PIN, LOW);


  // --- Draining and Extortion of Water (3s) ---
  digitalWrite(DRAINING_AND_EXTORTION_OF_WATER_PIN, HIGH);
  // Countdown from 4 to 2
  digitalWrite(DISPLAY_PIN_2, LOW);
  digitalWrite(DISPLAY_PIN_3, LOW);
  digitalWrite(DISPLAY_PIN_4, HIGH);
  digitalWrite(DISPLAY_PIN_5, LOW); // Representing 4
  delay(1000);
  digitalWrite(DISPLAY_PIN_2, HIGH);
  digitalWrite(DISPLAY_PIN_3, HIGH);
  digitalWrite(DISPLAY_PIN_4, LOW);
  digitalWrite(DISPLAY_PIN_5, LOW); // Representing 3
  delay(1000);
  digitalWrite(DISPLAY_PIN_2, LOW);
  digitalWrite(DISPLAY_PIN_3, HIGH);
  digitalWrite(DISPLAY_PIN_4, LOW);
  digitalWrite(DISPLAY_PIN_5, LOW); // Representing 2
  delay(1000);
  Serial.println("Final draining and spinning complete.");
  digitalWrite(DRAINING_AND_EXTORTION_OF_WATER_PIN, LOW);


  // --- Final Countdown (2s) and Buzzer ---
  digitalWrite(DISPLAY_PIN_2, HIGH);
  digitalWrite(DISPLAY_PIN_3, LOW);
  digitalWrite(DISPLAY_PIN_4, LOW);
  digitalWrite(DISPLAY_PIN_5, LOW); // Representing 1
  delay(1000);
  digitalWrite(DISPLAY_PIN_2, LOW);
  digitalWrite(DISPLAY_PIN_3, LOW);
  digitalWrite(DISPLAY_PIN_4, LOW);
  digitalWrite(DISPLAY_PIN_5, LOW); // Representing 0
  delay(1000);

  beepBuzzer(3, 1000); // 3 beeps, 1 second each
  Serial.println("White Clothes Program Finished!");
}


// Function to run the "Colored Clothes" washing program
void runColorProgram() {
  Serial.println("Starting Colored Clothes Program (19s total)");

  // Reset all washing action outputs
  digitalWrite(DRAINING_AND_EXTORTION_OF_WATER_PIN, LOW);
  digitalWrite(SOAP_FREE_RINSE_PIN, LOW);
  digitalWrite(DRAIN_WATER_PIN, LOW);
  digitalWrite(WASH_WITH_SOAP_PIN, LOW);
  digitalWrite(WATER_FILLING_PIN, LOW); // Ensure water filling is off

  // --- Initial Countdown & Wash with Soap (8s) ---
  // Countdown from 19 to 11 (9 seconds including initial delay)
  digitalWrite(DISPLAY_PIN_1, HIGH); // Example display states
  digitalWrite(DISPLAY_PIN_2, HIGH);
  digitalWrite(DISPLAY_PIN_3, LOW);
  digitalWrite(DISPLAY_PIN_4, LOW);
  digitalWrite(DISPLAY_PIN_5, HIGH); // Representing 19 (or initial state)
  delay(1000);

  // Second 18: Wash with soap starts
  digitalWrite(WASH_WITH_SOAP_PIN, HIGH);
  digitalWrite(DISPLAY_PIN_2, LOW);
  digitalWrite(DISPLAY_PIN_3, LOW);
  digitalWrite(DISPLAY_PIN_4, LOW);
  digitalWrite(DISPLAY_PIN_5, HIGH); // Representing 18
  delay(1000);

  // Second 17:
  digitalWrite(DISPLAY_PIN_2, HIGH);
  digitalWrite(DISPLAY_PIN_3, HIGH);
  digitalWrite(DISPLAY_PIN_4, HIGH);
  digitalWrite(DISPLAY_PIN_5, LOW); // Representing 17
  delay(1000);

  // Second 16:
  digitalWrite(DISPLAY_PIN_2, LOW);
  digitalWrite(DISPLAY_PIN_3, HIGH);
  digitalWrite(DISPLAY_PIN_4, HIGH);
  digitalWrite(DISPLAY_PIN_5, LOW); // Representing 16
  delay(1000);

  // Second 15:
  digitalWrite(DISPLAY_PIN_2, HIGH);
  digitalWrite(DISPLAY_PIN_3, LOW);
  digitalWrite(DISPLAY_PIN_4, HIGH);
  digitalWrite(DISPLAY_PIN_5, LOW); // Representing 15
  delay(1000);

  // Second 14:
  digitalWrite(DISPLAY_PIN_2, LOW);
  digitalWrite(DISPLAY_PIN_3, LOW);
  digitalWrite(DISPLAY_PIN_4, HIGH);
  digitalWrite(DISPLAY_PIN_5, LOW); // Representing 14
  delay(1000);

  // Second 13:
  digitalWrite(DISPLAY_PIN_2, HIGH);
  digitalWrite(DISPLAY_PIN_3, HIGH);
  digitalWrite(DISPLAY_PIN_4, LOW);
  digitalWrite(DISPLAY_PIN_5, LOW); // Representing 13
  delay(1000);

  // Second 12:
  digitalWrite(DISPLAY_PIN_2, LOW);
  digitalWrite(DISPLAY_PIN_3, HIGH);
  digitalWrite(DISPLAY_PIN_4, LOW);
  digitalWrite(DISPLAY_PIN_5, LOW); // Representing 12
  delay(1000);

  // Second 11:
  digitalWrite(DISPLAY_PIN_2, HIGH);
  digitalWrite(DISPLAY_PIN_3, LOW);
  digitalWrite(DISPLAY_PIN_4, LOW);
  digitalWrite(DISPLAY_PIN_5, LOW); // Representing 11
  delay(1000);
  Serial.println("Washing with soap complete.");
  digitalWrite(WASH_WITH_SOAP_PIN, LOW);


  // --- Drain Water (2s) ---
  digitalWrite(DRAIN_WATER_PIN, HIGH);
  // Countdown from 10 to 9
  digitalWrite(DISPLAY_PIN_2, LOW);
  digitalWrite(DISPLAY_PIN_3, LOW);
  digitalWrite(DISPLAY_PIN_4, LOW);
  digitalWrite(DISPLAY_PIN_5, LOW); // Representing 10
  delay(1000);
  digitalWrite(DISPLAY_PIN_1, LOW); // Adjust as per your display
  digitalWrite(DISPLAY_PIN_2, HIGH);
  digitalWrite(DISPLAY_PIN_3, LOW);
  digitalWrite(DISPLAY_PIN_4, LOW);
  digitalWrite(DISPLAY_PIN_5, HIGH); // Representing 9
  delay(1000);
  Serial.println("Water drainage complete.");
  digitalWrite(DRAIN_WATER_PIN, LOW);


  // --- Soap-Free Rinse (4s) ---
  digitalWrite(SOAP_FREE_RINSE_PIN, HIGH);
  // Countdown from 8 to 5
  digitalWrite(DISPLAY_PIN_2, LOW);
  digitalWrite(DISPLAY_PIN_3, LOW);
  digitalWrite(DISPLAY_PIN_4, LOW);
  digitalWrite(DISPLAY_PIN_5, HIGH); // Representing 8
  delay(1000);
  digitalWrite(DISPLAY_PIN_2, HIGH);
  digitalWrite(DISPLAY_PIN_3, HIGH);
  digitalWrite(DISPLAY_PIN_4, HIGH);
  digitalWrite(DISPLAY_PIN_5, LOW); // Representing 7
  delay(1000);
  digitalWrite(DISPLAY_PIN_2, LOW);
  digitalWrite(DISPLAY_PIN_3, HIGH);
  digitalWrite(DISPLAY_PIN_4, HIGH);
  digitalWrite(DISPLAY_PIN_5, LOW); // Representing 6
  delay(1000);
  digitalWrite(DISPLAY_PIN_2, HIGH);
  digitalWrite(DISPLAY_PIN_3, LOW);
  digitalWrite(DISPLAY_PIN_4, HIGH);
  digitalWrite(DISPLAY_PIN_5, LOW); // Representing 5
  delay(1000);
  Serial.println("Soap-free rinse complete.");
  digitalWrite(SOAP_FREE_RINSE_PIN, LOW);


  // --- Draining and Extortion of Water (3s) ---
  digitalWrite(DRAINING_AND_EXTORTION_OF_WATER_PIN, HIGH);
  // Countdown from 4 to 2
  digitalWrite(DISPLAY_PIN_2, LOW);
  digitalWrite(DISPLAY_PIN_3, LOW);
  digitalWrite(DISPLAY_PIN_4, HIGH);
  digitalWrite(DISPLAY_PIN_5, LOW); // Representing 4
  delay(1000);
  digitalWrite(DISPLAY_PIN_2, HIGH);
  digitalWrite(DISPLAY_PIN_3, HIGH);
  digitalWrite(DISPLAY_PIN_4, LOW);
  digitalWrite(DISPLAY_PIN_5, LOW); // Representing 3
  delay(1000);
  digitalWrite(DISPLAY_PIN_2, LOW);
  digitalWrite(DISPLAY_PIN_3, HIGH);
  digitalWrite(DISPLAY_PIN_4, LOW);
  digitalWrite(DISPLAY_PIN_5, LOW); // Representing 2
  delay(1000);
  Serial.println("Final draining and spinning complete.");
  digitalWrite(DRAINING_AND_EXTORTION_OF_WATER_PIN, LOW);


  // --- Final Countdown (2s) and Buzzer ---
  digitalWrite(DISPLAY_PIN_2, HIGH);
  digitalWrite(DISPLAY_PIN_3, LOW);
  digitalWrite(DISPLAY_PIN_4, LOW);
  digitalWrite(DISPLAY_PIN_5, LOW); // Representing 1
  delay(1000);
  digitalWrite(DISPLAY_PIN_2, LOW);
  digitalWrite(DISPLAY_PIN_3, LOW);
  digitalWrite(DISPLAY_PIN_4, LOW);
  digitalWrite(DISPLAY_PIN_5, LOW); // Representing 0
  delay(1000);

  beepBuzzer(3, 1000); // 3 beeps, 1 second each
  Serial.println("Colored Clothes Program Finished!");
}


void setup() {
  Serial.begin(9600); // Initialize Serial communication for debugging

  // Setup outputs for washing machine actions
  pinMode(DRAINING_AND_EXTORTION_OF_WATER_PIN, OUTPUT);
  pinMode(SOAP_FREE_RINSE_PIN, OUTPUT);
  pinMode(DRAIN_WATER_PIN, OUTPUT);
  pinMode(WASH_WITH_SOAP_PIN, OUTPUT);
  pinMode(WATER_FILLING_PIN, OUTPUT);

  // Setup inputs for buttons
  pinMode(WHITE_BTN, INPUT_PULLUP); // Use INPUT_PULLUP for buttons connected to ground
  pinMode(COLOR_BTN, INPUT_PULLUP);

  // Setup buzzer
  pinMode(BUZZER_PIN, OUTPUT);

  // Setup pins for 7-segment display (assuming they are outputs)
  pinMode(DISPLAY_PIN_1, OUTPUT);
  pinMode(DISPLAY_PIN_2, OUTPUT);
  pinMode(DISPLAY_PIN_3, OUTPUT);
  pinMode(DISPLAY_PIN_4, OUTPUT);
  pinMode(DISPLAY_PIN_5, OUTPUT);

  // Ensure all outputs are initially LOW
  digitalWrite(DRAINING_AND_EXTORTION_OF_WATER_PIN, LOW);
  digitalWrite(SOAP_FREE_RINSE_PIN, LOW);
  digitalWrite(DRAIN_WATER_PIN, LOW);
  digitalWrite(WASH_WITH_SOAP_PIN, LOW);
  digitalWrite(WATER_FILLING_PIN, LOW);
  digitalWrite(BUZZER_PIN, LOW);
  digitalWrite(DISPLAY_PIN_1, LOW);
  digitalWrite(DISPLAY_PIN_2, LOW);
  digitalWrite(DISPLAY_PIN_3, LOW);
  digitalWrite(DISPLAY_PIN_4, LOW);
  digitalWrite(DISPLAY_PIN_5, LOW);

  Serial.println("Washing Machine System Ready. Press a program button.");
}

void loop() {
  // Read button states. Note: INPUT_PULLUP means button pressed = LOW.
  // The original code checks for == 1, implying external pull-down or different wiring.
  // If using INPUT_PULLUP, usually check for == LOW when button is pressed.
  // Assuming the original wiring is external pull-down or specific button logic:
  if (digitalRead(WHITE_BTN) == HIGH) { // If white button is pressed
    runWhiteProgram();
  }

  if (digitalRead(COLOR_BTN) == HIGH) { // If color button is pressed
    runColorProgram();
  }
  // Add a small delay to prevent busy-waiting if no button is pressed
  // or to debounce buttons if not handled in hardware.
  delay(10);
}
