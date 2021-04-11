typedef struct {
	int big;
	int medium;
	int small;
} ParkingSystem;


ParkingSystem* parkingSystemCreate(int big, int medium, int small) {
	ParkingSystem *p = (ParkingSystem*)malloc(sizeof(ParkingSystem));
	p->big = big;
	p->medium = medium;
	p->small = small;
	return p;
}

bool parkingSystemAddCar(ParkingSystem* obj, int carType) {
	switch (carType)
	{
	case 1:
		if (obj->big == 0)
			return false;
		else
			obj->big--;
		break;
	case 2:
		if (obj->medium == 0)
			return false;
		else
			obj->medium--;
		break;
	case 3:
		if (obj->small == 0)
			return false;
		else
			obj->small--;
		break;
	default:
		break;
	}
	return true;
}

void parkingSystemFree(ParkingSystem* obj) {
	free(obj);
}