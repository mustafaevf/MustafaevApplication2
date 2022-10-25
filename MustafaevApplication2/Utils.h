#pragma once
#include <iostream>
#include <string>

template <typename T>
T getNumber(std::string text, T borderMin, T borderMax) {
	T number;
	while (1) {
		std::cout << text;
		std::cin >> number;
		if (std::cin.fail() || number > borderMax || number < borderMin) {
			std::cout << "Попробуйте еще раз" << std::endl;
			std::cin.clear();
			std::cin.ignore(1234, '\n');
		}
		else {
			return number;
		}
	}
}



