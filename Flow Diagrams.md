# **1. High-Level Data Flow**

```mermaid
flowchart LR
A[User Input Button Press or Bluetooth Command] --> B[Arduino Control Logic]
B --> C[Servo Command Generation PWM]
C --> D[Servo Actuation Tendon Pulling]
D --> E[Position Feedback Software State]
E --> B
B --> F[LED Indicators System Status]
```

---

# **2. Bluetooth Command Flow**

```mermaid
flowchart LR
A1[User Sends Command from Smartphone App] --> B1[HC-05 Receives Bluetooth Data]
B1 --> C1[HC-05 Converts to Serial and Sends to Arduino RX]
C1 --> D1[Arduino Reads Serial Buffer]
D1 --> E1[Character Compared with Command Definitions]
E1 --> F1[Execute Matching Servo Function]
F1 --> G1[Servos Move Accordingly]
G1 --> H1[Arduino Sends Confirmation via HC-05]
H1 --> I1[User Sees Feedback in App]
```

---

# **3. Manual Control Flow**

```mermaid
flowchart LR
A2[User Presses Push Button] --> B2[Arduino Detects Button State Change]
B2 --> C2[Check Current Finger Positions]
C2 --> D2[Determine Action Open or Close]
D2 --> E2[Execute Coordinated Movement Sequence]
E2 --> F2[Update Position Variables]
F2 --> G2[Return to Idle State]
```

---
