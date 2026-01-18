#pragma once

struct Vector3 {
    Vector3() = default;
    Vector3(float x_, float y_, float z_) : x(x_), y(y_), z(z_) {}

    public: 
        float get_x() const { return x; }
        void set_x(float value) { x = value; }

        float get_y() const { return y; }
        void set_y(float value) { y = value; }

        float get_z() const { return z; }
        void set_z(float value) { z = value; }
    
    private:
        float x = 0.0f;
        float y = 0.0f;
        float z = 0.0f;
};