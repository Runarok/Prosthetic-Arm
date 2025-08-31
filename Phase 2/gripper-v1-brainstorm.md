## System Overview

A single-actuator two-jaw gripper with **three operational modes**:

1. **NTG (Idle/Open)** – jaws open, minimal power.
2. **HOLD (Light Grip)** – gentle force, maintains object position.
3. **TIGHTEN (Strong Grip)** – increased force, secure hold.

Mechanism uses one high-torque servo or linear actuator. Force feedback is sensed via an FSR, enabling threshold-based grip control.

---

## Actuator Selection

### Option A – High-Torque RC Servo *(recommended for fast prototyping)*

* Models: **DS3235 / DS3218**
* Stall torque: 20–35 kg·cm (≈2–3.5 Nm)
* Voltage: 6–7.4 V
* Pros: Simple 3-wire PWM control, position hold without complex code.
* Cons: No native torque control; requires timeouts and current limiting.

### Option B – Smart Servo *(cleaner control)*

* Model: **Dynamixel XM430-W350**
* Stall torque: ≈3–4 Nm @ 12 V
* Features: Built-in position, velocity, and current/torque limits.
* Pros: Direct torque mode, daisy-chain wiring, reliable performance.
* Cons: Higher cost, 12 V supply required.

### Option C – Linear Actuator *(compact squeeze)*

* Models: **Actuonix L12-R / L16-R**
* Force: 50–100 N (model-dependent)
* Stroke: 30–50 mm
* Pros: Clean motion, inherently self-locking.
* Cons: Slower, lower speed-to-force ratio.

**Recommendation:** For minimal setup time → **DS3235 high-torque servo**.

---

## Sensing Setup

### Force Feedback

* Sensor: **FSR 402**
* Placement: Under jaw or fingertip pad.
* Wiring: Voltage divider with 10 kΩ resistor → analog input.
* Purpose: Detects **light grip** vs **tight grip** thresholds.

### Position Feedback

* Source: Servo’s internal angle from commanded PWM.
* Optional: Use **AS5600/AS5048 magnetic encoder** for absolute jaw angle.

### User Input

* One momentary **pushbutton** to cycle NTG → HOLD → TIGHTEN.
* Optional: EMG control via **MyoWare 2.0** (skip initially).

---

## Control Electronics

* **MCU:** Arduino Nano (basic) or Teensy 4.0 (higher headroom).
* **Power Supply:**

  * Battery: **2S LiPo (7.4 V, ≥1500 mAh)**.
  * BEC: **6.0–7.4 V @ ≥5 A** for servo rail.
  * Separate buck regulator **5 V/1 A** for MCU and sensors.
* **Protection Components:**

  * Inline fuse: 5–7.5 A
  * Low-ESR capacitor: 470–1000 µF across servo supply
  * Optional TVS diode for transient suppression.

---

## Control Logic

### NTG Mode (Idle/Open)

* Jaw angle → `openAngle`.
* Servo torque minimized or disabled.
* Motor detached after short delay.

### HOLD Mode (Light Grip)

* Servo closes until **FSR ≥ F\_hold**.
* Position maintained.
* Micro-adjusts +1–2° if slipping detected.
* Low current limit to conserve power.

### TIGHTEN Mode (Strong Grip)

* Higher threshold **F\_tight** applied.
* Servo increases angle stepwise until FSR ≥ F\_tight or timeout reached.
* Backoff by 2–3° after stall detection.

---

## Reference Values

| Parameter       | Value         | Notes                    |
| --------------- | ------------- | ------------------------ |
| `openAngle`     | \~20°         | Fully open jaw position  |
| `closeAngleMax` | \~140°        | Physical stop limit      |
| `F_hold`        | \~0.2–0.4 V Δ | Light grip threshold     |
| `F_tight`       | \~2× F\_hold  | Tight grip threshold     |
| Stall timeout   | 700 ms        | Avoids servo overheating |

---

## Mechanical Setup

* **Two-Jaw Gripper:** One fixed jaw, one moving jaw on hinge.
* **Drive Method:** Servo horn → crank or GT2 belt → jaw linkage.
* **Self-Locking Geometry:** Slight over-center bias to reduce holding torque.
* **Grip Pads:** Rubber or TPU to improve friction, reduce required force.

---

## Wiring Layout

* Servo: powered from **BEC** → servo rail + capacitor.
* MCU: powered from **5 V regulator**.
* Common ground between MCU, BEC, and sensors.
* FSR → voltage divider → Arduino A0.
* Pushbutton → digital input with pull-up resistor.

---

## Starter BOM

| Component            | Qty | Example Model     |
| -------------------- | --- | ----------------- |
| High-torque RC servo | 1   | DS3235            |
| Microcontroller      | 1   | Arduino Nano      |
| Battery              | 1   | 2S LiPo 1500 mAh  |
| BEC                  | 1   | 6 V 5–7.5 A       |
| FSR sensor           | 1   | FSR 402           |
| Pushbutton           | 1   | Generic           |
| Capacitor            | 1   | 470–1000 µF ≥10 V |
| Resistor             | 1   | 10 kΩ             |

---

## Control Pseudocode

```cpp
enum Mode { NTG, HOLD, TIGHTEN };
Mode mode = NTG;

const int PIN_SERVO = 9;
const int PIN_FSR   = A0;
const int PIN_BTN   = 2;

int openAngle = 20;
int closeAngleMax = 140;
int fsrHold = 300;
int fsrTight = 600;
int step = 1;
unsigned long stallTimeout = 700;

void loop() {
  static unsigned long lastMoveMs = 0;
  static int angle = openAngle;
  int fsr = analogRead(PIN_FSR);

  if (buttonPressed()) mode = nextMode(mode);

  switch (mode) {
    case NTG:
      angle = approach(angle, openAngle, 2);
      writeServo(angle);
      break;

    case HOLD:
      if (fsr < fsrHold && angle < closeAngleMax) {
        angle += step;
        writeServo(angle);
        lastMoveMs = millis();
      } else if (fsr > fsrHold && millis() - lastMoveMs > stallTimeout) {
        angle -= 1;
        writeServo(angle);
      }
      break;

    case TIGHTEN:
      if (fsr < fsrTight && angle < closeAngleMax) {
        angle += step;
        writeServo(angle);
        lastMoveMs = millis();
      }
      if (millis() - lastMoveMs > stallTimeout && fsr >= fsrTight) {
        angle -= 1;
        writeServo(angle);
      }
      break;
  }
}
```

---

## Safety Constraints

* Hardware and software **hard stops** at jaw limits.
* Stall timeout to avoid servo burnout.
* Long-press button → force NTG mode (emergency release).
* Low-voltage cutoff for LiPo battery protection.
* Monitor actuator temperature; pause if overheated.

---

