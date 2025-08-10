#include<iostream>	
#include<string>    //FOR STRING
#include<sstream>	//FOR ISTRINGSTREAM
#include<fstream>	//FOR FILE HANDLING
#include<stdexcept> //for exceptional handling
using namespace std;

//for removing spaces if we are getting the name in getline()
string removeSpaces(string str) {
    			string result = "";
    			for (char c : str) {
        				if (c != ' ') {
            				result += c;
        				}
    				}
    			return result;
				} 

//MENU:
class menu
{
	string name,price,available;
	public:
		menu()
		{
			
		}
		
		int choice;
		int num=0;
		int additems;
		
		//FOR SETTING MENU FROM MANAGER
		
		//FOR ADDING PRODUCTS OF DIFFERENT KIND.
		void addproducts()
		{
				num=num+1;
				cout<<"Enter name of the new item: ";
				cin.ignore();
				getline(cin,name);
				cout<<"Enter price of the "<<name<<": ";
				cin>>price;
				cout<<"Enter the amount you want to add: ";
				cin>>available;
		}
		
		//DISPLAY FUNCTION.
		void display()
		{
			cout<<num<<":\nName: "<<name<<"\nPrice: "<<price<<"\nAvailable: "<<available<<"."<<endl;
		}
		
		//for adding files
		void addfile(string file,string category)		//Encapsulation (reuse of function)
		{
			ofstream fileopen(file,ios::app);
			if(fileopen.is_open())
			{
				cout<<"Category name: "<<category<<":"<<endl;
				addproducts();
				display();
				fileopen<<num<<","<<name<<","<<price<<","<<available<<"."<<endl;
			}
			else{
				cout<<"Error in opening the file."<<endl;
			}	
		}
		//file name	
		void additem()
		{
		do
		{
		cout<<"Select the category for which you want to add the product.(1 to 5)"<<endl;
		cout<<"1. Vegetarian.\n2. Vegan.\n3. Glutten-Free.\n4. Drinks.\n5.Speciality."<<endl;
		cin>>choice;
	
		if(choice==1)
		{
			addfile("Vegetarian.txt","Vegetarian");
		}
		else if(choice==2)
		{
			addfile("Vegan.txt","Vegan");
		}
		else if(choice==3)
		{
			addfile("Glutten_Free.txt","Glutten_Free");
			
		}
		else if(choice==4)
		{
			addfile("Drinks.txt","Drinks");
		}
		else if(choice==5)
		{
			addfile("Speciality.txt","Speciality");
		}
		else
		{
			cout<<"Wrong digit entered. Please enter number between 1 to 3."<<endl;
		}
		
		cout<<"Enter 0 to add more items: ";
		cin>>additems;
		}while(additems==0);
		}
		
		
		
		//READING THE MENU AND DISPLAYING IT
		
		void display(string file)
		{
			ifstream fileread(file);
			if(fileread.is_open())
			{
				string line;
				while(getline(fileread,line))
				{
					cout<<line<<endl;
				}
				fileread.close();
			}
			else{
				cout<<"Error in opening the file."<<endl;
			}
			
		}
		
		void displayingallmenu()
		{
			cout<<"Vegetarian: "<<endl;
			display("Vegetarian.txt");
			cout<<"Vegan: "<<endl;
			display("Vegan.txt");
			cout<<"Glutten-Free: "<<endl;
			display("Glutten_Free.txt");
			cout<<"Drinks: "<<endl;
			display("Drinks.txt");
			cout<<"Speciality: "<<endl;
			display("Speciality.txt");
			
		} 
		
