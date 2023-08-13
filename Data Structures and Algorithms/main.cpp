#include <iostream>
#include <fstream>
#include <vector>
#include <math.h>
#include <string>
#include <iomanip>
#include <chrono>

#define MAX 517440
#define MAX_SESSIONS 2
#define MAX_ALGORITHMS 2
#define MAX_SEARCHING_ALGORITHMS 2
#define MAX_SORTING_ALGORITHMS 4
#define MAX_DATA_STRUCTURES 4
#define MAX_DOUBLE_LINKED_LIST_OPTIONS 8

// FLUSH FUNCTIONS
void flushFile(std::ifstream& f) {
    char c;
    while (f.get(c) && c != '\n' && c != std::ifstream::traits_type::eof());
}
void flushStdin() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}
// DATA STRUCTURE
// LINKED LIST
typedef struct DOUBLE_LINKED_LIST_NODE {
    long info;
    DOUBLE_LINKED_LIST_NODE* prev;
    DOUBLE_LINKED_LIST_NODE* next;
}DLNode;
typedef struct DOUBLE_LINKED_LIST {
    DOUBLE_LINKED_LIST_NODE* head, * tail;
}DLIST;

DLIST* List = new DLIST;
unsigned int limit_DList = 0;
unsigned int current_position;
unsigned int position_DList;
long element_DList;
short int option_DList;
short int choices_DList;
long data_Dynamic;

void initDList(DLIST* List) {
    List->head = List->tail = NULL;
}
short int isEmpty(DLIST* List) {
    if (List->head == NULL)
        return 1;
    else
        return 0;
}
DLNode* createNode(long data) {
    DLNode* newNode = new DLNode;
    if (!newNode) {
        std::cout << "Not enough space to create Node" << std::endl;
        return NULL;
    }
    newNode->info = data;
    newNode->next = newNode->prev = NULL;
    return newNode;
}
short int insertHead(DLIST* List, DLNode* newNode) {
    if (isEmpty(List)) {
        List->head = List->tail = newNode;
        limit_DList = 1; // Initialize the limit_DList to 1 for the first node
        return 0;
    }
    else {
        newNode->next = List->head;
        List->head->prev = newNode;
        List->head = newNode;
        limit_DList++; // Update the global variable directly
    }
    return 1;
}
short int insertTail(DLIST* List, DLNode* newNode) {
    if (isEmpty(List)) {
        List->head = List->tail = newNode;
        limit_DList = 1; // Initialize the limit_DList to 1 for the first node
        return 0;
    }
    else {
        List->tail->next = newNode;
        newNode->prev = List->tail;
        List->tail = newNode;
        limit_DList++; // Update the global variable directly
    }
    return 1;
}
long showHead(DLIST *List){
    return List->head->info;
}
long showTail(DLIST *List){
    return List->tail->info;
}
short int insertAfter(DLIST* List, DLNode* node, DLNode* newNode) {
    if (!node || !newNode)
        return 0; //Failed insertion
    DLNode* nearbyNode = node->next;
    newNode->next = nearbyNode;
    newNode->prev = node;
    node->next = newNode;
    if (nearbyNode != NULL) {
        nearbyNode->prev = newNode;
    }
    else // if (node == List->tail)
        List->tail = newNode; // Update the tail if inserting after the current tail
    limit_DList++;
    return 1; //Success insertion
}
short int insertBefore(DLIST* List, DLNode* node, DLNode* newNode) {
    if (!node || !newNode)
        return 0; //Failed insertion
    DLNode* nearbyNode = node->prev;
    newNode->next = node;
    newNode->prev = nearbyNode;
    node->prev = newNode;
    if (nearbyNode != NULL) {
        nearbyNode->next = newNode;
    }
    else //if (node == List->head)
        List->head = newNode; // Update the head if inserting before the current head
    limit_DList++;
    return 1; //Success insertion
}
short int insert(DLIST* List, unsigned int position_DList, short int option_DList, long data) {
    unsigned int count = 1;
    if (position_DList > limit_DList + 1) // Allow inserting at the end
        return 1; //Exceeding limit
    if (position_DList < 1)
        return 2; //Invalid position

    DLNode* node = List->head;
    DLNode* newNode = createNode(data);
    while (node != NULL && count != position_DList) {
        count++;
        node = node->next;
    }
    if (option_DList == 1) {
        if (!insertBefore(List, node, newNode))
            return 3; // Insertion failed
    }
    else {
        if (!insertAfter(List, node, newNode))
            return 3; // Insertion failed
    }
    return 0; // Successful insertion
}
void showAllDList(DLIST* List, short int option_DList) {
    if (isEmpty(List)) {
        std::cout << "Empty List." << std::endl;
        return;
    }
    DLNode* node;
    if (option_DList) {
        node = List->head;
        while (node) {
            std::cout << node->info << " ";
            node = node->next;
        }
    }
    else {
        node = List->tail;
        while (node) {
            std::cout << node->info << " ";
            node = node->prev;
        }
    }
    std::cout << std::endl;
}
long findPositionOfElement(DLIST* List, long element) {
    if (isEmpty(List) == 1)
        return -1; // Empty List

    DLNode* node = List->head;
    unsigned int location = 1;
    while (node) {
        if (node->info == element)
            return location; // Found the element at this location
        node = node->next;
        location++;
    }

    return -2; // Unable to find the element in the list
}
long showInfoAtPosition(DLIST* List, unsigned int position) {
    if (isEmpty(List) == 1)
        return LONG_MIN; // Empty List

    DLNode* node = List->head;
    unsigned int count = 1;
    while (node && count != position) {
        node = node->next;
        count++;
    }

    if (node) {
        return node->info; // Found the data at this position
    } else {
        return LONG_MIN + 1; // Unable to find data at the specified position
    }
}

