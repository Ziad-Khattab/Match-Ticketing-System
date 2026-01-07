# Sports Match Ticketing System (GUI Edition) 🏟️🎟️ 

> A modern, desktop-based C++ application for managing sports matches and booking tickets, built with Qt 6 and CMake.

## 📌 Project Overview

This project simulates a real-world ticketing system using **Object-Oriented Programming (OOP)** principles. Originally a console application, it has been upgraded to a full **Graphical User Interface (GUI)** using the Qt Framework.

It features a secure **Admin Panel** with login protection and a **Fan Zone** for users to browse and book matches dynamically.

---

## ✨ Key Features

### 👤 Fan Zone (User)
* **View Matches:** Real-time table displaying Match IDs, Teams (Codes), Capacity, and Booked Seats.
* **Book Tickets:** Simple interface to book a seat by entering a fan name.
* **Live Updates:** The table updates immediately after a booking to prevent overbooking.
* **My Tickets:** View all tickets booked under a specific name.
* **Validation:** Prevents booking if the match is full or input is invalid.

### 🛡️ Admin Panel (Secure)
* **Authentication:** Secured tab requiring a login (Username/Password) to access.
* **Add Match:** Create new matches with custom ID, Name, and Capacity.
* **Delete Match:** Remove matches (and their tickets) from the system.
* **System Monitoring:** View the status of all matches in a read-only list.

---

## 🛠️ Tech Stack

* **Language:** C++17
* **GUI Framework:** Qt 6 (Widgets Module)
* **Build System:** CMake (3.16+)
* **Platform:** Linux / WSL (Ubuntu 24.04) / Windows

---

## 🚀 Installation & Build Guide

### Prerequisites (Ubuntu / WSL)
Ensure you have the compiler, CMake, and Qt 6 libraries installed.

Run the following in your terminal:
```bash
sudo apt update
sudo apt install build-essential cmake qt6-base-dev qt6-wayland libxkbcommon-dev
git clone [https://github.com/YourUsername/SportsTicketingSystem.git](https://github.com/YourUsername/SportsTicketingSystem.git)
cd SportsTicketingSystem
mkdir build
cd build
cmake ..
make
./SportsTicketing
```
## 📖 How to Use

### 1. Booking a Ticket
1. Launch the app. You will land in the **Fan Zone**.
2. Click on a match in the table to select it.
3. Enter your name in the text box.
4. Click **"Book Selected Match"**.

### 2. Accessing Admin Panel
1. Click the **"Admin Panel"** tab.
2. A security dialog will pop up.
3. Enter Credentials:
   * **Username:** `admin`
   * **Password:** `1234`
4. Upon success, you can add or delete matches.

---

## 📂 Project Structure

```text
/SportsTicketingSystem
│
├── CMakeLists.txt       # Build configuration
├── main.cpp             # Entry point
├── MainWindow.h         # Main GUI logic (Header)
├── MainWindow.cpp       # Main GUI logic (Source)
├── Admin.h / .cpp       # Admin class logic
├── Fan.h / .cpp         # Fan class logic
├── Match.h / .cpp       # Match data structure
└── README.md            # Documentation
