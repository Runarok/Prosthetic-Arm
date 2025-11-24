/*
  ============================================================
      UPDATED VERSION OF:
      "Arduino Robotic Hand Tutorial" by Kuldip K. Gami

      This version keeps the *exact same logic and functionality*
      but adds clearer comments, spacing, and explanation of how
      each part works to make it easier for learners and makers.

      All added explanations are in comments only.
  ============================================================
*/

#include <Servo.h>
#include <SoftwareSerial.h>

// ------------------------------------------------------------
// Servo objects for each finger
// ------------------------------------------------------------
Servo Thumb, Index, Middle, Ring, Little;

// ------------------------------------------------------------
// Bluetooth module on pins 10 (RX) and 11 (TX)
// ------------------------------------------------------------
SoftwareSerial mySerial(10, 11);

// ------------------------------------------------------------
// Finger position variables (used to track current servo angle)
// ------------------------------------------------------------
int ThumbPos, IndexPos, MiddlePos, RingPos, LittlePos;

// ------------------------------------------------------------
// Movement speeds (ms delay between servo steps)
// fingerSpeed = individual finger
// HandSpeed  = whole-hand open/close
// ------------------------------------------------------------
int fingerSpeed = 20;
int HandSpeed   = 20;

// ------------------------------------------------------------
// Input/Output Pins
// ------------------------------------------------------------
int BLED   = 13; // Blue LED (Bluetooth mode indicator)
int RLED   = 12; // Red LED  (Push-button mode indicator)
int PUSH   = 8;  // Push-button input
int SWITCH = 9;  // Mode selector switch

// ============================================================
// Setup
// ============================================================
void setup()
{
  mySerial.begin(9600);

  pinMode(BLED, OUTPUT);
  pinMode(RLED, OUTPUT);
  pinMode(PUSH, INPUT_PULLUP);   // Active LOW
  pinMode(SWITCH, INPUT_PULLUP); // Active LOW = Push-button mode

  // Attach servos to pins
  Thumb.attach(2);
  Index.attach(3);
  Middle.attach(4);
  Ring.attach(5);
  Little.attach(6);

  // Initialize all fingers at the same starting position
  Thumb.write(45);   ThumbPos  = 45;
  Index.write(45);   IndexPos  = 45;
  Middle.write(45);  MiddlePos = 45;
  Ring.write(45);    RingPos   = 45;
  Little.write(45);  LittlePos = 45;

  digitalWrite(RLED, LOW);
  digitalWrite(BLED, LOW);
}

// ============================================================
// MAIN LOOP
// Checks mode switch:
//   LOW  -> Push-button control
//   HIGH -> Bluetooth control
// ============================================================
void loop()
{
  int ProgSwitch = digitalRead(SWITCH);

  if (ProgSwitch == 0)
  {
    // PUSH-BUTTON MODE
    PUSH_BUTTON();
    digitalWrite(RLED, LOW);
    digitalWrite(BLED, HIGH);
  }
  else
  {
    // BLUETOOTH MODE
    BLUETOOTH();
    digitalWrite(RLED, HIGH);
    digitalWrite(BLED, LOW);
  }
}

// ============================================================
// PUSH-BUTTON MODE CONTROL
// One press = close hand, next press = open hand
// ============================================================
void PUSH_BUTTON()
{
  int PushState = digitalRead(PUSH);

  if (PushState == 0)  // Button pressed (active LOW)
  {
    // Check if hand is OPEN
    if (ThumbPos == 45 && IndexPos == 45 && MiddlePos == 45 &&
        RingPos == 45 && LittlePos == 45)
    {
      // Close four fingers first
      for (int i = 45; i <= 150; i++)
      {
        Index.write(i);
        Middle.write(i);
        Ring.write(i);
        Little.write(i);

        IndexPos = MiddlePos = RingPos = LittlePos = i;
        delay(HandSpeed);
      }

      // Then close the thumb
      for (int i = 45; i <= 150; i++)
      {
        Thumb.write(i);
        ThumbPos = i;
        delay(HandSpeed);
      }
    }
    // Check if hand is CLOSED
    else if (ThumbPos == 150 && IndexPos == 150 && MiddlePos == 150 &&
             RingPos == 150 && LittlePos == 150)
    {
      // Open thumb first
      for (int i = 150; i >= 45; i--)
      {
        Thumb.write(i);
        ThumbPos = i;
        delay(HandSpeed);
      }

      // Then open all fingers
      for (int i = 150; i >= 45; i--)
      {
        Index.write(i);
        Middle.write(i);
        Ring.write(i);
        Little.write(i);

        IndexPos = MiddlePos = RingPos = LittlePos = i;
        delay(HandSpeed);
      }
    }
  }
  else
  {
    // If button is not pressed, maintain current position
    Thumb.write(ThumbPos);
    Index.write(IndexPos);
    Middle.write(MiddlePos);
    Ring.write(RingPos);
    Little.write(LittlePos);
  }
}

