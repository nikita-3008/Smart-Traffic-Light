# Smart-Traffic-Light
Arduino-based Smart Traffic Light with Pedestrian &amp; Vehicle Sensing
---

# **Smart Traffic Light System using Arduino**  

## **Overview**  
This project implements a **Smart Traffic Light System** using an **Arduino Uno**, LEDs, a push button for pedestrian crossing, and an ultrasonic sensor for vehicle detection. The system aims to optimize traffic control by ensuring pedestrian safety and reducing unnecessary power usage.  

## **Project Features**  
### **Basic Traffic Light System **  
- Simulates a **real traffic light cycle**: **Green → Yellow → Red → Green**.  
- A **push button** allows pedestrians to stop traffic by turning the light Red for safe crossing.  

### **Smart Traffic Light System **  
- **Ultrasonic Sensor (HC-SR04)** detects vehicles at the signal.  
- If no vehicle is detected for **30 seconds**, the light remains **Red** to save power.  
- If a vehicle is detected, the normal traffic cycle resumes.  

## **Required Components**  
- **Arduino Uno**  
- **Red, Yellow, Green LEDs**  
- **3 × 220Ω resistors** (for LEDs)  
- **Push button** (for pedestrian crossing)  
- **10kΩ resistor** (for push button)  
- **Ultrasonic Sensor (HC-SR04)** (for vehicle detection)  
- **Breadboard & jumper wires**  

## **Circuit Diagram**  
(Include an image of your circuit diagram here.)  

## **Working**  

### **Basic Traffic Light System**  
1. The system starts in a **normal traffic light cycle**.  
2. If the **pedestrian button** is pressed, the system immediately turns **Red** to allow crossing.  
3. After a few seconds, the normal traffic cycle resumes.  

### **Smart Traffic Light System**  
1. If **no vehicle is detected**, the light stays **Red** to conserve power.  
2. If a **vehicle is detected** (distance < threshold), the traffic light follows the **normal cycle**.  
3. The **pedestrian button** can override the cycle for safe crossing.  

## **Installation & Setup**  
1. **Clone the Repository**  
```sh
git clone https://github.com/yourusername/smart-traffic-light.git
cd smart-traffic-light
```
2. **Upload the Code to Arduino**  
- Open **Arduino IDE**.  
- Connect the **Arduino Uno** to your PC.  
- Open `smart_traffic_light.ino`.  
- Select the correct **Board & Port** in Arduino IDE.  
- Click **Upload**.  

3. **Connect the Circuit**  
- Assemble the circuit using a **breadboard** and **connect all components** as per the diagram.  

## **Code Explanation**  
- Uses `digitalWrite()` to control LED states.  
- Uses `digitalRead()` to check button presses.  
- Uses **HC-SR04 ultrasonic sensor** to measure distance and detect vehicles.  
- Implements a **state machine** for traffic control logic.  

## **Demo Video**  
(Add a link to your demo video here.)  

## **Future Improvements**  
- Add **Real-time Clock (RTC)** to adjust signals based on time of day.  
- Implement **wireless communication** between traffic lights.  
- Use **machine learning** for adaptive traffic control.  
