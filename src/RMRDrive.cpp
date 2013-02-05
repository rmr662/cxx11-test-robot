#include "RMRDrive.h"
#include "RMRInvertableJaguar.h"
#include "Jaguar.h"

namespace rmr {
	Drive::Drive(Joystick *controller, int speedAxis, int turnAxis)
		:m_leftController(new InvertableJaguar(1, true)), m_rightController(new InvertableJaguar(2, false))
	{
		m_robotDrive = new RobotDrive(*m_leftController, *m_rightController);
		setJoystickDelegate(controller, speedAxis, turnAxis);
	}

	Drive::Drive(std::function<float()> speedDelegate, std::function<float()> turnDelegate)
		:m_leftController(new Jaguar(1)), m_rightController(new InvertableJaguar(2, true))
	{
		m_robotDrive = new RobotDrive(*m_leftController, *m_rightController);
		m_speedDelegate = speedDelegate;
		m_turnDelegate = turnDelegate;
	}

	Drive::~Drive()
	{
		delete m_robotDrive;
	}

	void Drive::update() {
		m_robotDrive->ArcadeDrive(m_speedDelegate(), m_turnDelegate());
	}

	void Drive::setJoystickDelegate(Joystick *controller, int speedAxis, int turnAxis)
	{
		std::function<float()> speedDelegate = std::bind(&Joystick::GetRawAxis, controller, speedAxis);
		std::function<float()> turnDelegate = std::bind(&Joystick::GetRawAxis, controller, turnAxis);
		m_speedDelegate = speedDelegate;
		m_turnDelegate = turnDelegate;
	}
}
