

#ifndef RESTFUL_H_
#define RESTFUL_H_
#include <Arduino.h>
#include "WiFi.h"
class RESTFUL {



private:
	 WiFiClient client;

public:
	void processRequest(String& header);
	void handleClient(WiFiClient client);
	void sendHeaders(WiFiClient& client);
	void sendHTML(WiFiClient& client);
	void GET(WiFiClient client, String stringOut);
};

#endif /* RESTFUL_H_ */