// STACK
struct STACK_NODE {
    int info;
    STACK_NODE* next;
};
struct STACK {
    STACK_NODE* Top;
};
// QUEUE
struct QUEUE_NODE {
    int info;
    QUEUE_NODE* next;
};
struct QUEUE {
    QUEUE_NODE* head;
};
// TREE
struct BINARY_TREE_NODE {
    int info;
    BINARY_TREE_NODE* left;
    BINARY_TREE_NODE* right;
};
struct AVL_BINARY_SEARCH_TREE{
    BINARY_TREE_NODE* Root;
};
//// SESSIONS
struct SESSION{
    std::string name;
};
//SESSION session[MAX_SESSIONS]{
//    {"Algorithm"},
//    {"Data Structure"}
//};
//SESSION algorithms[MAX_ALGORITHMS] = {
//    {"Searching Algorithm"},
//    {"Sorting Algorithm"}
//};
//SESSION searching[MAX_SEARCHING_ALGORITHMS] = {
//    {"Linear Search"},
//    {"Binary Search"},
//};
//SESSION sorting[MAX_SORTING_ALGORITHMS] = {
//    {"Quick Sort"},
//    {"Merge Sort"},
//    {"Heap Sort"},
//    {"Shell Sort"}
//};
//SESSION data_structures[MAX_DATA_STRUCTURES] = {
//    {"Double Linked List"},
//    {"Stack"},
//    {"Queue"},
//    {"Binary Search Tree"}
//};
//SESSION double_linked_lists[MAX_DOUBLE_LINKED_LIST_OPTIONS] = {
//    {"Show all List"},
//    {"Show head node"},
//    {"Show tail node"},
//    {"Show info of an element"},
//    {"Find position of a specified element"},
//    {"Insert Head"},
//    {"Insert Tail"},
//    {"Insert Middle"}
//};

// PERFORMED_TIMES Turns[MAX_SORTING_ALGORITHMS];
// void assignment(PERFORMED_TIMES Turns[]) {
//     for (unsigned short int count = 0; count < MAX_SESSIONS; count++) {
//         Turns[count].times = 0;
//     }
// }
// void showTurns(PERFORMED_TIMES Turns[]) {
//     for (unsigned short int count = 0; count < MAX_SESSIONS; count++) {
//         std::cout << Turns[count].times << " ";
//     }
//     std::cout << std::endl;
// }

// Sessions
std::vector<SESSION> sessions = {
    {"Algorithm"},
    {"Data Structure"}
};

// Algorithms
std::vector<SESSION> algorithms = {
    {"Searching Algorithm"},
    {"Sorting Algorithm"}
};

// Searching Algorithms
std::vector<SESSION> searching_algorithms = {
    {"Linear Search"},
    {"Binary Search"}
};

