#include "GreenSquare.h"
#include "Registry.h"

GreenSquare::GreenSquare() {
    initPath();
}

void GreenSquare::initPath() {
    path.addRect(0, 0, 10, 10);
}

QRectF GreenSquare::boundingRect() const {
    return this->path.boundingRect();
}

void GreenSquare::paint(QPainter * painter, const QStyleOptionGraphicsItem * option, QWidget * widget = 0 ) {
    painter->setPen(QColor("green"));
    painter->setBrush(QColor("green"));
    painter->drawPath(this->path);
}

Registry<Entity>::Add<GreenSquare> greenSquare("greensquare", "GreenSquare shape entity");