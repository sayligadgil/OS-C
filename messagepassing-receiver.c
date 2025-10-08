#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <string.h>

// Define message structure
struct msg_buffer {
    long msg_type;
    char msg_text[100];
} message;

int main() {
    key_t key;
    int msgid;

    // Generate unique key
    key = ftok("msgqueuefile", 65);

    // Access the existing message queue
    msgid = msgget(key, 0666 | IPC_CREAT);

    // Receive message type 1
    msgrcv(msgid, &message, sizeof(message), 1, 0);

    printf("Data received is : %s\n", message.msg_text);

    // Destroy the message queue
    msgctl(msgid, IPC_RMID, NULL);

    return 0;
}
