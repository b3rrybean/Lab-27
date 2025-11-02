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

    // increase or decrease friendship
    cout << "Increasing Drago's friendship by 1!" << endl;
    get<0>(villagers["Drago"]) += 1;
    
    // search for a villager
    string searchKey = "Audie";
    auto it = villagerColors.find(searchKey);
    if (it != villagerColors.end()) {  // the iterator points to beyond the end of the map
                                       // if searchKey is not found
        cout << "\nFound " << searchKey << "'s favorite colors: ";
        for (auto color : it->second)  // range loop to traverse the value/vector
            cout << color << " ";
        cout << endl;
    } else
        cout << endl << searchKey << " not found." << endl;

    // report size, clear, report size again to confirm map operations
    cout << "\nSize before clear: " << villagerColors.size() << endl;
    villagerColors.clear();
    cout << "Size after clear: " << villagerColors.size() << endl;

    // delete a villager
    villagerColors.erase("Raymond");

    return 0;
}