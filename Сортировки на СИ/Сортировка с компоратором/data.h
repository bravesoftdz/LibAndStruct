typedef
	struct PersonT{
		int age;
		int height;
		char *name;
	};

	struct PointT{
		int x;
		int y;
	};

	int CompareAge(struct PersonT *a, struct PersonT *b);
	int CompareHeight(struct PersonT *a, struct PersonT *b);
	int CompareName(struct PersonT *a, struct PersonT *b);
	int CompareX(struct PointT *a, struct PointT *b);
	int CompareY(struct PointT *a, struct PointT *b);
	int ComparePolarC(struct PointT *a, struct PointT *b);