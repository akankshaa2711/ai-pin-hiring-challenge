# ai-pin-hiring-challenge
Wearable AI Pin – Hardware + Firmware assignment

**Name: Akanksha Rani**
**Email: Akanksharani777@gmail.com**

---

## Part 1: Hardware & Architecture

### Question 1: Always-Listening Problem
Core B handles wake-word detection because it is low power and can stay active continuously.
When the wake word is detected, Core B wakes up Core A.Core A then handles audio processing and cloud upload over Wi-Fi.This minimizes battery usage because the high-power core is active only when required.

---

### Question 2: Memory Calculation (Audio Buffer)
Given:
Sample rate = 16 kHz
Bit depth = 16 bits = 2 bytes
Mono Duration = 10 seconds
Available RAM = 256 KB 

#calculation:-
Samples per second = 16,000
Bytes per sample = 2
Bytes per second = 16,000 × 2 = 32,000 bytes
10 seconds = 32,000 × 10 = 320,000 bytes
                         =320,000 ÷ 1024 ≈ 312.5 KB


#### Question 3: Privacy Hardware 
The hard mute switch should be wired in series with the microphone power supply (VCC).
When the switch is OFF, power is physically disconnected from the microphone.
Even if software crashes or behaves incorrectly, the microphone cannot turn on, ensuring absolute privacy.
