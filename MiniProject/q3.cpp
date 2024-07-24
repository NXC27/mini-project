#include<iostream>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;

class Book
{
    private:
    int id;
    string title;
    string author;
    string genre;
    int quantity_available;
    float price_copy;
    public:
    //constructor(
    Book(int uid=0,string utitle="",string uauthor="", 
            string ugenre="", int uqa=0, float ppc=0) :
        id(uid),
        title(utitle),
        author(uauthor),
        genre(ugenre),
        quantity_available(uqa),
        price_copy(ppc)
        {}
    void get_info()
	{
		cout << "===== Enter Book Information ====="<<endl;
		cout << "Enter Book ID : ";
		cin >> id;
		cout << "Enter Title: ";
		cin >> title;
		cout << "Enter author: ";
		cin >> author;
		cout << "Enter genre: ";
		cin >> genre;
		cout << "Enter Quantity Available: ";
		cin >> quantity_available;
		cout << "Enter Price per Copy: ";
		cin >> price_copy;
	}
	string get_title()
	{
	    return  title;
	}
	void update_quantity(int value)
	{
	    quantity_available += value;
	}
    float calculate_revenue()
    {
        return (float)quantity_available*price_copy;
    }
	void display()
	{
		cout << "===== Book Information ====="<<endl;
		cout << "Book ID : " << id << endl;
		cout << "Enter Title: " << title << endl;
		cout << "Enter author: " << author << endl;
		cout << "Enter genre: " << genre << endl;
		cout << "Enter Quantity Available: " << quantity_available << endl;
		cout << "Enter Price per Copy: " << price_copy << endl;
		cout<<endl;
	}
};

int main()
{
    vector<Book> vect;
    Book b(0);
    
    int choice;
    int len;
    int pos = 0;
    float max = 0;
    string title_book;
    int new_quantity;
    while(1)
    {
        cout<<"^^^^^^^^^^ MENU ^^^^^^^^^^"<<endl;
        cout<<"1.Add Book"<<endl;
        cout<<"2.Display All Books"<<endl;
        cout<<"3.Display Revenue"<<endl;
        cout<<"4.Display Bestselling Book"<<endl;
        cout<<"5.Search Book By Title"<<endl;
        cout<<"6.Update Book Quantity"<<endl;
        cout<<"7.Exit"<<endl;
        cout<<"Enter your choice: ";
        cin>>choice;
        
        switch(choice)
        {
            case 1:
                b.get_info();
                vect.push_back(b);
                break;
            case 2:
                len = vect.size();
                for (int i=0; i<len; i++)
                {
                    vect[i].display();
                }
                break;
            case 3:
                len = vect.size();
                for (int i=0; i<len; i++)
                {
                    cout<<"Revenue of "<<vect[i].get_title()<<" : ";
                    cout<<vect[i].calculate_revenue()<<endl;
                }
                cout<<endl;
                break;
            case 4:
                cout<<"Best Seller: "<<endl;
                len = vect.size();
                max = vect[0].calculate_revenue();
            	for (int i=0; i<len; i++)
            	{
                    if (vect[i].calculate_revenue() > max)
                    {
                        max = vect[i].calculate_revenue();
                        pos = i;
                    }
            	}
                vect[pos].display();
                break;
            case 5:
                cout<<"Enter the book's title: ";
                cin>>title_book;
            	for (int i=0; i<len; i++)
            	{
                    if (title_book.compare(vect[i].get_title())==0)
                    {
                        pos = i;
                        break;
                    }
                    else
                    {
                        cout<<"Counld Not Find Out That Book's Title"<<endl;
                    }
            	}
                vect[pos].display();
                break;
            case 6:
                cout<<"Enter the book's title: ";
                cin>>title_book;
            	for (int i=0; i<len; i++)
            	{
                    if (title_book.compare(vect[i].get_title())==0)
                    {
                        pos = i;
                        break;
                    }
                    else
                    {
                        cout<<"Could Not Find Out That Book's Title"<<endl;
                    }
            	}
            	cout<<"Enter new quantity: ";
            	cin>>new_quantity;
                vect[pos].update_quantity(new_quantity);
                vect[pos].display();
                break;
            case 7:
                return 0;
                break;
            default:
                cout<<"Please Enter A Valid Value"<<endl;
                break;
        }
    }
}