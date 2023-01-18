#pragma once

#include <OgreInput.h>
#include <OgreSceneNode.h>
#include <OgreSceneManager.h>
#include <OgreEntity.h>

#include "EntidadIG.h"

using namespace Ogre;

class Mu�eco : public EntidadIG
{
public:
	Mu�eco(SceneNode* node);
	~Mu�eco() {};

protected:
	SceneNode* mNode;
	SceneManager* mSM;
	bool isMoving = false;
	bool isRed = false;

	SceneNode* mMu�ecoNode = nullptr;
	SceneNode* mMu�ecoHeadNode = nullptr;
	SceneNode* mMu�ecoBodyNode = nullptr;
	//SceneNode* mMu�ecoNoseNode = nullptr;
	SceneNode* mMu�ecoNavelNode = nullptr;
	Entity* ent = nullptr;
	Entity* head = nullptr;
	Entity* body = nullptr;

	AnimationState* animationState = nullptr;
	float duration = 20.0;
	float distance = 600.0;

	virtual bool keyPressed(const OgreBites::KeyboardEvent& evt);
	virtual void frameRendered(const FrameEvent& evt);
	virtual void receiveEvent(MessageType msgType, EntidadIG* entidad);
};

