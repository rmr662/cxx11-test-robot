#ifndef RMRCOMPONENT_H
#define RMRCOMPONENT_H

namespace rmr {
	class Component {
		public:
			Component() {};
			virtual ~Component() {};
			virtual void update() = 0;
	};
}

#endif
