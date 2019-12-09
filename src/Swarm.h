/*
 * Swarm.h
 *
 *  Created on: 9 Dec 2019
 *      Author: PC
 */

#ifndef SWARM_H_
#define SWARM_H_

#include "Particle.h"

namespace cop {

class Swarm {
public:
	const static int NPARTICLES = 5000;
private:
	Particle *m_pParticles;
	int lastTime;
public:
	Swarm();
	virtual ~Swarm();
	void update(int elapsed);

	const Particle * const getParticles(){return m_pParticles;};
};

} /* namespace cop */

#endif /* SWARM_H_ */
