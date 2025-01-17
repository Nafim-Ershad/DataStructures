#include <iostream>
#include <string.h>

// Linked List Node
class Node
{
public:
    const char* key;
    const char* value;
    Node* next;

    Node(const char* key, const char* value)
    {
        this->key = key;
        this->value = value;
        this->next = nullptr;
    }
};

// Hash Map
class HashMap
{
    // Current number of elements in hashMap
    // and capacity of hashMap
    int numOfElements, capacity;

    // hold base address array of linked list
    Node** arr;

    // Hash function to find index of key
    int hashFunction(const char* key)
    {
        int bucketIndex;
        int sum=0, factor=31;

        const int FACTOR = 31;
        // Sum of ASCII values of all characters
        for (int i = 0; i < strlen(key); i++) {
            // sum = sum + (ascii value of
            // char * (primeNumber ^ x))...
            // where x = 1, 2, 3....n
            sum = ((sum % capacity) + (((int)key[i]) * factor) % capacity) % capacity;
            // factor = factor * prime
            // number....(prime
            // number) ^ x
            factor = ((factor % __INT16_MAX__) * (FACTOR % __INT16_MAX__)) % __INT16_MAX__;
        }
        bucketIndex = sum;
        return bucketIndex;
    }

public:
    HashMap()
    {
        // Initial capacity of hashMap
        capacity = 20;
        numOfElements = 0;

        // Create an array of Node* with size capacity
        arr = new Node*[capacity];

        // Initialize all elements of array as nullptr
        for (int i = 0; i < capacity; i++)
            arr[i] = nullptr;
    }

    void insert(const char* key, const char* value)
    {
        // Find the index of the key
        int bucketIndex = hashFunction(key);

        // Create a new node with key and value
        Node* newNode = new Node(key, value);

        if(arr[bucketIndex] == nullptr)
        {
            // If the bucket is empty, insert the node
            arr[bucketIndex] = newNode;
            numOfElements++;
            return;
        }
        // Collision
        // Adding newNode at the head of
        // linked list which is present
        // at bucket index....insertion at
        // head in linked list is done to
        // Insert the node in the linked list at the index
        newNode->next = arr[bucketIndex]; // Insert old head as next of new node
        arr[bucketIndex] = newNode; // Replacing old head with new node

        // Increment the number of elements
        numOfElements++;
    }

    void deleteKey(const char* key)
    {
        // Getting bucket index for the
        // given key
        int bucketIndex = hashFunction(key); // Might be same for different keys
        Node* prev = nullptr;
        // Points to the head of
        // linked list present at
        // bucket index

        Node* currNode = arr[bucketIndex]; // Instead of iterating, O(1) time is used to find and delete key
        // iterating through linked list if it exists
        while(currNode != nullptr)
        {
            // If key is found
            if(strcmp(currNode->key, key) == 0)
            {
                // If the key is found, delete the node
                if(prev == nullptr)
                {
                    // If the key is found at the head of the linked list
                    // Update the head of the linked list to the next node
                    arr[bucketIndex] = currNode->next;
                }
                else
                {
                    // If the key is found in the middle of the linked list
                    prev->next = currNode->next; // Update the next of the previous node to the next of the current node
                }
                // Delete the node
                delete currNode;
                numOfElements--;
                return;
            }
            prev = currNode;
            currNode = currNode->next;
        }

    }

    const char* search(const char* key)
    {
        // Getting the bucket index for the given key
        int bucketIndex = hashFunction(key);
        Node* bucketHead = arr[bucketIndex];

        while(bucketHead != nullptr)
        {
            // looping through the linked list
            // at the bucket index

            // If the key is found, return the value
            if(strcmp(bucketHead->key, key) == 0)
            {
                return bucketHead->value;
            }

            bucketHead = bucketHead->next;
        }

        // If no key found in the hashMap equal to the given key
        const char* errorMsg = "Oops! Key not found!";
        return errorMsg;
    }

    ~HashMap()
    {
        // Delete all the nodes in the hashMap
        for (int i = 0; i < capacity; i++)
        {
            Node* temp = arr[i];
            while (temp != nullptr)
            {
                Node* prev = temp;
                temp = temp->next;
                delete prev;
            }
        }

        // Delete the array
        delete[] arr;
    }
};


int main()
{
    HashMap hashMap = HashMap();
    hashMap.insert("name", "John");
    hashMap.insert("age", "24");
    hashMap.insert("phone", "+8801869265844");

    hashMap.deleteKey("name");

    std::cout << hashMap.search("age") << std::endl;
    std::cout << hashMap.search("name") << std::endl;

    return 0;
}