// Sorting Algorithms
std::vector<SESSION> sorting_algorithms = {
    {"Quick Sort"},
    {"Merge Sort"},
    {"Heap Sort"},
    {"Shell Sort"}
};

// Data Structures
std::vector<SESSION> data_structures = {
    {"Double Linked List"},
    {"Stack"},
    {"Queue"},
    {"Binary Search Tree"}
};

// Double Linked List Options
std::vector<SESSION> double_linked_list_options = {
    {"Show all List"},
    {"Show head node"},
    {"Show tail node"},
    {"Show info of an element"},
    {"Find position of a specified element"},
    {"Insert Head"},
    {"Insert Tail"},
    {"Insert Middle"}
};

// FUNCTION PROTOTYPE
void announceProcessingTime(std::chrono::microseconds ProcessingTime);
void menu();
void algorithms_menu();
void sorting_menu();
void searching_menu();
void data_structures_menu();
void main_program();
void algorithms_program();
void searching_program();
void sorting_program();
void data_structures_program();
// GLOBAL VARIABLE DECLARATION
unsigned short int menu_options; // session number
unsigned short int menu_choices; // struct number
unsigned short int Align01 = 10;
unsigned short int Align02 = 39;
unsigned short int Width01 = 55;
long Array[MAX];
long elementsOfArray = 0;
long searchKey;
long SearchResult;
char file_input[] = "Input.txt";
char file_Output[] = "Output.txt";
char file_History[] = "Algorithms_History.txt";
char running_status[] = " is running... ";
// INPUT - OUTPUT FILE FUNCTIONS
short int readFromFile_Array(long* Array, long& elementsOfArray, char file_input[]) {
    std::ifstream file;
    file.open(file_input);
    if (!file)
        //if (!outputFile.is_open())
        //file.fail()
    {
        std::cout << "Can't find the specified file." << std::endl;
        system("pause");
        return -1;
    }
    file >> elementsOfArray;
    if (elementsOfArray < 1) {
        std::cout << "Invalid amount of array." << std::endl;
        return -1;
    }
    
    auto startTime = std::chrono::high_resolution_clock::now();
    for (long i = 0; i < elementsOfArray; i++)
        file >> Array[i];
    auto endTime = std::chrono::high_resolution_clock::now();
    auto ProcessingTime = std::chrono::duration_cast<std::chrono::microseconds>(endTime - startTime);
    std::cout << "Elements of the Array: " << limit_DList << std::endl;
    announceProcessingTime(ProcessingTime);
    
    file.close();
    return 1;
}
short int readFromFile_DynamicAllocation(DLIST* List, char file_input[],  long data) {
    std::ifstream file;
    file.open(file_input);

    if (!file)
    //if (!outputFile.is_open())
    //file.fail()
    {
        std::cout << "Unable to open the file." << std::endl;
        return 0; //Failed
    }

    DLNode* newNode;
    unsigned int limitation;
    unsigned int i = 0;

    if (!(file >> limitation)) {
        std::cout << "Error reading limit from file." << std::endl;
        file.close();
        return 0; //Failed
    }

    auto startTime = std::chrono::high_resolution_clock::now();
    while (i < limitation) {
        if (!(file >> data)) {
            std::cout << "Error reading data from file." << std::endl;
            file.close();
            return 0; //Failed
        }
        newNode = createNode(data);
        insertTail(List, newNode);
        i++;
    }
    auto endTime = std::chrono::high_resolution_clock::now();
    auto ProcessingTime = std::chrono::duration_cast<std::chrono::microseconds>(endTime - startTime);
    std::cout << "Elements of the List: " << limit_DList << std::endl;
    announceProcessingTime(ProcessingTime);
    
    file.close();
    return 1;
}
short int exportToFile(long Array[], long elementsOfArray, char file_Output[]) {
    std::ofstream outputFile(file_Output);
    if (!outputFile.is_open()) {
        std::cerr << "Unable to open output file." << std::endl;
        return 0; //Failed
    }
    for (int i = 0; i < elementsOfArray; ++i) {
        outputFile << Array[i] << "\n";
    }
    outputFile.close();
    return 1; //Successfully export
}

