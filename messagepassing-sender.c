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

    // Create message queue
    msgid = msgget(key, 0666 | IPC_CREAT);
    message.msg_type = 1; // Message type

    printf("Write Data: ");
    fgets(message.msg_text, sizeof(message.msg_text), stdin);

    // Send message
    msgsnd(msgid, &message, sizeof(message), 0);

    printf("Data sent is : %s\n", message.msg_text);

    return 0;
}
