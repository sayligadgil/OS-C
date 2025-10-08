#include <stdio.h>
#include <sys/ipc.h>
#include <sys/shm.h>

int main() {
    // Generate the same key
    key_t key = ftok("shmfile", 65);

    // Locate the shared memory segment
    int shmid = shmget(key, 1024, 0666);

    // Attach to the shared memory
    char *str = (char*) shmat(shmid, (void*)0, 0);

    printf("Data read from memory: %s\n", str);

    // Detach from shared memory
    shmdt(str);

    // Destroy the shared memory
    shmctl(shmid, IPC_RMID, NULL);

    return 0;
}
