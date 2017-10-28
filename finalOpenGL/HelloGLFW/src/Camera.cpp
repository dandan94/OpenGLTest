#include "Camera.h"

static const float MaxVerticalAngle = 85.0f; //must be less than 90 to avoid gimbal lock

Camera::Camera()
{
    //ctor
}

Camera::~Camera()
{
    //dtor
}



const glm::vec3& Camera::getPosition() const
{
    return this->position;
}

void Camera::setPosition(const glm::vec3& position)
{
    this->position = position;
}

void Camera::offsetPosition(const glm::vec3& offset)
{
    this->position += offset;
}


float Camera::getFieldOfView() const
{
    return this->fieldOfView;
}

void Camera::setFieldOfView(float fieldOfView)
{
    this->fieldOfView = fieldOfView;
}


float Camera::getNearPlane() const
{
    return this->nearPlane;
}

float Camera::getFarPlane() const
{
    return this->farPlane;
}

void Camera::setNearAndFarPlanes(float nearPlane, float farPlane)
{
    assert(nearPlane > 0.0f);
    assert(farPlane > nearPlane);
    this->nearPlane = nearPlane;
    this->farPlane = farPlane;
}

glm::mat4 Camera::getOrientation() const {
    glm::mat4 orientation;
    orientation = glm::rotate(orientation, glm::radians(this->verticalAngle), glm::vec3(1,0,0));
    orientation = glm::rotate(orientation, glm::radians(this->horizontalAngle), glm::vec3(0,1,0));
    return orientation;
}

void Camera::offsetOrientation(float upAngle, float rightAngle) {
    this->horizontalAngle += rightAngle;
    this->verticalAngle += upAngle;
    normalizeAngles();
}

void Camera::lookAt(glm::vec3 position) {
    assert(position != this->position);
    glm::vec3 direction = glm::normalize(position - this->position);
    this->verticalAngle = glm::radians(asinf(-direction.y));
    this->horizontalAngle = -glm::radians(atan2f(-direction.x, -direction.z));
    normalizeAngles();
}

float Camera::getViewportAspectRatio() const {
    return this->viewportAspectRatio;
}

void Camera::setViewportAspectRatio(float viewportAspectRatio) {
    assert(viewportAspectRatio > 0.0);
    this->viewportAspectRatio = viewportAspectRatio;
}


glm::vec3 Camera::getForward() const {
    glm::vec4 forward = glm::inverse(getOrientation()) * glm::vec4(0,0,-1,1);
    return glm::vec3(forward);
}

glm::vec3 Camera::getRight() const {
    glm::vec4 right = glm::inverse(getOrientation()) * glm::vec4(1,0,0,1);
    return glm::vec3(right);
}

glm::vec3 Camera::getUp() const {
    glm::vec4 up = glm::inverse(getOrientation()) * glm::vec4(0,1,0,1);
    return glm::vec3(up);
}

glm::mat4 Camera::getMatrix() const {
    return getProjection() * getView();
}

glm::mat4 Camera::getProjection() const {
    return glm::perspective(glm::radians(this->fieldOfView), this->viewportAspectRatio, this->nearPlane, this->farPlane);
}

glm::mat4 Camera::getView() const {
    return getOrientation() * glm::translate(glm::mat4(), -this->position);
}

void Camera::normalizeAngles() {
    this->horizontalAngle = fmodf(this->horizontalAngle, 360.0f);
    //fmodf can return negative values, but this will make them all positive
    if(this->horizontalAngle < 0.0f)
        this->horizontalAngle += 360.0f;

    if(this->verticalAngle > MaxVerticalAngle)
        this->verticalAngle = MaxVerticalAngle;
    else if(this->verticalAngle < -MaxVerticalAngle)
        this->verticalAngle = -MaxVerticalAngle;
}
