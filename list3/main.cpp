#include "OpenHash.h"

int main(int argc, char const *argv[])
{
    int tableSize;

    cout << "******* Create a hash table *******" << endl;
    cout << endl;

    cout << "# Enter the maximum value of elements: " << endl;
    cin >> tableSize;

    OpenHash table(tableSize/2);
    cout << "Table with size " << tableSize/2 << " created." << endl;
    cout << endl;

    while(true) {
        char option;
        int element;

        cout << "# Menu of operations with the table:" << endl;
        cout << " 0 - Add an element" << endl;
        cout << " 1 - Check if an element exists" << endl;
        cout << " 2 - Remove an element" << endl;
        cout << " any - Delete the table and exit the program" << endl;
        cout << "Enter the number operation: " << endl;
        cin >> option;

        switch(option) {
            case '0':
                cout << "You chose to add an element." << endl;
                cout << "Enter the element: " << endl;
                cin >> element;
                table.addElement(element);
                cout << endl;
                break;

            case '1':
                cout << "You chose to check if an element exists." << endl;
                cout << "Enter the element: " << endl;
                cin >> element;
                table.elementExists(element);
                cout << endl;
                break;

            case '2':
                cout << "You chose to remove an element." << endl;
                cout << "Enter the element: " << endl;
                cin >> element;
                table.deleteElement(element);
                cout << endl;
                break;

            default:
                cout << "You chose to delete the table." << endl;
                table.deleteHash();
                cout << endl;
                return 0;
        }
    }

    
    return 0;
}