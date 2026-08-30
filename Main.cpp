#include<iostream>
using namespace std;

enum Category{
    ELECTRONICS,
    CLOTHS,
    FOODS,
    BOOKS
};

enum orderstatus{
    PENDING,
    CONFORMED,
    CANCELLED,
    DELIEVERED
};

enum paymentStatus{
    UNPAID,
    PAID,
    FAILED
};

enum PaymentMethod{
    Credit_id,
    Upi,
    Cash
};

union PaymentInfo{
    int last4digits;
    string upiId;
};

class product{
    int prodid;
    string name;
    double price;
    int stock;
    Category category;

    public:

        product(int p, string n, double m, int s, Category c){
            prodid=p;
            name=n;
            price=m;
            stock=s;
            category=c;
        }

        void displayproduct(){
            cout<<"Product Id : "<<prodid<<endl;
            cout<<"Product name : "<<name<<endl;
            cout<<"Price : "<<price<<endl;
            cout<<"Stock : "<<stock<<endl;
            cout<<"Category : "<<category<<endl;
        }

        void updatestock(int u){
            stock+=u;
        }

        int checkavailibilty(){
            if(stock>0){
                return 1;
            }
            else{
                return 0;
            }
        }

        int getProductId(){
            return prodid;
        }
};

class customer{
    long custid;
    string custname;
    string email;
    long phone;
    string address;

    public:

        customer(long c, string n, string e, long p, string a){
            custid=c;
            custname=n;
            email=e;
            phone=p;
            address=a;
        }

        void displaycustomer(){
            cout<<"Customer id : "<<custid<<endl;
            cout<<"Customer name : "<<custname<<endl;
            cout<<"Email : "<<email<<endl;
            cout<<"Phone number : "<<phone<<endl;
            cout<<"Address : "<<address<<endl;
        }

        void updatecustomerDetails(string n, string e, long p, string a){
            custname=n;
            email=e;
            phone=p;
            address=a;
        }

        long getCustomerId(){
            return custid;
        }
};

struct order{
    long orderid;
    long custid;
    double amount;
    orderstatus ord;
    paymentStatus pay;

    order(long a, long b, double c, orderstatus d, paymentStatus e){
        orderid=a;
        custid=b;
        amount=c;
        ord=d;
        pay=e;
    }

    void displayorder(){
        cout<<"Order-Id : "<<orderid<<endl;
        cout<<"Cust-Id : "<<custid<<endl;
        cout<<"Amount : "<<amount<<endl;
        cout<<"Orderstatus : "<<ord<<endl;
        cout<<"Pay-ment status : "<<pay<<endl;
    }

    void updateorder(long a, long b, double c, orderstatus d, paymentStatus e){
        orderid=a;
        custid=b;
        amount=c;
        ord=d;
        pay=e;
    }

    void confirmorder(){
        if(pay==PAID){
            ord=CONFORMED;
            cout<<"Order is conformed"<<endl;
        }
        else{
            cout<<"Order cannot be conformed because payment failed"<<endl;
        }
    }

    void cancelorder(){
        if(ord==DELIEVERED){
            cout<<"Delievered Order Cannot be cancelled"<<endl;
        }
        else{
            ord=CANCELLED;
            cout<<"Order cancelled successfully"<<endl;
        }
    }
};

struct Payment{
    PaymentMethod method;
    paymentStatus status;
    PaymentInfo info;

    Payment(PaymentMethod m, paymentStatus s, int digits){
        method=m;
        status=s;

        if(method==Credit_id){
            info.last4digits=digits;
        }
    }

    Payment(PaymentMethod m, paymentStatus s, string id){
        method=m;
        status=s;

        if(method==Upi){
            info.upiId=id;
        }
    }

    Payment(PaymentMethod m, paymentStatus s){
        method=m;
        status=s;
    }

    void displayPayment(){
        cout<<"Payment Method : ";

        if(method==Credit_id){
            cout<<"Credit Card"<<endl;
            cout<<"Last 4 Digits : "<<info.last4digits<<endl;
        }
        else if(method==Upi){
            cout<<"UPI"<<endl;
            cout<<"UPI ID : "<<info.upiId<<endl;
        }
        else{
            cout<<"Cash"<<endl;
            cout<<"No additional information"<<endl;
        }

        cout<<"Payment Status : ";

        if(status==UNPAID)
            cout<<"Unpaid";
        else if(status==PAID)
            cout<<"Paid";
        else
            cout<<"Failed";

        cout<<endl;
    }

    void makePayment(order &o){
        if(o.ord==CANCELLED){
            cout<<"Payment cannot be made for a cancelled order"<<endl;
        }
        else if(status==FAILED){
            cout<<"Payment failed"<<endl;
        }
        else{
            status=PAID;
            o.pay=PAID;
            cout<<"Payment successful"<<endl;
        }
    }
};

int main(){

    product product1(101,"Phone",65000,10,ELECTRONICS);

    product1.displayproduct();

    cout<<endl;

    if(product1.checkavailibilty()){
        cout<<"Product is available"<<endl;
    }
    else{
        cout<<"Product is out of stock"<<endl;
    }

    cout<<endl;

    customer customer1(
        201,
        "Mohith",
        "mohith@gmail.com",
        7981058166,
        "Sirpur"
    );

    customer1.displaycustomer();

    cout<<endl;

    order order1(
        501,
        201,
        65000,
        PENDING,
        UNPAID
    );

    order1.displayorder();

    cout<<endl;

    Payment payment1(
        Upi,
        PAID,
        "mohith@upi"
    );

    payment1.displayPayment();

    cout<<endl;

    payment1.makePayment(order1);

    cout<<endl;

    order1.confirmorder();

    cout<<endl;

    order1.displayorder();

    cout<<endl;

    order1.cancelorder();

    cout<<endl;

    product product2(
        102,
        "Laptop",
        75000,
        0,
        ELECTRONICS
    );

    if(product2.checkavailibilty()){
        cout<<"Product 102 is available"<<endl;
    }
    else{
        cout<<"Product 102 is out of stock"<<endl;
    }

    cout<<endl;

    int searchProductId=999;

    if(product1.getProductId()!=searchProductId){
        cout<<"Invalid product ID"<<endl;
    }

    cout<<endl;

    long searchCustomerId=999;

    if(customer1.getCustomerId()!=searchCustomerId){
        cout<<"Invalid customer ID"<<endl;
    }

    cout<<endl;

    order order2(
        502,
        201,
        5000,
        DELIEVERED,
        PAID
    );

    order2.cancelorder();

    cout<<endl;

    order order3(
        503,
        201,
        3000,
        CANCELLED,
        UNPAID
    );

    Payment payment2(
        Cash,
        UNPAID
    );

    payment2.makePayment(order3);

    cout<<endl;

    order order4(
        504,
        201,
        4000,
        PENDING,
        FAILED
    );

    order4.confirmorder();

    return 0;
}