#include "stdio.h"
#include "stdlib.h"
#include "string.h"

typedef struct {
    char key[256];
    int value;
}map;

#define MAP_LENGTH 256

bool doesKeyExist(char *key, int value, map persons[MAP_LENGTH]);
void addToMap(const char *key, int value, map persons[MAP_LENGTH]);
void printEntireMap(map persons[MAP_LENGTH]);
void printMapKey(char *key, map persons[MAP_LENGTH]);

int main(void) {
    map persons[MAP_LENGTH] = {};
    char input[MAP_LENGTH];

    char keyBuffer[MAP_LENGTH];
    char *key = keyBuffer;

    int value;
    char *garbage;

    while (true)
    {
        // Asks the user what to do.
        printf("Options:\n"
               "    add\n"
               "    print\n"
               "    q\n"
               ">");
        scanf("%s", input);

        if (strcmp(input, "q") == 0)
        {
            printf("Goodbye!");
            break;
        }
        else if (strcmp(input, "add") == 0)
        {
            printf("Enter key>");
            scanf("%255s",key); // We limit the size of the input to 255 characters, since that is the length of our buffer, minus the null character.

            char valBuffer[MAP_LENGTH];
            char *val = valBuffer;
            printf("Enter value>");
            scanf("%255s",val);
            value = strtol(val,&garbage,10);

            printf("<--Key = %s | Value = %d-->\n", key, value);

            if (doesKeyExist(key, value, persons)) {
                printEntireMap(persons);
                continue;
            }
            else {
                addToMap(key, value, persons);
            }
            printEntireMap(persons);

        }
        else if (strcmp(input, "print") == 0)
        {
            char printerKey[MAP_LENGTH];
            printf("Enter key to print>");
            scanf("%s",printerKey);

            printMapKey(printerKey, persons);
        }
        else
        {
            printf("Invalid input\n");
        }
    }

    return 0;
}


/**
 * @brief Checks if a given key exists in the provided map and updates its corresponding value.
 *
 * This function searches through an array of map structures to find a
 * matching key. If a match is found, it updates the map's value and
 * returns true. If no match is found, it returns false.
 *
 * @param key The key to search for in the map.
 * @param value The new value to assign to the map entry if the key exists.
 * @param persons An array of map structures where each structure contains
 *                a key and a corresponding value.
 * @return true if the key exists in the map and the value is updated.
 * @return false if the key does not exist in the map.
 */
bool doesKeyExist(char *key, int value, map persons[MAP_LENGTH]) {
    //printf("%s | %d\n", key, value);
    for (int i = 0; i < MAP_LENGTH; i++) {
        if (strcmp(persons[i].key, key) == 0) {
            persons[i].value = value;
            return true;
        }
    }

    // If we get to this part, the key was not found and so doesn't exist.
    return false;
}

/**
 * @brief Adds a key-value pair to an array of map entries.
 *
 * This function iterates through the given array of map entries and
 * adds the specified key-value pair to the first empty entry found.
 *
 * If an empty entry is found, the key is copied and the value is set
 * in that entry. The function stops searching after adding the new entry.
 *
 * @param key The key to be added in the map.
 * @param value The value associated with the key.
 * @param persons An array of map entries where the key-value pair
 *                should be added. The array has a fixed length defined
 *                by MAP_LENGTH.
 */
void addToMap(const char *key, int value, map persons[MAP_LENGTH]) {
    for (int i = 0; i < MAP_LENGTH; i++) {
        if (strcmp(persons[i].key, "") == 0) {
            strcpy(persons[i].key, key);
            persons[i].value = value;
            break;
        }
    }
}

/**
 * @brief Prints all non-empty entries in the provided map array.
 *
 * This function iterates through the map array and prints the key and value
 * of each map entry that has a non-empty key.
 *
 * @param persons An array of map structures to be printed.
 */
void printEntireMap(map persons[MAP_LENGTH]) {
    for (int i = 0; i < MAP_LENGTH; i++) {
        if (strcmp(persons[i].key, "") != 0) {
            printf("Key = %s | Value = %d\n", persons[i].key, persons[i].value);
        }
    }
}

/**
 * @brief Searches for a given key in an array of maps and prints the corresponding value.
 *
 * @param key A character pointer to the key that is to be searched in the map.
 * @param persons An array of maps where each map contains a key-value pair.
 */
void printMapKey(char *key, map persons[MAP_LENGTH]) {
    for (int i = 0; i < MAP_LENGTH; i++) {
        if (strcmp(persons[i].key, key) == 0) {
            printf("Key = %s | Value = %d\n", persons[i].key, persons[i].value);
            return;
        }
    }
    printf("Key not found\n");
}

// strcmp returns 0 if the strings are EQUAL
// strcmp returns 1 if the strings are NOT equal