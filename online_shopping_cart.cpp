#include<iostream>
#include<iomanip>
#include<list>
#include<vector>
#include "my_module.cpp"
using namespace std;

class product
{
    public:
    int price , id;
    string name , brand;
    
    list<int>added_items = {};
    static int number_of_products;
    static int total_cost;
    int arr[6] = {101 , 102 ,103 ,104 , 105 ,106};
    static void display_number_of_items(){number_of_products++;}
    static void display_total_cost(int a){total_cost+=a;}
    product(){
        cout<<"Welcome the online shopping!"<<endl;
    }
    product(int i , string n , int d , string b) : id(d) , price(i) , name(n) , brand(b){}
};

class electronic:public product
{
    protected:
    int power_rating , warranty;
    string model , smart_device;

    public:
    electronic(int i , string n , int d , int pw , int war , string b , string mod , string smart) : product(i , n , d ,b) ,power_rating(pw), warranty(war), model(mod) , smart_device(smart){}
    void display_single(){
        cout<<"--------------------------------------"<<endl;
        cout<<"|"<<left<<setw(14)<<"ID"<<          ": "<<setw(20)<<id<<          "|"<<endl;
        cout<<"|"<<left<<setw(14)<<"Name"<<        ": "<<setw(20)<<name<<        "|"<<endl;
        cout<<"|"<<left<<setw(14)<<"Price"<<       ": "<<setw(20)<<price<<       "|"<<endl;
        cout<<"|"<<left<<setw(14)<<"Brand"<<       ": "<<setw(20)<<brand<<       "|"<<endl;
        cout<<"|"<<left<<setw(14)<<"Power Rating"<<": "<<setw(20)<<power_rating<<"|"<<endl;
        cout<<"|"<<left<<setw(14)<<"Warranty"<<    ": "<<setw(20)<<warranty<<    "|"<<endl;
        cout<<"|"<<left<<setw(14)<<"Model"<<       ": "<<setw(20)<<model<<       "|"<<endl;
        cout<<"|"<<left<<setw(14)<<"Smart"<<       ": "<<setw(20)<<smart_device<<"|"<<endl;
        cout<<"--------------------------------------"<<endl;
    }
    static void display_electronics(){
        electronic obj1(12000 , "OLED" , 101 , 150 , 24 , "sumsung" , "8748huh" , "Yes");
        electronic obj2(20000 ,"Smart" , 102, 170 , 28 , "Panasonic" , "2374gtr" , "Yes");
        electronic obj3(25000 ,"Vivid" , 103, 200 , 36 , "Sony" , "6435hug" , "No");

        obj1.display_single();
        obj2.display_single();
        obj3.display_single();
    }
};

class clothing : public product
{
    protected:
    string size , color , gender , fit_type;
    int material;

    public:
    clothing(int i , string n , int d , string b , int mat , string s , string cl , string gen , string fit) : product(i , n ,d ,b) , size(s) , color(cl) , gender(gen) , fit_type(fit) , material(mat){}
    void display_single1(){
        cout<<"--------------------------------------"<<endl;
        cout<<"|"<<left<<setw(14)<<"ID"<<          ": "<<setw(20)<<id<<          "|"<<endl;
        cout<<"|"<<left<<setw(14)<<"Name"<<        ": "<<setw(20)<<name<<        "|"<<endl;
        cout<<"|"<<left<<setw(14)<<"Price"<<       ": "<<setw(20)<<price<<       "|"<<endl;
        cout<<"|"<<left<<setw(14)<<"Brand"<<       ": "<<setw(20)<<brand<<       "|"<<endl;
        cout<<"|"<<left<<setw(14)<<"Material"<<    ": "<<setw(20)<<material<<    "|"<<endl;
        cout<<"|"<<left<<setw(14)<<"size"<<        ": "<<setw(20)<<size<<        "|"<<endl;
        cout<<"|"<<left<<setw(14)<<"color"<<       ": "<<setw(20)<<color<<       "|"<<endl;
        cout<<"|"<<left<<setw(14)<<"Gender"<<      ": "<<setw(20)<<gender<<      "|"<<endl;
        cout<<"|"<<left<<setw(14)<<"Fit-type"<<    ": "<<setw(20)<<fit_type<<    "|"<<endl;
        cout<<"--------------------------------------"<<endl;
    }
    static void display_clothing(){
        clothing obj4(900 , "T-shirt" , 104 , "Puma" , 100 , "M" , "Black" , "Male" , "Regular");
        clothing obj5(500 , "Shirt" , 105 , "Cotton Candy" , 100 , "L" , "Blue" , "Male" , "Regular");
        clothing obj6(1200 , "Hoodie" , 106 , "Nike" , 100 , "M" , "White" , "Female" , "Regular");

        obj4.display_single1();
        obj5.display_single1();
        obj6.display_single1();
    }
};

