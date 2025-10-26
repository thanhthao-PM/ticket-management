#include <iostream>
using namespace std;
struct show
{
    int id;
    char film [50];
    int room;
    int seatsTotal;
    int seatsSold;
    float price;   
};


int main()
{
    int a;
    do {
        cout <<"--Menu--\n";
        cout <<"1. Thêm suất chiếu \n";
        cout <<"2. Bán vé \n";
        cout <<"3. Hoàn vé \n";
        cout <<"4. In danh sách suất còn vé \n";
        cout <<"5.Sắp xếp giảm dần theo doanh thu \n";
        cout <<"6. Thống kê tổng vé bán & doanh thu \n";
        cin>>a;

    }
    
        
}