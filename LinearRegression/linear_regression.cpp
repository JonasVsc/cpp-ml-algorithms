#include <iostream>
#include <sstream>
#include <vector>
#include <map>
/*

y = slope * x + b

*/

class Model 
{
public:
	Model() 
	{
		std::cout << "Creating Model..." << '\n';
	}

	void showData()
	{

		std::cout << "Input  [ ";
		for (size_t i = 0; i < mData.first.size(); i++)
		{
			std::cout << mData.first[i] << ' ';
		}
		std::cout << "]\n";

		std::cout << "Output [ ";
		for (size_t i = 0; i < mData.first.size(); i++)
		{
			std::cout << mData.second[i] << ' ';
		}
		std::cout << "]\n";
	}

	void populate(std::vector<double> input, std::vector<double> output)
	{
		mData.first.resize(input.size());
		mData.second.resize(input.size());

		for (size_t i = 0; i < input.size(); i++)
		{
			mData.first = input;
			mData.second = output;
		}
	}

	void linearRegression()
	{

		// Reta: y = A + Bx

		double n = mData.first.size();

		std::vector<double> x = mData.first; // input
		std::vector<double> y = mData.second;

		// x times y vector 
		std::vector<double> x_y;
		for (size_t i = 0; i < n; i++)
		{
			x_y.push_back(x[i] * y[i]);
		}

		// x^2
		std::vector<double> x_2;
		for (size_t i = 0; i < n; i++)
		{
			x_2.push_back(x[i] * x[i]);
		}

		double B = (n * summation(x_y) - summation(x) * summation(y)) / (n * summation(x_2) - summation(x) * summation(x));
		
		double A = (summation(y) - B * summation(x)) / n;

		std::ostringstream equation;
		equation.precision(2);

		equation << std::fixed << "y  = " << B << "(x)" << " + " << A;

		std::cout << equation.str() << '\n';
	}


private:
	std::pair<std::vector<double>, std::vector<double>> mData;

	std::string mLineEquation;


	double summation(std::vector<double> x)
	{
		double sum{};
		for (size_t i = 0; i < x.size(); i++)
			sum += x[i];
		return sum;
	}

};


int main()
{
	try
	{
		Model my_model;
	
		my_model.populate({ 2, 4, 6, 8 },
						  { 4, 8, 12, 16 });

		my_model.showData();

		my_model.linearRegression();
	}
	catch (std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	return 0;
}