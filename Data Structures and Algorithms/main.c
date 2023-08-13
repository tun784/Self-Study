#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#define MAX 517440
#define MAX_SESSIONS 2
#define MAX_ALGORITHMS 2
#define MAX_SEARCHING_ALGORITHMS 2
#define MAX_SORTING_ALGORITHMS 4
#define MAX_DATA_STRUCTURES 4
#define MAX_DOUBLE_LINKED_LIST_OPTIONS 8
#define LENGTH 40
//FLUSH FUNCTIONS
void flushFile(FILE* f) {
    int c;
    while ((c = fgetc(f)) != '\n' && c != EOF);
}
void flushStdin() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}
// DATA STRUCTURE
// LINKED LIST
typedef struct DOUBLE_LINKED_LIST_NODE {
    int info;
    struct DOUBLE_LINKED_LIST_NODE* prev;
    struct DOUBLE_LINKED_LIST_NODE* next;
}DLNode;
typedef struct DOUBLE_LINKED_LIST {
    DLNode* head;
    DLNode* tail;
}DLIST;

unsigned int limit_DList = 0;
unsigned int current_position;
unsigned int position_DList;
long element_DList;
short int option_DList;
short int choices_DList;
long data_Dynamic;

DLNode* createNode(int data){
    DLNode *newNode = (DLNode*)malloc(sizeof(DLNode));
    if (!newNode) {
        printf("Not enough space to create Node\n");
        return NULL;
    }
    newNode->info = data;
    newNode->next = newNode->prev = NULL;
    return newNode;
}
short int isEmpty(DLIST* List) {
    if (List->head == NULL)
        return 1;
    else
        return 0;
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
        printf("Empty List.\n");;
        return;
    }
    DLNode* node;
    if (option_DList) {
        node = List->head;
        while (node) {
            printf(node->info," ");
            node = node->next;
        }
    }
    else {
        node = List->tail;
        while (node) {
            printf(node->info," ");
            node = node->prev;
        }
    }
    printf("\n");
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
typedef struct STACK_NODE {
    int info;
    struct STACK_NODE* next;
}STACK_NODE;
typedef struct STACK {
    struct STACK_NODE* Top;
}STACK;
//QUEUE
typedef struct QUEUE_NODE {
    int info;
    struct QUEUE_NODE* next;
}QUEUE_NODE;
typedef struct QUEUE {
    struct QUEUE_NODE* head;
}QUEUE;
// TREE
typedef struct BINARY_SEARCH_TREE_NODE {
    int info;
    struct BINARY_SEARCH_TREE_NODE* left;
    struct BINARY_SEARCH_TREE_NODE* right;
}BST_NODE;
typedef struct AVL_BINARY_SEARCH_TREE{
    BST_NODE* Root;
}BST;
//SESSIONS
typedef struct SESSION {
    char name[LENGTH];
}SESSION;
SESSION sessions[] = {
    {"Algorithm"},
    {"Data Structure"}
};
SESSION algorithms[] = {
    {"Searching Algorithm"},
    {"Sorting Algorithm"}
};
SESSION searching_algorithms[] = {
    {"Linear Search"},
    {"Binary Search"}
};
SESSION sorting_algorithms[] = {
    {"Quick Sort"},
    {"Merge Sort"},
    {"Heap Sort"},
    {"Shell Sort"}
};
SESSION data_structures[] = {
    {"Double Linked List"},
    {"Stack"},
    {"Queue"},
    {"Binary Search Tree"}
};
SESSION double_linked_list_options[] = {
    {"Show all List"},
    {"Show head node"},
    {"Show tail node"},
    {"Show info of an element"},
    {"Find position of a specified element"},
    {"Insert Head"},
    {"Insert Tail"},
    {"Insert Middle"}
};

//Function prototypes
void announceProcessingTime(clock_t ProcessingTime);
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

int readFromFile_Array(long* Array, long* sizeOfArray, char file_Input[]) {
    FILE* file = fopen(file_Input, "r");
    if (!file)
    //if (!outputFile.is_open())
    //file.fail()
    {
        printf("Can't find the specified file\n");
        return -1;
    }
    fscanf(file, "%ld", *sizeOfArray);
    if (*sizeOfArray < 1) {
        printf("Invalid amount of array\n");
        return -1;
    }
    for (long i = 0; i < *sizeOfArray; i++)
        fscanf(file, "%ld", &Array[i]);
    fclose(file);
    return 1;
}
short int readFromFile_DynamicAllocation(DLIST* List, char file_input[], long* data) {
    FILE* file = fopen(file_input, "r");
    
    if (!file)
    //if (!outputFile.is_open())
    //file.fail()
    {
        printf("Unable to open the file.\n");
        return 0;
    }

    DLNode* newNode;
    unsigned int limitation;
    unsigned int i = 0;

    if (fscanf(file, "%u", &limitation) != 1) {
        printf("Error reading limit from file.\n");
        fclose(file);
        return 0; //Failed
    }

    clock_t startTime = clock();
    while (i < limitation) {
        if (fscanf(file, "%ld", data) != 1) {
            printf("Error reading data from file.\n");
            fclose(file);
            return 0; //Failed
        }
        newNode = createNode(*data);
        insertTail(List, newNode);
        i++;
    }
    clock_t endTime = clock();
    clock_t ProcessingTime = endTime - startTime;
    printf("Elements of the List: %d\n", limit_DList);
    announceProcessingTime(ProcessingTime);
    fclose(file);
    return 1;
}

