/*
 * Screen.h
 *
 *  Created on: 22 Nov 2019
 *      Author: PC
 */

#ifndef SCREEN_H_
#define SCREEN_H_

#include <SDL.h>
#include <iostream>
#include <math.h>
#include <cstring>

namespace cop {

class Screen {
public:
	static int const SCREEN_WIDTH = 800;
	static int const SCREEN_HEIGHT = 600;
private:
	SDL_Window *m_window;
	SDL_Renderer *m_renderer;
	SDL_Texture *m_texture;
	Uint32 *m_buffer1;
	Uint32 *m_buffer2;
public:
	Screen();
	bool init();
	void update();
	void setPixel(int x, int y, Uint8 red, Uint8 green, Uint8 blue);
	bool processEvents();
	void close();
	void boxBlur();

};

} /* namespace cop */

#endif /* SCREEN_H_ */
