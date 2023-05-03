#include "stdafx.h"
#include "bullet.h"

bullet::bullet(){
    x_val_ =0;
    y_val_ =0;
    is_move_ = false;
    bullet_type_ = TYPE_1;
}

bullet::~bullet(){

}

void bullet::loadImgBullet(SDL_Renderer* screen,int bullet_level){
    if(bullet_type_ == TYPE_1){
        std::string type_1_str = "image//type_1" + std::to_string(bullet_level) + ".png";
        loadImg(type_1_str,screen);
    }
    else if(bullet_type_ == TYPE_2){
        std::string type_2_str = "image//type_2" + std::to_string(bullet_level) + ".png";
        loadImg(type_2_str,screen);
    }
    else if(bullet_type_ == TYPE_3){
        std::string type_3_str = "image//type_3" + std::to_string(bullet_level) + ".png";
        loadImg(type_3_str,screen);
    }
}


void bullet::HandleMoveSpaceShipBullet(){
    rect_.y += y_val_;
    if(rect_.y < -rect_.h){
        is_move_ = false;
    }
}


void bullet::HandleMoveThreatBullet(){
    rect_.y += y_val_;
    if(rect_.y > SCREEN_HEIGHT){
        is_move_ = false;
    }
}


void bullet::HandleMoveBossBullet(const int& x_border,const int& y_border){
    rect_.y += y_val_;
    if(rect_.y > y_border){
        is_move_ = false;
    }
}