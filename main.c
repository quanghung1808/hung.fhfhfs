#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
    char maSV[10];
    char tenSV[50];
    char sdtSV[50];

} SV;

void themSV(int *p, SV danhSachSV[]) {     //case 1.
    char a[10];
    for (int j = 0; j < 10; ++j) {
        printf("Nhap ten sinh vien thu %d:", *p + 1);
        scanf("%[^\n]",danhSachSV[*p].tenSV);
        while (1) {
            printf("Nhap mã sinh vien thu %d:", *p + 1);
            scanf("%s",danhSachSV[*p].maSV);
            if (strlen(danhSachSV[*p].maSV) != 5) {
                printf("yeu cau ma sinh vien phai du 5 ki tu!!!Vui long nhap lai sinh vien thu %d.\n", *p + 1);
            } else break;
        }
        printf("Nhap so dien thoai sinh vien thu %d:\n", *p + 1);
        fgetc(stdin);
        scanf("%[0-9]",danhSachSV[*p].sdtSV);
        *p+=1;
        printf("Nhap exit de dung hoac an Enter de tiep tuc.");
        fgetc(stdin);
        fgets(a, 10, stdin);
        if (strcmp(a, "exit\n") == 0)break;
        if(*p==10){
            printf("Danh sach sinh vien da day");
            break;
        }
    }

}

void hienSV(SV danhSachSV[]) {     // case 2.
    int i=0;
    printf("-%-25s|%-25s|%s", "Ma sinh vien", "Ten sinh vien", "Đien thoai");
    for (int j = 0; j < 10; ++j) {
        printf("\n-%-23s|%-23s|%s", danhSachSV[i].maSV, danhSachSV[i].tenSV, danhSachSV[i].sdtSV);
        i++;
    }
}

void in(SV danhSachSV[]) {     // case 3.
    int i=0;
    FILE *f=fopen("danhsachsinhvien.txt","w");
    fprintf(f,"-%-20s|%-20s|%s", "Ma sinh vien", "Ten sinh vien", "Dien thoai");
    for (int j = 0; j < 10; ++j) {
        fprintf(f,"\n-%-18s|%-18s|%s", danhSachSV[i].maSV, danhSachSV[i].tenSV, danhSachSV[i].sdtSV);
        i++;
    }
    fclose(f);
}
void doc(){       //case 4.
    FILE *f=fopen("danhsachsinhvien.txt","r");
    printf("Doc du lieu tu file\n");
    char buffer[255];
    while (fgets(buffer, 255, f) != NULL){
        printf("%s", buffer);
    }
    fclose(f);
}
int main() {
    int ch;
    int i = 0;
    int *p;
    p = &i;
    SV danhSachSV[10] = {};
    printf("------------Menu-------------\n");
    printf("1. Them moi sinh vien. \n");
    printf("2. Hien thi danh sach sinh vien.\n");
    printf("3. Luu danh sach sinh vien ra file.\n");
    printf("4. Doc danh sach sinh vien tu file.\n");
    printf("5. Thoat chuong trinh.\n");

    while (1) {
        printf("\nLua chon:");
        scanf("%d", &ch);
        fgetc(stdin);
        switch (ch) {
            case 1:
                if (*p == 10) {
                    printf("Danh sach sinh vien da day!!!");
                    break;
                }
                printf("Bat dau them sinh vien.\n");
                themSV(p, danhSachSV);
                break;
            case 2:
                printf("Day la danh sach sinh vien.\n");
                hienSV(danhSachSV);
                break;
            case 3:
                in(danhSachSV);
                printf("Da dua thong tin sinh vien vao file danhsachsinhvien.txt.\n");
                break;
            case 4:
                doc();
                break;

        }
        if (ch == 5) {
            printf("Dong chuong trinh.\n");
            break;
        }

    }

    return 0;
}