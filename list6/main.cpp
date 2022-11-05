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

            for(it = this->elements.begin(); it != this->elements.end(); it++)
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
            }
               
            return StringSet();
        }

        void printSet() {
            for(string element : this->elements)
                cout << element << " ";
            cout << endl;
        }
};


int main(int argc, char const *argv[])
{
    StringSet A(3);
    StringSet B(3);

    A.insertElement("car");
    A.insertElement("ball");
    A.insertElement("dog");

    A.printSet();

    B.insertElement("car");
    B.insertElement("ball");
    B.insertElement("road");

    B.printSet();

    StringSet unionSet = A.unionSet(B.elements);

    unionSet.printSet();

    StringSet intersectionSet = A.intersectionSet(B.elements);

    intersectionSet.printSet();

    StringSet differenceSet = A.differenceSet(B.elements);

    differenceSet.printSet();

    cout << "Is A a subset of B? " << A.isSubset(B.elements) << endl;

    cout << "Is A equals to B? " << A.isEqual(B.elements) << endl;

    StringSet complementarySet = A.complementarySet(B.elements);

    cout << "~A is" << endl;
    complementarySet.printSet();

    return 0;
}
