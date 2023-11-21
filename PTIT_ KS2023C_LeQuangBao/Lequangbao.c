#include<stdio.h>
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
int main(){
	int size =10;
	int choice;
	int sum = 0;
	int numbers[size];
	int max = numbers[0];
	int min = numbers[0];
	int find;
	int count = 0;
	int flag = 0;
	int dem = 0;
	int index;
	int index1 = 1;
	int value,n;
	int temp[size];
	int e3c=0;
	int o3c=0;
	int oc=0;
	do{
		printf("\n*****************Menu******************");
	printf("\n1. nhap gia tri n phan tu cua mang");
	printf("\n2. In ra gia tri cac phan tu trong mang");
	printf("\n3. tinh trung binh phan tu duong trong mang");
	printf("\n4. In ra vi tri cac phan tu co gia tri bang k va k duoc nhap tu ban phim");
	printf("\n5. su dung thuat toan sap xep noi bat sap xep mang giam dan");
	printf("\n6. tinh so luong cac phan tu la so nguyen to trong mang");
	printf("\n7. sap xep cac phan tu chan chia het cho 3 o dau mang theo thu tu giam dan, cac phan tu le chia het cho 3 o cuoi mang theo thu tu giam dan,cac phan tu con lai o gia mang theo thu tu tang dan");
	printf("\n8. nhap gia tri m tu bam phim chem m vao dung vi tri (sap xep giam dan)");
	printf("\n9. Thoat");
	printf("\nnhap lua chon can nhap: ");
	scanf("%d", &choice);
	switch(choice){
		case 1: 
			for (int i=0; i<size; i++){
				printf("Nhap phan tu thu [%d]: ",i);
				scanf("%d", &numbers[i]);
				}
			break;
		case 2:
			for (int i=0; i<size;i++){
				printf("phan tu thu [%d] trong mang la: %d\n",i,numbers[i]);
				}
			break;
		case 3:
			for (int i = 0; i < size; i++) {
                    if (numbers[i] > 0) {
                        sum += numbers[i];
                        dem++;
                    }
                }
                if (dem > 0) {
                    printf("trung binh cac phan tu duong la: %2f", (double)sum / dem);
                } else {
                    printf("Mang khong co phan tu duong.");
                }
                break;
		case 4:
			printf("nhap 1 so tuy y: ");
                scanf("%d", &index);
                count = 0;
                for (int i = 0; i < size; i++) {
                    if (numbers[i] == index) {
                        count++;
                        printf("phan tu thu [%d] giong k trong mang la: %d\n", i, numbers[i]);
                    }
                }
                printf("co %d gia tri giong gia tri dang tim kiem", count);
                break;
		case 5:
			for (int i=0;i<size;i++){
				for(int j=i+1;j<size;j++){
					if(numbers[i] < numbers[j]){
						int temp = numbers[i];
						numbers[i] = numbers[j];
						numbers[j] = temp;
					}
				}
			}
			for (int i=0; i<size; i++){
				printf("phan tu thu [%d] = %d\n",i,numbers[i]);
			}
			break;
		case 6:
			count = 0;
                for (int i = 0; i < size; i++){
                    flag = 0;
                    for (int j = 2; j < numbers[i]; j++){
                        if (numbers[i] % j == 0){
                            flag = 1;
                            break;
                        }
                    }
                    if (flag == 0 && numbers[i] > 1){
                        count++;
                    }
                }
            printf("co %d la so nguyen to co trong mang", count);
            break;
		case 7:
			for(int i = 0; i < size; i++){
        		if(numbers[i] % 2 == 0 && numbers[i] % 3 == 0){
            		temp[e3c++] = numbers[i];
        		}else if (numbers[i] % 2 != 0 && numbers[i] % 3 == 0){
            		temp[size - 1 - o3c++] = numbers[i];
        		}else{
            		temp[oc++] = numbers[i];
        		}
    		}
    		for(int i = 0; i < e3c - 1; i++){
        		for(int j = i + 1; j < e3c; j++){
            		if(temp[i] > temp[j]){
                		swap(&temp[i], &temp[j]);
            		}
        		}
   			}
    		for(int i = e3c; i < e3c + oc - 1; i++){
        		for(int j = i + 1; j < e3c + oc; j++){
            		if (temp[i] > temp[j]) {
                		swap(&temp[i], &temp[j]);
            		}
        		}
    		}
    		for(int i = size - o3c; i < size - 1; i++){
        		for(int j = i + 1; j < size; j++){
            		if(temp[i] < temp[j]){
                		swap(&temp[i], &temp[j]);
            		}
        		}
    		}
    		for(int i = 0; i < size; i++){
        		numbers[i] = temp[i];
   			}
    		printf("\nmang duoc sap xep:\n");
   			for(int i = 0; i < size; i++){
        		printf("phan tu thu [%d] = %d\n", i, numbers[i]);
    		}
    		break;
		case 8:
            printf("\nnhap gia tri muon them vao mang: ");
            scanf("%d", &value);
            if (index1 >= 0 && index1 <= size){
                for (int i = size; i > index1; i--){
                   	numbers[i] = numbers[i - 1];
                }
                numbers[index1] = value;
                size++;
                for (int i = 0; i < size; i++){
                    for (int j = i + 1; j < size; j++){
                       	if (numbers[i] < numbers[j]){
                            int temp = numbers[i];
                            numbers[i] = numbers[j];
                            numbers[j] = temp;
                        }
                    }
                }
                for (int i = 0; i < size; i++){
                	printf("phan tu thu [%d] = %d\n", i, numbers[i]);
                    }
                }
    		break;
		case 9:
			printf("thoat");
			break;
		}
	}while(choice != 9);
}
