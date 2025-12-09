#include <iostream>
#include <queue>
#include <stack>
#include <string>
#include <iomanip>  
using namespace std;

// Patient structure
struct Patient {
    string name;
    int age;
    string problem;
};

// Global queues
queue<Patient> criticalQ;
queue<Patient> seriousQ;
queue<Patient> normalQ;

// Function to safely display a queue with numbering and totals

void displayQueue(queue<Patient> &q, string title) {
    cout << "\n--- " << title << " ---\n";

    if (q.empty()) {
        cout << "No patients.\n";
        cout << "Total patients in this stage = 0\n";
        return;
    }

    stack<Patient> tempStack;
    int count = 0;

    // Print table header
    cout << "+-----+----------------------+-------+------------------------+\n";
    cout << "| No. | Name                 | Age   | Problem                |\n";
    cout << "+-----+----------------------+-------+------------------------+\n";

    // Process queue
    while (!q.empty()) {
        Patient p = q.front();
        q.pop();
        tempStack.push(p);

        count++;

        // C++ formatted table row
        cout << "| " << setw(3) << left << count
             << " | " << setw(20) << left << p.name
             << " | " << setw(5) << left << p.age
             << " | " << setw(22) << left << p.problem
             << " |\n";
    }

    cout << "+-----+----------------------+-------+------------------------+\n";
    cout << "Total patients in this stage = " << count << "\n";

    // Restore the queue
    while (!tempStack.empty()) {
        q.push(tempStack.top());
        tempStack.pop();
    }
}

// Add a new patient
void addPatient() {
    Patient p;
    int severity;

    cout << "\nEnter patient name: ";
    cin.ignore();               // Clear buffer BEFORE getline
    getline(cin, p.name);

    cout << "Enter age: ";
    cin >> p.age;

    cout << "Enter problem: ";
    cin.ignore();               // Clear buffer again for next getline
    getline(cin, p.problem);

    cout << "Enter severity (1 = Critical, 2 = Serious, 3 = Normal): ";
    cin >> severity;

    if (severity == 1) {
        criticalQ.push(p);
        cout << "Patient added to CRITICAL queue.\n";
    }
    else if (severity == 2) {
        seriousQ.push(p);
        cout << "Patient added to SERIOUS queue.\n";
    }
    else {
        normalQ.push(p);
        cout << "Patient added to NORMAL queue.\n";
    }
}


// Treat next patient based on priority
void treatPatient() {
    if (!criticalQ.empty()) {
        Patient p = criticalQ.front();
        criticalQ.pop();
        cout << "\nTreating CRITICAL patient: " << p.name << endl;
    }
    else if (!seriousQ.empty()) {
        Patient p = seriousQ.front();
        seriousQ.pop();
        cout << "\nTreating SERIOUS patient: " << p.name << endl;
    }
    else if (!normalQ.empty()) {
        Patient p = normalQ.front();
        normalQ.pop();
        cout << "\nTreating NORMAL patient: " << p.name << endl;
    }
    else {
        cout << "\nNo patients to treat.\n";
    }
}

// Display all patients in priority order
void displayAllPatients() {
    cout << "\n===== CURRENT PATIENT LIST =====\n";

    displayQueue(criticalQ, "Critical Queue");
    displayQueue(seriousQ, "Serious Queue");
    displayQueue(normalQ, "Normal Queue");

    int total = criticalQ.size() + seriousQ.size() + normalQ.size();
    cout << "\n*** Total patients waiting: " << total << " ***\n";
}

// Search patient by name in all queues
void searchPatient() {
    string name;
    cout << "\nEnter patient name to search: ";
    cin >> name;

    bool found = false;

    auto searchInQueue = [&](queue<Patient> &q, string category) {
        stack<Patient> temp;
        while (!q.empty()) {
            Patient p = q.front(); 
            q.pop();

            if (p.name == name) {
                cout << "\nFound in " << category << " queue:\n";
                cout << "Name: " << p.name << ", Age: " << p.age 
                     << ", Problem: " << p.problem << endl;
                found = true;
            }
            temp.push(p);
        }
        while (!temp.empty()) {
            q.push(temp.top());
            temp.pop();
        }
    };

    searchInQueue(criticalQ, "CRITICAL");
    searchInQueue(seriousQ, "SERIOUS");
    searchInQueue(normalQ, "NORMAL");

    if (!found)
        cout << "\nPatient not found.\n";
}

// Count all patients waiting
void countPatients() {
    int criticalCount = criticalQ.size();
    int seriousCount = seriousQ.size();
    int normalCount = normalQ.size();

    int total = criticalCount + seriousCount + normalCount;

    cout << "\n===== PATIENT COUNT =====\n";
    cout << "Critical: " << criticalCount << endl;
    cout << "Serious: " << seriousCount << endl;
    cout << "Normal: " << normalCount << endl;
    cout << "---------------------------\n";
    cout << "Total waiting patients: " << total << endl;
}

// Main menu
int main() {
    int choice;

    while (true) {
        cout << "\n==============================\n";
        cout << " Hospital Emergency Manager\n";
        cout << "==============================\n";
        cout << "1. Add Patient\n";
        cout << "2. Display All Patients\n";
        cout << "3. Treat Next Patient\n";
        cout << "4. Show Remaining Patients\n";
        cout << "5. Count Patients\n";
        cout << "6. Search Patient by Name\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: addPatient(); break;
            case 2: displayAllPatients(); break;
            case 3: treatPatient(); break;
            case 4: displayAllPatients(); break;
            case 5: countPatients(); break;
            case 6: searchPatient(); break;
            case 7: cout << "Exiting...\n"; return 0;
            default: cout << "Invalid choice. Try again.\n";
        }
    }
}
