// shouldn't this get included from the mdatapub.h ??
#include <iostream>
#include <ctime>
#include <unistd.h>
#include "mdatapub.h"
#include "broadcaster.h"
int main()
{
	StubBroadcast bcast;
/*
  MarketDataPublisher(Broadcaster& priceBroadcaster,
                      int maxIntervalSeconds,
                      int maxPriceMove,
                      int maxSymbolsAtATime,
                      int movingAverageSeconds = 0);

*/
	MarketDataPublisher<StubBroadcast> mdatapub(bcast, 0, 10, 2);
	uint64_t k = time(0);
	cout<<"TIMESTAMP before update: "<<k <<endl;
	mdatapub.updatePrice(0, 20, k);
	k = time(0);
	cout<<"TIMESTAMP before update: "<<k <<endl;
	mdatapub.updatePrice(1, 28, k);
	k = time(0);
	cout<<"TIMESTAMP before update: "<<k <<endl;
	mdatapub.updatePrice(2, 86, k);
	k = time(0);
	cout<<"TIMESTAMP before update: "<<k <<endl;
	mdatapub.updatePrice(3, 78, k);
	k = time(0);
	cout<<"TIMESTAMP before update: "<<k <<endl;
	mdatapub.updatePrice(4, 99, k);
	k = time(0);
	cout<<"TIMESTAMP before update: "<<k <<endl;
	mdatapub.updatePrice(5, 3, k);
	k = time(0);
	cout<<"TIMESTAMP before update: "<<k <<endl;
	mdatapub.updatePrice(2, 34, k);
	k = time(0);
	cout<<"TIMESTAMP before update: "<<k <<endl;
	mdatapub.updatePrice(2, 23, k);
	k = time(0);
	cout<<"TIMESTAMP before update: "<<k <<endl;
	mdatapub.updatePrice(2, 9, k);
	k = time(0);
	cout<<"TIMESTAMP before update: "<<k <<endl;
	mdatapub.updatePrice(5, 82, k);
	k = time(0);
	cout<<"TIMESTAMP before update: "<<k <<endl;
	mdatapub.updatePrice(4, 11, k);
	k = time(0);
	cout<<"TIMESTAMP before update: "<<k <<endl;
	mdatapub.updatePrice(2, 44, k);
	k = time(0);
	cout<<"TIMESTAMP before update: "<<k <<endl;
	mdatapub.updatePrice(4, 56, k);
	sleep(2);
	k = time(0);
	cout<<"TIMESTAMP before update: "<<k <<endl;
	mdatapub.onTimer(k);
	//Instantiate the broadcaster 
	//Instantiate the publisher
	//Simulate the updatePrice and onTimer calls

}