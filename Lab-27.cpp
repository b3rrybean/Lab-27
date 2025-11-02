#include <iostream>
#include <map>
#include <vector>
#include <tuple>
#include <limits>
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
        cout << "1. Add Villager\n";
        cout << "2. Delete Villager\n";
        cout << "3. Increase Friendship\n";
        cout << "4. Decrease Friendship\n";
        cout << "5. Search for Villager\n";
        cout << "6. Exit\n";
        cout << "Enter choice; ";
        cin >> choice;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        // option 1: adding a villager
        if (choice == 1) {
            cout << "Villager name: ";
            getline(cin >> ws, name);

            int level;
            string species, catchphrase;
            cout << "Friendship level: ";
            cin >> level;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Species: ";
            getline(cin, species);
            cout << "Catchphrase: ";
            getline(cin, catchphrase);

            villagers[name] = make_tuple(level, species, catchphrase);
            cout << name << " added.\n";
        }

        // option 2: deleting a villager
        else if (choice == 2) {
            cout << "Enter villager name to delete: ";
            getline(cin >> ws, name);

            auto it = villagers.find(name);
            if (it != villagers.end()) {
                villagers.erase(it);
                cout << name << " deleted.\n";
            } else {
                cout << "Villager not found.\n";
            }
        }

        // option 3: milestone 2's increase but interactive now
        else if (choice == 3) {
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

        // option 4: decrease version
        else if (choice == 4) {
            cout << "Enter villager name to decrease friendship: ";
            getline(cin >> ws, name);

            auto it = villagers.find(name);
            if (it != villagers.end()) {
                int& level = get<0>(it->second);
                if (level > 0) level--;
                cout << name << "'s friendship level is now " << level << ".\n";
            } else {
                cout << "Villager not found.\n";
            }
        }

        // option 5: milestone 2's search code reused
        else if (choice == 5) {
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

        // option 6: exit program
        else if (choice == 6) {
            cout << "Exiting program\n";
            break;
        }
        else {
            cout << "Invalid choice. Try again.\n";
        }

    } while (choice != 6);

    // report size, clear, report size again to confirm villager operations
    cout << "\nSize before clear: " << villagers.size() << endl;
    villagers.clear();
    cout << "Size after clear: " << villagers.size() << endl;

    return 0;
}