// SEARCHING ALGORITHMS
long LinearSearch(long Array[], long elementsOfArray, long searchKey) {
    for (long i = 0; i < elementsOfArray; i++)
        if (Array[i] == searchKey)
            return i;
    return -1; //Can't find out
}
long BinarySearch(long Array[], long elementsOfArray, long searchKey) {
    long left = 0;
    long right = elementsOfArray - 1;
    long mid = 0;
    while (left <= right) {
        mid = (left + right) / 2;
        if (Array[mid] == searchKey)
            return mid; //Return position of the data
        else if (Array[mid] > searchKey)
            right = mid - 1;
        else
            left = mid + 1;
    }
    return -1; //Can't find out
}
// SORTING ALGORITHMS
// Swap function
void swap(long& x, long& y) {
    long temp = x;
    x = y;
    y = temp;
}
// Function to merge two subarrays of Array[]
// First subarray is Array[low..mid]
// Second subarray is Array[mid+1..high]
void merge(long Array[], long left, long mid, long right) {
    long N1 = mid - left + 1;
    long N2 = right - mid;
    // Create temporary arrays
    long* Left = new long[N1];
    long* Right = new long[N2];
    //Instead of: int Left[N1], Right[N2];

    // Copy data to temporary arrays
    for (long i = 0; i < N1; i++)
        Left[i] = Array[left + i];
    for (long j = 0; j < N2; j++)
        Right[j] = Array[mid + 1 + j];
    // Merge the temporary arrays back into Array[low..high]
    long i = 0, j = 0, k = left;
    while (i < N1 && j < N2) {
        if (Left[i] <= Right[j]) {
            Array[k] = Left[i];
            i++;
        }
        else {
            Array[k] = Right[j];
            j++;
        }
        k++;
    }
    // Copy the remaining elements of Left[] and Right[]
    while (i < N1) {
        Array[k] = Left[i];
        i++;
        k++;
    }
    // Copy the remaining elements of Right[], if any
    while (j < N2) {
        Array[k] = Right[j];
        j++;
        k++;
    }
}
// Function to implement Merge Sort
void mergeSort(long Array[], long left, long right) {

    if (left >= right) {
        // Base case: array has only one element or is empty
        return;
    }
    // Find the middle point to divide the array into two halves
    long mid = left + (right - left) / 2;
    // Recursively sort first and second halves
    mergeSort(Array, left, mid);
    mergeSort(Array, mid + 1, right);
    // Recursively sort first and second halves
    merge(Array, left, mid, right);
}

// Function to partition the array using the last element as pivot
long partition(long Array[], long left, long right) {
    long pivot = Array[right];
    long i = left - 1;

    for (long j = left; j <= right - 1; j++) {
        if (Array[j] < pivot) {
            i++;
            swap(Array[i], Array[j]);
        }
    }

    swap(Array[i + 1], Array[right]);
    return i + 1;
}
// Function to implement Quick Sort
void quickSort(long Array[], long left, long right) {
    if (left < right) {
        long pivot = partition(Array, left, right);

        quickSort(Array, left, pivot - 1);
        quickSort(Array, pivot + 1, right);
    }
}
// Function to heapify a subtree rooted at index 'root'
void heapify(long Array[], long elementsOfArray, long rootIndex) {
    long largest = rootIndex; // Initialize largest as root
    long leftChild = 2 * rootIndex + 1; // Left child
    long rightChild = 2 * rootIndex + 2; // Right child
    // If left child is larger than root
    if (leftChild < elementsOfArray && Array[leftChild] > Array[largest])
        largest = leftChild;
    // If right child is larger than current largest
    if (rightChild < elementsOfArray && Array[rightChild] > Array[largest])
        largest = rightChild;
    // If largest is not root
    if (largest != rootIndex) {
        swap(Array[rootIndex], Array[largest]);
        // Recursively heapify the affected sub-tree
        heapify(Array, elementsOfArray, largest);
    }
}
// Main function to perform heap sort
void heapSort(long Array[], long elementsOfArray) {
    // Build the heap (rearrange the array)
    for (long i = elementsOfArray / 2 - 1; i >= 0; i--)
        heapify(Array, elementsOfArray, i);
    // Extract elements one by one from the heap
    for (long i = elementsOfArray - 1; i >= 0; i--) {
        // Move the current root to the end
        swap(Array[0], Array[i]);
        // Call heapify on the reduced heap
        heapify(Array, i, 0);
    }
}
// Function to perform Shell Sort
void shellSort(long Array[], long elementsOfArray) {
    // Start with a large gap, then reduce the gap
    for (long gap = elementsOfArray / 2; gap > 0; gap /= 2) {
        // Perform insertion sort for elements at a specific gap
        for (long i = gap; i < elementsOfArray; i++) {
            long temp = Array[i];
            long j;
            // Shift elements that are greater than temp to the right
            for (j = i; j >= gap && Array[j - gap] > temp; j -= gap)
                Array[j] = Array[j - gap];
            // Place the temp element at its correct position
            Array[j] = temp;
        }
    }
}
// Show all elements of an array
void showallArray(long Array[], long elementsOfArray) {
    for (long i = 0; i < elementsOfArray; i++)
        std::cout << Array[i] << " ";
}