		//MODIFY THE EXISTING FILE
		void category(string category)
		{
			ofstream filemodify(category,ios::app);
			if(filemodify.is_open())
			{
				addproducts();
				filemodify<<num<<","<<name<<","<<price<<","<<available<<"."<<endl;
				filemodify.close();
				cout<<"File modified successfully."<<endl;
			}
			else{
				cout<<"Error in opening the file."<<endl;
			}
		}
		void modify()
		{
			int modifyfile;
			cout<<"Select the category for which you want to update the product.(1 to 5)"<<endl;
			cout<<"1. Vegetarian.\n2. Vegan.\n3. Glutten-Free.\n4. Drinks.\n5. Speciality."<<endl;
			cin>>modifyfile;
			
			if(modifyfile==1)
			{
				category("Vegetarian.txt");
				
			}
			else if(modifyfile==2)
			{
				category("Vegan.txt");
		}
		else if(modifyfile==3)
			{
				category("Glutten_Free.txt");
		}
		else if(modifyfile==4)
			{
				category("Drinks.txt");
		}
		else if(modifyfile==5)
			{
				category("Speciality.txt");
		}
	}
	
	
	//update price
	void adjustprices()
	{
	ifstream vegetarian1("Vegetarian.txt");
	string line;
	string number,name,price,updateprice;
	string findname,avail;
	int categorychoice;
	cout<<"Enter the category choice for which you want to update the price. "<<endl;
	cout<<"1. Vegetarian.\n2. Vegan.\n3. Glutten_Free.\n4. Drinks.\n5. Speciality.\n";
	cin>>categorychoice;
	if(categorychoice==1)
	{
	if(vegetarian1.is_open())
	{
		cout<<"Enter the name of the item you want to update the price: ";
		cin.ignore();
		getline(cin,findname);
		ofstream updatevegetarian("Updatevegetarian.txt",ios::app);
		while(getline(vegetarian1,line))
		{
			istringstream iss(line);
			getline(iss,number,',');
			getline(iss,name,',');
			getline(iss,price,',');
			getline(iss,avail,',');
			if(findname==name)
			{
				cout<<"Enter the updated price: ";
				cin>>updateprice;
				
				if(updatevegetarian.is_open())
				{
					updatevegetarian<<number<<","<<name<<","<<updateprice<<","<<available<<","<<endl;
				}

			}
			else 
			{
				if(updatevegetarian.is_open())
				updatevegetarian<<line<<endl;
			}
			
		}
			updatevegetarian.close();
		vegetarian1.close();
		string file="Vegetarian.txt";
		string updatefile="Updatevegetarian.txt";
		if(remove(file.c_str())==0 )
		{
			if(rename(updatefile.c_str(),file.c_str())==0)
			cout<<"Price updated successfully."<<endl;
		}
	
		else{
			remove(updatefile.c_str());
			cout<<"Item not found in the file."<<endl;
		}
	}
	}
	else if(categorychoice==2)
	{	
	ifstream vegan1("Vegan.txt");
	string line;
	string number,name,price,updateprice;
	string findname;
	if(vegetarian1.is_open())
	{
		cout<<"Enter the name of the item you want to update the price: ";
		cin.ignore();
		getline(cin,findname);
		ofstream updatevegan("Updatevegan.txt",ios::app);
		while(getline(vegan1,line))
		{
			istringstream iss(line);
			getline(iss,number,',');
			getline(iss,name,',');
			getline(iss,price,',');
			getline(iss,avail,',');
			if(findname==name)
			{
				cout<<"Enter the updated price: ";
				cin>>updateprice;
				
				if(updatevegan.is_open())
				{
					updatevegan<<number<<","<<name<<","<<updateprice<<","<<available<<","<<endl;
				}
			
		
			}
			 else
			{
				if(updatevegan.is_open())
				updatevegan<<line<<endl;
			}
			
		}
			updatevegan.close();
		vegan1.close();
			string file="Vegan.txt";
			string updatefile="Updatevegan.txt";
		if(remove(file.c_str())==0 )
		{
			if(rename(updatefile.c_str(),file.c_str())==0)
			cout<<"Price updated successfully."<<endl;
		}
	
		else{
			remove(updatefile.c_str());
			cout<<"Item not found in the file."<<endl;
		}
	}
		
	}
	else if (categorychoice == 3) {
    ifstream gluttenfree1("Glutten_Free.txt");
    string line, number, name, price, avail, updateprice;
    string findname;

    if (gluttenfree1.is_open()) {
        cout << "Enter the name of the item you want to update the price: ";
        cin.ignore();
        getline(cin,findname);

        ofstream updategluttenfree("Updategluttenfree.txt", ios::app);

        bool itemFound = false;

        while (getline(gluttenfree1, line)) {
            istringstream iss(line);
            getline(iss, number, ',');
            getline(iss, name, ',');
            getline(iss, price, ',');
            getline(iss, avail, ',');

            if (findname == name) {
                itemFound = true;
                cout << "Enter the updated price: ";
                cin >> updateprice;

                if (updategluttenfree.is_open()) {
                    updategluttenfree << number << "," << name << "," 
                                      << updateprice << "," << avail << "," << endl;
                }
            } 
			else {
                if (updategluttenfree.is_open()) {
                    updategluttenfree << line << endl;
                }
            }
        }

        updategluttenfree.close();
        gluttenfree1.close();

        string originalFile = "Glutten_Free.txt";
        string updatedFile = "Updategluttenfree.txt";

        if (itemFound) {
            // Remove the old file and rename the updated file
            if (remove(originalFile.c_str()) == 0 && rename(updatedFile.c_str(), originalFile.c_str()) == 0) {
                cout << "Price updated successfully." << endl;
            } else {
                cout << "Error updating the file." << endl;
            }
        } else {
            remove(updatedFile.c_str()); // Cleanup temporary file if item not found
            cout << "Item not found in the file." << endl;
        }
    } else {
        cout << "Error: Unable to open Glutten-Free.txt file." << endl;
    }
}
	else if(categorychoice==4)
	{
		ifstream drinks("Drinks.txt");
	string line;
	string number,name,price,updateprice;
	string findname;
	if(drinks.is_open())
	{
		cout<<"Enter the name of the item you want to update the price: ";
		cin.ignore();
		getline(cin,findname);
		ofstream updatedrinks("Updatedrinks.txt",ios::app);
		while(getline(drinks,line))
		{
			istringstream iss(line);
			getline(iss,number,',');
			getline(iss,name,',');
			getline(iss,price,',');
			getline(iss,avail,',');
			if(findname==name)
			{
				cout<<"Enter the updated price: ";
				cin>>updateprice;
				
				if(updatedrinks.is_open())
				{
					updatedrinks<<number<<","<<name<<","<<updateprice<<","<<available<<","<<endl;
				}

			}
			else{
			 if(updatedrinks.is_open())
			{
				updatedrinks<<line<<endl;
			}
		}
		}
			updatedrinks.close();
		drinks.close();
		string file="Drinks.txt";
		string updatefile="Updatedrinks.txt";
		if(remove(file.c_str())==0 )
		{
			if(rename(updatefile.c_str(),file.c_str())==0)
			cout<<"Price updated successfully."<<endl;
		}
	
		else{
			remove(updatefile.c_str());
			cout<<"Item not found in the file."<<endl;
		}
	}
	}
	else if(categorychoice==5)
	{
		ifstream speciality("Speciality.txt");
	string line;
	string number,name,price,updateprice;
	string findname;
	if(speciality.is_open())
	{
		cout<<"Enter the name of the item you want to update the price: ";
		cin.ignore();
		getline(cin,findname);
		ofstream updatespeciality("Updatespeciality.txt",ios::app);
		while(getline(speciality,line))
		{
			istringstream iss(line);
			getline(iss,number,',');
			getline(iss,name,',');
			getline(iss,price,',');
			getline(iss,avail,',');
			if(findname==name)
			{
				cout<<"Enter the updated price: ";
				cin>>updateprice;
				
				if(updatespeciality.is_open())
				{
					updatespeciality<<number<<",Name: "<<name<<",Price: "<<updateprice<<",Availability: "<<available<<","<<endl;
				}
			
			}
			else{
			 if(updatespeciality.is_open())
			{
				updatespeciality<<line<<endl;
			}
		}
		}
			updatespeciality.close();
		speciality.close();
		string file="Speciality.txt";
		string updatefile="Updatespeciality.txt";
		if(remove(file.c_str())==0 )
		{
			if(rename(updatefile.c_str(),file.c_str())==0)
			cout<<"Price updated successfully."<<endl;
		}
	
		else{
			remove(updatefile.c_str());
			cout<<"Item not found in the file."<<endl;
		}
	}
	}
	else
	{
		cout<<"You entered incorrect digit or key. "<<endl;
		adjustprices();
	}
	}
	
	
	//Update availability
	void updateavailability()
	{
			ifstream vegetarian1("Vegetarian.txt");
	string line;
	string number,name,price,updateavail;
	string findname,avail;
	int categorychoice;
	int choicecategory;
	do{
	cout<<"Enter the category choice for which you want to update the availability. "<<endl;
	cout<<"1. Vegetarian.\n2. Vegan.\n3. Glutten_Free.\n4. Drinks.\n5. Speciality.\n";
	cin>>categorychoice;
  if (categorychoice == 1) {
        if (vegetarian1.is_open()) {
            cout << "Enter the name of the item you want to update the availability: ";
            cin.ignore();
            getline(cin,findname);
            ofstream updatevegetarian("Updatevegetarian.txt", ios::app);
            while (getline(vegetarian1, line)) {
                istringstream iss(line);
                getline(iss, number, ',');
                getline(iss, name, ',');
                getline(iss, price, ',');
                getline(iss, avail, ',');
                if (findname == name) {
                    cout << "Enter the updated availability: ";
                    cin >> updateavail;

                    if (updatevegetarian.is_open()) {
                        updatevegetarian << number << "," << name << "," << price << "," << updateavail << "," << endl;
                    }
                } 
				else {
                    if (updatevegetarian.is_open()) {
                        updatevegetarian << line << endl;
                    }
                }
            }
            updatevegetarian.close();
            vegetarian1.close();

            string file = "Vegetarian.txt";
            string updatefile = "Updatevegetarian.txt";
            if (remove(file.c_str()) == 0) {
                if (rename(updatefile.c_str(), file.c_str()) == 0) {
                    cout << "Price updated successfully." << endl;
                }
            } else {
                remove(updatefile.c_str());
                cout << "Item not found in the file." << endl;
            }
        }
    } else if (categorychoice == 2) {
        ifstream vegan1("Vegan.txt");
        if (vegan1.is_open()) {
            cout << "Enter the name of the item you want to update the availability: ";
            cin.ignore();
            getline(cin,findname);
            ofstream updatevegan("Updatevegan.txt", ios::app);
            while (getline(vegan1, line)) {
                istringstream iss(line);
                getline(iss, number, ',');
                getline(iss, name, ',');
                getline(iss, price, ',');
                getline(iss, avail, ',');
                if (findname == name) {
                    cout << "Enter the updated availability: ";
                    cin >> updateavail;

                    if (updatevegan.is_open()) {
                        updatevegan << number << "," << name << "," << price << "," << updateavail << "," << endl;
                    }
                } else {
                    if (updatevegan.is_open()) {
                        updatevegan << line << endl;
                    }
                }
            }
            updatevegan.close();
            vegan1.close();

            string file = "Vegan.txt";
            string updatefile = "Updatevegan.txt";
            if (remove(file.c_str()) == 0) {
                if (rename(updatefile.c_str(), file.c_str()) == 0) {
                    cout << "Price updated successfully." << endl;
                }
            } else {
                remove(updatefile.c_str());
                cout << "Item not found in the file." << endl;
            }
        }
    } 
	else if (categorychoice == 3) {
        ifstream gluttenfree1("Glutten_Free.txt");
        if (gluttenfree1.is_open()) {
            cout << "Enter the name of the item you want to update the availability: ";
           getline(cin,findname);
            ofstream updategluttenfree("Updategluttenfree.txt", ios::app);
            while (getline(gluttenfree1, line)) {
                istringstream iss(line);
                getline(iss, number, ',');
                getline(iss, name, ',');
                getline(iss, price, ',');
                getline(iss, avail, ',');
                if (findname == name) {
                    cout << "Enter the updated availability: ";
                    cin >> updateavail;

                    if (updategluttenfree.is_open()) {
                        updategluttenfree << number << "," << name << "," << price << "," << updateavail << "," << endl;
                    }
                } else {
                    if (updategluttenfree.is_open()) {
                        updategluttenfree << line << endl;
                    }
                }
            }
            updategluttenfree.close();
            gluttenfree1.close();

            string file = "Glutten_Free.txt";
            string updatefile = "Updategluttenfree.txt";
            if (remove(file.c_str()) == 0) {
                if (rename(updatefile.c_str(), file.c_str()) == 0) {
                    cout << "Price updated successfully." << endl;
                }
            } else {
                remove(updatefile.c_str());
                cout << "Item not found in the file." << endl;
            }
        }
    } 
	else if (categorychoice == 4) {
        ifstream drinks("Drinks.txt");
        if (drinks.is_open()) {
            cout << "Enter the name of the item you want to update the availability: ";
            cin.ignore();
            getline(cin,findname);
            ofstream updatedrinks("Updatedrinks.txt", ios::app);
            while (getline(drinks, line)) {
                istringstream iss(line);
                getline(iss, number, ',');
                getline(iss, name, ',');
                getline(iss, price, ',');
                getline(iss, avail, ',');
                if (findname == name) {
                    cout << "Enter the updated availability: ";
                    cin >> updateavail;

                    if (updatedrinks.is_open()) {
                        updatedrinks << number << "," << name << "," << price << "," << updateavail << "," << endl;
                    }
                } else {
                    if (updatedrinks.is_open()) {
                        updatedrinks << line << endl;
                    }
                }
            }
            updatedrinks.close();
            drinks.close();

            string file = "Drinks.txt";
            string updatefile = "Updatedrinks.txt";
            if (remove(file.c_str()) == 0) {
                if (rename(updatefile.c_str(), file.c_str()) == 0) {
                    cout << "Price updated successfully." << endl;
                }
            } else {
                remove(updatefile.c_str());
                cout << "Item not found in the file." << endl;
            }
        }
    } 
	else if (categorychoice == 5) {
        ifstream speciality("Speciality.txt");
        if (speciality.is_open()) {
            cout << "Enter the name of the item you want to update the availability: ";
            cin.ignore();
           getline(cin,findname);
            ofstream updatespeciality("Updatespeciality.txt", ios::app);
            while (getline(speciality, line)) {
                istringstream iss(line);
                getline(iss, number, ',');
                getline(iss, name, ',');
                getline(iss, price, ',');
                getline(iss, avail, ',');
                if (findname == name) {
                    cout << "Enter the updated availability: ";
                    cin >> updateavail;

                    if (updatespeciality.is_open()) {
                        updatespeciality << number << "," << name << "," << price << "," << updateavail << "," << endl;
                    }
                } else {
                    if (updatespeciality.is_open()) {
                        updatespeciality << line << endl;
                    }
                }
            }
            updatespeciality.close();
            speciality.close();

            string file = "Speciality.txt";
            string updatefile = "Updatespeciality.txt";
            if (remove(file.c_str()) == 0) {
                if (rename(updatefile.c_str(), file.c_str()) == 0) {
                    cout << "Price updated successfully." << endl;
                }
            } else {
                remove(updatefile.c_str());
                cout << "Item not found in the file." << endl;
            }
        }
    } 
	else {
        cout << "You entered an incorrect digit or key." << endl;
    }
    cout<<"Enter 1 to update another item.";
    cin>>choicecategory;
}while(choicecategory==1);
}
};

