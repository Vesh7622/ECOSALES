#include <stdio.h>
#include <string.h>
#include "retail_shop.h"

Product products[MAX_PRODUCTS];
int productCount = 0;

void addProduct() {
    if (currentUser == NULL || currentUser->isSeller == 0) {
        printf("Only sellers can add products!\n");
        return;
    }
    if (productCount >= MAX_PRODUCTS) {
        printf("Product limit reached!\n");
        return;
    }
    products[productCount].id = productCount + 1;
    printf("Enter product name: ");
    scanf("%s", products[productCount].name);
    printf("Enter product description: ");
    scanf(" %[^\n]%*c", products[productCount].description);
    printf("Enter product price: ");
    scanf("%f", &products[productCount].price);
    printf("Enter product quantity: ");
    scanf("%d", &products[productCount].quantity);
    strcpy(products[productCount].seller, currentUser->username);
    productCount++;
    printf("Product added successfully!\n");
    saveData();
}

void viewProducts() {
    printf("Available Products:\n");
    for (int i = 0; i < productCount; i++) {
        printf("ID: %d, Name: %s, Price: %.2f, Quantity: %d, Seller: %s\n", 
               products[i].id, products[i].name, products[i].price, products[i].quantity, products[i].seller);
    }
}

void buyProduct() {
    if (currentUser == NULL || currentUser->isSeller == 1) {
        printf("Only buyers can purchase products!\n");
        return;
    }
    int id, quantity;
    printf("Enter product ID to buy: ");
    scanf("%d", &id);
    printf("Enter quantity: ");
    scanf("%d", &quantity);

    for (int i = 0; i < productCount; i++) {
        if (products[i].id == id) {
            if (products[i].quantity < quantity) {
                printf("Not enough stock available!\n");
                return;
            }
            products[i].quantity -= quantity;
            printf("Purchase successful! You bought %d %s(s) for %.2f.\n", 
                   quantity, products[i].name, products[i].price * quantity);
            saveData();
            return;
        }
    }
    printf("Product not found!\n");
}
