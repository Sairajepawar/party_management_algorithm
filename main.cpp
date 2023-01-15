#include<iostream>

#include<vector>

#include<fstream>

#include<string>

using namespace std;
void title() {
    printf("\n\n\n");
    printf("\t\t\t\t\t");
    printf("\n");
    printf("\t\t\t\t    ---------------------------\n");
    printf("\t\t\t\t    |PARTY MANAGEMENT SYSTEM|\n");
    printf("\t\t\t\t    ---------------------------\n");
    printf("\n\n");

}
class guestvari{
    public: string name;
    string gender;
    string age;
    virtual void input()=0;
};
class guest:public guestvari {
    public:
    void input();
    void output();
    bool check(string a);
};
bool guest::check(string a) {
    if (a == name) {
        return true;
    } else {
       return false;
    }
}
void guest::input() {
    /*cout << "Enter the name:- ";
    cin >> name;
    cout << "Enter the gender:- ";
    cin >> gender;
    cout << "Enter the  age:- ";
    cin >> age;*/
    cout << "\n\t\t\t-----------------------------";
    cout << "\n\t\t\tEnter the Name of Guest: ";
    cin >> name;
    cout << "\n\t\t\t-----------------------------";
    cout << "\n\t\t\tEnter the Gender of Guest: ";
    cin >> gender;
    cout << "\n\t\t\t-----------------------------";
    cout << "\n\t\t\tEnter the Age of Guest: ";
    cin >> age;
}
void guest::output() {
    cout << "\n\t\t\t---------------------";
    cout << "\n\t\t\tName: " << name;
    cout << "\n\t\t\t---------------------";
    cout << "\n\t\t\tGender: " << gender;
    cout << "\n\t\t\t---------------------";
    cout << "\n\t\t\tAge: " << age;
    cout << "\n\t\t\t---------------------";
}
class adminvari
{
    public: string id;
    string password;
    virtual void input()=0;
};
class admin:public adminvari {
    public:
    void input();
};
void admin::input() {
    /*cout << "Enter the id:- ";
    cin >> id;
    cout << "Enter the password:- ";
    cin >> password;*/
    cout << "\n\t\t\t-----------------------------";
    cout << "\n\t\t\tEnter the Admin ID: ";
    cin >> id;
    cout << "\n\t\t\t-----------------------------";
    cout << "\n\t\t\tEnter the Password: ";
    cin >> password;
}
int main() {
    //"admin.txt" store admin data
    //"g.txt" stores guests data
    title();
    int flag = 0;
    ifstream ini;
    ini.open("admin.txt", ios::in);
    while (1) {
        string i, pass;
        cout << "\n\t\t\t-----------------------------";
        cout << "\n\t\t\tEnter the Admin ID: ";
        cin >> i;
        cout << "\n\t\t\t-----------------------------";
        cout << "\n\t\t\tEnter the Password: ";
        cin >> pass;
        admin a;
        ini >> a.id >> a.password;
        int count = 0;
        while (!ini.eof()) {
            count++;
            if (a.id == i && a.password == pass) {
                flag = 1;
                break;
            }
            ini >> a.id >> a.password;
        }
        ini.close();
        if (count == 0) {
            break;
        } else if (flag) {
            cout << "\n\t\t\t-----------------------------";
            cout << "\n\t\t\tAccess Granted." << endl;
            cout << "\n\t\t\t-----------------------------";
            break;
        } else {
            cout << "\n\t\t\t-----------------------------";
            cout << "\n\t\t\tWrong Credentials,Try Again." << endl;
            cout << "\n\t\t\t-----------------------------";
        }
    }
    while (1) {
        cout << "\n\t\t\t>>>>>>>>>  EMPLOYEE MANAGEMENT SYSTEM  <<<<<<<<<";
        cout << "\n";
        cout << "\n\t\t\t------------------------------------------------";
        cout << "\n\t\t\tENTER   1:   To Add the Guest.";
        cout << "\n\t\t\t------------------------------------------------";
        cout << "\n\t\t\tENTER   2:   To Add Admin.";
        cout << "\n\t\t\t------------------------------------------------";
        cout << "\n\t\t\tENTER   3:   To Search the Guest.";
        cout << "\n\t\t\t------------------------------------------------";
        cout << "\n\t\t\tENTER   4:   To Delete the Data of the Guest.";
        cout << "\n\t\t\t------------------------------------------------";
        cout << "\n\t\t\tENTER   5:   To Display the Data of all Guest.";
        cout << "\n\t\t\t------------------------------------------------";
        cout << "\n\t\t\tENTER   6:   To Exit.     ";
        cout << "\n\t\t\t------------------------------------------------";
        cout << "\n\n\t\t\t   Please Enter Your Choice: ";
        int res;
        cin >> res;
        if (res == 1) {
            guest add;
            add.input();
            ofstream a;
            a.open("g.txt", ios::app);
            a << " " + add.name + " " + add.age + " " + add.gender + " " << endl;
            a.close();
        } else if (res == 2) {
            admin add;
            add.input();
            ofstream a;
            a.open("admin.txt", ios::app);
            a << " " + add.id + " " + add.password + " " << endl;
            a.close();
        } else if (res == 3) {
            cout << "\n\t\t\t-----------------------------";
            cout << "\n\t\t\tENTER THE NAME OF GUEST TO BE SEARCHED:- ";
            string name;
            cin >> name;
            ifstream it;
            it.open("g.txt", ios::in);
            guest temp;
            it >> temp.name >> temp.age >> temp.gender;
            int flag = 1;
            while (!it.eof()) {
                if (temp.check(name)) {
                    flag = 0;
                    cout << "\n\t\t\tYES THE GUEST IS ATTENDING THE PARTY";
                    cout << "\n\t\t\t-----------------------------";
                    cout << "\n\t\t\t DETAILS ";
                    temp.output();
                    break;
                }
                it >> temp.name >> temp.age >> temp.gender;
            }
            it.close();
            if (flag)
                cout << "\n\t\t\tNO, THE GUEST IS NOT ATTENDING THE PARTY";
        } else if (res == 4) {
            cout << "\n\t\t\t-----------------------------";
            cout << "\n\t\t\tENTER THE NAME OF GUEST WHOSE DATA IS TO BE DELETED:- ";
            string name;
            cin >> name;
            ifstream iti;
            guest ii;
            iti.open("g.txt", ios::in);
            vector<string> n;
            vector<string> a;
            vector<string> g;
            iti >> ii.name >> ii.age >> ii.gender;
            while (!iti.eof()) {
                if (!ii.check(name)) {
                    n.push_back(ii.name);
                    a.push_back(ii.age);
                    g.push_back(ii.gender);
                }
                iti >> ii.name >> ii.age >> ii.gender;
            }
            iti.close();
            remove("g.txt");
            ofstream ito;
            ito.open("g.txt",ios::out|ios::app);
            for(int i=0;i<a.size();i++)
            {
                ito << " " + n[i] + " " + a[i] + " " + g[i] + " ";
            }
            ito.close();
        } else if (res == 5) {
            ifstream it;
            guest temp;
            it.open("g.txt", ios::in);
            it >> temp.name >> temp.age >> temp.gender;
            while (!it.eof()) {
                temp.output();
                it >> temp.name >> temp.age >> temp.gender;
            }
            it.close();
        } else if (res == 6) {
            break;
        } else {
            cout << "\n\t\t\t-----------------------------";
            cout << "\n\t\t\tWRONG RESPONSE, PLEASE TRY AGAIN.";
            cout << "\n\t\t\t-----------------------------";
        }
    }
    cout << "\n\t\t\t-----------------------------";
    cout << "\n\t\t\tTHANK YOU";
    cout << "\n\t\t\t-----------------------------";
    return 0;
}
