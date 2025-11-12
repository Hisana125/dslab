#include <stdio.h>
int createBitstring(int set[], int size, int U[], int n) {
    int bitstring = 0;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < n; j++) {
            if (set[i] == U[j]) {
                bitstring |= (1 << (n - j - 1));
            }
        }
    }
    return bitstring;
}
void displaySet(int bitstring, int U[], int n) {
    int empty = 1;
    printf("{ ");
    for (int i = 0; i < n; i++) {
        if (bitstring & (1 << (n - i - 1))) {
            printf("%d ", U[i]);
            empty = 0;
        }
    }
    if (empty)
        printf("NULL");
printf("}\n");
}
int main() {
    int U[20], A[20], B[20];
    int bitA, bitB, bitU, result;
    int n, sizeA, sizeB, choice;

    printf("Enter size of Universal Set: ");
    scanf("%d", &n);
    printf("Enter elements of Universal Set: ");
    for (int i = 0; i < n; i++)
        scanf("%d", &U[i]);

    printf("Enter number of elements in Set A: ");
    scanf("%d", &sizeA);
    printf("Enter elements of Set A: ");
    for (int i = 0; i < sizeA; i++)
        scanf("%d", &A[i]);

    printf("Enter number of elements in Set B: ");
    scanf("%d", &sizeB);
    printf("Enter elements of Set B: ");
for (int i = 0; i < sizeB; i++)
        scanf("%d", &B[i]);

    bitA = createBitstring(A, sizeA, U, n);
    bitB = createBitstring(B, sizeB, U, n);
    bitU = (1 << n) - 1;

    while (1) {
        printf("\n--- Set Operations Menu ---\n");
        printf("1. Union (A U B)\n");
        printf("2. Intersection (A n B)\n");
        printf("3. Difference (A - B)\n");
        printf("4. Complement of A (U - A)\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 5) {
            printf("Exiting program...\n");
            break;
        }
switch (choice) {
            case 1:
                result = bitA | bitB;
                printf("A U B = ");
                displaySet(result, U, n);
                break;

            case 2:
                result = bitA & bitB;
                printf("A n B = ");
                displaySet(result, U, n);
                break;

            case 3:
                result = bitA & (~bitB);
                printf("A - B = ");
                displaySet(result, U, n);
                break;

            case 4:
                result = (~bitA) & bitU;
                printf("U - A = ");
                displaySet(result, U, n);
                break;

            default:
                printf("Invalid choice! Try again.\n");
        }
    }

    return 0;
}

