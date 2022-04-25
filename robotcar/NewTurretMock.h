#include "NewTurret.h"

class NewTurretMock : public NewTurret {
	public:
		void aimRight() override;
		void aimLeft() override;
		void aimStraight() override;
};
