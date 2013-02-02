#ifndef RMRLOADER_H
#define RMRLOADER_H

#include "RMRComponent.h"
#include "SpeedController.h"
#include "Joystick.h"
#include <functional>
#include <memory>

namespace rmr {
	class Loader : public Component {
		public:
			Loader(Joystick *controller);
			Loader(std::function<float()> speedDelegate);
			virtual ~Loader();
			virtual void update();
			void setSpeedDelegate(std::function<float()> speedDelegate) { m_speedDelegate = speedDelegate; };
		protected:
			std::function<float()> m_speedDelegate;
			std::unique_ptr<SpeedController> m_motor;
	};
}

#endif