//class customer to take customer id etc
class customer:public menu
{
	char press;
	string name;
	string contact;
	int preference;
	int id=30145;
	 int order=0;
	int searchitem;
	string item;
	public:
		
		customer()
		{
		}
		customer(string n,string c)
		{
			name=n;
			contact=c;
		}
		void customerdetail()
		{
			id=id++;
			cout<<"Enter name of customer: ";
			cin.ignore();
			getline(cin,name);
			cout<<"Enter contact of customer: ";
			cin>>contact;
			cout<<"Select the preference of the customer:\n ";
			cout<<"1.Vegetarian\n2.Vegan\n3.Glutten-Free"<<endl;
			cin>>preference;

			ofstream details("Customer.txt",ios::app);
			if(details.is_open())
			{
				details<<name<<","<<contact<<","<<id<<",";
				if(preference==1)
				{
					details<<"Vegetarian"<<"."<<endl;
					cout<<"Vegetarian is preference of customer."<<endl;
				}
				else if(preference==2)
				{
					details<<"Vegan"<<"."<<endl;
					cout<<"Vegan is preference of customer."<<endl;
				}
				else if(preference==3)
				{
					details<<"Glutten-Free"<<"."<<endl;
					cout<<"Glutten-Free is preference of customer."<<endl;
				}
				id++;
			}
			else{
				cout<<"File not found."<<endl;
			}
		}
	
		
	void searchcategory(string file) {
    string item, line, name1, price1, num1, availability;
    int itemsneed, priceofday, avail1;
    bool itemfound = false;

    ifstream searchobj(file);
    if (!searchobj.is_open()) {
        cout << "Error: Unable to open file." << endl;
        return;
    }
    
    ofstream temp("temp.txt");
    ofstream order("Order.txt",ios::app);

    if (!temp.is_open() || !order.is_open()) {
        cout << "Error: Unable to open necessary files." << endl;
        return;
    }

    cout << "Enter the name of the item: ";
    cin.ignore();
    getline(cin,item);
    cout << "Enter how many items you need: ";
    cin >> itemsneed;
    while (getline(searchobj, line)) {
        istringstream iss(line);
        getline(iss, num1, ',');
        getline(iss, name1, ',');
        getline(iss, price1, ',');
        getline(iss, availability, ',');
        try {
            priceofday = stoi(price1);
            avail1 = stoi(availability);
            if (item == name1) { 
                if (itemsneed <= avail1) {
                    avail1 -= itemsneed;
                    priceofday*=itemsneed;
                    itemfound = true;
                    order << num1 << "," << name1 << "," << priceofday << "," << endl;
                    cout << "Order placed: " << name1 << " (" << itemsneed << ")" << endl;
                    if (avail1 == 0) {
                        cout << "Stock depleted. You need to restock this item." << endl;
                    } 
					else if (avail1 < 6) {
                        cout << "Warning: Stock is running low (" << avail1 << " remaining)." << endl;
                    } 
					else {
                        cout << "Stock updated: " << avail1 << " items remaining." << endl;
                    }
                } 
				else {
                    cout << "Insufficient stock! Available stock: " << avail1 << endl;
                }

                
                temp << num1 << "," << name1 << "," << price1 << "," << avail1 << "," << endl;
            } 
			else {
                
                temp << line << endl;
            }
        } 
		catch (exception e) {
            cout << "Error processing line: " << e.what() << endl;
        }
    }


    searchobj.close();
    temp.close();
    order.close();

    if (itemfound) 
	{
        if (remove(file.c_str()) == 0 && rename("temp.txt", file.c_str()) == 0) {
            cout << "File updated successfully." << endl;
        } 
		else {
            cout << "Error updating the file." << endl;
        }
    } 
	else {
        remove("temp.txt"); 
        cout << "Item not found in the file." << endl;
    }
}
		
		
		//SEARCH FOR SEARCHING IN WHICH FILE IT CONTAINS
		void search()
		{
			
			order+=1;
			cout<<"Order of the day: "<<order<<endl;
			do
			{
			
			
			do{
				displayingallmenu();
				cout<<"Enter: \n1 to select vegetarian.\n2 to select Vegan.\n3 to select Glutten-free.\n4 to select drinks\n5 for speciality."<<endl;
				cin>>searchitem;
			switch(searchitem)
			{
				case 1:
					{
						searchcategory("Vegetarian.txt");
						break;
					}
				case 2:
					{
						searchcategory("Vegan.txt");
						break;
					}
				case 3:
					{
						searchcategory("Glutten_Free.txt");
						break;
					}
				case 4:
					{
						searchcategory("Drinks.txt");
						break;
					}
				case 5:
					{
						searchcategory("Speciality.txt");
						break;
					}
				default:
					{
						cout<<"Not correct input."<<endl;
						break;
					}
				
			}
				cout << "Press 'y' or 'Y' to order another item: ";
        		cin >> press;
        	}while(press=='y' || press=='Y');
		}while((searchitem!=1)&&(searchitem!=2)&&(searchitem!=3)&&(searchitem!=4)&&(searchitem!=5));
	}
};