// Function to display title
void display_title(const std::string& title, const std::vector<SESSION>& sessions) {
    std::string separatorLine(Width01 - 2, '=');
    std::string separatorLinePart01(Align01 + 1, '-');
    std::string separatorLinePart02(Align02 + 1, '-');
    std::string separatorRow = "\t\t||" + separatorLinePart01 + "||" + separatorLinePart02 + "||";

    std::cout << "\t\t.";
    for (int i = 1; i <= Width01; i++) {
        std::cout << "=";
    }
    std::cout << "." << std::endl;

    std::cout << std::left << "\t\t|| " << std::setw(Align01) << "Number" << "|| " << std::setw(Align02) << title << "||" << std::endl;
    std::cout << separatorRow << std::endl;
    for (int menu_choices = 0; menu_choices < sessions.size(); menu_choices++) {
        std::cout << std::left << "\t\t|| " << std::setw(Align01) << menu_choices + 1 << "|| " << std::setw(Align02) << sessions[menu_choices].name << "||" << std::endl;
    }

    std::cout << "\t\t*";
    for (int i = 1; i <= Width01; i++) {
        std::cout << "=";
    }
    std::cout << "*" << std::endl;
}

// Function to display notification
void display_notification(const std::string& message, const std::vector<SESSION>& sessions, unsigned short int menu_options, unsigned short int menu_choices) {
    std::cout << message << menu_options << ": " << sessions[menu_choices].name << std::endl;
}

// Function to perform menu selection
short int menu_selection(const std::string& prompt, int max_options) {
    int option;
    std::cout << prompt;
    std::cin >> option;
    while (!(option >= 0 && option <= max_options)) {
        std::cout << "Your choice is invalid, please try again: ";
        std::cin >> option;
    }
    return option;
}
// MENU SELECTION
short int main_selection() {
    return menu_selection("Choose your session (press number 0 for exiting the program): ", sessions.size());
}
short int algorithms_selection() {
    return menu_selection("Choose your algorithm (press number 0 to return to the menu): ", algorithms.size());
}
short int searching_selection() {
    return menu_selection("Choose your searching algorithm (press number 0 to return to the menu): ", searching_algorithms.size());
}
short int sorting_selection() {
    return menu_selection("Choose your sorting algorithm (press number 0 to return to menu): ", sorting_algorithms.size());
}
short int data_structures_selection() {
    return menu_selection("Choose your data structure (press number 0 to return to menu): ", data_structures.size());
}

// Enter key search
long enterKey() {
    long searchKey;
    std::cout << "Please enter your number: ";
    std::cin >> searchKey;
    return searchKey;
}

// ANNOUNCEMENTS
void announceProcessingTime(std::chrono::microseconds ProcessingTime) {
    std::cout << "Input the file successfully. Processing time is " << ProcessingTime.count() << " microseconds." << std::endl << std::endl;
}
void announceSearchingTime(int menu_choices, long searchKey, long SearchResult, std::chrono::microseconds SearchingTime) {
    if (SearchResult == -1) {
        std::cout << searchKey << " wasn't found." << std::endl;
    }
    else {
        std::cout << searchKey << " was found at index Array[" << SearchResult << "] " << std::endl;
    }
    std::cout << searching_algorithms[menu_choices].name << " Time: " << SearchingTime.count() << " microseconds." << std::endl << std::endl;
}
void announceSortingTime(int menu_choices, std::chrono::microseconds SortingTime) {
    std::cout << sorting_algorithms[menu_choices].name << " Time: " << SortingTime.count() << " microseconds." << std::endl << std::endl;
}

