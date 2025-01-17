/* A Hash Table algorithm copied from Gemini Flash 2.0 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define CAPACITY 10 // Initial capacity of the hash table

// Structure for a node in the linked list (chaining)
typedef struct Node {
    char *key;
    int value;
    struct Node *next;
} Node;

// Structure for the hash table
typedef struct HashTable {
    Node **table; // Array of pointers to Nodes (buckets)
    int size;     // Current number of elements in the hash table
    int capacity; // Current capacity of the hash table
} HashTable;

// Hash function (djb2 algorithm - good general-purpose hash)
unsigned long hash(const char *key) {
    unsigned long hash = 5381;
    int c;
    while ((c = *key++))
        hash = ((hash << 5) + hash) + c; /* hash * 33 + c */
    return hash;
}

// Create a new hash table
HashTable *createHashTable(int capacity) {
    HashTable *ht = (HashTable *)malloc(sizeof(HashTable));
    if (ht == NULL) {
        perror("Memory allocation failed");
        exit(1);
    }
    ht->table = (Node **)calloc(capacity, sizeof(Node *));
    if (ht->table == NULL) {
        perror("Memory allocation failed");
        free(ht);
        exit(1);
    }
    ht->size = 0;
    ht->capacity = capacity;
    return ht;
}

// Insert a key-value pair into the hash table
void insert(HashTable *ht, const char *key, int value) {
    if (ht == NULL || key == NULL) {
        return; // Handle NULL input
    }
    int index = hash(key) % ht->capacity;

    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL) {
        perror("Memory allocation failed");
        exit(1);
    }
    newNode->key = strdup(key); // Duplicate the key!
    if (newNode->key == NULL) {
        perror("Memory allocation failed");
        free(newNode);
        exit(1);
    }
    newNode->value = value;
    newNode->next = ht->table[index]; // Insert at the head of the list
    ht->table[index] = newNode;
    ht->size++;
}

// Search for a value by key
int search(HashTable *ht, const char *key) {
    if (ht == NULL || key == NULL) {
        return -1; // Indicate not found for NULL input
    }
    int index = hash(key) % ht->capacity;
    Node *current = ht->table[index];
    while (current != NULL) {
        if (strcmp(current->key, key) == 0) {
            return current->value; // Found
        }
        current = current->next;
    }
    return -1; // Not found
}

// Delete a key-value pair from the hash table
bool delete(HashTable *ht, const char *key) {
    if (ht == NULL || key == NULL) {
        return false;
    }

    int index = hash(key) % ht->capacity;
    Node *current = ht->table[index];
    Node *prev = NULL;

    while (current != NULL) {
        if (strcmp(current->key, key) == 0) {
            if (prev == NULL) {
                ht->table[index] = current->next; // Removing the head
            } else {
                prev->next = current->next;
            }
            free(current->key);
            free(current);
            ht->size--;
            return true; // Successfully deleted
        }
        prev = current;
        current = current->next;
    }
    return false; // Key not found
}

// Free the memory used by the hash table
void freeHashTable(HashTable *ht) {
    if (ht == NULL) return;
    if (ht->table != NULL) {
        for (int i = 0; i < ht->capacity; i++) {
            Node *current = ht->table[i];
            while (current != NULL) {
                Node *temp = current;
                current = current->next;
                free(temp->key);
                free(temp);
            }
        }
        free(ht->table);
    }
    free(ht);
}

int main() {
    HashTable *myHashTable = createHashTable(CAPACITY);

    insert(myHashTable, "apple", 10);
    insert(myHashTable, "banana", 20);
    insert(myHashTable, "cherry", 30);

    printf("Value of apple: %d\n", search(myHashTable, "apple"));   // Output: 10
    printf("Value of banana: %d\n", search(myHashTable, "banana")); // Output: 20
    printf("Value of grape: %d\n", search(myHashTable, "grape"));   // Output: -1 (not found)

    if (delete(myHashTable, "banana")) {
        printf("Deleted banana\n");
    }
    printf("Value of banana after deletion: %d\n", search(myHashTable, "banana")); // Output: -1

    freeHashTable(myHashTable); // Free memory

    return 0;
}