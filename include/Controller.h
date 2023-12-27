/*! \mainpage Main Page
 * - **Project name:** AED2G135 - Yet Another AirRoute Navigator (YAARN)
 * - **Short description:** Console-based Air Travel Flight Management System
 * - **Environment:** Unix/Windows console
 * - **Tools:** C++
 * - **Institution:** [FEUP](https://sigarra.up.pt/feup/en/web_page.Inicial)
 * - **Course:** [AED](https://sigarra.up.pt/feup/pt/UCURR_GERAL.FICHA_UC_VIEW?pv_ocorrencia_id=520316) (Algorithms and Data Structures)
 * - **Project grade:** TBD
 * - **Group members:**
 *   - Álvaro Tomas Teixeira Silva Pacheco (up202207733@up.pt)
 *   - André Pinto de Sousa (up202109775@up.pt)
 *   - Rodrigo Dias Ferreira Loureiro de Sousa (up202205751@up.pt)
 *
 */



#ifndef AED2G135_CONTROLLER_H
#define AED2G135_CONTROLLER_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <algorithm>
#include <limits>
#include <queue>
#include "../include/Graph.h"
#include "../include/Airline.h"
#include "../include/Airport.h"
#include "../include/Flight.h"
#include "../include/CSVParser.h"

using namespace std;

class Controller {
private:
    vector<Airport> airports;
    vector<Airline> airlines;
    vector<Flight> flights;
    unordered_map<string, Airport> airportHashTable;
    unordered_map<string, vector<Airport>> cityHashTable;
    unordered_map<string, Airline> airlineHashTable;
    void addAirportToHashTable(const Airport& airport) {
        airportHashTable[airport.getCode()] = airport;
        cityHashTable[airport.getCity()].push_back(airport);
    }
    void addAirlineToHashTable(const Airline& airline) {
        airlineHashTable[airline.getCode()] = airline;
    }
    void BFSWithLayovers(const Airport& source, const Airport& destination, int maxLayovers);
    Graph<Airport> g;
public:
    Controller();
    void displayMenu();
    void numAirports();
    void numAirlines();
    void numFlights();
    void numDepartures(Airport a);
    void numArrivals(Airport a);
    void showDestinations(Airport a);
    void showFlights(Airport a);
    void numAirlineFlights(Airline a);
    void displayCredits();
};


#endif //AED2G135_CONTROLLER_H
