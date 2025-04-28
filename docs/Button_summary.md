# Button Module Overview

The `Button` module provides a simple interface for detecting button presses and triggering actions or events in response. It is designed to work in embedded systems where user input is needed through a physical button.

---

## ⚙️ Features

- Detects button presses with debounce delay
- Sends a notification message upon each valid press
- Uses `INPUT_PULLUP` for internal pull-up resistor configuration

---

## 🛠️ How to Use

1. **Initialization**: Create a `Button` instance by passing:
   - The GPIO pin where the button is connected
   - A unique name for the module

2. **Setup**: Call the `setup()` method to configure the pin as an input with an internal pull-up resistor.

3. **Polling Loop**: Call the `loop()` method regularly (e.g., inside `Arduino::loop()`):
   - It checks for a rising edge (LOW to HIGH) and debounce delay of 500 ms
   - If a valid press is detected, it sends the `"BUTTON_PRESSED"` message via `sendMessage()`

---

## 📦 Integration

- Designed for use with ESP-NOW or similar communication layers
- Works well in systems requiring user-triggered actions (e.g., toggling lights, switching modes)

---

## 🔄 Extendability

- Add long-press or double-press detection
- Extend the message to include the button name or timestamp
- Combine with other modules (e.g., toggling a `BinarySwitch` on press)

---