// Double linked list
short int choices_DList_selection() {
    return menu_selection("Choose your test (press number 0 to cancel): ", double_linked_list_options.size());
}
void Double_Linked_List() {
    if (!readFromFile_DynamicAllocation(List, file_input, data_Dynamic)) {
        return data_structures_menu();
    }
    while(1==1){
        choices_DList = choices_DList_selection();
        switch (choices_DList){
            case 1:{
                std::cout << "Choose your option (1 to output from head to tail & 0 to output from tail to head): ";
                std::cin >> option_DList;
                while (!(option_DList >= 0 && option_DList <= 1)) {
                    std::cout << "Your choice is invalid, please try again: ";
                    std::cin >> option_DList;
                }
                showAllDList(List,option_DList);
            }break;
            case 2:{
                std::cout << "Head of the list: " << showHead(List) << std::endl;
            }break;
            case 3:{
                std::cout << "Tail of the list: " << showTail(List) << std::endl;
            }break;
            case 4: {
                std::cout << "Enter a position: ";
                std::cin >> position_DList;

                while (position_DList > limit_DList){
                    std::cout << "Exceeding the limit, enter again: " << std::endl;
                    std::cin >> position_DList;
                }
                while (position_DList < 1){
                    std::cout << "Invalid position, enter again: " << std::endl;
                    std::cin >> position_DList;
                }

                long Info = showInfoAtPosition(List, position_DList);
                if (Info == LONG_MIN)
                    std::cout << "Empty List." << std::endl;
                else if (Info == (LONG_MIN + 1))
                    std::cout << "Unable to find data at the specified position." << std::endl;
                else
                    std::cout << "Info at " << position_DList << " is " << Info << std::endl;
            }break;
            case 5: {
                std::cout << "Enter an element: ";
                std::cin >> element_DList;
                
                long Location = findPositionOfElement(List, element_DList);
                if (Location == -1){
                    std::cout << "Empty List." << std::endl;
                }
                else if (Location == -2){
                    std::cout << "Unable to find position of " << element_DList << std::endl;
                }
                else{
                    std::cout << "Position of " << element_DList << " is " << Location << std::endl;
                }
            }break;
            case 6: {
                std::cout << "Please enter any integer number: ";
                std::cin >> data_Dynamic;
                DLNode* newNode = createNode(data_Dynamic);
                if (insertHead(List, newNode) == 1)
                    std::cout << "Successful insertion." << std::endl;
                else
                    std::cout << "Initialized Head node of the list." << std::endl;
            }break;
            case 7:{
                std::cout << "Please enter any integer number: ";
                std::cin >> data_Dynamic;
                DLNode* newNode = createNode(data_Dynamic);
                if (insertTail(List, newNode) == 1)
                    std::cout << "Successful insertion." << std::endl;
                else
                    std::cout << "Initialized Tail node of the list." << std::endl;
            }break;
            case 8:{
                std::cout << "Please enter any integer number: ";
                std::cin >> data_Dynamic;
                std::cout << "Please enter position do you want to insert: ";
                std::cin >> position_DList;
                
                std::cout << "Choose your option (1 to insert before a node & 0 to insert after a node): ";
                std::cin >> option_DList;
                while (!(option_DList >= 0 && option_DList <= 1)) {
                    std::cout << "Your choice is invalid, please try again: ";
                    std::cin >> option_DList;
                }

                short int insertResult = insert(List, position_DList, option_DList, data_Dynamic);
                while (insertResult == 1){
                    std::cout << "The position which you enter has exceeded the limitation of the list, enter position again: " << std::endl;
                    std::cin >> position_DList;
                }
                while (insertResult == 2){
                    std::cout << "The position you entered is less than the limit of the list, enter position again: " << std::endl;
                    std::cin >> position_DList;
                }
                if (insertResult == 3){
                    std::cout << "Failed insertion." << std::endl;
                }
                else{
                    std::cout << "Successful insertion." << std::endl;
                }
            }break;
            default:{
                return data_structures_program();
            }break;
        }
    }
}

