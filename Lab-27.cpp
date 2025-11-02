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

        // option 1: milestone 2's increase/decrease but interactive now

        
    }

    // increase or decrease friendship
    cout << "Increasing Drago's friendship by 1!" << endl;
    get<0>(villagers["Drago"]) += 1;

    cout << "\nUpdated villager details:\n";
    for (const auto& [name, info] : villagers) {
         cout << name << " ["
             << get<0>(info) << ", "
             << get<1>(info) << ", "
             << get<2>(info) << "]\n";
    }
    
    // search for a villager
    string searchKey = "Drago";
    auto it = villagers.find(searchKey);
    if (it != villagers.end()) {       // the iterator points to beyond the end of the map
                                       // if searchKey is not found
        cout << "\nFound " << searchKey << ": ["
             << get<0>(it->second) << ", "
             << get<1>(it->second) << ", "
             << get<2>(it->second) << "]\n";
    } else
        cout << endl << searchKey << " not found." << endl;

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