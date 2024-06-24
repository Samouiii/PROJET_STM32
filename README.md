# Projet Station météo à base de STM32

## Présentation du projet

<p align="center">
  <img src="https://github.com/Samouiii/PROJET_STM32/assets/101981670/f26c02bd-edad-4e14-9964-55df453a3e4b" alt="Première Image" width="200"/>
  <img src="https://github.com/Samouiii/PROJET_STM32/assets/101981670/20155448-0489-49f8-b698-f361707627b3" alt="Deuxième Image" width="200"/>
  <img src="https://github.com/Samouiii/PROJET_STM32/assets/101981670/e22ac42b-58a9-490c-a0cc-decef9a4a34b" alt="Troisième Image" width="200"/>
</p>

Ce projet consiste à développer une station météo basée sur un microcontrôleur STM32. L'objectif est de mesurer différentes variables environnementales telles que la température et l'humidité, en utilisant divers périphériques et capteurs. Le projet intègre plusieurs fonctionnalités, dont certaines utilisent des interruptions et des timers pour améliorer l'efficacité du système.

## Présensation des fonctionnalités

Ci-dessous se trouve un schéma de la carte présentant la disposition des composants de l'interface homme-machine. Leur fonctionnement sera détaillé plus bas.

![Carte_STM_ISEN](https://github.com/Samouiii/PROJET_STM32/assets/101981670/5640c53b-9e70-430d-add1-0129be8e545c)

### Affichage de la température

La température mesurée par le capteur HTS221 est affichée sur l'écran SPI à l'appuis du bouton BTN1.

### Affichage de l'humidité

L'humidité mesurée par le capteur HTS221 est affichée sur l'écran SPI à l'appuis du bouton BTN2.

### Configuration des alarmes

La configuration de l'alarme s'effectue par l'appui du bouton BTN3 pour configurer la température à ne pas dépasser, et par l'appui du bouton BTN4 pour configurer l'humidité à ne pas dépasser. Après l'appui sur le bouton souhaité, le potentiomètre PV1 est utilisé pour sélectionner la valeur d'alarme, comprise entre 0 et 40.

### Buzzer et LEDs d'alarme

Lors d'un événement d'alarme, le buzzer émet un son à une fréquence de 1 kHz. Les LEDs L4 à L7 clignotent en cas d'alarme de température, et les LEDs L0 à L3 clignotent en cas d'alarme d'humidité. Un appui sur les boutons BP3 ou BP4, selon le type d'alarme, sert à arrêter l'alarme actuelle.
