#include "RMRPneumatic.h"

#define RELAY_PORT (1)
#define CUTOFF_PORT (5)
#define SWITCH_PORT (6)

namespace rmr {
	Pneumatic::Pneumatic()
		:m_compressor(CUTOFF_PORT, RELAY_PORT), m_switch(SWITCH_PORT)
	{
		
	}

	Pneumatic::~Pneumatic()
	{

	}

	void Pneumatic::update()
	{
		if (m_switch.Get() && m_compressor.Enabled()) {
			m_compressor.Stop();
		}
		if (!(m_switch.Get() || m_compressor.Enabled())) {
			m_compressor.Start();
		}
	}
}
