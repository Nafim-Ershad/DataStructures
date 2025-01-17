#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define __CAPACITY__ 100

typedef struct Node {
    char* key;
    int value;
    struct Node* next;
} Node;

typedef struct HashTable {
    unsigned int size, capacity;
    Node** arr;
} HashTable;

// Hash function (djb2 algorithm - good general-purpose hash)
unsigned long hashFunction(const char *key) {
    unsigned long hash = 5381;
    int c;
    while ((c = *key++))
        hash = ((hash << 5) + hash) + c; /* hash * 33 + c */
    return (hash % __CAPACITY__);
}

HashTable *createTable()
{
    HashTable* ht = (HashTable*)malloc(sizeof(HashTable));
    if (ht == NULL) {
        perror("Memory allocation failed\n");
        exit(1);
    }

    ht->arr = (Node**)calloc(__CAPACITY__, sizeof(Node*));
    if (ht->arr == NULL) {
        perror("Memory allocation failed\n");
        free(ht);
        exit(1);
    }

    ht->size = 0;
    ht->capacity = __CAPACITY__;
    return ht;
}

void insert(HashTable* ht, const char* key, int value)
{
    if(ht == NULL)
    {
        perror("No Hash Table created!!\n");
        exit(1);
    }

    if(key == NULL)
    {
        perror("No key provided\n");
        exit(1);
    }

    int index = hashFunction(key);

    Node* newNode = (Node*)malloc(sizeof(Node));
    if(newNode == NULL)
    {
        perror("Failed to create Node\n");
        exit(1);
    }
    newNode->key = strdup(key); // Duplicates key since the param is a const char*
    newNode->value = value;
    newNode->next = ht->arr[index];
    ht->arr[index] = newNode;
    
    ht->size++;
}

void delete(HashTable* ht, const char* key)
{
    if(ht == NULL)
    {
        perror("No Hashtable referenced -> Delete Function\n");
        exit(1);
    }

    if(key == NULL)
    {
        perror("No key provided -> Delete Function\n");
        exit(1);
    }

    int index = hashFunction(key);
    Node* curr = ht->arr[index];
    Node* prev = NULL;

    while(curr != NULL)
    {
        if(strcmp(curr->key, key) == 0)
        {
            if(prev == NULL)
            {
                // If its in the very first NODE
                ht->arr[index] = curr->next;
            }
            else
            {
                // Changes the ponter of previous to the next of current
                prev->next = curr->next;
            }
            // Frees up memory for current and the next pointer
            free(curr->next);
            free(curr);

            ht->size--;
            return;
        }

        prev = curr;
        curr = curr->next;
    }
    return;
}

int search(HashTable *ht, const char* key)
{
    if(ht == NULL)
    {
        perror("No Hash Table created -> Search\n");
        exit(1);
    }
    if(key == NULL)
    {
        perror("No key passed -> Search\n");
        exit(1); 
    }

    int index = hashFunction(key);
    Node* current = ht->arr[index];

    while(current != NULL)
    {
        if(strcmp(current->key, key) == 0)
        {
            return current->value;
        }

        current = current->next;
    }

    printf("No value found for key: %s\n", key);
    exit(1);
}

int main()
{
    HashTable* h = createTable();

    insert(h, "age", 24);
    insert(h, "height", 184);
    insert(h, "weight", 90);

    printf("Age is: %d\n", search(h, "age"));
    delete(h, "age");
    printf("Age is: %d\n", search(h, "age"));

    return 1;
}