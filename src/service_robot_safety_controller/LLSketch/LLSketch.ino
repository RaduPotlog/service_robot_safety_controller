#include <AlPlc_PMC.h>

/* pmc_1.0.6
*/

struct PLCSharedVarsInput_t
{
};
PLCSharedVarsInput_t& PLCIn = (PLCSharedVarsInput_t&)m_PLCSharedVarsInputBuf;

struct PLCSharedVarsOutput_t
{
};
PLCSharedVarsOutput_t& PLCOut = (PLCSharedVarsOutput_t&)m_PLCSharedVarsOutputBuf;


AlPlc AxelPLC(-435410793);

// shared variables can be accessed with PLCIn.varname and PLCOut.varname

#include <WiFi.h>

char ssid[] = "MikroLAB";    // your network SSID (name)
char pass[] = "@2wsxdr%5";    // your network password (use for WPA, or use as key for WEP)
int keyIndex = 0;             // your network key Index number (needed only for WEP)

int status = WL_IDLE_STATUS;

void setup()
{
	// Configure static IP address
	IPAddress ip(192, 168, 88, 11);
	IPAddress dns(8, 8, 8, 8);
	IPAddress gateway(192, 168, 88, 1);
	IPAddress subnet(255, 255, 255, 0);
	// If cable is not connected this will block the start of PLC with about 60s of timeout!
	Ethernet.begin(ip, dns, gateway, subnet);
	
	status = WiFi.beginAP(ssid,pass);
    
    if(status != WL_AP_LISTENING){
       Serial.println("Creating access point failed");
      // don't continue
      while (true);
    }

    // wait 10 seconds for connection:
    delay(1000);
    // start the web server on port 80
    //server.begin();
    // you're connected now, so print out the status
    //printWiFiStatus();

	AxelPLC.Run();
}

void loop()
{

}
