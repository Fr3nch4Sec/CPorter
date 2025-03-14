#include <iostream>
#include <vector>
#include <chrono>
#include <thread>
#include <cstdlib>
#include <cstring>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <unistd.h>

using namespace std;

// Codes couleurs ANSI
#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define CYAN    "\033[36m"
#define BOLD    "\033[1m"

// Affichage du logo CPorter
void showLogo() {
    std::cout << CYAN << R"(
   ____  ____            _            
  / ___||  _ \ ___  _ __| |_ ___ _ __ 
  \___ \| |_) / _ \| '__| __/ _ \ '__|
   ___) |  __/ (_) | |  | ||  __/ |   
  |____/|_|   \___/|_|   \__\___|_|   
                                        
    CPorter - C++ Port Scanner
    By [Yoann C/French4Sec]
    )" << RESET << std::endl;
}

// Fonction pour scanner un port spécifique
void scanPort(const string& ip, int port, bool stealth)
{
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) return;

    struct sockaddr_in target;
    memset(&target, 0, sizeof(target));
    target.sin_family = AF_INET;
    target.sin_port = htons(port);
    inet_pton(AF_INET, ip.c_str(), &target.sin_addr);

    if (stealth)
    {
        this_thread::sleep_for(chrono::milliseconds(500 + rand() % 1500));
    }

    int result = connect(sock, (struct sockaddr*)&target, sizeof(target));
    close(sock);

    if (result == 0)
    {
        cout << "Port " << port << " is open\n";
    }
}

void stealthScan(const string& ip, int startPort, int endPort)
{
    for (int port = startPort; port <= endPort; ++port)
    {
        scanPort(ip, port, true);
    }
}

void noisyScan(const string& ip, int startPort, int endPort)
{
    for (int port = startPort; port <= endPort; ++port)
    {
        cout << "Scanning port: " << port << "...\n";
        scanPort(ip, port, false);
    }
}

int main(int argc, char* argv[]) {
    showLogo();  // Afficher le logo au démarrage

    if (argc < 5)
    {
        cerr << "Usage: " << argv[0] << " <IP> <startPort> <endPort> <mode (stealth/noisy)>\n";
        return 1;
    }

    string ip = argv[1];
    int startPort = atoi(argv[2]);
    int endPort = atoi(argv[3]);
    string mode = argv[4];

    if (mode == "stealth")
    {
        stealthScan(ip, startPort, endPort);
    }
    else if (mode == "noisy")
    {
        noisyScan(ip, startPort, endPort);
    }
    else
    {
        cerr << "Invalid mode. Use 'stealth' or 'noisy'.\n";
        return 1;
    }

    std::cout << BOLD << CYAN << "\nScan terminé." << RESET << std::endl;
    return 0;
}
