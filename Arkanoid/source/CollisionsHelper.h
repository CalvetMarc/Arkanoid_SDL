#ifndef SDLPROJECT_COLLISIONS_HELPER_H
#define SDLPROJECT_COLLISIONS_HELPER_H
#include <SDL.h>
#include "Vector2D.h"
class CollisionsHelper {
public:
    static bool IsPointInsideRect(Vector2D<float> rect, Vector2D<float> point, float rectW,float rectH){
        return point.X < (rect.X + rectW)
        && point.X > rect.X
        && point.Y < (rect.Y + rectH)
        && point.Y > rect.Y;
    }

    //static bool IsRectInsideRect(const SDL_Rect* rect1, const SDL_Rect* rect2){
    static bool IsRectInsideRect(Vector2D<float> rect1, Vector2D<float> rect2, float rectW1, float rectH1, float rectW2, float rectH2){

        /*return rect1->x + rect1->w >= rect2->x
        && rect1->x <= rect2->x + rect2->w
        && rect1->y + rect1->h >= rect2->y
        && rect1->y <= rect2->y + rect2->h;*/
        return rect1.X + rectW1 >= rect2.X
        && rect1.X <= rect2.X + rectW2
        && rect1.Y + rectH1 >= rect2.Y
        && rect1.Y <= rect2.Y + rectH2;
    }
};
#endif //SDLPROJECT_COLLISIONS_HELPER_H
