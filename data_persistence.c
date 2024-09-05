#include <stdio.h>
#include "retail_shop.h"

void saveData() {
    FILE *file = fopen("users.dat", "wb");
    if (file) {
        fwrite(&userCount, sizeof(int), 1, file);
        fwrite(users, sizeof(User), userCount, file);
        fclose(file);
    }

    file = fopen("products.dat", "wb");
    if (file) {
        fwrite(&productCount, sizeof(int), 1, file);
        fwrite(products, sizeof(Product), productCount, file);
        fclose(file);
    }
}

void loadData() {
    FILE *file = fopen("users.dat", "rb");
    if (file) {
        fread(&userCount, sizeof(int), 1, file);
        fread(users, sizeof(User), userCount, file);
        fclose(file);
    }

    file = fopen("products.dat", "rb");
    if (file) {
        fread(&productCount, sizeof(int), 1, file);
        fread(products, sizeof(Product), productCount, file);
        fclose(file);
    }
}
