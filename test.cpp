#include <iostream>
#include <cstring>
using namespace std;

struct Show {
    int id;
    char film[50];
    int room;
    int seatsTotal;
    int seatsSold;
    float price;
};

int main() {
    Show ds[100];
    int n = 0; // số suất chiếu hiện có
    int chon;

    while (true) {
        cout << "\n===== MENU =====\n";
        cout << "1. Them suat chieu\n";
        cout << "2. Ban ve\n";
        cout << "3. Hoan ve\n";
        cout << "4. In danh sach suat con ve\n";
        cout << "5. Sap xep giam dan theo doanh thu\n";
        cout << "6. Thong ke tong ve ban & doanh thu\n";
        cout << "7. Thoat\n";
        cout << "Nhap lua chon: ";
        cin >> chon;
        cin.ignore();

        switch (chon) {
            case 1: {
                cout << "Nhap so luong suat muon them: ";
                int them; cin >> them; cin.ignore();
                for (int i = 0; i < them; i++) {
                    cout << "\nNhap suat chieu thu " << i+1 << ":\n";
                    cout << "ID: "; cin >> ds[n].id; cin.ignore();
                    cout << "Ten phim: "; cin.getline(ds[n].film, 50);
                    cout << "Phong: "; cin >> ds[n].room;
                    cout << "Tong ghe: "; cin >> ds[n].seatsTotal;
                    cout << "Gia ve: "; cin >> ds[n].price;
                    ds[n].seatsSold = 0; // ban đầu chưa bán
                    n++;
                }
                break;
            }

            case 2: { // bán vé
                int id, soVe;
                cout << "Nhap ID suat muon ban: ";
                cin >> id;
                bool found = false;
                for (int i = 0; i < n; i++) {
                    if (ds[i].id == id) {
                        found = true;
                        cout << "Nhap so ve ban: ";
                        cin >> soVe;
                        while (ds[i].seatsSold + soVe > ds[i].seatsTotal) {
                            cout << "Khong du ghe! Nhap lai: ";
                            cin >> soVe;
                        }
                        ds[i].seatsSold += soVe;
                        cout << "Ban thanh cong!\n";
                    }
                }
                if (!found) cout << "Khong tim thay suat chieu!\n";
                break;
            }

            case 3: { // hoàn vé
                int id, soVe;
                cout << "Nhap ID suat muon hoan ve: ";
                cin >> id;
                bool found = false;
                for (int i = 0; i < n; i++) {
                    if (ds[i].id == id) {
                        found = true;
                        cout << "Nhap so ve hoan: ";
                        cin >> soVe;
                        while (soVe > ds[i].seatsSold) {
                            cout << "Khong hop le! Nhap lai: ";
                            cin >> soVe;
                        }
                        ds[i].seatsSold -= soVe;
                        cout << "Hoan ve thanh cong!\n";
                    }
                }
                if (!found) cout << "Khong tim thay suat chieu!\n";
                break;
            }

            case 4: { // in suất còn vé
                cout << "\n--- Danh sach suat con ve ---\n";
                for (int i = 0; i < n; i++) {
                    if (ds[i].seatsSold < ds[i].seatsTotal) {
                        cout << "ID: " << ds[i].id << ", Phim: " << ds[i].film
                             << ", Con " << ds[i].seatsTotal - ds[i].seatsSold
                             << " ghe trong\n";
                    }
                }
                break;
            }

            case 5: { // sắp xếp theo doanh thu giảm dần
                for (int i = 0; i < n - 1; i++) {
                    for (int j = i + 1; j < n; j++) {
                        float dt1 = ds[i].seatsSold * ds[i].price;
                        float dt2 = ds[j].seatsSold * ds[j].price;
                        if (dt1 < dt2) swap(ds[i], ds[j]);
                    }
                }
                cout << "Da sap xep theo doanh thu giam dan!\n";
                break;
            }

            case 6: { // thống kê
                int tongVe = 0;
                float tongTien = 0;
                for (int i = 0; i < n; i++) {
                    tongVe += ds[i].seatsSold;
                    tongTien += ds[i].seatsSold * ds[i].price;
                }
                cout << "Tong ve ban: " << tongVe << endl;
                cout << "Tong doanh thu: " << tongTien << endl;
                break;
            }

            case 7:
                cout << "Thoat chuong trinh...\n";
                return 0;

            default:
                cout << "Lua chon khong hop le!\n";
        }
    }
}