short int exportToFile(long Array[], long sizeOfArray, char file_Output[]) {
    FILE* outputFile = fopen(file_Output, "w");
    if (!outputFile) {
        fprintf(stderr, "Failed to open the output file.\n");
        return 0; //Failed
    }
    for (int i = 0; i < sizeOfArray; ++i) {
        fprintf(outputFile, "%ld\n", Array[i]);
    }
    fclose(outputFile);
    return 1; //Successfully export
}

// SEARCHING ALGORITHMS
long LinearSearch(long Array[], long sizeOfArray, long searchKey) {
    for (long i = 0; i < sizeOfArray; i++)
        if (Array[i] == searchKey)
            return i;
    return -1; //Can't find out
}

long BinarySearch(long Array[], long sizeOfArray, long searchKey) {
    long left = 0;
    long right = sizeOfArray - 1;
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
void swap(long* x, long* y) {
    long temp = *x;
    *x = *y;
    *y = temp;
}
// Function to merge two subarrays of Array[]
// First subarray is Array[low..mid]
// Second subarray is Array[mid+1..high]
void merge(long Array[], long left, long mid, long right) {
    long N1 = mid - left + 1;
    long N2 = right - mid;
    // Create temporary arrays
    long* Left = (long*)malloc(N1 * sizeof(long));
    long* Right = (long*)malloc(N2 * sizeof(long));

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
    free(Left);
    free(Right);
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
            swap(&Array[i], &Array[j]);
        }
    }

    swap(&Array[i + 1], &Array[right]);
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
void heapify(long Array[], long sizeOfArray, long rootIndex) {
    long largest = rootIndex; // Initialize largest as root
    long leftChild = 2 * rootIndex + 1; // Left child
    long rightChild = 2 * rootIndex + 2; // Right child
    // If left child is larger than root
    if (leftChild < sizeOfArray && Array[leftChild] > Array[largest])
        largest = leftChild;
    // If right child is larger than current largest
    if (rightChild < sizeOfArray && Array[rightChild] > Array[largest])
        largest = rightChild;
    // If largest is not root
    if (largest != rootIndex) {
        swap(&Array[rootIndex], &Array[largest]);
        // Recursively heapify the affected sub-tree
        heapify(Array, sizeOfArray, largest);
    }
}

// Main function to perform heap sort
void heapSort(long Array[], long sizeOfArray) {
    // Build the heap (rearrange the array)
    for (long i = sizeOfArray / 2 - 1; i >= 0; i--)
        heapify(Array, sizeOfArray, i);
    // Extract elements one by one from the heap
    for (long i = sizeOfArray - 1; i >= 0; i--) {
        // Move the current root to the end
        swap(&Array[0], &Array[i]);
        // Call heapify on the reduced heap
        heapify(Array, i, 0);
    }
}

