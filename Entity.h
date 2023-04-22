#ifndef _ENTITY_H
#define _ENTITY_H

#include "Math.h"

class Entity {
    private:
        Vector2f position;

        bool active;

        float angle;

    public:
        Entity();
        Entity(Vector2f pos);
		~Entity();

		void setPosition(Vector2f pos);
		Vector2f getPosition();

		void setActive(bool status);
		bool isActive();

		void Translate(Vector2f vec);
		void Rotate(float amount);

		float getAngle();
		void setAngle(float r);

		virtual void Update();
		virtual void Render();
};

#endif
