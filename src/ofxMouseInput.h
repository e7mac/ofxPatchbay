//
//  ofxMouseInput.h
//  mondrian
//
//  Created by Mayank Sanganeria on 2/29/20.
//

#ifndef ofxMouseInput_h
#define ofxMouseInput_h

#include <stdio.h>
#include <glm/glm.hpp>

class ofxMouseInput {
public:
    float getX();
    float getY();
    glm::vec2 getXY();
    bool getPressed(int button);
};


#endif /* ofxMouseInput_h */
