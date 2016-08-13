#include "data.h"
#include "sorts.h"

	struct PersonT Person[10] = {
		3, 1, "fleshy",
		0, 3, "freckled",
		0, 9, "gaunt",
		3, 5, "long",
		1, 4, "oval",
		7, 0, "pasty",
		8, 8, "pimpled",
		1, 6, "round",
		9, 5, "gaunt",
		4, 7, "broad"
	};

	struct PointT Point[10] = {
		3, 1,
		2, 3,
		5, 6,
		6, 7,
		4, 9,
		2, 8,
		4, 8,
		2, 3,
		0, -1,
		-2, -1
	};

int main () {
	int i;

	printf("QuickSort\n");

	QuickSort(Point, 9, CompareX, sizeof(struct PointT));
	for (i = 0; i < 10; i++)
		printf("%d", Point[i].x); 
		
	printf("\nMergeSort\n");

	MergeSort(Point, 9, CompareY, sizeof(struct PointT));
	for (i = 0; i < 10; i++)
		printf("%d", Point[i].y);

	printf("\nBubbleSort\n");

	BubbleSort(Person, 9, CompareAge, sizeof(struct PersonT));  
	for (i = 0; i < 10; i++)
		printf("%d", Person[i].age); 

	printf("\nEnd\n");
	getch();
};
