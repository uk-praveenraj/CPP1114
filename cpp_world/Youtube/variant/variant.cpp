// compile using: g++ -std=c++17 .\variant.cpp -o program -lpthread
#include <iostream> 
#include <variant>
using namespace std; 

int main() 
{ 
    std::variant<int, double> data;
    data = 2.3;
    data = 20;

	//cout << "Data is : " << get<double>(data) << endl; 
    cout << "Data is : " << get<int>(data) << endl; 

    if(auto res = std::get_if<double>(&data)){
        cout << "Data is of type - float: "  << endl; 
    } else{
        cout << "Data is not of type - float"  << endl; 
    }

    try
    {
        std::get<double>(data);
    }
    catch (const std::bad_variant_access& ex)
    {
        std::cout << ex.what() << '\n';
    }
	

	return 0; 
}
