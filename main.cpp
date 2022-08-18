#include<iostream>
#include<vector>
#include<fstream>
#include<string>
using namespace std;
class guest{
    public:
    guest(){}
    ~guest(){}
    string name;
    string gender;
    int age;
    void setgender(string in)
    {
        char a=in[0];
        if(a=='B'||a=='b'||a=='M'||a=='m')
        {
            gender="BOY";
        }
        else
        {
            gender="GIRL";
        }
    }
};
typedef vector<guest> my_container;
void read_file(my_container* my_guests)
{
    string in_str;
    ifstream in_file("MYG.txt");
    if(in_file.is_open())
    {
        guest temp;
        while (getline(in_file,in_str))
        {
            temp.name=in_str;
            getline(in_file,in_str);
            temp.setgender(in_str);
            getline(in_file,in_str);
            temp.age=stoi(in_str);
            my_guests->push_back(temp);
        }
        in_file.close();
    }
}
void avg_age(my_container* my_guests)
{
    auto i=my_guests->begin();
    int sum=0;
    int x=0;
    while(i<my_guests->end())
    {
        sum+=i->age;
        x++;
        i+=1;
    }
    cout<<sum/x;
}
void print_guest_index(my_container* my_guests,int index)
{
    cout<<"Name:- "<<my_guests->at(index).name<<endl;
    cout<<"Gender:- "<<my_guests->at(index).gender<<endl;
    cout<<"Age:- "<<my_guests->at(index).age<<endl;
    cout<<endl;
}
void remove_data(my_container* my_guests,int index)
{
    my_guests->erase(my_guests->begin()+index);
}
void find_guests(my_container* my_guests,string a)
{
    auto it=my_guests->begin();
    while(it->name!=a && it!=my_guests->end())
    {
        it+=1;
    }
    if(it->name==a)
    {
        cout<<"Guest is their in the party";
    }
    else
    {
        cout<<"Guest is not their in the party";
    }
}
int main()
{
    my_container* my_guests=new my_container;
    read_file(my_guests);
    int response;
    string abc;
    int index;
    label:
    cout<<"Following are the options"<<endl;
    cout<<"1.To get the data of guest at a particular index"<<endl;
    cout<<"2.To erase data of a guest"<<endl;
    cout<<"3.To calculate the average of age's of guests"<<endl;
    cout<<"4.To find whether a person is present in the party or not"<<endl;
    cout<<"5.To stop the program"<<endl;
    cout<<"Calculate average age of guest"<<endl;
    cout<<"Enter the response:- ";
    cin>>response;
    switch(response)
    {
    case 1:
        cout<<"Enter the index:- ";
        cin>>index;
        print_guest_index(my_guests,index);
        goto label;
        break;
    case 2:
        cout<<"Enter the index:- ";
        cin>>index;
        remove_data(my_guests,index);
        goto label;
    case 3:
        avg_age(my_guests);
        goto label;
        break;
    case 4:
        cout<<"Enter the name of guest:- ";
        cin>>abc;
        find_guests(my_guests,abc);
        goto label;
        break;
    case 5:
        return 0;
    default:
        break;
    }
    return 0;
}
