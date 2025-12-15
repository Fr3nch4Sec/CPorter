# CPorter
Scanner de Ports en C++


    Mode furtif ("stealth") : Ajoute des délais aléatoires pour rendre le scan plus discret.
    Mode bruyant ("noisy") : Affiche chaque port scanné et effectue le scan plus rapidement.

Utilisation :

      ./CPorter <IP> <startPort> <endPort> <mode>

Exemples :

      ./CPorter 192.168.1.1 20 80 stealth

      ./CPorter 192.168.1.1 20 80 noisy
