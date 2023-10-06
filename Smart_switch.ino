#include <ESP8266WiFi.h>

const char *ssid = "Sri Dialog 4G";
const char *password = "E76DFED1";

int R1 = D1;
int R2 = D2;
int R3 = D3;
int R4 = D4;
WiFiServer server(8080);

void setup()
{
    Serial.begin(115200);
    delay(10);

    pinMode(R1, OUTPUT);
    pinMode(R2, OUTPUT);
    pinMode(R3, OUTPUT);
    pinMode(R4, OUTPUT);

    digitalWrite(R1, LOW);
    digitalWrite(R2, LOW);
    digitalWrite(R3, LOW);
    digitalWrite(R4, LOW);

    Serial.println();
    Serial.println();
    Serial.print("Connecting to ");
    Serial.println(ssid);

    WiFi.begin(ssid, password);

    while (WiFi.status() != WL_CONNECTED)
    {
        delay(500);
        Serial.print(".");
    }
    Serial.println("");
    Serial.println("WiFi connected");

    server.begin();
    Serial.println("Server started");

    Serial.print("Use this URL to connect: ");
    Serial.print("http://");
    Serial.print(WiFi.localIP());
    Serial.println("/");
}

void loop()
{
    WiFiClient client = server.available();
    if (!client)
    {
        return;
    }

    Serial.println("new client");
    while (!client.available())
    {
        delay(1);
    }

    String request = client.readStringUntil('\r');
    Serial.println(request);
    client.flush();

    if (request.indexOf("/Relay1On") != -1)
    {
        digitalWrite(R1, HIGH);

        client.println("HTTP/1.1 200 OK");
        client.println("Content-Type: text/html");
        client.println("");
        client.println("<!DOCTYPE HTML>");
        client.println("<html>");
        client.println("Relay 1 is ON");
        client.println("</html>");
        client.stop();
        delay(1);
    }
    if (request.indexOf("/Relay1Off") != -1)
    {
        digitalWrite(R1, LOW);

        client.println("HTTP/1.1 200 OK");
        client.println("Content-Type: text/html");
        client.println("");
        client.println("<!DOCTYPE HTML>");
        client.println("<html>");
        client.println("Relay 1 is OFF");
        client.println("</html>");
        client.stop();
        delay(1);
    }

    if (request.indexOf("/Relay2On") != -1)
    {
        digitalWrite(R2, HIGH);

        client.println("HTTP/1.1 200 OK");
        client.println("Content-Type: text/html");
        client.println("");
        client.println("<!DOCTYPE HTML>");
        client.println("<html>");
        client.println("Relay 2 is ON");
        client.println("</html>");
        client.stop();
        delay(1);
    }
    if (request.indexOf("/Relay2Off") != -1)
    {
        digitalWrite(R2, LOW);

        client.println("HTTP/1.1 200 OK");
        client.println("Content-Type: text/html");
        client.println("");
        client.println("<!DOCTYPE HTML>");
        client.println("<html>");
        client.println("Relay 2 is OFF");
        client.println("</html>");
        client.stop();
        delay(1);
    }

    if (request.indexOf("/Relay3On") != -1)
    {
        digitalWrite(R3, HIGH);

        client.println("HTTP/1.1 200 OK");
        client.println("Content-Type: text/html");
        client.println("");
        client.println("<!DOCTYPE HTML>");
        client.println("<html>");
        client.println("Relay 3 is ON");
        client.println("</html>");
        client.stop();
        delay(1);
    }
    if (request.indexOf("/Relay3Off") != -1)
    {
        digitalWrite(R3, LOW);

        client.println("HTTP/1.1 200 OK");
        client.println("Content-Type: text/html");
        client.println("");
        client.println("<!DOCTYPE HTML>");
        client.println("<html>");
        client.println("Relay 3 is OFF");
        client.println("</html>");
        client.stop();
        delay(1);
    }

    if (request.indexOf("/Relay4On") != -1)
    {
        digitalWrite(R4, HIGH);

        client.println("HTTP/1.1 200 OK");
        client.println("Content-Type: text/html");
        client.println("");
        client.println("<!DOCTYPE HTML>");
        client.println("<html>");
        client.println("Relay 4 is ON");
        client.println("</html>");
        client.stop();
        delay(1);
    }
    if (request.indexOf("/Relay4Off") != -1)
    {
        digitalWrite(R4, LOW);

        client.println("HTTP/1.1 200 OK");
        client.println("Content-Type: text/html");
        client.println("");
        client.println("<!DOCTYPE HTML>");
        client.println("<html>");
        client.println("Relay 4 is OFF");
        client.println("</html>");
        client.stop();
        delay(1);
    }
}