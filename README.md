# So_long

* [Introduction](#introduction)
* [Notion](#notion-link)
* [The Project](#the-project)

## Skills that I have improved

## Introduction

## The project

### Follow these steps to run the project
* This project only runs on Linux
* run `sudo apt-get update && sudo apt-get install xorg libxext-dev zlib1g-dev libbsd-dev`
* run `make` or `make bonus`
* If you are using WSL2 you must have Xming installed and then:
  * Click Multiple windows and go to the next page
  * Click Start no client and go to the next page
  * Make sure that the No Access Control box is ticked and go to the next page
  * Click Save configuration and then Finish
  * Run `export DISPLAY=$(cat /etc/resolv.conf | grep nameserver | awk '{print $2}'):0.0`
  * Run xeyes and check if a window appears
* Inside the `maps` folder there are maps that can be played
* For instance, run `./so_long ./maps/pdf1.ber`

### How to play it?
- Movement
- W => Move up
- S => Move down
- A => Move left
- D => Move right
