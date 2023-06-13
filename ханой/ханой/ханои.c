#include<stdio.h>
#include<stdlib.h>
void Hanoi(int Disks, int fromRod, int toRode, int freeRode) {
    if (Disks == 1) {
        printf("%d->%d\n", Disks, toRode);
        return;
    }
    Hanoi(Disks - 1, fromRod, freeRode, toRode);
    printf("%d->%d\n", Disks, toRode);

    Hanoi(Disks - 1, freeRode, toRode, fromRod);
}

int main() {
    int Disks;
    scanf_s("%d", &Disks);
    Hanoi(Disks, 0, 2, 1);
    return 0;
}