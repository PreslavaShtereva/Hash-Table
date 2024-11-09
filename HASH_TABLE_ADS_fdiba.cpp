#include<stdio.h>
#include<stdlib.h>

#define SUBSLOT_LEN 10
#define HASHTABLE_LEN 100

int hf(int key);
void insert_key(int key, int* slot, int* sub_slot);
void search_key(int key);

struct hashslot2 {
    int key;
};

struct hashslot {
    struct hashslot2 subslots[SUBSLOT_LEN];
};

struct hashslot hashtable[HASHTABLE_LEN];

int main() {
    for (int i = 0; i < HASHTABLE_LEN; i++) {
        for (int j = 0; j < SUBSLOT_LEN; j++) {
            hashtable[i].subslots[j].key = -1;
        }
    }

    int new_key;
    printf("Enter a key to insert: ");
    scanf_s("%d", &new_key);

    int slot;
    int sub_slot;

    insert_key(new_key, &slot, &sub_slot);


    printf("Inserted key at slot %d\n", slot);
    printf("Inserted key at sub-slot %d\n", sub_slot);

    printf("Enter a key to search: ");
    scanf_s("%d", &new_key);
    search_key(new_key);

    return 0;
}

int hf(int key) {
    return key % HASHTABLE_LEN;
}


void insert_key(int key, int* slot, int* sub_slot) {
    int slot_index = hf(key);

    for (int i = 0; i < SUBSLOT_LEN; i++) {
        if (hashtable[slot_index].subslots[i].key == -1 || hashtable[slot_index].subslots[i].key == key) {
            hashtable[slot_index].subslots[i].key = key;


            *slot = slot_index;
            *sub_slot = i;
            break;
        }
    }
}

void search_key(int key) {
    int slot_index = hf(key);

    for (int i = 0; i < SUBSLOT_LEN; i++) {
        if (hashtable[slot_index].subslots[i].key == key) {
            printf("Found at slot %d\n", slot_index);
            printf("Found at sub-slot %d\n", i);
            return;

        }
    }
    printf("No element found.");
}














