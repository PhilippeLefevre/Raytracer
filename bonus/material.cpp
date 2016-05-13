#include "material.h"

#include <QDebug>

Material::Material()
{
    this->id = -1;
    this->color = new Color();
    this->reflect = 0.0;
    this->transparency = 0.5;
    this->bump = 0.0;
    this->texture = new QImage();
}

Material::Material(const int id, const Color color, const float reflect, const float transparency, const float ior, const float bump, const int sky, QString path)
{
    this->id = id;
    this->color = new Color(color.r, color.g, color.b);
    this->reflect = reflect / 100.0;


    this->transparency = transparency / 100.0;
    this->ior = ior;
    this->eior = 1.0 / this->ior;

    this->bump = bump;

    this->sky = sky;
    this->texture = new QImage(path);

    qDebug() << this->texture->size().width();
}
