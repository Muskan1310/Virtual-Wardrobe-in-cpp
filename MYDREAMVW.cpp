#include <iostream>
#include <vector>
#include <algorithm> 
#include <iomanip> 
#include <ctime> 
#include <cstdlib> 

using namespace std;

struct ClothingItem {
    string type;
    string color;
    string brand;
    string season; 
};


void addClothingItem(vector<ClothingItem>& wardrobe) {
    ClothingItem newItem;

    
    cout << "Enter the type of clothing: ";
    cin >> newItem.type;
    
    cout << "Enter the color: ";
    cin >> newItem.color;
    
    cout << "Enter the brand: ";
    cin >> newItem.brand;

    cout << "Enter the season (e.g., Summer, Winter, etc.): ";
    cin >> newItem.season;

 
    wardrobe.push_back(newItem);

    cout << "Clothing item added to wardrobe!\n";
}

void displayWardrobe(const vector<ClothingItem>& wardrobe) {
    cout << "Wardrobe Inventory:\n";
    cout << setw(10) << "Type" << setw(10) << "Color" << setw(10) << "Brand" << setw(10) << "Season" << endl;
    for (const ClothingItem& item : wardrobe) {
        cout << setw(10) << item.type << setw(10) << item.color << setw(10) << item.brand << setw(10) << item.season << endl;
    }
}


void suggestOutfit(const vector<ClothingItem>& wardrobe) {
    vector<ClothingItem> seasonItems;
    string currentSeason;

    cout << "Enter the current season (e.g., Summer, Winter, etc.): ";
    cin >> currentSeason;

  
    for (const ClothingItem& item : wardrobe) {
        if (item.season == currentSeason) {
            seasonItems.push_back(item);
        }
    }

    
    if (seasonItems.size() < 2) {
        cout << "Not enough items in the wardrobe for an outfit in " << currentSeason << ".\n";
    } else {
        cout << "Outfit suggestion for " << currentSeason << ":\n";
        cout << "Top: " << seasonItems[rand() % seasonItems.size()].type << endl;
        cout << "Bottom: " << seasonItems[rand() % seasonItems.size()].type << endl;
    }
}


bool sortByType(const ClothingItem& a, const ClothingItem& b) {
    return a.type < b.type;
}


bool sortByColor(const ClothingItem& a, const ClothingItem& b) {
    return a.color < b.color;
}

bool sortByBrand(const ClothingItem& a, const ClothingItem& b) {
    return a.brand < b.brand;
}

int main() {
    vector<ClothingItem> wardrobe; 

    
    srand(time(nullptr));
    
   
    int choice;
    do {
       
        cout << "\nVirtual Wardrobe Organizer\n";
        cout << "1. Add Clothing Item\n";
        cout << "2. Display Wardrobe Inventory\n";
        cout << "3. Suggest Outfit\n";
        cout << "4. Sort Wardrobe\n";
        cout << "5. Quit\n";
        cout << "Enter your choice: ";
        cin >> choice;

       
        switch(choice) {
            case 1:
                addClothingItem(wardrobe);
                break;
            case 2:
                displayWardrobe(wardrobe);
                break;
            case 3:
                suggestOutfit(wardrobe);
                break;
            case 4:
              
                int sortChoice;
                cout << "Sort Wardrobe by:\n";
                cout << "1. Type\n";
                cout << "2. Color\n";
                cout << "3. Brand\n";
                cout << "Enter your choice: ";
                cin >> sortChoice;

                switch (sortChoice) {
                    case 1:
                        sort(wardrobe.begin(), wardrobe.end(), sortByType);
                        break;
                    case 2:
                        sort(wardrobe.begin(), wardrobe.end(), sortByColor);
                        break;
                    case 3:
                        sort(wardrobe.begin(), wardrobe.end(), sortByBrand);
                        break;
                    default:
                        cout << "Invalid choice.\n";
                }
                break;
            case 5:
                cout << "Exiting program. Goodbye!\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 5); 

    return 0;
}
