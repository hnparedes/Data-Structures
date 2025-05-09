#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdlib>
using namespace std;

// Global file pointer for output file
FILE *outfile;

// Class definition for item nodes (items within each tree)
class itemNode {
public:
    char name[50]; // Item name
    int count;      // Item count
    itemNode *left, *right; // Pointers to left and right child nodes

    // Constructor to initialize an item node
    itemNode(char itemName[], int population) {
        strcpy(name, itemName); // Copy item name
        count = population;     // Set item count
        left = NULL;            // Initialize left child to NULL
        right = NULL;           // Initialize right child to NULL
    }
};

// Class definition for tree name nodes (main tree holding tree names)
class treeNameNode {
public:
    char treeName[50];      // Tree name
    treeNameNode *left, *right; // Pointers to left and right child nodes
    itemNode *theTree;      // Pointer to the root of the item tree for this tree name

    // Constructor to initialize a tree name node
    treeNameNode(char name[]) {
        strcpy(treeName, name); // Copy tree name
        theTree = NULL;         // Initialize item tree to NULL
        left = NULL;            // Initialize left child to NULL
        right = NULL;           // Initialize right child to NULL
    }
};

// Function to insert an item node into an item tree (BST)
void insertItemNode(itemNode*& root, char itemName[], int count) {
    if (root == NULL) { // If tree is empty, create a new node
        root = new itemNode(itemName, count);
        return;
    }
    if (strcmp(itemName, root->name) < 0) { // If item name is less, insert in left subtree
        insertItemNode(root->left, itemName, count);
    } else if (strcmp(itemName, root->name) > 0) { // If item name is greater, insert in right subtree
        insertItemNode(root->right, itemName, count);
    } else { // If item name already exists, add to the count
        root->count += count;
    }
}

// Function to insert a tree name node into the main tree (BST)
treeNameNode* insertTreeNameNode(treeNameNode* root, char treeName[]) {
    if (root == NULL) { // If tree is empty, create a new node
        return new treeNameNode(treeName);
    }
    if (strcmp(treeName, root->treeName) < 0) { // If tree name is less, insert in left subtree
        root->left = insertTreeNameNode(root->left, treeName);
    } else { // If tree name is greater, insert in right subtree
        root->right = insertTreeNameNode(root->right, treeName);
    }
    return root;
}

// Function to search for a tree by name in the main tree
treeNameNode* searchTree(treeNameNode* root, char treeName[]) {
    if (root == NULL) {
        return NULL; // If tree not found, return NULL
    }
    if (strcmp(treeName, root->treeName) == 0) {
        return root; // If tree found, return node
    }
    if (strcmp(treeName, root->treeName) < 0) {
        return searchTree(root->left, treeName); // Search left subtree
    }
    return searchTree(root->right, treeName); // Search right subtree
}

// Function to search for an item within a specific item tree
void searchItem(treeNameNode* root, char treeName[], char itemName[]) {
    treeNameNode* treeNode = searchTree(root, treeName); // Find the tree node
    if (treeNode == NULL) { // If tree does not exist
        fprintf(outfile, "\n%s does not exist", treeName);
        return;
    }

    itemNode* current = treeNode->theTree; // Start search from the item tree root
    while (current != NULL) {
        if (strcmp(itemName, current->name) == 0) { // If item found
            fprintf(outfile, "\n%d %s found in %s", current->count, itemName, treeName);
            return;
        }
        current = (strcmp(itemName, current->name) < 0) ? current->left : current->right; // Move to left or right child
    }
    fprintf(outfile, "\n%s not found in %s", itemName, treeName); // Item not found
}

// Function to traverse tree names in order (inorder traversal)
void traverseTreeNames(treeNameNode* root) {
    if (root == NULL) { 
        return;
    }
    traverseTreeNames(root->left); // Traverse left subtree
    fprintf(outfile, "%s ", root->treeName); // Print tree name
    traverseTreeNames(root->right); // Traverse right subtree
}

// Function to traverse and print items in order (inorder traversal)
void traverseItemTree(itemNode* root) {
    if (root == NULL) {
        return;
    }
    traverseItemTree(root->left); // Traverse left subtree
    fprintf(outfile, "%s ", root->name); // Print item name
    traverseItemTree(root->right); // Traverse right subtree
}

// Function to print all trees and their items in order
void traverseAllTrees(treeNameNode* root) {
    if (root == NULL) {
        return;
    }
    traverseAllTrees(root->left); // Traverse left subtree
    fprintf(outfile, "\n***%s***\n", root->treeName); // Print tree name header
    traverseItemTree(root->theTree); // Print items in this tree
    traverseAllTrees(root->right); // Traverse right subtree
}

// Function to compute the height of an item tree
int height(itemNode* root) {
    if (root == NULL) {
        return 0;
    }
    return max(height(root->left), height(root->right)) + 1; // Recursively compute height
}

