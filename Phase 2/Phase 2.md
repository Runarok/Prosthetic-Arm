## **Core Objective**

> Build a **modular, muscle-controlled prosthetic arm** with basic grip functionality using a single EMG sensor, 3D-printed parts, and high-torque servos — ready for demo in 6–8 weeks, optimized for minimal working hours.

---

## **Modular Prosthetic Arm — Project Overview**

### **Primary Goal:**

Design and build a **functional, modular prosthetic arm** that:

* Is controlled by a **single EMG sensor** to trigger basic grip actions.
* Has **interchangeable components** — hand, wrist, and socket should be easily swappable.
* Uses **affordable, off-the-shelf parts** and **3D-printed structural elements**.
* Is **reliable** and **simple enough to build under time and resource constraints**.
* Includes a **backup joystick mode** to ensure a working prototype, even if EMG control takes longer than expected.

---

## **Simplified, Fast-Track Objectives**

1. **Modular Design:** Create a frame with swappable hand, wrist, and socket modules.
2. **Simple EMG Control:** Map 1 EMG channel to 3 grip modes — open, pinch, strong.
3. **Tendon-Driven Fingers:** Use tendons to reduce complexity and move motors to the forearm.
4. **Parallel Development:** Split mechanical, electrical, and firmware work to build concurrently.
5. **Early Prototype First:** Complete a rough working prototype by **Week 4**, then refine.
6. **Joystick Fallback:** Add a joystick-based control mode as a backup for guaranteed functionality.
7. **Prioritize Functionality:** Focus on getting it working — avoid overengineering CAD or wiring.

---

## **Core Principles**

1. **Modular First** – Arm is split into independent sections (socket, forearm, wrist, hand). If one module fails, you can replace it without redoing the whole arm.
2. **Simplicity Over Complexity** – Single EMG channel → 3 preset grip states instead of full finger-by-finger control.
3. **Parallel Work** – Mechanics, electronics, and firmware can be done in parallel by different people to save time.
4. **Early Success** – Get a working mechanical + joystick-controlled arm by mid-project, then layer EMG control on top.
5. **Fail-Safe** – Always keep a joystick backup so there’s no risk of demo failure.

---

## **System Overview**

### **Modules**

1. **Socket/Interface** – Attaches to the user or demo rig. Has mounting for electronics and battery access.
2. **Forearm Shell** – Hollow casing for servos, wiring, battery, and control board. Designed in two halves for easy assembly.
3. **Wrist Coupler** – Quick-release mechanism for swapping hand/tool modules. Locking pin or bayonet twist design.
4. **Hand / End-Effector** – Starts as a 2–3 finger tendon-driven gripper. Can later be replaced with hooks, utensil holders, or tools.
5. **Control Module** – Arduino/ESP32 board with EMG input, servo outputs, and battery regulation.

---

### **Control Flow**

* **Muscle contraction** → EMG sensor reads electrical activity → Arduino processes signal → Arduino sends PWM commands to servos → Servos pull tendons → Fingers move into preset grip position.
* **Backup Mode:** Joystick sends position values directly to servos.

---

## **Mechanical Design**

* **Forearm Shell:**

  * Length: \~22–25cm (average adult forearm size).
  * Material: PLA+ for speed printing; PETG or Nylon for high-stress parts.
  * Printed in two halves, connected by M3 screws or snap-fit tabs.
  * Cable channels for neat tendon routing and wiring.

* **Finger Mechanism:**

  * Each finger = rigid phalanges connected by flex joints (printed hinges).
  * Nylon fishing line acts as tendon to pull finger closed; elastic cord or spring returns it open.
  * Motors stay in forearm to reduce weight at fingers.

* **Quick-Release Wrist:**

  * Simple male-female coupler with locking pin (can 3D print).
  * Allows swapping between gripper hand, hook, or other tools in seconds.

* **Printing Strategy:**

  * Keep each part’s print time <8 hours so it can be reprinted in a day if it fails.
  * Print in parallel on multiple printers if possible.
  * Start with a small test print of joints to check fit before printing full hand.

---

## **Electronics Design**

* **Controller:** Arduino Nano (easy) or ESP32 (if Bluetooth is needed).
* **Actuators:** 2× DS3218 high-torque servos (20kg/cm torque) for finger control.
* **Sensor:** MyoWare Muscle Sensor v3 — single-channel EMG for simplicity.
* **Power:**

  * 2S LiPo battery (7.4V, 2200 mAh).
  * 5V UBEC regulator to provide stable voltage to servos + Arduino.
  * Toggle switch as emergency cut-off.
* **Wiring:**

  * EMG signal → Arduino analog input.
  * Servos → Arduino PWM pins.
  * Power routed through UBEC to avoid brownouts.
* **Backup Joystick:**

  * Standard thumb joystick module to control open/close in case EMG fails.

---

## **Firmware Logic**

* **EMG Mode:**

  1. Read analog value from EMG.
  2. Compare to thresholds:

     * Low → Open grip
     * Medium → Pinch grip
     * High → Strong grip
  3. Send corresponding angle commands to servos.
* **Joystick Mode:**

  * Map joystick position to servo angles for direct manual control.
* **Safety Features:**

  * Servo angle limits to prevent over-rotation.
  * Delay or debounce to prevent jitter from noisy EMG readings.

---

## **Integration & Safety**

* Keep EMG sensor wires away from servo power wires to reduce noise.
* Calibrate EMG sensitivity per user before mounting in arm.
* Add **mechanical stops** on fingers to avoid snapping tendons.
* Add **software grip-time limit** to prevent servos stalling for long.
* Test everything on a table before putting it on a person.

---

## **Risks & Mitigation**

1. **3D Printing Delays** – Print in smaller parts, keep spares.
2. **Servo Burnout** – Use torque-limiting grip logic in firmware.
3. **EMG Noise** – Shield EMG cables, ensure good skin contact, test with arm still.
4. **Time Pressure** – Build basic working joystick version first.
5. **Team Inactivity** – Break tasks into tiny milestones (e.g., “print finger joints” instead of “finish hand”).

---

## **Parts List (Minimal & Modular)**

* Arduino Nano or ESP32
* MyoWare Muscle Sensor v3 + sensor cables
* 2× DS3218 high-torque servo motors
* 2S LiPo battery (2200 mAh) + charger
* 5V UBEC regulator
* Nylon fishing line (1mm) + PTFE tube for tendons
* PLA+ / PETG / Nylon filament for 3D printing
* JST connectors + wire sleeves
* Toggle switch (emergency cut-off)
* Joystick module (backup control)

---

## **Build Strategy for Busy Students**

1. **Week 1–2:** Design & print forearm, hand, wrist coupler.
2. **Week 3:** Install servos, tendon routing, and joystick control.
3. **Week 4:** You now have a **working arm** with joystick.
4. **Week 5–6:** Add EMG sensor, calibrate thresholds.
5. **Week 7–8:** Polish design, add extra hand tools, finalize demo.

If EMG integration takes longer than expected, that’s okay — by the midpoint, we’ll already have a functional mechanical and electronic prototype. That’s our safety net. The core system will work, and we can always switch to joystick control to ensure a successful demo.

---
