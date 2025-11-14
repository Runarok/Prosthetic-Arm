# Prosthetic Arm Project — Feasibility & Design Notes

## Objective Overview

Designing a basic prosthetic arm capable of controlled gripping using EMG-based muscle sensing integrated with Arduino for signal processing and motor control. The arm will be housed inside a 3D-printed enclosure designed for comfort and modularity.

---

## 1. EMG-Based Muscle Activity Sensing

### Goal

Use an EMG (Electromyography) sensor to measure muscle activity and convert it into control signals for the prosthetic arm.

### Feasibility Insights

**Sensor Choice:**

- **Recommended:** MyoWare Muscle Sensor v3.0  
- **Cost:** ~₹1,500 – ₹1,700  
- **Available at:** Robu.in, Thingbits, RDL Technologies (Bengaluru)  
- **Power:** 3.3–5V, directly compatible with Arduino  
- **Output:** Analog voltage proportional to muscle activity

**Why MyoWare:**

- Simple integration, onboard filtering, good documentation.
- Compact, designed for wearable projects.

**Signal Characteristics:**

- EMG signals are low amplitude (~0.5 mV to 5 mV raw).
- The MyoWare sensor amplifies and smooths these to 0–3.3V or 0–5V outputs.

**Placement:**

- Attachable to the forearm or bicep muscles.
- Requires skin contact; better results with proper electrode placement.

### Integration Considerations

**Noise Filtering:**
EMG signals are naturally noisy. Built-in filters in MyoWare handle basic smoothing, but physical stability matters:

- Minimize wire movement.
- Maintain firm electrode-skin contact.

**Reliability Factors:**

- Dry skin or sweat can affect readings.
- Electrode quality matters for stability.
- Single-muscle sensing = simple control, but less precise than multi-sensor setups.

---

## 2. Arduino Integration for Signal Processing & Motor Control

### Goal

Use Arduino as the central controller to:

- Read EMG signals.
- Process threshold-based actions.
- Drive motors to open/close the prosthetic grip.

### Feasibility Insights

**Board Options:**

- **Arduino Nano** — compact, cheap (~₹400–₹500).
- **Arduino Uno** — easier for prototyping (~₹600–₹700).
- **Teensy 4.0** — optional upgrade if faster sampling needed (~₹2,000+).

**Motor Control Needs:**

- Single actuator is sufficient for simple grip (open/close).
- For smoother motion, use PWM-based control.
- Motor driver may not be required if using RC servos directly.

**Why Arduino:**

- Built-in analog inputs for EMG signal.
- PWM pins for servo/motor control.
- Huge community and libraries for prototyping.

### Integration Challenges

- EMG signals vary between individuals → requires calibration.
- Motor power draw can cause voltage dips → requires proper power isolation.
- Latency is negligible (<50ms) if thresholds are simple.

---

## 3. Enclosure Design Using 3D Printing

### Goal

Create a lightweight, ergonomic enclosure to house the electronics, motor, and gripper assembly.

### Feasibility Insights

**Material Choices:**

- **PLA:**
  - Easy to print, affordable, biodegradable.
  - **Cost:** ₹1,200–₹1,500 per kg.
  - **Downsides:** Lower heat resistance.

- **ABS:**
  - Stronger, better for load-bearing.
  - **Cost:** ₹1,400–₹1,700 per kg.
  - **Downsides:** Requires controlled print environment.

- **TPU (Optional for soft padding):**
  - Flexible, ideal for grip pads.
  - **Cost:** ₹1,500–₹1,800 per kg.

**Design Considerations:**

- Enclosure should have modular compartments:
  - Motor housing.
  - EMG sensor access points.
  - Easy wiring channels.

- Comfort and weight balance are critical:
  - **Ideal total weight:** <800g for comfort.

- Ventilation slots recommended for electronics.

**Bengaluru Options:**

- **Local makerspaces:** Fablab, Workbench Projects, IKP Eden.
- **Online:** 3Ding, Fracktal Works, Thingbits.

---

## 4. Cost & Material Availability — Bengaluru

| Component        | Example Model       | Approx. Cost (₹) | Where to Buy                         |
|------------------|---------------------|------------------|--------------------------------------|
| EMG Sensor       | MyoWare v3.0        | 1,500–1,700      | Robu.in, Thingbits, RDL              |
| Arduino Board    | Nano / Uno          | 400–700          | SP Road, Robu.in                     |
| Servo Motor      | DS3218 / DS3235     | 1,200–2,000      | SP Road, Robu.in                     |
| LiPo Battery     | 7.4V, 2200mAh       | 600–900          | Robu.in, SP Road                     |
| PLA Filament     | 1kg, 1.75mm         | 1,200–1,500      | 3Ding, Thingbits                     |
| 3D Printing Service | External         | 800–1,500 per prototype | Fracktal, Workbench Projects |

> Tip: For quick prototyping, SP Road (Bengaluru) has most electronic parts.

---

## 5. Key Risks & Constraints

| Aspect           | Risk/Constraint                  | Mitigation Strategy                          |
|------------------|----------------------------------|----------------------------------------------|
| EMG Signal Quality | Noise, sweat, loose electrodes | Use shielded cables + proper placement       |
| Power Handling   | Servo draws high current         | Use separate regulator + capacitor buffer    |
| Weight           | Overweight prosthetic            | Use PLA + hollow sections in design          |
| Printing Issues  | Poor tolerances                  | Outsource to professional service initially  |
| Calibration      | Varies per user                  | Adjustable thresholds in firmware            |

---

## 6. Clarifications for Project Guide

1. **Sensor Calibration** →  
   “Is a single EMG sensor sufficient for this project, or should we plan for dual-sensor input for better control?”

2. **Motor Torque** →  
   “What range of torque should be targeted for the grip — enough to hold a lightweight bottle or something stronger?”

3. **Enclosure Requirements** →  
   “Should the enclosure focus purely on function, or are there form/appearance constraints?”

4. **Testing Expectations** →  
   “Are there any specific test cases we must demonstrate — e.g., object lifting, response speed, etc.?”

5. **Power Guidelines** →  
   “Do we have preferred battery specs or safety limits to follow?”

---

## Summary

The project is feasible within **5–7k** budget, uses readily available components in Bengaluru, and can be built incrementally:

- **Phase 1:** EMG + Arduino integration (signal to servo).
- **Phase 2:** Gripper mechanism + enclosure.
- **Phase 3:** Calibration, safety, and testing.

This approach minimizes technical risk while delivering a functional demo.
