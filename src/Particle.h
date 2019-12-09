/*
 * Particle.h
 *
 *  Created on: 9 Dec 2019
 *      Author: PC
 */

#ifndef PARTICLE_H_
#define PARTICLE_H_

namespace cop {

struct Particle {

	double m_x;
	double m_y;
private:
	double m_speed;
	double m_direction;

public:
	Particle();
	virtual ~Particle();
	void update(int interval);
private:
	void init();
};

} /* namespace cop */

#endif /* PARTICLE_H_ */
