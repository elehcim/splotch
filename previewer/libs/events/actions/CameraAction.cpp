#include "CameraAction.h"

namespace previewer
{
	// Declare the static list
	std::list<CameraAction*>* CameraAction::subscriberList = 0;

	// Removes subscriber for the subscriber list (the object is being
	// destroyed)
	CameraAction::~CameraAction()
	{
		// Remove subclass instance from the subscriber list
		subscriberList->remove(dynamic_cast<CameraAction*>(this));
	}

	// Subscribe the camera to the subscriber list
	void CameraAction::CameraActionSubscribe()
	{
		if(!subscriberList)
		{
			subscriberList = new std::list<CameraAction*>();
		}

		// Add the subclass to the subscriber list
		subscriberList->push_back(dynamic_cast<CameraAction*>(this));
	}

	// Unsubscribe the camera from the subscriber list
	void CameraAction::CameraActionUnsubscribe()
	{
		// Remove the subclass from the subscriber list
		subscriberList->remove(dynamic_cast<CameraAction*>(this));
	}

	// Call the subscriber list with a vector
	void CameraAction::CallMoveCameraAction(vec3f newPosition, int type)
	{

		for(std::list<CameraAction*>::iterator it = subscriberList->begin(); it!=subscriberList->end(); ++it)
		{
			// Call the MoveCameraAction implementation of the sub class
			CameraAction* thisAction = dynamic_cast<previewer::CameraAction*>(*it);
			thisAction->ActionMoveCameraPosition(newPosition, type);
		}
	}

	// Call the subscriber list with a vector
	void CameraAction::CallGetCameraPosAction(vec3f& position)
	{

		for(std::list<CameraAction*>::iterator it = subscriberList->begin(); it!=subscriberList->end(); ++it)
		{
			// Call the MoveCameraAction implementation of the sub class
			CameraAction* thisAction = dynamic_cast<previewer::CameraAction*>(*it);
			thisAction->ActionGetCameraPos(position);
		}
	}

		// Call the subscriber list with a vector
	void CameraAction::CallSetCameraLookAtAction(vec3f newLookat)
	{
		for(std::list<CameraAction*>::iterator it = subscriberList->begin(); it!=subscriberList->end(); ++it)
		{
			// Call the MoveCameraAction implementation of the sub class
			CameraAction* thisAction = dynamic_cast<previewer::CameraAction*>(*it);
			thisAction->ActionMoveCameraLookAt(newLookat);
		}
	}

	// Call the subscriber list with a vector
	void CameraAction::CallGetCameraLookAtAction(vec3f& lookat)
	{

		for(std::list<CameraAction*>::iterator it = subscriberList->begin(); it!=subscriberList->end(); ++it)
		{
			// Call the MoveCameraAction implementation of the sub class
			CameraAction* thisAction = dynamic_cast<previewer::CameraAction*>(*it);
			thisAction->ActionGetCameraLookAt(lookat);
		}
	}

	// Call the subscriber list with a vector
	void CameraAction::CallGetCameraUpAction(vec3f& newUpVector)
	{

		for(std::list<CameraAction*>::iterator it = subscriberList->begin(); it!=subscriberList->end(); ++it)
		{
			// Call the MoveCameraAction implementation of the sub class
			CameraAction* thisAction = dynamic_cast<previewer::CameraAction*>(*it);
			thisAction->ActionGetCameraUp(newUpVector);
		}
	}
}