#include "RMRLoader.h"
#include "RMRInvertableJaguar.h"

namespace rmr {

	Loader::Loader(std::function<float()> speedDelegate)
		:m_motor(new InvertableJaguar(3, false))
	{
		setSpeedDelegate(speedDelegate);
	}

	Loader::Loader(Joystick *controller)
		:m_motor(new InvertableJaguar(3, false))
	{
		setSpeedDelegate( [controller] () {
			float speed = controller->GetRawAxis(3);
			if (speed < 0.0) {
				speed = -speed;
			}
			return speed;
		} );
	}

	Loader::~Loader() {

	}

	void Loader::update()
	{
		m_motor->Set(m_speedDelegate());
	}

}
