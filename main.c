#include "stdio.h"
#include "stdlib.h"
#include "string.h"

typedef struct {
    char key[256];
    int value;
}mapSample;

typedef struct {
    mapSample mapList[256];
    int size;
}map;

#define MAP_LENGTH 256

void addToMap(const char *key, int value, map persons[MAP_LENGTH]);
bool doesKeyExist(const char *key, int value, map persons[MAP_LENGTH]);
void printEntireMap(const map persons[MAP_LENGTH]);
void printMapKey(const char *key, const map persons[MAP_LENGTH]);
void popKey(const char *key, map persons[MAP_LENGTH]);

int main(void) {
    // We HAVE to use dynamic memory, as to not overload the stack memory, since the stack is relatively small.
    /* Memory size:
     * mapSample: char key[256] = 256 bytes, int value = 4 bytes, key+value = 260.
     * map: mapSample mapList[256] = 256*mapSample = 256*260 = 66560 bytes, int size = 4 bytes, mapSample+size = 66564.
     * So, we allocate 65564 bytes for the persons variable.
    */
    map *persons = (map *)malloc(sizeof(map));
    if (persons == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }
    persons->size = 0;

    // Used for determining what the user wants to do.
    char input[MAP_LENGTH];

    // The key to be added to a map. We use a buffer, since a pointer has to be pointing at something.
    char keyBuffer[MAP_LENGTH];
    char *key = keyBuffer;

    // The value to be added to the map with the corresponding key.
    // Garbage is used for the function "strtol", where in case there are characters that are not numbers, will be put in garbage.
    int value;
    char *garbage;

    while (true)
    {
        // Asks the user what to do.
        printf("Options:\n"
               "    add\n"
               "    print\n"
               "    pop\n"
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

            addToMap(key, value, persons);
            printEntireMap(persons);
        }
        else if (strcmp(input, "print") == 0)
        {
            char printerKey[MAP_LENGTH];
            printf("Enter key to print>");
            scanf("%s",printerKey);

            printMapKey(printerKey, persons);
        }
        else if (strcmp(input, "pop") == 0)
        {
            char keyToPop[MAP_LENGTH];
            printf("Enter key to pop>");
            scanf("%s", keyToPop);

            popKey(keyToPop, persons);
            printEntireMap(persons);
        }
        else
        {
            printf("Invalid input\n");
        }
    }

    free(persons);

    return 0;
}

/**
 * Adds a key-value pair to the mapSample if the key does not already exist.
 *
 * This function checks if the provided key exists in the mapSample. If the key
 * is found, the associated value is updated and the function returns. If the key
 * is not found, the key-value pair is added to the mapSample and the size of the mapSample is incremented.
 *
 * @param key A constant character pointer representing the key to be added or updated.
 * @param value An integer value to be associated with the key.
 * @param persons An array of mapSample structures where the key-value pair is to be added.
 * @param size A pointer to an integer representing the current number of elements in the mapSample.
 *             This value is incremented if a new key-value pair is added.
 */
void addToMap(const char *key, int value, map persons[MAP_LENGTH]) {
    int size = persons->size;

    // Checks if the key exists, and if it does, changes the same keys value.
    if (doesKeyExist(key, value, persons))
    {
        printf("Key existed\n");
        return;
    }
    // We add the key if it does not exist.
    else
    {
        strcpy(persons->mapList[size].key, key);
        persons->mapList[size].value = value;
        persons->size++;
        return;
    }
}

/**
* Checks whether a given key exists within an array of mapSample structures.
*
* This function searches through the provided array of mapSample structures
* to determine if a specified key is present. If the key is found,
* the value of the corresponding mapSample structure is updated to the provided value.
*
* @param key A constant character pointer that represents the key to search for.
* @param value An integer to set as the new value if the key is found.
* @param persons An array of mapSample structures where the search is performed.
* @param size An integer representing the number of elements in the persons array.
* @return A boolean value, true if the key is found, otherwise false.
*/
bool doesKeyExist(const char *key, const int value, map persons[MAP_LENGTH]) {
    int size = persons->size;

    // If the size of the array is 0, it's empty, and we know the key does not exist.
    if (size == 0) {
        return false;
    }

    //printf("%s | %d\n", key, value);
    for (int i = 0; i < size; i++) {
        if (strcmp(persons->mapList[i].key, key) == 0) {
            persons->mapList[i].value = value;
            return true;
        }
    }

    // If we get to this part, the key was not found and so doesn't exist.
    return false;
}

/**
 * @brief Prints the entire mapSample excluding empty entries.
 *
 * This function iterates through a mapSample array and prints the index, key, and value
 * of each non-empty entry. An entry is considered non-empty if its key is not an
 * empty string.
 *
 * @param persons Array of `mapSample` structures containing key-value pairs.
 * @param size Pointer to an integer representing the size of the mapSample array.
 */
void printEntireMap(const map persons[MAP_LENGTH]) {
    int size = persons->size;

    for (int i = 0; i < size; ++i) {
        if (strcmp(persons->mapList[i].key, "") != 0) {
            printf("%d: ", i);
            printf("Key = %s | Value = %d\n", persons->mapList[i].key, persons->mapList[i].value);
        }
    }
}

/**
 * @brief Prints the value associated with a specific key in an array of maps.
 *
 * This function searches through an array of mapSample structures to find a specific key.
 * If the key is found, it prints the key and its associated value.
 * If the key is not found, it prints "Key not found".
 *
 * @param key The key to search for within the array of maps.
 * @param persons An array of mapSample structures where each structure contains a key-value pair.
 * @param size The size of the mapSample array.
 */
void printMapKey(const char *key, const map persons[MAP_LENGTH]) {
    int size = persons->size;

    if (size == 0) {
        printf("Size is 0, nothing to print!");
        return;
    }

    for (int i = 0; i < size; ++i) {
        if (strcmp(persons->mapList[i].key, key) == 0) {
            printf("Key = %s | Value = %d\n", persons->mapList[i].key, persons->mapList[i].value);
            return;
        }
    }

    printf("Key not found\n");
}

/**
* Removes the entry with the specified key from the array of maps.
*
* This function searches for the entry with the given key in the
* array of mapSample elements and removes it by shifting subsequent elements
* one position to the left. The size of the array is then decreased by one.
*
* @param key The key of the entry to be removed.
* @param persons The array of mapSample elements from which the entry should be removed.
* @param size A pointer to the size of the array, which will be updated upon removal.
*/
void popKey(const char *key, map persons[MAP_LENGTH]){
    int size = persons->size;

    for (int i = 0; i < size; ++i) {
        if (strcmp(persons->mapList[i].key, key) == 0) {
            for (int j = i; j < size - 1; ++j) {
                strcpy(persons->mapList[j].key, persons->mapList[j + 1].key);
                persons->mapList[j].value = persons->mapList[j + 1].value;
            }
            persons->size--;
            return;
        }
    }

    printf("Key not found");
}
