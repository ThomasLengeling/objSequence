//
//  Header.h
//  CinderProject
//
//  Created by tom on 11/19/16.
//
//

#pragma once

#include "cinder/gl/gl.h"

class ObjFrame;
typename std::shared_ptr<ObjFrame> ObjFrameRef;

class ObjFrame{

public:
    ObjFrame();
    
   static ObjFrameRef create(){
       return std::make_shared<ObjFrame>();
    }

private:
};