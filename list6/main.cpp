#include <iostream>
#include <string>
#include <vector>
using namespace std;


class StringSet
{
    public:
        vector<string> elements;
        int maxSize;

        StringSet() {
            
        }

        StringSet(int maxSize) {
            this->maxSize = maxSize;
        }

        ~StringSet() {
            elements.clear();
        }

        void insertElement(string element) {
            if(this->elements.size() < maxSize)
                if(!this->contains(element))
                    this->elements.push_back(element);
            else
                cout << "Element could not be inserted because set is full." << endl;
        }

        void removeElement(string element) {
            vector<string>::iterator it;

            for(it = this->elements.begin(); it != this->elements.end()+1; it++)
                if(*it == element)
                    this->elements.erase(it);
        }

        bool contains(string element) {
            for(string el : this->elements) {
                if(el == element)
                    return true;
            }
            return false;
        }

        int getCurrentSize() {
            return this->elements.size();
        }

        StringSet unionSet(vector<string> elements) {
            int newSetMaxSize = this->getCurrentSize() + elements.size();

            StringSet newSet(newSetMaxSize);

            for(string element : this->elements)
                newSet.insertElement(element);
            
            for(string element: elements)
                if(!newSet.contains(element))
                    newSet.insertElement(element);

            return newSet;
        }

        StringSet intersectionSet(vector<string> elements) {
            int newSetMaxSize = 0;

            if(this->getCurrentSize() < elements.size())
                newSetMaxSize = this->getCurrentSize();
            else
                newSetMaxSize = elements.size();

            StringSet newSet(newSetMaxSize);

            for(string el : this->elements)
                for(string el1 : elements)
                    if(el == el1)
                        newSet.insertElement(el);

            return newSet;
        }

        StringSet differenceSet(vector<string> elements) {
            StringSet newSet(this->getCurrentSize());

            for(string el : this->elements) {
                bool hasnt = true;
                for(string el1 : elements)
                    if(el == el1)
                        hasnt = false;
                
                if(hasnt)
                    newSet.insertElement(el);
            }

            return newSet;
        }

        bool isEqual(vector<string> elements) {
            if(this->getCurrentSize() != elements.size())
                return false;

            for(string el : this->elements) {
                bool contains = false;
                for(string el1 : elements)
                    if(el == el1)
                        contains = true;
                if(!contains)
                    return false;
            }
            return true;
        }

        bool isSubset(vector<string> elements) {
            if(isEqual(elements))
                return true;
            
            if(this->getCurrentSize() <= elements.size()) {
                for(string el : this->elements) {
                    bool contains = false;
                    for(string el1 : elements)
                        if(el == el1)
                            contains = true;
                    if(!contains)
                        return false;
                }
                return true;
            }

            return false;
        }

        StringSet complementarySet(vector<string> elements) {
            if(this->isSubset(elements)) {
                StringSet newSet(elements.size());

                for(string el : elements)
                    if(!this->contains(el))
                        newSet.insertElement(el);

                return newSet;
            } else {
                cout << "" << endl;
            }
               
            return StringSet();
        }

        void printSet() {
            for(string element : this->elements)
                cout << element << " ";
            cout << endl;
            cout << endl;
        }
};


int main(int argc, char const *argv[])
{
    cout << "******* Starting script... *******" << endl;
    cout << endl;

    // Q6.1
    cout << "# Create threee sets (A, B and C)." << endl;
    cout << endl;

    StringSet A(3);
    StringSet B(3);
    StringSet C(5);

    // Q6.2
    cout << "# Insert elements." << endl;

    cout << "- Set A:" << endl;
    A.insertElement("car");
    A.insertElement("ball");
    A.insertElement("dog");
    A.printSet();

    cout << "- Set B:" << endl;
    B.insertElement("car");
    B.insertElement("ball");
    B.insertElement("road");
    B.insertElement("pen");
    B.printSet();

    cout << "- Set C:" << endl;
    C.insertElement("car");
    C.insertElement("ball");
    C.insertElement("dog");
    C.insertElement("pen");
    C.printSet();

    // Q6.3
    cout << "# Remove element 'pen' from B." << endl;

    B.removeElement("pen");

    B.printSet();

    // Q6.4
    cout << "# Join two sets (A and B)." << endl;

    StringSet unionSet = A.unionSet(B.elements);

    unionSet.printSet();

    // Q6.5
    cout << "# Make the intersection between two sets (A and B)." << endl;

    StringSet intersectionSet = A.intersectionSet(B.elements);

    intersectionSet.printSet();

    // Q6.6
    cout << "# Find the difference between A and B (A - B)." << endl;

    StringSet differenceSet = A.differenceSet(B.elements);

    differenceSet.printSet();

    // Q6.7
    cout << "# Is A a subset of B? (0: false, 1: true) " << A.isSubset(B.elements) << endl;
    cout << "# Is A a subset of C? (0: false, 1: true) " << A.isSubset(C.elements) << endl;
    cout << endl;

    // Q6.8
    cout << "# Is A equals to B? (0: false, 1: true) " << A.isEqual(B.elements) << endl;
    cout << endl;

    // Q6.9
    cout << "# Generate the complement of set A with respect to C." << endl;

    StringSet complementarySet = A.complementarySet(C.elements);

    cout << "~A is ";
    complementarySet.printSet();

    // Q6.10
    cout << "# Does element 'pen' belong to set A? (0: false, 1: true) " << A.contains("pen") << endl;
    cout << "# Does element 'car' belong to set A? (0: false, 1: true) " << A.contains("car") << endl;
    cout << endl;

    // Q6.11
    cout << "# Number of elements of A: " << A.getCurrentSize() << endl;
    cout << "# Number of elements of B: " << B.getCurrentSize() << endl;
    cout << "# Number of elements of C: " << C.getCurrentSize() << endl;
    cout << endl;

    // Q6.12
    cout << "# Free set A." << A.getCurrentSize() << endl;
    A. elements.clear();
    cout << "- Set A:" << endl;
    A.printSet();

    return 0;
}
