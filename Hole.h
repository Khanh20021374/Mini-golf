#ifndef _HOLE_H
#define _HOLE_H

#include "Entity.h"
#include "Texture.h"

class Hole : public Entity {
    private:
        Texture* holeTexture;

        bool visible;

    public:
        ~Hole();
        Hole();

        void setVisible(bool isVisible);

        void Update();
        void Render();

        const int HOLE_RADIUS = 8;
};

#endif
