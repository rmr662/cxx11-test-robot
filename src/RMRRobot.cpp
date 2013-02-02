#include "RMRRobot.h"
#include "RMRDrive.h"
#include "RMRLoader.h"
#include <iostream>

#define JOYSTICK_PORT (3)


extern "C" {
void _start() {
	std::cout << "ERROR! _start called!\n";
}
}

RMRRobot::RMRRobot()
	:m_controller(JOYSTICK_PORT)
{
	rmr::Drive *driveComponent = new rmr::Drive(&m_controller, 2, 4);
	rmr::Loader *loaderComponent = new rmr::Loader(&m_controller);
	m_components.push_back(driveComponent);
	m_components.push_back(loaderComponent);
}

RMRRobot::~RMRRobot()
{

}

void RMRRobot::TeleopPeriodic()
{
	for (std::vector<rmr::Component*>::iterator it = m_components.begin(); it != m_components.end(); ++it) {
		(*it)->update();
	}
}

START_ROBOT_CLASS(RMRRobot);
