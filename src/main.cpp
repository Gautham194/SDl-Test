//============================================================================
// Name        : SDl.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
#include <iostream>
#include <SDL.h>
#include <math.h>
#include <cstring>
#include <stdlib.h>
#include <time.h>
#include "Screen.h"
#include "Particle.h"
#include "Swarm.h"
using namespace std;
using namespace cop;

int main(int argc, char *argv[]) {

	srand(time(NULL));

	Screen screen;

	if (screen.init() == false) {
		cout << "Error initialising SDL" << endl;
	}

	Swarm swarm;

	while (true) {

		int elapsed = SDL_GetTicks();

		swarm.update(elapsed);

		unsigned char green = (unsigned char) (1 + sin(elapsed * 0.0001)) * 128;
		unsigned char red = (unsigned char) (1 + sin(elapsed * 0.0002)) * 128;
		unsigned char blue = (unsigned char) (1 + sin(elapsed * 0.0003)) * 128;

		const Particle *const pParticles = swarm.getParticles();
		for (int i = 0; i < Swarm::NPARTICLES; i++) {
			Particle particle = pParticles[i];

			int x = (particle.m_x + 1) * 0.5 * Screen::SCREEN_WIDTH;
			int y = (particle.m_y * 0.5 * Screen::SCREEN_WIDTH) + Screen::SCREEN_HEIGHT/2;

			screen.setPixel(x, y, red, green, blue);
		}

		screen.boxBlur();

// Draw screen
		screen.update();
// Check for events
		if (screen.processEvents() == false) {
			break;
		}
	}
		screen.close();

		return 0;
	}
