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
  <summary><h3>Template</h3></summary>

	

</details>


</details>
