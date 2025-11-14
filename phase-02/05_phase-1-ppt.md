Prosthetic Arm – Phase 1 Review


---

Slide 1: Introduction

Slide Content:

Prosthetic arms as assistive technology

Muscle signals as natural control inputs

Towards an affordable, Arduino-based design


Notes:
Prosthetic technology has come a long way, but many devices remain out of reach because of their cost and complexity. A natural way forward is to make control more intuitive — instead of switches or buttons, the user’s own muscle signals can guide the arm. Our project explores this idea by combining EMG sensors with Arduino. The aim is to keep it simple, cost-effective, and replicable, so it isn’t just a lab prototype but a step toward something accessible.


---

Slide 2: Problem Statement

Slide Content:

Conventional prosthetics: high cost, limited accessibility

Need for muscle-driven, intuitive alternatives

Design challenge: Arduino-controlled EMG prosthetic


Notes:
The problem is not that prosthetic arms don’t exist — it’s that many people who need them can’t afford them or find them too limited. We want to design a prosthetic system that listens directly to muscle activity, processes it, and converts it into movement. Using Arduino helps us balance performance with affordability, since it’s open-source, flexible, and widely supported.


---

Slide 3: Objectives

Slide Content:

1. To design a prosthetic arm with integrated EMG sensor to measure muscle activity.
2. To integrate with Arduino for signal processing and motor control.
3. Design a basic enclosure using 3D printing.


Notes:
The project has three objectives. First, detect muscle activity reliably through EMG sensors. Second, process these signals in real time using Arduino and use them to control motors for movement. Third, design a housing for the electronics and mechanics — using 3D printing to keep the enclosure lightweight, customizable, and cost-effective.


---

Slide 4: Literature Survey

Slide Content:

Advanced myoelectric prosthetics: effective but expensive

Academic research confirms EMG → motor actuation

Identified gap: low-cost, modular designs for real-world use


Notes:
Looking at existing prosthetic arms, especially myoelectric ones, the technology clearly works. EMG signals have already been shown to control motors successfully. But the challenge remains accessibility — commercial solutions often cost thousands of dollars, and even academic models can be too complex. The opportunity lies in bridging this gap: making something affordable, modular, and adaptable that still demonstrates meaningful control.


---

Slide 5: Block Diagram

Slide Content:

flowchart TD
    A[Muscle Contraction] --> B[EMG Sensor & Electrodes]
    B --> C[Signal Conditioning<br/>Amplification + Filtering]
    C --> D[Arduino Microcontroller<br/>Feature Extraction & Thresholding]
    D --> E[Motor Driver Circuit]
    E --> F[Servo/Stepper Motors]
    F --> G[Prosthetic Arm Mechanism]
    G -.->|Feedback| D
    D --> H[3D Printed Enclosure<br/>Integration & Housing]
    H --> I[Final Prosthetic Arm]

Notes:
The flow begins with muscle contractions, which generate weak electrical signals. EMG sensors with electrodes detect these signals, but they are too noisy to be used directly. That’s where signal conditioning comes in — amplification and filtering clean them up. The Arduino then processes the data, applies thresholds, and determines when to activate movement. This output goes through a motor driver circuit, which powers servo or stepper motors. The motors create mechanical motion in the prosthetic arm. There’s also a feedback path — Arduino can adjust control based on motion response. Finally, everything is housed in a 3D-printed enclosure, giving us the full prototype.


---

Slide 6: Basic Components Used

Slide Content:

EMG sensor with surface electrodes

Arduino Uno / Nano controller

Motor driver IC (L293D / equivalent)

Servo or stepper motors for actuation

Power supply unit

3D-printed frame and joints


Notes:
The backbone of this project is a few essential components. EMG sensors capture muscle activity via surface electrodes. Arduino boards — either Uno or Nano — handle processing and decision-making. Motor drivers like L293D provide the necessary current to actuators. For movement, servo or stepper motors are used because they give precise angular control. A power supply ensures stable operation. And finally, the entire system is held together in a 3D-printed frame, allowing flexibility in design and adjustments.


---

Slide 7: Expected Outcome

Slide Content:

A functional, Arduino-controlled prosthetic prototype

Real-time EMG-driven movement

Affordable, adaptable design for future expansion


Notes:
The expected outcome is a working prosthetic arm that responds to muscle signals. It should demonstrate the feasibility of real-time EMG-driven movement. Just as importantly, it will showcase that such a design can be achieved with low-cost, open-source components. The design is modular — leaving room for improvements like multi-gesture mapping, wireless connectivity, or AI-based signal classification in future phases.


---


