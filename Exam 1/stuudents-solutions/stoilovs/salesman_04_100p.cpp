#include <iostream>
#include <stack>
#include <cmath>
#include <vector>
#include <iostream>    
#include <iomanip>
#include <algorithm>


std::vector<std::pair<std::pair<double, double>, long long>> products;
std::vector<std::pair<double, double>> productsInOrder;

bool compareFunc(std::pair<std::pair<double, double>, long long>& l, std::pair<std::pair<double, double>, long long>& r)
{
	return l.first.second > r.first.second;
}


int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	double m;
	long long n;
	std::cin >> m >> n;
	double weight;
	double value;
	for (long long i = 0; i < n; i++)
	{
		std::cin >> weight >> value;
		std::pair<double, double> prod;
		std::pair<std::pair<double, double>, int> finalProd;
		prod.first = weight;
		prod.second = value;
		finalProd.first = prod;
		finalProd.second = i;
		products.push_back(finalProd);
		productsInOrder.push_back(prod);
	}
	std::vector<double> answers(n, 0);

	std::sort(products.begin(), products.end(), compareFunc);

	double answ = 0;
	for (long long i = 0; i < n; i++)
	{
		if (m > products[i].first.first)
		{
			answ += products[i].first.first * products[i].first.second;
			m -= products[i].first.first;
			answers[products[i].second] = products[i].first.first;
		}
		else
		{
			answ += m * products[i].first.second;
			answers[products[i].second] = m;
			break;
		}
	}

	std::cout << std::fixed << std::setprecision(2) << answ << std::endl;
	for (long long i = 0; i < n; i++)
	{
		std::cout << std::fixed << std::setprecision(3) << answers[i] << std::endl;
	}
	return 0;
}