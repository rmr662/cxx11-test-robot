#ifndef RMRROBOT_H
#define RMRROBOT_H

#include "WPILib.h"
#include "RMRComponent.h"
#include <vector>

class RMRRobot : public IterativeRobot {
	public:
		RMRRobot();
		virtual ~RMRRobot();
		virtual void TeleopPeriodic();
	protected:
		std::vector<rmr::Component*> m_components;
		Joystick m_controller;
};

#endif