//class order for ordering and checking loyalty points
class order:public customer {
string namecustomer;
float total=0.0;
public:
    void loyaltypoints() {
    cout << "Enter the name of the customer: ";
    cin.ignore();
    getline(cin, namecustomer);

    ifstream frequentcustomer("Customer.txt");
    if (!frequentcustomer.is_open()) {
        cerr << "Error: Unable to open Customer.txt" << endl;
        return;
    }
    namecustomer = removeSpaces(namecustomer);
    string line;
    bool customerFound = false;
    string name, contact, id, preference;
    while (getline(frequentcustomer, line)) {
        istringstream iss(line);
        getline(iss, name, ',');
        getline(iss, contact, ',');
        getline(iss, id, ',');
        getline(iss, preference, '.');
        name = removeSpaces(name);

      
        if (namecustomer == name) {
            customerFound = true;
            ifstream ordercustomer("Order.txt");
            if (!ordercustomer.is_open()) {
                cout << "Error: Unable to open Order.txt" << endl;
                return;
            }

             
            while (getline(ordercustomer, line)) {
                istringstream obj(line);
                string num1, name1, price1;
                getline(obj, num1, ',');
                getline(obj, name1, ',');
                getline(obj, price1, ',');

                try {
                    float price = stof(price1);
                    total += price;
                }
                catch (invalid_argument&) {
                    cout << "Invalid price format: " << price1 << endl;
                }
                catch (out_of_range&) {
                    cout << "Price out of range: " << price1 << endl;
                }
            }

            ordercustomer.close();
            cout << "Total price before discount: $" << total << endl;

            if (total >= 50) {
                float discountprice = total * 0.90; 
                cout << "    *************************" << endl;
                cout << "Yahoooo!  Congratulations! You qualify for a 10% discount." << endl;
                cout << "Total after discount: $" << discountprice << endl;
                cout << "    *************************" << endl;
			total=discountprice;
                ofstream loyaltypoint("Updatecustomer.txt", ios::app);
                if (loyaltypoint.is_open()) {
                    static int loyalty = 0; 
                    loyaltypoint << name << "," << contact << "," << id << "," << preference << "," << ++loyalty << endl;
                    cout << "Loyalty points updated for " << namecustomer << endl;
                    cout << "Loyalty points: " << loyalty << endl;
                
                }
                else {
                    cout << "Error: Unable to open Updatecustomer.txt" << endl;
                }
            } 
            else {
                cout << "  *************************" << endl;
                cout << "Total is less than $50. No discount applied." << endl;
                cout << "  *************************" << endl;
            }

            break; 
        }
    }

    frequentcustomer.close();

    if (!customerFound) {
        cout << "Customer not found in the database." << endl;
    }
  		ofstream file_tracksale("Tracksale.txt",ios::app);
  		
                    if(file_tracksale.is_open())
                    {
                    	int totalsales;
						cout<<"Enter 1 to end sales for the day: ";
						cin>>totalsales;
						if(totalsales==1)
						{
		   				cout<<"Total sales price of the day: "<<total<<endl;
                    	static int order=0;
                    	order+=1;
                    	file_tracksale<<order<<": "<<total<<"."<<endl;
                    	ofstream orderfile("Order.txt",ofstream::trunc);
                    	}
                    	else
                    	{
                    		return;
						}
	}

}
            