int product::number_of_products = 0 ;
int product::total_cost = 0 ;

int main(){
    product pro;

    bool active1 = true;
    bool active2 = true;
    bool active3 = true;
    while(active1){
    int choice1;
    cout<<"\nPlease Select the shopping mode : \n1) Add Products.\n2) Remove Products.\n3) Display Items.\n4) Calculate Total cost.\n5) Exit\n";
    cin>>choice1;
    if (choice1 == 5){active1=false;}
    
    switch (choice1){
        while(active2){
        case 1:
             cout<<"Here's the list of product available today :\n1.Electronics\n2.Clothing.\n3.Exit\n"<<endl;
             int choice; cout<<"Enter the choice : ";
             cin>>choice;
            if (choice == 1){
                electronic::display_electronics();
                char decision1; cout<<"Want to add something(Y/N) : ";
                cin>>decision1;

                    if (decision1 == 'y' || decision1 == 'Y'){
                    cout<<"Please Enter the Id number of the product : ";
                    int Id;
                    cin>>Id;
                    pro.added_items.push_back(Id);
                    pro.display_number_of_items();
                
                        while(active3){
                        char decision2 ; cout<<"Want to add something more(Y/N) : ";cin>>decision2;
                        if (decision2 == 'y' || decision2 == 'Y'){
                            cout<<"Please Enter the Id number of the product : ";
                            cin>>Id;
                            pro.added_items.push_back(Id);
                            pro.display_number_of_items();
                        }
                        else if(decision2 == 'n' || decision2 == 'N'){break;}
                        }
                    cout<<"Thank you! ,Products has added to your cart.\n"<<endl;
                } 
            }
            else if(choice == 2){
                clothing::display_clothing();
                char decision1; cout<<"Want to add something(Y/N) : ";
                cin>>decision1;
                if (decision1 == 'y' || decision1 == 'Y'){
                    int Id;cout<<"Please Enter the Id number of the product : ";
                    cin>>Id;
                    pro.added_items.push_back(Id);
                    pro.display_number_of_items();
                    
                    while(active3){
                        char decision2 ; cout<<"Want to add something more(Y/N) : ";cin>>decision2;
                        if (decision2 == 'y' || decision2 == 'Y'){
                            cout<<"Please Enter the Id number of the product : ";
                            cin>>Id;
                            pro.added_items.push_back(Id);
                            pro.display_number_of_items();
                        }
                        else if(decision2 == 'n' || decision2 == 'N'){break;}
                    }
                    cout<<"Thank you! ,Product has added to your cart.\n"<<endl;
                    }
                }
            else if(choice == 3){
                active2 = false;
            }
            else{cout<<"Please Enter valid choice!";}
            break;
        case 2:
            int remove_id;
            cout<<"Please Enter the id number of the product to remove it from the cart! : ";cin>>remove_id;
            pro.added_items.remove(remove_id);cout<<"Following item has been removed from the cart!."<<endl;
            pro.number_of_products--;
            if(remove_id == 101){electronic obj1(12000 , "OLED" , 101 , 150 , 24 , "sumsung" , "8748huh" , "Yes"); obj1.display_single(); pro.total_cost-=obj1.price;}
            else if(remove_id == 102){electronic obj2(20000 ,"Smart" , 102, 170 , 28 , "Panasonic" , "2374gtr" , "Yes"); obj2.display_single();pro.total_cost-=obj2.price;}
            else if(remove_id == 103){electronic obj3(25000 ,"Vivid" , 103, 200 , 36 , "Sony" , "6435hug" , "No");; obj3.display_single();pro.total_cost-=obj3.price;}
            else if(remove_id == 104){clothing obj4(900 , "T-shirt" , 104 , "Puma" , 100 , "M" , "Black" , "Male" , "Regular");; obj4.display_single1();pro.total_cost-=obj4.price;}
            else if(remove_id == 105){clothing obj5(500 , "Shirt" , 105 , "Cotton Candy" , 100 , "L" , "Blue" , "Male" , "Regular");; obj5.display_single1();pro.total_cost-=obj5.price;}
            else if(remove_id == 106){clothing obj6(1200 , "Hoodie" , 106 , "Nike" , 100 , "M" , "White" , "Female" , "Regular");; obj6.display_single1();pro.total_cost-=obj6.price;}
            break;
        case 3:
            for(int id : pro.added_items){
                if( id == 101){electronic obj1(12000 , "OLED" , 101 , 150 , 24 , "sumsung" , "8748huh" , "Yes"); obj1.display_single();}
                else if(id == 102){electronic obj2(20000 ,"Smart" , 102, 170 , 28 , "Panasonic" , "2374gtr" , "Yes"); obj2.display_single();}
                else if(id == 103){electronic obj3(25000 ,"Vivid" , 103, 200 , 36 , "Sony" , "6435hug" , "No"); obj3.display_single();}
                else if(id == 104){clothing obj4(900 , "T-shirt" , 104 , "Puma" , 100 , "M" , "Black" , "Male" , "Regular"); obj4.display_single1();}
                else if(id == 105){clothing obj5(500 , "Shirt" , 105 , "Cotton Candy" , 100 , "L" , "Blue" , "Male" , "Regular"); obj5.display_single1();}
                else if(id == 106){clothing obj6(1200 , "Hoodie" , 106 , "Nike" , 100 , "M" , "White" , "Female" , "Regular"); obj6.display_single1();}
            }
            cout<<"\nNumber of items in cart : "<<pro.number_of_products<<endl;
            break;
        case 4:
            for(int id : pro.added_items){
                if( id == 101){electronic obj1(12000 , "OLED" , 101 , 150 , 24 , "sumsung" , "8748huh" , "Yes"); pro.display_total_cost(obj1.price);}
                else if(id == 102){electronic obj2(20000 ,"Smart" , 102, 170 , 28 , "Panasonic" , "2374gtr" , "Yes"); pro.display_total_cost(obj2.price);}
                else if(id == 103){electronic obj3(25000 ,"Vivid" , 103, 200 , 36 , "Sony" , "6435hug" , "No"); pro.display_total_cost(obj3.price);}
                else if(id == 104){clothing obj4(900 , "T-shirt" , 104 , "Puma" , 100 , "M" , "Black" , "Male" , "Regular"); pro.display_total_cost(obj4.price);}
                else if(id == 105){clothing obj5(500 , "Shirt" , 105 , "Cotton Candy" , 100 , "L" , "Blue" , "Male" , "Regular"); pro.display_total_cost(obj5.price);}
                else if(id == 106){clothing obj6(1200 , "Hoodie" , 106 , "Nike" , 100 , "M" , "White" , "Female" , "Regular"); pro.display_total_cost(obj6.price);}
            }
            cout<<"Total cost for you shopping is : "<<pro.total_cost<<" Rs"<<endl;
            break;
        }
      }
    } 
}