#include <stdio.h>

struct Item {
    char name[50];
    int price;
    int quantity;
};

void print_receipt(struct Item items[], int itemCount, float discount) {
    int total_price = 0;
    printf("\n========= Struk Belanja =========\n");
    printf("%-20s %10s %10s\n", "Barang", "Jumlah", "Harga");
    
    for (int i = 0; i < itemCount; i++) {
        int item_total = items[i].price * items[i].quantity;
        printf("%-20s %10d %10d\n", items[i].name, items[i].quantity, item_total);
        total_price += item_total;
    }
    
    printf("\n%-30s %10d\n", "Total Harga Sebelum Diskon", total_price);
    
    // Hitung diskon
    int discount_amount = (int)(total_price * (discount / 100));
    int final_price = total_price - discount_amount;
    
    printf("%-30s %10d\n", "Diskon", discount_amount);
    printf("%-30s %10d\n", "Total Harga Setelah Diskon", final_price);
    printf("\n========== Terima Kasih =========\n");
    printf("====== Hati - Hati Dijalan ======\n");
}

int main() {
    int maxItems = 10;  // Jumlah maksimal item yang bisa diinput
    struct Item items[maxItems];
    int itemCount;
    float discount;
    
    //Membuat aturan cara pengisian
    printf("\n= Selamat Datang di Warung Madura Swasta =\n");
    printf("==== Mohon Perhatikan Cara Pengisian =====\n");
    printf("\nPengisian Jumlah Item\n");
    printf("Masukkan jumlah item: 10\n");
    printf("!Jumlah barang yang bisa dimasukkan max 10!\n");
    printf("\nPengisian Nama Barang\n");
    printf("Masukkan nama barang ke-1: beat \n");
    printf("!Hanya memasukkan 1 kata saja!\n");
    printf("\nPengisian Harga Barang\n");
    printf("Masukkan harga (nama barang): 10000\n");
    printf("!Masukkan dalam bilangan bulat tanpa titik!\n");
    printf("\nPengisian Jumlah Barang\n");
    printf("Masukkan jumlah: 4\n");
    printf("!Masukkan jumlah barang sesuai keinginan!\n");
    printf("\nPengisian Diskon Barang\n");
    printf("Masukkan diskon: 100\n");
    printf("!Masukkan diskon sesuai keinginan dari 0-100!\n");
    printf("\n=========== Selamat Berbelanja ===========\n");
    
    
    // Menerima input jumlah item
    printf("\nMasukkan jumlah item: ");
    scanf("%d", &itemCount);
    
    // Batasi jumlah item maksimal 10
    if (itemCount > maxItems) {
        printf("Maaf, jumlah item maksimal adalah 10.\n");
        return 1;
    }
    
    // Menerima input barang
    for (int i = 0; i < itemCount; i++) {
        printf("Masukkan nama barang ke-%d: ", i+1);
        scanf("%s", items[i].name);
        printf("Masukkan harga %s: ", items[i].name);
        scanf("%d", &items[i].price);
        printf("Masukkan jumlah %s: ", items[i].name);
        scanf("%d", &items[i].quantity);
    }
    
    // Menerima input diskon
    printf("Masukkan diskon: ");
    scanf("%f", &discount);
    
    // Menampilkan struk belanja
    print_receipt(items, itemCount, discount);

    return 0;
}