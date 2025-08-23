# Prosthetic Arm Design Alternatives

After reviewing multiple open-source designs, research papers, and project case studies, the following three approaches were shortlisted.  
These alternatives focus on achieving a **working, modular prosthetic arm** while keeping the design concise, cost-effective, and within the project scope.

---

## **Alternative 1 — Single-Motor Underactuated Hand (3-Finger Design)**

**Concept:**  
A 3-fingered hand where a **single DC servo motor** drives all fingers using a tendon-based underactuated mechanism. Elastic bands or springs return the fingers to their open position when the motor relaxes. This approach balances **functionality**, **cost**, and **build simplicity**.

**Key Features:**
- Uses **one actuator** to control multiple fingers.
- **Tendon-driven mechanism** for power grip and basic pinch.
- Modular palm structure with **removable drive module**.
- EMG-controlled or button-controlled input.

**Advantages:**
- Lower cost compared to multi-motor hands.
- Looks close to an actual prosthetic hand.
- Modular design allows upgrading later (e.g., adding a second tendon for more grips).
- Easier tuning and debugging.

**Limitations:**
- Limited to one primary grip mode.
- Finger independence is restricted.

**Example Use-Cases:**
- Holding a water bottle.
- Picking and placing small objects.
- Pressing switches or buttons.

---

## **Alternative 2 — Body-Powered Prosthetic Hand**

**Concept:**  
A fully **mechanical approach** where the hand or claw is operated using a **cable-driven harness system**. The user’s shoulder or arm movement pulls a cable that closes the fingers or claw, while springs or elastics return them to an open state. No electronics are required.

**Key Features:**
- **Harness-based actuation** using Bowden cables.
- Simple, lightweight mechanical design.
- Uses a 3-finger claw or hook for gripping.
- Designed to handle moderate weights reliably.

**Advantages:**
- **Low cost** and quick to fabricate.
- Extremely reliable and easy to maintain.
- No dependency on sensors, batteries, or controllers.
- Ideal for validating grip mechanics before adding electronics.

**Limitations:**
- Limited flexibility in grip patterns.
- Requires the user’s shoulder or arm movement to operate.
- Less “modern” appearance compared to myoelectric solutions.

**Example Use-Cases:**
- Carrying lightweight bags or bottles.
- Pulling door handles.
- Holding simple tools securely.

---

## **Alternative 3 — Passive Prosthetic Hand**

**Concept:**  
A **non-actuated, compliant hand** designed purely for **holding or stabilizing objects** without active control. It uses carefully tuned **spring mechanisms, friction pads, and compliant fingers** to maintain grip once the object is placed manually.

**Key Features:**
- Compliant finger design for passive holding.
- Adjustable springs to tune grip strength.
- Lightweight, fully 3D-printable structure.
- Designed to prioritize simplicity and speed of build.

**Advantages:**
- Fastest and cheapest prototype option.
- Very low failure risk since no active components are involved.
- Useful for early-stage testing of finger compliance and ergonomics.

**Limitations:**
- Cannot perform active tasks or controlled grips.
- Limited to holding pre-placed objects.
- Lower overall functionality compared to other alternatives.

**Example Use-Cases:**
- Stabilizing a cup or bottle while walking.
- Holding small items in place.
- Basic demonstrations of finger design and load capacity.

---

## **Summary**

| **Criteria**         | **Alternative 1** <br>(Single-Motor) | **Alternative 2** <br>(Body-Powered) | **Alternative 3** <br>(Passive) |
|----------------------|--------------------------------------|--------------------------------------|---------------------------------|
| **Complexity**       | Moderate                            | Low                                  | Very Low                        |
| **Cost**            | Medium (~₹4k–₹6k)                   | Low (~₹2k–₹3k)                       | Lowest (<₹2k)                   |
| **Control Method**   | EMG/button-based                    | Harness-driven                      | Manual placement               |
| **Grip Options**     | Power + basic pinch                 | Basic claw grip                     | Passive hold only              |
| **Timeline**         | ~3 weeks                            | ~2 weeks                            | ~1 week                        |
| **Modularity**       | High                                | Medium                              | Low                            |

---
