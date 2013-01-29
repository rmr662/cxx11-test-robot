#ifndef RMRDRIVE_H
#define RMRDRIVE_H

#include "RMRComponent.h"
#include "Joystick.h"
#include "SpeedController.h"
#include "RobotDrive.h"
#include <memory>
#include <functional>

namespace rmr {
	class Drive : public Component {
		public:
			Drive(Joystick *controller, int speedAxis, int turnAxis);
			Drive(std::function<float()> speedDelegate, std::function<float()> turnDelegate);
			virtual ~Drive();
			virtual void update();
			void setJoystickDelegate(Joystick *controller, int speedAxis, int turnAxis);
		protected:
			std::unique_ptr<SpeedController> m_leftController;
			std::unique_ptr<SpeedController> m_rightController;
			RobotDrive *m_robotDrive;
			std::function<float()> m_speedDelegate;
			std::function<float()> m_turnDelegate;
	};
}

#endif