void algorithms_menu(){
    // if (readFromFile_Array(Array, elementsOfArray, file_input) == -1){
    //     return;
    // }
    while(1==1){
        menu_options = algorithms_selection();
        switch (menu_options){
            case 1:{
                display_title("Name of Searching Algorithm", searching_algorithms);
                searching_menu();
            }break;
            case 2:{
                display_title("Name of Sorting Algorithm", sorting_algorithms);
                sorting_menu();
            }break;
            default:{
                return main_program();
            }break;
        }
    }
}
void searching_menu(){
    while(1==1){
        menu_options = searching_selection();
        menu_choices = menu_options - 1;
        switch(menu_options){
            case 1: {
                display_notification("You chose ", searching_algorithms, menu_options, menu_choices);
                searchKey = enterKey();

                std::cout << algorithms[menu_choices].name << running_status << std::endl;
                auto startTime = std::chrono::high_resolution_clock::now();
                SearchResult = LinearSearch(Array, elementsOfArray, searchKey);
                auto endTime = std::chrono::high_resolution_clock::now();
                auto SearchingTime = std::chrono::duration_cast<std::chrono::microseconds>(endTime - startTime);

                announceSearchingTime(menu_choices, searchKey, SearchResult, SearchingTime);
            }break;
            case 2: {
                display_notification("You chose ", searching_algorithms, menu_options, menu_choices);
                searchKey = enterKey();

                std::cout << algorithms[menu_choices].name << running_status << std::endl;
                auto startTime = std::chrono::high_resolution_clock::now();
                SearchResult = BinarySearch(Array, elementsOfArray, searchKey);
                auto endTime = std::chrono::high_resolution_clock::now();
                auto SearchingTime = std::chrono::duration_cast<std::chrono::microseconds>(endTime - startTime);

                announceSearchingTime(menu_choices, searchKey, SearchResult, SearchingTime);
            }break;
            default:{
                return algorithms_program();
            }break;
        }
    }
}
void sorting_menu(){
    while(1==1){
        menu_options = sorting_selection();
        menu_choices = menu_options - 1;
        switch (menu_options){
            case 1: {
                display_notification("You chose ", sorting_algorithms, menu_options, menu_choices);
                if (readFromFile_Array(Array, elementsOfArray, file_input) == -1)
                    return;

                std::cout << algorithms[menu_choices].name << running_status << std::endl;
                auto startSort = std::chrono::high_resolution_clock::now();
                quickSort(Array, 0, elementsOfArray - 1);
                auto endSort = std::chrono::high_resolution_clock::now();
                auto SortingTime = std::chrono::duration_cast<std::chrono::microseconds>(endSort - startSort);

                announceSortingTime(menu_choices, SortingTime);

                exportToFile(Array, elementsOfArray, file_Output);
            }break;
            case 2: {
                display_notification("You chose ", sorting_algorithms, menu_options, menu_choices);
                if (readFromFile_Array(Array, elementsOfArray, file_input) == -1)
                    return;

                std::cout << algorithms[menu_choices].name << running_status << std::endl;
                auto startSort = std::chrono::high_resolution_clock::now();
                mergeSort(Array, 0, elementsOfArray - 1);
                auto endSort = std::chrono::high_resolution_clock::now();
                auto SortingTime = std::chrono::duration_cast<std::chrono::microseconds>(endSort - startSort);

                announceSortingTime(menu_choices, SortingTime);

                exportToFile(Array, elementsOfArray, file_Output);
            }break;
            case 3: {
                display_notification("You chose ", sorting_algorithms, menu_options, menu_choices);
                if (readFromFile_Array(Array, elementsOfArray, file_input) == -1)
                    return;

                std::cout << algorithms[menu_choices].name << running_status << std::endl;
                auto startSort = std::chrono::high_resolution_clock::now();
                heapSort(Array, elementsOfArray);
                auto endSort = std::chrono::high_resolution_clock::now();
                auto SortingTime = std::chrono::duration_cast<std::chrono::microseconds>(endSort - startSort);

                announceSortingTime(menu_choices, SortingTime);

                exportToFile(Array, elementsOfArray, file_Output);
            }break;
            case 4: {
                display_notification("You chose ", sorting_algorithms, menu_options, menu_choices);
                if (readFromFile_Array(Array, elementsOfArray, file_input) == -1)
                    return;

                std::cout << algorithms[menu_choices].name << running_status << std::endl;
                auto startSort = std::chrono::high_resolution_clock::now();
                shellSort(Array, elementsOfArray);
                auto endSort = std::chrono::high_resolution_clock::now();
                auto SortingTime = std::chrono::duration_cast<std::chrono::microseconds>(endSort - startSort);

                announceSortingTime(menu_choices, SortingTime);

                exportToFile(Array, elementsOfArray, file_Output);
            }break;
            default:{
                return algorithms_program();
            }break;
        }
    }
}
void data_structures_menu(){
    while(1==1){
        menu_options = data_structures_selection();
        menu_choices = menu_options - 1;
        switch (menu_options) {
            case 1: {
                display_notification("You chose ", data_structures, menu_options, menu_choices);
                display_title("Name of Data Structure", data_structures);
                initDList(List);
                Double_Linked_List();
            }break;
            case 2: {
                display_notification("You chose ", data_structures, menu_options, menu_choices);
            }break;
            case 3:{
                display_notification("You chose ", data_structures, menu_options, menu_choices);
            }break;
            case 4:{
                display_notification("You chose ", data_structures, menu_options, menu_choices);
            }break;
            default:{
                return main_program();
            }break;
        }
    }
}
void menu() {
    while (1 == 1) {
        menu_options = main_selection();
        switch (menu_options) {
        case 0: {
            std::cout << "Exited the entire program..." << std::endl;
            exit(0);
        }break;
        case 1: {
            if (readFromFile_Array(Array, elementsOfArray, file_input) == -1)
                    return;
            algorithms_program();
        }break;
        case 2:{
            data_structures_program();
        }break;
        default: {
            std::cout << "Exiting..." << std::endl;
            exit(0);
        }break;
        }
    }
}
// ENTIRE PROGRAMS
// Definitions of other functions (algorithms_menu, searching_menu, sorting_menu, data_structures_menu, etc.)
void main_program() {
    display_title("Name of the Session", sessions);
    menu();
}
void algorithms_program() {
    display_title("Name of Algorithm", searching_algorithms);
    algorithms_menu();
}
void searching_program() {
    display_title("Name of Searching Algorithm", searching_algorithms);
    searching_menu();
}
void sorting_program() {
    display_title("Name of Sorting Algorithm", sorting_algorithms);
    sorting_menu();
}
void data_structures_program() {
    display_title("Name of Data Structure", data_structures);
    data_structures_menu();
}

