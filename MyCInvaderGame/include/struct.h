#ifndef STRUCT_H
#define STRUCT_H

typedef struct{
	double x;
	double y;
}Position;

typedef struct{
	int status;
	double x;
	double y;
}Invader;

typedef struct{
	int flag;
	double begin_x;
	double begin_y;
}Ray_Position;

#endif //STRUCT_H
