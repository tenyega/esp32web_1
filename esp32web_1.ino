#include <WiFi.h>
#include <WebServer.h>

const char *ssid = "****";
const char *password = "************";
WebServer server(80);//here the port by default is 80 which is 8080 on which the http is listening. 

void handleRoot()
{
    String page = "<!DOCTYPE html>";
    page += "<head>";
    page += "    <title>Serveur ESP32</title>";
    page += "    <meta http-equiv='refresh' content='60' name='viewport' content='width=device-width, initial-scale=1' charset='UTF-8'/>";
    page += "</head>";

    page += "<body lang='fr'>";
    page += "    <h1>Serveur</h1>";
    page += "    <p>Ce serveur est hébergé sur un ESP32</p>";
    page += "    <i>Créé pour MS2D </i>";
    page += "</body>";

    page += "</html>";

    server.send(200, "text/html", page);
}

void handleDolma()
{
    String page = "<!DOCTYPE html>";
    page += "<head>";
    page += "    <title>Serveur Dolma </title>";
    page += "    <meta http-equiv='refresh' content='60' name='viewport' content='width=device-width, initial-scale=1' charset='UTF-8'/>";
    page += "</head>";

    page += "<body lang='fr'>";
    page += "    <h1>wELCOME </h1>";
    page += "    <p>Ce serveur est hébergé sur un ESP32</p>";
    page += "    <i>Créé pour MS2D </i>";
    page += "</body>";

    page += "</html>";

    server.send(200, "text/html", page);
}
void handleNotFound()
{
    server.send(404, "text/plain", "404: Not found");
}

void setup()
{
    Serial.begin(115200);
    delay(1000);
    Serial.println("\n");

    WiFi.persistent(false);
    WiFi.begin(ssid, password);
    Serial.print("Tentative de connexion...");

    while (WiFi.status() != WL_CONNECTED)
    {
        Serial.print(".");
        delay(100);
    }

    Serial.println("\n");
    Serial.println("Connexion etablie!");
    Serial.print("Adresse IP: ");
    Serial.println(WiFi.localIP());

    server.on("/", handleRoot);
        server.on("/dolma", handleDolma);

    server.onNotFound(handleNotFound);
    server.begin();

    Serial.println("Serveur web actif!");
}

void loop()
{
    server.handleClient();// to handle the client http for each loop. 
}
