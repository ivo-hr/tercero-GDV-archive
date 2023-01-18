#include "IG2App.h"

#include <OgreEntity.h>
#include <OgreInput.h>
#include <SDL_keycode.h>
#include <OgreMeshManager.h>

using namespace Ogre;

bool IG2App::keyPressed(const OgreBites::KeyboardEvent& evt)
{
	if (evt.keysym.sym == SDLK_ESCAPE)
	{
		getRoot()->queueEndRendering();
	}
	/*else if (evt.keysym.sym == SDLK_g)
	{
		mClockNode->roll(Degree(1));
	}
	else if (evt.keysym.sym == SDLK_h)
	{
		mHoursNode->yaw(Degree(1));
	}*/
	/*else if (evt.keysym.sym == SDLK_p)
	{
		mPlaneNode->yaw(Degree(1));
		noria->moveBlades();
	}*/
	/*else if (evt.keysym.sym == SDLK_h)
	{
		AxisAlignedBox aab = mAvionNode->_getWorldAABB();

		for (int i = 0; i < nDron; i++)
		{
			auto mDronAvispa = mSM->getSceneNode("mDronAvispa" + std::to_string(i));
			AxisAlignedBox aab2 = mDronAvispa->_getWorldAABB();

			if (aab.intersects(aab2))
			{
				mDronAvispa->setVisible(false);

				nDronAlive--;
				if (nDronAlive <= 0)
					dron->changeColor();
			}
		}
	}*/
	/*else if (evt.keysym.sym == SDLK_0) sinbad->arma(true);
	else if (evt.keysym.sym == SDLK_1) sinbad->arma(false);
	else if (evt.keysym.sym == SDLK_2) sinbad->arma();
	else if (evt.keysym.sym == SDLK_3) sinbad->cambiaArma();*/
	/*else if (evt.keysym.sym == SDLK_c) sinbad->changeAnimation();*/
  
  return true;
}

void IG2App::shutdown()
{
  mShaderGenerator->removeSceneManager(mSM);  
  mSM->removeRenderQueueListener(mOverlaySystem);  
					
  mRoot->destroySceneManager(mSM);

  delete mTrayMgr;  mTrayMgr = nullptr;
  delete mCamMgr; mCamMgr = nullptr;
  
  // do not forget to call the base 
  IG2ApplicationContext::shutdown();
}

void IG2App::setup(void)
{
  // do not forget to call the base first
  IG2ApplicationContext::setup();

  mSM = mRoot->createSceneManager();  

  // register our scene with the RTSS
  mShaderGenerator->addSceneManager(mSM);

  mSM->addRenderQueueListener(mOverlaySystem);

  mTrayMgr = new OgreBites::TrayManager("TrayGUISystem", mWindow.render);  
  mTrayMgr->showFrameStats(OgreBites::TL_BOTTOMLEFT);
  addInputListener(mTrayMgr);

  addInputListener(this);   
  setupScene();
}

