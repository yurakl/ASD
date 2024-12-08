#include <iostream>
#include <iomanip>
#include <memory>

#include <vector>
#include <string>
#include <algorithm>
#include <numeric>


void print_sections()
{
	std::cout << std::left << std::setw(20)
					<< "Name" << "| " << std::setw(20) << "Category" << "| "
					<< std::setw(10) << "Price" << "| "
					<< std::setw(10) << "Rating" << "| "
					<< std::setw(10) << "Quantity" << "\n";
					std::cout << std::string(80, '-') << "\n";
}

class Product {
public:
	std::string name;
	std::string category;
	int price;
	double rating;
	Product() = default;
	Product(std::string n, std::string c, double p, double r) :
		name(std::move(n)), category(std::move(c)), price(p), rating(r) {}

	// Для виведення інформації про продукт
	void display() const {
		
		std::cout << std::left << std::setw(20) << name  << "|   " 
						<< std::setw(20) << category << "|   "
						<< std::setw(10) << price << "|   "
						<< std::setw(10) << rating << "|\n";
	}
};

class ShoppingCart {
	private:
		std::vector<std::pair<std::unique_ptr<Product>, int>> items;
	public:

		void addProduct(std::unique_ptr<Product> product, int quantity)
					{ items.push_back(std::make_pair(std::move(product), quantity)); }

	void displayCart() const
	{
		for (const auto& item : items)
		{
			item.first->display();
			std::cout << std::setw(60) << " " << "| " << std::setw(10) << item.second << "\n";
		}
	}
};

	
void sort_menu(std::vector<Product>& products)
{
	int choise;
	std::cout << "Sort shoping list by:\n" <<
								"\t1) name;\n" << 
								"\t2) category;\n" << 
								"\t3) price;\n" << 
								"\t4) rating;\n" << std::endl;
	std::cin >> choise;
	switch (choise)
	{
		case (1):
			std::sort(products.begin(), products.end(),
							[](const Product& a, const Product& b) {return a.name < b.name;});
			break;
		case (2):
			std::sort(products.begin(), products.end(),
							[](const Product& a, const Product& b) {return a.category < b.category;});
			break;
		case (3):
			std::sort(products.begin(), products.end(),
							[](const Product& a, const Product& b) {return a.price < b.price;});
			break;
		case (4):
			std::sort(products.begin(), products.end(),
							[](const Product& a, const Product& b) {return a.rating < b.rating;});
			break;
		default:
			break;
	}
}



int main()
{
	std::vector<Product> products = {
        {"Laptop", "Electronics", 999, 4.5},
        {"Phone", "Electronics", 699, 4.8},
        {"Headphones", "Accessories", 49, 4.2},
        {"Keyboard", "Accessories", 8, 4.0},
        {"Shoes", "Clothing", 120, 4.1},
        {"T-Shirt", "Clothing", 19, 3.9}
    };
	sort_menu(products);
	print_sections();
	auto print = [](const Product& a) {a.display();};
	std::for_each(products.begin(), products.end(), print);

	
	//~ int nelec = count_if(products.begin(), products.end(),
							//~ [](const Product& a){return a.category == "Electronics";});
	//~ std::cout << "N Electronics: " << nelec << std::endl;

	//~ std::vector<Product> ve;
	//~ ve.resize(nelec);
	//~ std::copy_if(products.begin(), products.end(), std::back_inserter(ve),
							//~ [](const Product& a){return a.category == "Electronics";});

	//~ auto mr = std::max_element(products.begin(), products.end(), [](const Product& a, const Product& b)
							//~ {return a.rating < b.rating;});
	//~ print(*mr);
	//~ std::cout << "Electronics only:\n";
	//~ std::for_each(ve.begin(), ve.end(), print);

	//~ std::vector <item> item_list;
	//~ item_list.push_back({products[0], 1});
	//~ item_list.push_back({products[1], 3});
	//~ item_list.push_back({products[2], 1});


	//~ for (auto& [key, value] : item_list)
	//~ {
		//~ std::cout << key.price << " " << value << std::endl;
	//~ }

	//~ std::for_each(item_list.begin(), item_list.end(),
					//~ [](item& a){std::cout << a.first.price << std::endl;});
 
		
}
