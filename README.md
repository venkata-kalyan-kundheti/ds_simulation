🏥 Hospital Emergency Queue Manager (Single Queue Priority System)

This project implements a hospital emergency management system using only one queue in C++.
Patients are inserted into the queue based on priority (severity) while still preserving FIFO order for patients with the same severity.

📌 Features
✅ Add Patient

Takes name, age, problem, and severity

Severity levels:

1 → Critical (highest priority)

2 → Serious

3 → Normal (lowest priority)

✅ Single Queue Priority Handling

Even though only one queue is used, the system maintains correct order:

Higher priority patients always come first

For equal priority, the patient who arrived first is served first (FIFO)

✅ Treat Patient

Treats (pops) the patient at the front of the queue — always the highest priority.

✅ Display All Patients

Shows a formatted table with:

Name

Age

Severity

Problem

✅ Count Patients

Displays the total number of patients.

✅ Search Patient

Search by name inside the queue.

🧠 How Priority is Managed With One Queue

A normal queue works only in FIFO.
But priority requires higher-severity patients to come earlier.

To solve this, we use:

⭐ Manual priority insertion

When adding a patient:

We remove all existing elements from the main queue one-by-one.

We insert the new patient before any patient with lower priority.

If severity is the same, we insert after them → maintains FIFO.

Remaining patients are pushed after that.

The temporary queue becomes the new queue.

This simulates a priority system using a simple queue.

🧪 Example of Insertion Logic

If the queue has:

Name	Severity
John	1
Alex	1
Raj	2

And we add Sam with severity 2:

Sam will be inserted after Raj?
NO — because Raj has the same severity.

Sam will be placed:

After the severity 1 group

At the end of severity 2 group

New queue:

Name	Severity
John	1
Alex	1
Raj	2
Sam	2
📂 Project Structure
HospitalQueue.cpp   // Main program
README.md           // Documentation

▶️ How to Run
Compile
g++ HospitalQueue.cpp -o hospital

Run
./hospital

📜 Menu Options
1. Add Patient
2. Display All Patients
3. Treat Next Patient
4. Count Patients
5. Search Patient
6. Exit

🛠 Technologies Used

C++

<queue> STL container

Manual priority logic with FIFO preservation

🎯 Learning Outcomes

Implementing priority systems using a normal queue

FIFO + Priority hybrid logic

Queue manipulation techniques

Struct-based data handling

Formatted table output in C++

📌 Future Enhancements

Delete a specific patient

Edit patient details

Save data to file

Colorful terminal output

Time-stamping patients
