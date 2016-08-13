#include "data.h"

	int CompareAge(struct PersonT *a, struct PersonT *b) {
		return a->age - b->age;
	};

	int CompareHeight(struct PersonT *a, struct PersonT *b) {
		return a->height - b->height;
	};

	int CompareName(struct PersonT *a, struct PersonT *b) {
		return strcmp(a->name, b->name);
	};

	int CompareX(struct PointT *a, struct PointT *b) {
		return a->x - b->x;
	};

	int CompareY(struct PointT *a, struct PointT *b) {
		return a->y - b->y;
	};

	int ComparePolarC(struct PointT *a, struct PointT *b) {
		return pow(a->x, 2) + pow(a->y, 2) - (b->x, 2) - (b->y, 2);
	};