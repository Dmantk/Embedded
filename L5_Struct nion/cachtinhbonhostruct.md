###Cách tính kích thước cửa struct
```C
#include<stdio.h>
#include<stdint.h>

struct typeDate{
	// Để tính bộ nhớ của struct là bao nhiêu byte thì ta dựa vào kiểu dữ liệu lớn nhất để tính bội số, ví dụ uint64 là 8bytes thì bội là 8,16,24,32....nếu số byte đệm sẽ sinh ra để đủ với bội số gần nhất
	uint8_t arr1[5];	// 5 thêm 3 (5 lần quét 1byte, tổng là 5bytes. Dựa vào uint64 là 8bytes nên cần thêm 3bytes đệm. Nên tổng là 5+3=8bytes)
	uint32_t arr2[2];	// 8 (vì 3bytes đệm ở trên không đủ cho 1 lần quét của uint32 là 4bytes nên không thể đưa vào 3bytes đệm. vậy 2 lần quét 4bytes là 8bytes, vừa đủ không cần byte đệm)
	uint8_t arr3[4];	// 4 thêm 4 (4 lần quét 1byte, tổng là 4bytes cần thêm 4bytes đệm)
	uint8_t arr4[6];	// 2 thêm 6 (6 lần quét 1byte, mà có 4bytes đệm ở trên nên được đẩy lên 4 lần quét, vậy chỉ còn 2 lần quét 1byte. Tổng là 2bytes cần 6bytes đệm)
	uint64_t arr5[3];	// 24 (3 lần quétđệm 8bytes, 6bytes đệm không đủ cho một lần quét nên không đưa lên được. Vậy tổng là 24bytes)
	uint8_t arr6[6];	// 6 thêm 2 (6 lần quét 1byte, không có byte đệm ở lần quét trước để đẩy lên, nên tổng là 6bytes cần 2bytes đệm)
	uint16_t arr7[2];	// 2 thêm 6 (2 lần quét 2bytes, có 2bytes đệm nên được đẩy lên 1 lần quét, nên còn 1 lần quét 2bytes, vậy tổng là 2bytes cần 6bytes đệm)
	uint64_t arr8[2];	// 16bytes (2 lần quét 8bytes, 6bytes đệm không đủ cho 1 lần quét 8bytes nên không đẩy lên, tổng là 16bytes không cần byte đệm)
};

int main(){
	printf("%lu\n", sizeof(struct typeDate));
	return 0;
}
```


