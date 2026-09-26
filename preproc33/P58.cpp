#include <iostream>
#include <fstream>
#include <conio.h>
#include <string>
#include "product.h"
#include "price.h"

int main()
{
	setlocale(LC_ALL, "UA");
	Price* price = new Price();

	while (true) {
		int choice;
		std::cout << "Choose an action:\n"
			<< "1: Init price\n"
			<< "2: Load price\n"
			<< "3: Show price\n"
			<< "4: Show price in 2s\n"
			<< "0: Exit\n";

		choice = _getch();
		switch (choice) {
		case 49:  // '1'
			if (price->init()) {
				std::cout << "Price init success" << std::endl;
			}
			else {
				std::cout << "Price init error" << std::endl;
			}
			break;
		case 50:  // '2'
			if (price->load()) {
				std::cout << "Price load success" << std::endl;
			}
			else {
				std::cout << "Price load error" << std::endl;
			}
			break;
		case 51:  // '3'
			price->show();
			break;
		case 52:  // '4'
			price->show_pag();
			break;
		case 48:  // '0'
			return 0;
		default:
			std::cout << "Invalid choice" << std::endl;
		}
	}
	return 0;
}


/*
[PC]	-- git init -- [git]
Project (P58)
	source     |		     source
	headers    | git add .   headers
	resources  |		     resources
	references x
	x64        x

Відмінність проєкту та репозиторію - репозиторій є частиною проєкту,
до якої входить лише те, що неможно взяти з загальних джерел або
створити компіляцією чи викоанням проєкту.
Ця відмінність задається у файлі ".gitignore"
Репозиторій НЕ заповнюється автоматично, слід зазначити які файли
слід до нього долучити (пожати команду git add)
Commit - "збереження" поточного стану файлів репозиторію, яке
дає можливість пізніше повернутись до цього стану. (git commit -m "message"
або користуємось git changes)
Коміт створюється локально (у прихованій директорії .git)
на Github його ще не існує. Для передачі даних до Github
необхідно "виштовхнути" коміт (push)
*/