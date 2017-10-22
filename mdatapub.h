#include <iostream>
#define SYMBOL_COUNT 6

// symbol structure to store all the symbol specific data
struct symbol
{
	double value;
	int time_stamp;
	int moving_average;
	int count;
};

// MarkeDataPublisher class to help publish price updates abiding the requirements.
template <typename Broadcaster>
class MarketDataPublisher {
private:
	symbol symbol_data[SYMBOL_COUNT];
	Broadcaster priceBroadcaster;
	int maxIntervalSeconds;
	int maxPriceMove;
	int maxSymbolsAtATime;
	int movingAverageSeconds;

	symbol getSymbolData(int symbol_id);
public:
  MarketDataPublisher(Broadcaster& priceBroadcaster,
                      int maxIntervalSeconds,
                      int maxPriceMove,
                      int maxSymbolsAtATime,
                      int movingAverageSeconds = 0);

  // Called by pricing thread
  void updatePrice(int symbol_id, double price, uint64_t secondsSinceEpoch);

  // Called by timer thread, every second
  void onTimer(uint64_t secondsSinceEpoch);

  void printSymbolData(int symbol_id);

};
