<details>
  <summary><h2>▶ C programming language</h2></summary>
	
<details>
  <summary><h3>Quá trình biên dịch</h3></summary>
	
Quy trình dịch là quá trình chuyển đổi từ ngôn ngữ bậc cao (NNBC) (C/C++, Pascal, Java, C#…) sang ngôn ngữ đích (ngôn ngữ máy) để máy tính có thể hiểu và thực thi. Ngôn ngữ lập trình C là một ngôn ngữ dạng biên dịch. Chương trình được viết bằng C muốn chạy được trên máy tính phải trải qua một quá trình biên dịch để chuyển đổi từ dạng mã nguồn sang chương trình dạng mã thực thi.
	
### Quá trình biên dịch bao gồm 4 giai đoạn:
	
- **_Pre-processor (Giai đoạn tiền xử lý):_** Nhận mã nguồn và xóa bỏ các dòng comments, xử lý các chỉ thị tiền xử lý có bắt đầu bằng kí hiệu `#`. Như `#include` (thay thế mã chương trình của một tệp tiêu để vào mã nguồn cần dịch), `#define` (thay thế bằng giá trị cụ thể tại mỗi nơi sử dụng trong chương trình).
	-  Sau khi qua quá trình tiền xử lý thì file code lúc này sẽ có dạng `.i`.
	-  Dùng lệnh `gcc -E filename.c -o filename.i` hoặc `gcc -E filename.c` để xem code sau khi qua quá trình preprocessor.
- **_Compiler (Giai đoạn dịch NNBC sang ngôn ngữ Assembly):_** Kiểm tra các kiểu dữ liệu có lỗi hay không, phân tích cú pháp (syntax) của mã nguồn NNBC và tối ưu code.
	-  Quá trình này sẽ biên dịch từ code `.i` sang ngôn ngữ assembly `.s`.
	-  Dùng lệnh `gcc -S -o filename.s filename.c` để có thể xem code sau quá tình compiler.
- **_Assembler (Giai đoạn dịch ngôn ngữ Assembly sang ngôn ngữ máy):_** Biên dịch ngôn ngữ Assembly sang ngôn ngữ máy (0 và 1). Và tạo ra tệp tin Object `.o` or `.obj`.
	-  Dùng lệnh `gcc -c filename.c -o filename.o` để tạo ra file ".o" và dùng lệnh `objdump -d -Mintel filename.o` để xem code.
- **_Linker (Giải đoạn liên kết):_** Trong giai đoạn này mã máy của một chương trình `.o` dịch từ nhiều nguồn (file .c hoặc file thư viện .lib) được liên kết lại với nhau để tạo thành chương trình đích nhất. Mã máy của các hàm thư viện gọi trong chương trình cũng được đưa vào chương trình cuối trong giai đoạn này. Chính vì vậy mà các lỗi liên quan đến việc gọi hàm hay sử dụng biến tổng thể mà không tồn tại sẽ bị phát hiện. Kể cả lỗi viết chương trình chính không có hàm main() cũng được phát hiện trong liên kết.
	- File sau khi được gộp lại thì sẽ có đuôi mở rộng Executable `.exe`, còn trên Linux và MacOs thì có thể có đuối theo chỉ định hoặc không có đuôi mở rộng.

- Để chạy file code C trên `terminal` dùng lệnh `gcc -o filename filename.c` đẻ tạo ra tệp thực thi, sau đó dùng lệnh `./filename` để chạy tệp thực thi đó.

### Boot Mode
- Cấp nguồn:
	- Khi cấp nguồn cho vi điều khiển, nó sẽ bắt đầu quá trình khởi động.
	- Lúc này các thanh ghi và bộ nhớ của vi điều khiển sẽ có giá trị không xác định.
- Tạo Stack Pointer(SP):
	- Stack Pointer(SP) là một thanh ghi đặc biệt để quản lý ngăn xếp(stack).
	- Giá trị ban đầu của SP thường được thiết lập tại địa chỉ nhất định trong bộ nhớ.
	- Quá trình thiết lập SP có thể thực hiện thông qua việc gán giá trị một địa chỉ cố định vào thanh ghi SP.
- Tạo Program Counter(PC):
	- Là một thanh ghi đặt biệt dùng để lưu địa chỉ của lệnh hiện tại được thực thi.
	- Giá trị ban đầu của PC thường được thiết lập là địa chỉ bắt đầu của chương trình
	- Quá trình thiệt lập PC thực hiện thông qua việc gán giá trị địa chỉ bắt đầu của chương trình vào thanh ghi PC
- Khởi động chương trình: 
	- Sau khi SP và PC được khởi tạo thì chương trình chính bắt đầu khởi động
	- Vi điều khiển sẽ đọc từng câu lệnh và thực thi nó.
	- Nó sẽ thực hiện các lệnh tiếp theo bằng cách tăng giá trị của PC để trỏ đế địa chỉ lệnh tiếp theo
	- Bước nhảy của địa chỉ tùy thuộc vào vi điều khiển (Ví dụ: vđk 8bit thì mỗi lần nhảy thì PC sẽ trỏ tới địa chỉ lên 1byte, tương tự 16bit sẽ là 2 bytes)
	- Trong quá trình chạy, nếu gặp lệnh gọi hàm con thì VĐK sẽ tạo ra một ngăn xếp mới để lưu trữ các biến cục bộ và thông tin của hàm đó.
		- Lúc này, giá trị của SP sẽ lưu lại địa chỉ của câu lệnh hiện tại và giá trị của PC sẽ trỏ tới địa chỉ bắt đầu của hàm con đó và thực thi .
		- Sau khi chạy xong trả về kết quả. Thì ngăn xếp đó sẽ được giải phóng, PC sẽ được gán thành địa chỉ của SP trước đó và tiếp tục thực hiện chương trình.
- ***Ví dụ:*** Chương trình trên VĐK 32bits và địa chỉ của hàm ham() là 0x0000ff00.
	```C
	#include<stdio.h>
	void ham() {
    	int a = 5;
	}
	int main() {
    	int b = ham();
    	printf("%d", b);
	}
	```
	- Địa chỉ 0x00000000: Khởi động chương trình.
	- Địa chỉ 0x00000004: Khởi tạo SP với giá trị không xác định.
	- Địa chỉ 0x00000008: Khởi tạo PC với địa chỉ bắt đầu của hàm main(), và PC có giá trị là 0x00000008. SP không thay đổi.
    - Địa chỉ 0x0000000C: PC trỏ tới lệnh trong hàm main() và có địa chỉ là 0x0000000C. SP không thay đổi.
   	- Địa chỉ 0x00000010: PC trỏ tới lệnh gọi hàm ham(). PC có địa chỉ là 0x00000010, và SP được gán địa chỉ là 0x00000010 để sau khi chạy xong hàm ham(), PC có thể lấy địa chỉ của SP để chạy tiếp chương trình.
    - Địa chỉ 0x0000FF00: PC trỏ tới địa chỉ bắt đầu của hàm ham(), và PC có địa chỉ là 0x0000FF00. SP vẫn giữ nguyên giá trị là 0x00000010.
  	- Địa chỉ 0x0000FF04: PC tiếp tục nhảy thêm 4 byte đối với địa chỉ trước đó để thực hiện lệnh int a = 5, địa chỉ PC lúc này là 0x0000FF04. SP vẫn giữ nguyên giá trị là 0x00000010. Sau khi chạy xong hàm, PC sẽ quay trở lại địa chỉ của SP, tức là 0x00000010.
   	- Địa chỉ 0x00000014: PC trỏ tới lệnh printf("%d", b);. Lúc này, địa chỉ PC sẽ là 0x00000014, và SP vẫn giữ nguyên giá trị là 0x00000010.
	
</details>



<details>
  <summary><h3>Phân vùng bộ nhớ trên RAM, cấp phát bộ nhớ động</h3></summary>
	
### Phân vùng bộ nhớ trên RAM

| Stack |
|:-----:|
|   ↓   |
|   ↑   |	
|  Heap |
|  Bss(Uninitialized data)  |
|  Data(Initialized data)   |
|  Text |
- ***Text:*** Quyền truy cập chỉ có thể Read
	- Chứa khai báo các hằng số(.rodata)
	- Nó chưa lệnh thực thi nên tránh sửa đổi instruction
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
	### Lưu ý: 
	- Việc tự động dọn vùng nhớ còn tùy thuộc vào trình biên dịch trung gian.
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
</details>



<details>
  <summary><h3>Các biến trong C</h3></summary>
	
- Biến số nguyên (Integer Variables): Lưu trữ giá trị số nguyên không có phần thập phân.
	`int age = 25;`
- Biến số thực (Floating-point Variables): Lưu trữ giá trị số thực có phần thập phân.
	`float pi = 3.14;`
- Biến dấu chấm động (Floating-point Variables): Lưu trữ giá trị số thực có độ chính xác cao hơn float.
    `double pi = 3.14159;`
- Biến dài (Long Variables): Lưu trữ giá trị số nguyên có phạm vi mở rộng so với int.
    `long population = 1000000;`
- Biến ngắn (Short Variables): Lưu trữ giá trị số nguyên có phạm vi nhỏ hơn so với int.
    `short temperature = -10;`
- Biến ký tự (Character Variables): Lưu trữ một ký tự.
	`char grade = 'A';`
- Biến chuỗi ký tự (String Variables): Lưu trữ một chuỗi các ký tự.
	`char name[] = "John";`
- Biến boolean (Boolean Variables): Lưu trữ giá trị đúng (1) hoặc sai (0).
	`int isTrue = 1;`
- Con trỏ (Pointer Variables): Lưu trữ địa chỉ của một biến hoặc vùng nhớ.
	`int* ptr = NULL;`
- Biến mảng (Array Variables): Lưu trữ nhiều giá trị trong một biến duy nhất.
	`int numbers[] = {1, 2, 3, 4, 5};`
- Biến kích thước (Size Variables): Lưu trữ giá trị kích thước của các đối tượng trong bộ nhớ.
    ```size_t length = 10;```
- Biến không đổi (Constant Variables): Lưu trữ giá trị không thay đổi trong suốt thời gian chương trình chạy.
    ```const int MAX_VALUE = 100;```
- Biến từ khóa (Keyword Variables): Lưu trữ giá trị trùng với các từ khóa được định nghĩa trong ngôn ngữ C.
    ```int int = 5;```
- Biến từ xa (Extern Variables):Khai báo một biến đã được định nghĩa trong một tệp tin khác.
    ```extern int globalVar;```
- Biến có phạm vi tĩnh (Static Scope Variables): Lưu trữ giá trị trong suốt vòng đời của biến và chỉ có thể truy cập trong phạm vi của một hàm hoặc tệp tin.
    ```static int count = 0;```
- Biến hệ thống (System Variables): Lưu trữ thông tin đối với chương trình chạy, như số lượng tham số dòng lệnh và danh sách tham số.
    ```int argc; char** argv;```
- Biến môi trường (Environment Variables): Lưu trữ thông tin môi trường hệ thống như đường dẫn, biến cấu hình, v.v.
    `char* path = getenv("PATH");`
- Biến vô kiểu (Void Variables): Lưu trữ một địa chỉ bất kỳ và có thể chuyển đổi thành bất kỳ kiểu con trỏ nào.
	`void* ptr;`
- Biến hằng số từ xa (Extern Constant Variables): Khai báo một hằng số đã được định nghĩa trong một tệp tin khác.
    `extern const int MAX_VALUE;`
- Biến gần (Auto Variables): Được sử dụng để chỉ ra rằng một biến cục bộ tự động sẽ được tạo ra.
 	`auto int x = 5;`
- Biến trình tự (Sequence Variables): Chỉ định rằng một biến thường được truy cập nhanh chóng và thường xuyên.
    `register int counter = 0;`
- Biến quyền (Qualifier Variables): Đánh dấu biến có thể thay đổi mà không cần thông báo và không nên tối ưu hóa.
   	`volatile int status;`
- Biến tĩnh (Static Variables): Lưu trữ giá trị trong suốt vòng đời của chương trình và giá trị được duy trì ngay cả khi hàm hoặc khối lệnh kết thúc.
	```static int count = 0;```
- Biến tĩnh cục bộ (Local Static Variables): Lưu trữ giá trị trong suốt vòng đời của biến, nhưng chỉ có thể truy cập trong phạm vi của một hàm.
    ```C
    void function() {
        static int count = 0;
        // ...
    }
    ```
- Biến toàn cục (Global Variables): Khai báo ngoài hàm. Lưu trữ giá trị có thể truy cập từ bất kỳ đâu trong chương trình.
	```int globalVar = 10;```
- Biến cục bộ (Local Variables): Khai báo trong hàm. Lưu trữ giá trị chỉ có thể truy cập trong phạm vi của một hàm hoặc khối lệnh.
	```C
	void function() {
    	int localVar = 5;
   		// ...
	} 
	```
- Biến tên (Label Variables): Đánh dấu một vị trí trong mã chương trình để nhảy đến khi sử dụng lệnh goto.
    ```C
    goto label;
    // ...
    label:
        // ...
    ```
- Biến tham chiếu (Reference Variables): Lưu trữ một tham chiếu đến một biến đã tồn tại, cho phép thay đổi giá trị của biến qua tham chiếu.
    ```C
    int x = 10;
    int& ref = x;
    ```
- Biến hàm (Function Variables): Lưu trữ địa chỉ của một hàm và cho phép gọi hàm thông qua con trỏ.
    ```C
    int (*func_ptr)(int, int);
    int sum(int a, int b) {
        return a + b;
    }
    func_ptr = sum;
    ```
- Biến cấu trúc (Structure Variables): Lưu trữ các thành phần có liên quan vào một biến.
    ```
    struct Person {
        char name[20];
        int age;
    };
    struct Person p1;
	```
- Biến cấu trúc mở rộng (Extended Structure Variables): Lưu trữ các thành phần có liên quan vào một biến và mở rộng chức năng của cấu trúc.
    ```C
    struct Person {
        char name[20];
        int age;
    } p1;
    ```
- Biến liên kết (Union Variables): Lưu trữ giá trị của một thành phần trong một thời điểm.
    ```
    union Data {
        int x;
        float y;
    };
    union Data data;
    ```
- Biến liệt kê (Enumeration Variables): Lưu trữ một trong các giá trị được xác định trước từ một tập hợp các giá trị có tên.
    ```
    enum Color {
        RED,
        GREEN,
        BLUE
    };
	enum Color c = BLUE;
- Biến kiểu định danh (Typedef Variables): Tạo ra một tên mới cho một kiểu dữ liệu đã tồn tại để sử dụng dễ dàng hơn.
    ```C
    typedef int Integer;
    Integer number = 42;
	```
- Biến kiểu dữ liệu do người dùng định nghĩa (User-defined Data Type Variables): Định nghĩa và sử dụng kiểu dữ liệu tùy chỉnh trong ngôn ngữ C.
	```C
	typedef struct {
    	char name[20];
    	int age;
	} Person;
	Person p1; 
	```
### Khác nhau của static cục bộ và static toàn cục:
- Biến static cục bộ: Khi 1 biến cục bộ được khai báo với từ khóa static. Biến sẽ chỉ được khởi tạo 1 lần duy nhất và tồn tại suốt thời gian chạy chương trình. Giá trị của nó không bị mất đi ngay cả khi kết thúc hàm. Tuy nhiên khác với biến toàn cục có thể gọi trong tất cả mọi nơi trong chương trình, thì biến cục bộ static chỉ có thể được gọi trong nội bộ hàm khởi tạo ra nó. Mỗi lần hàm được gọi, giá trị của biến chính bằng giá trị tại lần gần nhất hàm được gọi.
- Biến static toàn cục: Biến toàn cục static sẽ chỉ có thể được truy cập và sử dụng trong File khai báo nó, các File khác không có cách nào truy cập được. 
</details>



<details>
  <summary><h3>Macro, Inline, Function</h3></summary>

- **_Macro:_** Được xử lý bởi preprocessor
    - Thay thế đoạn code được khai báo macro vào bất cứ chỗ nào xuất hiện macro đó
    - VD: Preprocessor khi gặp bất kỳ lời gọi SUM(first+last) nào thì thay ngay bằng
    ```C
    #define SUM(a,b)     (a+b)
    ```
- **_Inline:_** Được xử lý bởi compiler
    - Được khai báo với từ khóa inline
    - Khi compiler thấy bất kỳ chỗ nào xuất hiện inline function, nó sẽ thay thế chỗ đó bởi định nghĩa của hàm đã được compile tương ứng. –> Phần được thay thế không phải code mà là đoạn code đã được compile
- **_Function:_** Khi thấy hàm được gọi, compiler sẽ phải lưu con trỏ chương trình PC hiện tại vào stack; chuyển PC tới hàm được gọi, thực hiện hàm đó xong và lấy kết quả trả về; sau đó quay lại vị trí ban đầu trong stack trước khi gọi hàm và tiếp tục thực hiện chương trình.
    - Như có thể thấy, các này khiến chương trình tốn thời gian hơn là chỉ cần thay thế đoạn code đã được compile (cách của inline function)
### So sánh Macro, Inline, Function:
- Macro đơn giản là chỉ thay thế đoạn code macro vào chỗ được gọi trước khi được biên dịch
- Inline thay thế đoạn mã code đã được biên dịch vào chỗ được gọi
- Hàm bình thường phải tạo một function call, lưu địa chỉ trước khi gọi hàm vào stack sau đó mới thực hiện hàm và sau cùng là quay trở về địa chỉ trên stack trước khi gọi hàm và thực hiện tiếp chương trình
- Macro khiến code trở nên dài hơn rất nhiều so với bình thường nhưng thời gian chạy nhanh.
- Hàm inline cũng khiến code dài hơn, tuy nhiên nó làm giảm thời gian chạy chương trình
- Hàm bình thường sẽ phải gọi function call nên tốn thời gian hơn inline function nhưng code ngắn gọn hơn.
</details>



<details>
  <summary><h3>BitWise Operarion (Thao tác bit)</h3></summary>

- AND (Biểu thức AND): Ký hiệu: `&`.
	| A | B | A & B |
  	|---|---|:---:|
  	|0|0|  0|
  	|0|1|  0|
  	|1|0|  0|
  	|1|1|  1|
    ```c
    unsigned int a = 5;  // 0101
	unsigned int b = 3;  // 0011
	unsigned int result = a & b;  // 0001
	```
- OR (Biểu thức OR): Ký hiệu: `|`.
	| A | B | A \| B |
  	|---|---|:---:|
  	|0|0|  0|
  	|0|1|  1|
  	|1|0|  1|
  	|1|1|  1|
    ```c
    unsigned int a = 5;  // 0101
	unsigned int b = 3;  // 0011
	unsigned int result = a | b;  // 0111
    ```
- XOR (Biểu thức XOR): Ký hiệu: `^`.
	| A | B | A ^ B |
  	|---|---|:---:|
  	|0|0|  0|
  	|0|1|  1|
  	|1|0|  1|
  	|1|1|  0|
    ```c
    unsigned int a = 5;  // 0101
	unsigned int b = 3;  // 0011
	unsigned int result = a ^ b;  // 0110
    ```
- NOT (Biểu thức NOT): Ký hiệu: `~`, thực hiện phép NOT bit, đảo ngược tất cả các bit của số.
	| A | ~ A |
  	|--|:---:|
  	|0|  1|
  	|1|  0|
    ```c
    unsigned int a = 5;  // 0101
	unsigned int result = ~a;  // 1010 (đảo ngược các bit)
    ```
- Left Shift (Dịch trái): Ký hiệu: `<<`.
    ```c
    unsigned int a = 5;  // 0101
	unsigned int result = a << 2;  // 010100 (dịch trái 2 vị trí)
    ```
- Right Shift (Dịch phải): Ký hiệu: `>>`.
    ```c
    unsigned int a = 5;  // 0101
	unsigned int result = a >> 2;  // 0001 (dịch phải 2 vị trí)
    ```
- Left Shift và Assign (Dịch trái và gán): Ký hiệu: `<<=`, dịch trái các bit của số `a` đi `b` vị trí và gán lại giá trị cho `a`.
    ```a <<= b;```
- Right Shift và Assign (Dịch phải và gán): Ký hiệu: `>>=`, dịch phải các bit của số `a` đi `b` vị trí và gán lại giá trị cho `a`.
    ```a >>= b;```
- Bitwise AND và Assign (AND bit và gán): Ký hiệu: `&=`, thực hiện phép AND bit trên từng cặp bit của hai số và gán lại giá trị cho `a`.
    ```a &= b;```
- Bitwise OR và Assign (OR bit và gán): Ký hiệu: `|=`, thực hiện phép OR bit trên từng cặp bit của hai số và gán lại giá trị cho `a`.
    ```a |= b;```
- Bitwise XOR và Assign (XOR bit và gán): Ký hiệu: `^=`, thực hiện phép XOR bit trên từng cặp bit của hai số và gán lại giá trị cho `a`.
	```a ^= b;```
</details>



<details>
  <summary><h3>Struct và Union</h3></summary>

- Về mặt ý nghĩa, struct và union cơ bản giống nhau. Tuy nhiên, về mặt lưu trữ trong bộ nhớ, chúng có sự khác biệt rõ rệt như sau:
	- struct: Dữ liệu của các thành viên của struct được lưu trữ ở những vùng nhớ khác nhau. Do đó kích thước của 1 struct tối thiểu bằng kích thước các thành viên cộng lại tại vì còn phụ thuộc vào bộ nhớ đệm (struct padding).
	- Union : Dữ liệu các thành viên sẽ dùng chung 1 vùng nhớ. Kích thước của union được tính là kích thước lớn nhất của kiểu dữ liệu trong union. Việc thay đổi nội dung của 1 thành viên sẽ dẫn đến thay đổi nội dung của các thành viên khác.
</details>




<details>
  <summary><h3>Pointer</h3></summary>
	
- Bộ nhớ RAM chứa rất nhiều ô nhớ, `mỗi ô nhớ có kích thước 1 byte`. Mỗi ô nhớ có địa chỉ duy nhất và địa chỉ này được đánh số từ 0 trở đi. Nếu `CPU 32bit` thì có `2^32 địa chỉ` có thể đánh cho các ô nhớ trong RAM.
	| Ô nhớ | 0 | 1 | ... | 2^32-2 | 2^32-1 |
  	|:-------:|:--------:|:--------:|---|:----------:|:--------:|
  	| Địa chỉ |0x00000000|0x00000001|...|0x0=fffffffe|0xffffffff|
	| Giá trị |          |     5    |...|     's'    |          |
	|   Biến  |          |     x    |...|    char    |          |
- Khi khai báo biến, trình biên dịch dành riêng một vùng nhớ với địa chỉ duy nhất để lưu biến. Trình biên dịch có nhiệm vụ liên kết địa chỉ ô nhớ đó với tên biến. Khi gọi tên biến, nó sẽ truy xuất tự động đến ô nhớ đã liên kết với tên biến để lấy dữ liệu. Các bạn phải luôn phân biệt giữa `địa chỉ bộ nhớ` và `dữ liệu được lưu trong đó`.
- Địa chỉ của biến bản chất cũng là một con số thường được biểu diễn ở `hệ cơ số 16`. Ta có thể sử dụng con trỏ (pointer) để lưu địa chỉ của các biến.
- ***Con trỏ(pointer):***
	- Trong ngôn ngữ C/C++, con trỏ (pointer) là những biến lưu trữ địa chỉ bộ nhớ của những biến khác.
	- Kích thước của các biến con trỏ có khác nhau không? Con trỏ chỉ lưu địa chỉ nên kích thước của mọi con trỏ là như nhau. Kích thước này phụ thuộc vào môi trường hệ thống máy tính:
		- `Môi trường Windows 32 bit: 4 bytes`
        - `Môi trường Windows 64 bit: 8 bytes`
### Các loại con trỏ:
- ***Con trỏ NULL:*** Con trỏ NULL là con trỏ lưu địa chỉ 0x00000000. Tức địa chỉ bộ nhớ 0, có ý nghĩa đặc biệt, cho biết con trỏ không trỏ vào đâu cả.
	```c
	int *p2; //con trỏ chưa khởi tạo, vẫn trỏ đến một vùng nhớ nào đó không xác định
	int *p3 = NULL; //con trỏ null không trỏ đến vùng nhớ nào
	int *p4 = null; // Lỗi "null" phải viết in hoa
	```
- ***Con trỏ đến con trỏ(pointer to pointer):*** Con trỏ này dùng để lưu địa chỉ của con trỏ khác.
	```c
	int x = 10;
    int *p1 = &x;     // Con trỏ p1 trỏ đến biến x và giá trị của p1 chỉnh là địa chỉ của biến x
    int **p2 = &p1;	 // Con trỏ p2 trỏ đến con trỏ p1 và lưu địa chỉ của con trỏ p1 vào p2  

    printf("Giá trị của x: %d\n", *p1); //Giá trị của x: 10
    printf("Địa chỉ của x: %p\n", p1); //Địa chỉ của x: 0x7ffee2a697a8 
    printf("Giá trị của x: %d\n", **p2); //Giá trị của x: 10
    printf("Địa chỉ của p1: %p\n", p2); //Địa chỉ của p1: 0x7ffee2a697a0
	```
- ***Con trỏ hằng (Constant Pointers):*** Không thể thay đổi giá trị mà nó trỏ tới, nhưng có thể thay đổi địa chỉ mà nó trỏ tới.
	```c
	int num = 10; 
	const int *ptr = &num; //thay đổi được địa chỉ của num nhưng không thay đổi được giá trị '10' của num
	```
- ***Con trỏ void (Void Pointers):*** Con trỏ void có thể trỏ tới bất kỳ kiểu dữ liệu nào, nhưng khi xuất ra giá trị thì phải ép kiểu.
	```c
	int num = 10;
	float f = 3.14;
	void *ptr;
	ptr = &num;
	printf("num = %d\n",(int*)ptr);
	ptr = &f;
	printf("f = %f\n",(float*)ptr);
	```
- ***Con trỏ hàm (Function Pointers):*** Dùng để lưu trữ và gọi các hàm thông qua con trỏ.
	```c
	int add(int a, int b) {
		return a + b;
	}
	int subtract(int a, int b) {
		return a - b;
	}

	int main() {
	
		int (*operation)(int, int) = add;
		int result = operation(5, 3);
		printf("Result: %d\n", result);

		operation = subtract;
		result = operation(5, 3);
		printf("Result: %d\n", result);

		return 0;
	}

	```
- ***Con trỏ vào hàm (Pointers to Functions):*** Lưu trữ địa chỉ của một hàm cụ thể để gọi hàm thông qua con trỏ.
	```c
	int add(int a, int b) {
		return a + b;
	}
	int subtract(int a, int b) {
		return a - b;
	}

	void performOperation(int a, int b, int (*operation)(int, int)) {
		int result = operation(a, b);
		printf("Result: %d\n", result);
	}

	int main() {
		int a = 5, b = 3;

		performOperation(a, b, add);
		performOperation(a, b, subtract);

		return 0;
	}

	```
- ***Con trỏ hàm parameter (Function Pointer Parameters):*** Truyền một hàm như một tham số cho một hàm khác.
	```c
	void greet() {
		printf("Hello, World!\n");
	}

	void performAction(void (*action)()) {
		action();
	}

	int main() {
		performAction(greet);

		return 0;
	}

	```
### Lưu ý khi sử dụng con trỏ
- Khi khởi tạo con trỏ NULL: Chữ NULL phải viết hoa, viết thường null sẽ bị lỗi.
- Không nên sử dụng con trỏ khi chưa được khởi tạo: Kết quả tính toán có thể sẽ phát sinh những lỗi không lường trước được nếu chưa khởi tạo con trỏ.
- Sử dụng biến con trỏ sai cách.

</details>
</details>






















<details>
  <summary><h2>▶ C++ programming language</h2></summary>

<details>
  <summary><h3>Class</h3></summary>
	
### Class là gì?
- Class là một cấu trúc dữ liệu tự định nghĩa, nó cho phép lập trình viên tạo ra các đối tượng (objects) mới có cùng bản chất. 
- Class định nghĩa các thuộc tính **data members** còn gọi là `property` và phương thức **member functions** còn gọi là `method` mà các đối tượng của nó có thể sử dụng.
- Trong C++, từ khóa `class` sẽ chỉ điểm bắt đầu của một class sẽ được cài đặt. Class trong C++ giúp tổ chức mã nguồn một cách có cấu trúc và tái sử dụng, đồng thời cho phép ẩn thông tin và triển khai tính kế thừa, đa hình và đóng gói.

### Khai báo class và sử dụng class.
```C++
class Person {
	public:
	string firstName; // property
	string lastName; // property
	int age; // property
	void fullname() { // method
	cout << firstName << ' ' << lastName; //trong tiêu chuẩn AutoSar thì không nên code ở đây
	}
};
```
- ***Lưu ý:*** Theo tiêu chuẩn của AutoSar thì trong class chỉ là định nghĩa các member, chứ không nên code trong phần body của class. Mà ta nên code riêng ra ngoài.
	```C++
	class Person {
		public:
		string firstName; // property
		string lastName; // property
		int age; // property
		void fullname(); // method
	};
	void Person::fullname(){
		cout << firstName << ' ' << lastName;
	}
	int main(){
		Person sv; //sv được gọi là object, object sv thuộc class Person 
		//object chỉ có thể truy cập những member nào nằm trong public
		sv.firstName = "An";
		sv.lastName = "Duong"; 
		sv.age = 23;
		sv.fullname();
		return 0;
	}
	```
### Phạm vi truy cập (Access modifiers):
- **Access modifier** là phạm vi truy cập của các thuộc tính và phương thức sẽ được khai báo bên dưới nó. Có 3 phạm vi truy cập trong C++ là `public`, `private` và `protecte`d.
	- ***Public:*** Các member được khai báo trong Public thì các Object có thể truy cập trực tiếp tới được. Và các User có thể sử dụng và thay đổi các giá trị trong các member này
	- ***Private:*** Được sử dụng khi bạn muốn chặn User truy cập vào những member khai báo trong phạm vi này, giới hạn truy cập và sửa đổi giá trị của chúng. Sử dụng các member trong Public để truy cập đến các member trong Private.
	- ***Protected:*** Tương tự như Private, nhưng Private thì các class con không thể kết thừa được các member trong Private của class chính, còn Protected thì lại cho phép các class con có thể kế thừa được các member trong protected của class chính.
 - 
### Constructor
- Constructor hay hàm dựng là một hàm đặc biệt.
- Constructor là một hàm sẽ có tên trùng với tên của class.
- Sẽ được gọi chạy đầu tiên ngay khi chúng ta khởi tạo một object.
```c++
class SinhVien{
	public: 
		SinhVien(int tuoi, int lop); //có tên trùng với tên của class gọi là contructor
		void hienThi(); //method	
	private: 
		int tuoi; //property
		int lop; //property
};
void SinhVien::hienThi(){
	cout<<"Tuoi: "<<tuoi<<endl;  
	cout<<"Lop "<<lop<<endl;
}
SinhVien::SinhVien(int tuoi,int lop){
	SinhVien::tuoi = tuoi; //class SinhVien có thể truy cập đến tất cả nhưng member nằm trong nó
	SinhVien::lop = lop;
}
int main(){
	// khi có contructor thì nó luôn luôn chạy đầu tiên khi object được khởi tạo.
	// contructor có thể có tham số đầu vào hoặc không có
	SinhVien sv(17,6); //có thể gán giá trị trực tiếp vào khai báo ở public
	sv.hienThi();
	return 0;
}
```

### Biến static trong class
- Khi định nghĩa static trong class thì phải khởi tạo lần đầu ở ngoài.
- Khi khởi tạo thì địa chỉ của nó tồn tại trong suốt chương trình nên member static này của các object sẽ đều có cùng 1 địa chỉ.
```c++
class SinhVien{
	public:
		string ten;
		static int tuoi; //khi khai báo static trong class thì phải hởi tạo lần đầu ở ngoài
};

int SinhVien::tuoi; //ta có thể gán giá trị cho nó, khi khởi tạo thì địa chỉ của nó tồn tại trong suốt chương trình nên member static này của các object sẽ có cùng 1 địa chỉ.

int main(){
	
	SinhVien sv1,sv2;
	//về địa chỉ của hai object thì giống với struct. sv1 và sv2 sẽ được cấp vùng nhớ khác  với kích thước là tổng kích thước của các member và bộ nhớ đệm, địa chỉ của nó sẽ là địa chỉ của member đầu tiên, và các member sẽ mang đỉa chỉ khác nhau như trong struct.
	return 0;
}
```

### Các đặc tính của OOP
- Có 4 đặc tính: Tính đa hình, tính kế thừa, tính trừu tượng, tính đóng gói.
	- ***Inheritance (Tính kế thừa ):*** Một **class** có thể kế thừa các thuộc tính của một **class** khác đã tồn tại trước đó. Trong C++, khi một **class** con được tạo ra bởi việc kế thừa thuộc tính của **class** cha thì ta gọi class con đó là **subclass** và class cha là **superclass**. Chỉ có **Public** và **Protected** mới được kế thừa còn **Private** thì không được kế thừa, muốn kế thừa được các **member** trong **Private** buộc phải đổi lại **Protected**.
		```c++
  		class DoiTuong{
			public:
				void setThongTin(string ten, int tuoi);
				void hienThi();
			protected:
				int TUOI; //property
				string TEN;
		};
		
		void DoiTuong::hienThi(){
			cout<<"Day la class DoiTuong"<<endl;
			cout<<"Ten: "<<TEN<<endl;  
			cout<<"Tuoi "<<TUOI<<endl;
		}
		
		void DoiTuong::setThongTin(string ten,int tuoi){
			TEN = ten;
			TUOI = tuoi;
		}
  		class SinhVien : public DoiTuong{
			public:
				void setThongTin(string ten, int tuoi, int mssv);
				void hienThi(); //method	
			private:
				int MSSV;
		};
		
		void SinhVien::setThongTin(string ten, int tuoi, int mssv){
			TEN = ten;
			TUOI = tuoi;
			MSSV = mssv;
		}
		
		void SinhVien::hienThi(){
			cout<<"Day la class DoiTuong"<<endl;
			cout<<"Ten: "<<TEN<<endl;  
			cout<<"Tuoi "<<TUOI<<endl;
			cout<<"Mssv "<<MSSV<<endl;
		}
		
		int main(){
			SinhVien dt;
			dt.setThongTin("Hoang", 17);
			dt.hienThi();
			
			SinhVien sv;
			sv.setThongTin("Toan", 15,100);
			sv.hienThi();
			
			return 0;
		}
  		```
	- ***Abstraction (Tính trừu tượng):*** Là một khả năng mà chương trình có thể bỏ qua sự phức tạp bằng cách tập trung vào cốt lõi của thông tin cần xử lý. Điều đó có nghĩa, bạn có thể xử lý một đối tượng bằng cách gọi tên một phương thức và thu về kết quả xử lý, mà không cần biết làm cách nào đối tượng đó được các thao tác trong class. (Là chỉ những thứ cần thiết mà người dùng cần sử dụng thì được nằm ở public còn tính toán phức tạp mà người dùng không quan tâm đến thì nằm ở private)
		- Ví dụ: Người dùng nhập a,b,c và muốn biết phương trình có nghiệm hay vô nghiệm. thì những phần method nhập và xuất thì nằm ở public, còn method tính toán kiểm tra thì nằm ở private,những phần nằm ở private người dùng không được quyền can thiệp vào.
  	- ***Polymorphism (Tính đa hình):*** Là một khả năng mà một phương thức trong class có thể đưa ra các kết quả hoàn toàn khác nhau, tùy thuộc vào dữ liệu được xử lý.
  	  	- Ta có thể khai báo tên hàm các method giống nhau nhưng phải khác đầu vào, bởi vì khi tên trùng nhau thì nó dựa vào inputparameter để xác định đó hàm nào.
  	  	- Ví dụ:
  	  	```c++
  	  	class th{
			public:
				void tong(int a, int b);
				void tong(int a, double b);
				void tong(int a, int b, int c);
		};
  		```
	- ***Encapsulation (Tính đóng gói):*** Có ý nghĩa không cho phép người sử dụng các đối tượng thay đổi trạng thái nội tại của một đối tượng, mà chỉ có phương thức nội tại của đối tượng có thể thay đổi chính nó. Điều đó có nghĩa, dữ liệu và thông tin sẽ được đóng gói lại, giúp các tác động bên ngoài một đối tượng không thể làm thay đổi đối tượng đó, nên sẽ đảm bảo tính toàn vẹn của đối tượng, cũng như giúp giấu đi các dữ liệu thông tin cần được che giấu.
   		- Ví dụ: những biến nhập vào như a,b,c và biến xuất ra kết quả x1,x2 thì không được khai báo ở public, phải nằm ở trong private, và những biến đó được nhập và xuất thông qua các method, để tránh người dùng sửa đổi code làm lỗi chương trình. ví dụ để các biến đó ở public, người dùng nhập a,b,c ở method nhập, sau đó người dùng còn có thể chỉnh sửa a,b,c,delta... lúc này chương trình dễ bị trả kết quả sai.

</details>
<details>
  <summary><h3>Namespace</h3></summary>

- Namespace là từ khóa trong C++ được sử dụng để định nghĩa một phạm vi nhằm mục đích phân biệt các hàm, lớp, biến, ... cùng tên trong các thư viện khác nhau. 
- Khi tạo `namespace` nếu muốn dùng chung tên biến của các `member` thì khi khai báo tên của `namespace` thì phải khai báo tên khác nhau
- Nếu dùng chung tên của namespace thì tên của các meber phải khác nhau (dù có chung file hay khác file), Do khai báo cùng tên namespace thì dùng chung bộ nhớ nên nếu tên các member cũng giống thì những member giống nhau sẽ cùng chung 1 địa thì sẽ dẫn đến xung đột vùng nhớ
- ví dụ:
	```C++
	namespace A{
		int a;
		void function(){...}
		struct c{...};
	};
	namespace B{
		int a;
		void function(){...}
		struct c{...};
	}
	```
 
</details>
<details>
  <summary><h3>Template</h3></summary>
	
- **Template (khuôn mẫu)** là một từ khóa trong C++, và là một kiểu dữ liệu trừu tượng tổng quát hóa cho các kiểu dữ liệu int, float, double, bool...
- **Template** trong C++ có 2 loại đó là function template & class template.
- **Template** giúp người lập trình định nghĩa tổng quát cho hàm và lớp thay vì phải nạp chồng (overloading) cho từng hàm hay phương thức với những kiểu dữ liệu khác nhau.
- Ví dụ:
	- Những hàm có form giống nhau chỉ khác kiểu dữ liệu.
	```c++
	int tong(int a, int b);
	double tong(double a, double b);
	template<typename var> //thay vì ta code hai hàm riêng để xử lý, thì ta có thể code dùng template chung lại để gọn code hơn.
	int tong(var a, var b){
		return (var)(a+b);
	}
	```
	- Nếu a và b khác kiểu dữ liệu thì tên var của hai thằng phải khác nhau. Ví dụ var a, var1 b. Lúc này var đại diện cho kiểu dữ liệu a và var1 đại diện cho kiểu dữ liệu b.
	
</details>
<details>
  <summary><h3>Vector, List & Map</h3></summary>

### Vector là gì?
- Vector là một cấu trúc dữ liệu trong C++ dùng để chứa các đối tượng khác. Tương tự như mảng (array), vector cũng có thể chứa nhiều phần tử.
- Các phần tử trong vector được lưu trữ một cách liên tiếp trong bộ nhớ. Điều này cho phép truy cập dễ dàng đến các phần tử bằng cách sử dụng chỉ số (index).
- vector khác mảng thông thường là kích thước của vector có thể thay đổi trong quá trình thực thi chương trình. Khi cần, vector có thể mở rộng (tăng kích thước) hoặc thu hẹp (giảm kích thước) để chứa thêm hoặc loại bỏ các phần tử.
- Sử dụng thư viện `#include<vector>`.
- Modifiers:
Modifiers
	- ***push_back():*** Hàm đẩy một phần tử vào vị trí sau cùng của vector. Nếu kiểu của đối tượng được truyền dưới dạng tham số trong push_back() không giống với kiểu của vector thì sẽ bị ném ra. VD: ten-vector.push_back(ten-cua-phan-tu);
	- ***assign():*** Nó gán một giá trị mới cho các phần tử vector bằng cách thay thế các giá trị cũ. VD: ten-vector.assign(int size, int value);
	- ***pop_back():*** Hàm pop_back () được sử dụng để xóa đi phần tử cuối cùng một vector.
	- ***insert():*** Hàm này chèn các phần tử mới vào trước phần tử trước vị trí được trỏ bởi vòng lặp. Chúng ta cũng có thể chuyển một số đối số thứ ba, đếm số lần phần tử được chèn vào trước vị trí được trỏ.
   	- ***erase():*** Hàm được sử dụng để xóa các phần tử tùy theo vị trí vùng chứa
	- ***emplace():*** Nó mở rộng vùng chứa bằng cách chèn phần tử mới vào
	- ***emplace_back():*** Nó được sử dụng để chèn một phần tử mới vào vùng chứa vector, phần tử mới sẽ được thêm vào cuối vector
	- ***swap():*** Hàm được sử dụng để hoán đổi nội dung của một vector này với một vector khác cùng kiểu. Kích thước có thể khác nhau.
	- ***clear():*** Hàm được sử dụng để loại bỏ tất cả các phần tử của vùng chứa vector.
- Ví dụ:
	```c++
	//dùng thư viện vector giống cấp phát bộ nhớ động trong c, nhưng có thư viện hỗ trợ các công cụ nhanh hơn.
	#include <vector>
	
	vector<int> array;	// khai báo mảng kiểu int
	array.push_back(4);  //thêm phần tử tại 0 là 4
	array.push_back(8);  //thêm phần tử tại 1 là 8
	array.push_back(20);
	array.push_back(15); //thêm phần tử tại 4 là 15
	
	//từ C++ 11 trở đi có for cải :
	for(int item : array){ // có thể dùng biến auto item, biến auto sẽ tự định nghĩa item thuộc kiểu dữ liệu gì tùy vào giá trị và nó được lưu
		printf("i = %d\n",item);
	}
	
	array.pop_back(); //xóa phần tử cuối cùng, xóa 15
	array.insert(array.begin()+2,77); //chèn phần tử tại 2 là 77, các phần tử phía sau sẽ dời vị trí cho nhau.
	array.erase(array.begin()+2); // xóa phần tử thứ 2, dời những phần tử phía sau lên.
	array.clear(); //thu hồi vùng nhớ giống free
	
	for(int i =0;i<array;i++){
		printf("%d\n",array[i]);
	}
	```

### List là gì?
- List là một cấu trúc dữ liệu danh sách liên kết kép (doubly linked list).
- Các phần tử cửa nó không được lưu trong các địa liên tiếp mà lưu ở địa chỉ bất kì, và mỗi phần tử trước sẽ lưu kèm địa chỉ của phần tử kế tiếp theo tuần tự.
- Vì cung cấp một danh sách các phần tử được liên kết với nhau bằng các con trỏ, cho phép thêm, xóa và truy cập các phần tử một cách linh hoạt.
- Dùng thư viện `#include<list>`.
- Ví dụ:
	```c++
	#include<list>
	list<int> array;	// khai báo mảng kiểu int
	array.push_back(4);  //thêm phần tử thứ 0 là 4
	array.push_back(8);  //thêm phần tử thứ 1 là 8
	array.push_back(20);
	array.push_back(15); //thêm phần tử thứ 4 là 15
	
	for(auto item : array){ //
		printf("i = %d\n",item);
	}
	```
### Map là gì?
- là một cấu trúc dữ liệu ánh xạ (associative container) trong thư viện chuẩn của ngôn ngữ. Nó được sử dụng để lưu trữ các cặp key-value, trong đó mỗi key là duy nhất và liên kết với một giá trị (value) tương ứng.
- Dùng thư viện `#include<map>`.
- Ví dụ:
	```c++
	#include <map>
	int main(){
		map<string, string> SinhVien;
		SinhVien["Ten"] = "Hoang";
		SinhVien["Tuoi"] = "7";
		SinhVien["Lop"] = "15";
		for(auto item : SinhVien){
			cout<<"Key: "<<itemp.first<<", value: "<<item.second<<endl;
		}
		return 0;
	}
	```
 ### Ưu điểm và nhược điểm của Vector, List và Map:

 |            | Vector                   | List                        | Map                            |
|------------|--------------------------|-----------------------------|--------------------------------|
| Ưu điểm    | - Truy cập ngẫu nhiên các phần tử thông qua index. <br> - Được triển khai dưới dạng địa chỉ liên tiếp trong bộ nhớ. <br> - Hỗ trợ thay đổi kích thước dễ dàng. | - Chèn và xóa phần tử ở bất kỳ vị trí nào dễ dàng hơn. <br> - Không cần dùng thêm bộ nhớ liền kề để mở rộng kích thước. <br> - Linh hoạt trong việc chèn, xóa và truy xuất. | - Lưu trữ các cặp key-value và tự động sắp xếp theo key. <br> - Truy cập hiệu quả thông qua key. <br> - Hỗ trợ các phương thức cho việc chèn, xóa và truy xuất. |
| Nhược điểm | - Chèn và xóa phần tử ở vị trí không phải cuối cùng thì phức tạp hơn. <br> - Cần dùng thêm bộ nhớ liền kề để mở rộng kích thước. <br> - Không hiệu quả cho chèn và xóa phần tử ở đầu hoặc giữa vector. | - Truy cập ngẫu nhiên chậm hơn so với vector. <br> - Chiếm nhiều bộ nhớ hơn do lưu trữ các con trỏ liên kết. | - Tốn nhiều bộ nhớ hơn do lưu trữ các key-value pairs và con trỏ liên kết. <br> - Thời gian tìm kiếm và truy xuất có phức tạp. <br> - Không hỗ trợ truy cập ngẫu nhiên theo index. |

</details>


</details>

























<details>
  <summary><h2>▶ Embedded</h2></summary>
	
<details>
  <summary><h3>Các giao thức (Protocols)</h3></summary>

<details>
  <summary><h4>SPI protocol</h4></summary>

- Các bit dữ liệu được truyền nối tiếp nhau và có xung clock đồng bộ.
- Giao tiếp song công, có thể truyền và nhận cùng một thời điểm.
- Khoảng cách truyền ngắn, được sử dụng để trao đổi dữ liệu với nhau giữa các chip trên cùng một bo mạch.
- Giao tiếp 1 Master với nhiều Slave.
- Tốc độ truyền khoảng vài Mb/s.
- Các dòng vi điều khiển thường được tích hợp module giao tiếp SPI dùng để giao tiếp truyền dữ liệu với các vi điều khiển khác, hoặc giao tiếp với các ngoại vi bên ngoài như cảm biến, EEPROM, ADC, LCD, SD Card,…

![Connect with orther](https://upload.wikimedia.org/wikipedia/commons/thumb/e/ed/SPI_single_slave.svg/800px-SPI_single_slave.svg.png)

![Connect with orther](https://upload.wikimedia.org/wikipedia/commons/thumb/f/fc/SPI_three_slaves.svg/350px-SPI_three_slaves.svg.png)
- ***SCLK (Serial Clock):*** Xung clock phát ra từ master
- ***MOSI (Master Out Slave In):*** Truyền data từ `master` đến `slave`. Chân `MOSI` ở `master` sẽ kết nối đến chân `MOSI` ở `slave`.
- ***MISO (Master In Slave Out):*** Truyền data từ `slave` đến `master`. Chân `MISO` ở `master` sẽ kết nối đến chân `MISO` ở `slave`.
- ***CS/SS (Chip/Slave Select):*** Chân CS được master sử dụng để lựa chọn slave cần giao tiếp. Master chỉnh chân SS xuống mức 0 để chọn slave truyền data.

![Connect with orther](https://upload.wikimedia.org/wikipedia/commons/thumb/b/bb/SPI_8-bit_circular_transfer.svg/500px-SPI_8-bit_circular_transfer.svg.png)
- Mỗi chip Master hay Slave sẽ có một thanh ghi dữ liệu 8 bit chứa dữ liệu cần gửi hoặc dữ liệu nhận.
- Mỗi xung nhịp mà Master tạo ra trên chân SCLK thì 1 bit trong thanh ghi dữ liệu của Master được truyền qua Slave và đồng thời 1 bit trong thanh ghi dữ liệu của Slave cũng truyền qua cho Master.

![Connect with orther](https://upload.wikimedia.org/wikipedia/commons/thumb/6/6b/SPI_timing_diagram2.svg/400px-SPI_timing_diagram2.svg.png)
- Có 4 chế độ hoạt động:
  	| Mode | CPOL | CPHA |
  	|:---:|:---:|:---:|
  	|0|0|0|
  	|1|0|1|
  	|2|1|0|
  	|3|1|1|
- CPOL = 0: Xung của SCK bắt đầu 1 chu kì là xung cạnh lên.
- CPOL = 1: Xung của SCK bắt đầu 1 chu kì là xung cạnh xuống.
- CPHA = 0: Bit dữ liệu đầu ra sẽ rơi vào cạnh xung đầu tiên của chu kì.
- CPHA = 1: Bit dữ liệu đầu ra sẽ rơi vào cạnh xung thứ hai của chu kì.

***Ưu, nhược điểm của chuẩn giao tiếp SPI.***
- Ưu điểm:
  - Không có Start bit và Stop bit như trong giao tiếp I2C và giao tiếp UART. Vì vậy dữ liệu có thể được truyền liên tục mà không bị gián đoạn
  - Không có hệ thống định địa chỉ slave phức tạp như I2C
  - Tốc độ truyền dữ liệu cao hơn I2C (nhanh gần gấp đôi)
  - Các dòng MISO và MOSI riêng biệt, vì vậy dữ liệu có thể được gửi và nhận cùng một lúc
- Nhược điểm:
  - Sử dụng bốn dây (I2C và UART sử dụng hai dây).
  - Không xác nhận rằng dữ liệu đã được nhận thành công.
  - Không có hình thức kiểm tra lỗi như bit chẵn lẻ (Parity bit) như trong UART.
  - Chỉ cho phép một master duy nhất.

</details>

<details>
  <summary><h4>I2C protocol</h4></summary>

- I2C (Inter-Integrated Circuit) là một giao thức truyền thông nối tiếp đồng bộ. Nên các bit dữ liệu truyền đi được đồng bộ hóa với xung nhịp do Master điều khiển.
- Hỗ trợ nhiều Master và Slave trên một đường truyền

![Connect with orther](https://upload.wikimedia.org/wikipedia/commons/thumb/3/3e/I2C.svg/220px-I2C.svg.png)

- I2C chỉ sử dụng hai dây để truyền dữ liệu giữa các thiết bị:
  - SDA (Serial Data) - đường truyền cho master và slave để gửi và nhận dữ liệu.
  - SCL (Serial Clock) - đường mang tín hiệu xung nhịp.

***Cách hoạt động:***

![Connect with orther](https://www.circuitbasics.com/wp-content/uploads/2016/01/Introduction-to-I2C-Message-Frame-and-Bit-2.png)

- Dữ liệu được truyền trong các `Message`, mỗi `Message` có một `khung địa chỉ` nhị phân chứa địa chỉ của `Slave` và một hoặc nhiều `khung dữ liệu` chứa dữ liệu đang được truyền.
- Trong mỗi thông điệp bao gồm điều kiện `Start` và `Stop`, các bit `Read/Write` và các bit `ACK/NACK` giữa mỗi `khung dữ liệu`.

![Connect with orther](https://encrypted-tbn0.gstatic.com/images?q=tbn:ANd9GcTry4sV-ui_OqN3z3ioNBQlq25u2RSJ0i1ucA&usqp=CAU)

- ***Điều kiện khởi động (1 bit):*** Chân `SDA` chuyển từ mức cao xuống mức thấp trước khi `SDL` chuyển từ cao xuống thấp.
- ***Khung địa chỉ (7 hoặc 10 bit):*** Là một chuỗi 7 hoặc 10 bit duy nhất cho mỗi `Slave` để xác định `Slave` mà `Master` muốn liên lạc và bit `Read/Write` cũng được gửi cùng ngay sau `khung địa chỉ`.
  	- `Master` sẽ gửi địa chỉ cho tất cả `Slave`, và những `Slave` sẽ so sánh địa chỉ đó với địa chỉ của nó.
  	- Nếu phù hợp nó sẽ gửi lại một bit `ACK` mức thấp trở lại cho `Master`, và nếu không khớp thì không làm gì cả và `SDA` giữa hai thiết bị đó vẫn ở mức cao
- ***Read/Write (1 bit):*** Sẽ cho `Slave` biết là `Master` muốn ghi dữ liệu vào nó hay nhận dữ liệu từ nó.
	- Nếu `Write` thì `0`, còn `Read` thì `1`.
- ***Data Frame (8 bit):*** Sau khi Master phát hiện bit `ACK` gửi từ `Slave`, thì `khung dữ liệu` bắt đầu gửi.
	- Bit MSB được gửi trước.
 	- Theo sau mỗi khung dữ liệu sẽ có 1 bit `ACK/NACK` để xác nhận khung đã được nhận thành công(bit 0 chân `SDA`).
  	- Bit `ACK` phải được nhận bởi `Master` hoặc `Slave` (tùy vào thiết bị gửi dữ liệu) trước khi khung dữ liệu tiếp theo được gửi.
- ***Điều kiện dừng (1 bit):*** Sau khi tất cả khung dữ liệu đã được gửi đi, thì `Master` có thể gửi điều kiện dừng bằng cách:
	- Chuyển `SCL` từ mức thấp lên mức cao trước khi chuyển `SDA` từ thấp lên cao.

***Ưu, nhược điểm của chuẩn giao tiếp I2C***

- **Ưu điểm:**
  - Chỉ sử dụng hai dây
  - Hỗ trợ nhiều `master` và nhiều `slave`
  - Bit `ACK / NACK` xác nhận rằng mỗi khung dữ liệu hay địa chỉ được gửi (hoặc nhận) thành công
  - Phần cứng ít phức tạp hơn với giao tiếp `UART`
  - Giao thức nổi tiếng và được sử dụng rộng rãi

- **Nhược điểm:**
  - Tốc độ truyền dữ liệu giao tiếp `I2C` chậm hơn so với giao tiếp `SPI`
  - Kích thước của khung dữ liệu được giới hạn ở `8 bit`
  - Cần phần cứng phức tạp hơn để triển khai so với giao tiếp `SPI`

</details>

<details>
  <summary><h4>UART protocol</h4></summary>

- `UART` (Universal Asynchronous Receiver / Transmitter) hoàn toàn khác biệt với chuẩn giao tiếp `SPI` hoặc `I2C`, những chuẩn này chỉ đơn tuần là giao tiếp phần mềm.
- Mục đích chính của `UART` là truyền và nhận dữ liệu nối tiếp không đồng bộ vì không có chân `Clock`. Nên tốc độ truyền `Baudrate` rất quan trọng trong giao thức này.
- Chuẩn giao tiếp `UART` sử dụng 2 dây để truyền và nhận dữ liệu giữa các thiết bị:
 - `TX (Transmiter)` – Dây truyền dữ liệu
 - `RX (Receiver)` – Dây nhận dữ liệu
- Giao tiếp giữa 1 `Master` và 1 `Slave`.
- Ngoài dữ liệu ra trong 1 lần truyền còn nhét thêm các Start bit, Stop bit, Parity bit. Các bit thêm vào này giúp cho Slave nhận biết, kiểm tra và nhận được đúng tín hiệu.

***Cách truyền nhận dữ liệu:***
![Connect with orther](https://kysungheo.com/wp-content/uploads/2023/03/3-300x129.png)
- UART sẽ truyền và nhận dữ liệu từ một Data Bus
- Data Bus được sử dụng để gửi dữ liệu đến UART bởi một thiết bị khác như vi điều khiển.
- Dữ liệu được gửi từ Data Bus sang UART ở dạng song song.
- Sau khi UART nhận được dữ liệu từ Data Bus, nó sẽ thêm một bit Start, một bit Parity và một bit Stop.
- Tạo ra gói dữ liệu và truyền đi nối tiếp từng bit qua chân TX.
- Bên nhận sẽ chuyển đổi gói dữ liệu đó sang dạng song song và lược bỏ các bit Start, Parity, Stop và chuyển qua Data Bus.

![Connect with orther](https://www.circuitbasics.com/wp-content/uploads/2016/01/Introduction-to-UART-Packet-Frame-and-Bits-2.png)

- ***Start bit:*** Để bắt đầu truyền dữ liệu, UART truyền sẽ kéo đường truyền từ mức cao xuống mức thấp trong một chu kỳ đồng hồ. Khi UART bên nhận phát hiện sự chuyển đổi điện áp cao xuống thấp, nó bắt đầu đọc các bit trong khung dữ liệu ở tần số của tốc độ truyền (Baud rate).
- ***Data Frame:***
  - Nó có thể dài từ 5 bit đến 8 bit nếu sử dụng bit Parity (bit chẵn lẻ).
  - Nếu không sử dụng bit Parity, khung dữ liệu có thể dài 9 bit.
  - Trong hầu hết các trường hợp, dữ liệu được gửi với bit LSB (bit có trọng số thấp nhất) trước tiên.
- ***Parity Bit*** bit Parity là một cách để UART bên nhận kiểm tra dữ liệu đã thay đổi trong quá trình truyền hay không. Bit có thể bị thay đổi bởi tốc độ truyền không khớp hoặc truyền dữ liệu khoảng cách xa,… Sau khi UART bên nhận đọc khung dữ liệu, nó sẽ đếm số bit có giá trị là 1 và kiểm tra xem tổng số là số chẵn hay lẻ.
  - Nếu bit Parity là 0 (chẵn), thì tổng các bit 1 trong khung dữ liệu phải là một số chẵn.
  - Nếu bit Parity là 1 (lẻ), thì tổng các bit 1 trong khung dữ liệu sẽ là một số lẻ. Do đó qua kiểm tra sẽ biết được quá trình truyền dữ liệu có chính xác.
- ***Stop Bit:*** Để báo hiệu sự kết thúc của gói dữ liệu, UART gửi sẽ điều khiển đường truyền dữ liệu từ điện áp thấp đến điện áp cao trong ít nhất hai khoảng thời gian bit.

***Ưu, nhược điểm của chuẩn giao tiếp UART***

Không có giao thức truyền thông nào là hoàn hảo, nhưng UART thực hiện khá tốt công việc của chúng. Dưới đây là một số ưu và nhược điểm của chuẩn giao tiếp UART. Mong rằng chúng có thể hỗ trợ cho dự án của bạn.
- Ưu điểm:
  - Chỉ sử dụng hai dây
  - Không cần tín hiệu đồng hồ
  - Có một bit chẵn lẻ để cho phép kiểm tra lỗi
  - Cấu trúc của gói dữ liệu có thể được thay đổi
  - Phương pháp được ghi chép rõ ràng và được sử dụng rộng rãi

- Nhược điểm:
  - Kích thước của khung dữ liệu được giới hạn tối đa là 9 bit
  - Không hỗ trợ nhiều hệ thống phụ dây hoặc nhiều hệ thống chính
  - Tốc độ truyền của mỗi UART phải nằm trong khoảng 10% của nhau

</details>

<details>
  <summary><h4>CAN protocol</h4></summary>

- Controller Area Network (CAN Bus) là giao thức truyền thông nối tiếp, tốc độ cao. Gồm có hai dây (CAN-High và CAN-Low).
  - 1 dây là CAN high: điện áp dao động từ 2.5 – 3.75 V
  - 1 dây là CAN low: điện áp dao động từ 1.25 – 2.5 V

</details>

</details>
</details>
