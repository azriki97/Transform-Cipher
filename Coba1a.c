#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

// Fungsi untuk enkripsi pesan
char* Pesan_Enkripsi(int key, const char* Pesan) {
    int Panjang_Pesan = strlen(Pesan);
    int Jlh_Baris = key;
    int Jlh_Kolom = (int)ceil((double)Panjang_Pesan / key);
    int numShadedBoxes = (Jlh_Kolom * Jlh_Baris) - Panjang_Pesan;
    char* cipherText = (char*)malloc(Panjang_Pesan + 1);

    if (cipherText == NULL) {
        perror("Gagal mengalokasikan memori");
        exit(1);
    }

    int Kolom = 0, Baris = 0;

    for (int i = 0; i < Panjang_Pesan; i++) {
        cipherText[i] = Pesan[key * Kolom + Baris];
        Kolom++;

        if ((Kolom == Jlh_Kolom) || (Kolom == Jlh_Kolom - 1 && Baris >= Jlh_Baris - numShadedBoxes)) {
            Kolom = 0;
            Baris++;
        }
    }

    cipherText[Panjang_Pesan] = '\0';
    return cipherText;
}

// Fungsi untuk dekripsi pesan 
char* Pesan_Dekripsi(int key, const char* Pesan) {
    int Panjang_Pesan = strlen(Pesan);
    int Jlh_Baris = key;
    int Jlh_Kolom = (int)ceil((double)Panjang_Pesan / key);
    int numShadedBoxes = (Jlh_Kolom * Jlh_Baris) - Panjang_Pesan;
    char* plainText = (char*)malloc(Panjang_Pesan + 1);

    if (plainText == NULL) {
        perror("Gagal mengalokasikan memori");
        exit(1);
    }

    int Kolom = 0, Baris = 0;

    for (int i = 0; i < Panjang_Pesan; i++) {
        plainText[key * Kolom + Baris] = Pesan[i];
        Kolom++;

        if ((Kolom == Jlh_Kolom) || (Kolom == Jlh_Kolom - 1 && Baris >= Jlh_Baris - numShadedBoxes)) {
            Kolom = 0;
            Baris++;
        }
    }

    plainText[Panjang_Pesan] = '\0';
    return plainText;
}

int main() {
    char Pesan[1000];
    int key;
    char mode;

    printf("Masukkan kata-kata: ");
    fgets(Pesan, sizeof(Pesan), stdin);
    Pesan[strcspn(Pesan, "\n")] = '\0';

    printf("Masukkan key [2-%d]: ", (int)(strlen(Pesan) - 1));
    scanf("%d", &key);

    printf("Enkripsi : %s\nDekripsi : %s", Pesan_Enkripsi(key, Pesan), Pesan_Dekripsi(key, Pesan));

    return 0;
}
