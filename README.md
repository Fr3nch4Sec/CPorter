# CPorter

## **Scanner de Ports en C++**

J'ai créé ce petit scanner réseaux pour me pousser à apprender le C++. Car c'est plus intéressant de faire ça, à travers des projets.
Et j'ai de l'intérêt pour la sécurité informatique. Le C++ est un langage dur... lol

### Utilisation :

Mode furtif ("stealth") : Ajoute des délais aléatoires pour rendre le scan plus discret.
Mode bruyant ("noisy") : Affiche chaque port scanné et effectue le scan plus rapidement.

```bash
./CPorter <IP> <startPort> <endPort> <mode>
```

### Exemples :
```bash
./CPorter 192.168.1.1 20 80 stealth

./CPorter 192.168.1.1 20 80 noisy
```
