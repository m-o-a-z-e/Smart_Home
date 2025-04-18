# Smart_Home
1. Introduction 
Smart Home System - Project Documentation 
This project presents a basic Smart Home System designed to enhance home safety and automation using a 
range of sensors and modules. The system provides real-time environmental monitoring, intrusion detection, 
gas leak alerts, and Bluetooth-based lighting control. 
2. Objectives - To develop a low-cost, efficient smart home prototype. - To monitor environmental parameters such as gas concentration and temperature. - To detect motion or unauthorized presence. - To provide both visual and audible alerts in emergency situations. - To implement remote lighting control using Bluetooth communication. 
3. Components and Modules 
3.1. I2C LCD Display 
Used to display real-time data such as temperature, gas levels, and warning messages when any abnormal 
condition is detected. 
3.2. MQ-5 Gas Sensor 
Continuously monitors gas levels. In the event of a gas leak, it triggers a visual warning on the LCD and 
activates the buzzer. 
3.3. LM35 Temperature Sensor 
Measures ambient temperature and displays it in real-time on the LCD. 
3.4. Infrared (IR) Sensor 
Detects motion or nearby presence and triggers an alert if movement is detected. 
3.5. Ultrasonic Sensor 
Defines a virtual "safe zone" around the monitored area. If an object enters this zone, an alarm is activated. 
Smart Home System - Project Documentation 
3.6. Bluetooth Module (e.g., HC-05) 
Enables wireless communication between the system and a smartphone. Used to control lighting remotely 
through Bluetooth commands. 
3.7. LEDs / Lights 
Controlled remotely via Bluetooth to simulate home lighting automation. 
3.8. Buzzer 
Provides audible alerts for gas detection, intrusion, or unauthorized motion. 
4. System Features - Environmental Monitoring: Real-time tracking of temperature and gas levels. - Intrusion Detection: Alerts triggered by motion or object detection. - Visual and Audio Alarms: Critical warnings are displayed on the LCD and indicated through buzzer sounds. - Bluetooth Lighting Control: Enables users to control lights using a smartphone app or serial interface. - Modular Design: The system is designed to be expandable with additional sensors or smart features. 
5. Conclusion 
The proposed smart home prototype provides a practical and affordable solution to enhance home security and 
automation. By integrating simple electronic components and wireless control, the system demonstrates the 
potential of IoT-based home monitoring with real-time alerts and remote functionality. 
