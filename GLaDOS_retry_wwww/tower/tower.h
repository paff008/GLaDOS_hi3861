#ifndef _TOWER_H
#define _TOWER_H

typedef struct{
    int Tower_x;
    int Tower_y;
}TOWER_CONFIG;

void Tower_init(void);

void tower_control(TOWER_CONFIG tower);

#endif 