// Function to perform Shell Sort
void shellSort(long Array[], long sizeOfArray) {
    // Start with a large gap, then reduce the gap
    for (long gap = sizeOfArray / 2; gap > 0; gap /= 2) {
        // Perform insertion sort for elements at a specific gap
        for (long i = gap; i < sizeOfArray; i++) {
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

void showArray(long Array[], long sizeOfArray) {
    for (long i = 0; i < sizeOfArray; i++)
        printf("%ld ", Array[i]);
    printf("\n");
}

// Function to display title
void display_title(const char* title, const char* options[], int numOptions) {
    int i;
    printf("\t\t.");
    for (i = 1; i <= Width01; i++) {
        printf("=");
    }
    printf(".\n");

    printf("\t\t|| %-18s || %-58s ||\n", "Number", title);
    printf("\t\t||==================||===========================================================||\n");

    for (i = 0; i < numOptions; i++) {
        printf("\t\t|| %-18d || %-58s ||\n", i + 1, options[i]);
    }

    printf("\t\t*");
    for (i = 1; i <= Width01; i++) {
        printf("=");
    }
    printf("*\n");
}

// Function to display notification
void display_notification(const char* message, const char* itemName, int option) {
    printf("%s%d: %s\n", message, option, itemName);
}

// Function to perform menu selection
int menu_selection(const char* prompt, int maxOptions) {
    int option;
    printf("%s", prompt);
    scanf("%d", &option);
    while (!(option >= 0 && option <= maxOptions)) {
        printf("Your choice is invalid, please try again: ");
        scanf("%d", &option);
    }
    return option;
}
// MENU SELECTION
short int main_selection() {
    return menu_selection("Choose your session (press number 0 for exiting the program): ", sizeof(sessions) / sizeof(sessions[0]));
}
short int algorithms_selection() {
    return menu_selection("Choose your algorithm (press number 0 to return to the menu): ", sizeof(algorithms) / sizeof(algorithms[0]));
}
short int searching_selection() {
    return menu_selection("Choose your searching algorithm (press number 0 to return to the menu): ", sizeof(searching_algorithms) / sizeof(searching_algorithms[0]));
}
short int sorting_selection() {
    return menu_selection("Choose your sorting algorithm (press number 0 to return to menu): ", sizeof(sorting_algorithms) / sizeof(sorting_algorithms[0]));
}
short int choices_DList_selection() {
    return menu_selection("Choose your test (press number 0 to cancel): ", sizeof(double_linked_list_options) / sizeof(double_linked_list_options[0]));
}

long enterKey() {
    long searchKey;
    printf("Please enter your number: ");
    scanf("%ld", &searchKey);
    return searchKey;
}

void announceSearchingTime(int choices, long searchKey, long SearchResult, clock_t SearchingTime) {
    if (SearchResult == -1) {
        printf("%ld wasn't found.\n", searchKey);
    }
    else {
        printf("%ld was found at index Array[%ld]\n", searchKey, SearchResult);
    }
    printf("%s Time: %ld microseconds\n\n", algorithms[choices].name, SearchingTime);
}
void announceSortingTime(int choices, clock_t SortingTime) {
    printf("%s Time: %ld microseconds\n\n", algorithms[choices].name, SortingTime);
}
void announceProcessingTime(clock_t ProcessingTime) {
    printf("Processing Time: %ld microsecondss\n\n", ProcessingTime);
}

void Double_Linked_List() {
    DLIST* List = (DLIST*)malloc(sizeof(DLIST));
    if (!readFromFile_DynamicAllocation(List, file_input, data_Dynamic)) {
        return data_structures_menu();
    }

    while (1) {
        choices_DList = choices_DList_selection();
        switch (choices_DList) {
        case 1: {
            printf("Choose your option (1 to output from head to tail & 0 to output from tail to head): ");
            scanf("%d", &option_DList);
            while (!(option_DList >= 0 && option_DList <= 1)) {
                printf("Your choice is invalid, please try again: ");
                scanf("%d", &option_DList);
            }
            showAllDList(List, option_DList);
        }break;

        case 2: {
            printf("Head of the list: %ld\n", showHead(List));
        }break;

            // Cases for other options...

        default: {
            return data_structures_program();
        }break;
        }
    }
}

// Similar functions for algorithms_menu(), searching_menu(), sorting_menu(), and data_structures_menu()

void menu() {
    while (1) {
        menu_options = main_selection();
        switch (menu_options) {
        case 0: {
            printf("Exited the entire program...\n");
            exit(0);
        }break;
        case 1: {
            if (readFromFile_Array(Array, elementsOfArray, file_input) == -1)
                return;
            algorithms_program();
        }break;

            // Cases for other options...

        default: {
            printf("Exiting...\n");
            exit(0);
        }break;
        }
    }
}
// Definitions of other functions (algorithms_menu, searching_menu, sorting_menu, data_structures_menu, etc.)

void main_program() {
    display_title("Name of the Session", sessions, sizeof(sessions) / sizeof(sessions[0]));
    menu();
}

void algorithms_program() {
    display_title("Name of Algorithm", searching_algorithms, sizeof(searching_algorithms) / sizeof(searching_algorithms[0]));
    algorithms_menu();
}

void searching_program() {
    display_title("Name of Searching Algorithm", searching_algorithms, sizeof(searching_algorithms) / sizeof(searching_algorithms[0]));
    searching_menu();
}

void sorting_program() {
    display_title("Name of Sorting Algorithm", sorting_algorithms, sizeof(sorting_algorithms) / sizeof(sorting_algorithms[0]));
    sorting_menu();
}

void data_structures_program() {
    display_title("Name of Data Structure", data_structures, sizeof(data_structures) / sizeof(data_structures[0]));
    data_structures_menu();
}

int main() {
    while (1==1) {
        main_program();
    }
    _getch();
    return 0;
}