#include <iostream>
#include "Serializer.hpp"

int main()
{
	Data data;
	data.id = 42;
	data.name = "Alice";

	std::cout << "=== Original ===" << std::endl;
	std::cout << "Address: " << &data << std::endl;
	std::cout << "id:      " << data.id << std::endl;
	std::cout << "name:    " << data.name << std::endl;

	uintptr_t raw = Serializer::serialize(&data);
	std::cout << "\n=== Serialized ===" << std::endl;
	std::cout << "raw: " << raw << std::endl;

	Data *ptr = Serializer::deserialize(raw);
	std::cout << "\n=== Deserialized ===" << std::endl;
	std::cout << "Address: " << ptr << std::endl;
	std::cout << "id:      " << ptr->id << std::endl;
	std::cout << "name:    " << ptr->name << std::endl;

	std::cout << "\n=== Comparison ===" << std::endl;
	if (ptr == &data)
		std::cout << "OK: pointers match" << std::endl;
	else
		std::cout << "KO: pointers differ" << std::endl;

	return 0;
}
