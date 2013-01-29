#include "RMRRobot.h"
#include "RMRDrive.h"

#define JOYSTICK_PORT (3)

RMRRobot::RMRRobot()
	:m_controller(JOYSTICK_PORT)
{
	rmr::Drive *driveComponent = new rmr::Drive(&m_controller, 2, 4);
	m_components.push_back(driveComponent);
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
