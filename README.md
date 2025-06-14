# STM32 GPIO Control - Bare-Metal Programming

This project demonstrates how to control GPIO pins (PA5, PA10, PB8, PC8, PD2) on an STM32 microcontroller using bare-metal programming without any HAL or library abstractions.

---

## 🔧 Hardware

- **Microcontroller**: STM32 (e.g., STM32F4 series)
- **LEDs** connected to:
  - **Port A, Pin 5 (PA5)**
  - **Port A, Pin 10 (PA10)**
  - **Port B, Pin 8 (PB8)**
  - **Port C, Pin 8 (PC8)**
  - **Port D, Pin 2 (PD2)**

---

## 📂 Project Structure

- `main.c`: Main source file where peripheral base addresses are defined and GPIO control is implemented using memory-mapped registers.
- No external dependencies (pure register-level coding).

---

## 🧠 Key Concepts

- Enabling GPIO clocks via **RCC_AHB1ENR**
- Configuring GPIO mode register to set pins as output
- Writing to **GPIOx_ODR** to set pins HIGH
- Bare-metal register manipulation using pointers and macros

---

## 🚀 How to Run

1. Open the project in STM32CubeIDE
2. Build and flash the firmware to the target STM32 board
3. Observe all the configured pins (PA5, PA10, PB8, PC8, PD2) set to HIGH (or toggle depending on delay logic you add)

> Note: You may need to connect LEDs to the respective pins with proper resistors to visually confirm output.

---

## 📌 Future Improvements

- Add a delay loop or SysTick timer to blink LEDs
- Implement pin toggling instead of just setting HIGH
- Modularize code for better readability
- Add input pin reading or button handling

---

## 📃 License

This project is provided for educational purposes. Feel free to modify and use it for your experiments.

