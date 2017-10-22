#include <iostream>
using namespace std;
class StubBroadcast
{
public:
	void broadcast(int symbol_id, double price)
	{
		cout<< "Consider the price of (" << symbol_id <<") broadcasted as (" << price <<")"<< endl;
	}
};