// ============================================================
// BLUETOOTH CONTROL MODE
// Commands:
//   T - Toggle Thumb
//   I - Toggle Index
//   M - Toggle Middle
//   R - Toggle Ring
//   L - Toggle Little finger
//   H - Toggle whole hand open/close
// ============================================================
void BLUETOOTH()
{
  if (mySerial.available())
  {
    char data = mySerial.read();
    int i;

    // --------------------------------------------------------
    // Individual finger toggles
    // --------------------------------------------------------
    if (data == 'T')
    {
      if (ThumbPos == 45)
        for (i = 45; i <= 150; i++) { Thumb.write(i); ThumbPos = i; delay(fingerSpeed); }
      else
        for (i = 150; i >= 45; i--) { Thumb.write(i); ThumbPos = i; delay(fingerSpeed); }
    }

    else if (data == 'I')
    {
      if (IndexPos == 45)
        for (i = 45; i <= 150; i++) { Index.write(i); IndexPos = i; delay(fingerSpeed); }
      else
        for (i = 150; i >= 45; i--) { Index.write(i); IndexPos = i; delay(fingerSpeed); }
    }

    else if (data == 'M')
    {
      if (MiddlePos == 45)
        for (i = 45; i <= 150; i++) { Middle.write(i); MiddlePos = i; delay(fingerSpeed); }
      else
        for (i = 150; i >= 45; i--) { Middle.write(i); MiddlePos = i; delay(fingerSpeed); }
    }

    else if (data == 'R')
    {
      if (RingPos == 45)
        for (i = 45; i <= 150; i++) { Ring.write(i); RingPos = i; delay(fingerSpeed); }
      else
        for (i = 150; i >= 45; i--) { Ring.write(i); RingPos = i; delay(fingerSpeed); }
    }

    else if (data == 'L')
    {
      if (LittlePos == 45)
        for (i = 45; i <= 150; i++) { Little.write(i); LittlePos = i; delay(fingerSpeed); }
      else
        for (i = 150; i >= 45; i--) { Little.write(i); LittlePos = i; delay(fingerSpeed); }
    }

    // --------------------------------------------------------
    // Whole-hand toggle ('H')
    // --------------------------------------------------------
    else if (data == 'H')
    {
      // Is the hand OPEN?
      if (ThumbPos == 45 && IndexPos == 45 && MiddlePos == 45 &&
          RingPos == 45 && LittlePos == 45)
      {
        // Close four fingers first
        for (i = 45; i <= 150; i++)
        {
          Index.write(i);
          Middle.write(i);
          Ring.write(i);
          Little.write(i);
          IndexPos = MiddlePos = RingPos = LittlePos = i;
          delay(HandSpeed);
        }

        // Close thumb
        for (i = 45; i <= 150; i++)
        {
          Thumb.write(i);
          ThumbPos = i;
          delay(HandSpeed);
        }
      }

      // Is the hand CLOSED?
      else if (ThumbPos == 150 && IndexPos == 150 && MiddlePos == 150 &&
               RingPos == 150 && LittlePos == 150)
      {
        // Open thumb first
        for (i = 150; i >= 45; i--)
        {
          Thumb.write(i);
          ThumbPos = i;
          delay(HandSpeed);
        }

        // Open the rest
        for (i = 150; i >= 45; i--)
        {
          Index.write(i);
          Middle.write(i);
          Ring.write(i);
          Little.write(i);
          IndexPos = MiddlePos = RingPos = LittlePos = i;
          delay(HandSpeed);
        }
      }
      else
      {
        // Mixed finger positions — whole-hand action not possible
        mySerial.println("Err: Position of all fingers are not same");
      }
    }
  }
}
