#include <stdio.h>
#include "retail_shop.h"

int main() {
    int choice;
    loadData();

    while (1) {
        printf("\nOnline Retail Shop\n");
        printf("1. Register\n");
        printf("2. Login\n");
        printf("3. Add Product (Sellers)\n");
        printf("4. View Products\n");
        printf("5. Buy Product (Buyers)\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                registerUser();
                break;
            case 2:
                loginUser();
                break;
            case 3:
                addProduct();
                break;
            case 4:
                viewProducts();
                break;
            case 5:
                buyProduct();
                break;
            case 6:
                saveData();
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}
