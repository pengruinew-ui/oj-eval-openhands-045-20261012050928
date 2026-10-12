#include <iostream>
#include <cstdio>
#include <set>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    // Current floor and direction
    int current_floor = 0;
    bool going_up = true;
    
    // Set to store pending requests
    set<int> requests;
    
    for (int i = 0; i < n; i++) {
        string operation;
        cin >> operation;
        
        if (operation == "action") {
            if (requests.empty()) {
                // No requests, stay in place
                continue;
            }
            
            int next_floor;
            
            // Find next floor based on current direction
            if (going_up) {
                // Look for requests in upward direction
                auto it = requests.lower_bound(current_floor + 1);
                if (it != requests.end()) {
                    // Found a request in upward direction
                    next_floor = *it;
                } else {
                    // No requests upward, reverse direction
                    going_up = false;
                    // Find the highest request in downward direction
                    next_floor = *requests.rbegin();
                }
            } else {
                // Going down
                // Look for requests in downward direction
                auto it = requests.upper_bound(current_floor - 1);
                if (it != requests.begin()) {
                    // Found a request in downward direction
                    it--;
                    next_floor = *it;
                } else {
                    // No requests downward, reverse direction
                    going_up = true;
                    // Find the lowest request in upward direction
                    next_floor = *requests.begin();
                }
            }
            
            // Move elevator to next floor
            current_floor = next_floor;
            // Remove the request
            requests.erase(next_floor);
            
        } else if (operation == "add") {
            int floor;
            cin >> floor;
            requests.insert(floor);
        } else if (operation == "cancel") {
            int floor;
            cin >> floor;
            requests.erase(floor);
        } else if (operation == "locate") {
            cout << current_floor << endl;
        }
    }
    
    return 0;
}