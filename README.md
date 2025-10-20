## 🕹️ ESP32 OLED Dodger Game

A **minimalist 2-button dodging game** built using an **ESP32** and a **0.96" OLED display**.
The player controls a small square that must avoid incoming obstacles.
This project demonstrates basic **game logic**, **input handling**, and **display rendering** on a microcontroller with limited resources.

---

### 🎮 Features

* Controlled with **two buttons** (UP and DOWN)
* **Randomly generated obstacles** that move faster as your score increases
* Simple **collision detection** and **score tracking**
* Built entirely with the **Adafruit SSD1306** and **Adafruit GFX** libraries
* Compact and fun — fits on a breadboard!

---

### 🧩 Components Used

| Component                 | Quantity | Description                        |
| ------------------------- | -------- | ---------------------------------- |
| ESP32-WROOM-32 Dev Board  | 1        | Main microcontroller               |
| OLED Display (0.96" I2C)  | 1        | 128×64 monochrome screen           |
| Push Buttons              | 2        | Player movement inputs             |
| Breadboard & Jumper Wires | –        | For connections                    |
| USB Cable                 | 1        | To upload code and power the ESP32 |

---

### ⚙️ Wiring

| OLED Pin | ESP32 Pin |
| -------- | --------- |
| VCC      | 3.3V      |
| GND      | GND       |
| SDA      | GPIO 21   |
| SCL      | GPIO 22   |

| Button | ESP32 Pin | Other Leg |
| ------ | --------- | --------- |
| UP     | GPIO 27   | GND       |
| DOWN   | GPIO 33   | GND       |

*(Both buttons use `INPUT_PULLUP` mode — no external resistors needed.)*

---

### 🧠 How It Works

* The player square moves up and down based on button input.
* Obstacles spawn from the right and move leftwards.
* Collision is detected via simple bounding box overlap.
* Each avoided obstacle increases your score.
* On collision, “Game Over” appears and you can restart with the UP button.

---

### 🧰 Libraries Used

Make sure to install these from Arduino Library Manager:

* **Adafruit SSD1306**
* **Adafruit GFX Library**

---

### 🚀 Getting Started

1. Open the `.ino` file in Arduino IDE.
2. Select **Board:** “ESP32 Dev Module” and correct **Port**.
3. Upload the code.
4. Press the **UP** or **DOWN** buttons to move your square and dodge obstacles!

---

### 📸 Demo



---

https://github.com/user-attachments/assets/c7bd2774-8fd5-48c8-8a5c-a8aab58e6a9c



### 🧑‍💻 Author

**[Shreyansh Kanojia]**
First-year electronics/computer engineering student exploring embedded systems, IoT, and creative coding.

