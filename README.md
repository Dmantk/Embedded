## ▶**Quá trình biên dịch bao gồm 4 giai đoạn:**

- **_Pre-processor (Giai đoạn tiền xử lý):_** Xóa bỏ các dòng comments, xử lý các chỉ thị tiền xử lý có bắt đầu bằng kí hiệu `#`. Như `#include` (thay thế mã chương trình của một tệp tiêu để vào mã nguồn cần dịch), `#define` (thay thế bằng giá trị cụ thể vào các biến được gọi).
	-  Sau khi qua quá trình tiền xử lý thì file code lúc này sẽ có dạng `.i`.
	-  Dùng lệnh `gcc -E filename.c -o filename.i` hoặc `gcc -E filename.c` để xem code sau khi qua quá trình preprocessor.
- **_Compiler (Giai đoạn dịch sang ngôn ngữ Assembly):_** Kiểm tra các kiểu dữ liệu có lỗi hay không, phân tích cú pháp (syntax) và tối ưu code.
	-  Quá trình này sẽ biên dịch từ code `.i` sang ngôn ngữ assembly `.s`.
	-  Dùng lệnh `gcc -S -o filename.s filename.c` để có thể xem code sau quá tình compiler.
- **_Assembler (Giai đoạn dịch sang ngôn ngữ máy):_** Biên dịch ngôn ngữ Assembly sang ngôn ngữ máy (0 và 1). Và tạo ra tệp tin Object `.o`.
	-  Dùng lệnh `gcc -c filename.c -o filename.o` để tạo ra file ".o" và dùng lệnh `objdump -d -Mintel filename.o` để xem code.
- **_Linker (Giải đoạn liên kết):_** Trong giai đoạn này mã máy của một chương trình `.o` dịch từ nhiều nguồn (file .c hoặc file thư viện .lib) được liên kết lại với nhau để tạo thành chương trình duy nhất
	- File sau khi được gộp lại thì sẽ có đuôi mở rộng Executable `.exe`, còn trên Linux và MacOs thì có thể có đuối theo chỉ định hoặc không có đuôi mở rộng.

- Để chạy file code C trên `terminal` dùng lệnh `gcc -o filename filename.c` đẻ tạo ra tệp thực thi, sau đó dùng lệnh `./filename` để chạy tệp thực thi đó.


## ▶**Phân vùng bộ nhớ trên RAM, cấp phát bộ nhớ động**

- ***Text:*** Quyền truy cập chỉ có thể Read
	- Chứa khai báo các hằng số(.rodata)
	- Nó chưa lệnh thực thị nên tránh sửa đổi instruction
- ***Data:*** Quyền truy cập Read-Write
	- Chứa biến toàn cục hoặc biến static: Có giá trị khởi tạo khác 0
	- Được giải phóng khi kết thúc chương trình
- ***Bss:*** Quyền truy cập Read-Write
	- Chứa biến toàn cục hoặc các biến static: Có giá trị khởi tạo bằng 0 hoặc không khởi tạo
	- Được giải phóng khi kết thúc chương trình
- ***Stack:*** Quyền truy cập là Read-Write.
	- Được sử dụng cấp phát cho biến local, input parameter của hàm,...
	- Sẽ được giải phóng khi ra khỏi block code/hàm
