#include<bits/stdc++.h>

using namespace std;

class Customer {
public: 
    int id, discount;
    string name;

    Customer(int a, string b, int c) : id(a), name(b), discount(c) {}
};

class Invoice {
public:
    int id;
    double amount;
    Customer customer;

    Invoice(int a, double b, Customer c) : id(a), amount(b), customer(c) {}
    double getAmountAfterDiscount() {
        return (1.0 - customer.discount / 100.0) * amount;
    }
};

bool compare(Invoice a, Invoice b) {
    if (a.getAmountAfterDiscount() == b.getAmountAfterDiscount()) return a.customer.id < b.customer.id;
    return a.getAmountAfterDiscount() > b.getAmountAfterDiscount();
}

int main() {   
    int t;
    cin >> t;
    cin.ignore();
    string s;
    getline(cin, s);
    vector<Invoice> ds;

    while (t--) { 
        getline(cin, s);
        int Id = stoi(s.substr(s.find(":") + 2));
        getline(cin, s);
        string Name = s.substr(s.find(":") + 2);
        getline(cin, s);
        int Discount = stoi(s.substr(s.find(":") + 2));
        getline(cin, s);
        int invoiceId = stoi(s.substr(s.find(":") + 2));
        getline(cin, s);
        string temp = s.substr(s.find(":") + 2);
        temp.pop_back();
        temp.pop_back();
        double Amount = stod(temp);

        Customer customer(Id, Name, Discount);
        Invoice invoice(invoiceId, Amount, customer);
        ds.push_back(invoice);
        getline(cin, s);
    }

    sort(ds.begin(), ds.end(), compare);

    for (int i = 0; i < ds.size(); i++) {
        cout << "Customer ID : " << ds[i].customer.id << "\nFull Name : "  << ds[i].customer.name
             << "\nAmount : " << fixed << setprecision(2) << ds[i].getAmountAfterDiscount() << " $\n";
        cout << "--------------------\n";
    }
}