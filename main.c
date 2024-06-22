#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 5
#define MAX_INPUT 100

typedef struct {
    char *description;
    char *items[MAX_ITEMS];
} Room;

typedef struct {
    Room *currentRoom;
    char *inventory[MAX_ITEMS];
} Player;

void printInventory(Player *player) {
    printf("Your inventory:\n");
    for (int i = 0; i < MAX_ITEMS; i++) {
        if (player->inventory[i] != NULL) {
            printf("- %s\n", player->inventory[i]);
        }
    }
}

void movePlayer(Player *player, Room *newRoom) {
    player->currentRoom = newRoom;
    printf("You are now in a %s\n", player->currentRoom->description);
}

void takeItem(Player *player, const char *item) {
    for (int i = 0; i < MAX_ITEMS; i++) {
        if (player->currentRoom->items[i] != NULL && strcmp(player->currentRoom->items[i], item) == 0) {
            for (int j = 0; j < MAX_ITEMS; j++) {
                if (player->inventory[j] == NULL) {
                    player->inventory[j] = player->currentRoom->items[i];
                    player->currentRoom->items[i] = NULL;
                    printf("You have taken the %s.\n", item);
                    return;
                }
            }
            printf("Your inventory is full!\n");
            return;
        }
    }
    printf("There is no %s here.\n", item);
}

void handleInput(Player *player, char *input) {
    if (strncmp(input, "go ", 3) == 0) {
        if (strcmp(input + 3, "north\n") == 0) {
            // Example: move north
        } else if (strcmp(input + 3, "south\n") == 0) {
            // Example: move south
        } else if (strcmp(input + 3, "east\n") == 0) {
            // Example: move east
        } else if (strcmp(input + 3, "west\n") == 0) {
            // Example: move west
        } else {
            printf("Invalid direction!\n");
        }
    } else if (strncmp(input, "take ", 5) == 0) {
        takeItem(player, input + 5);
    } else if (strcmp(input, "inventory\n") == 0) {
        printInventory(player);
    } else {
        printf("Invalid command!\n");
    }
}

int main() {
    Room rooms[2];
    rooms[0].description = "dark room";
    rooms[0].items[0] = "key";
    rooms[0].items[1] = NULL;

    rooms[1].description = "bright room";
    rooms[1].items[0] = "sword";
    rooms[1].items[1] = NULL;

    Player player;
    player.currentRoom = &rooms[0];
    for (int i = 0; i < MAX_ITEMS; i++) {
        player.inventory[i] = NULL;
    }

    char input[MAX_INPUT];
    printf("You are in a %s\n", player.currentRoom->description);
    while (1) {
        printf("> ");
        fgets(input, MAX_INPUT, stdin);
        handleInput(&player, input);
    }

    return 0;
}
