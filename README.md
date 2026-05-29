# Gym Management System

> A modular C++ desktop application for managing gym operations — members, coaches, sessions, subscriptions, and facilities — built on Object-Oriented Programming and Data Structures principles.

---

## Table of Contents

- [Overview](#overview)
- [Features](#features)
- [Project Structure](#project-structure)
- [Architecture](#architecture)
- [My Contribution](#my-contribution)
- [Technologies Used](#technologies-used)
- [Getting Started](#getting-started)
- [How to Run](#how-to-run)
- [Database](#database)
- [Author](#author)

---

## Overview

The **Gym Management System** is a C++ console-based desktop application designed to simulate and automate the core operations of a real-world gym. It handles everything from member registration and coach assignments to class scheduling, subscription management, and facility booking.

The project follows a clean **OOP design** with a modular, scalable structure that enforces clear separation of responsibilities across its components.

---

## Features

| Module | Description |
|---|---|
| **Member Management** | Add, update, and manage gym members and their status |
| **Coach Management** | Assign coaches to classes and track their sessions |
| **Class Scheduling** | Create and manage class sessions with booking and availability |
| **Subscription System** | Handle membership plans, renewals, and expiry tracking |
| **Facility Management** | Book and manage padel courts and gym resources |
| **Reporting System** | Generate operational reports and analytics |
| **Role-Based Staff Access** | Admin, Receptionist, Coach, and Staff modules |

---

## Project Structure

```
DS_Project/
│
├── main.cpp                  # Entry point
│
├── Core User Hierarchy
│   ├── person                # Base class
│   ├── member                # Gym member
│   ├── coach                 # Coach management
│   └── staff                 # Staff records
│
├── Staff Roles
│   ├── admin                 # Admin operations
│   └── receptionist          # Front desk management
│
├── System Controller
│   └── gymSystemManager      # Central application logic
│
├── Scheduling & Booking
│   ├── booking.h / booking.cpp   # Booking system (see contribution below)
│   ├── classSession              # Class sessions
│   └── padelCourt                # Padel court management
│
├── Membership
│   └── subscription          # Subscription plans and tracking
│
├── Fitness
│   └── workout               # Workout tracking and logging
│
├── Analytics
│   └── reportGenerator       # Reports and insights
│
└── Utilities
    ├── Date                  # Date utility class
    ├── colors.h              # Console color helpers
    └── common_include.h      # Shared headers and utilities
```

---

## Architecture

The system follows a layered OOP architecture:

```
┌──────────────────────────────────┐
│         main.cpp (Entry)         │
├──────────────────────────────────┤
│       gymSystemManager           │  <- Core Controller
├────────────┬─────────────────────┤
│  User Layer│  Operations Layer   │
│  person    │  booking            │
│  member    │  classSession       │
│  coach     │  padelCourt         │
│  staff     │  subscription       │
│  admin     │  workout            │
│  recept.   │  reportGenerator    │
├────────────┴─────────────────────┤
│         Data / Database Layer    │
│   Members · Bookings · Sessions  │
│   Subscriptions · Staff Records  │
└──────────────────────────────────┘
```

---

## My Contribution

I was responsible for designing and implementing the **Booking System**, which serves as a core operational component of the application.

### Files

- `booking.h` — Class declaration, data members, and function prototypes
- `booking.cpp` — Full implementation of all booking logic

### Responsibilities

- Designed the `Booking` class with all relevant attributes (booking ID, member reference, session details, date, and status)
- Implemented core booking operations: creating new bookings, cancelling existing ones, and checking slot availability
- Integrated the booking system with the `classSession` and `padelCourt` modules to enforce scheduling constraints
- Handled booking validation logic to prevent double-booking and manage capacity limits
- Connected booking records to the file-based database layer for persistent storage and retrieval
- Ensured the module interfaces cleanly with `gymSystemManager` for centralized control flow

---

## Technologies Used

- **Language:** C++
- **Paradigm:** Object-Oriented Programming (OOP)
- **IDE:** Visual Studio (`.sln` / `.vcxproj` project format)
- **Concepts:** Data Structures, Modular Design, File I/O
- **Storage:** File-based persistent data storage

---

## Getting Started

### Prerequisites

- [Visual Studio 2019 or later](https://visualstudio.microsoft.com/) with the **Desktop development with C++** workload installed.

### Clone the Repository

```bash
git clone https://github.com/your-username/gym-management-system.git
cd gym-management-system
```

---

## Database

The system uses a **file-based storage layer** to persist data across sessions, including:

- Member records
- Booking history
- Subscription data
- Staff information
- Session logs

All data is read and written through the database layer, keeping the business logic cleanly separated from storage.

---

## Author

Developed as part of a **university-level Data Structures and Object-Oriented Programming** academic project, designed to demonstrate real-world software design in C++.

---

> *Built to simulate real-world gym operations through clean, modular C++ design.*
