/*
 * RESTFUL.cpp
 *
 *  Created on: 27 Feb 2020
 *      Author: cmpjcrof
 */

#include "RESTFUL.h"
#include <Arduino.h>
#include "WiFi.h"





void RESTFUL::processRequest(String& header) {
	if (header.indexOf("GET /helloworld") != -1) {
		Serial.println("Hello World!");
	}
}

void RESTFUL::handleClient(WiFiClient client) {
	Serial.println(client.remoteIP());
	String header;
	header.reserve(512);
	String currentLine;
	currentLine.reserve(196);

	while (client.connected()) {
		char c = client.read();
		if (c < 255) {
			Serial.print(c);
			header.concat(c);
			if (c == '\n') {
				// end of request - send response
				if (currentLine.length() == 0) {
					processRequest(header);
					sendHeaders(client);
					sendHTML(client);
				} else {
					currentLine = "";
				}
			} else if (c != '\r') {
				currentLine += c;
			}
		} else { // JUNK - Break out!
			break;
		}
	}
}

void RESTFUL::sendHeaders(WiFiClient& client) {
	client.println("HTTP/1.1 200 OK");
	client.println("Content-type: text/html");
	client.println("Connection: close");
	client.println();
	client.println("<!DOCTYPE html>");
}

void RESTFUL::sendHTML(WiFiClient& client) {
	client.println("<html>");
	client.println("<head><title>ESP Web Server</title></html>");
	client.println("<body>");
	client.println("<h1>Welcome to the ESP server!</h1>");
	client.print("<p> hasib is late </p> ");
	client.println("</body>");
	client.println("</html>");
	client.println();
}

void RESTFUL::GET(WiFiClient client, String stringOut) {
	const char* HOST = "team-null.atwebpages.com";
	String id = "&x=";
	String val = stringOut;
	String url = "/serialToServer.php?file=serialOut";

	url.concat(id);
	url.concat(val);




	if (!client.connect(HOST, 80)) {
		Serial.println("connection failed");
		return;
	}

	Serial.print("GET ");
	Serial.print(HOST);
	Serial.println(url);

	client.print("GET ");
	client.print(url);
	client.println(" HTTP/1.1");
	client.print("Host: ");
	client.println(HOST);
	client.println();

	const int TIMEOUT = 10000;

		long timing = millis();
		while (client.available() == 0) {
			// wait for response
			if (millis() - timing > TIMEOUT) {
				Serial.println("Timed out waiting for client");
				client.stop();
				break;
			}
		}

		if(client.connected() == true)
		client.stop();

}

