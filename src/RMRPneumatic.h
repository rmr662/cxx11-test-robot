#ifndef RMRPNEUMATIC_H
#define RMRPNEUMATIC_H

#include "RMRComponent.h"
#include "Compressor.h"
#include "DigitalInput.h"
#include <functional>

namespace rmr {
	class Pneumatic : public Component {
		public:
			Pneumatic();
			virtual ~Pneumatic();
			virtual void update();
		private:
			Compressor m_compressor;
			DigitalInput m_switch;
	};
}

#endif
