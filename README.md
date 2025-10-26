# Quản lý vé rạp phim 
- Show { int id; char film[50]; int room; int seatsTotal; int seatsSold; float price; };
- Ràng buộc: 0 ≤ seatsSold ≤ seatsTotal 
 Menu
1. Thêm suất chiếu. 
2. Bán vé (if còn ghế; while bắt nhập số vé hợp lệ). 
3. Hoàn vé (if seatsSold đủ để trừ). 
4. In danh sách suất còn vé. 
5. Sắp xếp giảm dần theo doanh thu (seatsSold*price). 
6. Thống kê tổng vé bán & doanh thu.