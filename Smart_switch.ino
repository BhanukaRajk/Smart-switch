#include <ESP8266WiFi.h>
#include <ArduinoJson.h>


// DEFINE THE MAXIMUM SIZE OF THE JSON BUFFER BASED ON .ENV FILE SIZE
const size_t bufferSize = 128;

// DEFINE THE SSID AND PASSWORD CHAR ARRAYS
char ssid[16];
char password[16];

// SET RELAYS WITH THE DIGITAL PINS
int R1 = D1;
int R2 = D2;
int R3 = D3;
int R4 = D4;

// INITIALIZES A WIFI SERVER OBJECT ON PORT 8080, WHICH WILL LISTEN FOR INCOMING HTTP REQUESTS.
WiFiServer server(8080);


void setup()
{
    Serial.begin(115200);
    delay(10);


    // OPEN THE ENVIRONMENT FILE
    File file = SPIFFS.open("/.env", "r");
    if (!file)
    {
        Serial.println("Failed to open .env file");
        return;
    }

    // PARSE THE ENVIRONMENT FILE AND RETRIEVE SSID AND PASSWORD
    DynamicJsonBuffer jsonBuffer(bufferSize);
    JsonObject &root = jsonBuffer.parseObject(file);
    if (!root.success())
    {
        Serial.println("Failed to parse .env file");
        file.close();
        return;
    }

    // GET SSID AND PASSWORD FROM THE JSON OBJECT
    const char *env_ssid = root["ssid"];
    const char *env_password = root["password"];

    // COPY SSID AND PASSWORD TO THE CHAR ARRAYS
    strncpy(ssid, env_ssid, sizeof(ssid) - 1);
    strncpy(password, env_password, sizeof(password) - 1);

    // CLOSE THE ENVIRONMENT FILE
    file.close();


    // SET RELAY PINS AS OUTPUT
    pinMode(R1, OUTPUT);
    pinMode(R2, OUTPUT);
    pinMode(R3, OUTPUT);
    pinMode(R4, OUTPUT);

    // INITIALLY SET RELAYS TO OFF
    digitalWrite(R1, LOW);
    digitalWrite(R2, LOW);
    digitalWrite(R3, LOW);
    digitalWrite(R4, LOW);

    // CONNECT TO WIFI NETWORK
    Serial.println();
    Serial.println();
    Serial.print("Connecting to ");
    Serial.println(ssid);

    WiFi.begin(ssid, password);

    // WAIT FOR CONNECTION
    while (WiFi.status() != WL_CONNECTED)
    {
        delay(500);
        Serial.print(".");
    }

    // IF CONNECTION IS SUCCESSFUL
    Serial.println("");
    Serial.println("WiFi connected");

    // START THE SERVER ON PORT 8080
    server.begin();
    Serial.println("Server started");

    // PRINT THE IP ADDRESS
    Serial.print("Use this URL to connect: ");
    Serial.print("http://");
    Serial.print(WiFi.localIP());
    Serial.println("/");
}

void loop()
{
    // CHECK IF A CLIENT HAS CONNECTED
    WiFiClient client = server.available();
    if (!client)
    {
        return;
    }

    // WAIT UNTIL THE CLIENT SENDS SOME DATA
    Serial.println("new client");
    while (!client.available())
    {
        delay(1);
    }

    // READ THE FIRST LINE OF THE REQUEST
    String request = client.readStringUntil('\r');
    Serial.println(request);
    client.flush();

    // MATCH THE REQUEST
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