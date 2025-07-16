#include <iostream>
#include <queue>
#include <vector>
#include <string>
using namespace std;

struct Grievance {
    string description;
    int severity;

    Grievance(string desc, int sev) : description(desc), severity(sev) {}
};

// Custom comparator for max-heap
struct CompareSeverity {
    bool operator()(Grievance const& g1, Grievance const& g2) {
        return g1.severity < g2.severity; // Max-Heap: higher severity = higher priority
    }
};

int main() {
    priority_queue<Grievance, vector<Grievance>, CompareSeverity> grievanceQueue;

    int n;
    cout << "Enter number of grievances: ";
    cin >> n;
    cin.ignore(); // to consume the newline character

    for (int i = 0; i < n; ++i) {
        string description;
        int severity;

        cout << "\nEnter grievance description: ";
        getline(cin, description);
        cout << "Enter severity (1-10): ";
        cin >> severity;
        cin.ignore();

        grievanceQueue.push(Grievance(description, severity));
    }

    cout << "\n--- Sorted Grievances by Severity (High to Low) ---\n";
    while (!grievanceQueue.empty()) {
        Grievance g = grievanceQueue.top();
        grievanceQueue.pop();
        cout << "Grievance: " << g.description << " | Severity: " << g.severity << endl;
    }

    return 0;
}