- ***Heap:*** Quyền truy cập là Read-Write.
	- Được sử dụng để cấp phát bộ nhớ động như: Malloc, Calloc,...
	- Sẽ được giải phóng khi gọi hàm free,...
	### So sánh Stack và Heap?
	- Bộ nhớ: Bộ nhớ Heap và bộ nhớ Stack bản chất đều cùng là vùng nhớ được tạo ra và lưu trữ trong RAM khi chương trình được thực thi.
		- Stack được dùng để lưu trữ các biến cục bộ trong hàm, tham số truyền vào... Truy cập vào bộ nhớ này rất nhanh và được thực thi khi chương trình được biên dịch.
		- Heap được dùng để lưu trữ vùng nhớ cho những biến con trỏ được cấp phát động bởi các hàm malloc - calloc - realloc (trong C)
	- Kích thước vùng nhớ:
		- Stack: kích thước của bộ nhớ Stack là cố định, tùy thuộc vào từng hệ điều hành, ví dụ hệ điều hành Windows là 1 MB, hệ điều hành Linux là 8 MB (lưu ý là con số có thể khác tùy thuộc vào kiến trúc hệ điều hành của bạn).
		- Heap: kích thước của bộ nhớ Heap là không cố định, có thể tăng giảm do đó đáp ứng được nhu cầu lưu trữ dữ liệu của chương trình.
	- Đặc điểm vùng nhớ
		- Stack: vùng nhớ Stack được quản lý bởi hệ điều hành, dữ liệu được lưu trong Stack sẽ tự động hủy khi hàm thực hiện xong công việc của mình.
		- Heap: Vùng nhớ Heap được quản lý bởi lập trình viên (trong C hoặc C++), dữ liệu trong Heap sẽ không bị hủy khi hàm thực hiện xong, điều đó có nghĩa bạn phải tự tay hủy vùng nhớ bằng câu lệnh free (trong C), và delete hoặc delete [] (trong C++), nếu không sẽ xảy ra hiện tượng rò rỉ bộ nhớ. 
	### Lưu ý: Việc tự động dọn vùng nhớ còn tùy thuộc vào trình biên dịch trung gian.
	- Vấn đề lỗi xảy ra đối với vùng nhớ Stack: Bởi vì bộ nhớ Stack cố định nên nếu chương trình bạn sử dụng quá nhiều bộ nhớ vượt quá khả năng lưu trữ của Stack chắc chắn sẽ xảy ra tình trạng tràn bộ nhớ Stack (Stack overflow), các trường hợp xảy ra như bạn khởi tạo quá nhiều biến cục bộ, hàm đệ quy vô hạn,..
		- Ví dụ về tràn bộ nhớ stack với hàm đệ quy vô hạn:
		```C
		int foo(int x){
			printf("De quy khong gioi han\n");
			return foo(x);
		}
		```
	- Vấn đề lỗi xảy ra đối với vùng nhớ Heap: Nếu bạn liên tục cấp phát vùng nhớ mà không giải phóng thì sẽ bị lỗi tràn vùng nhớ Heap (Heap overflow). Nếu bạn khởi tạo một vùng nhớ quá lớn mà vùng nhớ Heap không thể lưu trữ một lần được sẽ bị lỗi khởi tạo vùng nhớ Heap thất bại.
		- Ví dụ trường hợp khởi tạo vùng nhớ Heap quá lớn:
		```C 
		int *A = (int *)malloc(18446744073709551615); 
		```
	### Các cách sử dụng malloc, calloc, realloc, free:
	- ***Malloc:*** Cấp phát bộ nhớ động chưa có giá trị khởi tạo cho mỗi phần tử, trả về con trỏ NULL khi cấp phát thành công
	```C 
	void* malloc(size_t size);
	```
	- ***Calloc:*** Cấp phát bộ nhớ động có giá trị khởi tạo ban đầu của mỗi phần tử đều là 0, trả về con trỏ NULL khi cấp phát thành công
	```C
	void* calloc(size_t num, size_t size);
	```
	- ***Realloc:*** Thay đổi kích thước bộ nhớ của bộ nhớ đã được cấp phát trước đó của Malloc và Calloc, trả về con trỏ NULL khi thay đổi thành công
	```C
	void* realloc(void* ptr, size_t size);
	```
	- ***Free:*** Giải phóng bộ nhớ đã được cấp phát bằng Malloc, Calloc, Realloc sau khi sử dụng xong, không có trả về
	```C
	void free(void* ptr);
	```
	