// Function to compute tree balance and print balance information
void heightBalance(treeNameNode* root, char treeName[]) {
    treeNameNode* treeNode = searchTree(root, treeName); // Find the tree node
    if (treeNode == NULL) {
        fprintf(outfile, "\n%s does not exist", treeName);
        return;
    }

    int leftHeight = height(treeNode->theTree->left); // Get height of left subtree
    int rightHeight = height(treeNode->theTree->right); // Get height of right subtree
    int diff = abs(leftHeight - rightHeight); // Compute height difference

    fprintf(outfile, "\n%s: left height %d, right height %d, difference %d, %sbalanced",
        treeName, leftHeight, rightHeight, diff, (diff > 1) ? "not " : ""); // Print balance info
}

// Function to count the total number of items in an item tree
int countTotalItems(itemNode* root) {
    if (root == NULL) {
        return 0;
    }
    return root->count + countTotalItems(root->left) + countTotalItems(root->right); // Recursively count items
}

void countItems(treeNameNode* root, char treeName[]) {
    treeNameNode* treeNode = searchTree(root, treeName); // Find tree node
    if (treeNode == NULL) {
        fprintf(outfile, "\n%s does not exist", treeName);
        return;
    }
    fprintf(outfile, "\n%s count %d", treeName, countTotalItems(treeNode->theTree)); // Print item count
}

// Function to count items before a given item in a tree (alphabetically)
int countItemsBefore(itemNode* root, char itemName[]) {
    if (root == NULL) {
        return 0;
    }
    if (strcmp(itemName, root->name) <= 0) { // If current item is greater or equal to target
        return countItemsBefore(root->left, itemName); // Check left subtree
    } else {
        return countItemsBefore(root->left, itemName) + 1 + countItemsBefore(root->right, itemName); // Check left, current, and right
    }
}

void itemBefore(treeNameNode* root, char treeName[], char itemName[]) {
    treeNameNode* treeNode = searchTree(root, treeName); // Find tree node
    if (treeNode == NULL) {
        fprintf(outfile, "\n%s does not exist", treeName);
        return;
    }
    fprintf(outfile, "\nitem before %s: %d", itemName, countItemsBefore(treeNode->theTree, itemName)); // print item before count
}

int main() {
    FILE* infile = fopen("in.txt", "r"); // Open input file "in.txt" for reading
    outfile = fopen("out.txt", "w"); // Open output file "out.txt" for writing

    int N, I, Q; // Declare variables to store number of tree names, items, and queries
    fscanf(infile, "%d %d %d", &N, &I, &Q); // Read N, I, and Q from the input file

    treeNameNode* root = NULL; // Initialize the root of the tree name tree to NULL
    char treeName[50]; // Declare a character array to store tree names

    // Read tree names from the input file and insert them into the tree name tree
    for (int i = 0; i < N; ++i) {
        fscanf(infile, "%s", treeName); // Read a tree name from the input file
        root = insertTreeNameNode(root, treeName); // Insert the tree name into the tree
    }

    traverseTreeNames(root); // Traverse the tree name tree and print the tree names to the output file

    // Read item data from the input file and insert them into the corresponding item trees
    for (int i = 0; i < I; ++i) {
        char itemName[50]; // Declare a character array to store item names
        int count; // Declare a variable to store item counts
        fscanf(infile, "%s %s %d", treeName, itemName, &count); // Read item data from the input file
        treeNameNode* treeNode = searchTree(root, treeName); // Find the tree name node
        if (treeNode) { // If the tree name node exists
            insertItemNode(treeNode->theTree, itemName, count); // Insert the item into the item tree
        }
    }

    traverseAllTrees(root); // Traverse all trees and print their items to the output file

    // Process queries from the input file
    for (int i = 0; i < Q; ++i) {
        char command[50], param1[50], param2[50]; // Declare character arrays to store command and parameters
        fscanf(infile, "%s %s", command, param1); // Read the command and the first parameter

        // Process different types of queries
        if (strcmp(command, "search") == 0) { // If the command is "search"
            fscanf(infile, "%s", param2); // Read the second parameter (item name)
            searchItem(root, param1, param2); // Search for the item and print the result
        } else if (strcmp(command, "height_balance") == 0) { // If the command is "height_balance"
            heightBalance(root, param1); // Check the height balance of the tree and print the result
        } else if (strcmp(command, "count") == 0) { // If the command is "count"
            countItems(root, param1); // Count the items in the tree and print the result
        } else if (strcmp(command, "item_before") == 0) { // If the command is "item_before"
            fscanf(infile, "%s", param2); // Read the second parameter (item name)
            itemBefore(root, param1, param2); // Count items before the given item and print the result
        } else if (strcmp(command, "search") == 0) { // If the command is "search"
            fscanf(infile, "%s", param2); // Read the second parameter (item name)
            searchItem(root, param1, param2); // Search for the item and print the result
        }
    }

    fclose(infile); // Close the input file
    fclose(outfile); // Close the output file

    // Print the content of "out.txt" to the console
    ifstream outFileStream("out.txt"); // Open "out.txt" for reading
    if (outFileStream.is_open()) { // If the file is opened successfully
        string line; // Declare a string variable to store each line
        while (getline(outFileStream, line)) { // Read each line from the file
            cout << line << endl; // Print the line to the console
        }
        outFileStream.close(); // Close the output file stream
    } else { // If the file cannot be opened
        cout << "Unable to open out.txt" << endl; // Print an error message
    }

    return 0; // Return 0 to indicate successful execution
}