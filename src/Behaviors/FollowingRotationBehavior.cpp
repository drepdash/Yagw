#include "Behaviors/FollowingRotationBehavior.h"
#include "Behaviors/BasicFollowingBehavior.h"
#include "Calculator.h"

void FollowingRotationBehavior::rotate()
{
    if (entity) {
        QVector2D direction = Calculator::calcDirectionVector(entity->pos(), target->pos());
        QVector2D orientation(qCos(angle*PI/180), qSin(angle*PI/180));
        qreal rotation = Calculator::calcAngle(orientation, direction);
        if (qFloor(rotation) < entity->getRotationSpeed())
            return;
        int sign = qCos(rotation*PI/180) >= 0 ? -1 : 1;
        entity->setRotation(sign*entity->getRotationSpeed());
        angle += entity->getRotationSpeed()*sign;
    }

}

void FollowingRotationBehavior::setTarget(Entity *entity) {
    target = entity;
}

void FollowingRotationBehavior::init() {
    if (entity)
        entity->setRotationSpeed(3);
}
