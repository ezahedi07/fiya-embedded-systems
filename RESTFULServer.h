void sendHeaders(WiFiClient& client) {
	client.println("HTTP/1.1 200 OK");
	client.println("Content-type: text/html");
	client.println("Connection: close");
	client.println();
	client.println("<!DOCTYPE html>");
}

void sendHTML(WiFiClient& client) {
	client.println("<html>");
	client.println("<head><title>ESP Web Server</title></html>");
	client.println("<body>");
	client.println("<h1>Welcome to the ESP server!</h1>");
	client.print("<p> hasib is late </p> ");
	client.println("</body>");
	client.println("</html>");
	client.println();
}
