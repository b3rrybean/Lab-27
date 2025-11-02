#include <iostream>
#include <map>
#include <vector>
using namespace std;

int main() {
    // declarations
    // map<key, value>
    // key = villager name
    // value = tuple(friendship level, species, catchphrase)
    map<string, tuple<int, string, string>> villagers;

    // insert elements into the map
    // note how the right-hand side of the assignment are the vector elements
    villagers["Drago"] = make_tuple(5, "Alligator", "Snap to it!");
    villagers["Kyle"] = make_tuple(10, "Wolf", "Hubba hubba");
    villagers["Raymond"] = make_tuple(8, "Cat", "Nice fit!");

    // display the villagers
    cout << "Villager details:" << endl;
    for (const auto& [name, info] : villagers) {
        cout << name << " ["
             << get<0>(info) << ", "
             << get<1>(info) << ", "
             << get<2>(info) << "]\n";
    }

    // milestone 3 is menu-driven so we implement milestone 2 into its menu options
    // this turns the hardcoded functions into menu options

    int choice;
    string name;

    do {
        // display menu
        cout << "\nMenu:\n";
        cout << "1. Increase Friendship\n";
        cout << "2. Decrease Friendship\n";
        cout << "3. Search for Villager\n";
        cout << "4. Exit\n";
        cout << "Enter choice; ";
        cin >> choice;

        // option 1: milestone 2's increase but interactive now
        if (choice == 1) {
            cout << "Enter villager name to increase friendship: ";
            getline(cin >> ws, name);

            auto it = villagers.find(name);
            if (it != villagers.end()) {
                int& level = get<0>(it->second);
                if (level < 10) level++;
                cout << name << "'s friendship level is now " << level << ".\n";
            } else {
                cout << "Villager not found.\n";
            }
        }

        // option 2: decrease version
        // paste increase but choice is now 2 and level--
        if (choice == 2) {
            cout << "Enter villager name to decrease friendship: ";
            getline(cin >> ws, name);

            auto it = villagers.find(name);
            if (it != villagers.end()) {
                int& level = get<0>(it->second);
                if (level < 10) level--;
                cout << name << "'s friendship level is now " << level << ".\n";
            } else {
                cout << "Villager not found.\n";
            }
        }

        // option 3: milestone 2's search code reused
        else if (choice == 3) {
            cout << "Enter villager name to search: ";
            getline(cin >> ws, name);

            auto it = villagers.find(name);
            if (it != villagers.end()) {
                cout << "\nFound " << name << ": ["
                     << get<0>(it->second) << ", "
                     << get<1>(it->second) << ", "
                     << get<2>(it->second) << "]\n";
            } else {
                cout << "Villager not found.\n" << endl;
            }
        }

        // option 4: exit program

        
    // report size, clear, report size again to confirm villager operations
    cout << "\nSize before clear: " << villagers.size() << endl;
    villagers.clear();
    cout << "Size after clear: " << villagers.size() << endl;

    // delete a villager
    villagers["Raymond"] = make_tuple(8, "Cat", "Nice fit!");
    cout << "\nAdded Raymond back.\n";
    villagers.erase("Raymond");
    cout << "Deleted Raymond. Current size: " << villagers.size() << endl;

    return 0;
}