   void checksalesdaily()
    {
    ifstream tracksale("Tracksale.txt");
    ofstream monthlysale("Monthlysale.txt",ios::app);
    if(!monthlysale.is_open())
    {
    	cout<<"Error in opening the file."<<endl;
	}
    float totalsale = 0.0;
	static int day=1;
    if (tracksale.is_open()) {
        string line, order, total;
        while (getline(tracksale, line)) {
            istringstream iss(line);
            getline(iss, order, ':');
            getline(iss, total, '.');  
            try {
                totalsale += stof(total);  
            } 
			catch (exception& e) {
                cout << "Error parsing total from line: " << line << endl;
            }
            
        }
        tracksale.close();
        cout << "Total sales of the month: $" << totalsale << endl;
        if(monthlysale.is_open())
        monthlysale<<day<<","<<totalsale<<","<<endl;
        monthlysale.close();
    }
	 else {
        cout << "Error opening Tracksale.txt" << endl;
        return;
    }
}
	
	void checksalesmonthly()
	{
    int count;
    cout<<"Enter 1 to check sales for the month: ";
    cin>>count;
    if(count==1)
    {
    	int daycount,salecount,days=0,sales=0;
    	ifstream sale("Monthlysale.txt");
    	string line,day,totalsale;
    	while(getline(sale,line))
    	{
    		istringstream iss(line);
    		getline(iss,day,',');
    		getline(iss,totalsale,',');
    		daycount=stoi(day);
    		days+=daycount;
    		salecount=stoi(totalsale);
    		sales+=salecount;
		}
		if(days<30)
		{
			cout<<"Days not completed yet. Days are: "<<days<<endl;
			cout<<"Sales of the remaining days:	$ "<<sales<<endl;
			days++;
		}
		else if(days==30)
		{
			cout<<"Sales for the month is: "<<sales<<endl;
			days=1;
			ofstream clearfile("Monthlysale.txt",ios::trunc);
			clearfile.close();
		}
	}
	
}

};  
 	               
