#ifndef CAMERA_H
#define CAMERA_H

#include "glm/glm/glm.hpp"
#include "glm/glm/gtx/transform.hpp"
#include "glm/glm/gtc/type_ptr.hpp"

class Camera
{
    public:
        Camera();
        virtual ~Camera();

        const glm::vec3& getPosition() const;
        void setPosition(const glm::vec3& position);
        void offsetPosition(const glm::vec3& offset);

        float getFieldOfView() const;
        void setFieldOfView(float fieldOfView);

        float getNearPlane() const;
        float getFarPlane() const;
        void setNearAndFarPlanes(float nearPlane, float farPlane);

        glm::mat4 getOrientation() const;
        void offsetOrientation(float upAngle, float rightAngle);

        void lookAt(glm::vec3 position);

        float getViewportAspectRatio() const;
        void setViewportAspectRatio(float viewportAspectRatio);


        glm::vec3 getForward() const;
        glm::vec3 getRight() const;
        glm::vec3 getUp() const;

        glm::mat4 getMatrix() const;
        glm::mat4 getProjection() const;
        glm::mat4 getView() const;

    protected:
    private:
        glm::vec3 position;
        float horizontalAngle;
        float verticalAngle;
        float fieldOfView;
        float nearPlane;
        float farPlane;
        float viewportAspectRatio;

        void normalizeAngles();
};

#endif // CAMERA_H
