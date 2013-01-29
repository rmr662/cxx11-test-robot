#include "RMRInvertableJaguar.h"

namespace rmr {
	InvertableJaguar::InvertableJaguar(int port, bool inverted)
		:Jaguar::Jaguar(port)
	{
		setInverted(inverted);
	}

	InvertableJaguar::~InvertableJaguar()
	{
		// destructor`
	}

	void InvertableJaguar::SetSpeed(float speed) {
		float realSpeed = isInverted()?-speed:speed;
		Jaguar::SetSpeed(realSpeed);
	}
}
