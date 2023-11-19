#ifndef PLANE_H
#define PLANE_H

#include "hittable.h"
#include "vec3.h"

class plane : public hittable{
    public:
        plane() {};
        plane(point3 ori, vec3 n, double a, double b, double c, shared_ptr<material> m) 
        : origin(ori), norm(n), a(a), b(b), c(c), mat_ptr(m) {};

        virtual bool hit(
            const ray& r, double t_min, double t_max, hit_record& rec) const override;
    
    public:
        point3 origin;
        vec3 norm;
        double a;
        double b;
        double c;
        shared_ptr<material> mat_ptr;
};

bool plane::hit(const ray& r, double t_min, double t_max, hit_record& rec) const {
    vec3 oc = r.origin() - origin;
    double x_min = origin.x() - a;
    double x_max = x_min + 2*a;

    double y_min = origin.y() - b;
    double y_max = y_min + 2*b;

    double z_min = origin.y() - c;
    double z_max = z_min + 2*c;

    if (
        (r.direction().x() < x_min && r.direction().x() > x_max) &&
        (r.direction().y() < y_min && r.direction().y() > y_max) &&
        (r.direction().z() > z_min && r.direction().z() > z_max)) return false;
    
    double t = oc.length() - dot(r.direction(), norm);
    if (t < t_min || t > t_max ) return false;
    
    rec.p = cross(r.direction(), norm);
    rec.normal = norm;
    rec.t = t;
    rec.mat_ptr = mat_ptr;
    rec.set_face_normal(r, norm);

    return true;



    


}

#endif