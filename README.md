Hospital Emergency Manager (C++ Project)

This project is a console-based Hospital Emergency Management System developed in C++. It simulates a real-world emergency queue by using a priority queue to manage patients based on condition severity. The system allows users to add patients, treat the most critical case first, view the entire waiting list, search for specific patients, and monitor the total number of patients waiting.

Features

Manages patient data including name, age, medical problem, and severity level.

Uses a priority queue to ensure critical patients are treated first.

Allows adding new patients with validated input.

Displays all waiting patients in a formatted table.

Treats the highest priority patient automatically.

Counts total patients currently in the emergency queue.

Supports searching for a patient by name.

Provides clean input handling to avoid crashes or incorrect entries.

Uses a simple, clear, and user-friendly console interface.

How the System Works

Severity levels determine priority:

1 → Critical

2 → Serious

3 → Normal

Patients with lower severity numbers are treated before others.

The system continuously runs in a loop until the user chooses to exit.

Technologies Used

C++ Standard Library

Priority Queue

String Handling

Console I/O

Data Formatting (iomanip)

Compilation and Execution

Compile using any standard C++ compiler such as g++, clang++, or Visual Studio.

Example command:

g++ main.cpp -o emergency
./emergency

Project Purpose

This program demonstrates the practical use of priority queues in managing real-time tasks, making it ideal for students learning data structures or for academic project submissions. It provides a realistic simulation of hospital emergency handling with clean structure and readable output.
