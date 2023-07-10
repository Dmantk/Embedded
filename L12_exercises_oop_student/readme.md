Viết chương trình quản lý sinh viên trong C/C++. Mỗi đối tượng sinh viên có các thuộc tính sau: id, tên, giới tính, tuổi, điểm toán, điểm lý, điểm hóa, điểm trung bình và học lực.
Id là mã sinh viên tự động tăng.
Khi khởi tạo, chương trình sẽ đọc file "student.txt" để lấy ra danh sách sinh viên đã được lưu trước đó.
Điểm trung bình là giá trị trung bình của 3 môn toán, lý , hóa.
Học lực được tính  như sau:
	- Giỏi: Nếu điểm trung bình lớn hơn hoặc bằng 8.
	- Khá: Nếu điểm trung bình nhỏ hơn 8 và lớn hơn hoặc bằng 6.5.
	- Trung bình: Nếu điểm trung bình nhỏ hơn 6.5 và lớn hơn bằng 5.
Yêu cầu: Tạo ra một menu với các chức năng sau:
	1. Thêm sinh viên.
	2. Cập nhật thông tin sinh viên bởi ID.
	3. Xóa sinh viên bởi ID.
	4. Tìm kiếm sinh viên theo tên.
	5. Sắp xếp sinh viên theo điểm trung bình.
	6. Sắp xếp sinh viên theo tên.
	7. Hiển thị danh sách sinh viên.
	8. Ghi danh sách sinh viên vào file "student.txt".