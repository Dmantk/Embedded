**Quá trình biên dịch bao gồm 4 giai đoạn:**

- **_Pre-processor(Giai đoạn tiền xử lý):_** Xóa bỏ các dòng comments, xử lý các chỉ thị tiền xử lý có bắt đầu bằng kí hiệu "#". Như #include (thay thế mã chương trình cần thiết của một tệp tiêu để vào mã nguồn cần dịch), #define (thay thế bằng giá trị cụ thể vào các biến được gọi).
-   Sau khi qua quá trình tiền xử lý thì file code lúc này sẽ có dạng ".i" hoặc".ii".
-   Dùng lệnh "gcc -E filename.c" để xem code sau qua trình preprocessing.
- **_Compiler(Giai đoạn dịch sang ngôn ngữ Assembly):_** 
- **_Assembler(Giai đoạn dịch sang ngôn ngữ máy):_**
- **_Linker(Giải đoạn liên kết):_**
