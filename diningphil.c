semaphore mutex = 1;
semaphore fork[5] = {1,1,1,1,1};

void philosopher(int i) {
    while (true) {
        think();
        wait(mutex);               // ask waiter for permission
        wait(fork[i]);             // pick left fork
        wait(fork[(i+1)%5]);       // pick right fork
        signal(mutex);
        
        eat();
        
        signal(fork[i]);
        signal(fork[(i+1)%5]);
    }
}
