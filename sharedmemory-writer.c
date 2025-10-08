#include <stdio.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <string.h>

int main() {
    // Generate unique key
    key_t key = ftok("shmfile", 65);

    // Create shared memory segment of 1024 bytes
    int shmid = shmget(key, 1024, 0666 | IPC_CREAT);

    // Attach shared memory segment to process address space
    char *str = (char*) shmat(shmid, (void*)0, 0);

    printf("Write Data: ");
    fgets(str, 1024, stdin);  // read string from user input

    printf("Data written in memory: %s\n", str);

    // Detach from shared memory
    shmdt(str);

    return 0;
}
