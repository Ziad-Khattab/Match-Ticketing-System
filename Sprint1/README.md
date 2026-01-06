# Sports Match Ticketing System 🏟️🎟️

> A console-based C++ application that allows administrators to manage sports matches and fans to view and book tickets.

The project follows **Agile methodology** and is developed incrementally through sprints, with clearly defined **SMART** requirements.

## 📌 Project Overview

The Sports Match Ticketing System is designed to simulate a basic ticket booking workflow using **Object-Oriented Programming** in C++.

It supports two user roles:
* **Admin:** Manages matches and monitors bookings.
* **Fan:** Views matches and books tickets.

The system runs entirely in the console and uses **in-memory data structures** for storage.

---

## 👥 Stakeholders

### Admin
* Add and delete matches
* View bookings per match

### Fan
* View available matches
* Book tickets
* View personal booked tickets

---

## ⚙️ Functional Requirements (SMART)

### 📅 Sprint 1
* **FR-02: View Matches (Fan)**
    * Display: Match ID, Match code, Available seats
* **FR-03: Book Ticket (Fan)**
    * Book one seat per request
    * Increase booked count upon success
* **FR-04: Prevent Overbooking**
    * Block booking when `booked seats == capacity`
* **FR-05: Generate Ticket**
    * Generate a ticket with: Unique ticket ID, Associated match, Fan name
* **NFR-03: Maintainability**
    * Multi-file OOP structure
    * Separate headers and source files

### 📅 Sprint 2
* **FR-01: Add Match (Admin)**
    * Add a new match with: Unique match ID, Match code, Capacity
* **FR-06: View Booked Tickets (Fan)**
    * Display all tickets booked by a specific fan
* **FR-07: View Match Bookings (Admin)**
    * Display all tickets for a selected match (Show: Ticket ID, Ticket owner)
* **FR-08: Delete Match (Admin)**
    * Delete a match and all associated tickets
* **NFR-01: Usability**
    * Console-based menu, Clear options, Single-word inputs
* **NFR-02: Reliability**
    * Handle invalid input gracefully
    * No crashes or runtime errors

---

## 🧠 Assumptions & Constraints

* **Input:** Contains no spaces (single-word only).
* **Platform:** Console-based application only.
* **Storage:** No database integration; Data stored **in-memory**.
* **Persistence:** CSV or file storage is planned for future sprints.

---

## ✅ Acceptance Criteria

- [x] Admin can add and delete matches
- [x] Fan can view and book tickets
- [x] Overbooking is prevented
- [x] Tickets are correctly linked to matches
- [x] System handles invalid input safely

---

## 🛠️ Technologies Used

* **Language:** C++
* **Paradigm:** Object-Oriented Programming (OOP)
* **Interface:** Command Line Interface (CLI)

---

## 🚀 Future Enhancements

- [ ] File persistence (CSV or database)
- [ ] Login/authentication system
- [ ] Seat selection
- [ ] Match scheduling with date & time
- [ ] GUI version

---

## 📂 Suggested Project Structure

```text
/SportsMatchTicketingSystem
│
├── Match.h / Match.cpp
├── Ticket.h / Ticket.cpp
├── main.cpp
└── README.md