void IG2App::setupScene(void)
{
  // create the camera
  Camera* cam = mSM->createCamera("Cam");
  cam->setNearClipDistance(1); 
  cam->setFarClipDistance(10000);
  cam->setAutoAspectRatio(true);
  //cam->setPolygonMode(Ogre::PM_WIREFRAME); 

  mCamNode = mSM->getRootSceneNode()->createChildSceneNode("nCam");
  mCamNode->attachObject(cam);

  mCamNode->setPosition(0, 0, 1000);
  mCamNode->lookAt(Ogre::Vector3(0, 0, 0), Ogre::Node::TS_WORLD);
  mCamNode->setDirection(Ogre::Vector3(-1, 0, 0));  
  
  // and tell it to render into the main window
  Viewport* vp = getRenderWindow()->addViewport(cam);

  /// <summary>
  /// Color de fondo de la escena
  /// </summary>
  /// <param name=""></param>
  vp->setBackgroundColour(Ogre::ColourValue(0.6, 0.7, 0.8)); // 0.7 0.8 0.9

  //------------------------------------------------------------------------

  // without light we would just get a black screen 

  Light* luz = mSM->createLight("Luz");
  luz->setType(Ogre::Light::LT_DIRECTIONAL);
  luz->setDiffuseColour(1.0, 1.0, 1.0);
  Light* luz2 = mSM->createLight("spotlight");
  luz2->setType(Ogre::Light::LT_POINT);
  luz2->setDiffuseColour(1.0, 1.0, 1.0);
  mLightNode = mSM->getRootSceneNode()->createChildSceneNode("nLuz");
  //mLightNode = mCamNode->createChildSceneNode("nLuz");
  mLightNode->attachObject(luz);
  
  Ogre::SceneNode* mLightNode2 = mSM->getRootSceneNode()->createChildSceneNode("nLuz2");
  //mLightNode = mCamNode->createChildSceneNode("nLuz");
  mLightNode2->attachObject(luz2);

  mLightNode2->setPosition(0, 500, 0);
  //mLightNode->setDirection(Ogre::Vector3(-1, -1, 0));  //vec3.normalise();
  //lightNode->setPosition(0, 0, 1000);
 
  //------------------------------------------------------------------------

  // finally something to render

  //Ogre::Entity* ent = mSM->createEntity("Sinbad.mesh");
  //Ogre::Entity* scn = mSM->createEntity("RomanBathLower.mesh");
  //Ogre::Entity* scn2 = mSM->createEntity("RomanBathUpper.mesh");
  //Ogre::Entity* scn3 = mSM->createEntity("Columns.mesh");

  //mSinbadNode = mSM->getRootSceneNode()->createChildSceneNode("nSinbad");
  //mSinbadNode->attachObject(ent);

  ///// <summary>
  ///// Creaci�n del escenario
  ///// </summary>
  ///// <param name=""></param>
  //mSceneNode = mSM->getRootSceneNode()->createChildSceneNode("nScene");
  //mSceneNode->attachObject(scn);
  //mSceneNode->attachObject(scn2);
  //mSceneNode->attachObject(scn3);

  ////mSinbadNode->setPosition(400, 100, -300);
  //mSinbadNode->setScale(20, 20, 20);
  //mSceneNode->setScale(1, 1, 1);
  ////mSinbadNode->yaw(Degree(-45));
  ////mSinbadNode->showBoundingBox(true);
  ////mSinbadNode->setVisible(false);

  /// <summary>
  /// Creacion del reloj
  /// </summary>
  /// <param name=""></param>
  /*mClockNode = mSM->getRootSceneNode()->createChildSceneNode("nClock");
  mHoursNode = mClockNode->createChildSceneNode("nHours");

  for (int i = 0; i < 12; i++) 
  {
	  int angle = (360 / 12) * i;

	  mSphereNode = mHoursNode->createChildSceneNode("Hora " + std::to_string(i));
	  mSphereNode->setPosition(Math::Cos(Degree(angle)) * 300, Math::Sin(Degree(angle)) * 300, 0);
	  mSphereNode->setScale(.5, .5, .5);

	  ent = mSM->createEntity("sphere.mesh");
	  mSphereNode->attachObject(ent);
  }

  mClockHandNode = mClockNode->createChildSceneNode();
  mClockHandNode->roll(Radian(Ogre::Math::PI / 2));
  mClockHandNode->setScale(.15, 2, .1);
  mClockHandNode->setPosition(Vector3(70, 0, 0));
  ent = mSM->createEntity("cube.mesh");
  mClockHandNode->attachObject(ent);

  mClockHandNode = mClockNode->createChildSceneNode();
  mClockHandNode->setScale(.1, 2.5, .1);
  mClockHandNode->setPosition(Vector3(0, 90, 0));
  ent = mSM->createEntity("cube.mesh");
  mClockHandNode->attachObject(ent);
  mClockHandNode = mClockNode->createChildSceneNode();
  mClockHandNode->roll(Radian(3 * Math::PI / 4));
  mClockHandNode->setScale(.02, 2.5, .1);
  mClockHandNode->setPosition(-90, -90, 0);
  ent = mSM->createEntity("cube.mesh");
  mClockHandNode->attachObject(ent);*/

  /// Modifica el tama�o de las esferas pares
  /*for (int i = 0; i < 12; i++) 
  {
	  if (i % 2 != 0)
		  mSM->getSceneNode("Hora " + std::to_string(i))->setScale(.25, .25, .25);
  }*/

  /*mAspaNoriaNode = mSM->getRootSceneNode()->createChildSceneNode("mAspaNoria");
  AspaNoria* aspaNoria = new AspaNoria(mAspaNoriaNode);*/

  /// <summary>
  /// Creacion del skyPlane
  /// </summary>
  /// <param name=""></param>
  mSM->setSkyPlane(true, Plane(Vector3::UNIT_X, -80), "Practica2GLSL/newSpace", 1, 1, true, 1.0, 100, 100);

  /// <summary>
  /// Creacion del plano de agua
  /// </summary>
  /// <param name=""></param>
  mPlaneNode = mSM->getRootSceneNode()->createChildSceneNode("mPlane");
  plano = new Plano(mPlaneNode);
  addInputListener(plano);

  mFictitiusNode = mPlaneNode->createChildSceneNode();

  /// <summary>
  /// Creacion de los planos de colores
  /// </summary>
  /// <param name=""></param>
  MeshManager::getSingleton().createPlane("mPlane1000x1000",
	  ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME,
	  Plane(Vector3::UNIT_Y, 0),
	  1000, 1000, 100, 80, true, 1, 1.0, 1.0, Vector3::UNIT_Z);

  /*mPlaneRed = mPlaneNode->createChildSceneNode("mPlaneRed");
  ent = mSM->createEntity("mPlane1000x1000");
  ent->setMaterialName("Practica1/red");
  mPlaneRed->attachObject(ent);
  mPlaneRed->translate(-1000, 5, -1000);*/

  mPlaneYellow = mPlaneNode->createChildSceneNode("mPlaneYellow");
  ent = mSM->createEntity("mPlane1000x1000");
  ent->setMaterialName("Practica1/yellow");
  mPlaneYellow->attachObject(ent);
  mPlaneYellow->translate(1000, 5, 1000);

  /// <summary>
  /// Creacion de la noria
  /// </summary>
  /// <param name=""></param>
  mNoriaNode = mPlaneNode->createChildSceneNode("mNoria");
  mNoriaNode->translate(-1400, 0, -1000);
  noria = new Noria(mNoriaNode, 30);
  addInputListener(noria);

  /// <summary>
  /// Creacion del mu�eco
  /// </summary>
  /// <param name=""></param>
  mMu�ecoNode = mPlaneNode->createChildSceneNode("mMu�eco");
  mMu�ecoNode->translate(-700, 100, -1300);
  //mMu�ecoNode->setScale(2, 2, 2);
  //mMu�ecoNode->yaw(Radian(-3 * Math::PI / 4));
  //mMu�ecoNode->yaw(Degree(-90));
  mu�eco = new Mu�eco(mMu�ecoNode);
  addInputListener(mu�eco);

  /// <summary>
  /// Creacion de la bomba
  /// </summary>
  /// <param name=""></param>
  mBombaNode = mPlaneNode->createChildSceneNode("mBomba");
  mBombaNode->scale(70, 70, 70);
  bomba = new Bomba(mBombaNode);
  mBombaNode->scale(.02, .02, .02);
  addInputListener(bomba);

  /// <summary>
  /// Creacion del avion caza drones
  /// </summary>
  /// <param name=""></param>
  mFictitiusNode = mPlaneNode->createChildSceneNode();
  mAvionNode = mFictitiusNode->createChildSceneNode("mAvion");
  avion = new Avion(mAvionNode);
  mAvionNode->translate(0, 1000, 500);
  addInputListener(avion);

  /// <summary>
  /// Niebla
  /// </summary>
  /// <param name=""></param>
  /*BillboardSet* bbSet2 = mSM->createBillboardSet("fog", 10);
  bbSet2->setDefaultDimensions(5000, 3500);
  bbSet2->setMaterialName("Practica1/smoke");
  mPlaneNode->attachObject(bbSet2);
  Billboard* bb2 = bbSet2->createBillboard(Vector3(500.0, 1200.0, -500.0));*/

  /// <summary>
  /// Creacion del planeta
  /// </summary>
  /// <param name=""></param>
  /*mPlanetNode = mSM->getRootSceneNode()->createChildSceneNode("mPlanet");
  ent = mSM->createEntity("sphere.mesh");
  ent->setMaterialName("Practica1/cyan");
  mPlanetNode->scale(3, 3, 3);
  mPlanetNode->attachObject(ent);

  mFictitiusNode = mPlanetNode->createChildSceneNode();*/

  /// <summary>
  /// Creacion del dron avispa
  /// </summary>
  /// <param name=""></param>
  /*nDron = nDronAlive;

  for (int i = 0; i < nDron; i++) 
  {
	  mFictitiusNode = mPlanetNode->createChildSceneNode();
	  mDronNode = mFictitiusNode->createChildSceneNode("mDronAvispa" + std::to_string(i));
	  dron = new Dron(mDronNode, 3, Dron::TYPE::WASP);
	  mDronNode->scale(.015, .015, .015);
	  mDronNode->setPosition(0, 105, 0);
	  mFictitiusNode->roll(Degree(Math::RangeRandom(0, 360)));
	  mFictitiusNode->pitch(Degree(Math::RangeRandom(0, 360)));
	  mFictitiusNode->yaw(Degree(Math::RangeRandom(0, 360)));
	  addInputListener(dron);
  }*/

  /// <summary>
  /// Creacion del dron nodriza
  /// </summary>
  /// <param name=""></param>
  /*mFictitiusNode = mPlanetNode->createChildSceneNode();
  mDronNode = mFictitiusNode->createChildSceneNode("mDronNodriza");
  dron = new Dron(mDronNode, 3, Dron::TYPE::MOTHERSHIP);
  mDronNode->scale(.03, .03, .03);
  mDronNode->setPosition(0, 105, 0);
  mFictitiusNode->roll(Degree(-45));
  addInputListener(dron);*/

  /// <summary>
  /// Creacion de Sinbad
  /// </summary>
  /// <param name=""></param>
  mFictitiusNode = mPlaneYellow->createChildSceneNode();
  mSinbadNode = mFictitiusNode->createChildSceneNode("mSinbad");
  mSinbadNode->translate(0, 270, 0);
  mSinbadNode->scale(50, 50, 50);
  mSinbadNode->yaw(Degree(90));
  sinbad = new Sinbad(mSinbadNode);
  sinbad->arma();
  addInputListener(sinbad);

  //------------------------------------------------------------------------

  mCamMgr = new OgreBites::CameraMan(mCamNode);
  addInputListener(mCamMgr);
  mCamMgr->setStyle(OgreBites::CS_ORBIT);  
  
  //mCamMgr->setTarget(mSinbadNode);  
  //mCamMgr->setYawPitchDist(Radian(0), Degree(30), 100);

  //------------------------------------------------------------------------

}

