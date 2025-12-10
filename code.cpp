#include <iostream>
#include <queue>
#include <string>
#include <iomanip>
using namespace std;

struct Patient {
    string name;
    int age;
    string problem;
    int severity;   // 1 = Critical, 2 = Serious, 3 = Normal
};

queue<Patient> q;

// Insert patient into correct priority position inside ONE queue
void addPatient() {
    Patient p;
    string temp;

    cout << "\nEnter name: ";
    getline(cin, p.name);

    cout << "Enter age: ";
    getline(cin, temp);
    p.age = stoi(temp);

    cout << "Enter problem: ";
    getline(cin, p.problem);

    do {
        cout << "Enter severity (1=Critical, 2=Serious, 3=Normal): ";
        getline(cin, temp);
    } while (temp != "1" && temp != "2" && temp != "3");

    p.severity = stoi(temp);

    // Temporary queue to reorder
    queue<Patient> tempQ;

    bool inserted = false;

    // Move existing patients and insert at correct priority position
    while (!q.empty()) {
        Patient cur = q.front();
        q.pop();

        // If current patient has LOWER priority, insert new patient before it
        if (!inserted && cur.severity > p.severity) {
            tempQ.push(p);
            inserted = true;
        }

        tempQ.push(cur);
    }

    // If not inserted yet, push at end
    if (!inserted) tempQ.push(p);

    q = tempQ;

    cout << "\nPatient added with priority.\n";
}

// Treat patient
void treatPatient() {
    if (q.empty()) {
        cout << "\nNo patients to treat.\n";
        return;
    }

    Patient p = q.front();
    q.pop();

    string s = (p.severity == 1 ? "Critical" :
                p.severity == 2 ? "Serious" : "Normal");

    cout << "\nTreating " << s << " patient: " << p.name << endl;
}

// Display all patients
void displayAll() {
    if (q.empty()) {
        cout << "\nNo patients.\n";
        return;
    }

    queue<Patient> temp = q;
    int count = 1;

    cout << "\n======== PATIENT LIST ========\n";
    cout << "+-----+----------------------+-------+------------+-------------------+\n";
    cout << "| No. | Name                 | Age   | Severity   | Problem           |\n";
    cout << "+-----+----------------------+-------+------------+-------------------+\n";

    while (!temp.empty()) {
        Patient p = temp.front();
        temp.pop();

        string s = (p.severity == 1 ? "Critical" :
                    p.severity == 2 ? "Serious" : "Normal");

        cout << "| " << setw(3) << left << count++
             << " | " << setw(20) << left << p.name
             << " | " << setw(5) << left << p.age
             << " | " << setw(10) << left << s
             << " | " << setw(17) << left << p.problem
             << " |\n";
    }

    cout << "+-----+----------------------+-------+------------+-------------------+\n";
}

// Count patients
void countPatients() {
    cout << "\nTotal patients: " << q.size() << endl;
}

// Search
void searchPatient() {
    string name;
    cout << "\nEnter name to search: ";
    getline(cin, name);

    queue<Patient> temp = q;
    bool found = false;

    while (!temp.empty()) {
        Patient p = temp.front();
        temp.pop();

        if (p.name == name) {
            cout << "\nFound: " << p.name 
                 << " (Severity " << p.severity 
                 << ", Problem: " << p.problem << ")\n";
            found = true;
        }
    }

    if (!found) cout << "\nPatient not found.\n";
}

int main() {
    while (true) {
        cout << "\n========== HOSPITAL MANAGER ==========\n";
        cout << "1. Add Patient\n";
        cout << "2. Display\n";
        cout << "3. Treat\n";
        cout << "4. Count\n";
        cout << "5. Search\n";
        cout << "6. Exit\n";
        cout << "Enter choice: ";

        string choice;
        getline(cin, choice);

        if (choice == "1") addPatient();
        else if (choice == "2") displayAll();
        else if (choice == "3") treatPatient();
        else if (choice == "4") countPatients();
        else if (choice == "5") searchPatient();
        else if (choice == "6") break;
    }
}
