#include "Mu�eco.h"

Mu�eco::Mu�eco(SceneNode* node) : EntidadIG(node)
{
	//La constructora pasa el nodo asociado al objeto creado, como par�metro
	mNode = node;

	mSM = mNode->getCreator();

	mMu�ecoNode = mNode->createChildSceneNode();

	mMu�ecoHeadNode = mMu�ecoNode->createChildSceneNode();
	head = mSM->createEntity("sphere.mesh");
	//head->setMaterialName("Practica1/head");
	head->setMaterialName("Practica1/amber");
	mMu�ecoHeadNode->attachObject(head);
	mMu�ecoHeadNode->translate(0, 150, 0);
	mMu�ecoHeadNode->setScale(.6, .6, .6);

	mMu�ecoBodyNode = mMu�ecoNode->createChildSceneNode();
	body = mSM->createEntity("sphere.mesh");
	//body->setMaterialName("Practica1/body");
	body->setMaterialName("Practica1/amber");
	mMu�ecoBodyNode->attachObject(body);

	/*mMu�ecoNoseNode = mMu�ecoHeadNode->createChildSceneNode();
	ent = mSM->createEntity("sphere.mesh");
	ent->setMaterialName("Practica1/orange");
	mMu�ecoNoseNode->attachObject(ent);
	mMu�ecoNoseNode->translate(100, 0, 0);
	mMu�ecoNoseNode->setScale(.1, .1, .1);*/

	mMu�ecoNavelNode = mMu�ecoBodyNode->createChildSceneNode();
	ent = mSM->createEntity("sphere.mesh");
	ent->setMaterialName("Practica1/red");
	mMu�ecoNavelNode->attachObject(ent);
	mMu�ecoNavelNode->translate(100, 0, 0);
	mMu�ecoNavelNode->setScale(.15, .15, .15);

	addListener(this);

	// Animacion desplazamiento
	Animation* animation = mSM->createAnimation("animM", duration);
	NodeAnimationTrack* track = animation->createNodeTrack(0);
	track->setAssociatedNode(mMu�ecoNode);
	Vector3 keyframePos(0.0, 0.0, 0.0); // Posicion del keyframe
	Real durPaso = duration / 5.0; // 6 keyframes

	TransformKeyFrame* kf;

	// Keyframe 0: origen
	kf = track->createNodeKeyFrame(durPaso * 0);
	kf->setTranslate(keyframePos);

	// Keyframe 1: rotacion
	kf = track->createNodeKeyFrame(durPaso * 1);
	Quaternion q1 = Quaternion(Degree(90), Vector3(0.0, -1.0, 0.0));
	kf->setRotation(q1);

	// Keyframe 2: movimiento
	kf = track->createNodeKeyFrame(durPaso * 2);
	keyframePos += Vector3::UNIT_Z * distance;
	kf->setTranslate(keyframePos);
	kf->setRotation(q1);

	// Keyframe 3: rotacion
	kf = track->createNodeKeyFrame(durPaso * 3);
	Quaternion q2 = Quaternion(Degree(180), Vector3(0.0, 1.0, 0.0));
	Quaternion q3 = q2 * q1;
	kf->setTranslate(keyframePos);
	kf->setRotation(q3);

	// Keyframe 4: movimiento
	kf = track->createNodeKeyFrame(durPaso * 4);
	keyframePos += Vector3::NEGATIVE_UNIT_Z * distance;
	kf->setTranslate(keyframePos);
	kf->setRotation(q3);

	// Keyframe 5: rotacion
	kf = track->createNodeKeyFrame(durPaso * 5);
	Quaternion q4 = q3 * q1;
	kf->setRotation(q4);

	animationState = mSM->createAnimationState("animM");
	animationState->setEnabled(true);
	animationState->setLoop(true);
}

bool Mu�eco::keyPressed(const OgreBites::KeyboardEvent& evt) 
{
	if (evt.keysym.sym == SDLK_UP) mMu�ecoNode->translate(10, 0, 0, Node::TS_LOCAL);
	else if (evt.keysym.sym == SDLK_DOWN) mMu�ecoNode->translate(-10, 0, 0, Node::TS_LOCAL);
	else if (evt.keysym.sym == SDLK_LEFT) mMu�ecoNode->yaw(Degree(1));
	else if (evt.keysym.sym == SDLK_RIGHT) mMu�ecoNode->yaw(Degree(-1));

	return true;
}

void Mu�eco::frameRendered(const FrameEvent& evt) 
{
	/*if (isMoving) 
	{
		mMu�ecoHeadNode->yaw(Degree(1));
		mMu�ecoBodyNode->yaw(Degree(-1));
	}*/

	animationState->addTime(evt.timeSinceLastFrame);
}

void Mu�eco::receiveEvent(MessageType msgType, EntidadIG* entidad) 
{
	switch (msgType)
	{
	case msgMu�eco:
		//isMoving = !isMoving;
		isRed = !isRed;

		if(isRed)
		{
			head->setMaterialName("Practica1/redHead");
			body->setMaterialName("Practica1/redBody");
		}
		else 
		{
			head->setMaterialName("Practica1/head");
			body->setMaterialName("Practica1/body");
		}
		break;
	default:
		break;
	}
}