int main()
{
	system("Color 03");
	int startagain;
	int count=0;
	int preference;
	string username,password;
	menu m1;
	do{
		system("cls");
	cout<<"           **************RIVERSIDE CAMPUS CAFETRIA********************"<<endl<<endl;
	char enter;
	cout<<" -----------------------------------------------------------------------------"<<endl;
	cout<<"Are you working as manager or as staff member?"<<endl;
	cout<<"Choose 'm' or 'M' for manager(Alice), 'c' or 'C' for customer and 'e' or 'E' to exit':"<<endl;
	cin>>enter;
	cout<<" ------------------------------------------------------------------------------"<<endl;
	char choose;
	
	//FOR CHECKING USERNAME AND PASSWORD
	if((enter=='m')||(enter=='M'))
	{
			cout<<"Enter your username for verification: ";
			cin>>username;
			cout<<"Enter your password: ";
			cin>>password;
		while(username!="moubeen123" || password!="moubeenakram")
		{
			cout<<"Incorrect password or username. :("<<endl;
			cout<<"Enter your username for verification: ";
			cin>>username;
			cout<<"Enter your password: ";
			cin>>password;		
		}
		system("cls");
		cout<<"Correct password and username. :) "<<endl;
		cout<<"Let's start :)"<<endl<<endl;
		cout<<"----------------------------------------------------"<<endl<<endl;
		//FOR MANAGER FOR SETTING NEW ITEMS, ADD\MODIFY MORE ITEMS, AND DISPLAYING THEM.
		cout<<"Enter a for setting new items, d for displaying the menu and s for modifying/displaying it.";
		cin>>choose;
		cout<<"----------------------------------------------------"<<endl<<endl;
		if(choose=='a')
		{
			system("cls");//TO CLEAR SCREEN
			m1.additem();	
		}
		else if(choose=='d')
		{
			system("cls");
			m1.displayingallmenu();	
		}
		else if(choose=='s')
		{
			system("cls");
			m1.modify();
			m1.displayingallmenu();
		}
		int c;
		cout<<"            -----------------------------------------------------------"<<endl;
		cout<<"Enter 1 to adjust prices, 2 to adjust availability of item and 3 for tracking the sales: ";
		cin>>c;
		cout<<"            ------------------------------------------------------------"<<endl;
		if(c==1)
		{
			m1.adjustprices();
		}
		else if(c==2)
		{
			m1.updateavailability();
		}
		else if(c==3)
		{
			order o1;
			int checking;
			cout<<"Enter 1 to check daily sales($) and 2 to check monthly sales($): ";
			cin>>checking;
			if(checking==1)
			{
			o1.checksalesdaily();
			}
			else if(checking==2)
			{
			o1.checksalesmonthly();
			}
			else{
				cout<<"Not valid input."<<endl;
			}
		}
    }
   
	
else if ((enter=='c') || (enter=='C')) 
{
	 
    int newcustomer;
    customer c1;
    order o1;
	cout<<"-----------------------------"<<endl<<endl;
	cout<<"We welcome you as a customer! Best of luck with our cafe.:)"<<endl<<endl;
	cout<<"-----------------------------"<<endl;
    cout << "Enter 1 if you are new customer: ";
    cin >> newcustomer;

		
    if (newcustomer== 1) 
	{
		cout<<"*************************"<<endl;
        c1.customerdetail();
        cout<<"*************************"<<endl;
    } 
	else 
	{
        string namecustomer;
        ifstream customercompare("Customer.txt");
		cout<<"*************************"<<endl;
        if (!customercompare.is_open()) {
            cout << "Error: Unable to open Customer.txt" << endl;
            
        }

        cout << "Enter your name: ";
        cin.ignore();
        getline(cin,namecustomer);

        string line, n, c, p, i;
        bool customerFound = false;
		namecustomer=removeSpaces(namecustomer);
        while (getline(customercompare, line)) {
            istringstream iss(line);
            getline(iss, n, ',');
            getline(iss, c, ',');
            getline(iss, i, ',');
            getline(iss, p, '.');
			n=removeSpaces(n);
            if (namecustomer==n) {
                cout << "Customer Details:\n";
                cout << "Name: " << n << "\nContact: " << c << "\nID: " << i << "\nPreference: " << p << endl;
                
                customerFound = true;
                break;
            }
            
        }
			if (!customerFound) {
            cout << "Customer not found in the database." << endl;
        }
       

        customercompare.close();
    }

    int search, orderplacement;
    cout<<"*****************************"<<endl;
    cout << "Enter 1 to place an order: ";
    cin >> search;
    cout<<"*****************************"<<endl;

    if (search == 1) {
       
            c1.search(); // Search function for placing orders
        o1.loyaltypoints(); // Update loyalty points
        cout<<"*************************"<<endl;
    } 
	
	else
	{
		cout<<"Invalid entered. "<<endl;
	}
}
else if((enter=='e')||(enter=='E'))
{
	system("cls");
	cout<<"*********************************"<<endl;
	cout<<"Thank you for visiting. Good bye!"<<endl;
	cout<<"*********************************"<<endl;
}
	cout<<"Enter 1 to again start the program: ";
	cin>>startagain;
}while(startagain==1);
	return 0;
}