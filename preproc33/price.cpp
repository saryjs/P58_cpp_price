#include "price.h"
#include <iostream>
#include <conio.h>

bool Price::init() {
	std::ofstream file(PRICE_FILENAME);
	if (!file.is_open()) {
		std::cout << "File open error";
		return false;
	}
	Product product = { "Black Pencil", 14.95f, 20, 0 };
	product.save_to_file(file);

	product = { "Blue Pen", 19.95f, 25, 5 };
	product.save_to_file(file);

	product = { "Green Whiteboard Marker", 17.50f, 10, 10 };
	product.save_to_file(file);

	product = { "Lined Copybook", 7.50f, 20, 10 };
	product.save_to_file(file);

	product = { "Grided Copybook", 7.50f, 20, 10 };
	product.save_to_file(file);

	product = { "Ruler", 8.50f, 10, 5 };
	product.save_to_file(file);

	file.close();
	return true;
}

bool Price::load() {
	std::ifstream file(PRICE_FILENAME);
	if (!file.is_open()) {
		std::cout << "File open error";
		return false;
	}
	ListNode* last = NULL;
	// видаляємо наявні товари перед зчитуванням файлу
	if (first) {   // якщо вони є
		do {
			last = first->next;
			delete first;
			first = last;
		} while (first);  // while (first != NULL)
	}
	Product product;
	while (product.load_from_file(file)) {
		if (last == NULL) {
			first = last = new ListNode;
			last->product = product;
			last->next = NULL;
		}
		else {
			last->next = new ListNode;
			last->next->product = product;
			last->next->next = NULL;
			last = last->next;
		}
	}
	file.close();
	return true;
}

void Price::show() const {
	if (first == NULL) {
		std::cout << "Price is empty" << std::endl;
		return;
	}
	ListNode* node = first;
	while (node) {
		std::cout << node->product.to_string() << std::endl;
		node = node->next;
	}
}

void Price::show_pag() const {
	if (first == NULL) {
		std::cout << "Price is empty" << std::endl;
		return;
	}
	ListNode* node = first;
	size_t count = 0;
	while (node) {
		if (count % 2 == 0) {
			std::cout << "Press any key to show: " << std::endl;
			size_t key;
			key = _getch();
		}
		std::cout << node->product.to_string() << std::endl;
		node = node->next;
		count += 1;
	}
}