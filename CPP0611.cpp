    #include<bits/stdc++.h>

    using namespace std;

    int cnt = 1;

    class SinhVien {
    public:
        string id, name, grade, bd;
        double gpa;

        friend istream& operator >> (istream& in, SinhVien &a) {
            getline(in >> ws, a.name);
            getline(in >> ws, a.grade);
            getline(in >> ws, a.bd);
            in >> a.gpa;
    
            a.id = "B20DCCN" + string(3 - to_string(cnt).length(), '0') + to_string(cnt);
            cnt++;
            if (a.bd[1] == '/') a.bd.insert(0, "0");
            if (a.bd[4] == '/') a.bd.insert(3, "0");
            return in;
        } 

        friend ostream& operator << (ostream& out, SinhVien a) {
            cout << a.id << " " << a.name << " " << a.grade << " " 
                 << a.bd << " " << fixed << setprecision(2) << a.gpa << endl; 
            
            return out;
        }
    };

    int main(){
        SinhVien ds[50];
        int N, i;
        cin >> N;
        for(i=0;i<N;i++){
            cin >> ds[i];
        }
        for(i=0;i<N;i++){
            cout << ds[i];
        }
        return 0;
    }