int main() {
    while(1==1){
        main_program();
    }
    system("pause");
    return 0;
}

// struct PERFORMED_TIMES {
//     unsigned short int times;
// };
// Functions to print average processing time of every algorithm
// void printHistory(int menu_choices, std::ofstream& historyFile, std::chrono::microseconds SortingTime) {
//     historyFile << ".";
//     for (int i = 1; i <= Width01; i++) {
//         historyFile << "=";
//     }
//     historyFile << "." << std::endl;
//     historyFile << std::left << "|| " << std::setw(Align01) << "Number" << "|| " << std::setw(Align02) << "Name of Algorithms" << "|| " << std::setw(Align02) << "Average Time (microseconds)" << std::endl;
//     for (int menu_choices = 0; menu_choices < MAX_SESSIONS; menu_choices++) {
//         historyFile << std::left << "|| " << std::setw(Align01) << menu_choices + 1 << "|| " << std::setw(Align02) << algorithms[menu_choices].name << "|| " << std::setw(Align02) << SortingTime.count() << std::endl;
//     }
//     historyFile << "*";
//     for (int i = 1; i <= Width01; i++) {
//         historyFile << "=";
//     }
//     historyFile << "*" << std::endl;
// }
// void AlgorithmHistory(int menu_choices, std::chrono::microseconds SortingTime) {
//     std::ofstream historyFile(file_History);
//     if (!historyFile.is_open()) {
//         std::cerr << "Failed to open the output file." << std::endl;
//         system("pause");
//         return;
//     }
//     printHistory(menu_choices, historyFile, SortingTime);
//     historyFile.close();
// }
// float AlgorithmAverageTime(unsigned short int menu_choices, std::chrono::microseconds SortingTime, PERFORMED_TIMES Turns[]) {
//     float averageTime = 0;
//     return averageTime;
// }