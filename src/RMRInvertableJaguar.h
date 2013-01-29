#ifndef RMRINVERTABLEJAGUAR_H
#define RMRINVERTABLEJAGUAR_H

#include "Jaguar.h"

namespace rmr {
	class InvertableJaguar : public Jaguar {
		public:
			InvertableJaguar(int port, bool inverted);
			virtual ~InvertableJaguar();
			void setInverted(bool inverted) { mInverted = inverted; };
			float isInverted() { return mInverted; };
			virtual void SetSpeed(float speed);
		private:
			bool mInverted;
	};
}

#endif
