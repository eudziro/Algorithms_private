#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TABLE_SIZE 10

typedef struct Node {
    char* key;
    int value;
    struct Node* next;
} Node;

typedef struct HashTable {
    Node** table;
} HashTable;

Node* createNode(const char* key, int value) {
    Node* newNode = malloc(sizeof(Node));
    newNode->key = strdup(key);
    newNode->value = value;
    newNode->next = NULL;
    return newNode;
}

HashTable* createHashTable() {
    HashTable* hashTable = malloc(sizeof(HashTable));
    hashTable->table = malloc(sizeof(Node*) * TABLE_SIZE);
    for (int i = 0; i < TABLE_SIZE; i++) {
        hashTable->table[i] = NULL;
    }
    return hashTable;
}

unsigned int hash(const char* key) {
    unsigned int hashValue = 0;
    while (*key) {
        hashValue = (hashValue << 5) + *key++;
    }
    return hashValue % TABLE_SIZE;
}

void insert(HashTable* hashTable, const char* key, int value) {
    unsigned int index = hash(key);
    Node* newNode = createNode(key, value);
    
    newNode->next = hashTable->table[index];
    hashTable->table[index] = newNode;
}

int search(HashTable* hashTable, const char* key) {
    unsigned int index = hash(key);
    Node* current = hashTable->table[index];
    
    while (current) {
        if (strcmp(current->key, key) == 0) {
            return current->value; // Возвращаем значение
        }
        current = current->next;
    }
    return -1; // Если не найдено
}

void delete(HashTable* hashTable, const char* key) {
    unsigned int index = hash(key);
    Node* current = hashTable->table[index];
    Node* previous = NULL;

    while (current) {
        if (strcmp(current->key, key) == 0) {
            if (previous) {
                previous->next = current->next;
            } else {
                hashTable->table[index] = current->next;
            }
            free(current->key);
            free(current);
            return;
        }
        previous = current;
        current = current->next;
    }
}

void freeHashTable(HashTable* hashTable) {
    for (int i = 0; i < TABLE_SIZE; i++) {
        Node* current = hashTable->table[i];
        while (current) {
            Node* temp = current;
            current = current->next;
            free(temp->key);
            free(temp);
        }
    }
    free(hashTable->table);
    free(hashTable);
}

int main() {
    HashTable* hashTable = createHashTable();

    insert(hashTable, "apple", 1);
    insert(hashTable, "banana", 2);
    insert(hashTable, "orange", 3);

    printf("Значение для 'apple': %d\n", search(hashTable, "apple"));
    printf("Значение для 'banana': %d\n", search(hashTable, "banana"));
    printf("Значение для 'grape': %d\n", search(hashTable, "grape")); // Не найдено

    delete(hashTable, "banana");
    printf("Значение для 'banana' после удаления: %d\n", search(hashTable, "banana")); // Не найдено

    freeHashTable(hashTable);
    return 0;
}
