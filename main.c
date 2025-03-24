#include <stdio.h>
#include <stdlib.h>

void initializeSystem(int rooms, int lights[], int locks[], int motion[], int temperature[]);
void displayMenu();
void toggleLight(int rooms, int lights[]);
void readTemperature(int rooms, int temperature[]);
void checkMotion(int rooms, int motion[]);
void securitySystem(int rooms, int locks[]);
void analyzeHouseStatus(int rooms, int lights[], int locks[], int motion[], int temperature[]);

int main() {
    int rooms;
    
    printf("Enter number of rooms: ");
    scanf("%d", &rooms);
    
    int lights[rooms], locks[rooms], motion[rooms], temperature[rooms];

    initializeSystem(rooms, lights, locks, motion, temperature);
    
    int choice;
    
    do {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1: toggleLight(rooms, lights); break;
            case 2: readTemperature(rooms, temperature); break;
            case 3: checkMotion(rooms, motion); break;
            case 4: securitySystem(rooms, locks); break;
            case 5: analyzeHouseStatus(rooms, lights, locks, motion, temperature); break;
            case 6: printf("Exiting...\n"); break;
            default: printf("Invalid choice! Try again.\n");
        }

    } while (choice != 6);
    
    return 0;
}

void initializeSystem(int rooms, int lights[], int locks[], int motion[], int temperature[]) {
    for (int i = 0; i < rooms; i++) {
        lights[i] = 0;
        locks[i] = 1;
        motion[i] = 0;
        temperature[i] = 22 + (rand() % 10);
    }
    printf("Initializing system...\n");
}

void displayMenu() {
    printf("\n===== Smart Home Menu =====\n");
    printf("1. Toggle Light\n");
    printf("2. Read Temperature\n");
    printf("3. Check Motion Sensor\n");
    printf("4. Lock/Unlock Security System\n");
    printf("5. House Status Summary\n");
    printf("6. Exit\n");
}

void toggleLight(int rooms, int lights[]) {
    int room;
    printf("Enter room number to toggle light (1-%d): ", rooms);
    scanf("%d", &room);
    
    if (room >= 1 && room <= rooms) {
        lights[room - 1] = !lights[room - 1];
        printf("Light in Room %d is now %s.\n", room, lights[room - 1] ? "ON" : "OFF");
    } else {
        printf("Invalid room number!\n");
    }
}

void readTemperature(int rooms, int temperature[]) {
    int room;
    printf("Enter room number (1-%d): ", rooms);
    scanf("%d", &room);
    
    if (room >= 1 && room <= rooms) {
        printf("Temperature in Room %d: %d°C\n", room, temperature[room - 1]);
    } else {
        printf("Invalid room number!\n");
    }
}

void checkMotion(int rooms, int motion[]) {
    int room;
    printf("Enter room number (1-%d): ", rooms);
    scanf("%d", &room);
    
    if (room >= 1 && room <= rooms) {
        motion[room - 1] = 1;
        printf("Motion detected in Room %d!\n", room);
    } else {
        printf("Invalid room number!\n");
    }
}

void securitySystem(int rooms, int locks[]) {
    int room;
    printf("Enter room number to Lock/Unlock (1-%d): ", rooms);
    scanf("%d", &room);
    
    if (room >= 1 && room <= rooms) {
        locks[room - 1] = !locks[room - 1];
        printf("Room %d is now %s.\n", room, locks[room - 1] ? "LOCKED" : "UNLOCKED");
    } else {
        printf("Invalid room number!\n");
    }
}

void analyzeHouseStatus(int rooms, int lights[], int locks[], int motion[], int temperature[]) {
    printf("\nHouse Status:\n");
    for (int i = 0; i < rooms; i++) {
        printf("- Room %d: Light %s, Temp %d°C, %s, %s\n", 
               i + 1, lights[i] ? "ON" : "OFF", temperature[i], 
               motion[i] ? "Motion Detected" : "No Motion", 
               locks[i] ? "Locked" : "Unlocked");
    }
}
