#include <iostream>
using namespace std;

class ListNode { // every created node is an object of ListNode
public:
    ListNode(const double element) : _data(element), _nextPtr(nullptr) { // the inputed value of the element, is going to be stored in _data variable
        };

    double _data;
    ListNode* _nextPtr;  //_nextPtr is a pointer to the next node (it indicates  the next element)
                         //By the way(return type is ListNode) and it is PUBLIC
};

class List {
public:
    List() :_firstPtr(nullptr), _lastPtr(nullptr),_count(0) {   
    };

    ~List() {
        ListNode* temporary = _firstPtr;
        while (temporary != nullptr) {
            _firstPtr = _firstPtr->_nextPtr;
            delete temporary;     // delete is used to destroy array or pointer objects from geeksforgeeks
            temporary = _firstPtr;
        }
    }

    bool insertAtIndex(const size_t idx, const double value) {

        _count++;
        size_t start = 0;
        ListNode* idxNode = getNewNode(value);
        ListNode* temporary = _firstPtr;
        if (isEmpty()) {
            _firstPtr = _lastPtr = idxNode;
            return true;
        }
        else if (idx == 0) {
            _firstPtr = idxNode;
            _firstPtr->_nextPtr = temporary;
            return true;
        }
        else {
            while (start < idx - 1) {
                temporary = temporary->_nextPtr;
                start++;
            }
            idxNode->_nextPtr = temporary->_nextPtr;
            temporary->_nextPtr = idxNode;
            temporary = nullptr;
            delete temporary;

        }
        return true;
    }


    bool deleteAtIndex(const size_t idx) {
        _count--;
        size_t start = 0;
        ListNode* temp;
        ListNode* temporary = _firstPtr;
        if (isEmpty()) {
            cout << "No element to delete";
            return true;
        }
        else if (idx == 0) {
            _firstPtr = _firstPtr ->_nextPtr;
           delete temporary;
           return false;
        }
        else {
            while (start < idx - 1) {
                temporary = temporary->_nextPtr;
                start++;
            }
            temp = temporary->_nextPtr;
            temporary ->_nextPtr = temporary->_nextPtr ->_nextPtr;
            temp = nullptr;
            delete temp;
            temporary = nullptr;
            delete temporary;
        }
        return true;
    }

    void insertAtFront(const double value) {
        _count++;
        ListNode* FirstNode = getNewNode(value);
        if (isEmpty()) {
            _firstPtr = _lastPtr = FirstNode;
        }
        else {
            FirstNode->_nextPtr = _firstPtr;
            _firstPtr = FirstNode;
        }
    };

    void insertAtBack(const double value) {
        _count++;
        ListNode* LastNode = getNewNode(value);
        if (isEmpty()) {
            _firstPtr = _lastPtr = LastNode;
        }
        else {
            _lastPtr->_nextPtr = LastNode;
            _lastPtr = LastNode;
        }
    };

    bool removeFromFront(double& data) {
        if (isEmpty()) {
            return false;
            _count = 0;
        }
        else {
            _count--;
            data = _firstPtr->_data;
            ListNode* temporary = _firstPtr->_nextPtr;   
            delete _firstPtr;
            _firstPtr = temporary;
            return true;
        }
    };

    bool removeFromBack(double& data) {
        if (isEmpty()) {
            return false;
            _count = 0;
        }
        else {
            data = _lastPtr->_data;
            if (_firstPtr == _lastPtr) {
                //delete _firstPtr;
                //delete _lastPtr;
                _firstPtr = _lastPtr = nullptr;
                _count = 0;
            }
            else {
                _count--;
                ListNode* temporary = _firstPtr;
                //ListNode* temp = _lastPtr;
                while (temporary->_nextPtr != _lastPtr) {
                    temporary = temporary->_nextPtr;
                }
                _lastPtr = temporary;
                _lastPtr->_nextPtr = nullptr;
                temporary = temporary->_nextPtr;
                delete temporary;
              /*  _lastPtr = temporary;
                _lastPtr->_nextPtr = nullptr;
                delete temp;
                delete temporary;
                */          
            }
            return true;
        }
    };

    bool isEmpty() const {  //this will check, wether the list is empty or not
        if (_firstPtr == nullptr) {
            return true;
        }
        return false;
    };

    void print() const {
        if (isEmpty()) {
            cout << "The list is empty:" << endl;
        }
        else {
            ListNode* temporary = _firstPtr;
            cout << "The List: \n";
            while (temporary != nullptr) {
                cout << "   " << temporary->_data;
                temporary = temporary->_nextPtr;
            }
            cout << endl;
        }
    };

    size_t getElementCount() const {
        return _count;
    };

private:

    ListNode* getNewNode(const double value) const {  //this will return a new object from ListNode class
        return new ListNode(value);
    };

private:

    ListNode* _firstPtr;
    ListNode* _lastPtr;
    size_t _count;
};

void instructions() {
    cout << "\n\nEnter one of the following: \n"
        << "1 to insert at beginning of list\n"
        << "2 to insert at end of list\n"
        << "3 to delete from beginning of list\n"
        << "4 to deete from end of list\n"
        << "5 to insert at index ldx\n"
        << "6 to delete at index ldx\n"
        << "7 to report the number of elements\n"
        << "8 end list processing\n";
}

int main()
{
    List object;
    int instructionN = 0;
    int value,index;

    while (instructionN != 8) {
        instructions();
        cin >> instructionN;
        switch (instructionN)
        {
        case 1:
            cout << "Enter element, wich will be added at the beginning: ";
            cin >> value;
            object.insertAtFront(value);
            object.print();
            break;
        case 2:
            cout << "Enter element, wich will be added at the end: ";
            cin >> value;
            object.insertAtBack(value);
            object.print();
            break;
        case 3:
            double elementDeletedFromFront;
            if (object.removeFromFront(elementDeletedFromFront)) {
                cout << elementDeletedFromFront << " is deleted:\n";
                object.print();
            }else{
                cout << "No element to delete";
            }
            break;
        case 4:
            double elementDeletedFromBack;
            if (object.removeFromBack(elementDeletedFromBack)) {
                cout << elementDeletedFromBack << " is deleted:\n";
                object.print();
            }
            else {
                cout << "No element to delete";
            }
            break;
        case 5: 
            cout << "Enter value: ";
            cin >> value;
            cout << "Enter index: ";
            cin >> index;
            object.insertAtIndex(index, value);
            cout << "The list is: " << endl;
            object.print();
            break;
        case 6:
            cout << "Enter index: ";
            cin >> index;
            object.deleteAtIndex(index);
            cout << "The list is: " << endl;
            object.print();
            break;
        case 7:
            cout << "Element count: " << object.getElementCount() << endl;
            break; 
        case 8:
            cout << "List processing is over:\n";
            break;
        default:
            cout << "Instruction number error! try again: " << endl;
            break;
        }
    }
    
}


