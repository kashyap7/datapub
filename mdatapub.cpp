#include "mdatapub.h"
#include "broadcaster.h"
#include <cmath>

#define PRICE_NOT_UPDATED -1

using namespace std;

template <typename Broadcaster> 
MarketDataPublisher<Broadcaster>:: MarketDataPublisher(Broadcaster& b, int i, int p, int m, int a) : priceBroadcaster{b}
																									 ,maxIntervalSeconds{i}
																									 ,maxPriceMove{p}
																									 ,maxSymbolsAtATime{m}
																									 ,movingAverageSeconds{a}
{
	for (int i = 0; i < SYMBOL_COUNT; i++) 
	{
		symbol_data[i].value = PRICE_NOT_UPDATED;
		symbol_data[i].count = 0;
		symbol_data[i].moving_average = 0;
		symbol_data[i].time_stamp = time(0);
	}
//define the default initialization of other member symbol_data
}

template <typename Broadcaster>
symbol MarketDataPublisher<Broadcaster>::getSymbolData(int symbol_id)
{
	return symbol_data[symbol_id];
}

// check if you need the template following the class-name and also follow the template function syntax if we access the template function ?
template <typename Broadcaster>
void MarketDataPublisher<Broadcaster>::updatePrice(int symbol_id, double price, uint64_t secondsSinceEpoch)
{
	double delta = abs(symbol_data[symbol_id].value - price);
	bool first_update = (symbol_data[symbol_id].value == PRICE_NOT_UPDATED);
	symbol_data[symbol_id].value = price;
	symbol_data[symbol_id].count = symbol_data[symbol_id].count + 1;
	symbol_data[symbol_id].moving_average = symbol_data[symbol_id].moving_average +
		(price - symbol_data[symbol_id].moving_average)/(symbol_data[symbol_id].count);
	if (delta > maxPriceMove || first_update)
	{
		cout<< "In Update"<<endl;
		priceBroadcaster.broadcast(symbol_id, price);
		symbol_data[symbol_id].time_stamp = secondsSinceEpoch;	
	}
}

// check if you need the template following the class-name
template <typename Broadcaster>
void MarketDataPublisher<Broadcaster>::onTimer(uint64_t secondsSinceEpoch){
	int count = 0;
	for (int i = 0; i < SYMBOL_COUNT && count < maxSymbolsAtATime ; i++ )
	{
		if (secondsSinceEpoch - symbol_data[i].time_stamp > maxIntervalSeconds && symbol_data[i].value != PRICE_NOT_UPDATED)
		{
			cout<<"In onTimer"<<endl;
			priceBroadcaster.broadcast(i, symbol_data[i].value);
			count += 1;
		}
	}
}
template class MarketDataPublisher<StubBroadcast>;