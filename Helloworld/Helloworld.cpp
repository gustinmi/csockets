// Helloworld : Console application project sample.

#include <iostream>

class HelloWorld
{
public:
	HelloWorld() { std::cout << "Hello, world!" << std::endl; }
	~HelloWorld() { std::cout << "Good bye!" << std::endl; }
};

HelloWorld hello;

int main() 
{
	return 0;
}
