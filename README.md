# Match-Ticketing-System
Sports Match Ticketing System 🏟️🎟️

A robust, object-oriented C++ console application for managing sports fixtures and ticket sales.

📖 Overview

This project is a Match Ticketing System designed to facilitate the scheduling of sports fixtures and the sale of tickets to fans. Developed using an Agile methodology, the system simulates a professional engineering workflow, focusing on object-oriented design, persistent storage, and strict adherence to functional requirements.

Current Version: Sprint 1 (MVP)

Status: Active Development

✨ Features (MVP)

👨‍💼 Administrator Mode

Schedule Matches: Create new fixtures by specifying Home Team, Away Team, Stadium, Date, Ticket Price, and Capacity.

Input Handling: Robust support for team/stadium names containing spaces (e.g., "Real Madrid", "Old Trafford").

Validation: Ensures prices and capacities are positive integers.

👤 Fan Mode

View Fixtures: Browse a formatted list of all upcoming matches, including live updates on seat availability.

Book Tickets: Purchase tickets for specific matches.

Inventory Management: System automatically checks seat availability (Capacity - Booked) before confirming a purchase.

💾 System

Data Persistence: All data is saved instantly to CSV files (matches.csv and tickets.csv).

Reliability: Data remains intact even if the application is closed or crashes.

🛠️ Tech Stack

Language: C++ (C++11 or higher recommended)

Architecture: Console Application (CLI) with Object-Oriented Design

Storage: CSV File I/O

Libraries: Standard Template Library (<vector>, <fstream>, <string>, <iostream>)

🚀 Getting Started

Prerequisites

A C++ Compiler (GCC, Clang, or MSVC)

Git

Installation

Clone the repository:

git clone [https://github.com/yourusername/match-ticketing-system.git](https://github.com/yourusername/match-ticketing-system.git)
cd match-ticketing-system


Compile the source code:

g++ *.cpp -o ticketing_system


Run the application:

On Windows:

ticketing_system.exe


On Linux/macOS:

./ticketing_system


📂 Data Storage

The system uses flat-file databases to persist information. These files are automatically updated upon every Schedule or Booking event.

matches.csv: Stores fixture details (ID, Teams, Date, Stadium, Price, Capacity, Booked Count).

tickets.csv: Stores individual ticket transactions (Ticket ID, Match ID, Owner Name).

🗺️ Roadmap

This project follows an iterative Agile development cycle.

Sprint 1 (Current): Basic Console UI, Admin Scheduling, Fan Booking, CSV Persistence.

Sprint 2 (Planned): User Authentication (Login/Register), Seat Selection, Ticket Cancellation.

Sprint 3 (Future): Advanced Search, Dynamic Pricing, GUI Implementation.

📝 License

This project is open-source and available under the MIT License.