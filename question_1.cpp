#include <iostream>
#include <fstream> // for read ifstream and write ofstream
#include <sstream>
#include <cstring>
#include <iomanip>
using namespace std;

class Tax_calculator {
    string **csv_data;
    int purchased_year, selling_year;
    long purchased_price;
    int no_of_records;

    public:
        Tax_calculator(string &filepath, int selling_year){
            ifstream read_csv(filepath);
            string fetch_line, year, growth_price, inflattion;
            no_of_records = 0;


            while(getline(read_csv, fetch_line))
            {
                no_of_records++ ;
            }

            csv_data = new string*[no_of_records - 1];
            for (int i = 0; i < no_of_records - 1; i++) {
                csv_data[i] = new string[3]; // 3 columns for year, growth_price, inflation
            }
            read_csv.clear();
            read_csv.seekg(0);
            getline(read_csv, fetch_line);

            int index = 0;
            while (getline(read_csv, fetch_line)) {
                string e_line[3];
                stringstream ss(fetch_line);

                getline(ss, year, ',');
                getline(ss, growth_price, ',');
                getline(ss, inflattion, ',');
                
                csv_data[index][0] = year.substr(0, 4);
                csv_data[index][1] = growth_price;
                csv_data[index][2] = inflattion;
                index++;
            }
            purchased_year = 2010;
            purchased_price = 5000000;
            this->selling_year = selling_year;
        }
        
        double selling_price(){
            double sp = purchased_price;
            for (int i = 0; i < no_of_records - 1; i++) {
                if (stoi(csv_data[i][0]) > purchased_year && stoi(csv_data[i][0]) <= selling_year) {                    
                    sp *= (1 + (stod(csv_data[i][1]) - stod(csv_data[i][2]))/100 );
                }
            }
            return sp;
        }


    double lctg_tax() {
        double sp = selling_price();
        double profit = sp - purchased_price;
        double tax = 0.2 * profit;
        
        if (tax <= 0) return 0;
        else return tax;
    }

};

int main() {
    int year;
    string filepath = "price-inflation.csv";
    cout << "In which year you want sell your property:" ;
    cin >> year;

    Tax_calculator tax(filepath, year);
    cout << "Selling Price: " << fixed << tax.selling_price() << endl;
    cout << "Tax: " << fixed << tax.lctg_tax();
    return 0;
}
