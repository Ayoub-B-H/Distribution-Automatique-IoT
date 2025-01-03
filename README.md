# Projet : Serveur Automatisé de Préparation de Boissons

Mise en place d'un serveur automatisé utilisant des équipements réels , permettant de sélectionner une  boisson via un bouton. Le système est contrôlé à distance à l'aide d'un Dashboard sur plateforme IoT  Adafruit IO ,  offrant la possibilité de préparer une boisson sans effort et à distance.

---

## 🚀 Fonctionnalités

- **Interface IoT avec Adafruit IO** :
Un Dashboard en ligne permet de sélectionner une boisson à votre choix.
Chaque boisson est associée à un bouton sur Adafruit IO.

- **Automatisation des pompes** :
Chaque boisson est associée à une pompe contrôlée par un relais. Lorsqu'une boisson est sélectionnée, la pompe correspondante est activée pour une durée prédéfinie (3 secondes).

- **Controle à distance** :
Grâce à la connexion WiFi et à la plateforme Adafruit IO, l'utilisateur peut préparer la boisson depuis n'importe quel endroit connecté à Internet.

---

## 📋 Matériel utilisé
- ESP8266 (NodeMCU).
- Module relais 4 canaux.
- Trois pompes.
- Source d'alimentation.
- Fils de connexion
- Tuyaux pour pompes

---

Voici le Dashboard Adafruit IO utilisé pour le contrôle des boissons :


![Dashboard](https://github.com/Ayoub-B-H/Distribution-Automatique-IoT/blob/main/images/Dashboard.png?raw=true)


Voici les images de réalisation :


![image1](https://github.com/Ayoub-B-H/Distribution-Automatique-IoT/blob/main/images/realisation.jpg?raw=true)



![image2](https://github.com/Ayoub-B-H/Distribution-Automatique-IoT/blob/main/images/realisation2.jpg?raw=true)



![image3](https://github.com/Ayoub-B-H/Distribution-Automatique-IoT/blob/main/images/realisation3.jpg?raw=true)
