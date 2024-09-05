#ifndef RETAIL_SHOP_H
#define RETAIL_SHOP_H

#define MAX_USERS 100
#define MAX_PRODUCTS 100

typedef struct {
    char username[50];
    char password[50];
    int isSeller;
} User;

typedef struct {
    int id;
    char name[50];
    char description[200];
    float price;
    int quantity;
    char seller[50];  // Seller's username
} Product;

extern User users[MAX_USERS];
extern int userCount;
extern User *currentUser;

extern Product products[MAX_PRODUCTS];
extern int productCount;

void registerUser();
void loginUser();
void addProduct();
void viewProducts();
void buyProduct();
void saveData();
void loadData();

#endif // RETAIL_SHOP_H